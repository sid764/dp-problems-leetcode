class Solution {
public:
    int climbStairs(int n) {
        
        if(n==1)
            return 1;
        
        int noOfWays[n+1];
        noOfWays[0]=0;
        noOfWays[1]=1;
        noOfWays[2]=2;
        
        for(int i=3; i<=n; i++)    
            noOfWays[i] = noOfWays[i-1] + noOfWays[i-2];
    
        return noOfWays[n];    
    }
};
