class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solve(coins,0,amount,dp);
    }
    int solve(vector<int>& coins,int i,int target,vector<vector<int>>& dp){
        if(target==0) return 1;
        if(target<0) return 0;
        if(i==coins.size()) return 0;
        if(dp[i][target]!=-1) return dp[i][target];
        dp[i][target]=solve(coins,i,target-coins[i],dp)+solve(coins,i+1,target,dp);
        return dp[i][target];
    }
};
