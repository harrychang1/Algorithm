#include <bits/stdc++.h>

using namespace std;

//Time Complexity Merge Sort O(n Log n)

void merge(int A[] , int start , int mid , int end)
{
	int i,j,k;
	int n1 = mid - start + 1;
	int n2 = end - mid;
	
	//buat temporary array
	int L[n1] , R[n2];
	
	//copy data temp array ke L[] dan R[]
	for(i = 0; i < n1; i++)
		L[i] = A[start + i];
	for(j = 0; j < n2; j++)
		R[j] = A[mid + 1 + j];
		
	//merge temp array ke A[start...end]
	i = 0;
	j = 0;
	k = start;
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++; 
		}else{
			A[k] = R[j];
			j++;
		}
		
		k++;
	}
	
	//copy sisa data yang ada pada L[] kalau ada
	while(i < n1){
		A[k] = L[i];
		i++;
		k++;
	}
	
	//copy sisa data yang ada pada R[] kalau ada 
	while(j < n2){
		A[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int A[], int start, int end)
{
	if(start < end){
		int mid = (start+end)/2;
		mergeSort(A,start,mid);
		mergeSort(A,mid+1,end);
		merge(A,start,mid,end);	
	}
}

int main()
{	
	int Arr[] = {12,11,13,5,6,7};
	int len = sizeof(Arr) / sizeof(Arr[0]);
	mergeSort(Arr,0,len-1);
	
	//print hasil array yang sudah di merge sort
	for(int i = 0; i < len; i++)
		printf("%d ",Arr[i]);
	
	return 0;
}
