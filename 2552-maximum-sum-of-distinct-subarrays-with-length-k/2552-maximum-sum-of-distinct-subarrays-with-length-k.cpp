class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        long long sum=0;
        unordered_map<int,int>mpp;
        int i=0;
        while(i<k && i<nums.size()){
            mpp[nums[i]]++;
            sum+=nums[i];
            i++;
        }
        if(mpp.size()==k) ans=sum;
        while(i<nums.size()){
            mpp[nums[i]]++;
            mpp[nums[i-k]]--;
            if(mpp[nums[i-k]]==0) mpp.erase(nums[i-k]);
            sum+=nums[i];
            sum-=nums[i-k];
            if(mpp.size()==k) ans=max(ans,sum);
            i++;
        }
        return ans;
    }
};