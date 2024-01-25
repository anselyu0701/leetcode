/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:

    void DFS (int left_cnt, int right_cnt, vector<string>& ans, string& path)
    {
        if (right_cnt == 0)
        {
            ans.push_back(path);
            return;
        }

        if (left_cnt > 0)
        {
            path.push_back('(');
            DFS (left_cnt-1, right_cnt, ans, path);
            path.pop_back();
        }

        if (left_cnt < right_cnt)
        {
            path.push_back(')');
            DFS(left_cnt, right_cnt-1, ans, path);
            path.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        int right_cnt = n;
        int left_cnt = n;
        string path = "";

        DFS(left_cnt, right_cnt, ans, path);
        return ans;  
    }
};
// @lc code=end

