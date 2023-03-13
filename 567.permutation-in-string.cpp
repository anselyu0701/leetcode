/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
    bool isVectorEqual(vector<int> v1, vector<int> v2)
    {
        for (int counter = 0; counter < 26; counter++)
        {
            if (v1[counter] != v2[counter])
            {
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        // hash table
        vector<int> s1Vector(26, 0);
        vector<int> s2Vector(26, 0);
        int s2Start = 0;
        int s2End = 0;
        int s1Size = s1.length();
        int s2Size = s2.length();

        // special case
        if (s1Size > s2Size || s1Size == 0 || s2Size == 0)
        {
            return false;
        }

        // store the number of each charactors in s1
        for (int counter = 0; counter < s1Size; counter++)
        {
            s1Vector[s1[counter] - 'a']++;
        }

        while (s2End < s2Size)
        {
            s2Vector[s2[s2End] - 'a']++;

            if (s2End - s2Start + 1 == s1Size)
            {
                if (isVectorEqual(s1Vector, s2Vector))
                {
                    return true;
                }
            }

            if (s2End - s2Start + 1 >= s1Size)
            {
                s2Vector[s2[s2Start] - 'a']--;
                s2Start++;
                s2End++;
            }
            else 
            {
                s2End++;
            }
        }
        return false;
    }
};
// @lc code=end

