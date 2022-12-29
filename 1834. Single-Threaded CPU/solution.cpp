/*
465 ms
142 MB

TC : O(Log N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Heap
*/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        using double_pair = pair<long int,pair<long int,long int >> ;
        using single_pair = pair<long int,long int>;
        priority_queue<single_pair,vector<single_pair>,greater<single_pair>> pq;
        int len=tasks.size(); 
        vector<double_pair> rearrange;
        for(long int  i=0;i<len;i++)
        {
            rearrange.push_back({tasks[i][0],{tasks[i][1],i}});
        }
        sort(rearrange.begin(),rearrange.end());
        long int i=0;
        long  int finishTime=rearrange[0].first;
        long int k=tasks.size();

        vector<int> res;
        while(k)
        {
            while(i<len && finishTime>=rearrange[i].first)
            {
                //push the processing time and the index
                pq.push({rearrange[i].second.first,rearrange[i].second.second});
                i++;
            }
            auto [time,ind]=pq.top();
            pq.pop();
            
            //processing the tasks take time
            finishTime+=time; 
            res.push_back(ind);
            
            if(pq.empty() && (i<len && finishTime < rearrange[i].first ))
                finishTime=rearrange[i].first;
            
            k--;
        }
        return res;
    }
};