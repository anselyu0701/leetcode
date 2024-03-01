/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int matrix_size = matrix.size();

        // Transpose
        for (int row = 0; row < matrix_size; row++)
        {
            for (int col = 0; col <= row; col++)
            {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
        
        // Reverse Column
        for (int row = 0; row < matrix_size; row++)
        {
            for (int col = 0; col < (matrix_size/2); col++)
            {
                swap(matrix[row][col], matrix[row][matrix_size-1-col]);
            }
        }
    }
};
// @lc code=end

