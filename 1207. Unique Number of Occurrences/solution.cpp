/*
0 ms
8.3 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Hashing
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map; //<item, occurence>
        unordered_set<int> set;
        
// For each element in an array        
        for(int i = 0;i<arr.size();i++)
        {
            int item = arr[i];
// if item found in map increment value associated with it..So, that we can store its number of occurences              
            if(map.find(item) != map.end())
            {
                map[item]++; 
            }
// Else means element not found in map so insert it in map with its occurence count 0            
            else
            {
                map.emplace(item,0);
            }
// For each element in map push no. of occurences in a set as set contains only unique values            
        }
        for(auto i : map){
            set.emplace(i.second);
        }
//Finally If, after the insert, the sizes of hash map and set are equal, then all occurences are unique.         
        if(set.size()==map.size()){
            return true;
        }
        return false;
    }
};