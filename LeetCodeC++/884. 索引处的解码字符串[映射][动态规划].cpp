/**
 * @Date:   2018-08-05
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-05
 */
/*题目：
给定一个编码字符串 S。为了找出解码字符串并将其写入磁带，从编码字符串中每次读取一个字符，并采取以下步骤：
    如果所读的字符是字母，则将该字母写在磁带上。
    如果所读的字符是数字（例如 d），则整个当前磁带总共会被重复写 d-1 次。
现在，对于给定的编码字符串 S 和索引 K，查找并返回解码字符串中的第 K 个字母。

示例 1：

输入：S = "leet2code3", K = 10
输出："o"
解释：
解码后的字符串为 "leetleetcodeleetleetcodeleetleetcode"。
字符串中的第 10 个字母是 "o"。

提示：本题不能将解码后的字符串存下来，这样会超过空间限制和时间限制，应该设法找到K与原字符串中字符的对应关系
*/
//解法2：寻找对应关系，动态规划，代码来自：uwi
class Solution {
	public String decodeAtIndex(String S, int K) {
		char[] s = S.toCharArray();
		int n = s.length;
		long[] dp = new long[n+1];
		for(int i = 0;i < n;i++){
			if(s[i] >= '2' && s[i] <= '9'){
				dp[i+1] = dp[i] * (s[i]-'0');
			}else{
				dp[i+1] = dp[i] + 1;
			}
		}
		K--;
		for(int i = n-1;i >= 0;i--){
			K %= dp[i+1];
			if(K+1 == dp[i+1] && !(s[i] >= '2' && s[i] <= '9')){
				return "" + s[i];
			}
		}
		return null;
	}
}

//解法1：暴力法+剪枝，超时
string decodeAtIndex(string S, int K) {
	string ans;
	long long anslen=0;
	for(int i=0;i<S.size();i++){
		if((S[i]>='a'&&S[i]<='z')||(S[i]>='A'&&S[i]<='Z')){
			anslen++;
			ans+=S[i];
			if(anslen>=K||anslen<0){
				//cout<<"1:"<<ans<<endl;
				return string(1,ans[K-1]);
			}
		}else if(S[i]>='1'&&S[i]<='9'){
			int t=S[i]-'1';
			while(t--){
				anslen+=anslen;
				ans+=ans;
				if(anslen>=K||anslen<0){
					//cout<<"2:"<<ans<<endl;
					return string(1,ans[K-1]);
				}
			}
		}
	}
}
