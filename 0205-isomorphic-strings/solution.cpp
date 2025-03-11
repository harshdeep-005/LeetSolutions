class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> store;
        int i=0;
        for(auto ch:s){
            if(store.find(ch) != store.end()){
                if(!(t[i]==store[ch])) return false;
            }
            store[ch]=t[i];
            i++;
        }
        i=0;
        unordered_map<char,char> store2;
        for(auto ch:t){
            if(store2.find(ch) != store2.end()){
                if(!(s[i]==store2[ch])) return false;
            }
            store2[ch]=s[i];
            i++;
        }
        return true;
    }
};
