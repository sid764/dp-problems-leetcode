class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
     
        int l1 = s1.length(), l2 = s2.length();
        
        if(l1+l2 != s3.length())
            return false;
        
        bool M[l1+1][l2+1];
        memset(M, false, sizeof(M));
        M[0][0] = true;
        
        for(int i=1; i<=l1; i++)
            M[i][0] = M[i-1][0] && (s3[i-1]==s1[i-1]);
        
        for(int j=1; j<=l2; j++)
            M[0][j] = M[0][j-1] && (s3[j-1]==s2[j-1]);
        
        for(int i=1; i<=l1; i++){
            for(int j=1; j<=l2; j++){
                
                if(s3[i+j-1]==s1[i-1])
                    M[i][j] = M[i-1][j];
                
                if(s3[i+j-1]==s2[j-1])
                    M[i][j] = M[i][j] || M[i][j-1];
            }
        }
        
        return M[l1][l2];    
    }
};
