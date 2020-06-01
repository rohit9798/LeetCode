Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5



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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head == NULL)
            return head;
        ListNode *ptr = head;
        while(ptr != NULL && ptr -> val == val)
            ptr = ptr -> next;
        head = ptr;
        while(ptr != NULL && ptr -> next != NULL)
        {
            if(ptr -> next -> val == val)
                ptr -> next = ptr -> next -> next;
            else
                ptr = ptr -> next;
        }
        return head;
    }
};
