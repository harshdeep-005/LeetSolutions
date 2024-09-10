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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode* p=head;
        vector<vector<int>> ar(m, vector<int>(n));
        int i=0, j=0, a=0, b=0;
        int x=1, y=m*n, u=m, v=n;
        int arr[m][n];
        while(x<=y){
            for(j=b; j<n; j++){
                if(p==NULL){
                    x++;
                    arr[i][j]=-1;
                    continue;
                }
                arr[i][j]=p->val;
                p=p->next;
                x++;
            }
            if(x>y)
                break;
            j--;
            for(i=i+1; i<m; i++){
                if(p==NULL){
                    x++;
                    arr[i][j]=-1;
                    continue;
                }
                arr[i][j]=p->val;
                p=p->next;
                x++;
            }
            if(x>y)
                break;
            i--;
            for(j=j-1; j>b; j--){
                if(p==NULL){
                    x++;
                    arr[i][j]=-1;
                    continue;
                }
                arr[i][j]=p->val;
                p=p->next;
                x++;
            }
            if(x>y)
                break;
            for(i=i; i>a; i--){
                if(p==NULL){
                    x++;
                    arr[i][j]=-1;
                    continue;
                }
                arr[i][j]=p->val;
                p=p->next;
                x++;
            }
            if(x>y)
                break;
            b++;
            i++;
            j++;
            a++;
            m--;
            n--;
        }
        for(int i=0; i<u; i++){
            for(int j=0; j<v; j++){
                ar[i][j]=arr[i][j];
            }
        }
        return ar;
    }
};
