/*
 * @lc app=leetcode id=278 lang=c
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int index;
    int left = 1;
    int right = n;
    bool state;
    while (left <= right)
    {
        index = (right - left) / 2 + left;
        state = isBadVersion(index);
        if (state)
        {
            right = index - 1;
        }
        else
        {
            left = index  + 1;
        }
    }
    return left;
}
// @lc code=end

