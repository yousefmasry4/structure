#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct data{
    char fname[8],mname[8],lname[8];
    float salary;
    struct date{
        int day,month,year;
    }dob;
};

void read(struct data arr[],int n);
float avg(struct data arr[],int n);
void print(struct data arr[],int n);
void minmax(struct data arr[],int n,float *a,float *b);
void swap(struct data a[],int max, int man);
void sort(struct data arr[],int n);
void sort_dob(struct data arr[],int n);
void git(struct data arr[],int n,char fn[],char mn[],char ln[]);

int main()
{
    int n;printf("enter the number of employee:");scanf("%d",&n);
    struct data arr[n];
    read(arr,n);
    print(arr,n);
    printf("average=%f",avg(arr,n));
    float a,b;
    minmax(arr,n,&a,&b);
    printf("\nmin=%f    max=%f\n",b,a);
    sort(arr,n);
    puts("----------------------------------------------------------------------------------------");
    print(arr,n);
    sort_dob(arr,n);
    puts("----------------------------------------------------------------------------------------");
    print(arr,n);
    char fn[10],mn[10],ln[10];
    printf("enter the name");scanf("%s %s %s",&fn,&mn,&ln);
    git(arr,n,fn,mn,ln);
    return 0;
}

void git(struct data arr[],int n,char fn[],char mn[],char ln[]){
    for(int i=0;i<n;i++){
        if(strcmp(arr[i].fname,fn)==0 && strcmp(arr[i].mname,mn)==0 && strcmp(arr[i].lname,ln)==0){
            printf("%d\t\t%s %s %s\t\t\t\t%f\t\t\t%d/%d/%d\n",i,arr[i].fname,arr[i].mname,arr[i].lname,arr[i].salary,arr[i].dob.day,arr[i].dob.month,arr[i].dob.year);break;
        }
    }
}

void swap(struct data a[],int max, int man){
    char temp[10];strcpy(temp,a[max].fname);
    strcpy(a[max].fname,a[man].fname);
    strcpy(a[man].fname,temp);
    char atemp[10];strcpy(atemp,a[max].mname);
    strcpy(a[max].mname,a[man].mname);
    strcpy(a[man].mname,atemp);
    char btemp[10];strcpy(btemp,a[max].lname);
    strcpy(a[max].lname,a[man].lname);
    strcpy(a[man].lname,btemp);
    float fbtemp=a[max].salary;
    a[max].salary=a[man].salary;
    a[man].salary=fbtemp;
        float dbtemp=a[max].dob.day;
    a[max].dob.day=a[man].dob.day;
    a[man].dob.day=dbtemp;
        float obtemp=a[max].dob.month;
    a[max].dob.month=a[man].dob.month;
    a[man].dob.month=obtemp;
        float bbtemp=a[max].dob.year;
    a[max].dob.year=a[man].dob.year;
    a[man].dob.year=bbtemp;
}

void sort_dob(struct data arr[],int n){
    for(int i=0;i<n-1;i++){
        int max=i;
        for(int j=i+1;j<n;j++){
            if(arr[max].dob.year < arr[j].dob.year){
                max=j;
            }
            else if(arr[max].dob.year== arr[j].dob.year){
                if(arr[max].dob.month== arr[j].dob.month){
                    if(arr[max].dob.day < arr[j].dob.day){
                        max=j;
                    }
                }
                if(arr[max].dob.month < arr[j].dob.month){
                        max=j;
                }
            }
        }
        swap(arr,max,i);
    }
}

void sort(struct data arr[],int n){
    for(int i=0;i<n-1;i++){
        int max=i;
        for(int j=i+1;j<n;j++){
            if(strcmp(arr[max].fname,arr[j].fname) == -1){
                max=j;
            }
        }
        swap(arr,max,i);
    }
}

void minmax(struct data arr[],int n,float *a,float *b){
    *a=arr[0].salary;
    for(int i=1;i<n;i++){
        if(arr[i].salary > *a){
            *a=arr[0].salary;
        }
    }
    *b=arr[0].salary;
    for(int i=1;i<n;i++){
        if(arr[i].salary < *b){
            *b=arr[i].salary;
        }
    }
}

float avg(struct data arr[],int n){
    float x=0;
    for(int i=0;i<n;i++){
        x+=arr[i].salary;
    }
    return x/n;
}

void print(struct data arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t\t%s %s %s\t\t\t\t%f\t\t\t%d/%d/%d\n",i,arr[i].fname,arr[i].mname,arr[i].lname,arr[i].salary,arr[i].dob.day,arr[i].dob.month,arr[i].dob.year);
    }
}

void read(struct data arr[],int n){
    for(int i=0;i<n;i++){
        printf("\nenter the name :\n");scanf("%s %s %s",arr[i].fname,arr[i].mname,arr[i].lname);
        printf("enter the salary:");scanf("%f",&arr[i].salary);
        printf("enter the date of birth>>>\n");
            printf("enter the day:");scanf("%d",&arr[i].dob.day);
            printf("enter the month:");scanf("%d",&arr[i].dob.month);
            printf("enter the year:");scanf("%d",&arr[i].dob.year);
        system("clear");
        }
}
