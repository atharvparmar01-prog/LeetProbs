class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>> &vis, int i, int j,int row[], int col[],int n,int m,int &maxi){
        vis[i][j]=1;

        for(int it=0;it<4;it++){
            int nrow = i+row[it];
            int ncol = j+col[it];
            if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && (vis[nrow][ncol]==0) && (grid[nrow][ncol]==1)){
                maxi++;
                dfs(grid,vis,nrow,ncol,row,col,n,m,maxi);
            }
        }

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int res=0;
        int row[] = {1,-1,0,0};
        int col[] = {0,0,1,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    int maxi=1;
                    dfs(grid,vis,i,j,row,col,n,m,maxi);
                    res = max(maxi,res);
                }
            }
        }
        return res;
    }
};