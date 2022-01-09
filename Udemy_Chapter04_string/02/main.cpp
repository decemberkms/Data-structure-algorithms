#include <iostream>


int main(){

    char s[] = "welcome";
    int i;
    for (i = 0; s[i] != '\0';i++){
        s[i] -= 32;
    }
    std::cout << s << std::endl;

    return 0;
}