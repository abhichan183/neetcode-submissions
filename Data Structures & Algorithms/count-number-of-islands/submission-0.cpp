class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
       vector<vector<int>> vis(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                if(!vis[i][j]){
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
       }
       return count; 
    }
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr<0||nr>=grid.size()||nc<0||nc>=grid[0].size()) continue;
                if(grid[nr][nc]=='1'&&!vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
};
