class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;

        for(int i = 0; i < asteroids.size(); i++) {

            // Positive asteroid
            if(asteroids[i] > 0) {
                st.push(asteroids[i]);
            }

            // Negative asteroid
            else {

                bool destroyed = false;

                while(!st.empty() && st.top() > 0) {

                    if(st.top() < -asteroids[i]) {
                        st.pop();
                    }

                    else if(st.top() == -asteroids[i]) {
                        st.pop();
                        destroyed = true;
                        break;
                    }

                    else {
                        destroyed = true;
                        break;
                    }
                }

                if(!destroyed) {
                    st.push(asteroids[i]);
                }
            }
        }

        vector<int> ans(st.size());

        for(int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};