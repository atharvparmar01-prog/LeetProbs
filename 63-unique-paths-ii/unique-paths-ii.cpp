class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(m==1 && n==1 && obstacleGrid[0][0]!=0){return 0;}
        if(m==1 && n==1 && obstacleGrid[0][0]==0){return 1;}
        vector<vector<int>> paths(n,vector<int>(m,0));
        if(obstacleGrid[0][0]==0){paths[0][0] = 1;}

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){continue;}
                if(obstacleGrid[i][j]){continue;}

                if(i>0 && j>0){
                    paths[i][j] = paths[i][j-1] + paths[i-1][j];
                }
                else if(i>0 && j==0){
                    paths[i][j] = paths[i-1][j];
                }
                else if(j>0 && i==0){
                    paths[i][j] = paths[i][j-1];
                }
            }
        }
        return paths[n-1][m-1];
    }
};