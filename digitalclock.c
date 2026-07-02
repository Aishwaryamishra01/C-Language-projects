#include<stdio.h> 
#include<time.h>
#include <stdlib.h>
#include <unistd.h>
int formate ;
char date[100];
int print_menu();
void fill_time(char*, int);
void fill_date(char*);
void clear_screen();
int main (){
    char time[50]; //string to store final formatted time
    formate= print_menu();
    while(1){
    fill_time(time, formate);
    fill_date(date);
    clear_screen();
    printf("currnt time is: %s\n",time);
    printf("Current date is: %s\n", date);
    sleep(1);
    }
    return 0;
}
void fill_time( char* buffer, int formate){
    time_t rawtime;
    struct tm *current_time;
    time(&rawtime);
    current_time = localtime(&rawtime);
    if (formate == 1){
        strftime(buffer, 50 , "%H:%M:%S %p", current_time);
    }if(formate== 2){
    strftime(buffer, 50, "%I:%M:%S %p",current_time); // buffer = storage place, size , formate , current time 
    }else{
        printf("\nPlease Choose a valid option\n" );
    }
}
int  print_menu(){
    printf("\nChoose the time formate: \n");
    printf("\n 1. 24 hours formmate ");
    printf("\n 2. 12 hours formate: ");
    printf("\nMake a choice(1/2):\n");
    scanf("%d",&formate);
    return formate;
}
void fill_date (char* buffer){
    time_t rawtime;
    struct tm *current_time;
    time(&rawtime);
    current_time= localtime(&rawtime);
    strftime(buffer, 100, "%A %B %d %Y", current_time);

}
void clear_screen(){
   // printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");  baccon wala tarika
   #ifdef _WIN32
    system("cls");
    #else
        system("clear");
    #endif
    
}