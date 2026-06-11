class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> a;
        a[n]=1;
        while(a[n]<2){
            if(n==1)return true;
            n=foo(n);
            a[n]++;
            if(a[n]==2)return false;
        }
        return false;
    }
    int foo(int n){
        int ans=0, temp=0;
        while(n!=0){
            temp=n%10;
            n/=10;
            ans+=temp*temp;
        }
        return ans;
    }
};
