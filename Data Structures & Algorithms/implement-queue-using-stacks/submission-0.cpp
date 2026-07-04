class MyQueue {
private: 
        stack<int>main;
        stack<int>helper;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while( !main.empty() ) {
            helper.push(main.top());
            main.pop();
        }
        main.push(x);
        while( !helper.empty() ){
            main.push(helper.top());
            helper.pop();
        }
    }
    
    int pop() {
        int no = main.top();
        main.pop();
        return no;
    }
    
    int peek() {
        return main.top();
    }
    
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */