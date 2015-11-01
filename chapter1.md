# First Chapter

GitBook allows you to organize your book into chapters, each chapter is stored in a separate file like this one.

#DAY 1
题目地址：
https://uva.onlinejudge.org/external/112/p11292.pdf


```
#include<cstdio>
#include<algorithm>
using namespace std;


const int maxn = 20000 + 5;
int A[maxn] ,B[maxn];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) == 2 && n && m){
		for(int i = 0; i < n ; i++)
			scanf("%d",&A[i]);
		for(int i = 0; i < m; i++)
			scanf("%d",&B[i]);
		sort(A,A+n);
		sort(B,B+m);
		int cur = 0;
		int cost = 0;
		for(int i = 0; i < m; i++)
			if(B[i] >= A[cur]){
				cost += B[i];
				if(++cur == n) break;
			}
		if(cur < n) 
			printf("Loowater is doomed!\n");
		else
			printf("%d\n",cost);
	}
	return 0;
} 

```

解题思路：
把恶龙的直径放入数组中，然后对这个数组进行排序。
把骑士的能力值放入数组中，然后对这个数组进行排序。
然后拿着骑士数组中的数依次和恶龙数组中的数进行比较，如果大于，那么各自数组的下标都加1，否则，恶龙数组不加，骑士数组加1.


