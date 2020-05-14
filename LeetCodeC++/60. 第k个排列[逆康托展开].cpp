/**
 * @Date:   2018-07-28
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-07-28
 */
//康托展开参考：https://blog.csdn.net/wbin233/article/details/72998375
class Solution {
public:
    int a[10]={1,1,2,6,24,120,720,5040,40320,362880};
    string getPermutation(int n, int k) {
        k--;
        string nums;
        vector<int> t;
        for(int i=1;i<=n;i++){t.push_back(i);}
        int m;
        while(n>0){
            m=k/a[n-1];
            nums+=t[m]+'0';
            t.erase(t.begin()+m);
            k=k%a[n-1];
            n--;

        }

        return nums;
    }
};
