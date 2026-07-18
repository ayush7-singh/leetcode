class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int mid = -1;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (nums[mid] == target)
                break;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        if (low > high)
            return {-1, -1};

        int first = mid;
        int last = mid;

        while (first > 0 && nums[first - 1] == target)
            first--;

        while (last < nums.size() - 1 && nums[last + 1] == target)
            last++;

        return {first, last};
    }
};