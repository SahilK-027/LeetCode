/*
3 ms
5.9 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : SWITCH
*/

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for(int i = 0 ; i < s.length(); i++){
            char ch = s[i];
            switch(ch){
                case 'V':
                    ans += 5;
                    break; 
                case 'L':
                    ans += 50;
                    break; 
                case 'D':
                    ans += 500;
                    break; 
                case 'M':
                    ans += 1000;
                    break; 
                case 'I':
                    if(i < s.length()-1 && (s[i+1] == 'V' || s[i+1] == 'X')){
                        char next_ch = s[i+1];
                        if(next_ch == 'V'){
                            ans += 4;
                            i++;
                        }
                        else if(next_ch == 'X'){
                            ans += 9;
                            i++;
                        }
                    }
                    else {
                        ans += 1;
                    }
                    break; 
                case 'X':
                    if(i < s.length()-1 && (s[i+1] == 'L' || s[i+1] == 'C')){
                        char next_ch = s[i+1];
                        if(next_ch == 'L' ){
                            ans += 40;
                            i++;
                        }
                        else if(next_ch == 'C'){
                            ans += 90;
                            i++;
                        }
                    }
                    else {
                        ans += 10;
                    }
                    break; 
                case 'C':
                    if(i < s.length()-1 && (s[i+1] == 'D' || s[i+1] == 'M')){
                        char next_ch = s[i+1];
                        if(next_ch == 'D'){
                            ans += 400;
                            i++;
                        }
                        else if(next_ch == 'M'){
                            ans += 900;
                            i++;
                        }
                    }
                    else {
                        ans += 100;
                    }
                    break; 
            }
        }
        return ans;
    }
};
