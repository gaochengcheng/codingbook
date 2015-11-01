# First Chapter

GitBook allows you to organize your book into chapters, each chapter is stored in a separate file like this one.

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
		sort(A,A+m);
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
