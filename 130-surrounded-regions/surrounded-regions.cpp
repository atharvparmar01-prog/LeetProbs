class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        set<pair<int,int>> st={};
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
            }
            if(board[n-1][i]=='O'){
                q.push({n-1,i});
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
            }
        }

        int col[4] = {0,1,0,-1};
        int row[4] = {1,0,-1,0};

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            st.insert({i,j});
            cout<<i<<" "<<j<<endl;
            q.pop();
            if(board[i][j]=='O'){
                for(int it=0;it<4;it++){
                    int ncol = col[it]+i;
                    int nrow = row[it]+j;
                    if(ncol<n && nrow<m && ncol>=0 && nrow>=0 && board[ncol][nrow]=='O' && (st.count({ncol,nrow})==0)){q.push({ncol,nrow});}
                }
            }
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if((st.count({i,j}) == 0)){board[i][j] = 'X';}
            }
        }
    }
};