class Solution {
public:
    // The dp table should be a member of the class
    std::vector<std::vector<int>> dp;

    bool isMatch(std::string s, std::string p) {
        // Initialize the dp table
        dp.assign(s.size() + 1, std::vector<int>(p.size() + 1, -1));
        return check(0, 0, s, p);
    }

    bool check(int i, int j, std::string& s, std::string& p) {
        if (j == p.length()) {
            return (i == s.length());
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool ans = false;
        bool first_char_match = (i < s.length() && (p[j] == s[i] || p[j] == '?'));
        
        if (p[j] == '*') {
            bool match_empty = check(i, j + 1, s, p);
            // Corrected typo from 'ool' to 'bool'
            bool match_one_or_more = (i < s.length() && check(i + 1, j, s, p));
            
            ans = match_empty || match_one_or_more;
        } else {
            ans = first_char_match && check(i + 1, j + 1, s, p);
        }
        
        return dp[i][j] = ans;
    }
};