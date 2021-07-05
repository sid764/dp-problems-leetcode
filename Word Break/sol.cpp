class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    
        int n = s.length();
        bool splittable[n+1];
        splittable[n] = true;
        
        for(int i=n-1; i>=0; i--){
            splittable[i] = false;
            
            for(int j=i; j<=n-1; j++){
                
                if(find(wordDict.begin(), wordDict.end(), s.substr(i,j-i+1)) != wordDict.end() && splittable[j+1])
                    splittable[i] = true;
            }
        }
        
        return splittable[0];
    }
};
