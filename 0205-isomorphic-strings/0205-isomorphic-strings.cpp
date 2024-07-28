class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>map1(200,0);
        vector<int>map2(200,0);
        if(s.length()!=t.length())
            return false;
        
        for(int i=0;i<s.length();i++){
            if(map1[s[i]]!=map2[t[i]])
            return false;
            map1[s[i]]=i+1;
            map2[t[i]]=i+1;
        }
        return true;
    }
};