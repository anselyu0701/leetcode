/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    void DFS (string digits, int pos, string& path, vector<string>& ans, vector<string>& map_table)
    {
        if (pos == (digits.size()))
        {
            ans.push_back(path);
            return;
        }

        int table_idx = digits[pos] - '0';
        string letters = map_table[table_idx];

        for (int letters_idx = 0; letters_idx < letters.length(); letters_idx++)
        {
            path.push_back(letters[letters_idx]);
            DFS(digits, pos + 1, path, ans, map_table);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;
        vector<string> map_table = {"", "", "abc", "def", "ghi", "jkl", "mno",
                                    "pqrs", "tuv", "wxyz"};

        if (digits.empty()) return ans;
        
        string path;
        DFS (digits, 0, path, ans, map_table);     

        return ans;
    }
};
// @lc code=end

