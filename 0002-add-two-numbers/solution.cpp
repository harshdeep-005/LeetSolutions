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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // int num1=0, num2=0, result=0, reversedNum1=0, reversedNum2=0;
        // while(l1->next!=NULL){
        //     num1=num1*10 + l1->val;
        //     l1=l1->next;
        // }
        // while(l2->next!=NULL){
        //     num2=num2*10 + l2->val;
        //     l2=l2->next;
        // }
        // if(l1->next==NULL){
        //     num1=num1*10 + l1->val;
        // }
        // if(l2->next==NULL){
        //     num2=num2*10 + l2->val;
        // }
        // ListNode* dummy=new ListNode();
        // ListNode* temp=dummy;

        // while (num1 > 0) {
        // int digit1 = num1 % 10;          
        // reversedNum1 = reversedNum1 * 10 + digit1;  
        // num1 = num1 / 10;                
        // }

        // while (num2 > 0) {
        // int digit2 = num2 % 10;          
        // reversedNum2 = reversedNum2 * 10 + digit2;  
        // num2 = num2 / 10;                
        // }

        // result=reversedNum1+reversedNum2;
        // if(result==0){
        //     ListNode* newnode=new ListNode();
        //     temp->next=newnode;
        //     temp=temp->next;
        // }
        // while(){
        //     ListNode* newnode=new ListNode(result%10);
        //     temp->next=newnode;
        //     temp=temp->next;
        //     result/=10;
        // }
        
        // return dummy->next;
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
};
