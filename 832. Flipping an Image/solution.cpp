class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int row,col;
        row = col = image.size() ;       
        for(int i = 0 ; i<row ;i++){
            reverse(image[i].begin(),image[i].end());
        }
        for(int i=0 ; i<row ;i++){
            for(int j = 0 ; j<col ; j++){
                //To toggle 0 with 1 and 1 with 0
                image[i][j] = image[i][j] ^ 1;
            }
        }
        return image;
    }
};