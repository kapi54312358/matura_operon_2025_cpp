#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int const n=1000;

void fib(long long *A){
	int i=0;
	A[0]=1;
	A[1]=2;
	for(i=2; i<90; i++){
		A[i]=A[i-1]+A[i-2];
	}
}

int potega2(int a, int s){
	if(s==0) return a;
	int w=a;
	for(int i=0; i<s; i++){
		w*=2;
	}
	return w;
}

bool czy_w_fib(int a, long long *A){
	for(int i=0; i<90; i++){
		if(A[i]==a) return 1;
	}
	return 0;
}

int main(int argc, char** argv) {
	ifstream we("C:/cpp/wielomiany.txt");
	stringstream ss;
	vector<int> wspolczynniki;
	int stopien_w[n];
	long long c_fib[90];
	string a="";
	int i=0, j=0, wielomian=0;
	fib(c_fib);
	
	for(i=0; i<n; i++){
		we>>stopien_w[i];
		getline(we,a);
		ss.clear();
		ss.str(a);
		wielomian=0;

        wspolczynniki.resize(stopien_w[i]+1);
        for (j=0; j<=stopien_w[i]; j++){
        	ss>>wspolczynniki[j];
        	wielomian+=potega2(wspolczynniki[j], stopien_w[i]-j);
		}
		if(czy_w_fib(wielomian, c_fib))
			cout<<stopien_w[i]<<a<<endl;
	}
	we.close();
	
	
	return 0;
}
