#include<iostream>
using namespace std;
int n;
int visit[1010],c[1010][1010];
void dfs(int node){
	visit[node]= true;
	for(int i=1;i<=n;i++){
		if(visit[i]==false&&c[node][i]==1)
			dfs(i);
	}
}

int main(){
	int m,k,a,b,tmp;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		c[a][b] = c[b][a]=1;
	}
	for(int i =0;i<k;i++){
		fill(visit,visit+1010,false);
		cin>>tmp;
		visit[tmp]=true;
		int count =0;
		for(int j = 1;j<=n;j++){
			if(visit[j]==false){
				dfs(j);
				count++;
			}
		}
		cout<<count-1<<endl;
	}

	system("pause");
	return 0;
}
