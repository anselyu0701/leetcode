/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int counter1, counter2;
        // define a 2d-vector to save the distance and initialize it with a greatest number (10000)
        vector<vector<int>> v(mat.size(), vector<int>(mat[0].size(), 10000));
        // the first traversal: from the top left to down right
        for (counter1 = 0; counter1 < mat.size(); ++counter1)
        {
            for (counter2 = 0; counter2 < mat[0].size(); ++counter2)
            {
                if (mat[counter1][counter2] >= 1)
                {
                    if (counter1 > 0)
                    {
                        v[counter1][counter2] = min(v[counter1][counter2], v[counter1-1][counter2]+1);
                    }
                    if (counter2 > 0)
                    {
                        v[counter1][counter2] = min(v[counter1][counter2], v[counter1][counter2-1]+1);
                    }
                }
                else
                {
                    v[counter1][counter2] = 0;
                }
            }
        }
        // the second traversal: from the down right to top left
        for (counter1 = mat.size()-1; counter1 >= 0; --counter1)
        {
            for (counter2 = (mat[0].size()-1); counter2 >= 0; --counter2)
            {
                if (counter1 < mat.size()-1)
                {
                    v[counter1][counter2] = min(v[counter1][counter2], v[counter1+1][counter2]+1);
                }
                if (counter2 < mat[0].size()-1)
                {
                    v[counter1][counter2] = min(v[counter1][counter2], v[counter1][counter2+1]+1);
                }
            }
        }
        return v;
    }
};
// @lc code=end

