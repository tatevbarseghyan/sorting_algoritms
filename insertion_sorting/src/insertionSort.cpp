#include <iostream>
#include <string>
#include <sstream>
#include "insertionSort.hpp"

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
//function to sort an array using insertion sort.
void sorting(int arr[], int size, int a)
{
	int currentElement = 0;
	int j = 0;
	for (int i  = 1; i < size; i++) {
		currentElement = arr[i];
		j = i - 1;
		if (a == 0) {
			while (j >= 0 && arr[j] > currentElement) {
				arr[j + 1] = arr[j];
				j--;
			}
		} else {
			while (j >= 0 && arr[j] <  currentElement) {
				arr[j + 1] = arr[j];
				j--;
			}
		}
		arr[j + 1] = currentElement;
	}
}
// Function to print array.
void printArr( int arr[], int size)
{
	std::cout << "Sorted arr: \n ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ' ';
	}
    std::cout << std::endl;
}
