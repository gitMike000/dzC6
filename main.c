#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Task 1

#define XLEN 4
#define YLEN 3

int** initArray(int** array,const int row, const int col) {
 array=(int**) calloc(sizeof(int*),row);
 for (int i=0;i<row;++i) {
  *(array+i)=(int*) calloc(sizeof(int), col);
 }
 return array;
}

void printArray(int **array,const int row, const int col) {
 for (int i=0;i<row;++i) {
     for (int j=0;j<col;++j) {
         printf("[%4d]", *((*(array+i))+j));
     }
     printf("\n");
 }
}

void swap(int *a,int *b) {
    int t=*a;
    *a=*b;
    *b=t;
}

void coord(int* x, int* y,int n) {
 *y=(int)(n/XLEN);
 *x=n%XLEN;
}

void bubbleSort(int** arr,int len) {
 int *n1,*n2, *temp;
 int x,y;
 for (int i=0;i<len;++i) {
    for (int j=0;j<len-1;++j) {
          coord(&x,&y,j);
          n1=(arr[y]+x);
          coord(&x,&y,j+1);
          n2=((*(arr+y))+x);
          if (*n1>*n2) {
              *temp=*n1;
              *n1=*n2;
              *n2=*temp;
          }
    }
 }
}

// Task 2
double f(double t)
{
    return sqrt(fabs(t)) + 5 * pow(t, 3);
}

void sort(double* a,int n){
    double temp;
    for (int i=0;i< (int)(n/2);i++) {
     temp=a[i];
     a[i]=a[n-i-1];
     a[n-i-1]=temp;
    }
}

int main(void)
{
// Task 1
    printf("Task 1\n");
    printf("\n");
    int m[YLEN][XLEN]= {
        {1,9,2,11},
        {5,7,6,10},
        {4,3,8,12}
    };
    int** mu=initArray(mu,YLEN,XLEN);
    for (int i=0;i<YLEN*XLEN;i++) mu[i]=m[i];
    printArray(mu,YLEN,XLEN);
    bubbleSort(mu,YLEN*XLEN);
    printf("\n");
    printArray(mu,YLEN,XLEN);
    free(mu);
    printf("\n");

// Task 2
    printf("Task 2\n");
    double A[11], y;
    for (int i = 0; i < 11; i++) {
        printf("Enter a[%d]=", i);
        scanf("%lf", &A[i]);
    }
    printf("\n");  
    // Файл с кодом на языке С, содержащим функцию main и две функции, соответствующие сортировке и алгоритму Трабба-Прадо-Кнута
    // Понимается с двойным смыслом. Поэтому так, но можно было и через for (int i = 11; i >= 1; i--)
    sort(&A,sizeof(A) / sizeof(double));
    for (int i = 0; i < 11; i++) {
        y = f(A[i]);
        if (y > 400)
            printf("A[%d]=%.16g TPK=TOO LARGE\n", i, A[i]);
        else
            printf("A[%d]=%.16g  TPK=%.16g\n", i, A[i], y);
    }
    printf("\n");
}
