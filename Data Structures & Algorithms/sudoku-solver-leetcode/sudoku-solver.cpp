// This is from Leetcode 37
class Solution {
public:
    vector<int> rows, columns, boxes;
    void backtrack(vector<vector<char>>& board, int m, int n, int index, vector<vector<char>>& result)
    {
        // If the result is not empty anymore, we have already found the solution and we can return
        if (!result.empty())
            return;

        if (index == m * n)
        {
            // The index has gone out of the board, indicating that we have already found a valid way
            // to fill all the cells in the board.
            // Because of the backtracking, 'board' becomes goes back to the original input state
            // so we store the result as soon as we find it.
            result = board;
            return;
        }

        int i = index / n, j = index % n;

        if (board[i][j] != '.')
        {
            // The current cell already has a fixed value given in the original board
            // So we move to the next index.
            backtrack(board, m, n, index + 1, result);
            return;
        }

        int boxId = (i / 3) * 3 + (j / 3);

        // We have found an empty cell, we now try to place numbers from 1 - 9 in this cell,
        // and explore each path and backtrack. Before placing a number, we have to check if
        // it already occurs in the row, column or box. If it does not, then we can safely place
        // it and move to the next cell and once we have explored all the possibilities, we come back,
        // remove the number and then try to place the next number and again go to explore all
        // possibilities.

        for (int num = 1; num <= 9; num++)
        {
            if (rows[i] & (1 << num) || columns[j] & (1 << num) || boxes[boxId] & (1 << num))
                continue;

            board[i][j] = (char)('0' + num);
            rows[i] |= (1 << num);
            columns[j] |= (1 << num);
            boxes[boxId] |= (1 << num);

            backtrack(board, m, n, index + 1, result);

            board[i][j] = '.';
            rows[i] &= ~(1 << num);
            columns[j] &= ~(1 << num);
            boxes[boxId] &= ~(1 << num);
        }
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        int m = board.size(), n = board[0].size();
        rows.assign(m, 0);
        columns.assign(n, 0);
        boxes.assign(9, 0);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';

                int boxId = (i / 3) * 3 + (j / 3);

                rows[i] |= (1 << num);
                columns[j] |= (1 << num);
                boxes[boxId] |= (1 << num);
            }
        }

        vector<vector<char>> result;
        backtrack(board, m, n, 0, result);
        board = result;
    }
};
