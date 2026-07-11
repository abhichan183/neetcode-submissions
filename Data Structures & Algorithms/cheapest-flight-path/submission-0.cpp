class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        dist[src][0]=0;
        pq.push({0,src,0});
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        while(!pq.empty()){
            auto arr=pq.top();
            pq.pop();
            int currPrice=arr[0];
            int currNode=arr[1];
            int steps=arr[2];
            if(currNode==dst) return currPrice;
            if(steps>=k+1) continue;
            for(auto x:adj[currNode]){
                int newPrice=currPrice+x.second;
                int newNode=x.first;
                if(newPrice<dist[newNode][steps+1]){
                    dist[newNode][steps+1]=newPrice;
                    pq.push({newPrice,newNode,steps+1});
                }
            }
        }
        return -1;
    }
};
