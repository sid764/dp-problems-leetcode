class Solution {
public:
    int countSubstrings(string s) {
    
        int n = s.length();
        bool dp[n][n]; 
        int ans=n;
        
        for(int i=0; i<n; i++){
            dp[i][i] = true;
            if(i < n-1){
                dp[i][i+1] = (s[i]==s[i+1]) ? true:false;
                ans += int(dp[i][i+1]);
            }    
        }    
        
        for(int k=2; k<n; k++){
            for(int i=0; i<n-k; i++){
                dp[i][i+k] = (s[i]==s[i+k] && dp[i+1][i+k-1]) ? true:false;
                ans += int(dp[i][i+k]);
            }
        }
        return ans;
    }
};
