class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> temp;
        for(char c:s){
            if(isalnum(c)){
                temp.push_back(tolower(c));
            }
        }
        int l=0;
        int r=temp.size()-1;
        while(l<r){
            if(temp[l]!=temp[r]) return false;
            l++;
            r--; 
        }
        return true;
    }
};
