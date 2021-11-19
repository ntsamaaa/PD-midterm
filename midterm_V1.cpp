#include <bits/stdc++.h>
using namespace std;

int numCenter = 0, numStore = 0, shippingRate = 0, s = 0;
int pCenter[50][2], pStore[1000][2], demand[1000]={0}, storeCost[1000]={0}, price[1000]={0}, centerCost[50]={0}, centerV[50]={0};
int pre_1[2][1001], sol_1[1000][50];
long long int profit1 = 0;
bool opStore[1000]={0}, opCenter[50]={0};

void f1();
void readInput();
void initialize(int arr[][50], int n, int m);
void print(int a);
int nearestCenter(int a);

int main(){
	readInput();
	initialize(sol_1, numStore, numCenter);
	f1();
	print(1);
	return 0;
}

void print(int a){
	if(a==1){
		//printf("--profit = %lld\n", profit1);
		for(int i=0; i<2; ++i){
			cout << pre_1[i][0];
			for(int j=1; j<=pre_1[i][0]; ++j){
				printf(" %d", pre_1[i][j]);
			}
			cout << endl;
		}
		for(int i=0; i<numStore; ++i){
			cout << sol_1[i][0];
			for(int j=1; j<numCenter; ++j){
				printf(" %d", sol_1[i][j]);
			}
			cout << endl;
		}
	}
}
int nearestCenter(int a){
	int x = pStore[a][0], y = pStore[a][1];
	long long int dist = 1000000000000;
	int ans = 0;
	for(int i=0; i<numCenter; ++i){
		long long int dis = abs(x-pCenter[i][0])+abs(y-pCenter[i][1]);
		if(dis < dist){
			dist = dis;
			ans = i;
		}
	}
	return ans;
}
void f1(){
	int** arr = new int*[numCenter];
	for(int i=0; i<numCenter; ++i){
		arr[i] = new int[numStore];
		for(int j=0; j<numStore; ++j){
			arr[i][j] = 0;
		}
	}
	for(int i=0; i<numStore; ++i){
		int nearest = nearestCenter(i);
		int dis = abs(pStore[i][0]-pCenter[nearest][0])+abs(pStore[i][1]-pCenter[nearest][1]);
		int amount = min(centerV[nearest], demand[i]);
		int totalCost = dis*shippingRate*amount+storeCost[i], totalIncome = amount*price[i], totalProfit = totalIncome-totalCost;
		if(totalProfit > 0){
			opStore[i] = 1;
			sol_1[i][nearest] = amount;
			centerV[nearest] -= amount;
			arr[nearest][i] = totalProfit;
		}
	}
	for(int i=0; i<numCenter; ++i){
		int sum = 0;
		for(int j=0; j<numStore; ++j){
			sum+=arr[i][j];
		}
		if(sum < centerCost[i]){
			for(int j=0; j<numStore; ++j){
				if(arr[i][j]>0){
					opStore[j]=0;
					sol_1[j][i] = 0;
				}
			}
		}
		else{
			profit1+=(sum-centerCost[i]);
			opCenter[i] = 1;
		}
	}
	pre_1[0][0]=0;
	pre_1[1][0]=0;
	for(int i=0; i<numCenter; ++i){
		if(opCenter[i]){
			pre_1[0][0]++;
			pre_1[0][pre_1[0][0]] = i+1;
		}
	}
	for(int i=0; i<numStore; ++i){
		if(opStore[i]){
			pre_1[1][0]++;
			pre_1[1][pre_1[1][0]] = i+1;
		}
	}
	for(int i=0; i<numCenter; ++i){
		delete [] arr[i];
	}
	delete [] arr;
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
void initialize(int arr[][50], int n, int m){
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			arr[i][j] = 0;
		}
	}
}
