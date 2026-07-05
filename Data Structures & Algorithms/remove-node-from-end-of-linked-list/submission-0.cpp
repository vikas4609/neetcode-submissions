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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int sz = 0;
        while(curr){
            sz++;
            curr = curr->next;
        }
        int k = sz-n;
        if(k == 0) return head->next;
        curr = head;//1
        ListNode* prev;
        while(k){ // 2 1
            prev = curr;//1 2
            curr = curr->next;//2 3
            k--;
        }
        prev->next = curr->next;
        return head;
    }
};
