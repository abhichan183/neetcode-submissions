class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> tracker;
        for(string s: strs){
            string sorted=s;
            sort(sorted.begin(),sorted.end());
            tracker[sorted].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& pair:tracker){
            ans.push_back(pair.second);
        }
        return ans;
        
    }
};
