class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) q.push({i,j});
            }
        }
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        int count=0;
        while(!q.empty()){
            int size=q.size();
            count++;
            for(int i=0;i<size;i++){
                auto [r,c]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    if(nc<0||nc>=m||nr<0||nr>=n) continue;
                    if(grid[nr][nc]==INT_MAX&&vis[nr][nc]!=1){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                        grid[nr][nc]=count;
                    }
                }
            }
        }        
    }
};
