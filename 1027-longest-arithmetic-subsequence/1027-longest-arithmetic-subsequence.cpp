class Solution {
public: 
    
    int solveMem(vector<int>& nums,int index,int difference,unordered_map<int,int> dp[]){
        if(index<0){
            return 0;
        } 
        
        if(dp[index].count(difference)){
            return dp[index][difference];
        }
        
        int ans = 0; 
        
        for(int j=index-1;j>=0;j--){
            if(nums[index]-nums[j]==difference){
                ans = max(ans,1+solveMem(nums,j,difference,dp));
            }
        } 
        
        return dp[index][difference]=ans;
    } 
    
    
    int solveTab(vector<int>& nums,int n){
        unordered_map<int,int> dp[n+1]; 
        
        int ans = 0; 
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int count=1; 
                int diff = nums[i]-nums[j]; 
                
                if(dp[j].count(diff)){
                    count = dp[j][diff];
                } 
                
                dp[i][diff] = 1 + count; 
                
                ans = max(ans,dp[i][diff]);
            }
        } 
        return ans;
    }
    
    
    
    
    int longestArithSeqLength(vector<int>& nums) { 
        int n = nums.size(); 
        
        int ans = solveTab(nums,n); 
        
        return ans;

    }
};