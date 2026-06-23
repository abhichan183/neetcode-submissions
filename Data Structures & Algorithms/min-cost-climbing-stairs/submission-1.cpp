class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==0) return 0;
        if(n==1) return 0;
        if(n==2) return min(cost[0],cost[1]);
        int a=0;
        int b=0;
        for(int i=2;i<=cost.size();i++){
            int c=min(a+cost[i-2],b+cost[i-1]);
            a=b;
            b=c;
        }
        return b;
    }
};
