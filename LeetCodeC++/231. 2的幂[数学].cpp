/**
 * @Date:   2018-09-12
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-12
 */
class Solution {
public:
    //这个小技巧不错的
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        int tag=1<<30;
        return (tag%n)==0;
    }
};
