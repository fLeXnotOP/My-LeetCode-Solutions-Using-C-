class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0; 
        int end = nums.size()-1; 
        
        int mid = start + (end-start)/2; 
        int min = INT_MIN;
        while(start<end){ 
            
            if(nums[start]<nums[end]){
                return nums[start];
            } 
            else if(nums[mid]>nums[end]){
                start=mid+1;
            } 
            else{
                end=mid;
            } 
            mid = start + (end-start)/2;
        } 
        
        return nums[start];
    }
};