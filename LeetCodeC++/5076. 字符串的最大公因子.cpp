class Solution {
public:
    //类比辗转相除法
    //gcd(a,b){return a%b==0?b:gcd(b,a%b);}
    string gcdOfStrings(string str1, string str2) {
        if(str1==str2)return str1;
        if(str1.size()<str2.size()){
            swap(str1,str2);
        }
        int n1=str1.size(),n2=str2.size();
        string ans="";
        int i=0,j=0;
        for(;i<n1;i++,j++){
            if(j>=n2){
                j=0;ans="";
            }
            if(str1[i]!=str2[j])return "";
            ans+=str1[i];
        }
        return gcdOfStrings(str2,ans);
    }
};
