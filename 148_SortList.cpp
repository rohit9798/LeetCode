Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5



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
    ListNode* merge(ListNode *start1, ListNode *start2)
    {
        ListNode *head = NULL, *start = NULL;
        if(start1 -> val < start2 -> val)
        {
            head = start1;
            start1 = start1 -> next;
        }
        else
        {
            head = start2;
            start2 = start2 -> next;
        }
        start = head;
        while(start1 != NULL && start2 != NULL)
        {
            if(start1 -> val <= start2 -> val)
            {
                start -> next = start1;
                start1 = start1 -> next;
            }
            else
            {
                start -> next = start2;
                start2 = start2 -> next;
            }
            start = start -> next;
        }
        if(start1 != NULL)
            start -> next = start1;
        else
            start -> next = start2;
        return head;
    }
    ListNode* mergeSort(ListNode *start)
    {
        if(start == NULL || start -> next == NULL)
            return start;
        ListNode *mid = start, *prev = NULL, *ptr = start;
        while(ptr != NULL && ptr -> next != NULL)
        {
            prev = mid;
            mid = mid -> next;
            ptr = ptr -> next -> next;
        }
        prev -> next = NULL;
        ListNode *start1 = mergeSort(start);
        ListNode *start2 = mergeSort(mid);
        return merge(start1, start2);
    }
    ListNode* sortList(ListNode* head) {
        
        ListNode *ptr = head;
        head = mergeSort(head);
        return head;
    }
};

