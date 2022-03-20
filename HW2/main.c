#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int lotto,inputid;
int count;
int addid,addsalary;
char addname[32];

FILE* fp;
FILE* fp_bin;
FILE* fp_rec;
FILE* fp_opid;
int count = 0;
int flag = 0; 
int ask_imfor() {
    flag = 0;
    printf("請輸入operator id:");
    scanf("%d",&inputid);
    printf("請問要購買幾組樂透(請輸入1~5的數字):");
    scanf("%d",&lotto);
    
    if(inputid == 0) {
        flag = 1;
        get_new_emp_records();
    }
    
}
void now() {
    time_t curtime;
    time(&curtime);
    fprintf(fp,"%s",ctime(&curtime));
}
int ran_num(int lotto) {
    int numbers[6];
    int c;
    srand(time(NULL));
    for(int i=0;i<lotto;i++) {
        fprintf(fp,"[%d]:",i+1);
        
        for(int j=0;j<6;j++) {
            int temp = rand()%69 + 1;
            numbers[j] = temp;  
        } 
        for(int z=5; z>=1; z--){
            for(int x=0; x<z; x++){
                if(numbers[x+1]<numbers[x]){
                    c=numbers[x+1];
                    numbers[x+1]=numbers[x];
                    numbers[x]=c;
                }
            }
        }
    for(int q = 0; q<6; q++){
        fprintf(fp, " %0*d",2,numbers[q]);
    }
    fprintf(fp," %0*d\n",2,rand()%10 + 1); 
    }   
}

typedef struct lotto_records {
     int lotto_no;
     int lotto_recipt;
     char lotto_date[32];
     char lotto_time[32];
     int emp_id;
}lotto_records_t;
lotto_records_t lo_1;

void def_lotto_record() {
    char datebuff[32];
    char timebuff[32];
    lo_1.lotto_no = count;
    int tot = 0;
    tot = lotto+tot;
    lo_1.lotto_recipt = tot*1.1*50;
    lo_1.emp_id = addid;
    time_t now = time(0);
    strftime(datebuff,100,"%Y%m%d",localtime(&now));
    strftime(timebuff,100,"%H:%M:%S",localtime(&now));
    
    strcpy(lo_1.lotto_date[32],datebuff);
    strcpy(lo_1.lotto_time[32],timebuff);  
   
    
}
    
    
typedef struct emp_records {
    char newname[32];
    int salary;
    int newid;
    
}emp_records;
emp_records emp_1;




void get_new_emp_records() {
    printf("請輸入要新增的操作人員ID:");
    scanf("%d",&addid);
    printf("請輸入要新增的操作人員NAME:");
    scanf("%d",&addname);
    printf("請輸入要新增的操作人員SALARY:");
    scanf("%d",&addsalary);
    printf("輸入完成!");
    
}
void define_emp_records() {
    strcpy(emp_1.newname[32],addname);
    emp_1.salary = addsalary;
    emp_1.newid = addid;
    
}

int count_num() {
    
    int n;
    
    if((fp_bin = fopen("count_bin","rb+"))==NULL) {
        n = 0;
        fp_bin = fopen("count_bin","wb+");
        fwrite(&n,sizeof(int),1,fp_bin);
        fclose(fp_bin);
    }
    if((fopen("count_bin","rb+"))!=NULL) {
        fread(&n,sizeof(int),1,fp_bin);
        fclose(fp_bin);
        n = n+1;
        fp_bin = fopen("count_bin","wb+");
        fwrite(&n,sizeof(int),1,fp_bin);
        fclose(fp_bin);
        return n;
    }
    
}
void namef(char name[],int count) {
    for(int i = 8;i>=5;i--) {
        name[i] = count%10+'0';
        count/=10;
    }
}


int main()
{
    
    ask_imfor();
    if(flag==1) {
        //新增成員
    fp_opid = fopen("operator_id.bin","ab");
    fwrite(&emp_1,sizeof(emp_1),1,fp_opid);
    fclose(fp_opid);
       
    }
    
    if(flag==0) {
        //購買彩卷
    fp_rec = fopen("records.bin","ab");
    fwrite(&lo_1,sizeof(lo_1),1,fp_rec);
    fclose(fp_rec);
    fp = fopen("lotto.txt","rb+");
    count = 0;
    count = count_num();
    char name[10] = "lotto";
    namef(name,count);
    fp = fopen(name,"w+");
    fprintf(fp,"========lotto649=========\n");
    fprintf(fp,"=========CSIE===========\n");
    fprintf(fp,"====operator id:%05d====\n",inputid);
    now();
    ran_num(lotto);
    for(int i=0;i<5-lotto;i++) {
        fprintf(fp,"[%d]:",lotto+i+1);
        fprintf(fp,"= = = = = = = = = = =\n");
    }
    fprintf(fp,"==========================\n");
    fprintf(fp,"========no:%0*d ========\n",6,count);
    fclose(fp);
    }
    return 0;
}
