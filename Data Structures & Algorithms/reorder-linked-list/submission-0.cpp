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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;
        while(curr){
            st.push(curr);
            curr = curr->next;
        }
        curr = head;
        ListNode* stk;
        ListNode* temp1;
        int n = st.size();
        if(n>1){
            int k = n/2;
            while(k){
                stk = st.top();//8,6
                temp1 = curr->next;//4,6
                curr->next = stk;//2->8, 4->6
                stk->next = temp1;//8->4, 6->6
                curr = temp1;//4
                st.pop();
                k--;
            }
            if(n%2 == 0){
                stk->next = nullptr;
            }else{
                stk->next = curr;
                curr->next = nullptr;
            }
        }
    }
};
