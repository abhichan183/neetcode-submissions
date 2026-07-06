class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(numCourses,0);
        vector<int> path(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)) return false;
            }
        }
        return true;
    }
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& path){
        vis[node]=1;
        path[node]=1;
        for(int nei:adj[node]){
            if(!vis[nei]){
                if(dfs(nei,adj,vis,path)) return true;
            }
            else if(path[nei]) return true;
        }
        path[node]=0;
        return false;
    }
};