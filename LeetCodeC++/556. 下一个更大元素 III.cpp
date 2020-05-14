/**
 * @Date:   2018-07-21
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-07-28
 */



//556. 下一个更大元素 III
//这个题目的意思是数字完全相同，还是应该保留数字然后比大小
//注意仔细分析数位变换的规律,然后发现，本题不需要调用sort函数

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> t;
        while(n>0){
            t.push_back(n%10);
            n=n/10;
        }
        int i=0;
        while(i+1<t.size()&&t[i]<=t[i+1])i++;
        if(i+1==t.size())return -1;
        int j=0;
        for(;j<i+1;j++)if(t[j]>t[i+1])break;
        swap(t[j],t[i+1]);
        //sort(t.begin(),t.begin()+i+1,cmp);//本来就是有序序列，不需要重新排序，只需要reverse即可
        reverse(t.begin(),t.begin()+i+1);
        int sum=0;
        for(int i=t.size()-1;i>=0;i--){
            if(sum>214748364)return -1;
            if(sum==214748364&&t[i]>7)return -1;
            sum=sum*10+t[i];
        }
        return sum;
    }

};
