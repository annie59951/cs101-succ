#include <stdio.h>
FILE* fp;
void rec_dec(char* s) {
    if (*s=='\0') return;
   printf("%c,",*s);
   rec_dec(s+1);
    }
    
int count=0;

int hanoi(int layer, char A, char B, char C) {
    if(layer == 1) {
        fprintf(fp,"Move disk %d from %c to %c\n",count+1, A, C);
        count++;
    }
    else {
        hanoi(layer-1, A, C, B);//把上面的搬走
        hanoi(1, A, B, C);//搬走底部
        hanoi(layer-1, B, A, C);//把該在上面的搬回來
    }
    return count;
}    

int multiplication(int i, int j){
    if ((i == 9)&&(j==10)) return 0;
    if (j == 10) {
        ++i;
        j = 1;
        printf("\n");
    }
        printf("%d*%d=%d\t", i, j, i*j);
        multiplication(i, j+1);
}

int main()
{
    char A,B,C;
    char s[] = "1234567890";
    rec_dec(s);
    printf("\nfunc#1----------------------------------------------------------------\n");
    fp = fopen("hanoi.txt","w+");
    hanoi(16,'A','B','C');
    printf("\nfunc#2------請見hanoi.txt---------------------------------------------\n");
    multiplication(1,1);
    printf("\nfunc#3----------------------------------------------------------------\n");
    return 0;
}
