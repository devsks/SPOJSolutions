#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
bool next_permutation(int *array, size_t length) {
	size_t i, j;
	int temp;
	
	// Find non-increasing suffix
	if (length == 0)
		return false;
	i = length - 1;
	while (i > 0 && array[i - 1] >= array[i])
		i--;
	if (i == 0)
		return false;
	
	// Find successor to pivot
	j = length - 1;
	while (array[j] <= array[i - 1])
		j--;
	temp = array[i - 1];
	array[i - 1] = array[j];
	array[j] = temp;
	
	// Reverse suffix
	j = length - 1;
	while (i < j) {
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i++;
		j--;
	}
	return true;
} 
int main(){
	int num, arr[12345], i = 0, len, div;
	scanf("%i%n", &num,&len);
	div = pow(10, len-1);
	while(num > 0){
		arr[i++] = num/div;
		num %=div;
		div/=10;
	}
	for(int i = 0; i < len; i++){
		printf("%i",arr[i]);
	}
	return 0;
} 

