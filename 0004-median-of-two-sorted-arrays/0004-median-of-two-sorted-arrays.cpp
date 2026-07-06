class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x=nums1.size()+nums2.size();
        vector<double> nums3(x);
        
        for(int i=0;i<nums1.size();i++){
            nums3[i]=nums1[i];
        }
        for(int j=0;j<nums2.size();j++){
            nums3[j+nums1.size()]=nums2[j];
        }
        sort(nums3.begin(),nums3.end());
        if(x%2==0){
            return (nums3[(x/2)-1]+nums3[(x/2)])/2;
        }
        else{
            return nums3[(x/2)];
        }
    }
};