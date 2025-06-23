class Solution {
public:
    int findMin(vector<int>& nums) {
        int maxi=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<maxi){
                maxi=nums[i];
            }
        }
        return maxi;
    }
};