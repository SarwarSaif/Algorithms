#include<bits/stdc++.h>

using namespace std;

int ST[100];
int w[100][100];
int node;
int d[100];

TVS(int T,int delta){
	
	if(ST[T]!=0){
		
		if((2*T) >node)
		   d[ST[T]]=0;
		   
		else{
			
			TVS(2*T,delta);
			d[T]= max(d[T],(d[2*T]+w[T][2*T]));
			
			if( ((2*T)+1)<=node ){
				TVS( ((2*T)+1) , delta );
				d[T]= max( d[T],( d[(2*T)+1]+w[T][(2*T)+1] ) );
			}
		}
		
		if(ST[T]!=1 && ( d[T] + w[(T/2)][T] )>delta ) {
			cout<<"Splitting Tree ";
			cout<<ST[T]<<endl;
		   d[T]=0;
		}  		
		
	}
}


int main(){
	
	int delta, vertex;
	
	cout<<"No. of Nodes : ";
	cin>>node;
	
	cout<<"Enter a Tree : ";
	
	
	for(int i=1;i<=node;i++){
		cin>>Tree[i];
	}
	
	cout<<"Delta :"<<endl;
	cin>>delta;
	cout<<endl;
	
	cout<<"Vertex : ";
	cin>>vertex;
	cout<<endl;
	
	for(int k=1;k<=vertex;k++){
		
			
			int val,i,j;
			cout<<"Enter Index i & j : ";
			cin>>i>>j;
			cout<<"Enter Value : ";
			cin>>val;
			w[i][j]=w[j][i]=val;
			cout<<endl;
			
		
	}
	
	TVS(1,delta);
	
	return 0;
}













