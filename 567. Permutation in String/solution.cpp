class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int window_size = s1.length();
        map<char, int>mp;
        for(int i = 0 ;i < s1.length();i++){
            if(mp.find(s1[i]) == mp.end()){
                mp[s1[i]] = 1;
            }
            else{
                mp[s1[i]]++;
            }
        }
        int i = 0, j = 0;
        int count = mp.size();
        while(j < s2.size()){
            if(mp.find(s2[j]) != mp.end()){      
              //If a character is found that already exists in the map, reduce its count by one.
                mp[s2[j]]--;
                if(mp[s2[j]] == 0){     
              //If the count of a specific character on the map is 0, it means that all occurrences of that character is found inside the current window size.
                    count--;
                }
            }
            if(j-i+1 < window_size){
                j++;
            }
            else if(j-i+1 == window_size){
				if(count == 0){    // Permutation found 
					return true;  
				}
                if(mp.find(s2[i]) != mp.end()){  //Check if that character is present in the map while sliding the window
                    mp[s2[i]]++;
                    if(mp[s2[i]] == 1){
                        // then increase its count by one, as we decreased its frequency when we first met it while crossing the window.
                        count++;
                    }
                }
                i++;
                j++;
            }
        }
        return false;
    }
};