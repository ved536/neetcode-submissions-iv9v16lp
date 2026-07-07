class FreqStack {
public:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>freqwise;
    int max = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        freqwise[freq[val]].push(val);
        if( freq[val] > max ){
            max = freq[val];
        }
    }
    
    int pop() {
        int top = freqwise[max].top();
        freqwise[max].pop();
        freq[top]--;
        if( freqwise[max].empty() ){
            max--;
        }
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */