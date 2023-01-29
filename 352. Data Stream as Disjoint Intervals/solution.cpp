/*
180 ms
50.6 MB
*/

/**
 * @author : SahilK-027
 * @brief :  Design
*/

class SummaryRanges {
public:
 // to remove duplicate entries
    set<int> s; 

    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        // vector of data_stream values till here
        vector<int> v = vector(s.begin(), s.end());   
        if (v.size()>0){  
            ans.push_back({v[0], v[0]});
            for (int i=1; i<v.size(); i++){
                // check for continuity in numbers
                if (v[i]==(v[i-1]+1)){   
                    // setting the end
                    ans[ans.size()-1][1] = v[i];   
                }else{
                    ans.push_back({v[i], v[i]});
                }
            }
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */