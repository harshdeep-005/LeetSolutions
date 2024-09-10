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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int i=0;
        if(head==NULL){
            vector<ListNode*>ar1(k,head);
            return ar1;
        }
        vector<ListNode*>ar;
        ListNode* p1=head;
        ListNode* p2=head;
        ListNode* p3=head;
        while(p1!=NULL){
            p1=p1->next;
            i++;
        }
        int m, n;
        while(k!=0){
            m=i/k;
            if(i%k==0){
                i=i-m;
                n=m;
            }
            else{
                i=i-(m+1);
                n=m+1;
            }
            k--;
            cout<<n;
            ar.push_back(p2);
            for(int a=0; a<n; a++){
                p3=p2;
                p2=p2->next;
            }
            p3->next=NULL;
        }
        return ar;
    }
};
