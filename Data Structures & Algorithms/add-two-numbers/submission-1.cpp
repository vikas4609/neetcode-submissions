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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1 = l1;
        int c1 = 0;
        while(n1){
            c1++;
            n1 = n1->next;
        }
        n1 = l2;
        int c2 = 0;
        while(n1){
            c2++;
            n1 = n1->next;
        }
        ListNode* head = c1 >= c2 ? l1 : l2;
        ListNode* other = c1 >= c2 ? l2 : l1;
        n1 = head;
        ListNode* last = head;
        int carry = 0;
        while(n1){
            int add = (other ? other->val : 0) + n1->val + carry;
            n1->val = add%10;
            carry = add/10;
            if(other){
                other = other->next;
            }
            last = n1;
            n1 = n1->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(carry);
            last->next = newNode;
        }
        return head;
    }
};
