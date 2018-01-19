#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
	int t1,t2;
};
bool cmp(node a, node b)
{
	return a.t1<b.t1;
}
bool cmp1(int a, int b){return a<b;}
int main(){
	int n,k,h,m,s,t;
	cin>>n>>k;
	vector<node> a;
	for(int i=0;i<n;i++){
		node temp;
		scanf("%d:%d:%d",&h,&m,&s);
		temp.t1 = h*3600+m*60+s;
		scanf("%d",&t);
		if(t>60)
			t=60;
		temp.t2=t*60;
		a.push_back(temp);
	}
	sort(a.begin(),a.end(),cmp);
	int *curtime = new int[k],total=0;
	fill(curtime,curtime+k,8*3600);
	int i;
	for(i=0;i<n;i++){
		if(a[i].t1>17*3600)
			break;
		if(a[i].t1<curtime[0]){
			total += curtime[0]-a[i].t1;
			curtime[0] = curtime[0]+a[i].t2;
		}
		else
			curtime[0] =a[i].t1+a[i].t2;//注意：当有窗口空闲，但是顾客还没有来时，是需要另外考虑的
		
		
		sort(curtime,curtime+k,cmp1);
	}
	if(n==1)
		printf("%.1f",total/(60.0*1));
	else if(n==0)
		printf("0.0");
	else
		printf("%.1f",total/(60.0*i));
	system("pause");
	return 0;
}

