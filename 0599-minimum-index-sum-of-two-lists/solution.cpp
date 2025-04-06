class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int mini=INT_MAX;
        for(int i=0; i<list1.size(); i++){
            for(int j=0; j<list2.size(); j++){
                if(list1[i]==list2[j])mini=min(mini,i+j);
            }
        }
        vector<string>arr;
        for(int i=0; i<list1.size(); i++){
            for(int j=0; j<list2.size(); j++){
                if(list1[i]==list2[j]&&i+j==mini){
                    mini=min(mini,i+j);
                    arr.push_back(list2[j]);
                }
            }
        }
        return arr;

    }
};
