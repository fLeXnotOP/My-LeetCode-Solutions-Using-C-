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
    
    
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head; 
        ListNode* fast = head->next; 
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next; 
            fast=fast->next->next;
        } 
        
        return slow;
    }
    
    
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL; 
        ListNode* curr=head; 
        
        while(curr!=NULL){
            ListNode* next = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = next;
        } 
        
        return prev;
    }
    
    
    
    int pairSum(ListNode* head) { 
        ListNode* curr = head;
        ListNode* mid = middleNode(head); 
        ListNode* reversehead = reverseList(mid->next); 

        mid->next = NULL; 
        
        int ans = 0; 
        
        while(curr!=NULL && reversehead!=NULL){
            ans = max(ans,curr->val+reversehead->val); 
            curr=curr->next; 
            reversehead=reversehead->next;
        } 
        
        return ans;
    }
};