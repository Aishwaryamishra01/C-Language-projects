#include<stdio.h>
#include<string.h>
#define max_user 10
#define credential_length 30
void fix_fgets_input(char*);
typedef struct{
 char username[30];
 char password[30];
}user;
user users [max_user];
int user_count = 0;
void print_menu();
void register_user();
int  login_user();
int user_index;
void input_password(char*);
int main (){
    int option ;
    while(1){
    printf("welcome to user management:-\n");
    printf("\n 1. Register");
    printf("\n 2. Login");
    printf("\n 3. Exit");
    printf("\n Select an option");
    scanf("%d",&option);
    getchar();//consume extra enter
    switch(option){
        case 1:
        register_user();
           break;
        case 2:
           user_index = login_user();
           if (user_index >= 0){
             printf("\n Login Successful! WElcome %s!",users[user_index].username );
           } else{
            printf("\nLogin failed! Incorrect username or password.");

           }
           break;
        case 3:
           printf("\n Exiting the program");
           return 0;
           break;
        default:
           printf("\nPlease enter a Valid option, Please try again");
           break;
      }
    }
return 0;
}
void register_user(){
    if(user_count == max_user){
        printf("\nMasimum 10 users are supported no more registration allowed", max_user);
        return;
    }  
  int new_index = user_count;
  printf("Register as a new user!\n");
  printf("Enter yor username Please:");
  fgets( users[new_index].username, credential_length, stdin);
  fix_fgets_input (users[new_index].username);
  input_password(users[new_index].password);
  user_count++;
  printf("\nRegistration successfull! \n");
}
int login_user(){
    char username[credential_length],password[credential_length];
    printf("\nPlease input usesrname:");
    fgets(username, credential_length,stdin);
    fix_fgets_input(username);
    input_password(password);

    for(int i = 0; i< user_count; i++){
        if(strcmp(username, users[i].username)== 0 && strcmp(password, users[i].password)){
           return i; 
        }
    }
  return -1;
}
void fix_fgets_input(char* string){
  int index= strcspn(string, "\n"); // to search the inde we use strcnpn function 
  string[index] = '\0';
}
void input_password(char*password){
    printf("\nPlease input your passwords ie in charcters: ");
    fgets(password,credential_length,stdin);
    fix_fgets_input(password);
}