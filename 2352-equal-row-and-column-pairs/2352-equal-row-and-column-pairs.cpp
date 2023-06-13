class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int ans = 0;
        
        for(int c=0;c<n;c++){
            vector<int> column; 
            column.reserve(n); 
            
            for(int r=0;r<n;r++){
                column.push_back(grid[r][c]);
            }  
            
            ans +=count(grid.begin(),grid.end(),column);
            
            
        } 
        
        return ans;
    }
};