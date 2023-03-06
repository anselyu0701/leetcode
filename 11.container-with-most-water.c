/*
 * @lc app=leetcode id=11 lang=c
 *
 * [11] Container With Most Water
 */

// @lc code=start
int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int max = 0;
    int area;
    while (left < right)
    {
        area = (height[left]<height[right] ? height[left]:height[right]) * (right - left);
        if (area > max)
        {
            max = area;
        }
        height[left]<height[right] ? left++:right--;
    }
    return max;
}
// @lc code=end

