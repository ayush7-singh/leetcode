class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum < abs(target)) return 0;
        if ((sum + target) % 2 != 0) return 0;

        int k = (sum + target) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        // Base case
        if (nums[0] == 0)
            dp[0][0] = 2;          // +0 and -0
        else
            dp[0][0] = 1;

        if (nums[0] != 0 && nums[0] <= k)
            dp[0][nums[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= k; t++) {
                int notTake = dp[i - 1][t];
                int take = 0;
                if (nums[i] <= t)
                    take = dp[i - 1][t - nums[i]];

                dp[i][t] = take + notTake;
            }
        }

        return dp[n - 1][k];
    }
};