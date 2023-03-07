/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int s_size = s.length();
        set<char> rp_c;
        int length = 0;
        int start = 0;
        int end = 0;

        while (end < s_size)
        {
            // not found in rp_c
            if (rp_c.find(s[end]) == rp_c.end())
            {
                rp_c.insert(s[end]);
                length = (end-start+1)>length ? (end-start+1):length;
                end++;
            }
            else 
            {
                rp_c.erase(rp_c.find(s[start]));
                start++;
            }
        }
        return length;
    }
};
// @lc code=end

