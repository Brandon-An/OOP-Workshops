#include <iostream>

void display(int& set1[]);

int main(){
    int set1[10] = {1,2,3,4,5,6,7,8,9,10};
    display((&set1)[]);
    return 0;
}

void display(int& set1[]){
    int i = 0;
    for (i = 0; i < 10; i++){
        std::cout << set1[i] << std::endl;
    }
}