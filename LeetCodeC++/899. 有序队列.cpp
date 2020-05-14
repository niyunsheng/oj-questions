/**
 * @Date:   2018-09-02
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-02
 */
//当k>1时，相当于冒泡排序，因为任意两个相邻数据都可以在头部交换顺序到尾部。
//当k==1时，遍历所有可能结果
class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K>1){
            sort(S.begin(),S.end());
            return S;
        }
        string minS=S;
        for (int i=0;i<S.size();++i){
            S=S.substr(1)+S.substr(0,1);
            minS=min(S,minS);
        }
        return minS;
    }
};
