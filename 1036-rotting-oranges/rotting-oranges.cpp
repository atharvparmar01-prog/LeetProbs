class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time =0;
        int max_time=0;
        //r,c,time
        queue< pair<pair<int,int>, int> > q;
        int vis[n][m];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] ==2 ){
                    q.push({{i,j},time});
                    vis[i][j]=2;
                }
                else{vis[i][j]=0;}
            }
        }
        
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            max_time = max(time,max_time);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && (vis[nrow][ncol]==0) && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},time+1});
                    vis[nrow][ncol]=2; 
                }

            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j]==1){return -1;}
            }
        }
        return max_time;
    }

};