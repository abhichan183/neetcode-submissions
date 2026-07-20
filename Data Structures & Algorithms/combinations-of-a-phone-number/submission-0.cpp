class Solution {
public:
    vector<string> res;
    string curr;
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        solve(0,digits);
        return res;
    }
    void solve(int idx, string& digits){
        if(idx==digits.size()){
            res.push_back(curr);
            return;
        }
        int num=digits[idx]-'0';
        string temp=nums(num);
        for(int i=0;i<temp.size();i++){
            curr.push_back(temp[i]);
            solve(idx+1,digits);
            curr.pop_back();
        }
    }
    string nums(int digit){
        if(digit==2) return "abc";
        if(digit==3) return "def";
        if(digit==4) return "ghi";
        if(digit==5) return "jkl";
        if(digit==6) return "mno";
        if(digit==7) return "pqrs";
        if(digit==8) return "tuv";
        if(digit==9) return "wxyz";
        return "";
    }
};