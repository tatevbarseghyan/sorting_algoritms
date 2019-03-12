#include <iostream>
#include <string>
#include <sstream>
#include "quickSort.hpp"

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
int get_int(int k) {
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
// Function  takes last element as lastElement, places all smaller to left of lastElement and all greater elemets to right.
int partition(int arr[], int start, int end, int a)
{
    int lastElement = arr[end];
    int j = start - 1;
    for (int i = start; i <= end - 1; i++) {
        if (0 == a){
            if (arr[i] <= lastElement) {
                j++;
                swap(arr[i],arr[j]);
            }
        } else if (1 == a) {
            if (arr[i] >= lastElement) {
                j++;
                swap(arr[i],arr[j]);
            }
        }
    }
    swap(arr[j+1],arr[end]);
    return (j + 1);
}
//Main function to sort an array using quick sort.
void sorting(int arr[], int start, int end, int a)
{
    if (start < end) {
        int p = partition(arr,start,end,a);
        sorting(arr,start,p - 1,a);
        sorting(arr,p + 1,end,a);
    }
}
