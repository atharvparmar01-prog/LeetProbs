class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph1) {
        int n = graph1.size();
        vector<int> indegree(n, 0);
        vector<int> res = {};
        vector<int> graph[n];
        queue<int> q;

        for(int i=0;i<n;i++){
            for(int it=0;it<graph1[i].size();it++){
                int index = graph1[i][it];
                graph[index].push_back(i);
                indegree[i]++;
            }
        }

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto it:graph[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }

};