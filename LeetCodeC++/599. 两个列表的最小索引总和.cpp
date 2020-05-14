//核心：map的使用，key-value的理解运用
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> tmp;
        vector<string> ans;
        int min=2000;
        for(int i=0;i<list1.size();i++){
            tmp[list1[i]]=i;
        }
        for(int i=0;i<list2.size();i++){
            if(tmp.count(list2[i])){
                if(i+tmp[list2[i]]<min){
                    ans={list2[i]};
                    min=i+tmp[list2[i]];
                }
                else if(i+tmp[list2[i]]==min)
                    ans.push_back(list2[i]);
            }
        }
        return ans;
    }
};
