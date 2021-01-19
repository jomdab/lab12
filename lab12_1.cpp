#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}
void stat(const double a[],int N,double B[]){
    double sum=0,sum2=0,suml=0,sumh=0,max,min=0;
    max=a[0];min=a[0];
    for (int i = 0; i < N; i++)
    {
        sum+=a[i];suml+=log10(a[i]);sumh+=1/a[i];
        if (a[i]>max)max=a[i];
        if (a[i]<min)min=a[i];
    }
    B[0]=sum/N;
    B[2]=pow(10,suml/N);
    B[3]=N/sumh;
    B[4]=max;
    B[5]=min;
    for (int i = 0; i < N; i++)
    {
       sum2+=pow(a[i]-B[0],2);
    }
    B[1]=sqrt(sum2/(N));
}
