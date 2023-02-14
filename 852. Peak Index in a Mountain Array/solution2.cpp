/*
783 ms
92.6 MB
TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Heap
*/


class Solution {
public:
    class DataNode{
        public:
            int data;
            int index;
            DataNode(int data, int index){
                this->data = data;
                this->index = index;
            }
    };
    class Compare {
    public:
       bool operator()(DataNode* a, DataNode* b){
           if(a->data < b->data){
               return true;
           }
           return false;
      }
    };
    int peakIndexInMountainArray(vector<int>& arr) {
        priority_queue<DataNode*, vector<DataNode*>, Compare >pq;
        for(int i = 0; i < arr.size(); i++){
            DataNode *temp = new DataNode(arr[i], i);
            pq.push(temp);
            cout<<pq.top()->data<<endl;
        }
        DataNode *temp = pq.top();
        return temp->index;
    }
};
