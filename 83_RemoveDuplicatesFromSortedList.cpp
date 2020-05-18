Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3



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
    ListNode* deleteDuplicates(ListNode* head) {
     
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode *ptr = head, *qtr = head -> next;
        while(ptr != NULL)
        {
            qtr = ptr -> next;
            while(qtr != NULL && qtr -> val == ptr -> val)
            {
                ptr -> next = qtr -> next;
                qtr = qtr -> next;
            }
            ptr = ptr -> next;
        }
        return head;
    }
};
