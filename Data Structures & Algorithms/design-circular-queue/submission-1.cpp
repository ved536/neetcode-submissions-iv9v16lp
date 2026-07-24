class MyCircularQueue {
private:
    struct Node{
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr){}
    };
    Node* tail;
    int capacity;
    int count;
public:
    MyCircularQueue(int k) {
        capacity = k;
        tail = nullptr;
        count = 0;    
    }
    
    bool enQueue(int value) {
        if( isFull() ){
            return false;
        }    
        Node* newNode = new Node(value);
        if( isEmpty() ){
            tail = newNode;
            tail->next = tail;
        } 
        else{
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        count++;
        return true;
    }
    
    bool deQueue() {
        if( isEmpty() ){
            return false;
        }
        Node* head = tail->next;
        if( count == 1 ){
            delete head;
            tail = nullptr;
        }
        else{
            tail->next = head->next;
            delete head;
        }
        count--;
        return true;
    }
    
    int Front() {
        if( isEmpty() ){
            return -1;
        }
        return tail->next->val;
    }
    
    int Rear() {
        if( isEmpty() ){
            return -1;
        }
        return tail->val;    
    }
    
    bool isEmpty() {
        return count == 0; 
    }
    
    bool isFull() {
        return count == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */