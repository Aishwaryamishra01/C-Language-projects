#include<stdio.h>
#include<math.h>
#include<float.h>
double division(double  , double );
double modulus(int a , int b); //signature of the function 
void print_menu();
int main (){
            int num =1;
            int choice;
            double first_num , second_num, result;
    while(1){
    print_menu();
    scanf("%d",&choice);
    if (choice == 7){
        printf("thank you so much for using this program");
    break;
     }
    if(choice < 1 || choice >7){
        printf("This is a Invalid choise pleaase make a choice of operation as given in the menu");
        continue;
    }
      printf("\n Please, enter your first number\n");
      scanf("%lf",&first_num);
      printf("\n Please ,enter your second number\n");
      scanf("%lf",&second_num);
   
        switch (choice)
        {
                case 1://Add
                    result = first_num + second_num;
                    break;
                case 2:// Subtract
                    result = first_num - second_num;
                    break;
                case 3: // Multiply
                    result = first_num * second_num;
                    break;
                case 4: // Divide 
                    result = division(first_num, second_num);
                    break;
                case 5: //Modulus
                    result = modulus( first_num, second_num);
                    break;
                case 6://Power
                    result = pow(first_num ,second_num);
                    break;
                
        }
        if(!isnan(result) ){
            printf("\n The result of the operation is :%.2f\n",result);
        }  
        };
   

return 0;
}

double division(double a, double b){
    if (b==0){
        fprintf( stderr, "Invalid Argument for division \n" );
        return NAN;
    }else {
        return a/b;
    }
}
double modulus(int a, int b){
    if (b==0){
        fprintf( stderr ,"Invalid Argument for Moduls operation\n" );
        return NAN;
    }else {
        return (int)a%(int) b;
    }
}
void print_menu(){
    printf("\n________________________________________________________\n");
    printf("Welcome to the Simple Calculator\n");
    printf("\nChoose one of the folloing operations:\n");
    printf("\nNO.1. Add\n");
    printf("\nNO.2. Subtract\n");
    printf("\nNO.3. multiply\n");
    printf("\nNO.4. divide\n");
    printf("\nNO.5. Modulus\n");
    printf("\nNO.6. power\n");
    printf("\nNO.7.Exit\n");
    printf("\nNow Enter your choice\n");
}