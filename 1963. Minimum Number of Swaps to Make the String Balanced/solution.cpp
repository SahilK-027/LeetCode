/*
107 ms
31.2 mb
*/

/**
 * @author : Sahilk-027
 * @brief : Using Recursion and backtracking.
*/

/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    int minSwaps(string s) {
        // Fast i/o
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // Cnt will keep track of number of invalid parenthesis
        int cnt = 0;
        int min_swaps = INT_MIN;
        for(auto i : s){
            if(i == ']'){
                // If we get close backet before opening bracket means invalid parenthesis
                cnt++;
            }
            else{
                // Else make 1 invalid parenthesis valid so cnt is incremented
                cnt--;
            }
            if(cnt > min_swaps){
                min_swaps = cnt;
            }
        }
        // In one swap we are cancelling out two brackets
        return (min_swaps + 1) /2;
    }
};