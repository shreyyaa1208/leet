class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int n=nums.size();
      if(n==0) return 0;
      sort(nums.begin(), nums.end());
      int smallest=INT_MIN;
      int longest=1;
      int cnt=0;
    for(int i=0;i<n;i++){
        if(nums[i]-1==smallest){
            cnt+=1;
            smallest=nums[i];
        }
        else if(nums[i]!=smallest){
            cnt=1;
            smallest=nums[i];
        }
        longest=max(longest,cnt);
    }
return longest;

    }
};