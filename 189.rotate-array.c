/*
 * @lc app=leetcode id=189 lang=c
 *
 * [189] Rotate Array
 */

// @lc code=start
void reverse(int *nums, int left, int right)
{
    int temp;
    while (left < right)
    {
        temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}

void rotate(int* nums, int numsSize, int k){
    k %= numsSize;
    int counter;
    // reverse total series
    reverse(nums, 0, numsSize-1);
    // reverse left part;
    reverse(nums, 0, k-1);
    // reverse right part
    reverse(nums, k, numsSize-1);
}
// @lc code=end

