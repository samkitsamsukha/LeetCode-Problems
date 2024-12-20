/*
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]



Constraints:

    The number of nodes in the list is n.
    1 <= k <= n <= 105
    0 <= Node.val <= 100

*/

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
    ListNode* swapNodes(ListNode* head, int k) {
        int c = 0, d1, d2;
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        if(head->next->next == nullptr){
            ListNode* temp = head->next;
            temp->next = head;
            head->next = nullptr;
            return temp;
        }
        ListNode* temp = head;
        int len = 0;
        while(temp != nullptr){
            len++;
            temp = temp->next;
        }
        cout << len;
        int l = len-k+1;
        temp = head;
        ListNode* t1;
        ListNode* t2;
        while(temp != nullptr){
            k--;
            l--;
            if(k == 0) t1 = temp;
            if(l == 0) t2 = temp;
            temp = temp->next;
        }
        int x = t1->val;
        t1->val = t2->val;
        t2->val = x;
        return head;
    }
};