Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3



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
        
        int flag = 1;
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode *ptr = NULL, *qtr = head;
        while(flag == 1)
        {
            flag = 0;
            while(qtr != NULL && qtr -> next != NULL && qtr -> val == qtr -> next -> val)
            {
                flag = 1;
                qtr = qtr -> next;
            }
            if(flag == 1)
                qtr = qtr -> next;  
        }
        head = qtr;
        ptr = head;
        if(qtr != NULL)
            qtr = qtr -> next;
        while(qtr != NULL)
        {
            flag = 0;
            while(qtr != NULL && qtr -> next != NULL && qtr -> val == qtr -> next -> val)
            {
                flag = 1;
                qtr = qtr -> next;
            }
            if(qtr == NULL)
                return head;
            if(flag == 0)
            {
                ptr -> next = qtr;
                qtr = qtr -> next;
                ptr = ptr -> next;
            }
            else
            {
                ptr -> next = qtr -> next;
                qtr = qtr -> next;
            }
        }
        return head;
        
    }
};
