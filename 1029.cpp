#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,m;
	vector<long int> q;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		long int temp;
		scanf("%ld",&temp);
		q.push_back(temp);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		long int temp;
		scanf("%ld",&temp);
		q.push_back(temp);
	}
	sort(q.begin(),q.end());
	printf("%ld",q[(n+m-1)/2]);
	system("pause");
	return 0;
}
