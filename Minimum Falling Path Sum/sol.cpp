class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
    
        int n = matrix.size();        
        int dp[n][n], ans=INT_MAX;
        
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                
                if(i==n-1)
                    dp[i][j] = matrix[i][j];
                
                else if(j==0)
                    dp[i][j] = matrix[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
                
                else if(j==n-1)
                    dp[i][j] = matrix[i][j] + min(dp[i+1][j-1], dp[i+1][j]);
                
                else dp[i][j] = matrix[i][j] + min({dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]});
                
                if(i==0)
                    ans = min(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
