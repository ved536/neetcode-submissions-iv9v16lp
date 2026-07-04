class MyStack {
private:
        queue<int>main;
        queue<int>helper;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        helper.push(x);
        while(!main.empty()) {
            helper.push(main.front());
            main.pop();
        }
        swap(main,helper);
    }
    
    int pop() {
        int top_el = main.front();
        main.pop();
        return top_el;
    }
    
    int top() {
        return main.front();
    }
    
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */