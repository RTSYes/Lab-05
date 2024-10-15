#include <iostream>
#include "StringData.h"

int binary_search(std::vector<std::string> container, std::string element) {
    int low = 0;
    int high = container.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (container[mid] == element) {
            return mid;
        } else if (container[mid] < element) {
            low = mid + 1;
        } else if (container[mid] > element) {
            high = mid - 1;
        }
    }
    return -1;

}

int linear_search(std::vector<std::string> container, std::string element) {
    int x = 0;
    while(x < container.size()){
        if(container[x] == element) {
            return x;
        }
        x++;
    }
    return -1;
}

/*int actually_record_time_please(std::vector<std::string> container, std::string element) {
    auto start1 = std::chrono::steady_clock::now();
    int linear = linear_search(container, "aaaaa");
    auto end1 = std::chrono::steady_clock::now();
    auto timing1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1- start1);
    std::cout << linear << "timel: " << timing1.count() << std::endl;
    return 0;

}
*/

int main() {
    std::string input;
    std::vector<std::string> stringData = getStringData();
    std::cout << "Enter string to search for: " << std::endl;
    std::cin >> input;

    //timing linear search
    auto start1 = std::chrono::steady_clock::now();
    int linear = linear_search(stringData, input);
    auto end1 = std::chrono::steady_clock::now();
    auto timing1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1- start1);
    std::cout << "Linear Index: " << linear << " Time: " << timing1 << std::endl;

    //actually_record_time_please(stringData, "sdajf");

    //timing binary search
    auto start2 = std::chrono::steady_clock::now();
    int binary = binary_search(stringData, input);
    auto end2 = std::chrono::steady_clock::now();
    auto timing2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
    std::cout << "Binary Index: " << binary << " Time: " << timing2 << std::endl;
    return 0;
}