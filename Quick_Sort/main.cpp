#include <iostream>

//swap elements
void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}	

//rearrange array(find the partition point)
int partition(int* arr, int low, int high){

	//the rightmost element as pivot
	int pivot = arr[high];
	//pointer for greater element
	int i = (low - 1);

	//traverse each elements of array , compare them with the pivot
	for(int j = low; j < high; ++j){
		if(arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quickSort(int* arr, int low, int high){
	if(low < high){
		//find the pivot
		//elements smaller than the pivot are on the left side
		//elements bigger than the pivot are on the right side
		int p = partition(arr, low, high);

		//recursive call on the left of pivot
		quickSort(arr, low, p - 1);

		//recursive call on the right of pivot
		quickSort(arr, p + 1, high);
	}
}

void printArray(int* arr, int size){
	for(int i = 0; i < size; ++i){
		std::cout << arr[i] << " ";
	}
}
int main(){
	int array[] = {3, 4, 7, 10, 9, 1, 5};
	int size = sizeof(array)/sizeof(array[0]);

	std::cout << "Unsorted array: ";
	printArray(array, size);
	std::cout << std::endl;

	std::cout << "Sorted array: ";
	quickSort(array, 0, size - 1);
	printArray(array, size);
	std::cout << std::endl;
}
