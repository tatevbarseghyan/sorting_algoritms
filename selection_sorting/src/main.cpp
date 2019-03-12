#include <iostream>
#include "selectionSort.hpp"
int main()
{
    int n = 0;
    int sortBy = 2;
    std::cout << "Please input array length " << std::endl;
    n = get_int(1);
    while (0 == n) {
        std::cout <<" Array length can't be zero, please input positive number " << std::endl;
        n = get_int(1);
    }
    int arr[n] = {};
    std::cout << "Input array's elements " << std::endl;
    for (int i = 0; i < n; i++) {
        arr[i] = get_int(0);
    }
    std::cout << " Enter '0' if you want to sort by ascending order or '1' by decending order  ";
    while (sortBy != 0 || sortBy != 1) {
        sortBy = get_int(1);
        if (sortBy == 0 || sortBy == 1) {
            sorting(arr,n,sortBy);
            printArr(arr,n);
            break;
        } else {
            std::cout << "Error - please input '0' or '1' " << std::endl;
        }
    }
}


