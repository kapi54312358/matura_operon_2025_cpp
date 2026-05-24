#include <iostream>

using namespace std;

int tablica2(int A[][100], int i, int n){
	int j=0, k=0, w=0;
	for(j=0; j<n; j++){
		for(k=0; k<n; k++){
			w+=A[j][k];
		}
	}
	return w;
}

int main(int argc, char** argv) {
	int n=2, i=0, w=0;
	int A[100][100];
	A[0][0]={3};
	A[1][0]={4};
	A[0][1]={5};
	A[1][1]={1};
	w=tablica2(A, i, n);
	cout<<w;
	
	return 0;
}
