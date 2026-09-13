class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        vector<unordered_set<int>> prereq(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
            prereq[prerequisites[i][1]].insert(prerequisites[i][0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i : adj[node]) {
                for (int j : prereq[node]) {
                    prereq[i].insert(j);
                }
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        int n = queries.size();
        vector<bool> ans(n, false);
        for (int i = 0; i < n; i++) {
            if (prereq[queries[i][1]].find(queries[i][0]) != prereq[queries[i][1]].end()) {
                ans[i] = true;
            }
        }

        return ans;
    }
};