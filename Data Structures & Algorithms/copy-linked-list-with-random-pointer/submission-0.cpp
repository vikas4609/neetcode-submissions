/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;
        Node* curr = head;
        if(!curr) return nullptr;
        Node* newNode = new Node(curr->val);
        Node* answer = newNode;
        mp[curr] = newNode;
        curr = curr->next;
        Node* prev = newNode;
        while(curr){
            newNode = new Node(curr->val);
            mp[curr] = newNode;
            prev->next = newNode;
            curr = curr->next;
            prev = newNode;
        }
        curr = head;
        Node* newcurr = answer;
        while(curr && newcurr){
            newcurr->random = mp[curr->random];
            curr = curr->next;
            newcurr = newcurr->next;
        }
        return answer;
    }
};
