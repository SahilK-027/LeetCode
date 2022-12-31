/*
368 ms
116 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Prefix sum
*/

// Creating Table 
/*
indx        0   1   2   3   4   5
element     2   5   3   9   5   3
avg ->      2   3   3   4   4   4
avg <-      5   5   5   4   3   0
diff        3   2   2   0   1   4
ans = 3

We will keep track of sum and count of element for finding average
*/
class Solution {
public:
    int minimumAverageDifference(vector<int>& arr) {
        // Traveling Left to right to calculate average
        int n = arr.size();
        int cnt = 1;
        long long sum = 0;
        vector<long long>avg_L2R;
        for(int i = 0 ;i < n ; i++){
            int element = arr[i];
            long long avg = (sum + arr[i]) / cnt;
            avg_L2R.push_back(avg);
            sum += arr[i];
            cnt++;
        }

        // Traveling right to left to calculate average
        sum = 0;
        cnt = 1;
        vector<long long>avg_R2L;
        for(int i = n-1 ;i > 0 ; i--){
            int element = arr[i];
            long long avg = (sum + arr[i]) / cnt;
            avg_R2L.push_back(avg);
            sum += arr[i];
            cnt++;
        }
        reverse(avg_R2L.begin(), avg_R2L.end());
        avg_R2L.push_back(0);

        // Calculting abs diff
        vector<int>abs_diff;
        int i = 0 ; 
        int j = 0 ;
        while(i < avg_L2R.size()){
            int diff = abs(avg_L2R[i] - avg_R2L[j]);
            abs_diff.push_back(diff);
            i++;
            j++;
        }
        
        // Finding minimum from abs_diff
        int min = INT_MAX;
        int min_index = -1;
        for(int i = 0 ; i < abs_diff.size(); i++){
            if(abs_diff[i] < min){
                min = abs_diff[i];
                min_index = i;
            }
        }
        return min_index;
    }
};