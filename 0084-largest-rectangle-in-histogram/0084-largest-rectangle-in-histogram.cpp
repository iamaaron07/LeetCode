class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxi = 0;

        for(int i=0; i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse;
                if(st.empty()){
                    pse = -1;
                }
                else{
                    pse = st.top();
                }
                int area = heights[element] * (nse-pse-1);
                maxi = max(maxi , area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int element = st.top();
            st.pop();
            int pse;
            if(st.empty()){
                pse = -1;
            }
            else{
                pse = st.top();
            }
            int area = heights[element] * (nse-pse-1);
            maxi = max(maxi , area);
        }
        return maxi;
    }
};