#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	
	int arr[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	
	while(k--)
	{
		for(int i = 0; i < n; i++){
			
			int tempValue = -1;
			
			for(int j = m-1; j >= 0; j--){
				if(j == m-1){
					tempValue = arr[i][j];
					arr[i][j] = arr[i][j-1];
				}else if(j == 0){
					arr[i][j] = tempValue;
				}else{
					arr[i][j] = arr[i][j-1];
				}
				
					
			}
		}
	}
		
	
	
	//print output rotate k matrix
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
