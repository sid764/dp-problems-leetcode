class Solution {
public:
    int change(int amount, vector<int>& coins) {
    
        int n = coins.size();
        sort(coins.begin(), coins.end());
        int dp[n+1][amount+1];
        
        dp[0][0]=1;
        
        for(int j=1; j<=amount; j++)
            dp[0][j] = 0;
        
        for(int i=1; i<=n; i++){
            dp[i][0]=1;
            for(int j=1; j<=amount; j++){
                
                if(coins[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        }
        return dp[n][amount];
    }
};
