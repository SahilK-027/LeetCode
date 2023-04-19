/*
Runtime : 300 ms
Memory : 99.9 MB

TC: O(N log N)
SC: O(1)
*/

/**
 * @author : Sahilk-027
 * @brief : Binary search
*/

// if a spell and potion pair is successful, then the spell and all stronger potions will be successful too.
// Thus, for each spell, we need to find the potion with the least strength that will form a successful pair.
class Solution {
private:
    void binarySearch(vector<int>& spells, vector<int>& potions, long long& success, vector<int>& ans, int &i, int& n){
        int s = 0;
        int e = potions.size()-1;
        int m = s + (e-s)/2;
        while(s <= e)
        {
            if(potions[m] * 1ll * spells[i]  >= success){
                e = m - 1;
            }
            else if(potions[m] * 1ll * spells[i] < success){
                s = m + 1;
            }
            m = s + (e-s)/2;
        }
        ans.push_back(n - s);
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int n = potions.size();
        for(int i = 0; i < spells.size(); i++){
            binarySearch(spells, potions, success, ans, i, n);
        }
        return ans;
    }
};