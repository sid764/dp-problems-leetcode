class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
    
        int m = s1.length(), n = s2.length();
        int dp[m+1][n+1];
        
        dp[0][0] = 0;
        for(int j=1; j<=n; j++)
            dp[0][j] = dp[0][j-1] + (int)s2[j-1];
        
        for(int i=1; i<=m; i++){
            dp[i][0] = dp[i-1][0] + (int)s1[i-1];
            
            for(int j=1; j<=n; j++){
                
                int del1 = dp[i-1][j] + (int)s1[i-1];
                int del2 = dp[i][j-1] + (int)s2[j-1];
                int rec = dp[i-1][j-1];
                
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = min({del1, del2, rec});
                else
                    dp[i][j] = min(del1, del2);
            }
        }
        return dp[m][n];
    }
};
