/*
286 ms
82 MB
*/
/**
 * TC: O(k log n)
 * SC: O(n)
*/
/**
 * @author : SahilK-027
 * @brief : Two heap problem
 */


/*
* Special pattern of problem: Two heap problem
*/
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // These projects we cannot affort right now but may be in future we can
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>minCapital;
        for(int i = 0 ; i < capital.size(); i++){
            minCapital.push(make_pair(capital[i], profits[i]));
        }
        // These are the projects we can afford right now
        priority_queue<int>maxProfit;  

        // looping k times
        while(k--){
            // While curr capital is less than w
            while(!minCapital.empty() && minCapital.top().first <= w){
                // take current profit ans push it on maxProfit
                pair<int, int> top = minCapital.top();
                minCapital.pop();
                int curr_capital = top.first;
                int curr_profit = top.second;
                maxProfit.push(curr_profit);
            }
            // Update the answer
            if(maxProfit.empty()){
                break;
            }
            w += maxProfit.top();
            maxProfit.pop();
        }
        return w;
    }
};