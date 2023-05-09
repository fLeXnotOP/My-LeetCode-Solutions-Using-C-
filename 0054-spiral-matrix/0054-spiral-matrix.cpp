class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size(); 
        int column=matrix[0].size();  
        vector<int> ans;

        int startingRowIndex=0; 
        int endingRowIndex=row-1; 
        int endingColIndex=column-1; 
        int startingColIndex=0; 
        int count=0;  
        int totalElements=row*column;

        while(count<totalElements){

            for(int index=startingColIndex; index<=endingColIndex && count<totalElements ;index++){ 
                ans.push_back(matrix[startingRowIndex][index]); 
                count++;

            } 
            startingRowIndex++; 

            for(int index=startingRowIndex; index<=endingRowIndex && count<totalElements;index++){
                ans.push_back(matrix[index][endingColIndex]); 
                count++;
            } 
            endingColIndex--; 

            for(int index=endingColIndex;index>=startingColIndex && count<totalElements;index--){
                ans.push_back(matrix[endingRowIndex][index]); 
                count++;
            } 
            endingRowIndex--; 

            for(int index=endingRowIndex ; index>=startingRowIndex && count<totalElements;index--){
                ans.push_back(matrix[index][startingColIndex]); 
                count++;
            } 
            startingColIndex++;
        } 
        return ans;
    }
};