class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
    
        int m = matrix.size(), n = matrix[0].size();
        int dp[m][n], ans=0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(i==0 || j==0 || matrix[i][j]==0)
                    dp[i][j] = matrix[i][j];
                
                else
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});
                
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
