class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int rowarr[4] = {0,0,1,-1};
        int colarr[4] = {1,-1,0,0};

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        vector<vector<int>> answer = grid;

        queue<pair<pair<int,int>,int>> q;
        q.push({{row,col},grid[row][col]});
        vis[row][col]=1;

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int val = q.front().second;

            q.pop();
            if(i==0 || j==0 || i==n-1 || j==m-1){answer[i][j]=color;}
            // for(int it=0;it<4;it++){
            //     int nrow = i + rowarr[it];
            //     int ncol = j + colarr[it];
            //     answer[i][j]=color;
            // }
            for(int it=0;it<4;it++){
                int nrow = i + rowarr[it];
                int ncol = j + colarr[it];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==val && vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},val});
                    vis[nrow][ncol]=1;
                }
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]!=val && vis[nrow][ncol]==0){
                    answer[i][j]=color;
                }
            }
        }

        return answer;
    }
};