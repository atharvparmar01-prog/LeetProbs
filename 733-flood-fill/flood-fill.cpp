class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue <pair<int,int>> q;
        int m = image.size();
        int n = image[0].size();
        int num = image[sr][sc];
        if(num==color){return image;}
        q.push({sr,sc});

        int drow[] = {1,-1,0,0,};
        int dcol[] = {0,0,1,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            image[r][c]=color;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow<m && ncol<n && ncol>=0 && nrow>=0 && (image[nrow][ncol]==num)){
                    q.push({nrow,ncol});
                }
            }
        }
        return image;

    }
};