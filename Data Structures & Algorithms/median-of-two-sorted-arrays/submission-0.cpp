class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        int totalHalf = (m + n + 1) / 2;
        
        while (left <= right) {
            int i = left + (right - left) / 2; // Binary search midpoint (partition for nums1)
            int j = totalHalf - i;             // Corresponding partition for nums2
            
            // Handle edge cases where partitions fall on the boundaries (0 or max size)
            int nums1LeftMax  = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
            
            int nums2LeftMax  = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2RightMin = (j == n) ? INT_MAX : nums2[j];
            
            // Valid partition condition found
            if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
                // Odd total number of elements
                if ((m + n) % 2 != 0) {
                    return std::max(nums1LeftMax, nums2LeftMax);
                }
                // Even total number of elements
                else {
                    return (std::max(nums1LeftMax, nums2LeftMax) + 
                            std::min(nums1RightMin, nums2RightMin)) / 2.0;
                }
            }
            // If nums1's left side is too large, move partition left
            else if (nums1LeftMax > nums2RightMin) {
                right = i - 1;
            }
            // If nums1's left side is too small, move partition right
            else {
                left = i + 1;
            }
        }
        
        return 0.0;    
    }
};
