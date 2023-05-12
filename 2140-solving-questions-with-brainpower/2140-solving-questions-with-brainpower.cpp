class Solution {
public:  
     long long helper(vector<vector<int>>& q, int i,int n,vector<long long>& dp){
       if(i >= n) return 0;
       if(dp[i] != -1) return dp[i];
       return dp[i] =  max(q[i][0] + helper(q, i + 1 + q[i][1], n,dp), helper(q, i + 1, n,dp));
    }   
    
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size(); 
        vector<long long> dp(n,-1); 
        return helper(q,0,n,dp);
    }
};