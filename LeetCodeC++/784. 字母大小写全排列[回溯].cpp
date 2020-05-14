/**
 * @Date:   2018-09-03
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-03
 */
//回溯法的套路真的是很固定啊
class Solution {
public:
    vector<string> ans;
    string tmp;
    void solve(int step,string& S){
        if(step==S.size()){
            ans.push_back(tmp);
            return;
        }
        if(S[step]>='0'&&S[step]<='9'){
            tmp+=S[step];
            solve(step+1,S);
            tmp.pop_back();
        }else{
            tmp+=tolower(S[step]);
            solve(step+1,S);
            tmp.pop_back();
            tmp+=toupper(S[step]);
            solve(step+1,S);
            tmp.pop_back();
        }
    }
    vector<string> letterCasePermutation(string S) {
        solve(0,S);
        return ans;
    }
};
