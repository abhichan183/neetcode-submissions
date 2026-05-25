class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> numbers;
        for(int i=0;i<nums.size();i++){
            if(numbers.count(nums[i])) return true;
            else numbers.insert(nums[i]);
        }
        return false;
    }
};