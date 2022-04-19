#include <stdio.h>
#include <stdlib.h>

void swap_func(int *a,int *b) {
    int tem = 0;
    tem = *a;
    *a = *b;
    *b = tem;
}
void swapArray(int *source,int *dest,int size) {
    for(int i = 0;i<size;i++) {
        swap_func(&source[i],&dest[i]);
    }
}
void printArray(int *arr,int size) {
    for(int i=0;i<size;i++) {
        if(i == size-1) {
            printf("%d",arr[i]);
        }
        else{
            printf("%d,",arr[i]);
        }
    }
    printf("]\n");
}

char* copy_string(char* s) {
    int n = 0;
    char *tem = s;
    while(*tem!=0) {
        n++;
        tem++;
    }
    //printf("%d",n);
    char *ptr = (char*)calloc(n+1,sizeof(char));
    for(int i = 0;i<n+1;i++) {
        ptr[i] = s[i];
    }
    return ptr;
}
int main()
{
    int n = 1,m = 2;
    swap_func(&n,&m);
    printf("No.1 ----------------\n");
    printf("after swap, n  = %d, m = %d\n",n,m);
    printf("No.2 ----------------\n");
    int size = 10;
    int source[10] = {0,9,8,7,6,5,4,3,2,1};
    int  dest[10] = {10,20,30,40,50,60,70,80,90,100};
    swapArray(source,dest,size);
    printf("after swap array, source arrey = [");
    printArray(source,size);
    printf("after swap array, dest arrey = [");
    printArray(dest,size);
    
    
    printf("No.3 ----------------\n");
    
    char str[] = "IU!IU!";
    char* cp_str = copy_string(str);
    printf("copy string = %s\n",cp_str);
    free(cp_str);

    return 0;
}
