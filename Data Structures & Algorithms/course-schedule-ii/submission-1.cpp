class Solution {
public:
    vector<vector<int>> adj;
        vector<int> state;
        vector<int> order;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        state.resize(numCourses, 0);
        for (auto &p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i))
                    return {};
            }
        }
        return order;
    }
      bool dfs(int node) {
        if (state[node] == 1)
            return false;              

        if (state[node] == 2)
            return true;               

        state[node] = 1;              

        for (int nei : adj[node]) {
            if (!dfs(nei))
                return false;
        }

        state[node] = 2;               
        order.push_back(node);

        return true;
    }
};
