/*
3 ms
7.2 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Iteration
*/

class Solution {
public:
    double average(vector<int>& salary) {
        if(salary.size()==2) return 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        double sum = 0;
        for(auto x: salary){
            mini = min(mini,x);
            maxi = max(maxi,x);
            sum += (double)x;
        }
        return (sum - (mini + maxi)) / (salary.size()-2);
    }
};