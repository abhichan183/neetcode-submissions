class Solution {
public:
    int findMin(vector<int> &nums) {
        int r=nums.size()-1;
        int l=0;
        if(nums[r]>nums[l]) return nums[0];
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]) l=mid+1;
            else if(nums[mid]<nums[r]) r=mid;
        }
        return nums[l];
    }
};
