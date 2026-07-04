class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(word1,word2,0,0,dp);
    }
    int helper(string& s, string& t, int i, int j, vector<vector<int>>& dp){
        if(i==s.size()) return t.size()-j;
        if(j==t.size()) return s.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            dp[i][j]=helper(s,t,i+1,j+1,dp);
        }
        else{
            dp[i][j]=1+min({helper(s,t,i,j+1,dp),helper(s,t,i+1,j,dp),helper(s,t,i+1,j+1,dp)});
        }
        return dp[i][j];
    }
};