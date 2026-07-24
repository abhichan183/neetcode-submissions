class Solution {
public:
vector<vector<int>> dp;
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.assign(n,vector<int>(2,-1));
        return solve(0,0,prices);
    }
    int solve(int idx,int holding, vector<int>& prices){
        if(idx>=prices.size()) return 0;
        if(dp[idx][holding]!=-1) return dp[idx][holding];
        if(holding){
            return dp[idx][holding]=max(prices[idx]+solve(idx+2,0,prices),solve(idx+1,1,prices));
        }
        else{
            return dp[idx][holding]=max(-prices[idx]+solve(idx+1,1,prices),solve(idx+1,0,prices));
        }
    }
};
