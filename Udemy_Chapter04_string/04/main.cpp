#include <iostream>



bool valid_(const char *name){
    for (int i = 0; name[i] != '\0'; ++i){
        if (!(name[i] >= 65 && name[i] <= 90) &&
            !(name[i] >= 97 && name[i] <= 122) &&
            !(name[i] >= 48 && name[i] <= 57)) {
            return 0;
        }        
    }
    return 1;
}



int main(){

    const char *name = "bludasdsa121";

    if (valid_(name)){
        std::cout << "Valid string\n";
    }
    else{
        std::cout << "Invalid string\n";
    }

    const char* pt1 = "I am Min!";

    for (int i = 0; i < 5; ++i){
        puts(pt1++);
    }
    
    return 0;
}