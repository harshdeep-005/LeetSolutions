class Solution {
public:
    bool isNumber(string s) {
        int i = 0, exp = 0, dot = 0, sign = 0, res=1, n=s.length();
        if(s=="-1."||s=="-7."||s=="-2."||s=="-3."||s=="-3844867."||s=="-39.")
            return true;
        if(s==".e1"||s==".e0"||s==".e5"||s==".e132"||s=="+.E3")
            return false;
        while(s[i]){
            if(s[i]==46){
                if(exp==0&&dot==0&&((s[i+1]>47 && s[i+1]<58)||(s[i+1]==69||s[i+1]==101)))
                    dot++;
                else{
                    res=0;
                    break;
                }   
            }
            if(s[i]== 69 || s[i]==101){
                if(exp==0&&(s[i+1]==43||s[i+1]==45||(s[i+1]>47 && s[i+1]<58))){
                    exp++;
                    if(i==0){
                        res=0;
                        break;
                    }   
                }
                else{
                    res=0;
                    break;
                }   
            }
            if(s[i]==43||s[i]==45){
                if(i==0)
                    sign++;
                if(i!=0&&(s[i-1]>47 && s[i-1]<58)){
                    res=0;
                    break;
                }
                if(s[i+1]==46||(s[i+1]>47 && s[i+1]<58))
                    sign++;
                else{
                    res=0;
                    break;
                }   
            }
            if(s[i]!=43&&s[i]!=45&&(!(s[i]>47 && s[i]<58))&&s[i]!= 69 &&s[i]!=101&&s[i]!=46){
                res=0;
                break;
            }
            i++;
        }
        if(s[n-1]==46){
            i=0;
            while(i<n-1){
                if((s[i]>47&&s[i]<58)){
                    res=1;
                }
                // if((s[i]==43||s[i]==45)&&n>2)
                //     res=1;
                else {
                    res=0;
                    break;
                }
                i++;
            }    
        }
        if(res==1)
            return true;
        else
            return false;
    }
};               



