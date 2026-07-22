class Solution {
public:
    int f(int ind, int target, vector<int>& nums) {
        if (ind == 0) {
            int ways = 0;
            if (target == nums[0]) ways++;
            if (target == -nums[0]) ways++;
            return ways;
        }

        int plus = f(ind - 1, target - nums[ind], nums);
        int minus = f(ind - 1, target + nums[ind], nums);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return f(nums.size() - 1, target, nums);
    }
};