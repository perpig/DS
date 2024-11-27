#include "Assistance.h"
#include "DblLinkList.h"

void test01()
{
    int N,K,M;
    cout<<"请输入N、K、M"<<endl;
    cin>>N>>K>>M;
	int v[N];
	for(int i=0;i<N;i++)
      v[i]=i+1;
	DblLinkList<int> myList(v,N);
    myList.PrintElem(N,K,M);
    cout<<endl;
}

void test02()
{
    int N,K,M;
    cout<<"请输入N K M:"<<endl;
    cin>>N>>K>>M;
	int v[N];
	for(int i=0;i<N;i++)
      v[i]=i+1;
	DblLinkList<int> myList(v,N);
    myList.solve2(N,K,M);
}


int main()
{
    //test01();
    test02();
    return 0;
}
