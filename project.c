
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct student{
    char name[20];
    int id;
    float cgpa;
};

void gotoxy(int x,int y)
{
    COORD CRD;
    CRD.X=x;
    CRD.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

void window()
{
    gotoxy(25,2);
    printf("STUDENT RECORD SYSTEM FOR CFA(DR.CHOWDHURY FARHAN AHMED) SIR");
    gotoxy(25,3);
    printf("LAB SECTION: 19 . LAB INSTRUCTOR: MEHEDI HASAN BIJOY");
    gotoxy(25,4);
    printf("NORTH SOUTH UNIVERSITY, DHAKA, BANGLADESH.");
    gotoxy(25,5);
    printf("-------------------------------------------");
}
void input_student(){

struct student s[100];
    int n;
 printf("Enter Number of Students:");
 scanf("%d",&n);
 FILE *fp;

for(int i=0;i<n;i++){
    printf("\nEnter NAME:");
    scanf("%s",s[i].name);
    fflush(stdin);
    printf("Enter ID:");
    scanf("%d",&s[i].id);
    printf("Enter CGPA:");
    scanf("%f",&s[i].cgpa);

}
fp=fopen("test.txt","w");
fprintf(fp,"%d\n",n);
for(int i=0;i<n;i++){
    fprintf(fp,"%s\n%d\n%.2f\n",s[i].name,s[i].id,s[i].cgpa);
}
fclose(fp);


}

void all_student(){
struct student s[100];
int n;
printf("\nDisplay all the Students:\n\n");
FILE *fp;
fp=fopen("test.txt","r");
fscanf(fp,"%d",&n);
for(int i=0;i<n;i++){
    fscanf(fp,"%s %d %f",s[i].name,&s[i].id,&s[i].cgpa);
}
fclose(fp);
for(int i=0;i<n;i++){
    printf("NAME:%s\nID:%d\nCGPA:%.2f\n",s[i].name,s[i].id,s[i].cgpa);
    printf("\n");
}

}

void new_student()
{
  struct student s[100];
  int n;
  FILE *fp;
  fp=fopen("test.txt","r");
  fscanf(fp,"%d\n",&n);
 for(int i=0;i<n;i++){
    fscanf(fp,"%s %d %f",s[i].name,&s[i].id,&s[i].cgpa);
}
 fclose(fp);
 printf("\nNew Students Name:");
 scanf("%s",s[n].name);
 fflush(stdin);
 printf("New Students Id:");
 scanf("%d",&s[n].id);
 fflush(stdin);
 printf("New Students CGPA:");
 scanf("%f",&s[n].cgpa);
 fflush(stdin);
 n++;
 FILE *fw;
 fw=fopen("test.txt","w");
 fprintf(fw,"%d\n",n);
 for(int i=0;i<n;i++){
    fprintf(fw,"%s\n%d\n%.2f\n",s[i].name,s[i].id,s[i].cgpa);
 }
 fclose(fw);

}
void remove_student(){
   struct student s[100];
   int n;
   FILE *fp;
  fp=fopen("test.txt","r");
  fscanf(fp,"%d\n",&n);
  for(int i=0;i<n;i++){
    fscanf(fp,"%s %d %f",s[i].name,&s[i].id,&s[i].cgpa);
 }
  int a;
    printf("\nEnter the ID Number:");
    scanf("%d", &a);
    for (int i=0;i<n;i++) {
        if (a==s[i].id) {
            for (int k=i; k<n;k++)
                s[k] = s[k + 1];
                  n--;
        }
    }
  printf("\nThe ID remove successfully");
  FILE *fc;
  fc=fopen("test.txt","w");
  fprintf(fc,"%d\n",n);
  for(int i=0;i<n;i++){
    fprintf(fc,"%s\n%d\n%.2f\n",s[i].name,s[i].id,s[i].cgpa);
 }
 fclose(fc);


}

int main()
{
    struct student s[100];
    window();
    int choice;
    printf("\n\n\t\tAt First Input How Much Student:");
    while(1)
    {
        printf("\n\n\t\t1. Input Student\n");
        printf("\t\t2. All Student\n");
        printf("\t\t3. New Student\n");
        printf("\t\t4. Remove Student\n");
        printf("\t\t5. Exit\n");
        printf("\n\t\tEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                input_student();
                break;
            case 2:
                all_student();
                break;
            case 3:
                new_student();
                break;
            case 4:
                remove_student();
                break;
            case 5:printf("\n\t\tThank You\n\n");
                exit(0);
                break;
            default:printf("Wrong Input");


        }

    }

    return 0;
}






