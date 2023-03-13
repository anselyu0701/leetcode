/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
    void dfs(vector<vector<int>>& image, int row, int col, int newColor, int oldColor)
    {
        if (row >= image.size() || row < 0 || col >= image[0].size() || col < 0)
        {  
            return;       
        }
        if (oldColor != image[row][col] || image[row][col] == newColor)
        {
            return;
        }   
        
        image[row][col] = newColor;
        dfs(image, row - 1, col, newColor, oldColor); // top
        dfs(image, row + 1, col, newColor, oldColor); // down
        dfs(image, row, col - 1, newColor, oldColor); // left
        dfs(image, row, col + 1, newColor, oldColor); // right
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};
// @lc code=end

