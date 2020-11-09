// 按照栈混洗的公式写递归方程和递归基即可

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==0){
            ans.push_back("");
            return ans;
        } 
        for(int i=0;i<n;i++){
            vector<string> t1 = generateParenthesis(i);
            vector<string> t2 = generateParenthesis(n-i-1);
            for(int j=0;j<t1.size();j++){
                for(int k=0;k<t2.size();k++){
                    ans.push_back("("+t1[j]+")"+t2[k]);
                }
            }
        }
        return ans;
    }
};