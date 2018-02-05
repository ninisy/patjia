#include<iostream>
#include<string>
#include<vector>
using namespace std;
char change(char a){
	if(a=='1')
		a='@';
	else if(a=='0')
		a='%';
	else if(a=='l')
		a='L';
	else if(a=='O')
		a='o';
	return a;
}
struct node{
	string nname, np;
};
int main(){
	int n;
	string name, p;
	vector<node> rel;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		cin>>name>>p;
		bool flag = true;
		for(int j=0;j<p.size();j++){
			if(p[j]=='1'||p[j]=='0'||p[j]=='l'||p[j]=='O'){
				p[j]=change(p[j]);
				flag = false;
			}
		}
		if(!flag){
			node temp;
			temp.nname = name;
			temp.np = p;
			rel.push_back(temp);
		}
	}
	if(rel.size()==0&&n==1)
		printf("There is 1 account and no account is modified");
	else if(rel.size()==0)
		printf("There are %d accounts and no account is modified", n);
	else {
		printf("%d\n",rel.size());
		for(int i=0;i<rel.size();i++){
			cout<<rel[i].nname<<" "<<rel[i].np<<endl;
		}
	}
	system("pause");
	return 0;
}
