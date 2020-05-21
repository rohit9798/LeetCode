Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.



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
    ListNode *reverse(ListNode *head)
    {
        ListNode *ptr = head, *qtr = NULL, *rtr = head;
        while(ptr != NULL)
        {
            rtr = rtr -> next;
            ptr -> next = qtr;
            qtr = ptr;
            ptr = rtr;
        }
        cout<<qtr -> val;
        return qtr;
    }
    void reorderList(ListNode* head) {
        
        if(head == NULL || head -> next == NULL)
            return ;
        ListNode *ptr = head, *qtr = head;
        while(ptr != NULL && ptr -> next != NULL)
        {
            ptr = ptr -> next -> next;
            qtr = qtr -> next;
        }
        ListNode *head1 = reverse(qtr);
        ptr = head;
        qtr = head1;
        while(ptr -> next != qtr && ptr != qtr)
        {
            ListNode *temp1 = ptr -> next;
            ListNode *temp2 = qtr -> next;
            ptr -> next = qtr;
            qtr -> next = temp1;
            ptr = temp1;
            qtr = temp2;
        }
    }
};
