class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        generateSubsets(nums,0,current,ans);
        return ans;
    }

private:
    void generateSubsets(vector<int>& nums,int i,vector<int>& current,vector<vector<int>>& ans){
        if(i>=nums.size()){
            ans.push_back(current);
            return;
        }
        current.push_back(nums[i]);
        generateSubsets(nums,i+1,current,ans);
        current.pop_back();
        generateSubsets(nums,i+1,current,ans);
    }
};
