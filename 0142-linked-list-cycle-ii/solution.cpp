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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode *,int> a;
        ListNode *pt=head, *ans=NULL;
        while(pt && pt->next){
            a[pt]++;
            if(a[pt]>1){
                ans=pt;
                return ans;
            }
            pt=pt->next;
        }
        return NULL;
    }
};
