// 方法1：暴力算法，复杂度O(mn)
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int j,k;
        for(int i=0;i<a.size();i++){
            j=0,k=i;
            while(j<b.size()&&b[j]==a[k%a.size()]){
                j++;k++;
            }
            if(j==b.size())break;
        }
        if(j==b.size())return k%a.size()==0?k/a.size():k/a.size()+1;
        else return -1;
    }
};

// 方法2：KMP串匹配
// 这个题目就是变形的串匹配
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        vector<int> next(b.size(),-1);
        int i=0,j=-1;
        while(i<b.size()-1){
            if(j<0 || b[i]==b[j]){
                next[i+1] = j+1;
                i++;j++;
            }else{
                j = next[j];
            }
        }
        i=0,j=0;
        while(i-j<a.size()){
            if(j<0 || a[i%a.size()]==b[j]){
                i++;j++;
                if(j==b.size()){
                    break;
                }
            }else{
                j=next[j];
            }
        }
        if(j==b.size())return i%a.size()==0?i/a.size():i/a.size()+1;
        else return -1;
    }
};