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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* p1=head;
        if(p1->next==NULL)
            return p1;
        ListNode* p2=p1->next;
        while(p2!=NULL){
            int gcd = foo(p1->val, p2->val);
            ListNode* newNode = new ListNode(gcd);
            newNode->next = p2;
            p1->next = newNode;
            p1=p2;
            p2=p2->next;
        }
        return head;
    }

    int foo(int a, int b)
    {   
        int t,c;
        if(a<b)
        {
            t=a;a=b;b=t;
        }
        if (b == 0) {
            return a;
        } else {
            return foo(b, a % b);
        }
        
    }
};
