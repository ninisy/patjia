#include<iostream>
#include<algorithm>
using namespace std;

//int e[510][510], weight[510], dis[510], num[510], w[510];

const int inf = 99999999;
int n,m,c1,c2;
bool visit[510];
//int e[510][510] = {inf},w[510]= {0},weight[510] = {0},num[510] = {0},dis[510] = {inf};//因为inf很大，所以需要放到最外面，否则会出错。
//上面的初始化有问题，仔细看看初始化部分知识
int main(){
	
	cin>>n >>m>>c1>>c2;
	//scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for(int i = 0;i<n;i++){
		cin>>weight[i];
		//scanf("%d", &weight[i]);
	}
	fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
	int a,b,c;
	for(int i = 0;i<m;i++){
		cin>>a>>b>>c;
		//scanf("%d%d%d", &a, &b, &c);
		e[a][b] = e[b][a] = c;
	}
	dis[c1] = 0;
	w[c1] = weight[c1];
	num[c1] = 1;
	for(int i = 0;i<n;i++){
		int u = -1,mmin = inf;
		for(int j = 0;j<n;j++){
			if(visit[j]==false&&dis[j]<mmin){
				u = j;
				mmin = dis[j];
			}
		}
		if(u == -1) break;
		visit[u] = true;
		for(int v = 0;v<n;v++){
			if(visit[v]==false&&e[u][v]!=inf){//这里没写对
			if(dis[u]+e[u][v]<dis[v]){
				dis[v] = dis[u]+e[u][v];
				num[v] = num[u];
				//if(weight[v]+w[u]>w[v])因为是最短路径上的最大权值
					w[v] = weight[v]+w[u];
			}
			else if(dis[u]+e[u][v]==dis[v]){
				num[v] = num[u]+num[v];//这里写成了num[u]+1；
				if(weight[v]+w[u]>w[v])
					w[v] = weight[v]+w[u];
			}
		}
		}
	}

	cout<<num[c2]<<" "<<w[c2]<<endl;
	//printf("%d %d", num[c2], w[c2]);
	system("pause");
	return 0;

}
