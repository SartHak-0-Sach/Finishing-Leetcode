#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         // Get the sizes of both input arrays.
//         int n = nums1.size();
//         int m = nums2.size();

//         // Merge the arrays into a single sorted array.
//         vector<int> merged;
//         for (int i = 0; i < n; i++) {
//             merged.push_back(nums1[i]);
//         }
//         for (int i = 0; i < m; i++) {
//             merged.push_back(nums2[i]);
//         }

//         // Sort the merged array.
//         sort(merged.begin(), merged.end());

//         // Calculate the total number of elements in the merged array.
//         int total = merged.size();

//         if (total % 2 == 1) {
//             // If the total number of elements is odd, return the middle element as the median.
//             return static_cast<double>(merged[total / 2]);
//         } else {
//             // If the total number of elements is even, calculate the average of the two middle elements as the median.
//             int middle1 = merged[total / 2 - 1];
//             int middle2 = merged[total / 2];
//             return (static_cast<double>(middle1) + static_cast<double>(middle2)) / 2.0;
//         }
//     }
// };

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();
//         int i = 0, j = 0, m1 = 0, m2 = 0;

//         // Find median.
//         for (int count = 0; count <= (n + m) / 2; count++) {
//             m2 = m1;
//             if (i != n && j != m) {
//                 if (nums1[i] > nums2[j]) {
//                     m1 = nums2[j++];
//                 } else {
//                     m1 = nums1[i++];
//                 }
//             } else if (i < n) {
//                 m1 = nums1[i++];
//             } else {
//                 m1 = nums2[j++];
//             }
//         }

//         // Check if the sum of n and m is odd.
//         if ((n + m) % 2 == 1) {
//             return static_cast<double>(m1);
//         } else {
//             double ans = static_cast<double>(m1) + static_cast<double>(m2);
//             return ans / 2.0;
//         }
//     }
// };

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        // Ensure nums1 is the smaller array for simplicity
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        
        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2; // Calculate the left partition size
        int low = 0, high = n1;
        
        while (low <= high) {
            int mid1 = (low + high) >> 1; // Calculate mid index for nums1
            int mid2 = left - mid1; // Calculate mid index for nums2
            
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            
            // Determine values of l1, l2, r1, and r2
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            
            if (l1 <= r2 && l2 <= r1) {
                // The partition is correct, we found the median
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2) {
                // Move towards the left side of nums1
                high = mid1 - 1;
            }
            else {
                // Move towards the right side of nums1
                low = mid1 + 1;
            }
        }
        
        return 0; // If the code reaches here, the input arrays were not sorted.
    }
};
