#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 5;

const char dirName[][10] = {"L","Turing","R"};  //��ά�ַ����飬�ڶ�ά�ĳ�����10.L��Turing��R3�����ĳ����Ѿ���8�ˡ����Կ�����10 
int order[maxn];
struct Ant{
	int id;  //����˳�� 
	int p;    //λ�� 
	int d;    //����
	bool operator < (const Ant& a) const {
		return p < a.p;
	}
}before[maxn],after[maxn];    
//before����������Ϣ��һ����������״̬��sortǰ��sort��
//sortǰ��before���±�������롣sort��before���±���������˵�Զ����

//after�Ǿ���ʱ��T֮���һ��״̬��Ϣ��Ҳ��sortǰ��sort������״̬�� 

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
		
		//����order����
		sort(before,before+n);
		for(int i = 0; i < n; i++)
			order[before[i].id] = i;
			
		//������̬
		sort(after,after+n);
		for(int i = 0; i < n-1; i++)
		 if(after[i].p == after[i+1].p)
		 	after[i].d = after[i+1].d = 0;
			 
		//������
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
