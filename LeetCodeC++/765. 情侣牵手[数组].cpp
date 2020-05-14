/**
 * @Date:   2018-08-24
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-24
 */
//思路：对于不满足条件的情侣，一次交换可以使前一对情侣坐到一起，交换一次。
//具体实现：用rank数组记录和维护节点位置信息，rank[i]=j表示编号为i的元素在row数组中的位置是j.然后就是遍历交换了。具体看代码。
#define couple(x) (x%2?(x-1):(x+1))
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size(),cnt=0;
        vector<int> rank(n);//rank[i]=j表示编号为i的元素在row数组中的位置是j
        for(int i=0;i<n;i++)rank[row[i]]=i;
        for(int i=0;i<n;i+=2){
            if(row[i]/2!=row[i+1]/2){
                int r=rank[couple(row[i])];
                swap(row[i+1],row[r]);
                swap(rank[row[i+1]],rank[row[r]]);
                cnt++;
            }
        }
        return cnt;
    }
};
