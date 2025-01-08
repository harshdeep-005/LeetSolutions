/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0, len2=0;
        ListNode* temp1=headA, *temp2=headB;
        while(temp1!=NULL){
            len1++;
            temp1=temp1->next;
        }
        cout<<"len1 : "<<len1<<endl;
        while(temp2!=NULL){
            len2++;
            temp2=temp2->next;
        }
        cout<<"len2 : "<<len2<<endl;
        temp1=headA, temp2=headB;
        if(len1>=len2){
            for(int i=0; i<len1-len2; i++){
                temp1=temp1->next;
            }
        }
        else{
            for(int i=0; i<len2-len1; i++){
                temp2=temp2->next;
            }
        }
        cout<<"val1 :"<<temp1->val<<endl<<"val2 :"<<temp2->val<<endl;
        while(temp1!=temp2 && temp1!=NULL){
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==NULL)return NULL;
        }
        return temp1;
    }
};
