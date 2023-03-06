/*
 * @lc app=leetcode id=167 lang=c
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    *returnSize = 2;
    int* ans = (int *) malloc(2 * sizeof(int));
    ans[0] = 0;
    ans[1] = numbersSize - 1;
    int total;

    while (1)
    {
        total = numbers[ans[0]] + numbers[ans[1]];
        if (total == target)
        {
            break;
        }
        else if(total < target)
        {
            ans[0]++;
        }
        else
        {
            ans[1]--;
        }

    }
    ans[0]++;
    ans[1]++;
    return ans;
}
// @lc code=end

