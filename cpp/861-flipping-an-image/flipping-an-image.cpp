class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                // Swap and invert simultaneously
                int temp = image[i][j];
                image[i][j] = image[i][n - j - 1] == 0 ? 1 : 0;
                image[i][n - j - 1] = temp == 0 ? 1 : 0;
            }
        }
        return image;
    }
};



// class Solution {
// public:
//     vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
//         auto cp = image;
//         int n = image.size();
//         for(int i=0; i<n;i++){
//             int m = n%2 == 0 ? n/2 : (n/2) + 1;
//             for(int j= 0; j<m;j++){
//                 int temp = cp[i][j];
//                 cp[i][j] = cp[i][n-j-1] == 0 ? 1 : 0;
//                 cp[i][n-j-1] = temp == 0 ? 1 : 0; 
//             }
//         }

//         return cp;
//     }
// };