class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return solve(s,0,dp);
    }
    int solve(string& s, int idx,vector<int>& dp){
        if(idx==s.size()) return 1;
        if(idx>s.size()) return 0;
        if(s[idx]=='0') return 0;
        if(dp[idx]!=-1) return dp[idx];
        dp[idx]=solve(s,idx+1,dp);
        if(idx+1<s.size()){
            int a=(s[idx]-'0');
            int b=(s[idx+1]-'0');
            int temp=10*a+b;
            if(temp>=10&&temp<=26){
                dp[idx]+=solve(s,idx+2,dp);
            }
        }
        return dp[idx];
    }    
};
