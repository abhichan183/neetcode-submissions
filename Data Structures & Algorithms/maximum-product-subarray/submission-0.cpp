class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            int oldMax = maxProd;
            int oldMin = minProd;

            maxProd = max({curr, oldMax * curr, oldMin * curr});
            minProd = min({curr, oldMax * curr, oldMin * curr});

            ans = max(ans, maxProd);
        }

        return ans;
    }
};