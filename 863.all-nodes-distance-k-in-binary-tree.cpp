/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:    
    
    vector<int> ans;    

    void findChildren (TreeNode* root, int k) 
    {
        if ((!root) || (k < 0))
        {
            return;
        }
        if (k == 0)
        {
            ans.push_back(root->val);
            return;
        }
        
        findChildren(root->right, k--);
        findChildren(root->left, k--);
        
    }

    int findParent (TreeNode* root, TreeNode* target, int k)
    {
        // root does not exist
        if (!root)
        {
            return -1;
        }
        if (root == target)
        {
            findChildren(root, k);
            return 0;
        }
        // DFS
        // left side
        int left_distance = findParent(root->left, target, k);
        if (left_distance != -1)
        {
            // target is in the left side
            if (left_distance + 1 == k)
            {
                ans.push_back(root->val);
            }
            else
            {
                findChildren(root->right, k-left_distance-2);
            }
            return 1 + left_distance;
        }

        int right_distance = findParent(root->right, target, k);
        if (right_distance != -1)
        {
            // target is in the right side
            if (right_distance + 1 == k)
            {
                ans.push_back(root->val);
            }
            else
            {
                findChildren(root->left, k-right_distance-2);
            }
            return 1 + right_distance;
        }
        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {       
        findParent(root, target, k);
        return ans;
    }
};
// @lc code=end

