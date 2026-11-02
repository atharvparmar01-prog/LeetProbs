class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> sums(n,vector<int>(m,0));
        sums[0][0] = grid[0][0];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){continue;}

                if(i>0 && j>0){
                    sums[i][j] = grid[i][j] + min(sums[i-1][j],sums[i][j-1]);
                }
                else if(i>0 && j==0){
                    sums[i][j] = grid[i][j] + sums[i-1][j];
                }
                else if(j>0 && i==0){
                    sums[i][j] = grid[i][j] + sums[i][j-1];
                }

            }
        }
        
        return sums[n-1][m-1];
    }
};