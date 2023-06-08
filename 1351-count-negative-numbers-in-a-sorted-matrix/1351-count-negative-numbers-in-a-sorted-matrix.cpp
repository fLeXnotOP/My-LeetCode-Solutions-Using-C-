class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0; 
        int row = grid.size()-1; 
        int column = 0; 
        int n = grid[0].size();
        
        while(row>=0 && column<n){
            
            if(grid[row][column]<0){
                row--; 
                count += n-column;
            } 
            else{
                column++;
            }
        } 
        return count;
    }
};