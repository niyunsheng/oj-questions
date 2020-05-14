/**
 * @Date:   2018-08-23
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-23
 */
//虽然自己也写对了，但是代码非常不简洁，还是答案的代码简洁，应该学习下

//答案
class Solution {
public:
 string addBinary(string a, string b) {
    int len_a = a.length();
    int len_b = b.length();
    // 新建一个结果字符串，长度为a、b串中最长的一个加1，加的一位留给进位
    int len = max(len_a, len_b);
    string res(len + 1, '0');
    int i = len_a - 1, j = len_b - 1;
    int index = len;
    int carry = 0;
    // 模拟手算
    while (index >= 0) {
	    res[index] = (i >= 0 ? a[i] : '0') + (j >= 0 ? b[j] : '0') + carry - '0';
	    carry = (res[index] - '0') / 2;
	    res[index] = (res[index] - '0') % 2 + '0';
	    index--;
	    i--;
	    j--;
    }
    index = 0;
    // 找到第一个不为0的位置
    while (res[index] == '0' && index <= len) index++;
    // 如果结果为0，就直接返回0
    if (index == len + 1)
	    return "0";
    return res.substr(index);
}
};
//自己写的
class Solution {
public:
    string addBinary(string a, string b) {
        int n1=a.size(),n2=b.size();
        string strans;
        vector<int> str1,str2,ans(max(n1,n2)+1);
        for(int i=0;i<n1;i++)str1.push_back(a[n1-1-i]-'0');
        for(int i=0;i<n2;i++)str2.push_back(b[n2-1-i]-'0');
        int carry=0;
        int i=0;
        while(i<n1&&i<n2){
            ans[i]=(carry+str1[i]+str2[i])%2;
            carry=(carry+str1[i]+str2[i])/2;
            //cout<<ans[i]<<carry<<endl;
            i++;
        }
        while(i<n1){
            ans[i]=(carry+str1[i])%2;
            carry=(carry+str1[i])/2;
            i++;
        }
        while(i<n2){
            ans[i]=(carry+str2[i])%2;
            carry=(carry+str2[i])/2;
            i++;
        }
        if(carry!=0)ans[i++]=carry;
        while(i>0){
            i--;
            if(ans[i])strans+="1";
            else strans+="0";
        }

        return strans;
    }
};
