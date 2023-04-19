/*
Runtime : 348 ms
Memory : 106.3 MB
*/

/**
 * @author : Sahilk-027
 * @brief : DFS
*/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjCities(n);
        vector<bool> visited(n,false);
        for(int i=0;i<connections.size();i++)
        {
            int city1=connections[i][0];
            int city2=connections[i][1];
            adjCities[city1].push_back(city2);
            adjCities[city2].push_back(-city1);
        }
        int count=0;
        reorderPaths(0,adjCities,count,visited);
        return count;

    }
    void reorderPaths(int currCity,vector<vector<int>>& adjCities,int& count,vector<bool>& visited)
    {
        visited[currCity]=true;
        for(auto city:adjCities[currCity])
        {
            
            if(!visited[abs(city)])
            {
                if(city>0) //reorder the path 
                    count++;
                reorderPaths(abs(city),adjCities,count,visited);
            }
        }
    }
};