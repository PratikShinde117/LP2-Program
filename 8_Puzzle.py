import heapq

goal = [[1, 2, 3],
        [4, 5, 6],
        [7, 8, 0]]

def heuristic(state):
    count = 0
    for i in range(3):
        for j in range(3):
            if state[i][j] != 0 and state[i][j] != goal[i][j]:
                count += 1
    return count

def find_blank(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                return i, j

def get_neighbors(state):
    neighbors = []
    x, y = find_blank(state)

    moves = [(-1,0), (1,0), (0,-1), (0,1)]

    for dx, dy in moves:
        nx, ny = x + dx, y + dy

        if 0 <= nx < 3 and 0 <= ny < 3:
            new_state = [row[:] for row in state]
            new_state[x][y], new_state[nx][ny] = new_state[nx][ny], new_state[x][y]
            neighbors.append(new_state)

    return neighbors

def state_to_tuple(state):
    return tuple(tuple(row) for row in state)

def a_star(start):
    pq = []
    heapq.heappush(pq, (heuristic(start), 0, start))

    visited = set()

    while pq:
        f, g, current = heapq.heappop(pq)

        if current == goal:
            print("Goal State Reached:")
            for row in current:
                print(row)
            return

        visited.add(state_to_tuple(current))

        for neighbor in get_neighbors(current):
            if state_to_tuple(neighbor) not in visited:
                h = heuristic(neighbor)
                heapq.heappush(pq, (g + 1 + h, g + 1, neighbor))

    print("No Solution Found")

start = [[1, 2, 3],
         [4, 0, 6],
         [7, 5, 8]]

a_star(start)
