class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n = nums2.size();

        vector<int> nge(n);
        stack<int> st;

        // Find NGE of nums2
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (st.empty()) {
                nge[i] = -1;
            }
            else {
                nge[i] = st.top();
            }

            st.push(nums2[i]);
        }

        vector<int> ans;

        // Find answers for nums1
        for (int i = 0; i < nums1.size(); i++) {

            for (int j = 0; j < nums2.size(); j++) {

                if (nums1[i] == nums2[j]) {

                    ans.push_back(nge[j]);

                    break;
                }
            }
        }

        return ans;
    }
};