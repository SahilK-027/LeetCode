/*
218 ms
34.2 MB

TC : 0(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Map of set
*/

// Set will conatin unique characters only 
/*
So, if we store {aabb} and {ba} both will get store in set as => {ab},{ab}

After that we are storing this sets and their count in map

If Ex. "abc" occurs four times in map means there are 6 different pairs of Similar Strings i.e 1->2, 1->3, 1->4, 2->3, 2->4, 3->4

So final result will be " result += (n * (n - 1)) / 2 "
*/
class Solution {
public:
    int similarPairs(vector<string>& words) {
        int result =0;
        map<set<char>, int> mp;
        for (auto i : words)
        {
            set<char> st;
            for (auto j : i)
            {
                st.insert(j);
            }
            mp[st]++;
        }

        for(auto i: mp){
            int n = i.second;
            result += (n * (n - 1)) / 2;
        }
        return result;
    }
};