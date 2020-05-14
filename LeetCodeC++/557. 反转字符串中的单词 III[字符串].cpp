/**
 * @Date:   2018-09-12
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-12
 */
//本题技巧：可以先统一后面加上空格，然后把最后一个空格去掉，在非标准输出时，即本题输出到字符串时可采用此技巧
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string tmp,ans;
        while(ss>>tmp){
            reverse(tmp.begin(),tmp.end());
            ans+=tmp+" ";
        }
        ans.pop_back();
        return ans;
    }
};
