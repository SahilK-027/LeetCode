/*
3 ms
26.7 MB
*/
/**
 * TC: O(n)
 * SC: O(n)
*/
/**
 * @author : SahilK-027
 * @brief : Unordered_set
 */

// In square distance between all sides are equal and distance between two diagonals is equal
// So we will store the distances in set and check if size of set is 2 or not
class Solution {
private: 
    int distance(vector<int>& p1, vector<int>& p2){
        return ((p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]));
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> validate;
        validate.insert(distance(p1, p2));
        validate.insert(distance(p2, p3));
        validate.insert(distance(p3, p4));
        validate.insert(distance(p1, p4));
        validate.insert(distance(p1, p3));
        validate.insert(distance(p2, p4));
        return !validate.count(0) && validate.size() == 2 ? true : false;
    }
};