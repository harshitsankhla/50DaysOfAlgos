#include <iostream>

// n^2 time complexity
void bubbleSort(int*, int);
void insertionSort(int*, int);
void selectionSort(int*, int);

int main()
{
    int n;
    std::cout<<"Enter the number of elements - ";
    std::cin>>n;

    int arr[n];
    std::cout<<"\nEnter array elements (space separated) to sort - ";
    for(int i=0; i<n; i++) {
        std::cin>>arr[i];
    }
        
    std::cout<<"\nWhich Sorting Algorithm to Use - ";
    std::cout<<"\n1. Bubble Sort";
    std::cout<<"\n2. Insertion Sort";
    std::cout<<"\n3. Selection Sort\n";

    int choice;
    std::cin>>choice;

    switch (choice) {
        case 1:     bubbleSort(arr, n);
                    break;

        case 2:     insertionSort(arr, n);
                    break;

        case 3:     selectionSort(arr, n);
                    break;

        default:    std::cout<<"Invalid Choice!";
                    break;
    }

    return 0;
}

void bubbleSort(int* arr, int n)
{
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

        std::cout<<"\nArray after "<<i+1<<" pass - ";
        for(int k=0; k<n; k++) {
            std::cout<<arr[k]<<" ";
        }
    }
    std::cout<<std::endl;
}

void insertionSort(int* arr, int n)
{
    for (int i=0; i<n; i++) {
        int temp = arr[i];
        int j=i;

        while (j>0 && arr[j-1]>temp) {
            arr[j] = arr[j-1];
            j = j-1;
        }
        arr[j] = temp;

        std::cout<<"\nArray after "<<i+1<<" pass - ";
        for (int k=0; k<n; k++) {
            std::cout<<arr[k]<<" ";
        }
    }
    std::cout<<std::endl;
}

void selectionSort(int* arr, int n)
{
    for (int i=0; i<n-1; i++) {
        int min = i;
        for (int j=i; j<n; j++) {
            if (arr[j]<arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

        std::cout<<"\nArray after "<<i+1<<" pass - ";
        for(int k=0; k<n; k++) {
            std::cout<<arr[k]<<" ";
        }
    }
    std::cout<<std::endl;
}
