/*
 * @lc app=leetcode id=283 lang=c
 *
 * [283] Move Zeroes
 */

// @lc code=start
void moveZeroes(int* nums, int numsSize){
    int size = 0;
    int counter;
    int temp;
    for (counter = 0; counter < numsSize; counter++)
    {
        if (nums[counter] == 0)
        {
            size++;
        }
        else if (size > 0)
        {
            temp = nums[counter];
            nums[counter] = 0;
            nums[counter-size] = temp;
        }
    }
    
}
// @lc code=end

