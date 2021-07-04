class Solution {
public:
    int countVowelStrings(int n) {
    
        if(n==1)
            return 5;
        
        int dp[5][n], ans=0;
        
        for(int j=0; j<n; j++)
            dp[0][j] = 1;
        
        for(int i=1; i<5; i++){
            dp[i][0] = 1;
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                if(j==n-1)
                    ans += dp[i][j];
            }
        }
        return ans+1;
    }
};
