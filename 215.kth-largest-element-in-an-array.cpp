/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
// using Quick-Selection Algorithm
class Solution {
public:

    int partition(vector<int>& nums, int l, int r)
    {
        int pivot = nums[r];
        int index = l;
        for (int counter = l; counter < r; counter++)
        {
            if (nums[counter] >= pivot)
            {
                swap(nums[counter], nums[index]);
                index++;
            }
        }
        swap(nums[index], nums[r]);
        return index;
    }

    int quickSelect (vector<int>& nums, int l, int r, int k)
    {
        while (1)
        {
            int index = partition(nums, l, r);
            
            if (index == k - 1)
            {
                return nums[index];                
            }
            else if (index > k-1)
            {
                r = index - 1;
            }
            else 
            {
                l = index + 1;
            }
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect (nums, 0, nums.size()-1, k);
    }
};
// @lc code=end

