/*
**x2表示2号给1号的金币数。 
**x2=x1-C1.   C数组是构造出的。 
*/ 

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 10;
long long A [maxn], C[maxn], tot, M;
int main(){
	int n;
	while(scanf("%d",&n) == 1){
		tot = 0;
		for(int i = 1; i <= n; i++){
			scanf("%lld",&A[i]);
			tot += A[i];
		}
		M = tot / n;
		C[0] = 0 ;
		for(int i = 1; i < n; i++)
			C[i] = C[i-1] + A[i] - M;     // 构造C数组 
		sort(C,C+n);
		long long x1 = C[n/2],ans = 0;  //计算x1.同时也是找到中位数。 
		for(int i = 0; i < n; i++)
			ans += abs(x1 - C[i]);      //计算交手的金币总数。 
		//把x1代入，计算转手的总金额
		printf("%lld\n",ans); 
	}
	return 0;
}
 
