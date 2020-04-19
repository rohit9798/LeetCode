You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1 = l1, *temp2 = l2, *head = NULL, *ptr = NULL;
        int carry = 0;
        while(temp1 != NULL && temp2 != NULL)
        {
            if(head == NULL)
            {
                head = new ListNode((temp1 -> val + temp2 -> val + carry) % 10);
                carry = (temp1 -> val + temp2 -> val + carry) / 10;
                ptr = head;
            }
            else
            {
                ptr -> next = new ListNode((temp1 -> val + temp2 -> val + carry) % 10);
                carry = (temp1 -> val + temp2 -> val + carry) / 10;
                ptr = ptr -> next;
            }
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        while(temp1 != NULL)
        {
            ptr -> next = new ListNode((temp1 -> val + carry) % 10);
            carry = (temp1 -> val + carry) / 10;
            ptr = ptr -> next;
            temp1 = temp1 -> next;
        }
        while(temp2 != NULL)
        {
            ptr -> next = new ListNode((temp2 -> val + carry) % 10);
            carry = (temp2 -> val + carry) / 10;
            ptr = ptr -> next;
            temp2 = temp2 -> next;
        }
        if(carry == 1)
            ptr -> next = new ListNode(1);
        return head;
    }
};
