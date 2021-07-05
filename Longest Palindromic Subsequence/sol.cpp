class Solution {
public:
    int longestPalindromeSubseq(string s) {
    
        int n = s.length();
        int dp[n][n];
        
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
            if(i < n-1){
                dp[i][i+1] = (s[i]==s[i+1]) ? 2:1;
            }
        }
        
        for(int k=2; k<n; k++){
            for(int i=0; i<n-k; i++){
                
                if(s[i]==s[i+k])
                    dp[i][i+k] = 2 + dp[i+1][i+k-1];
                else
                    dp[i][i+k] = max(dp[i][i+k-1], dp[i+1][i+k]);
            }
        }
        return dp[0][n-1];
    }
};
