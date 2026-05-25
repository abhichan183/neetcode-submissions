class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxprice=0;
       int minprice=prices[0];
       for(int curr:prices){
        maxprice=max(maxprice,curr-minprice);
        minprice=min(minprice,curr);
       } 
       return maxprice;
    }
};
