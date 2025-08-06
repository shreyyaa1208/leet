class Solution {
public:
int merge(vector<int>& nums, int low, int mid,int high){
    int count=0;
    int j=mid+1;
    for(int i=low;i<=mid;i++){
        while(j<=high && (long long)nums[i]>2LL*nums[j]){
            j++;
        }
        count+=(j-(mid+1));
    }
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left++]);
        }
       else{
        temp.push_back(nums[right++]);
       }
    }
    while(left<=mid){
        temp.push_back(nums[left++]);

    }
    while (right <= high) {
            temp.push_back(nums[right++]);
        }
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
        
        return count;
    }

    int mergeSort(vector<int>& nums, int low, int high){
        if(low>=high){
            return 0;
        }
        int mid=low+(high-low)/2;
        int pairs=0;
         pairs += mergeSort(nums, low, mid);
          pairs += mergeSort(nums, mid + 1, high);
        
        // Count "cross" pairs and merge the two halves
        pairs += merge(nums, low, mid, high);
        
        return pairs;
    }
    int reversePairs(vector<int>& nums) {
         if (nums.empty()) {
            return 0;
        }
        return mergeSort(nums, 0, nums.size() - 1);
    }
};