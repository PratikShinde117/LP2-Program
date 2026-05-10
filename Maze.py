import heapq

def heuristic(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def a_star(maze, start, goal):
    rows = len(maze)
    cols = len(maze[0])

    pq = []
    heapq.heappush(pq, (0, start))

    visited = set()
    cost = {start: 0}

    while pq:
        f, current = heapq.heappop(pq)

        if current == goal:
            print("Goal Reached:", goal)
            return

        visited.add(current)

        x, y = current
        moves = [(-1,0), (1,0), (0,-1), (0,1)]

        for dx, dy in moves:
            nx, ny = x + dx, y + dy

            if 0 <= nx < rows and 0 <= ny < cols and maze[nx][ny] == 0:
                neighbor = (nx, ny)
                new_cost = cost[current] + 1

                if neighbor not in visited or new_cost < cost.get(neighbor, float("inf")):
                    cost[neighbor] = new_cost
                    priority = new_cost + heuristic(goal, neighbor)
                    heapq.heappush(pq, (priority, neighbor))

    print("No Path Found")

maze = [
    [0, 0, 0, 0],
    [1, 1, 0, 1],
    [0, 0, 0, 0],
    [0, 1, 1, 0]
]

start = (0, 0)
goal = (3, 3)

a_star(maze, start, goal)


