class Solution {
public: 
    
    int solveMem(int index1,int index2,vector<int>& nums1,vector<int>& nums2,vector<vector<int>>& dp){
        if(index1>=nums1.size() || index2>=nums2.size()){
            return 0;
        } 
        
        if(nums1[index1]==nums2[index2]){
            return 1+solveMem(index1+1,index2+1,nums1,nums2,dp);
        } 
        
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        } 
        
        dp[index1][index2]=max(solveMem(index1+1,index2,nums1,nums2,dp),solveMem(index1,index2+1,nums1,nums2,dp)); 
        
        return dp[index1][index2];
    }
    
    
    
    
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) { 
        int n = nums1.size(); 
        int m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1)); 
        
        return solveMem(0,0,nums1,nums2,dp);
    }
};