#include "cstring.h"


namespace sdds{

void strCpy(char* des, const char* src){
    
    int i;
    
    for (i = 0; i < 100; i++){
        if (src == nullptr)
            {
                des[0] = 0;
                return;
            }
        if(src[i] == '\0'){
		des[i] = '\0';
            break;
	}
        des[i] = src[i];
    }
}

void strnCpy(char* des, const char* src, int len){
    int i;
    for (i = 0; i < len; i++){
        if (src == nullptr)
            {
                des[0] = 0;
                return;
            }
        if(src[i] == '\0'){
            des[i] = src[i];
            break;
        }
        des[i] = src[i];
    }
}

int strCmp(const char* s1, const char* s2){
    int i;

    for (i = 0; i < 100; i++){

        if( s1[i] == '\0' || s2[i] == '\0'){
            break;
        }

        if(int(s1[i]) > int(s2[i])){
            return 1;
        }

        if(int(s1[i]) < int(s2[i])){
            return -1;
        }
    
    }

    return 0;

}

int strnCmp(const char* s1, const char* s2, int len){
    int i;
    
    for (i = 0; i < len; i++){

        if(s1[i] == '\0' || s2[i] == '\0'){
            break;
        }

        if(int(s1[i]) > int(s2[i])){
            return 1;
        }

        if(int(s1[i]) < int(s2[i])){
            return -1;
        }
    
    }

    return 0;
}

int strLen(const char* s){
    int i;
    int count = 0;

    for(i = 0; i < 100; i++){
        if(s[i] != '\0')
            count++;
        else
            return count;
    }
    return 0;
}

const char* strStr(const char* str1, const char* str2){
    int i;
    int same;
	
    for (i = 0; i < 100; i++){
        same = strCmp(&str1[i], str2);
            if (same == 0 && str1[i] != '\0')
                return &str1[i];


    } 
    for (i =0; i<100; i++) {
        same = strCmp(&str1[i], str2);
        if (same == -1 || same == 1)
        return nullptr;
    }

    return nullptr; 
}

void strCat(char* des, const char* src){
    int i = 0;
    int j = 0;
    while(true){
        if (des[i] == '\0'){
            for (j = 0; j < 10; j++){
                des[i+j] = src[j];
                if (src[j] == '\0'){
                    return;
                }
            }
        }
        i++;
    }
}



// int main(){
//     char str1[6] = "Hello";
//     char str2[6] = "World";
    
//     strStr(str1, str2);
    
//     return 0;
// }

}
