class Solution {
public:
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.assign(n,vector<int>(2,-1));
        return solve(0,0,prices);
    }
    int solve(int idx,int hold, vector<int>& prices){
        if(idx==prices.size()) return 0;
        if(dp[idx][hold]!=-1) return dp[idx][hold];
        if(hold){
            return dp[idx][hold]=max(prices[idx]+solve(idx+1,0,prices),solve(idx+1,1,prices));
        }
        else{
            return dp[idx][hold]=max(-prices[idx]+solve(idx+1,1,prices),solve(idx+1,0,prices));
        }
        return dp[idx][hold];
    }
};