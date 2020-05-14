/**
 * @Date:   2018-09-03
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-03
 */
//注意`ss+(1<<step)<60`，<<移位运算的优先级不如加法
class Solution {
public:
    int N=10;
    vector<string> ans;
    void solve(int step,int mm,int ss,int num,int cnt){
        if(step==10){
            if(cnt!=num)return;
            char tmp[10];
            sprintf(tmp,"%d:%02d",mm,ss);
            string s=tmp;
            ans.push_back(s);
            printf("%d %d %d %d\n",mm,ss,num,cnt);
            return;
        }
        //printf("%d %d %d %d\n",mm,ss,num,cnt);
        if(cnt>num)return;
        if(step<6){

            if(ss+(1<<step)<60){
                solve(step+1,mm,ss+(1<<step),num,cnt+1);
            }
            solve(step+1,mm,ss,num,cnt);
        }else{

            if(mm+(1<<(step-6))<12){
                solve(step+1,mm+(1<<(step-6)),ss,num,cnt+1);
            }
            solve(step+1,mm,ss,num,cnt);

        }
    }
    vector<string> readBinaryWatch(int num) {
        solve(0,0,0,num,0);
        return ans;
    }
};
