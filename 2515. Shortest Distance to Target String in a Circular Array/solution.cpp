/*
46 ms
19.9 MB
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution 
*/

class Solution {
private:
    int solve(vector<string>& arr,int i, string t, int n, unordered_map<int, bool>& visited){
        // If standing on target return 0
        if(arr[i] == t){
            return 0;
        }
        // If prvious value is already visited don't visit other wise you will stuck in loop so return any large number
        if(visited[i]){
            return 1000;
        }
        visited[i] = true;
        // Find left ans and right ans and return min
        int left_ans = 1 + solve(arr, (i - 1 + n)%n, t, n, visited);
        int right_ans = 1 + solve(arr, (i + 1)%n, t, n, visited);
        return min(left_ans, right_ans);
    }
public:
    int closetTarget(vector<string>& arr, string t, int i) {
        // Checking if the target exists in array or not
        int flag = 0;
        for(auto i: arr){
            if(i == t){
                flag = 1;
            }
        }
        // If target doesn't exixts return -1
        if(!flag){
            return -1;
        }
        int n = arr.size();
        unordered_map<int, bool>visited;
        // Solve otherwise
        return solve(arr, i, t, n, visited);
    }
};