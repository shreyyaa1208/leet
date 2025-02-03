class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int ans=0;
        int inc=1;
        int dec=1;
if(n==1) return 1;
for(int i=1;i<n;i++){
    if(nums[i]>nums[i-1]) inc++, dec=1;
    else if (nums[i]<nums[i-1]) inc=1,dec++;
    else inc=dec=1;
    ans=max({ans,dec,inc});
}
return ans;
    }
};