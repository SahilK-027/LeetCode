/*
870 ms
7.5 MB

*/

/**
 * @author : SahilK-027
 * @brief : Recursion and Backtracking
*/

class Solution {
private:
    int getMax(vector<int>& arr){
        int max = INT_MIN;
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }
        return max;
    }

    void solve(vector<int>& jobs, int k, int n, vector<int>& work, int OneAssignmentAns, int& final_ans, int index = 0){
        // Base case
        if(index == n){
            OneAssignmentAns = getMax(work);
            final_ans = min(final_ans, OneAssignmentAns);
            return;
        }

        // Optimization - 1
        // If at any point of time our max of work is getting greater than our final_ans then it cannot be the solution as we meed to find final_ans as minimum as possible
        if(getMax(work) >= final_ans){
            return;
        }

        // For all k workers
        for(int j = 0; j < k ;j++){
            // Optimization - 2 Saving Mirror Calls (Pruning)
            if(j > 0 && work [j] == work[j-1]){
                continue;
            }
            // Action
            work[j] += jobs[index];
            // Recursive call
            solve(jobs, k, n, work, OneAssignmentAns, final_ans, index+1);
            // Backtrack
            work[j] -= jobs[index];
        }

    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        // If we have n jobs and n workers then its optimal assignment will be to assign 1 job to each worker so ans will be maximum of all job times
        int n = jobs.size();
        if(n == k){
            return getMax(jobs);
        }
        // Each worker can get at a time k jobs
        vector<int> work(k, 0);
        int OneAssignmentAns = INT_MIN;
        int Final_Ans = INT_MAX;
        solve(jobs, k, n, work, OneAssignmentAns, Final_Ans);
        return Final_Ans;
    }
};
