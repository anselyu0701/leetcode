/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
//using Multiset
// refer to https://leetcode.com/problems/the-skyline-problem/solutions/2094329/c-easiest-explanation-ever-guaranteed-beginner-friendly-detailed-o-nlogn/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> heights;
        vector<vector<int>> ans;

        for (auto build : buildings)
        {
            heights.push_back({build[0], -build[2]}); // store the start point with -height
            heights.push_back({build[1],  build[2]}); // store the end point with +height
        }

        sort(heights.begin(), heights.end());

        // define a multiset that store the numbers in decreasing order
        multiset<int, greater<int>> ms;
        ms.insert(0);
        int  lastMax = 0;

        for (auto it : heights)
        {
            if (it.second < 0)
            {
                // if height is negative(at head) then adding to the set
                ms.insert(-it.second);
            }
            else
            {
                // if height is positive(at rear) then removing from the set
               ms.erase(ms.find(it.second));
            }

            // find the biggest element in the set, then equal to curMax
            int curMax = *(ms.begin());

            // if the curMax != lastMax, that means it's a turning point
            // it needs to be add to the ans vector 
            if(curMax != lastMax)
            {
                ans.push_back({it.first, curMax});
                lastMax = curMax;
            }
        }
        return ans;
    }
};
// @lc code=end