/*
4 ms
6.2 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : String traversal
*/

class Solution {
private:
    // Function to check character is capital or not
    bool isCapital(char ch){
        return(int(ch) >= 65 && int(ch) <= 90);
    }
    // Function to check character is small or not
    bool isSmall(char ch){
        return(int(ch) >= 97 && int(ch) <= 122);
    }
public:
    bool detectCapitalUse(string word) {
        // Fast i/o
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        // If first character is capital
        if(isCapital(word[0])){
            // If second character is also captial 
            // We need to check if all next are capital or not.. 
            // If any of the next characters is small return false
            if(isCapital(word[1])){
                for(int i = 2; i < word.length(); i++){
                    if(isSmall(word[i])){
                        return false;
                    }
                }
            }
            // If second character is small
            // We need to check if all next are small or not.. 
            // If any of the next characters is capital return false
            else{
                for(int i = 2; i < word.length(); i++){
                    if(isCapital(word[i])){
                        return false;
                    }
                }
            }
        }

        // First letter is small
        // We need to check if all next are small or not
        // If any of the next characters is capital return false
        else{
            for(int i = 1; i < word.length(); i++){
                if(isCapital(word[i])){
                    return false;
                }
            }
        }

        // Haven't retured false yet
        // This means string is Valid
        return true;
    }
};