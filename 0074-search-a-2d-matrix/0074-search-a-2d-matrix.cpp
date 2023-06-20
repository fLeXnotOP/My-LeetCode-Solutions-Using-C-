class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(); 
        int column=matrix[0].size(); 

        int end=(row*column)-1;  
        int start=0; 

        int mid=start+(end-start)/2; 

        while(start<=end){
            int element=matrix[mid/column][mid%column]; 

            if(element==target){
                return true;
            } 
            if(element>target){
                end=mid-1;
            } 
            else{
                start=mid+1;
            } 
            mid=start+(end-start)/2;
        } 
        return false;
    }
};