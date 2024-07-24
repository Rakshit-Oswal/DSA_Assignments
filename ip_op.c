//given an input array like
//2, 2, 3, 4
//that after some operations has output
//1
//write a program for the same


#include <stdio.h>

int computeAPSum(int n){
	return (((n)*(n + 1)) / 2);
}

int reduceArrayElementByOne(int arr[], int size){
	int sum = 0;
	for(int i = 0; i < size; i++){
		arr[i] -= 1;
		sum += arr[i];
	}
	return sum;
}
int main(){
	int arr1[] = {2, 2, 3, 4},
	    arr2[] = {1, 3, 2, 5, 4, 9},
	    arr3[] = {1, 5, 3, 4, 6, 2, 12};

	int sum1 = computeAPSum(sizeof(arr1)/sizeof(arr1[0]) - 1),
	    sum2 = computeAPSum(sizeof(arr2)/sizeof(arr2[0]) - 1),
	    sum3 = computeAPSum(sizeof(arr3)/sizeof(arr3[0]) - 1);

	int chksum1 = reduceArrayElementByOne(arr1,sizeof(arr1)/sizeof(arr1[0])
),
 	    chksum2 = reduceArrayElementByOne(arr2,sizeof(arr2)/sizeof(arr2[0])
),
	    chksum3 = reduceArrayElementByOne(arr3,sizeof(arr3)/sizeof(arr3[0])
);

	printf("%d\n%d\n%d", chksum1 - sum1, chksum2 - sum2, chksum3 - sum3);
	return 0;
}
