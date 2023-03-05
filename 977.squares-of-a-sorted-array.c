/*
 * @lc app=leetcode id=977 lang=c
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int *solve = (int *) malloc(numsSize * sizeof(int));
    int left = 0;
    int right = numsSize - 1;
    int counter;
    *returnSize = numsSize;
    for (counter = numsSize-1; counter >= 0; counter--)
    {
        if (abs(nums[right]) > abs(nums[left]))
        {
            solve[counter] = nums[right] * nums[right];
            right--;
        }
        else 
        {
            solve[counter] = nums[left] * nums[left];
            left++;
        }
    }
    return solve;
}
// @lc code=end

