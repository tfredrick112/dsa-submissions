class Solution {
public:
    // This solution is a O(m * n * 3 ^ L) time complexity solution.
    // There are O(m*n) starting positions, and once we start, we can go in 3 directions to the next letter.
    // Not 4, but 3 directions, because the visited array ensures that you do not go back to where you came from.
    vector<vector<int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    bool f(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int index, int x, int y)
    {
        if (board[x][y] != word[index])
            return false;

        if (index == word.size() - 1)
            return true;

        bool result = false;
        int m = board.size(), n = board[0].size();

        for(const auto& d : directions)
        {
            int i = x + d[0], j = y + d[1];

            if (i >= 0 && i < m && j >= 0 && j < n && !visited[i][j])
            {
                visited[i][j] = true;
                result = result || f(board, visited, word, index + 1, i, j);
                visited[i][j] = false;

                if (result == true)
                    return true;
            }
        }

        return result;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = true;

                if (f (board, visited, word, 0, i, j))
                    return true;

                visited[i][j] = false;
            }
        }

        return false;
    }
};
