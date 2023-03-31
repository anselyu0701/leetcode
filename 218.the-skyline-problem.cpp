/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    int getMaxHeight(vector<vector<int>>& buildings, int pointer)
    {
        int height = buildings[pointer][2];
        for (int index = 0; index < buildings.size(); index++)
        {
            if (index != pointer)
            {
                if (buildings[pointer][0] >= buildings[index][0] && buildings[pointer][0] <= buildings[index][1])
                {
                    // overlapping happened, find the max height
                    height = max(buildings[pointer][2], buildings[index][2]);
                    // head, head overlapping
                    if (buildings[pointer][2] == buildings[index][2] && buildings[pointer][0] != buildings[index][0])
                    {
                        return -1;
                    }
                }
                if (buildings[pointer][0] == buildings[index][1] && buildings[pointer][2] == buildings[index][2])
                {
                    // head, rear connected
                    return -1;
                }
            }
        }
        if (height != buildings[pointer][2])
        {
            return -1; // be overlapped and samller than others
        }
        else
        {
            return height; // not be overlapped or bigger than others
        }
    }

    int checkRear(vector<vector<int>>& buildings, int pointer)
    {
        int height = 0;
        for (int index = 0; index < buildings.size(); index++)
        {
            if (index != pointer)
            {
                if (buildings[pointer][1] >= buildings[index][0] && buildings[pointer][1] <= buildings[index][1])
                {
                    if (buildings[index][2] >= buildings[pointer][2])
                    {
                        return -1;
                    }
                    else if (buildings[pointer][1] == buildings[index][1])
                    {
                        height = 0;
                    }
                    else
                    {
                        height = max(height, buildings[index][2]);
                    }
                }
            }
        }
        return height; // not be overlapped
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        sort(buildings.begin(), buildings.end());
        int height, rear;
        for (int pointer = 0; pointer < buildings.size(); pointer++)
        {
            height = getMaxHeight(buildings, pointer);
            if (height != -1)
            {
                ans.push_back({buildings[pointer][0], height});
            }
            rear = checkRear(buildings, pointer);            
            if (rear != -1)
            {
                ans.push_back({buildings[pointer][1], rear});
            }
        }
        return ans;
    }
};
// @lc code=end

