/*
 * @lc app=leetcode id=876 lang=c
 *
 * [876] Middle of the Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head){
    int size = 1;
    int counter;
    int middle;
    struct ListNode* temp = head;

    while (temp->next != NULL)
    {
        size++;
        temp = temp->next;
    }
    middle = size / 2;
    for (counter = 0; counter < middle; counter++)
        {
            head = head->next;
        }
    return head;
}
// @lc code=end

