class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
    int res=0;
    int sum=nums[0];
    int n=nums.size();
    for(int i=1;i<n;i++){
        if(nums[i]<=nums[i-1]){
            res=max(res,sum);
            sum=0;
        }
        sum+=nums[i];
    }    
    return max(res,sum);
    }
};