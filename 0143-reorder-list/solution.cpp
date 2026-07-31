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
    void reorderList(ListNode* head) {
        if(head->next==nullptr|| head->next == nullptr)return;
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *temp=nullptr;
        while(fast!=nullptr&&fast->next!=nullptr){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=nullptr;
        ListNode *a=NULL, *b=slow, *c=NULL;
        while(b!=nullptr){
            c=b->next;
            b->next=a;
            a=b;
            b=c;
        }
        ListNode* ptr1=head, *ptr2=a,*temp1=nullptr,*temp2=nullptr;
        while(ptr1!=nullptr){
            temp1=ptr1->next;
            temp2=ptr2->next;
            ptr1->next=ptr2;
            if (temp1 == nullptr) break;
            ptr2->next=temp1;
            ptr1=temp1;
            ptr2=temp2;
        }
        ptr1->next=ptr2;
    }
};
