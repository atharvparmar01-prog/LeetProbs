class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){return -1;}
        queue<pair<pair<int,int>,int>> q;

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        int row[8] = {0,0,1,-1,1,-1,1,-1};
        int col[8] = {1,-1,0,0,1,-1,-1,1};

        q.push({{0,0},1});

        while(!q.empty()){
            int dist = q.front().second;
            int i = q.front().first.first;
            int j = q.front().first.second;

            q.pop();

            if((i==n-1)&&(j==m-1)){return dist;}

            for(int it=0;it<8;it++){
                int nrow = i + row[it];
                int ncol = j + col[it];
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && (vis[nrow][ncol]==0) && (grid[nrow][ncol]==0)){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},dist+1});
                }
            }
        }
        return -1;
    }
};