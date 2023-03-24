/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
public:

    typedef struct node{
        int row;
        int col;
    }node_t;
    
    int BFS(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col, int rowSize, int colSize)
    {
        int areaSize = 1;
        // define a queue for queuing nodes
        queue<node_t> queuing;
        node_t tempNode1;
        node_t tempNode2;
        tempNode1.row = row;
        tempNode1.col = col; 
        int paraTopDown[4] = {-1, 1, 0, 0};
        int paraLeftRight[4] = {0, 0, -1, 1};
        // push the first node into queue
        queuing.push(tempNode1);
        visited[tempNode1.row][tempNode1.col] = true;

        while (!queuing.empty())
        {
            tempNode1 = queuing.front();

            for (int counter = 0; counter < 4; counter++)
            {
                if (((tempNode1.row+paraTopDown[counter]) < rowSize) && ((tempNode1.row+paraTopDown[counter]) >= 0) &&
                    ((tempNode1.col+paraLeftRight[counter]) < colSize) && ((tempNode1.col+paraLeftRight[counter]) >= 0))
                {
                    if ((grid[tempNode1.row+paraTopDown[counter]][tempNode1.col+paraLeftRight[counter]] == 1) && 
                        (!visited[tempNode1.row+paraTopDown[counter]][tempNode1.col+paraLeftRight[counter]]))
                    {    
                        areaSize++;
                        tempNode2.row = tempNode1.row + paraTopDown[counter];
                        tempNode2.col = tempNode1.col + paraLeftRight[counter];
                        visited[tempNode2.row][tempNode2.col] = true;
                        queuing.push(tempNode2);
                    }
                }
            }            
            queuing.pop();
        }
        return areaSize;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxAreaSize = 0;
        // get the matrix size
        int rowSize = grid.size();
        int colSize = grid[0].size();
        if (rowSize == 0)
        {
            return 0;
        }

        int tempSize;

        // define a 2d array vector with matrix size and initial value is false
        vector<vector<bool>> visited(rowSize, vector<bool>(colSize, false));    

        for (int outer = 0; outer < rowSize; outer++)
        {
            for (int inner = 0; inner < colSize; inner++)
            {
                if ((!visited[outer][inner]) && grid[outer][inner] == 1)
                {
                    tempSize = BFS(grid, visited, outer, inner, rowSize, colSize);
                    maxAreaSize = maxAreaSize > tempSize ? maxAreaSize:tempSize;
                }
                else
                {
                    visited[outer][inner] = true;
                }
            }
        }

        return maxAreaSize;
    }
};
// @lc code=end

