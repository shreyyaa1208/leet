class Solution {
public:
    int jump(vector<int>& nums) {
    int jumps=0;
    int far=0;
    int curr=0;
    int n=nums.size()-1;
    for(int i=0;i<n;i++){
        far=max(far,i+nums[i]);
        if(i==curr){
            curr=far;
            jumps++;
        }
    }
    return jumps;
    }
};