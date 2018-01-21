#include<iostream>
#include<vector>
using namespace std;
vector<int> level(1000000,-1),post,in;
void pre(int root, int start, int end, int index){
	if(start>end) return ;
	int i=start;
	while(in[i]!=post[root]&&i<end) i++;//important!
	level[index] = post[root];
	pre(root-(end+1-i),start,i-1,2*index+1);
	pre(root-1,i+1,end,2*index+2);
}
int main(){
	int n,cnt=0;
	cin>>n;
	post.resize(n);//**
	in.resize(n);//**
	for(int i=0;i<n;i++) cin>>post[i];
	for(int i=0;i<n;i++) cin>>in[i];
	pre(n-1,0,n-1,0);
	for(int i=0;i<level.size();i++){
		if(level[i]!=-1) {
			if(cnt!=0) printf(" ");
			printf("%d",level[i]);
			cnt++;}
		if(cnt==n) break;
	}
	system("pause");
	return 0;
}
