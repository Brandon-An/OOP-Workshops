#include <cstdio>
#include <iostream>

int main (){
    char string[30] = {"12345,,, asdfasdfasdf"};
    char string2[25] = {" "};
    int i;

    sscanf(string, "%d,,,%s", &i, string2);
    std::cout << i;
    std::cout << string2 << std::endl;

    return 0;
}