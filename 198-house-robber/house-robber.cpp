class Solution {
public:
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,0);
    if(n==1){return nums[0];}
    if(n==2){return max(nums[1],nums[0]);}

    dp[n-1] = nums[n-1];
    dp[n-2] = max(dp[n-1],nums[n-2]);
    for(int i = n-3;i>-1;i--){
        dp[i] = max(dp[i+1],nums[i]+dp[i+2]);
    }
    for(auto it:dp){
        cout<<it<<" ";
    }
    return max(dp[0],dp[1]);
}
};