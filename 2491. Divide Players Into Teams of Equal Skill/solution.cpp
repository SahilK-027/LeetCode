// Sort + Two pointer  logic
class Solution {
public:
    long long dividePlayers(vector<int>& arr) {
        long long ans = 0;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        if(arr.size() == 2){
            int i = 0;
            while( i < n ){
                ans = ans + arr[i]*arr[i+1];
                i = i +2;
            }
        }
        else{
            int initial_sum = arr[0] + arr[n-1]; 
            int i = 1 ;
            int j = n-2;
            // Checking if pair can be formed or not
            while(i < j){
                if(arr[i]+arr[j] != initial_sum) return -1;
                i++;
                j--;
            }
            // If we have reached over here means pairs can be formed so finding ans
            i = 0;
            j = n-1;
            while(i < j){
                ans = ans + arr[i]*arr[j];
                i++;
                j--;
            }
        }
        return ans;
    }
};