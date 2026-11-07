class Solution {
public:
int maximalSquare(vector<vector<char>>& matrix) {
    
    int n = matrix.size();
    int m = matrix[0].size();
    int res = 0;
    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int t=0,l=0,tl=0;
            dp[i][j] = matrix[i][j]-'0';
            if(res==0 && matrix[i][j]!='0'){res=1;}

            if(i>0 && j>0 && matrix[i][j]!='0'){
                t = dp[i-1][j];
                l = dp[i][j-1];
                tl = dp[i-1][j-1];
                int curr = min(t,min(l,tl));
                curr = (sqrt(curr) + 1)*(sqrt(curr) + 1);
                res = max(res,curr);
                dp[i][j] = curr;
            }
            else{
                continue;
            }
        }
    }
    return res;
}
};