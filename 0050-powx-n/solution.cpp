class Solution {
public:
    double myPow(double x, int n) {
        double a=1;

        if(n==0 || x==1 ) return a;
        if( (n > INT_MAX / 10) || (n < INT_MIN / 10)){
            if(x==1||x==-1)
                if(n>0)
                    return x;
                else 
                    return 1;
            else
                return 0;    
        }
        if(n>0){
            for(int i=0; i<n; i++){
                a*=x;
            }
        }
        else{
            n=n*(-1);
            for(int i=0; i<n; i++){
                a*=(1/x);
            }
        }
        return a;
    }
};
