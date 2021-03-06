#include "bubbleSort.hpp"
#include <iostream>
#include <string>
#include <sstream>

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
void printArr( int arr[], int size)
{
	std::cout << " Sorted array: \n ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}
// function to sort an array using bubble sort.
void sorting(int arr[], int size, int a)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (0 == a) {
				if (arr[j] > arr[j+1]) {
				swap(arr[j],arr[j+1]);
				}
			} else if (1 == a) {
				if (arr[j] < arr[j+1]) {
				swap(arr[j],arr[j+1]);
				}
			}
		}
    }
}
