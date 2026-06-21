class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int i=0;i<n+1;i++){
            res[i]=ones(i);
        }
        return res;
    }

    int ones(int x){
        int count=0;
        for(int i=0;i<32;i++){
            if(x&1) count++;
            x=x>>1;
        }
        return count;
    }
};
