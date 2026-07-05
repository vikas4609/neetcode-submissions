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
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        bool visited = false;
        while(slow && fast && fast->next){
            if(visited && slow == fast){
                return true;
            }else{
                slow = slow->next;
                fast = fast->next->next;
                visited = true;
            }
        }
        return false;
    }
};
