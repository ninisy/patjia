#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int m;

struct student{
  int id,score;
  string name;
}tempstd;
vector<student> s;
bool cmp(student s1,student s2){
  if(m==1){
    return s1.id< s2.id;
  }
  else if(m==2){
    return s1.name != s2.name ? s1.name<s2.name:s1.id<s2.id;
  }
  else if(m==3){
    return s1.score != s2.score ? s1.score<s2.score:s1.id<s2.id;
  }
  return false;
}
int main(){
  int n;
  scanf("%d %d",&n,&m);
  //cin>>n>>m;
  for(int i=0;i<n;i++){
    //cin>>tempstd.id>>tempstd.name>>tempstd.score;
    //s.push_back(tempstd);
    scanf("%d",&tempstd.id);
    cin>>tempstd.name;
    scanf("%d", &tempstd.score);
    s.push_back(tempstd);
  }
  sort(s.begin(), s.end(),cmp);
  for(int i=0;i<n;i++){
    printf("%06d %s %d\n",s[i].id, s[i].name.c_str(), s[i].score);
  //  cout<<s[i].name<<" "<<s[i].score<<endl;
  }
  system("pause");
  return 0;
}
