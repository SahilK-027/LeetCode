/*
20 ms
16.1 MB
*/

/**
 * @author : SahilK-027
 * @brief : Tree Implementation
*/


// Definition for a QuadTree node.
/*
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return recur(grid, 0, 0, n-1, n-1);
    }
    
    Node* recur(vector<vector<int>>& grid, int i1, int j1, int i2, int j2){
        int val = grid[i1][j1];
        bool flag = true;
        for(int i=i1; i<=i2; i++){
            for(int j=j1; j<=j2; j++){
                if(val != grid[i][j]){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) return new Node(val, true, nullptr, nullptr, nullptr, nullptr);
        Node *topLeft = recur(grid, i1, j1, (i1+i2)/2, (j1+j2)/2);
        Node *topRight = recur(grid, i1, (j1+j2)/2+1, (i1+i2)/2, j2);
        Node *bottomLeft = recur(grid, (i1+i2)/2+1, j1, i2, (j1+j2)/2);
        Node *bottomRight = recur(grid, (i1+i2)/2+1, (j1+j2)/2+1, i2, j2);
        return new Node(1, false, topLeft, topRight, bottomLeft, bottomRight);
    }

};