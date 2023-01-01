/*
5 ms
7.1 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : HashMap + Two pointer + Set
*/


/*
TWO PTR + MAP
EX.
pattern = "abba", s = "dog cat cat dog"
map<char, set<string>>
a -> dog
b -> cat
return true    

EX.
pattern = "abba", s = "dog cat cat doc"
map<char, set<string>>
a -> dog, doc
b -> cat
return false 
*/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Fast i/o
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        // Store the letter and its index in pattern
        map<pair<int, string>, int>mp1;
        for(int i = 0 ; i < pattern.length(); i++){
            string temp = "";
            temp += pattern[i];
            pair<int, string> p = make_pair(i, temp);
            mp1[p] = (i);
        }

        // Store the words and its index in s
        map<pair<int, string>, int>mp2;
        int word = 0;
        for(int i = 0 ; i < s.length(); i++){
            string temp = "";
            while(i < s.length() && s[i] != ' '){
                temp += s[i];
                i++;
            }
            pair<int, string> p = make_pair(word, temp);
            mp2[p] = word;
            word++;
        }

        // If both maps are unqual in length means pattern is not matching
        if(mp1.size() != mp2.size()) return false;

        // Create map of set for checking pattern to string
        unordered_map<string, set<string>> res;
        auto j =  mp2.begin();
        for (auto i = mp1.begin(); i != mp1.end(); i++){
            res[i->first.second].emplace(j->first.second);
            j++;
        }

        // Create map of set for checking string to pattern
        unordered_map<string, set<string>> res2;
        j =  mp1.begin();
        for (auto i = mp2.begin(); i != mp2.end(); i++){
            res2[i->first.second].emplace(j->first.second);
            j++;
        }

        // If for a particular character set's size exceeds by 1 means it doesn't follow pattern
        for(auto i: res){
            if(i.second.size() > 1){
                return false;
            }
        }
                    
        for(auto i: res2){
            if(i.second.size() > 1){
                return false;
            }
        }
        return true;
    }
};