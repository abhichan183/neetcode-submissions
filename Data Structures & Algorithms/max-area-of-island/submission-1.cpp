class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxim=0;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vis[i][j]!=1&&grid[i][j]==1){
                    bfs(i,j,grid,vis,maxim);
                }
            }
        }
        return maxim;
    }
    void bfs(int i,int j, vector<vector<int>>& grid,vector<vector<int>>& vis, int& maxim){
        queue<pair<int,int>> q;
        vis[i][j]=1;
        q.push({i,j});
        int count=0;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            count++;
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr<0||nc<0||nr>=grid.size()||nc>=grid[0].size()) continue;
                if(vis[nr][nc]!=1&&grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        maxim=max(count,maxim);
    }
};
