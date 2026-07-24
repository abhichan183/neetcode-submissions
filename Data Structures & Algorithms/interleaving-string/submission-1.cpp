class Solution {
public:
    vector<vector<int>> dp;
    bool isInterleave(string s1, string s2, string s3) {
        int n=s3.size();
        if(s1.size()+s2.size()!=s3.size()) return false;
        dp.assign(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(0,0,s1,s2,s3);
    }
    int solve(int l, int r, string& s1, string& s2, string& s3){
        if(l>=s1.size()){
            bool res=true;
            int poi=r;
            while(r<s2.size()){
                if(s2[r]!=s3[l+r]) res=false;
                r++;
            }
            return dp[l][poi]=res;
        }
        if(r>=s2.size()){
            bool res=true;
            int poi=l;
            while(l<s1.size()){
                if(s1[l]!=s3[l+r]) res=false;
                l++;
            }
            return dp[poi][r]=res;
        }
        if(dp[l][r]!=-1) return dp[l][r];
        bool ans=false;
        if(s1[l]==s3[l+r]) ans|= solve(l+1,r,s1,s2,s3);
        if(s2[r]==s3[l+r]) ans|=solve(l,r+1,s1,s2,s3);
        return dp[l][r]=ans;
    }
};
