/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
// using two pointers
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        // initialize the first interval
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int counter1 = 1; counter1 < intervals.size(); counter1++)
        {
            // check whether it's overlapping
            if (end >= intervals[counter1][0])
            {
                end = max(end, intervals[counter1][1]);
            }
            else
            {
                // when the intervals are not contiguous, push the interval, and start a new interval
                ans.push_back({start, end});
                start = intervals[counter1][0];
                end = intervals[counter1][1];
            }
        }
        // push the last interval
        ans.push_back({start, end});
        return ans;
    }
};
// @lc code=end

