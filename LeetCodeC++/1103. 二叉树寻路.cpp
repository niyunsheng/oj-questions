//先用完全二叉树找到最初的路径，然后再分奇数和偶数行分别处理找到变换之后的数字。

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> v,ans;
        int len = 0;
        while((1<<len)<=label)len++;
        len--;
        // printf("%d",len);
        int k=(len%2==0)?label:((1<<len)*3-1-label);
        while(k>0){
            // printf("%d\n",k);
            v.push_back(k);
            k/=2;
        }
        for(int i=1;i<=v.size();i++){
            int r=v.size()-i;
            if(i%2==0)v[r]=(1<<(i-1))*3-1-v[r];
            ans.push_back(v[r]);
        }
        return ans;
    }
};
