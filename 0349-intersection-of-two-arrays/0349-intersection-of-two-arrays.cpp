class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size(), i=0, j=0;
        vector<int>ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j])i++;
            
            else if(nums2[j]<nums1[i])j++;
            else{
                if(ans.empty() || nums1[i]!=ans.back()) ans.push_back(nums1[i]);
                i++; 
                j++;
            }
            }
            return ans;
    }
};