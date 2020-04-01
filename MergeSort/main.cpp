#include <iostream>
#include <cstdio>
using namespace std;
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m= l+(r-l)/2;

        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}

void printArray(int arr[], int size){
    int i;
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main() {
    int n, T, i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int arr[n+1];
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        mergeSort(arr,0,n-1);
        printArray(arr,n);
    }
    return 0;
}

void merge(int arr[], int l, int m, int r){
    int i = l;
    int j = m+1;
    int tempArr[r-l+1];
    int nextTemp = 0;
    while(i<=m && j<=r){
        if(arr[i]<arr[j]){
            tempArr[nextTemp] = arr[i];
            nextTemp++;
            i++;
        } else {
            tempArr[nextTemp] = arr[j];
            nextTemp++;
            j++;
        }
    }
    while(i<=m){
        tempArr[nextTemp] = arr[i];
        nextTemp++;
        i++;
    }
    while(j<=r){
        tempArr[nextTemp] = arr[j];
        nextTemp++;
        j++;
    }
    for(int k=0;k<(r-l+1);k++){
        arr[l+k] = tempArr[k];
    }
}