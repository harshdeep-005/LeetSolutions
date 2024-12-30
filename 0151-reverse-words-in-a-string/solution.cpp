class Solution {
public:
    string reverseWords(string s) {
        stack<string> a;
        int i = 0;
        string b = "";
        char c;
        while(s[i]){
            string d = "";
            if(s[i]!=' '){
                do{
                    c = s[i];
                    if (((int)c >= 48 && (int)c <= 57) ||((int)c >= 65 && (int)c <= 90) ||((int)c >= 97 && (int)c <= 122)) {
                        d+=c;
                    }
                    i++; 
                }while (s[i]!=' '&&s[i]) ;
                cout<<d<<endl;
                a.push(d);
            }
            else i++;
        }
        b = a.top();
        a.pop();
        while (!a.empty()) {
            b =b+" "+ a.top();
            a.pop();
        }
        return b;
    }
};
