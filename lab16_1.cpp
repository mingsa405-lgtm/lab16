#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}
void showData(double *a,int M, int N){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << *(a+i);
        if((i+1)%N==0) cout << endl;
        else cout << " ";
    }
}
void randData(double *a,int M,int N){
    for(int i = 0; i < N*M; i++){
          a[i]= (rand()%101)/100.0;
    }
}
void findColSum(const double *a, double *b, int m, int n){
    double sum;

    for(int i = 0; i < n; i++){     
        sum = 0;
        for(int j = 0; j < m; j++){  
            sum += a[j*n + i];
        }
        b[i] = sum;                  
    }
}
void findRowSum(const double *a,double *b,int m,int n){
    double sum=0;
    int r=0;
    for(int i=0;i<m*n;i++){
        sum=sum+a[i];
        if((i+1)%n==0){b[r]=sum;
            sum=0;
            r+=1;
        }
       
        
        
    }
    }

