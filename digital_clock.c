/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <time.h>
#include <unistd.h>//sleep();
#include <stdlib.h>

void fill_time(char*, int);
void fill_date(char*);
int timeformet();
void clear_scren();

int main()
{   
    char time[50],date[100];
    int formet = timeformet();
    
    while(1){
    fill_time(time,formet);
    fill_date(date);
    clear_scren();
    printf("-----------------------------------\n");
    printf(" current time : %s\n",time);
    printf(" date : %s\n",date);
    printf("-----------------------------------\n");
    sleep(1);
    }
    return 0;
}
void clear_scren(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void fill_time(char* buffer,int format){
    time_t raw_time;
    struct tm *current_time;
   
    time(&raw_time);
    current_time = localtime(&raw_time);
    if(format==1){
        strftime(buffer, 50, "%H:%M:%S", current_time);
    }else{
    strftime(buffer, 50, "%I:%M:%S %p", current_time);
    }
}
void fill_date(char* buffer){
    time_t raw_time;
    struct tm *current_time;
   
    time(&raw_time);
    current_time = localtime(&raw_time);
    
    strftime(buffer, 100, "%A %d %B %Y", current_time);
   
}


int timeformet(){
    int formet;
    printf("Choose the time format : \n");
    printf("1: 24 Hour format \n");
    printf("2: 12 Hour format (default) \n");
    printf("Make a choice(1/2) :  ");
    scanf("%d", &formet);
    return formet;
    
}
