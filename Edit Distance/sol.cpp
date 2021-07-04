class Solution {
public:
    int minDistance(string word1, string word2) {
    
        int m = word1.length(), n = word2.length();
        int edit[m+1][n+1];
        
        for(int j=0; j<=n; j++)
            edit[0][j] = j;
        
        for(int i=1; i<=m; i++){
            
            edit[i][0] = i;
            
            for(int j=1; j<=n; j++){
                
                int ins = edit[i][j-1] + 1;
                int del = edit[i-1][j] + 1;
                int rep = edit[i-1][j-1];
                
                if(word1[i-1]==word2[j-1])
                    edit[i][j] = min({ins, del, rep});
                else
                    edit[i][j] = min({ins, del, rep+1});
            }
        }
        
        return edit[m][n];
        
    }
};
