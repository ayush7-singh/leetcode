// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=0;
        int high=n-1;
        int mid=low+(high-low)/2;
        int ans;
        while(low<=high){
            mid=low+(high-low)/2;
            if(isBadVersion(mid)==true){
                ans=mid;
                high=mid-1;
            }
            else if (isBadVersion(mid-1)!=true ) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};