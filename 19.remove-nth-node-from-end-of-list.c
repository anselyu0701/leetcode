/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* ans = head;
    struct ListNode* n_last;
    int size = 1;
    int remove_item;
    int counter;

    // get length
    for (; head->next != NULL; head = head->next)
    {
        size++;
    }

    // special case
    if (size == 1)
    {
        return NULL;
    }
    if (size == n)
    {
        ans = ans->next;
        return ans;
    }


    remove_item = size - (n - 1);
    head = ans;
    for (counter = 1; counter <= remove_item; counter++)
    {
        if (counter == remove_item-1)
        {
            n_last = head;
        }
        head = head->next;
    }
    n_last->next = head;
    return ans;
}
// @lc code=end

