class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5=0, c10=0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i]==5)c5++;
            else 
                if(bills[i]==10&&c5!=0){
                    c10++;
                    c5--;
                }
                else
                    if(bills[i]==20){
                        if(c10!=0){
                            if(c5!=0){
                                c5--;
                                c10--;
                            }  
                            else return false;  
                        }
                        else
                            if(c5>=3)c5=c5-3;
                            else return false;
                    }
                    else return false;
        }
        return true;
    }
};
