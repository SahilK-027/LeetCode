/*
Runtime: 0 ms
Memory Usage: 6.3 MB
*/

class Solution {
private:
    void solve(string digits,vector<string>& ans, string output,string map[],int index = 0){
        //Base case
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        //Recursive call
        int number = digits[index] - '0'; //First extract the number from digits string
        string mapped_string = map[number]; // Find the mapped string for the number
        
        // Push output using for loop
        for(int i = 0; i< mapped_string.length();i++){
            output.push_back(mapped_string[i]);
            solve(digits,ans,output,map,index+1);
            output.pop_back(); // ex. For 23 we only want output strings of length 2
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        //No ditit return empty array
        if(digits.length()==0){
            return ans;
        }
        string output = "";
        string map[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,ans,output,map);
        return ans;
    }
};
