class Solution {
public:

    void bfs(queue<int> q, unordered_set<int> &st,vector<int> adjL[]){
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adjL[node]){
                if(st.count(it)==0){q.push({it});}
                st.insert(it);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<(n-1)){return -1;}

        vector<int> adjL[n];
        
        for(int i=0;i<connections.size();i++){
            adjL[connections[i][1]].push_back(connections[i][0]);
            adjL[connections[i][0]].push_back(connections[i][1]);
        }

        unordered_set<int> vis;
        int answer=0;
        queue<int> q;

        for(int i=0;i<n;i++){
            if(vis.count(i)==0){
                q.push(i);
                bfs(q,vis,adjL);
                answer++;
            }
        }

        return answer-1;
    }
};