#include <iostream>
#include <vector>
using namespace std;



int merge(int arr[], int temp[], int l, int m, int r);
int mergeSort(int arr[], int temp[], int l, int r);
const int mod = 1e9 + 7;

int reverseCount(int arr[], int array_size) {
    int temp[array_size];
    return mergeSort(arr, temp, 0, array_size - 1)%mod;
}
int mergeSort(int arr[], int temp[], int l, int r){
    int count = 0;
    if(l >= r){
        return 0;
    }
    int mid = l + (r-l)/2;

    count += mergeSort(arr, temp, l, mid);

    count += mergeSort(arr, temp, mid+1, r);

    count += merge(arr, temp, l, mid+1, r);

    return count%mod;

}
int merge(int arr[], int temp[], int l, int m, int r){
    int p1=l, p2=m, p3=l;
    int count=0;
    while(p1<m && p2<=r){
        if (arr[p1] <= arr[p2]){
            temp[p3++] = arr[p1++];
        }

        else {
            temp[p3++] = arr[p2++];
            count += (m - p1);
        }
    }
    while (p1 < m){
        temp[p3++] = arr[p1++];
    }
    while (p2 <= r){
        temp[p3++] = arr[p2++];
    }
    for (int i = l; i <= r; i++){
        arr[i] = temp[i];
    }
    return count%mod;
}
int solve(vector<int> &A) {
    int N= A.size();
    int a[N];
    for(int i=0; i<N; i++){
        a[i] = A[i];
    }

    return reverseCount(a, N);
}


int main ()
{
   vector<int> A = { 10, 3, 8,15 ,6 ,12, 2 ,18, 7 ,1 };
   int a [] = {0};
   cout<< "\n count is " <<   solve(A) << "\n";

  return 0;
}
