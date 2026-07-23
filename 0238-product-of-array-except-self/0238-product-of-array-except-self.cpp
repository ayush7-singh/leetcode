class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        //left product
        int prefix=1;
        for(int i=0;i<n;i++){
            ans[i]=prefix;
            prefix *= nums[i];
        }

        //right product
        int suffix=1;
        for(int i=n-1;i>=0;i--){
            ans[i] *=suffix;
            suffix*=nums[i];
        }
        return ans;
        // int left=1;
        // int right=1;
        // for(int i=0;i<n;i++){
        //     //left product
        //     for(int j=0;j<i;i++){
        //         int left = left*nums[j];
        //     }
        //     //right product
        //     for(int k=i+1;k<n;k++){
        //         right = right*nums[k];
        //     }
        //     ans[i]=left*right;
        // }
        // return ans;

    }
};