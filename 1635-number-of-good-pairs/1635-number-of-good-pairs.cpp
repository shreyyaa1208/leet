class Solution {
public:
int solve(vector<int>& nums, int index){
    int n=nums.size();
   
    if(index>=n){
        return 0;
    }
     int currentPair=0;
    for(int i=index+1;i<n;i++){
        if(nums[i]==nums[index]){
            currentPair++;
        }
    }
    int restPair=solve(nums,index+1);
    return currentPair+restPair;
}
    int numIdenticalPairs(vector<int>& nums) {
        return solve(nums,0);
    }
};