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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare> hp;
        for(ListNode* lis:lists){
            if(lis)hp.push(lis);
        }
        ListNode ans(0);
        ListNode* pt = &ans;
        while(!hp.empty()){
            ListNode* temp=hp.top();
            hp.pop();
            pt->next=temp;
            pt=pt->next;
            if(temp->next!=nullptr){
                temp=temp->next;
                hp.push(temp);
            }

        }
        return ans.next;
    }
};
