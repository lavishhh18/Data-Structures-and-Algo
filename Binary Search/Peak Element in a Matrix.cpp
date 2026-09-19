class Solution {
public:
    int findMaxInCol(vector<vector<int>>& mat, int col){
        int idx = -1;
        int maxi = -1;

        for(int i = 0; i<mat.size(); i++){
            int curr = mat[i][col];
            if(curr > maxi){
                maxi = curr;
                idx = i;
            }
        }

        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n - 1;

        while(low <= high){
            int col = low + (high - low)/2;

            int row = findMaxInCol(mat, col);

            int left = -1;
            int right = -1;
            if(col - 1 >= 0) left = mat[row][col - 1];
            if(col + 1 < n) right = mat[row][col + 1];

            int curr = mat[row][col];

            if(curr > left && curr > right){
                return {row, col};
            }
            else if(curr < left){
                high = col - 1;
            }
            else {
                low = col + 1;
            }
        }
        return {-1, -1};
    }
};