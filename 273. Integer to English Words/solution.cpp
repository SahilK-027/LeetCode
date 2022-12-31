/*
13 ms
8.2 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
*/

class Solution {
private:
    string solve(int n, unordered_map<int, string>&mp){
        // Base case
        if(n == 0){
            return "";
        }
        // Recursion
        if(n >= 1000000000){
            return solve(n / 1000000000, mp) + mp[1000000000] + solve(n % 1000000000, mp);
        }   
        else if(n >= 1000000){
            return solve(n / 1000000,mp) + mp[1000000] + solve(n % 1000000,mp);
        } 
        else if(n >= 1000){
            return solve(n / 1000,mp) + mp[1000]+ solve(n % 1000 ,mp);
        }   
        else if(n >= 100){
            return solve(n / 100, mp) + mp[100] + solve(n % 100,mp);
        }     
        else if(n >= 20){
            return mp[(n / 10) * 10] + solve(n % 10 ,mp);
        }     
        else {
            return mp[n];
        }       
    }
public:
    string numberToWords(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if(n == 0){
            return "Zero";
        }
        unordered_map<int, string>mp;
        mp = {{1, " One"},  {2, " Two"}, {3, " Three"},{4, " Four"},{5, " Five"},{6, " Six"}, {7, " Seven"},{8, " Eight"},{9, " Nine"},{10, " Ten"},
        {11, " Eleven"},{12, " Twelve"}, {13, " Thirteen"},{14, " Fourteen"},{15, " Fifteen"},{16, " Sixteen"},{17, " Seventeen"},{18, " Eighteen"},
        {19, " Nineteen"}, {20, " Twenty"},{30, " Thirty"},{40, " Forty"},{50, " Fifty"},{60, " Sixty"},{70," Seventy"},{80," Eighty"}, {90, " Ninety"}, 
        {100," Hundred"}, {1000, " Thousand"}, {1000000," Million"},{1000000000," Billion"}};
        string ans = solve(n, mp);
        return ans.substr(1,ans.length());
    }
};