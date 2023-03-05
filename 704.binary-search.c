/*
 * @lc app=leetcode id=704 lang=c
 *
 * [704] Binary Search
 */

// @lc code=start
int search(int* nums, int numsSize, int target){
    int key;
    int left = 0;
    int right = numsSize - 1;
    while (left <= right)
    {
        key = (left + right) / 2;        
        if (nums[key] == target)
        {
            return key;
        }
        else if(nums[key] < target)
        {
            left = key + 1;
        }
        else // find the key
        {
            right = key - 1;
        }
    }
    return -1;
}
// @lc code=end

