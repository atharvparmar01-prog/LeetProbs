class Solution {
public:
    void dfs(int n,int num,unordered_set<int> &res,vector<int> &answer){
        if(res.count(num)>0){return;}
        res.insert(num);
        answer.push_back(num);

        if(((num+1)%10)!=0){
            if((num*10)<=n){
                dfs(n,num*10,res,answer);
            }
            if((num+1)<=n){
                dfs(n,num+1,res,answer);
            }
        }
        else{
            if((num*10)<=n){
                dfs(n,num*10,res,answer);
            }
            else{
                int cnt = 0;
                if(num>10000){cnt = 4;}
                else if(num>1000){cnt = 3;}
                else if(num>100){cnt = 2;}
                else if(num>10){cnt = 1;}
                dfs(n,(num+1)/(pow(10,cnt)),res,answer);
            }
        }
    }

    vector<int> lexicalOrder(int n) {
        unordered_set<int> res;
        vector<int> v;
        dfs(n,1,res,v);
        return v;
    }
};