class MinStack {
private:
    stack<pair<int,int>>ans;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if( ans.empty() ){
            ans.push( {val,val} );
        }
        else{
            int mini = min(ans.top().second,val);
            ans.push( {val,mini} );
        }
    }
    
    void pop() {
        ans.pop();    
    }
    
    int top() {
        return ans.top().first;
    }
    
    int getMin() {
        return ans.top().second;
    }
};
