class Solution {
public:
    bool compare(string& s1, string& s2) {
        if (s1.size() != s2.size() + 1) return false;
        
        int first = 0;
        int second = 0;
        
        while (first < s1.size()) {
            if (second < s2.size() && s1[first] == s2[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }
        return (first == s1.size() && second == s2.size());
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        
        // Sort the array
        sort(words.begin(), words.end(), [](string& s1, string& s2) {
            return s1.size() < s2.size();
        });

        vector<int> dp(n, 1);
        int maxi = 1;
        
        for (int i = 0; i < n; i++) {
            for (int prev_index = 0; prev_index < i; prev_index++) {
                if (compare(words[i], words[prev_index]) && 1 + dp[prev_index] > dp[i]) {
                    dp[i] = 1 + dp[prev_index];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
