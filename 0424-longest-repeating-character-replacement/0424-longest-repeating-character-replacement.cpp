class Solution {
public:
    int characterReplacement(string s, int k) {
       vector<int>counts(26,0);
       int res=0;
       int r=0;
       int l=0;
        int count=0;
        int n=s.length();
        for( r=0;r<n;r++){
          counts [s[r]-'A']++;
          if(count<counts[s[r]-'A']){
            count=counts[s[r]-'A'];
          }
          while(r-l-count+1>k){
            counts[s[l]-'A']--;
            l++;
            for(int i=0;i<26;i++){
             if(count<counts[i]) {
                count=counts[i];
             }  
            }
          }
          res=max(res,r-l+1);
        }
        return res;
    }
};