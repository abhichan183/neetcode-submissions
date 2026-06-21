class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]) l=mid+1;
            else if(nums[mid]<nums[r]) r=mid;
        }
        int minIndex=l;
        r=nums.size()-1;
        if(target>nums[r]){
            l=0;
            r=minIndex-1;
        }
        while(l<=r){
            int mid=l+(r-l)/2;
            if(target>nums[mid]) l=mid+1;
            else if(target<nums[mid]) r=mid-1;
            else return mid;
        }
        return -1;
    }
};
