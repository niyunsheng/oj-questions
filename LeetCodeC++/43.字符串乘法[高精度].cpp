/**
 * @Date:   2018-08-23
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-23
 */
//> 思路：高精度典型算法，应注意到n1位*n2位，结果最大为n1+n2位，位数不够的话要去除前导0，如果结果为0，记得输出0

class Solution {
public:

    string multiply(string num1, string num2) {
        int n1=num1.size(),n2=num2.size();
        vector<int> bign1(n1),bign2(n2),bign(n1+n2,0);
        for(int i=0;i<n1;i++)bign1[n1-1-i]=num1[i]-'0';
        for(int i=0;i<n2;i++)bign2[n2-1-i]=num2[i]-'0';
        //n2做乘数，n1做被乘数
        for(int i=0;i<n2;i++){
            int carry=0;
            for(int j=0;j<n1;j++){
                int t=bign[i+j]+(carry+bign1[j]*bign2[i]);
                //这里要先保存t，然后再更新该数位和进位
				bign[i+j]=t%10;
                carry=t/10;
            }
            if(carry!=0){
                bign[i+n1]=carry;
            }
        }
        string ans;
        //去除前导0
        int r=n1+n2-1;
        while(r>=0&&bign[r]==0)r--;
        if(r<0)ans="0";
        while(r>=0){
            ans+=bign[r]+'0';
            r--;
        }
        return ans;
    }
};
