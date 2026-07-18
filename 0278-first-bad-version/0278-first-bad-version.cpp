class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isBadVersion(mid)) {
                ans = mid;
                high = mid - 1;   // Search left
            } else {
                low = mid + 1;    // Search right
            }
        }

        return ans;
    }
};