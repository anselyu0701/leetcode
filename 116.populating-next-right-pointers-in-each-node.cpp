/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if (!root)
        {
            return nullptr;
        }

        queue<Node*> q;
        Node* tempNode;
        int currQSize;
        q.push(root);

        while (!q.empty()) 
        {
            currQSize = size(q);
            // traves all nodes in the same layer
            for (int counter = 0; counter < currQSize; counter++)
            {
                tempNode = q.front();
                q.pop();
                if (counter == currQSize-1)
                {
                    tempNode->next = nullptr;
                }
                else 
                {
                    tempNode->next = q.front();
                }

                if (tempNode->left)
                {
                q.push(tempNode->left);
                q.push(tempNode->right);
                }
            }            
        }
        return root;
    }
};
// @lc code=end

