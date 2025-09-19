class Solution {
public:
    int titleToNumber(string a) {
        int sum=0;
        for(auto c:a){
            sum=sum*26+(c-'A'+1);
        }
        return sum;
    }
};
