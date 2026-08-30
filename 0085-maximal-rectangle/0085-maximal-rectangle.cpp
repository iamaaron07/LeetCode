class Solution {
public:

    // Largest Rectangle in Histogram
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        stack<int> st;
        int maxi = 0;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[st.top()] > heights[i]) {

                int element = st.top();
                st.pop();

                int nse = i;

                int pse;

                if(st.empty())
                    pse = -1;
                else
                    pse = st.top();

                int area = heights[element] * (nse - pse - 1);

                maxi = max(maxi, area);
            }

            st.push(i);
        }

        // Remaining elements have NSE = n
        while(!st.empty()) {

            int element = st.top();
            st.pop();

            int nse = n;

            int pse;

            if(st.empty())
                pse = -1;
            else
                pse = st.top();

            int area = heights[element] * (nse - pse - 1);

            maxi = max(maxi, area);
        }

        return maxi;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        // This is the psum array from the video
        vector<vector<int>> psum(n, vector<int>(m, 0));

        int maxi = 0;

        // Build vertical prefix sum
        for(int j = 0; j < m; j++) {

            int sum = 0;

            for(int i = 0; i < n; i++) {

                if(matrix[i][j] == '1') {
                    sum += 1;
                }
                else {
                    sum = 0;
                }

                psum[i][j] = sum;
            }
        }

        // Treat every row of psum as a histogram
        for(int i = 0; i < n; i++) {

            vector<int> heights = psum[i];

            int area = largestRectangleArea(heights);

            maxi = max(maxi, area);
        }

        return maxi;
    }
};