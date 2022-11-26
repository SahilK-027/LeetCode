\class Solution {
public:
    int lengthOfLastWord(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int last_word_len = 0;
        int curr = 0;
        int i = 0;
        int j = s.length()-1;
        while(s[i] == ' '){
            i++;
        }
        while(s[j] == ' '){
            j--;
        }
        for(int x = i; x <= j; x++){
            if(s[x] == ' ' && curr){
                last_word_len = curr;
                curr = 0;
            }
            else{
                if(s[x] == ' '){
                    curr = 0;
                }
                else{
                    curr++;
                }
            }
        }
        if(curr != last_word_len){
            last_word_len = curr;
        }
        cout<<curr;
        return last_word_len;
    }
};