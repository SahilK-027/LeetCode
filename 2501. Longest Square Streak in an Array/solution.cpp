/**
 * @author : Sahilk-027
 * @brief : Using hashmap to keep track of element exists in array so that we can fecth if the square of element exists in array in O(1)
*/

class Solution {
public:
    int longestSquareStreak(vector<int>& arr) {
        unordered_map<unsigned long long int, int> mp;
        for(int i = 0 ; i < arr.size() ; i++){
            mp[arr[i]]++;
        }
        int maxi = INT_MIN;
        for(int i = 0 ; i < arr.size() ; i++){
            int cnt = 1;
            unsigned long long int element = arr[i];
            unsigned long long int ele_sq = element * element;
            // If hashmap has square of num count++
            while(mp[ele_sq] != 0){
                element = ele_sq;
                ele_sq = element * element;
                cnt++;
            }
            // We have to return max count
            maxi = max(maxi, cnt);
        }
        if(maxi == 1){
            return -1;
        }
        return maxi;
    }
};
