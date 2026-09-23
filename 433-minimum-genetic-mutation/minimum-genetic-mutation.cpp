class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = startGene.size();

        unordered_set<string> st(bank.begin(),bank.end());
        unordered_set<char> st_char = {'A','C','G','T'};

        queue<pair<string,int>> q;

        q.push({startGene,0});

        while(!q.empty()){
            string s = q.front().first;
            if(s==endGene){return q.front().second;}
            int distance = q.front().second;
            q.pop();
            
            for(int i=0;i<n;i++){
                string str = s;
                for(auto it:st_char){
                    str[i]= it;
                    if(st.count(str) > 0){
                        q.push({str,distance+1});
                        st.erase(str);
                    }
                }
            }
        }
        return -1;
    }
};