class Solution {
public:
    unordered_set<string> st;
    vector<int> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string str:wordDict){
            st.insert(str);
        }
        dp.resize(s.size(),-1);
        return solve(0,s);
    }
    bool solve(int idx, string& s){
        if(idx==s.size()) return true;
        if(dp[idx]!=-1) return dp[idx];
        string curr="";
        for(int i=idx;i<s.size();i++){
            curr+=s[i];
            if(st.contains(curr)&&solve(i+1,s)) return dp[idx]=true;
        }
        return dp[idx]=false;
    }
};