class Solution {
public:
    int hammingWeight(uint32_t n) {
        int temp=32;
        int count=0;
        while(temp--){
            if(n&1) count++;
            n=n>>1;
        }
        return count;
    }
};
