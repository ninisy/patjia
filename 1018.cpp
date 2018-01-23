#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int inf = 99999999 ;
int ttime[510][510],mtime[510],minneed = inf,minback=inf;//因为变量名是time所以报编译错误，可能是与某个重名了
bool visit[510];
vector< int> road[510];
vector<int> c,temppath,path;

void dfs(int node){
	temppath.push_back(node);
	if(node ==0){
		int need=0,back=0;
		for(int i=temppath.size()-1;i>=0;i--){
			int id = temppath[i];
			if(c[id]>0){
				back = back+c[id];
			}
			else{
				if(back>(0-c[id]))
					back +=c[id];
				else{
					need +=((0-c[id])-back);
					back=0;
				}
			}
		}
		if(need<minneed){
			minneed = need;
			minback = back;
			path = temppath;
		}else if(need==minneed&&back<minback){
			minback = back;
			path = temppath;
		}
		temppath.pop_back();
		return ;

	}
	for(int i=0;i<road[node].size();i++)
		dfs(road[node][i]);
	temppath.pop_back();
}

int main(){
	int cmax,n,p,m,a,b,t;
	cin>>cmax>>n>>p>>m;
	c.resize(n+1);
	fill(mtime,mtime+510,inf);
	fill(ttime[0],ttime[0]+510*510,inf);
	for(int i=1;i<=n;i++){
		cin>>c[i];
		c[i] = c[i]-cmax/2;
	}
	for(int i=0;i<m;i++){
		cin>>a>>b>>t;
		ttime[a][b]=ttime[b][a]=t;
	}
	//vector<int> *road = new vector<int> [n+1];
	
	mtime[0]=0;
	for(int i=0;i<=n;i++){
		int u=-1,mmin = inf;
		for(int j = 0;j<=n;j++){
			if(visit[j]==false&&mtime[j]<mmin){
				u=j;
				mmin = mtime[j];
			}
		}
		if(u==-1) break;
		visit[u] = true;

		for(int v = 0;v<=n;v++){
			if(visit[v]==false&&ttime[u][v]!=inf){
				if(ttime[u][v]+mtime[u]<mtime[v]){
					mtime[v] = ttime[u][v]+mtime[u];
					road[v].clear();
					road[v].push_back(u);
				}
				else if(ttime[u][v]+mtime[u]==mtime[v]){
					
						road[v].push_back(u);
					
				}
			}
		}
	}
	dfs(p);
	printf("%d 0", minneed);
	for(int i=path.size()-2;i>=0;i--){
		printf("->%d",path[i]);
	}
	printf(" %d",minback);
	system("pause");
	return 0;
}
