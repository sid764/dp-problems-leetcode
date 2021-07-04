class Solution {
public:
    bool isMatch(string s, string p) {
    
        int m = s.length(), n = p.length();
        bool dp[m+1][n+1];
        dp[0][0] = true;
        
        for(int i=1; i<=m; i++)
            dp[i][0] = false;
        
        for(int j=1; j<=n; j++)
            dp[0][j] = (p[j-1]=='*') ? dp[0][j-1] : false;
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                
                if(p[j-1]==s[i-1] || p[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                
                else if(p[j-1]=='*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                
                else dp[i][j] = false;
            }
        }
        
        return dp[m][n];
    }
};
