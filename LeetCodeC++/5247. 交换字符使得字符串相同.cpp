/*
所有不同情况只会有x - y 和 y - x两种情况
分别统计x - y和y - x的次数计为cnt1 和 cnt2, 简单判断可知如果cnt1 + cnt2是奇数是无法完成交换的
简单分析可以得出两个x - y 可以一次交换恢复成 x - x 和 y - y, 两个y - x也是同理
针对可能多出来的x - y和 y - x组合
x - y 和 y - x一次交换可以变成两个 y - x 或者 两个x - y
所以需要多进行一次交换
*/
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if(s1.length()!=s2.length())
            return -1;
        int c1=0,c2=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                if(s1[i]=='x')
                    c1++;
                else
                    c2++;
            }
        }
        cout<<c1<<"  "<<c2<<endl;
        if((c1+c2)%2!=0)
            return -1;
        if(c1%2==0)
            return (c1+c2)/2;
        else
            return (c1+c2)/2+1;
    }
};