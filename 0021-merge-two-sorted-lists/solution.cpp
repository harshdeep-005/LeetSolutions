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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* head=new ListNode;
        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1->val<temp2->val){
                insert(head,temp1->val);
                temp1=temp1->next;
            }
            else{
                insert(head,temp2->val);
                temp2=temp2->next;
            }
        }
        while(temp1!=nullptr){  
            insert(head,temp1->val);
            temp1=temp1->next;
        }
        while(temp2!=nullptr){  
            insert(head,temp2->val);
            temp2=temp2->next;
        }
        return head->next;
        
    }

    void insert(ListNode* &head, int info){
        ListNode* temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next=new ListNode(info);
    }
};
