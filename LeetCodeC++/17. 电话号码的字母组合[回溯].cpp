/**
 * @Date:   2018-09-03
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-03
 */
class Solution {
public:
    vector<string> ans;
    string tmp;
    int num[8]={3,3,3,3,3,4,3,4};
    void solve(int step,string& digits){
        if(step==digits.size()){
            ans.push_back(tmp);

            return;
        }
        int r=(digits[step]-'2')*3;
        if(digits[step]>'7')r++;
        for(int i=0;i<num[digits[step]-'2'];i++){
            tmp.push_back('a'+r+i);
            solve(step+1,digits);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return ans;
        solve(0,digits);
        return ans;
    }
};
