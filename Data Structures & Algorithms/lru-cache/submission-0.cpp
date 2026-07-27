class LRUCache {
private : 
    struct Node{
        int val;
        int key;
        Node* next;
        Node* prev;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr){}
    };
    int limit;
    unordered_map<int,Node*>cache;
    Node* head;
    Node* tail;
    void add(Node* node){
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node; 
    }
    void removeNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void movetohead(Node* node){
        removeNode(node);
        add(node);
    }
    Node* pop(){
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }
public:
    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        auto itr = cache.find(key);
        if(itr == cache.end()){
            return -1;
        }
        Node* node = itr->second;
        movetohead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        auto itr = cache.find(key);
        if(itr != cache.end()){
            Node* node = itr->second;
            movetohead(node);
            node->val = value;
        }
        else{
            Node* node = new Node(key, value);
            add(node);
            cache[key] = node;
        }
        if( cache.size() > limit){
            Node* lruNode = pop();
            cache.erase(lruNode->key);
            delete lruNode;
        }
    }
};
