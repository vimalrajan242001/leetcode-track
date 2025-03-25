class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        auto cp = image;
        int n = image.size();
        for(int i=0; i<n;i++){
            int m = n%2 == 0 ? n/2 : (n/2) + 1;
            for(int j= 0; j<m;j++){
                int temp = cp[i][j];
                cp[i][j] = cp[i][n-j-1] == 0 ? 1 : 0;
                cp[i][n-j-1] = temp == 0 ? 1 : 0; 
            }
        }

        return cp;
    }
};