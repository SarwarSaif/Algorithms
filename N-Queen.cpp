#include<bits\stdc++.h>
using namespace std;
int N;
bool online_safe(int board[100][100],int row,int col){
	
	for(int i=0;i<N;i++){
		if(board[i][col]==1)
		   return false;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(board[i][j]==1){
				if((i+j)==(row+col) ||(i-j)==(row-col) )
				{
					return false;
				}
			}
		
	   }
		
	}
	return true;
	
}

bool findPlace(int board[100][100],int row){
	if(row>=N)
	return true;
	
	for(int i=0;i<N;i++){
		if(online_safe(board,row,i)){
			board[row][i]=1;
			if(findPlace(board,row+1)==true)
			return true;
			board[row][i]=0;
		}
		
	}
	return false;
	
}



int main(){
	
	cout<<"enter N ";
	cin>>N;
	cout<<endl;
	
	int board[100][100]={0};
	if(findPlace(board,0)==true){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout<<board[i][j]<<"  ";
			}
			cout<<endl;
			cout<<endl;
		}
	}
	
	
	return 0;
}
