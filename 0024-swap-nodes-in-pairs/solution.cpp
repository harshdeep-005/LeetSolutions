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
    ListNode* swapPairs(ListNode* head) {
        ListNode* ptr1=head;
        if(ptr1==NULL || ptr1->next==NULL){
            return head;
        }
        ListNode* ptr2=head->next;
        ListNode* temp;
        ListNode* newnode=ptr1->next;
        while(ptr1->next!=NULL){
            ptr1->next=ptr2->next;
            ptr2->next=ptr1;
            if(ptr1->next==NULL ){
                return newnode;
            }
            if(ptr1->next->next==NULL ){
                return newnode;
            }
            temp=ptr1;
            ptr1=ptr1->next;
            ptr2=ptr1->next;
            temp->next=ptr2;
            // if(ptr2->next==NULL)
            //     return newnode;
            // if(ptr1->next->next!=NULL){
            //     ptr1->next=ptr1->next->next;
            //     ptr1=ptr1->next;
            // }
        }
        // while(ptr1->next==NULL && ptr2->next==NULL){
        //     ptr1->next=ptr2->next;
        //     ptr2->next=ptr1;
        //     if(ptr1->next==NULL)
        //         return newnode;
        //     ptr2=ptr1->next;
        //     if(ptr2->next==NULL)
        //         return newnode;
        //     if(ptr1->next->next!=NULL){
        //         ptr1->next=ptr1->next->next;
        //         ptr1=ptr1->next;
        //     }
        // }
        return head;
    }
};
