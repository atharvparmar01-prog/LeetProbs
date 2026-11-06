class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2){return 0;}
        vector<int> dp(prices.size(),0);

        for(int i=prices.size()-2;i>-1;i--){
            if(prices[i+1]>prices[i]){
                dp[i] = prices[i+1] - prices[i] + dp[i+1];
            }
            else{
                dp[i] = dp[i+1];
            }
        }


        return dp[0];
    }
};