class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int res=helper(n);
        while(res!=1){
            if(s.contains(res)) return false;
            s.insert(res);
            res=helper(res);
        }
        return true;
    }
    int helper(int nums){
        int temp=nums;
        int digits=0;
        int res=0;
        while(temp!=0){
            digits++;
            temp=temp/10;
        }
        for(int i=0;i<digits;i++){
            int ans=nums%10;
            nums=nums/10;
            res+=ans*ans;
        }
        return res;
    }
};
