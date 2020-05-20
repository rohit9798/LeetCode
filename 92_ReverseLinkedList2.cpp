Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL



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
    ListNode *reverse(ListNode *head, int m, int n)
    {
        ListNode *dummy = head -> next;
        ListNode *save =  NULL, *ptr = head, *qtr = head, *rtr = head;
        if(m == 1)
        {
            save = head;
            qtr = NULL;
        }
        else
        {
            for(int i = 2; i < m; i++)
                qtr = qtr -> next;
            save = qtr;
            ptr = qtr -> next;
            qtr = NULL;
        }
        int count = m;
        rtr = ptr -> next;
        while(count <= n)
        {
            ptr -> next = qtr;
            qtr = ptr;
            ptr = rtr;
            if(rtr == NULL)
                break;
            rtr = rtr -> next;
            count++;
        }
        if(m > 1)
        {
            ListNode *temp = save -> next;
            save -> next = qtr;
            temp -> next = ptr;
        }
        else
        {
            save -> next = ptr;
            head = qtr;
        }
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        ListNode *head1 = NULL;
        head1 = reverse(head, m, n);
        return head1;
    }
};
