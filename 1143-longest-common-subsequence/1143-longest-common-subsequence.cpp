class Solution {
public: 
    
    
    int solveMem(string text1,string text2,int index1,int index2,vector<vector<int>>& dp){
        if(index1==text1.length()){
            return 0;
        } 
        
        if(index2==text2.length()){
            return 0;
        } 
        
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }  
        
        int ans = 0;
        
        if(text1[index1]==text2[index2]){
            ans = 1 + solveMem(text1,text2,index1+1,index2+1,dp);
        } 
        
        else{
            ans = max(solveMem(text1,text2,index1+1,index2,dp),solveMem(text1,text2,index1,index2+1,dp));
        } 
        
        return dp[index1][index2]=ans;
        
        
    } 
    
    int solveTab(string a,string b){
        
        int n = a.length(); 
        int m = b.length(); 
        vector<int> curr(m+1,0); 
        vector<int> next(m+1,0);
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                int ans = 0; 
                
                if(a[i]==b[j]){
                    ans = 1 + next[j+1];
                } 
                else{
                    ans = max(next[j],curr[j+1]);
                } 
                
                curr[j]=ans;
            } 
            next=curr;
        } 
        
        return next[0];
    }
    
    
    
    int longestCommonSubsequence(string text1, string text2) { 
        
        //int n = text1.length(); 
        //int m = text2.length();
        //vector<vector<int>> dp(n,vector<int>(m,-1)); 
        
        return solveTab(text1,text2);
    }
};