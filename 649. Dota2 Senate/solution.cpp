/*
12 ms
8 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : 2 Queue
*/

// 2 Queue solution
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        deque<int>RQueue;
        deque<int>DQueue;
        for(int i = 0 ; i < n; i++){
            if(senate[i] == 'R'){
                RQueue.push_back(i);
            }
            else{
                DQueue.push_back(i);
            }
        }
        while(!RQueue.empty() && !DQueue.empty()){
            if(RQueue.front() < DQueue.front()){
                int item = RQueue.front();
                int item_to_insert = item + n;
                RQueue.pop_front();
                RQueue.push_back(item_to_insert);
                DQueue.pop_front();
            }
            else{
                int item = DQueue.front();
                int item_to_insert = item + n;
                DQueue.pop_front();
                DQueue.push_back(item_to_insert);
                RQueue.pop_front();
            }
        }
        if(!RQueue.empty()){
            return "Radiant";
        }
        else{
            return "Dire";
        }
    }
};