class Solution {
public:
int f(string a, string b){
    int n=a.size();
    int m=b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    for(int j=0;j<=m;j++) dp[0][j]=0;
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
     return dp[n][m];
}
int g(string a){
    string t=a;
    reverse(a.begin(),a.end());
    return f(a,t);
}
    int minInsertions(string s) {
        return s.size()-g(s);
    }
};