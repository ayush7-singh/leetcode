class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0;
        int high=height.size()-1;
        int lowh;
        int maxi=INT_MIN;
        while(low<=high){
            lowh=min(height[low],height[high]);
            maxi=max(maxi,lowh*(high-low));
            if(height[low]<height[high])low++;
            else high--;
        }
        return maxi;
    }
};