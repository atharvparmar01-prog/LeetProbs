class Solution {
public:
    void dfs(vector<int>& nums,int i,unordered_set<int> &vis,bool &flag){

        for(int it=i;it<=(i+nums[i]);it++){

            if((i+nums[i]) >= (nums.size()-1)){flag = true;return;}

            if(vis.count(it)==0){vis.insert(it);dfs(nums,it,vis,flag);}

            if(flag){return;}

        }
    }

    bool canJump(vector<int>& nums) {
        if(nums.size()==1){return true;}
        int i=0;
        unordered_set<int> vis = {};
        bool flag = false;
        dfs(nums,i,vis,flag);
        return flag;
    }
};