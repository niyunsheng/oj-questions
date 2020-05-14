class Solution {
public:
    int maxProduct(vector<string>& w) {
        int n=w.size();
        vector<int> A(w.size(),0),B(w.size(),0);
        int ans=0;
        for(int i=0;i<w.size();i++){
            B[i]=w[i].size();
            for(int j=0;j<B[i];j++)A[i]|=(1<<(w[i][j]-'a'));
        }
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if((A[i]&A[j])==0)ans=max(ans,B[i]*B[j]);//(A[i]&A[j])这里要加括号，否则运算顺序出错
        return ans;
    }
};
