// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int l=0,r=0,x=0,y=0,z=0,count=0;
//         while(l<s.size()){
//             if(s[r]=='a')x++;
//             if(s[r]=='b')y++;
//             if(s[r]=='c')z++;
//             if(x>0&&y>0&&z>0)count++;
//             if(r==s.size()-1){
//                 l++;
//                 r=l-1;
//                 x=0;
//                 y=0;
//                 z=0;
//             }
//             r++;
//         }
//         return count;
//     }
// };

class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0, x = 0, y = 0, z = 0, count = 0;
        while (l < s.size()) {
            while (r < s.size() && (x == 0 || y == 0 || z == 0)) {
                if (s[r] == 'a') x++;
                if (s[r] == 'b') y++;
                if (s[r] == 'c') z++;
                r++;
            }
            if (x > 0 && y > 0 && z > 0) {
                count += (s.size() - r + 1);
            }
            if (s[l] == 'a') x--;
            if (s[l] == 'b') y--;
            if (s[l] == 'c') z--;
            l++;
        }
        return count;
    }
};



