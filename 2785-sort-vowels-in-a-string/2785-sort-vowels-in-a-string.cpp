class Solution {
public: 
    
    bool isVowel(char c){
        
        return (c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    
    
    
    string sortVowels(string s) { 
        
        unordered_map<char,int> frequency; 
        
        
        for(auto c : s){
            
            if(isVowel(c)){
                frequency[c]++;
            }
        }  
        
        string vowels="AEIOUaeiou"; 
        string ans=s; 
        
        int j=0; 
        
        
        for(int i=0;i<s.size();i++){
            
            if(!isVowel(s[i])){
                continue;
            }  
            
            else{
                while(frequency[vowels[j]]==0){
                    j++;
                } 
                
                ans[i] = vowels[j]; 
                frequency[vowels[j]]--;
            }
            
            
        } 
        
        
        return ans;
        
        

    }
};