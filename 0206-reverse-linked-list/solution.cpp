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
    ListNode* reverseList(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        if(temp==NULL||temp->next==NULL)
            return head;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        int arr[n];
        temp = head;
        for(int i = 0; i < n; i++){
            arr[i] = temp->val;
            temp = temp->next;
        }

        temp=head;
        for(int i = n-1; i >=0 ; i--){						
            temp->val=arr[i];
            temp=temp->next;
        }

        return head;
    }
};
