#include <iostream>
#include <vector>
#include <string>
#include "StringData.h"



int linear_search(const std::vector<std::string>& container, std::string element) {
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element){
		return i;
	}
    }

    return -1;
}

int binary_search(const std::vector<std::string>& container, std::string element) {
	int left = 0;
	int right = container.size()-1;
	int mid = 0;

	while (left <= right){
		
		mid = (right + left) / 2;

		if (container[mid] == element){
			return mid;
		}

		else if (container[mid] > element){
			left = mid + 1;
		}

		else if (container[mid] < element){
			right = mid - 1;
		}
	}

	return -1;

}

int main() {

	std::cout << "loading data:..." << std::endl;
	std::vector<std::string> string_data = getStringData();
	
	std::cout << "Begin testing:" << std::endl;

	long start = systemTimeNanoseconds();
	linear_search(string_data, "not_here");
	long end = systemTimeNanoseconds();
	std::cout << "Linear Search: not_here: " << end - start << std::endl;

	start = systemTimeNanoseconds();
	binary_search(string_data, "not_here");
	end = systemTimeNanoseconds();
	std::cout << "Binary Search: not_here: " << end - start << std::endl;

	start = systemTimeNanoseconds();
	linear_search(string_data, "mzzzz");
	end = systemTimeNanoseconds();
	std::cout << "Linear Search: mzzzz: " << end - start << std::endl;

	start = systemTimeNanoseconds();
	binary_search(string_data, "mzzzz");
	end = systemTimeNanoseconds();
	std::cout << "Binary Search: mzzzz: " << end - start << std::endl;

	start = systemTimeNanoseconds();
	linear_search(string_data, "aaaaa");
	end = systemTimeNanoseconds();
	std::cout << "Linear Search: aaaaa: " << end - start << std::endl;

	start = systemTimeNanoseconds();
	binary_search(string_data, "aaaaa");
	end = systemTimeNanoseconds();
	std::cout << "Binary Search: aaaaa: " << end - start << std::endl;

	return 1;
}
