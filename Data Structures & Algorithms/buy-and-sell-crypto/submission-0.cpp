class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int max_diff = INT_MIN;
        int n = prices.size();
        for( int i = 0; i < n; i++){
            for( int j = i; j < n; j++){
                int pr = (prices[j] - prices[i]);
                max_diff = max(pr,max_diff);      
            }
        }
        return max_diff;
    }

                                        
};
