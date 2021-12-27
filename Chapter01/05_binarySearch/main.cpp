#include <iostream>
#include <vector>

int binarySearch(std::vector<int> vec, int key){
    int lo =0, hi = vec.size() - 1;
    while (lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if (key < vec.at(mid)) hi = mid - 1;
        else if (key > vec.at(mid)) lo = mid + 1;
        else return mid;
    }
    return -1;
}

int main() {

    std::vector<int> myVector {1,2,3,4,5,6,7,8,9};

    std::cout << "Here is the answer: ";
    std::cout << binarySearch(myVector, 3) << std::endl;

    return 0;
}