#include <stdio.h>
#include <stdlib.h>
#include <time.h>
FILE* fp;
void NowTime() {
    
    
    time_t curtime;
    time(&curtime);
    fprintf(fp,"%s",ctime(&curtime));
    
}

void HowManyLotto(int *num) {
    
    int a;
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問你要買幾組:");
    scanf("%d",&a);
    printf("%d",a);
    printf("已為您購買的%d組樂透組合輸入至 lotto.txt\n",a);
    *num = a;
    
}

int Num(int *num) {
    
    
    srand(time(0));
    for(int i=0;i<*num;i++) {
        fprintf(fp,"[%d]",i+1);
        for(int j=0;j<6;j++) {
            fprintf(fp," %0*d",2,rand()%69+1); 
        }
    fprintf(fp," %0*d\n",2,rand()%10+1); 
    }
    
}

            
int main()
{
   
    fp = fopen("Lotto.txt","w+");
    int num = 0;
    HowManyLotto(&num);
    fprintf(fp,"========lotto649========\n");
    NowTime();
    Num(&num);
    for(int i=0;i<5-num;i++) {
        fprintf(fp," == == == == == == == ==\n");
    }   
    
    fprintf(fp,"========================\n");
    
    
    fclose(fp);
    return 0;
}
