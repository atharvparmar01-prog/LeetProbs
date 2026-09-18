class Solution {
public:
    void bfs(vector<vector<char>>& grid,int i ,int j,vector<vector<int>> &visited, int col[], int row[],int n,int m){

        queue<pair<char,pair<int,int>>> q;
        q.push({grid[i][j],{i,j}});

        while(!q.empty()){
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();
            for(int it=0;it<4;it++){
                int nrow = i + row[it];
                int ncol = j + col[it];
                if(nrow<m && ncol<n && nrow>=0 && ncol>=0 && visited[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                    visited[nrow][ncol]=1;
                    q.push({grid[nrow][ncol],{nrow,ncol}});
                }
            }
        }

    }


    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt=0;
        int col[4] = {0,0,1,-1};
        int row[4] = {1,-1,0,0};

        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    visited[i][j]=1;
                    bfs(grid,i,j,visited,col,row,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};