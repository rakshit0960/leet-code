struct Node {
    int key, val;
    Node* next;
    Node* prev;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = prev = NULL;
    }
};

class LRUCache {
    int size;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

    void InsertNodeBeginning(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void DeleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        delete node;
    }

public:
    LRUCache(int capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = capacity;
    }   
    
    int get(int key) {
        if (!mp.count(key)) return -1;
        int val = mp[key]->val;
        DeleteNode(mp[key]);
        Node* newNode = new Node(key, val);
        InsertNodeBeginning(newNode);
        mp[key] = newNode;
        return val;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            DeleteNode(mp[key]);
        }
        else if (mp.size() >= size) {
            mp.erase(tail->prev->key);
            DeleteNode(tail->prev);
        }
        Node* newNode = new Node(key, value);
        InsertNodeBeginning(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */