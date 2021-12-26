#include <iostream>
#include <vector>
// #include <iomanip>

class QuickUnion {
private:
    std::vector<int> id;
    std::vector<int> sz;
    int count_sz;

    int root(int i){
    while (i != id[i])
        i = id[i];
        return i;   
    }

public:
    QuickUnion(){}
    QuickUnion(int N){
        count_sz = N;
        for (int i = 0; i < N; ++i){
            id.push_back(i);
            sz.push_back(1);
        }
    }

    ~QuickUnion(){
        std::cout << "ID has been destroyed" << std::endl;
    }

    int count(){
        return count_sz;
    }


    bool connected(int q, int p){
        return root(p) == root(q);
    }

    void union_points(int p, int q){
        int i = root(p);
        int j = root(q);
        if (i == j) return;
        if (sz.at(i) < sz.at(j)){
            id.at(i) = j;
            sz.at(j) += sz.at(i);
        } else {
            id.at(j) = i;
            sz.at(i) += sz.at(j);
        }
        count_sz--;
    }

    void print_id(){
        std::cout << "Array itself:" << std::endl;
        std::cout << "[ ";
        for (auto &ele:id)
            std::cout << ele << " ";
        std::cout << "]" << std::endl;
        std::cout << "Size array: " << std::endl;
        std::cout << "[ ";
        for (auto &ele:sz)
            std::cout << ele << " ";
        std::cout << "]" << std::endl;

    }

}; 

int main(){
    int vector_length {10};
    
    // std::cout << "Type the vector length: " ;
    // std::cin >> vector_length;
    std::cout << std::boolalpha;
    QuickUnion my_obj1{vector_length};
    // my_obj1.print_id();
    
    my_obj1.union_points(4,3);
    my_obj1.print_id();
    my_obj1.union_points(3,8);
    my_obj1.print_id();
    my_obj1.union_points(6,5);
    my_obj1.print_id();
    my_obj1.union_points(9,4);
    my_obj1.print_id();
    my_obj1.union_points(2,1);
    my_obj1.print_id();
    
    std::cout << "8 and 9: " << my_obj1.connected(8,9) << std::endl;
    std::cout << "5 and 4: " << my_obj1.connected(5,4) << std::endl;
    

    return 0;
}