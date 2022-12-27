/*
392 ms
86.7 MB

TC : O(N Log N)
SC : O(N) (Little space optimization can be done if we do all the calculations in capacity array itself)
*/

/**
 * @author : SahilK-027
 * @brief : Sorting 
*/

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        // Store answer
        int cnt = 0;
        int n = capacity.size();
        // We will fill that bag first which will has less difference of capacity[i] and rocks[i]
        vector<int> diff(n,-1);
        for(int i = 0 ; i < n; i++){
            diff[i] = capacity[i] - rocks[i];
        }
        sort(diff.begin(), diff.end());
        int i = 0;
        // While number of rocks availabel is grrater than 0
        while(i < n && additionalRocks > 0 ){
            // If its valid to add rock to bag 
            if(additionalRocks >= diff[i]){
                cout<<additionalRocks<<endl;
                additionalRocks -= diff[i];
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};