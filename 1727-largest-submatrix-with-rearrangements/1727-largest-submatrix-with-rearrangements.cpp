class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size(); 
        int n = matrix[0].size();  
        vector<int> prevRow = vector(n,0);
        int ans=0;
        
        for(int i=0;i<m;i++){ 
            vector<int> currRow = matrix[i];
            for(int j=0;j<n;j++){
                if(currRow[j]!=0){
                    currRow[j] += prevRow[j];
                }
            } 
            
            vector<int> sortedRow = currRow; 
            
            sort(sortedRow.begin(),sortedRow.end(),greater()); 
            
            for(int k=0;k<n;k++){
                ans= max(ans,sortedRow[k]*(k+1));
            } 
            prevRow = currRow;
        } 
        
        
        
        return ans;
       
    }
};