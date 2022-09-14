/*
Runtime: 23 ms
Memory Usage: 8.9 MB
*/

class Solution {
public:
    int romanToInt(string s) {
        int n = s.length()-1;
        int ans=0;
        unordered_map<char,int> map={ { 'I' , 1 },{ 'V' , 5 },
        { 'X' , 10 }, { 'L' , 50 }, { 'C' , 100 }, { 'D' , 500 },
        { 'M' , 1000 } };
        for(int i = n ; i>=0;i--){
           if (map[s[i]] < map[s[i + 1]])
                ans -= map[s[i]]; //For IV case we cannot add 1+5 we have to subtract
            else
                ans += map[s[i]];
        }
        return ans;
    }
};
