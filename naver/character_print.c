#include <stdio.h>

int main(){
    int asciiNum;
    for(asciiNum = 33; asciiNum <= 110; asciiNum++) {
        printf("%d -> %c\n", asciiNum, asciiNum);
    }
    return 0;
}