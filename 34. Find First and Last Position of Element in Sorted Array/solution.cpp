// UPPERBOUND AND LOWERBOUND ALGORITHM
// TC: O(log N)
class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int t) {
        int s1 = 0;
        int e1 = arr.size()-1;
        int m1 = s1 + (e1-s1)/2;
        int s2 = s1;
        int e2 = e1;
        int m2 = m1;
        int UPPERBOUND = -1;
        int LOWERBOUND = -1;
        // Calculate Upper Bound and Lower Bound Simultaneously
        while(s1 <= e1 || s2 <= e2){
            // For upper bound
            if(arr[m1] == t ){
                UPPERBOUND = m1;
                // Element may exists behind
                e1 = m1 - 1;   
            }
            else if(arr[m1] > t){
                e1 = m1 -1;
            }
            else if (arr[m1] < t){
                s1 = m1 +1;
            }

            // For lower bound
            if(arr[m2] == t){
                LOWERBOUND = m2;
                // Element may exists ahead
                s2 = m2 + 1; 
            }
            else if(arr[m2] > t){
                e2 = m2 -1;
            }
            else if (arr[m2] < t){
                s2 = m2 +1;
            }
            m1 = s1 + (e1-s1)/2;
            m2 = s2 + (e2-s2)/2;
        }

        // Return ans;
        vector<int> ans;
        ans.push_back(UPPERBOUND);
        ans.push_back(LOWERBOUND);
        return ans;
    }
};