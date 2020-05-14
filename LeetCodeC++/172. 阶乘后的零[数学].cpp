/**
 * @Date:   2018-08-14
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-14
 */
class Solution {
public:
    //对于阶乘这个大数，我们不可能将其结果计算出来，再统计其末尾所含有的“0”的个数。所以必须从其数字特征进行分析。下面我们从因式分解的角度切入分析。
    //dp。n!与5k*5(k-1)*……*10*5的零的个数相同，则f(n)=n/5+f(n/5),f(5)=1,f(1)=0
    int fun(int n){
        if(n<=1)return 0;
        return n/5+fun(n/5);
    }
    int trailingZeroes(int n) {
        return fun(n);
    }
};
