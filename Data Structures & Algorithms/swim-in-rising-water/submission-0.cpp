class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[0][0]=grid[0][0];
        pq.push({dist[0][0],{0,0}});
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!pq.empty()){
            auto [curr,cell]=pq.top();
            pq.pop();
            int r=cell.first;
            int c=cell.second;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<0||nc<0||nr>=n||nc>=m) continue;
                int newTime=max(curr,grid[nr][nc]);
                if(newTime<dist[nr][nc]){
                    dist[nr][nc]=newTime;
                    pq.push({newTime,{nr,nc}});
                }
            }
        }
        return dist[n-1][n-1];
    }
};
