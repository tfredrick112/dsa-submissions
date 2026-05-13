class Solution {
public:
    bool checkValidString(string s)
    {
        stack<int> left, star;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                left.push(i);
            }
            else if (s[i] == '*')
            {
                star.push(i);
            }
            else if (s[i] == ')')
            {
                if (!left.empty())
                {
                    left.pop();
                }
                else if (!star.empty())
                {
                    star.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        while (!left.empty() && !star.empty())
        {
            int leftBracketIndex = left.top();
            left.pop();
            int starIndex = star.top();
            star.pop();

            if (leftBracketIndex > starIndex)
            {
                return false;
            }
        }

        return left.empty();
    }
};
