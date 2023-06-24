/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public: 
    

    
    
    ListNode* rotateRight(ListNode* head, int k) {  
        
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        ListNode* tail = head; 
        
        int len=1;  
        
        while(tail->next!=NULL){
            tail=tail->next; 
            len++;
        }  
        
        tail->next=head;
        
        int headIndex = len - k % len; 
        
        for(int i=0;i<headIndex;i++){
            tail=tail->next;
        }
        
        head = tail->next; 
        tail->next=NULL; 
        
        return head;
        
        
        

    }
};