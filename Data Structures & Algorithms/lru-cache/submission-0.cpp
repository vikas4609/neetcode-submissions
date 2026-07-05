class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr){}
};
class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    void insert(Node* node){
        node->next = right;
        right->prev->next = node;
        node->prev = right->prev;
        right->prev = node;
    }

    void remove(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

public:
    LRUCache(int capacity) {
        this->cap = capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* found = cache[key];
            remove(found);
            insert(found);
            return found->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            remove(node);
            cache.erase(key);
        }
        Node* newNode = new Node(key, value);
        insert(newNode);
        cache[key] = newNode;
        if(cache.size() > this->cap){
            cache.erase(left->next->key);
            remove(left->next);
        }
    }
};
