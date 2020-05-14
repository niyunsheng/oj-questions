/**
 * @Date:   2018-07-23
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-07-28
 */



//蛮力算法超出时间限制，既然是脑筋急转弯题目，那么肯定有简便算法，就是找完全平方数的个数
class Solution {
public:
    int bulbSwitch(int n) {

        if(n<=0)return 0;
        else return (int)sqrt(n);


        /*一般人能都想到的蛮力算法
        bool* tmp=new bool[n];
        for(int i=0;i<n;i++)//第一轮，初始化，将灯泡全部开启
            tmp[i]=true;
        for(int j=2;j<=n;j++)//第二到n论
            for(int i=j-1;i<n;i=i+j)
                tmp[i]=!tmp[i];
        int sum=0;
        for(int i=0;i<n;i++)
            if(tmp[i])sum++;
        return sum;
        */
    }
};
