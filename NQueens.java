import java.util.*;

class Solution {

    boolean isSafe(int row, int col, List<String> board) {

        int r = row;
        int c = col;

        // Upper
        while (r >= 0) {

            if (board.get(r).charAt(c) == 'Q') {
                return false;
            }

            r--;
        }

        r = row;
        c = col;

        // Upper-left diagonal
        while (r >= 0 && c >= 0) {

            if (board.get(r).charAt(c) == 'Q') {
                return false;
            }

            r--;
            c--;
        }

        r = row;
        c = col;

        // Upper-right diagonal
        while (r >= 0 && c < board.size()) {

            if (board.get(r).charAt(c) == 'Q') {
                return false;
            }

            r--;
            c++;
        }

        return true;
    }

    void recursion(int row,
                   List<List<String>> ans,
                   List<String> board,
                   int n) {

        if (row == board.size()) {

            ans.add(new ArrayList<>(board));
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isSafe(row, col, board)) {

                char[] currentRow = board.get(row).toCharArray();
                currentRow[col] = 'Q';
                board.set(row, new String(currentRow));

                recursion(row + 1, ans, board, n);

                currentRow = board.get(row).toCharArray();
                currentRow[col] = '.';
                board.set(row, new String(currentRow));
            }
        }
    }

    public List<List<String>> NQueens(int n) {

        List<String> board = new ArrayList<>();

        for (int i = 0; i < n; i++) {

            String row = ".".repeat(n);
            board.add(row);
        }

        List<List<String>> ans = new ArrayList<>();

        recursion(0, ans, board, n);

        return ans;
    }
}

public class Main {

    public static void main(String[] args) {

        Solution solution = new Solution();

        int n = 4;

        List<List<String>> solutions = solution.NQueens(n);

        for (List<String> sol : solutions) {

            for (String row : sol) {
                System.out.println(row);
            }

            System.out.println();
        }
    }
}
