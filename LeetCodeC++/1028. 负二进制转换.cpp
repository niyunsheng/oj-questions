/*
采取从高位到低位的顺序，分别对每一个奇数位进行修复处理，通过例子分析，可以看成，当该奇数位为1时才需要修复，当其高位为0时，只需要将其高位置1即可。当其高位为1时，根据其更高位采用不同的方法。其更高位为1时，只需要同时将其高位和更高位置0即可；其更高位为0时，同时将其高位和更高位取反后，修复上溢，对其跟高位进行修复。
*/
class Solution {
public:
    void repair(int& N,int i){
        if(N&i){
            if(N&(i<<1)){
                if(N&(i<<2)){
                    N=N^(i<<1);
                    N=N^(i<<2);
                }else{
                    N=N^(i<<1);
                    N=N^(i<<2);
                    repair(N,i<<2);
                }
            }else{
                N=N^(i<<1);
            }
        }
    }
    string baseNeg2(int N) {
        int i=1<<29;
        while(i>1){
            repair(N,i);
            i=i>>2;
        }
        // cout<<N<<endl;
        string s;
        while(N>0){
            if(N%2){
                s.push_back('1');
            }else{
                s.push_back('0');
            }
            N/=2;
        }
        reverse(s.begin(),s.end());
        if(s.empty())s.push_back('0');
        return s;
    }
};
