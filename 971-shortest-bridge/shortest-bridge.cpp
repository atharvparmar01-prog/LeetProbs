class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        bool flag = true;

        // Find first island
        for(int i = 0; i < n && flag; i++){
            for(int j = 0; j < m && flag; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    vis[i][j] = 1;
                    flag = false;
                }
            }
        }

        int row[] = {1, -1, 0, 0};
        int col[] = {0, 0, 1, -1};

        // Mark the entire first island
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int it = 0; it < 4; it++){
                int nrow = i + row[it];
                int ncol = j + col[it];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        // Put all cells of first island into queue
        // for the second BFS
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 1){
                    q.push({i, j});
                }
            }
        }

        int dist = 0;

        // Expand from first island through water
        while(!q.empty()){

            int size = q.size();

            while(size--){

                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(int it = 0; it < 4; it++){

                    int nrow = i + row[it];
                    int ncol = j + col[it];

                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    vis[nrow][ncol] == 0){

                        // Found second island
                        if(grid[nrow][ncol] == 1){
                            return dist;
                        }

                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }

            dist++;
        }

        return -1;
    }
};