/*
Runtime : 4 ms
Memory : 8.1 MB

TC : O(n)
SC : O(1)
*/

/**
 * @author : Shashank BHosagi
 * @brief : Array
 */

class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        vector<int> temp(costs.size(), 0);
        int costA = 0;

        for (auto i : costs)
        {
            costA = costA + i[0];
        }

        for (int i = 0; i < costs.size(); i++)
        {
            temp[i] = costs[i][1] - costs[i][0];
        }

        sort(temp.begin(), temp.end());

        int costB = 0;

        for (int i = 0; i < (costs.size() / 2); i++)
        {
            costB += temp[i];
        }

        return costA + costB;
    }
};