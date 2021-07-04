class Solution {
public:
        int minScoreTriangulation(vector<int>& values) {
    
        int n = values.size();
        int dp[n][n];
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(j-i < 2)
                    dp[i][j] = 0;
            }
        }
        
        for(int s=2; s<n; s++){
            for(int i=0; i<n-s; i++){
                
                if(s==2)
                    dp[i][i+2] = values[i]*values[i+1]*values[i+2];
                
                else{
                    dp[i][i+s] = INT_MAX;
                    for(int k=i+1; k<i+s; k++)
                        dp[i][i+s] = min(dp[i][i+s], values[i]*values[i+s]*values[k] + dp[i][k] + dp[k][i+s]);
                }    
            }
        }
        
        return dp[0][n-1];
    }
};
