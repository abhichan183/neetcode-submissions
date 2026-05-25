class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0;
        unordered_map<int,int> index;
        for(int i=0;i<nums.size();i++){
            index[nums[i]]=i;
        }
        int r=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            int req=target-nums[i];
            if(index.find(req)!=index.end()&&index[req]!=i){
                return {i,index[req]};
            }
        }
        return {};
    }
};
