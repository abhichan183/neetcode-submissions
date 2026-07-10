class Solution {
public:
    vector<int> parent,rank;
    void DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int u,int v){
        int a=find(u);
        int b=find(v);
        if(a==b) return;
        if(rank[a]<rank[b]){
            parent[a]=b;
        }
        else if(rank[a]>rank[b]){
            parent[b]=a;
        }
        else{
            parent[b]=a;
            rank[a]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({wt,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        DSU(n);
        int ans=0;
        int used=0;
        for(auto& e:edges){
            int wt=e[0];
            int u=e[1];
            int v=e[2];
            if(find(u)!=find(v)){
                Union(u,v);
                ans+=wt;
                used++;
                if(used==n-1) break;
            }
        }
        return ans;
    }
};
