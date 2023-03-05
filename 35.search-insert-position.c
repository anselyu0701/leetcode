/*
 * @lc app=leetcode id=35 lang=c
 *
 * [35] Search Insert Position
 */

// @lc code=start
int searchInsert(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize-1;
    int key;
    while (left <= right)
    {
        
        key = (right - left) / 2 + left;
        if (nums[key] == target)
        {
            return key;
        }
        else if (nums[key] > target)
        {
            right = key - 1;
        }
        else 
        {
            left = key + 1;
        }
    }
    return left;
}
// @lc code=end

