class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        int size=s1.size();
        int l=0;
        int r=size-1;
        while(l<s2.size()){
            string temp=s2.substr(l,size);
            sort(temp.begin(),temp.end());
            if(temp==s1) return true;
            l++;
        }
        return false;
    }
};
