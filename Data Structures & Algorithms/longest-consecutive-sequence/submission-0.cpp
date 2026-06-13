class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        set<int> track;
        for(int x:nums){
            track.insert(x);
        }
        int count=1;
        int res=1;
        for(auto &p:track){
            if(track.contains(p+1)) count++;
            else count=1;
            res=max(res,count);
        }
        return res;
    }
};
