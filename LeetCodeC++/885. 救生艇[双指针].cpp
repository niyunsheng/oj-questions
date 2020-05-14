/**
 * @Date:   2018-08-05
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-05
 */
 class Solution {
 public:
     int numRescueBoats(vector<int>& people, int limit) {
         sort(people.begin(),people.end());
         int lo=0,hi=people.size()-1;
         int num=0;
         while(lo<hi){
             if(people[lo]+people[hi]<=limit){
                 num++;lo++;hi--;
             }else if(people[hi]<=limit){
                 num++;hi--;
             }
         }
         if(lo==hi)num++;
         return num;
     }
 };
