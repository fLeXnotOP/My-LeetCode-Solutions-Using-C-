class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
         
        unordered_map<int,vector<int>> bStopToBid;
        
        for(int i=0;i<routes.size();i++){
            int bId = i; 
            vector<int> bStops = routes[i]; 
            
            for(auto bStop : bStops){
                bStopToBid[bStop].push_back(bId);
            }
        } 
        
        queue<pair<int,int>> q; //curStop -> busesTravelled; 
        
        unordered_map<int,bool> busVisited; 
        unordered_map<int,bool> busStopVisited; 
        
        q.push({source,0}); 
        busStopVisited[source]=true; 
        
        while(!q.empty()){
            int size = q.size(); 
            
            while(size--){
                pair<int,int> p = q.front(); 
                q.pop(); 
                
                int curStop = p.first; 
                int busesTravelled = p.second; 
                
                if(curStop==target){
                    return busesTravelled;
                } 
                
                for(auto bus : bStopToBid[curStop]){
                    if(busVisited[bus]){
                        continue;
                    }  
                    busVisited[bus]=true;
                    
                    for(auto busStop : routes[bus]){
                        if(busStopVisited[busStop]){
                            continue;
                        }  
                        
                        busStopVisited[busStop]=true; 
                        
                        q.push({busStop,busesTravelled+1});
                        
                        
                    }
                }
                
             
            }
        } 
        
        return -1;
        
    }
};