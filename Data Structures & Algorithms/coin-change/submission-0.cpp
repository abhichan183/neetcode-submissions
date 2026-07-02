class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        return solve(amount,coins,dp)==INT_MAX?-1:solve(amount,coins,dp);
    }
    int solve(int x,vector<int> &coins,vector<int> &dp){
        if (x == 0) return 0;
        if (dp[x] != -1) return dp[x];
        int best=INT_MAX;
        for(int c:coins){
            if(x-c>=0){
            int res=solve(x-c,coins,dp);
            if(res!=INT_MAX) best=min(best,res+1);
            }
        }
        dp[x]=best;
        return best;
    }
};
