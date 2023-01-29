/*
147 ms
64 MB
*/

/**
 * TC: O(n log n)
 * SC: O(n)
 */

/**
 * @author : SahilK-027
 * @brief :  Sorting
*/

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // Fast i/o
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = weights.size();
        // If k == 1 means there is only one bag so differnce between min and max will be 0
        if(k == 1) return 0;
        // If k == n means there are n bags so each bag will contain 1 marble. 
        // Since there is just one possible distribution, the difference between the one with maximum score
        // and the one with minimum score would obviously 0.
        if(k == n) return 0;
        // The first and the last marble will always get distributed
        // We have to distribute remaining n - 2 marbles in k groups
        // We will divide n-2 marbles with k-1 bars
        // ex n = 10 and k = 3,  no. of bars =2  [1,2,3 | 4,5,6,7 | 8,9,10]

        // When we put a bar after i-th marble, 
        // the score of such distribution would increase by weights[i]+weights[i+1].

        // record weights[i]+weights[i+1] for each 0≤ i <n−1 
        // sort them, select k−1 smallest/largest ones from them, and find the difference in score.
        vector<int>marbles_distribution;
        for(int i = 0 ; i < n -1 ; i++){
            marbles_distribution.push_back(weights[i] + weights[i+1]);
        }
        sort(marbles_distribution.begin(), marbles_distribution.end());

        long long int mini = 0;
        long long int maxi = 0;
        for(int i = 0 ; i < k-1 ; i++){
            mini += marbles_distribution[i];
            // TO Get last k elements we would do n - i. but as it is 0 based index it becoms n - i - 1
            // further more as we are having n marbles so n - 1 gaps to place bar so last k element becomes 
            // n - i - 1 - 1 ==== n - i - 2
            maxi += marbles_distribution[n - i - 2];
        }

        return maxi - mini;

    }
};