/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tail = new ListNode();
        ListNode* head = tail;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int val1 = (l1 == nullptr) ? 0:l1->val;
            int val2 = (l2 == nullptr) ? 0:l2->val;
            int sum = val1 + val2 + carry;
            carry = 0;

            if (sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }

            ListNode* new_node = new ListNode(sum);         
            tail->next = new_node;
            tail = tail->next;

            l1 = (l1 == nullptr) ? nullptr:l1->next;
            l2 = (l2 == nullptr) ? nullptr:l2->next;
        }
        ListNode* del_head = head;
        head = head->next;
        delete del_head;
        return head;        
    }
};
// @lc code=end

