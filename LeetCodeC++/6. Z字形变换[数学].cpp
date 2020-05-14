/**
 * @Date:   2018-08-24
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-24
 */
class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        if(numRows==1)return s;
        int r=0;
        while(r<s.size()){ans+=s[r];r=r+2*numRows-2;}
        for(int i=1;i<numRows-1;i++){
            int r=i;
            while(1){
                if(r>=s.size())break;
                ans+=s[r];
                if(r+2*numRows-2-2*i>=s.size())break;
                ans+=s[r+2*numRows-2-2*i];
                r=r+2*numRows-2;
            }
        }
        r=numRows-1;
        while(r<s.size()){ans+=s[r];r=r+2*numRows-2;}
        return ans;
    }
};
