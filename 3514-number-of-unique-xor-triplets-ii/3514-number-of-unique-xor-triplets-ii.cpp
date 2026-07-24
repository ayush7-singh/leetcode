class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int pick = 1; pick <= 3; pick++) {
            for (int xr = 0; xr < MAXX; xr++) {
                if (!dp[pick - 1][xr]) continue;

                for (int val : nums) {
                    dp[pick][xr ^ val] = true;
                }
            }
        }

        int ans = 0;
        for (bool ok : dp[3])
            ans += ok;

        return ans;
    }
};