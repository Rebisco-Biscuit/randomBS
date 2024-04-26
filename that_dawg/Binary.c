/* From Exercism, Binary */

#include "binary.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

int convert(const char *input){
    int len = strlen(input);
    int result=0;
    int *newarr = malloc(sizeof(int)*len);

    if(input[0]== 0){
        return -1;
    }
    
    for(int i=0; i<len; i++){
        if(input[i]== 48){
            newarr[i]=0;
        } else if(input [i]==49){
            newarr[i]=1;
        } else {
            return -1;
        }
    }
    int k=len-1;
    for(int i=0; i<len; i++){
        result += (newarr[i]*pow(2,k));
        k--;
    }
    return result;
}
