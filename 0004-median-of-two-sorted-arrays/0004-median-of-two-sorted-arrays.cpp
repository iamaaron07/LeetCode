class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Always binary search on the smaller array
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0;
        int high = n1;

        int left = (n1 + n2 + 1) / 2;
        int n = n1 + n2;

        while (low <= high) {

            // Partition of nums1
            int mid1 = (low + high) / 2;

            // Partition of nums2
            int mid2 = left - mid1;

            // Elements just outside the partitions
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            // Right side of nums1
            if (mid1 < n1)
                r1 = nums1[mid1];

            // Right side of nums2
            if (mid2 < n2)
                r2 = nums2[mid2];

            // Left side of nums1
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];

            // Left side of nums2
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];

            // Correct partition
            if (l1 <= r2 && l2 <= r1) {

                // Odd total number of elements
                if (n % 2 == 1) {
                    return max(l1, l2);
                }

                // Even total number of elements
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }

            // We have taken too many elements from nums1
            else if (l1 > r2) {
                high = mid1 - 1;
            }

            // We need to take more elements from nums1
            else {
                low = mid1 + 1;
            }
        }

        return 0.0;
    }
};