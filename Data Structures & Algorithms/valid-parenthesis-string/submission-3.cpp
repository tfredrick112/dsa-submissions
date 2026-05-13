class Solution {
public:
    bool checkValidString(string s)
    {
        int minOpen = 0, maxOpen = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                minOpen++;
                maxOpen++;
            }
            else if (s[i] == ')')
            {
                minOpen--;
                maxOpen--;
            }
            else if (s[i] == '*')
            {
                minOpen--;
                maxOpen++;
            }

            if (maxOpen < 0)
                return false;

            if (minOpen < 0)
                minOpen = 0; // use some of the extra * as empty string
        }

        return minOpen == 0;
    }
};
