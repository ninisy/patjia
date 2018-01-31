#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int inf = 99999999;
int d[510][510], cost[510][510], c[510], dis[510], m;
bool visit[510];
vector<vector<int>> path(510);//存储最短路径

int main(){
	int n, start, dist;
	scanf("%d %d %d %d",&n, &m, &start, &dist);
	fill(d[0],d[0]+510*510,inf);
	fill(dis, dis+510, inf);
	fill(cost[0],cost[0]+510*510,inf);
	fill(visit,visit+510,false);
	for(int i=0;i<m;i++){
		int tc1, tc2, td, tc;
		scanf("%d %d %d %d",&tc1,&tc2,&td,&tc);
		d[tc1][tc2] = d[tc2][tc1] = td;
		cost[tc1][tc2] = cost[tc2][tc1] = tc;
	}
	d[start][start] = 0;
	dis[start] = 0;
	c[start] = 0;
	path[start].push_back(start);
	for(int i=0;i<m;i++){
		int u = -1, mmin = inf;
		for(int j=0;j<m;j++){
			if(visit[j]==false && dis[j]<mmin){
				u = j;
				mmin = c[j];
			}
		}
		if(u==-1) break;
		visit[u] = true;
		for(int v =0; v < m; v++){
			if(d[u][v]+dis[u]<dis[v]){
				dis[v] = d[u][v]+dis[u];
				c[v] = c[u] + cost[u][v];
				path[v].clear();
				path[v] = path[u];
				path[v].push_back(v);
			}else if(d[u][v]+dis[u]==dis[v]){
				if(c[u]+cost[u][v]<c[v]){
					c[v] = c[u] + cost[u][v];
					path[v].clear();
					path[v] = path[u];
					path[v].push_back(v);
				}
			}
		}
	}
	printf("%d",start);
	for(int i = 1;i<path[dist].size();i++)
		printf(" %d",path[dist][i]);
	printf(" %d %d",dis[dist], c[dist]);
	system("pause");
	return 0;
}
