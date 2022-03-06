#include <iostream>
#include <vector>
// #include <iomanip>

class QuickUnion {
private:
    std::vector<int> id;
    
    int root(int i){
    while (i != id[i])
        i = id[i];
        return i;   
    }

public:
    QuickUnion(){}
    QuickUnion(int N){
        for (int i = 0; i < N; ++i)
            id.push_back(i);
    }

    ~QuickUnion(){
        std::cout << "ID has been destroyed" << std::endl;
    }

    void print_id(){
        std::cout << "[ ";
        for (auto &ele:id)
            std::cout << ele << " ";
        std::cout << "]" << std::endl;
    }

    bool connected(int q, int p){
        return root(p) == root(q);
    }

    void union_points(int p, int q){
        int i = root(p);
        int j = root(q);
        id[i] = j;    
    }

}; 

int main(){
    int vector_length;
    
    std::cout << "Type the vector length: " ;
    std::cin >> vector_length;

    QuickUnion my_obj1{vector_length};
    my_obj1.print_id();
    
    my_obj1.union_points(4,3);
    my_obj1.union_points(3,8);
    my_obj1.union_points(6,5);
    my_obj1.union_points(9,4);
    my_obj1.union_points(2,1);
    my_obj1.print_id();
    std::cout << std::boolalpha;
    std::cout << "8 and 9: " << my_obj1.connected(8,9) << std::endl;
    std::cout << "5 and 4: " << my_obj1.connected(5,4) << std::endl;
    my_obj1.union_points(5,0);
    my_obj1.union_points(7,2);
    my_obj1.union_points(6,1);
    my_obj1.union_points(2,1);
    my_obj1.union_points(7,3);
    my_obj1.print_id();
    // std::cout << "Are they connected?\n";
    
    // std::cout << "0 and 1: " << my_obj1.connected(0,1) << std::endl;
    // std::cout << std::endl;

    // std::cout << "Connect 0 and 1";
    // my_obj1.union_points(0,1);
    // std::cout << "0 and 1: " << my_obj1.connected(0,1) << std::endl;
    // my_obj1.print_id();
    

    return 0;
}