class Solution {
public: 
    
    int solveMem(string& a,string& b,int i,int j,vector<vector<int>>& dp){
        if(i==a.length()){
            return b.length()-j;
        } 
        if(j==b.length()){
            return a.length()-i;
        } 
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        } 
        
        int ans = 0; 
        
        if(a[i]==b[j]){
            return solveMem(a,b,i+1,j+1,dp);
        } 
        
        else{
            
            int insertAns = 1 + solveMem(a,b,i,j+1,dp); 
            int replaceAns = 1 + solveMem(a,b,i+1,j+1,dp); 
            int deleteAns = 1 + solveMem(a,b,i+1,j,dp); 
            
            ans = min(insertAns,min(replaceAns,deleteAns));
        } 
        
        return dp[i][j] = ans;
    }
    
    
    
    
    
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,-1)); 
        
        return solveMem(word1,word2,0,0,dp);
    }
};