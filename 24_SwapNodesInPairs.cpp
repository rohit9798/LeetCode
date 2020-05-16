Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.



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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode *result = head;
        result = result -> next;
        ListNode* ptr = result, *qtr = head;
        while(qtr != NULL && qtr -> next != NULL)
        {
            ListNode *temp = ptr -> next;
            if(temp != NULL)
            {
                if(temp -> next == NULL)
                    qtr -> next = temp;
                else
                    qtr -> next = temp -> next;
            }
            else
                qtr -> next = NULL;
            ptr -> next = qtr;
            qtr = temp;
            if(qtr != NULL)
                ptr = qtr -> next;
            else
                ptr = NULL;
        }
        
        return result;
    }
};
