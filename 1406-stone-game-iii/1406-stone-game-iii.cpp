class Solution {
public: 
    
    int solveMem(int i,vector<int>& stoneValue,vector<int>& dp){ 
        
        int n = stoneValue.size();
        if(i==n){
            return 0;
        } 
        
        if(dp[i]!=INT_MAX){
            return dp[i];
        } 
        
        int take_one = stoneValue[i] - solveMem(i+1,stoneValue,dp); 
        
        int take_two = INT_MIN; 
        
        if(i+1<n){
            take_two = stoneValue[i] + stoneValue[i+1] - solveMem(i+2,stoneValue,dp);
        } 
        
        int take_three = INT_MIN; 
        
        if(i+2<n){
            take_three = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solveMem(i+3,stoneValue,dp);
        } 
        
        return dp[i] = max(take_one,max(take_two,take_three));
    }
    
    
    
    
    string stoneGameIII(vector<int>& stoneValue) { 
        
        vector<int> dp(stoneValue.size()+1,INT_MAX);
        int value = solveMem(0,stoneValue,dp); 
        
        if(value<0){
            return "Bob";
        } 
        
        if(value>0){
            return "Alice";
        } 
        
        else{
            return "Tie";
        }
    }
};