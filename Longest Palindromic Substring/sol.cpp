class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        bool dp[n][n]; 
        int start=0, end=0;
        
        for(int i=0; i<n; i++){
            dp[i][i] = true;
            if(i < n-1){
                if(s[i]==s[i+1]){
                    dp[i][i+1] = true;
                    start = i;
                    end = i+1;
                }    
                else dp[i][i+1] = false;
            }
        }    
        
        for(int k=2; k<n; k++){
            for(int i=0; i<n-k; i++){
                if(s[i]==s[i+k] && dp[i+1][i+k-1]){
                    dp[i][i+k] = true;
                    if(end-start < k){
                        start = i;
                        end = i+k;
                    }
                }
                else dp[i][i+k] = false;
            }
        }
        return s.substr(start, end-start+1);
    }
};
