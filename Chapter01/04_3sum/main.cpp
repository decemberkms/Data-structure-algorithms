#include <iostream>
#include <vector>


int threeSum(std::vector<int> vec){
    int N = vec.size();
    int count = 0;
    for (int i = 0; i < N; ++i){
        for (int j = i + 1; j < N; ++j){
            for (int k = j + 1; k < N; k++){
                if (vec.at(i) + vec.at(j) + vec.at(k) == 0)
                    count++;
            }
        }

    }
    return count;
}

int main(){
    std::vector<int> my_vec {10,-10,20,-20,30,-30,100,-40,-50};

    std::cout << threeSum(my_vec) << std::endl;


    return 0;
}