class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> rev(32);
        for(int i=0;i<32;i++){
            
            rev[i]=(n>>i)&1;
        }
        uint32_t num=0;
        for(int bit:rev){
            num=(num<<1)|bit;
        }
        return num;
    }
};
