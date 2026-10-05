class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int finalNum = graph.size()-1;
        vector<vector<int>> answer ={};

        queue<vector<int>> q;

        for(auto it:graph[0]){
            vector<int> vec_init= {0};
            if(it==finalNum){
                vec_init.push_back(it);
                answer.push_back(vec_init);
            }
            else{
                vec_init.push_back(it);
                q.push(vec_init);
            }
        }
        while(!q.empty()){
            vector<int> tvec = q.front();
            int ln = tvec[tvec.size()-1];
            vector<int> tv = tvec;
            q.pop();

            for(auto it:graph[ln]){
                vector<int> tvec = tv;
                if(it==finalNum){
                    tvec.push_back(it);
                    answer.push_back(tvec);
                }
                else{
                    tvec.push_back(it);
                    q.push(tvec);
                }
            }
        }
        return answer;
    }
};