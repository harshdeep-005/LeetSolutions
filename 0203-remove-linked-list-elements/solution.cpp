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
    ListNode* removeElements(ListNode* head, int va) {
        while(head){
            if(head->val==va){
                head=head->next;
            }
            else break;
        }
        if(head==NULL)return nullptr;
        ListNode *temp=head, *temp2=head->next;
        while(temp2){
            if(temp2->val==va){
                temp->next=temp2->next;
            }
            else{
                temp=temp2;
            }
                temp2=temp->next;
        }
        return head;
    }
};
