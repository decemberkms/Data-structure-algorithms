#include <iostream>
#include <vector>
// #include <iomanip>

class QuickFind {
private:
    std::vector<int> id;

public:
    QuickFind(int N){
        for (int i = 0; i < N; ++i) {
            id.push_back(i);
        }
    }

    ~QuickFind(){
        std::cout << "ID has been destroyed" << std::endl;
    }

    void print_id(){
        for (auto &ele:id){
            std::cout << ele << std::endl;
        }
    }

    bool connected(int q, int p){
        return id[q] == id[p];
    }

    void union_points(int p, int q){
        int pid = id[p];
        int qid = id[q];
        for (int i = 0; i < id.size(); ++i)
            if (id[i] == pid)
                id[i] = qid;        
    }

}; 

int main(){
    int vector_length;
    
    std::cout << "Type the vector length: " ;
    std::cin >> vector_length;

    QuickFind my_obj1{vector_length};
    my_obj1.print_id();

    std::cout << "Are they connected?\n";
    std::cout << std::boolalpha;
    std::cout << "0 and 1: " << my_obj1.connected(0,1) << std::endl;
    std::cout << std::endl;

    std::cout << "Connect 0 and 1";
    my_obj1.union_points(0,1);
    std::cout << "0 and 1: " << my_obj1.connected(0,1) << std::endl;


    return 0;
}