class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int res=0;
        unordered_set<int> setX = {};
        unordered_set<int> NewsetX = {};
        unordered_set<int> setY = {};
        unordered_set<int> NewsetY = {};
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && (setX.count(i)>0)){
                    NewsetX.insert(i);
                }
                if(grid[i][j] && (setY.count(j)>0)){
                    NewsetY.insert(j);
                }
                if(grid[i][j]){
                    setX.insert(i);
                    setY.insert(j);
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;

            q.pop();
            if(NewsetX.count(i)>0){res++;}
            else if(NewsetY.count(j)>0){res++;}
        }
        return res;
    }
};