class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n,-1);
        vector<int>right(n,n);
        stack<int>ans;
        for(int i = n-1; i >= 0; i--){
            while( !ans.empty() && heights[ans.top()] >= heights[i] ){
                ans.pop();
            }
            if( !ans.empty() ){
            right[i] = ans.top();
            }
            ans.push(i);
        }
        while( !ans.empty() ){
            ans.pop();
        }
        for(int i = 0; i < n; i++){
            while( !ans.empty() && heights[ans.top()] >= heights[i] ){
                ans.pop();
            }
            if( !ans.empty() ){
            left[i] = ans.top();
            }
            ans.push(i);
        }
        int maxi = 0;
        for( int i = 0; i < n; i++){
            int width = right[i] - left[i]-1;
            int area = width * heights[i];
            maxi = max(maxi , area);
        }
        return maxi;
    }
};
