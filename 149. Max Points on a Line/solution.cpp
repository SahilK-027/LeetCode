/*
125 ms
33 mb

TC : O(N^2)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief :  Brute-force
*/

class Solution {
private:
    double calculate_angle(vector<vector<int>>& p1, vector<vector<int>>& p2){
        // Change in y and x
        double dy = p2[0][1]-p1[0][1];
        double dx = p2[0][0]-p1[0][0];
        double angle = 0;
        // If change in y is 0 means line is horizontal
        if(dy == 0){
            angle = 0;
        }
        // If change in x is 0 means line is vertical
        if(dx == 0){
            angle = 90;
        }
        // Else find angle
        else{
            angle = atan(dy / dx) * (180 / M_PI) ;
        }
        return angle;
    }
public:
    int maxPoints(vector<vector<int>>& pts) {
        // Fast i/o
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        // Edge case
        if(pts.size() == 1 || pts.size() == 2){
            return pts.size();
        }
        // For each point calculating its angle with the rest of points
        // The points with the same angle will be on same line
        int ans = INT_MIN;
        for(auto i: pts){
            vector<vector<int>> p1;
            p1.push_back(i);
            vector<double> angles;
            for(auto j: pts){
                // Need to exclude the same point
                if(j != i){
                    vector<vector<int>> p2;
                    p2.push_back(j);
                    angles.push_back(calculate_angle(p1, p2));
                }
            }
            // sorting angles to calculate which angle appears the most of time
            sort(angles.begin(), angles.end());
            int cnt = 0;
            int x = 0;
            int y = 1;
            // Logic to check which angle has appeared most times 
            while(y < angles.size()){
                int curr = 0;
                while(y < angles.size() && angles[x] == angles[y]){
                    curr += 1;
                    y++;
                }
                if(y < angles.size() && angles[x] != angles[y])
                {
                    x = y;
                    y++;
                }
                // Adding 2 to curr to include current point and first point which we had left i != j in upper for loop
                cnt = max(cnt, curr+2);
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};