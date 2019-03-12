#include <iostream>
#include <string>
#include <sstream>
#include "mergeSort.hpp"

void is_number(std::string& s, bool& fl, int i)
{
        for (; i < s.size(); ++i) {
            if(s[i] < '0' || s[i] > '9') {
                std::cout << "Error please input integer number ... " << std::endl;
                fl = true;
                break;
            }
        }
}
int get_int(int k)
{
    bool fl = false;
    int result = 0;
    std::string s( "" );
    do {
        getline(std::cin , s);
        fl = false;
        if (0 == s.size()) {
            std::cout <<"Error, invalid input" <<std::endl;
            fl = true;
        } else {
            if (0 == k) {
                if (s[0] == '-') {
                    is_number(s,fl,1);
                } else {
                    is_number(s,fl,0);
                }
            } else if (1 == k) {
                is_number(s,fl,0);
            }
        }
    } while(fl);
    std::stringstream str_int(s);
    str_int >> result;
    return result;
}
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
// Function to print array.
void printArr(int arr[], int size)
{
	std::cout << "Sorted arr: \n ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}
//function to merge the two half into a sorted dat
void merge(int arr[], int low, int high, int midl, int a)
{
    int i = low;
    int j = midl + 1;
    int k = 0;
    int arr1[high - low + 1];
    while (i <= midl && j <= high) {
        if (0 == a) {
            if (arr[i] < arr[j]) {
                arr1[k] = arr[i];
                k++;
                i++;
            } else {
                arr1[k] = arr[j];
                k++;
                j++;
            }
        } else if (1 == a) {
            if (arr[i] > arr[j]) {
                arr1[k] = arr[i];
                k++;
                i++;
            } else {
                arr1[k] = arr[j];
                k++;
                j++;
            }
        }
    }
    while (i <= midl) {
        arr1[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        arr1[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++) {
        arr[i] = arr1[i - low];
    }
}
//function to split array into two parts.
void sorting(int arr[], int low, int high,int a)
{
    int midl = 0;
    if (low < high) {
        midl = (low + high) / 2;
        sorting(arr, low, midl,a);
        sorting(arr, midl+1, high,a);
        merge(arr,low,high,midl,a);
    }
}



    
