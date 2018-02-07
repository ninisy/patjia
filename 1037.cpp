#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(long long int a , long long int b){return a>b;}
int main(){
	int nc, np;
	long long int tmp, sum = 0;
	vector<long long int> vcp, vcn, vpp, vpn;
	scanf("%d", &nc);
	for(int i = 0;i<nc;i++){
		scanf("%lld", &tmp);
		if(tmp>0)
			vcp.push_back(tmp);
		else
			vcn.push_back(tmp);
	}
	scanf("%d", &np);
	for(int i = 0;i<np;i++){
		scanf("%lld", &tmp);
		if(tmp>0)
			vpp.push_back(tmp);
		else
			vpn.push_back(tmp);
	}
	sort(vcp.begin(), vcp.end(), cmp);
	sort(vcn.begin(), vcn.end());
	sort(vpp.begin(), vpp.end(), cmp);
	sort(vpn.begin(), vpn.end());
	
	for(int i=0;i<vcp.size()&&i<vpp.size();i++){
		sum += vcp[i]*vpp[i];
	}
	for(int i=0;i<vcn.size()&&i<vpn.size();i++){
		sum += vcn[i]*vpn[i];
	}
	printf("%d", sum);
	system("pause");
	return 0;
}
