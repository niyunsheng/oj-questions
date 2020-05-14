/**
 * @Date:   2018-08-23
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-23
 */
//思路：同字符串相乘等题目的思路是一致的，转换为int数组，然后模拟手算。共同点是都先假设结果是最大位数，然后最后输出的时候再去除前导0；
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.size(),n2=num2.size(),n=max(n1,n2)+1;
        vector<int> bign1(n1),bign2(n2),bign(n,0);
        for(int i=0;i<n1;i++)bign1[n1-1-i]=num1[i]-'0';
        for(int i=0;i<n2;i++)bign2[n2-1-i]=num2[i]-'0';
        int i=0,carry=0;
        while(i<n){
            int t=(i<n1?bign1[i]:0)+(i<n2?bign2[i]:0)+carry;
            bign[i]=t%10;
            carry=t/10;
            i++;
        }
        string ans;
        //去除前导0
        int r=n-1;
        while(r>=0&&bign[r]==0)r--;
        if(r<0)ans="0";
        while(r>=0){
            ans+=bign[r]+'0';
            r--;
        }
        return ans;
    }
};
