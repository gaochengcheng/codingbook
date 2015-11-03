#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 5;

const char dirName[][10] = {"L","Turing","R"};  //二维字符数组，第二维的长度是10.L、Turing、R3个串的长度已经是8了。所以开到了10 
int order[maxn];
struct Ant{
	int id;  //输入顺序 
	int p;    //位置 
	int d;    //方向
	bool operator < (const Ant& a) const {
		return p < a.p;
	}
}before[maxn],after[maxn];    
//before保存输入信息，一共经历两个状态，sort前和sort后。
//sort前，before中下标代表输入。sort后before中下标代表距离左端的远近。

//after是经过时间T之后的一个状态信息。也有sort前和sort后两个状态。 

int main(){
	int k;
	scanf("%d",&k);
	for(int kase = 1; kase <= k; kase ++){
		int L, T, n;
		printf("Case #%d:\n",kase);
		scanf("%d%d%d",&L, &T, &n);
		for(int i = 0; i < n; i++){
			int p, d;
			char c;
			scanf("%d %c",&p,&c);
			d = (c == 'L' ? -1 : 1);
			before[i] = (Ant){i, p, d};
			after[i] = (Ant){i, p+T*d, d};
		}
		
		//计算order数组
		sort(before,before+n);
		for(int i = 0; i < n; i++)
			order[before[i].id] = i;
			
		//计算终态
		sort(after,after+n);
		for(int i = 0; i < n-1; i++)
		 if(after[i].p == after[i+1].p)
		 	after[i].d = after[i+1].d = 0;
			 
		//输出结果
		for(int i = 0; i < n; i++){
			int a = order[i];
			if(after[a].p < 0 || after[a].p > L)
				printf("Fell off\n");
			else
				printf("%d %s\n",after[a].p,dirName[after[a].d+1]);
		}
		
		printf("\n");
	} 
	return 0;
	
} 
