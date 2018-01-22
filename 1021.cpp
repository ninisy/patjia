#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

set<int> s;
int n,maxheight = 0;
vector<int> temp,s1;
vector<vector <int>> e;
bool visit[10002];
void dfs(int v,int height){
	if(height>maxheight){
		maxheight = height;
		temp.clear();
		temp.push_back(v);
	}else if(height==maxheight){
		temp.push_back(v);
	}
	visit[v] = true;
	for(int i=0;i<e[v].size();i++){
		if(visit[e[v][i]]==false){
			dfs(e[v][i],height+1);
		}
	}
}

int main(){
	int a,b;
	cin>>n;
	e.resize(n+1);
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	int cnt=0,s2=0;
	for(int i=1;i<=n;i++){
		if(visit[i]==false)
		{
			dfs(i,1);
			if(i==1)
			{
				for(int j=0;j<temp.size();j++)//j
				{
					//s1.push_back(temp[j]);
					s.insert(temp[j]);
					if(j==0) s2= temp[j];
				}
			}
			cnt++;
		}
	}
	if(cnt>=2){
		cout<<"Error: "<<cnt<<" components"<<endl;}
	else
	{
		temp.clear();	
		maxheight = 0;
		fill(visit,visit+10002,false);
		dfs(s2,1);
		for(int i=0;i<temp.size();i++)
			s.insert(temp[i]);
			//s1.push_back(temp[i]);
		sort(s1.begin(),s1.end());
		//for(int i=0;i<s1.size();i++)
		//	cout<<s1[i]<<endl;

		for(auto it =s.begin();it !=s.end();it++)
			printf("%d\n",*it);

	}
	system("pause");
	return 0;
}
