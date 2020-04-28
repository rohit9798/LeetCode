Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *ptr = head;
        ListNode *qtr = head;
        for(int i = 0; i < n; i++)
        {
            ptr = ptr -> next;
        }
        if(ptr == NULL)
        {
            head = head -> next;
            return  head;
        }
        while(ptr -> next != NULL)
        {
            qtr = qtr -> next;
            ptr = ptr -> next;
        }
        qtr -> next = qtr -> next -> next;
        return head;
    }
};
