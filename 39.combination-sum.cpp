/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    void DFS (int pos, int target, int sum, vector<int>& candidates, vector<int>& path, vector<vector<int>>& ans)
    {
        if (sum == target)
        {
            ans.push_back(path);
            return;
        }
        
        if (sum < target)
        {
            for (int idx = pos; idx < candidates.size(); idx++, pos++)
            {
                path.push_back(candidates[idx]);
                DFS(pos, target, sum+candidates[idx], candidates, path, ans);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> path;
        vector<vector<int>> ans;
        unsigned int pos = 0;

        sort(candidates.begin(), candidates.end());
        DFS(pos, target, 0, candidates, path, ans);
        
        return ans;
    }
};
// @lc code=end

