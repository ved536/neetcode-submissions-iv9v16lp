class StockSpanner {
private:
    stack<pair<int,int>>ans;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int curr = 1;
        while(!ans.empty() && price >= ans.top().first ){
            curr += ans.top().second;
            ans.pop();
        }
        ans.push({price,curr});
        return curr;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */