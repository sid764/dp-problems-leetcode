class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    
        int m = matrix.size(), n = matrix[0].size();
        int maxSquare[m][n], maxSide = INT_MIN;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(i==0 || j==0)
                    maxSquare[i][j] = (matrix[i][j]=='1') ? 1 : 0;
                
                else if(matrix[i][j]=='0')
                    maxSquare[i][j] = 0;
                
                else
                    maxSquare[i][j] = 1+min({maxSquare[i-1][j], maxSquare[i][j-1], maxSquare[i-1][j-1]});
                
                maxSide = max(maxSide, maxSquare[i][j]);
            }
        }
        return maxSide*maxSide;
    }
};
