//Quick sort
#include<iostream.h>
class Quick{
	int *a,n,l;
    public:
      Quick();
      ~Quick();
      void f(int,int);
      int sort(int,int);
      void Disp();
      void call(){
      	f(0,n-1);
      }
      friend istream& operator>>(istream&,Quick&);
};
int main(){
    Quick m;
    cin>>m;
}
istream& operator>>(istream& is,Quick& k){
    k.Disp();
    k.call();
    k.Disp();
}
Quick::Quick(){
	cout<<"Enter size:";
	cin>>n;
	a=new int[n];
	for(l=0;l<n;l++){
		cout<<"Enter a["<<l<<"]:";
		cin>>a[l];
	}   
}
Quick::~Quick(){
	delete(a);
}
void Quick::Disp(){
		cout<<"[";
	for(l=0;l<n;l++)
		cout<<a[l]<<",";
     cout<<"\b]"<<endl;   
}
void Quick::f(int lo,int hi){
    int z;
	if(lo<hi){
		z=sort(lo,hi);
		f(lo,z-1);
		f(z+1,hi);
	}
}
int Quick::sort(int low,int high){
	int i,j,p,t;
	i=low+1;
	j=high;
	p=a[low];
	while(i<=j){
		while(a[i]<p && i<=j)
		    i++;
		while(p<a[j] && i<=j)
		    j--;
		if(i<=j){
		  t=a[i];
		  a[i]=a[j];
		  a[j]=t;
		}
	}
	a[low]=a[j];
	a[j]=p;
	return j;
}
