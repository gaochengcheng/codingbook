/*
**x2��ʾ2�Ÿ�1�ŵĽ������ 
**x2=x1-C1.   C�����ǹ�����ġ� 
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
			C[i] = C[i-1] + A[i] - M;     // ����C���� 
		sort(C,C+n);
		long long x1 = C[n/2],ans = 0;  //����x1.ͬʱҲ���ҵ���λ���� 
		for(int i = 0; i < n; i++)
			ans += abs(x1 - C[i]);      //���㽻�ֵĽ�������� 
		//��x1���룬����ת�ֵ��ܽ��
		printf("%lld\n",ans); 
	}
	return 0;
}
 
