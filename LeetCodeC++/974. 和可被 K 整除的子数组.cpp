//总体思路：动态规划
/*
	用sum[i]记录A[0]-A[i]的和，将余数的个数记录到v数组当中，如果某个余数的个数有k个，则对应的和是K的倍数的子数组的个数是k*(k-1)/2个。
*/
int subarraysDivByK(vector<int>& A, int K) {
	int cnt=0,sum=0;
	vector<int> v(K,0);
	for(int i=0;i<A.size();i++){
		sum+=A[i];
		sum=(sum%K+K)%K;
		v[sum]++;
	}
	for(int i=0;i<K;i++)if(v[i]>=2){cnt+=v[i]*(v[i]-1)/2;}
	cnt+=v[0];
	return cnt;
}
