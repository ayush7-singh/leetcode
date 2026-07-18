class Solution {
public:
    bool f(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (ind == 0) return nums[0] == target;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool notTake = f(ind - 1, target, nums, dp);

        bool take = false;
        if (nums[ind] <= target)
            take = f(ind - 1, target - nums[ind], nums, dp);

        return dp[ind][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for (int x : nums)
            sum += x;

        if (sum % 2)
            return false;

        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));

        return f(n - 1, sum / 2, nums, dp);
    }
};