class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int right=0;
        int left=0;
        int count=0;
        int n=s.size();
        for(right=0;right<n;right++){
            mp[s[right]]++;
        
        //checking till all the three elements are found or not
        while(mp['a'] && mp['b'] && mp['c']){
            //n - right calculates the number of substrings that
            // can be formed from the current position (right) till the end of the string (n).
            count+=n-right;
            mp[s[left]]--;
            left++;

        }
        }
        return count;
    }
};