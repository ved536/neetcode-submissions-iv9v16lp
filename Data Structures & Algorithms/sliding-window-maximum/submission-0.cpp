class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // Stores indices of elements, keeping them in a decreasing order
        
        for (int j = 0; j < nums.size(); j++) {
            // 1. Maintain the decreasing order in our deque
            // Remove any elements from the back that are smaller than the incoming nums[j]
            while (!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }
            
            // 2. Add the current element's index to the back of the window tracking
            dq.push_back(j);
            
            // 3. Remove the front element if it has slid completely out of the left bound
            if (dq.front() < j - k + 1) {
                dq.pop_front();
            }
            
            // 4. Once our window hits size k, the front element is our maximum
            if (j >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};
