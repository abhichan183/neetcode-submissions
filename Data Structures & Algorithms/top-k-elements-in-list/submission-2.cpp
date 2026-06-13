class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> res;
        for(int x:nums){
            freq[x]++;
        }
        vector<pair<int,int>> v;
        for(auto &p:freq){
            v.push_back({p.second,p.first});
        }
        sort(v.begin(),v.end(),greater<>());
        for(int i=0;i<k;i++){
            res.push_back(v[i].second);
        }
        return res;
    }
};
