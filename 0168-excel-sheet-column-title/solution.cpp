class Solution {
public:
    string convertToTitle(int a) {
        string s = "";
        while(a>0){
            a--;
            int b = a%26;
            cout <<char('A'+ b) << endl;
            s = char('A'+ b) + s;
            a = a/26;
        
        }
        return s;
    }
};
