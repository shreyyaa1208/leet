class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mpp;
        for(auto x:s){
            mpp[x]++;
        }
        for(auto x:t){
            mpp[x]--;
        }
        for(auto x:mpp)
        if(x.second!=0){
            return false;
        }
        return true;
    }
};