class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if(n<=2){
            return 0;
        }

        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for(int j = 1; j<n ; j++){
            leftMax[j] = max(leftMax[j-1], height[j]);
        }

        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];
        for(int k=n-2 ; k>=0; k--){
            rightMax[k] = max(rightMax[k+1], height[k]);
        }

        int total = 0;

        for(int i = 0;i<n; i++){
            total = total + min(leftMax[i] , rightMax[i]) - height[i];
        }
        return total;
    }
};