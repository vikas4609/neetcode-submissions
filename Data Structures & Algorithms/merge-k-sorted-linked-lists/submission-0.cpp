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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* answer = nullptr;
        if(!list1 && !list2){
            return answer;
        }
        if(!list1){
            answer = list2;
            list2 = list2->next;
        }else if(!list2){
            answer = list1;
            list1 = list1->next;
        }else{
            //answer = list1->val <= list2->val ? list1 : list2;
            if(list1->val <= list2->val){
                answer = list1;
                list1 = list1->next;
            }else {
                answer = list2;
                list2 = list2->next;
            }
        }
        ListNode* curr = answer;
        while(list1 || list2){
            if(!list1){
                while(list2){
                    curr->next = list2;
                    curr = curr->next;
                    list2 = list2->next;
                }
            }
            if(!list2){
                while(list1){
                    curr->next = list1;
                    curr = curr->next;
                    list1 = list1->next;
                }
            }
            while(list1 && list2 && list1->val <= list2->val){
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            }
            while(list1 && list2 && list1->val > list2->val){
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }
        }
        return answer;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        if(lists.size() == 1){
            if(lists[0]){
                return lists[0];
            }else{
                return nullptr;
            }
        }
        ListNode* answer = lists[0];
        for(int i=1;i<lists.size();i++){
            answer = mergeTwoLists(answer, lists[i]);
        }
        return answer;
    }
};
