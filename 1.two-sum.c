/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* solution = (int *) malloc(2 * sizeof(int));
    int p1 = 0;
    int p2 = numsSize - 1;

    while (nums[p1] + nums[p2] != target || p1 == p2)
    {
        if (p1 >= p2)
        {
            p1++;
            p2 = numsSize - 1;
        }        
        else 
        {
            p2--;
        }
    }
    solution[0] = p1;
    solution[1] = p2;
    return solution;
}
// @lc code=end

