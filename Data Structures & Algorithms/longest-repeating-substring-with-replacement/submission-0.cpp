class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> tracker;
        int l=0;
        int maxfreq=0;
        int ans=0;
        int r=0;
        while(r<s.size()){
            tracker[s[r]]++;
            maxfreq=max(maxfreq,tracker[s[r]]);
            while(r-l+1-maxfreq>k){
                tracker[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }        
        return ans;
    }
};
