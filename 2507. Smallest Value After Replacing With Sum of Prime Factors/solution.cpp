/*
10 ms
6.2 mb
*/

/**
 * @author : SahilK-027
 * @brief : Recursion
*/

class Solution {
    void solve(int n, int& mini, unordered_map<int, bool>& mp){
        // Base case
        if(mp[n] == true){
            return ;
        }
        mp[n] = true;
        int next_num = 0;
        // Logic to find prime factors of n
        int i=2;
        while(n>1)
        {
            if(n % i == 0){
            next_num += i;
            
            n = n / i;
        }
            else i++;
        }
        mini = min(mini, next_num);
        solve(next_num, mini, mp);
    }
public:
    int smallestValue(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int mini = INT_MAX;
        unordered_map<int, bool>mp;
        solve(n, mini, mp);
        return mini;
    }
};