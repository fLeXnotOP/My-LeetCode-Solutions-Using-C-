class Solution {
public:
    
    bool is_possible(long  long int need,long long int mid)
    {
        long long int val=2*(mid)*(mid+1)*(2*mid+1);
        if(val<need)
        {
            return 1;
        }
        return 0;
    }
    
    
    long long minimumPerimeter(long long need) {
        
       long long  int start=0; // start point
        long long  int end=100000;// end point
        
        while(start<end)
        {
           long long  int mid=start-(start-end)/2;// middle point 
            if(is_possible(need,mid))//check  if we are able to count apple or not.
            {
                start=mid+1;
                
            }
            else
            {
                end=mid;
                
            }
        }
        
        return 8*start;
        
        
        
    }
};



