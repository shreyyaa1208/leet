class Solution {
public:
    int f(int ind, vector<int>& nums, vector<int>& dp){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];

        //pick
        int pick=nums[ind]+f(ind-2,nums,dp);
        int noPick=0+f(ind-1,nums,dp);
        return dp[ind]=max(pick,noPick);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
         if (n == 1) return nums[0];
        vector<int>dp1(n-1,-1);
        vector<int> nums1(nums.begin() + 1, nums.end());
        int excludeFirst=f(n-2,nums1,dp1);


vector<int>dp2(n-1,-1);
vector<int>nums2(nums.begin(), nums.end()-1);
int excludeLast=f(n-2,nums2,dp2);
return max(excludeFirst, excludeLast);
    }
};