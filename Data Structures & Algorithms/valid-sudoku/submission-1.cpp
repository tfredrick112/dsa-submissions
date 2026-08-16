class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        bool boxes[9][9];
        bool rows[9][9];
        bool columns[9][9];

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char ch = board[i][j];
                if (ch == '.')
                    continue;

                int num = ch - '0';
                num -= 1;

                int boxIndex = (i / 3) * 3 + (j / 3);

                if (rows[i][num] || columns[j][num] || boxes[boxIndex][num])
                {
                    return false;
                }

                rows[i][num] = true;
                columns[j][num] = true;
                boxes[boxIndex][num] = true;
            }
        }

        return true;
    }
};
