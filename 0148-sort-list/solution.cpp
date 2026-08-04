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
struct comp {
    bool operator()(const pair<int, ListNode*>& a,
                    const pair<int, ListNode*>& b) const {
        return a.first < b.first;   // ascending order
    }
};
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
       vector<pair<int,ListNode*>>mp;
        ListNode *temp=head;
        while(temp!=nullptr){
            mp.push_back({temp->val,temp});
            temp=temp->next;
        }
        sort(mp.begin(),mp.end(),comp());
        head=mp[0].second,temp=head;
        for(int i=1;i<mp.size();i++){
            temp->next=mp[i].second;
            temp=temp->next;
        }
        temp->next=nullptr;
        return head;
    }
};
