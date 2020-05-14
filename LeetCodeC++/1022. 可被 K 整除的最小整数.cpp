//本题采用模拟的方法，难点在于为什么模拟到K个1就可以停止模拟了呢？需要证明其中的循环特点。可以这样考虑，对于K来说，其余数至多有0到K-1共K个，如果K次尝试不成功的话，必然产生循环，后面的尝试就无用了。也可以用出现余数的次数来进行剪枝，如果是第二次出现相同的余数，则可终止循环。不过，这样剪枝的代价是增加了空间复杂度。
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K%2==0||K%5==0)return -1;
        int res=1;
        for(int i=1;i<=K;i++){
            if(res%K==0)return i;
            res=(res*10+1)%K;
        }
        return -1;
    }
};
