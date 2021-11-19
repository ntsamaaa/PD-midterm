#include <bits/stdc++.h>
using namespace std;
int numCenter = 0, numStore = 0, shippingRate = 0, s = 0;
int pCenter[50][2] = {0}, pStore[1000][2] = {0}, demand[1000]={0}, storeCost[1000]={0}, price[1000]={0}, centerCost[50]={0}, centerV[50]={0};

void readInput();

int main(){
	readInput();
	
	return 0;
}

void readInput(){
	cin >> numCenter >> numStore >> shippingRate >> s;
	for(int i=0; i<numCenter; ++i){
		cin >> pCenter[i][0] >> pCenter[i][1];
	}
	for(int i=0; i<numStore; ++i){
		cin >> pStore[i][0] >> pStore[i][1];
	}
	for(int i=0; i<numStore; ++i){
		cin >> demand[i];
	}
	for(int i=0; i<numStore; ++i){
		cin >> storeCost[i];
	}
	for(int i=0; i<numStore; ++i){
		cin >> price[i];
	}
	for(int i=0; i<numCenter; ++i){
		cin >> centerCost[i];
	}
	for(int i=0; i<numCenter; ++i){
		cin >> centerV[i];
	}

}
