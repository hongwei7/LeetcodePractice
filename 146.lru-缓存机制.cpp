/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start

class Node {
public: 
    Node(int akey, int val) 
    : key(akey), value(val){}
    int key;
    int value;
    Node* previous, *next;
};

class LRUCache {
private:
    Node *root, *tail;
    unordered_map<int, Node*> m;
    int cap;
public:
    LRUCache(int capacity) 
    : cap(capacity), root(new Node(-1, -1)), tail(new Node(-1, -1)) {
        root->next = tail;
        tail->previous = root;
    }

    void insertToHead(int key, Node* node) {
        Node* next = root->next;
        root->next = node;
        node->next = next;
        node->previous = root;
        next->previous = node;
        m[key] = node;
    }

    void remove(int key) {
        Node *node = m[key];
        node->previous->next = node->next;
        node->next->previous = node->previous;
        m.erase(key);
    }
    
    int get(int key) {
        auto iter = m.find(key);
        if(iter == m.end()) {
            return -1;
        }
        Node* node = iter->second;
        this->remove(key);
        this->insertToHead(key, node);
        return node->value;
    }
    
    void put(int key, int value) {
        auto iter = m.find(key);
        if(iter != m.end()) {
            iter->second->value = value;
            Node* node = iter->second;
            this->remove(key);
            this->insertToHead(key, node);
            return;
        }
        if(cap == m.size()) {
            Node* node = tail->previous;
            this->remove(node->key);
            node->value = value;
            node->key = key;
            this->insertToHead(key, node);
            return;
        }
        Node* node = new Node(key, value);
        this->insertToHead(key, node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
