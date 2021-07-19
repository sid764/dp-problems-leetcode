#include <bits/stdc++.h>
using namespace std;

/*Recursive implementation : O(2^n)
int minSubset(vector<int>& arr, int i, int curr_or, int max_or) {
    
    if(curr_or==max_or)
        return 0;
        
    if(i<0)
        return 10000;
        
    return min(minSubset(arr, i-1, curr_or, max_or), 1 + minSubset(arr, i-1, curr_or|arr[i], max_or));
}*/

int main() {
    
    vector<int> arr = {2, 6, 2, 8, 4, 5};
    
    int n = arr.size(), max_or = arr[0];
    
    for(int i=1; i<n; i++)
        max_or = max_or | arr[i];
    
    int dp[n+1][max_or+1];
    
    for(int i=0; i<=n; i++)
        dp[i][max_or] = 0;
    
    for(int j=0; j<max_or; j++)
        dp[0][j] = 10000;
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<max_or; j++){
            dp[i][j] = min(dp[i-1][j], 1+dp[i-1][j|arr[i-1]]); 
        }    
    }
    
    cout<<dp[n][0]<<endl;
    return 0;
}
