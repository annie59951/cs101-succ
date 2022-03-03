#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    time_t curtime;
    time(&curtime);
    FILE* fp;

    fp = fopen("a.txt","w+");
    fprintf(fp , "Wei An ,come to paly, TIME: %s",ctime(&curtime));
    fclose(fp);
    return 0;
}