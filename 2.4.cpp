#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int const n=1000;

int l_mnozen(int a){
	return a*(a+1)/2;
}

int main(int argc, char** argv) {
	ifstream we("C:/cpp/wielomiany.txt");
	int stopien_w[n], roznice[n];
	string A[n];
	int i=0, najw=0;
	
	
	for(i=0; i<n; i++){
		we>>stopien_w[i];
		roznice[i]=l_mnozen(stopien_w[i])-stopien_w[i];
		if(roznice[i]>najw) najw=roznice[i];
		getline(we, A[i]);
	}
	we.close();
	
	for(i=0; i<n; i++){
		if(roznice[i]==najw) cout<<stopien_w[i]<<" "<<A[i]<<endl;
	}
	
	return 0;
}
