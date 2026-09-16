class Solution {
public:
    bool isSqrt(int n){
        if(sqrt(n) == (int)sqrt(n)){return true;}
        return false;
    }
    int numSquares(int n) {

        if(isSqrt(n)){return 1;}
        queue<pair<int,int>> q;
        q.push({n,1});
        int cnt;

        while(!q.empty()){
            int num = q.front().first;
            cnt = q.front().second;
            int nSqrt = sqrt(num);
            q.pop();
            for(int i=1;i<=nSqrt;i++){
                if(isSqrt(num - (i*i))){return cnt+1;}
                q.push({num-(i*i) , cnt+1});
            }
        }
        return 0;
    }
};