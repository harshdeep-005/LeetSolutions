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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        if(temp==NULL||temp->next==NULL)
            return head;
        int l=0;
        while(l<left-1){
            l++;
            temp = temp->next;
        }
        int n=right-left+1 ,arr[n];
        for(int i = 0; i < n; i++){
            arr[i] = temp->val;
            cout<<arr[i]<<" ";
            temp = temp->next;
        }
        temp=head;
        l=0;
        while(l<left-1){
            l++;
            temp = temp->next;
        }
        
        for(int i = n-1; i >=0 ; i--){						
            temp->val=arr[i];
            temp=temp->next;
        }

        return head;
    }
};

