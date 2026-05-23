class Solution {
public:
    bool isSafePosition(vector<string>& board, int i, int c)
    {
        // check if there is already a queen in the same row
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        // check if there is a queen in the left top diagonal
        int x = i - 1, y = c - 1;
        while (x >= 0 && y >= 0)
        {
            if (board[x][y] == 'Q')
                return false;

            x--;
            y--;
        }

        // check if there is already a queen in the left bottom diagonal
        x = i + 1, y = c - 1;
        while (x < board.size() && y >= 0)
        {
            if (board[x][y] == 'Q')
                return false;

            x++;
            y--;
        }

        return true;
    }
    void backtrack(vector<string>& board, int c, int n, vector<vector<string>>& result)
    {
        if (c == n)
        {
            // this means that we have placed all the N queens in the columns 0 to N - 1
            result.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (isSafePosition(board, i, c))
            {
                board[i][c] = 'Q';
                backtrack(board, c + 1, n, result);
                board[i][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, n, result);
        return result;
    }
};
