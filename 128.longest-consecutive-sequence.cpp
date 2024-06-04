/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int max_len = 0;
        unordered_set<int> us;

        // insert unordered_set, O(n)
        for (int iter : nums)
        {
            us.insert(iter);
        }

        // for: O(n), find: O(1), 
        for (int iter : nums)
        {
            // identify if the head for longest
            if (us.find(iter-1) == us.end())
            {
                int expected_num = iter + 1;
                int len = 1;

                while(us.find(expected_num) != us.end())
                {
                    len++;
                    expected_num++;
                }

                max_len = max(max_len, len);
            }
        }

        return max_len;
    }
};
// @lc code=end

