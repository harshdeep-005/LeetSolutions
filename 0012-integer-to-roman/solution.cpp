class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        while(num!=0){
                if(num>=1000){
                    ans+="M";
                    num=num-1000;
                    continue;
                }
                if(num>=900){
                    ans+="CM";
                    num=num-900;
                    continue;
                }
                else if(num>=500){
                    ans+="D";
                    num=num-500;
                    continue;
                }
                else if(num>=400){
                    ans+="CD";
                    num=num-400;
                    continue;
                }
                else if(num>=100){
                    ans+="C";
                    num=num-100;
                    continue;
                }
                else if(num>=90){
                    ans+="XC";
                    num=num-90;
                    continue;
                }
                else if(num>=50){
                    ans+="L";
                    num=num-50;
                    continue;
                }
                else if(num>=40){
                    ans+="XL";
                    num=num-40;
                    continue;
                }
                else if(num>=10){
                    ans+="X";
                    num=num-10;
                    continue;
                }
                else if(num>=9){
                    ans+="IX";
                    num=num-9;
                    continue;
                }
                else if(num>=5){
                    ans+="V";
                    num=num-5;
                    continue;
                }
                else if(num>=4){
                    ans+="IV";
                    num=num-4;
                    continue;
                }
                else if(num>=1){
                    ans+="I";
                    num=num-1;
                    continue;
                }
        }
      return ans;
    }
};
