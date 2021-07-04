class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    
        int n = coins.size();
        sort(coins.begin(), coins.end());
        int dp[n+1][amount+1];
        
        dp[0][0]=0;
        for(int j=0; j<=amount; j++)
            dp[0][j] = 10001;
        
        for(int i=1; i<=n; i++){
            dp[i][0] = 0;
            for(int j=1; j<=amount; j++){
                
                if(coins[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);   
            }
        }
        
        if(dp[n][amount] > 10000)
            return -1;
        
        return dp[n][amount];
    }
};
