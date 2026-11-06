class Solution {
public:
    int numDecodings(string num) {

        unordered_set<string> st = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26"};
        if(num.size()==1 && num!="0"){return 1;}
        if(num.size()==1 && num=="0"){return 0;}
        vector<int> dp(num.size()+1,0);
        dp[num.size()] = 1;

        for(int i = num.size()-1;i>=0;i--){

            string s1 = "";
            s1 += num[i];
            string s2 = "";
            if(i!=(num.size()-1)){s2 = num.substr(i,2);}

            if(st.count(s1)){dp[i] += dp[i+1];}
            if(st.count(s2)){dp[i] += dp[i+2];}
        }

        return dp[0];
    }
};