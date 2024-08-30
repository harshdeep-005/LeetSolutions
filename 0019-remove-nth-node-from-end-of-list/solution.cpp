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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            count++;
            temp = temp ->  next;
        }
        int pos=count-n;
        if(pos==0&&n==1){
            return 0;
        }
        if(pos==0&&n>1){
            ListNode* temp3 = head;
            head=temp3->next;
            return head;
        }
        { //deletion at any position
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        for(int i=0; i<pos; i++){
            temp2= temp2 -> next;
        }
        for(int i=0; i<pos-1; i++){
            temp1= temp1 -> next;
        }
        temp1 -> next = temp2 -> next; 
        }
        return head;
    }

};
