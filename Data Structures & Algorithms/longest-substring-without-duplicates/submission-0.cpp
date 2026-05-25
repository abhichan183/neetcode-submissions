class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int maxlen=0;
        map<char,int> tracker;
        while(r<s.size()){
            tracker[s[r]]++;
            while(tracker[s[r]]>1){
                tracker[s[l]]--;
                l++;
            }
            int length=r-l+1;
            maxlen=max(maxlen,length);
            r++;
        }
        return maxlen;
    }
};
