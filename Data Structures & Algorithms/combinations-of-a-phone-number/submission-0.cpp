class Solution {
public:
    // Time complexity = O(n * 4 ^ n) : There are at most 4 options at each position, and the time taken
    // to copy one combination into the result array is O(n). Total number of combinations = O(4^n)
    // Total time complexity = O(n * 4^n)
    // Space complexity = O(n) for the curr string and O(n) for the recursion stack.
    // Output space - O(n * 4^n)
    unordered_map<char, string> mp = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };
    void backtrack(string& digits, int index, string& curr, vector<string>& result)
    {
        if (index >= digits.size())
        {
            result.push_back(curr);
            return;
        }

        for (char letter : mp[digits[index]])
        {
            curr += letter;
            backtrack(digits, index + 1, curr, result);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        string curr = "";

        if (digits.size() == 0)
            return result;

        backtrack(digits, 0, curr, result);
        return result;
    }
};
