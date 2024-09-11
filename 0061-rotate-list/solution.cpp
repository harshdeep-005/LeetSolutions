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
        ListNode* temp=head;
        if(temp==NULL) return head;
        int n=0;
        while(temp->next!=NULL){
            temp=temp->next;
            n++;
        }
        n++;
        temp->next=head;
        if(k>n)
            k%=n;

        if(n>k)
            n-=k;
        
        temp=head;
        for(int i=0; i<n-1; i++){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        
        
        return head;
    }
};
