#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;
enum enoperation {add=1,sub=2,mul=3,Div=4,Mix=5};
enum enlevel{easy=1,med=2,hard=3,mix=4};
enum encorrect{correct=1,False=2};

struct stuserchoice{
short level=0;
short operation=0;
short numberofq=0;
int generatenumber1=0;
int generatenumber2=0;


};


int randomnumber(int from,int to)
 {
     int random=rand()%(to-from+1)+from;

     return random;}

int random_operation(short operationtype)
{



    return (randomnumber(1,4));


}



short get_number_of_question()
{
    short numberofquestion;
do{cout<<"How Many Question Do You Want To Answer: ";
cin>>numberofquestion;
}while(numberofquestion<=0);
return numberofquestion;
}

enlevel get_level_type()
{
    short leveltype;
do{cout<<"Please Enter Level Of Question: Easy[1] Med[2] Hard[3] Mix[4] ";
cin>>leveltype;}
while(leveltype<=0||leveltype>4);
return (enlevel)leveltype;
}

enoperation read_operation_type()
{
    short operationtype;
do{cout<<"Please Enter Operation Type Of Question: Add[1] Sub[2] Mul[3] Div[4] Mix[5]";
cin>>operationtype;}
while(operationtype<=0||operationtype>5);
    (enoperation)operationtype;}

int calcul_numbers(int num1,int num2,short operationtype)
{
     if (operationtype==1)
           return num1 + num2;
else if(operationtype==2)
           return num1 - num2;
else if(operationtype==3)
           return num1 * num2;

else if(operationtype==4)
           return num1 / num2;
else if(operationtype==5)
    return calcul_numbers(num1,num2,randomnumber(1,4));

}
void print_operation(short operationtype)
{
    string arr[4]={"+","-","*","/"};
cout<<arr[operationtype-1];}


int generate_numbers_by_level(short leveltype )
{
       if (leveltype==1)
            return randomnumber(1,10);
     else if(leveltype==2)
            return randomnumber(10,50);
     else if(leveltype==3)
            return randomnumber(50,200);
     else return randomnumber(1,200);
}


int read_user_answer()
{
    int answer;
cin>>answer;
return answer;
  }

stuserchoice get_user_choices(stuserchoice &userchoices)
{
    userchoices.numberofq=get_number_of_question();
    userchoices.level=get_level_type();
    userchoices.operation=read_operation_type();
    userchoices.generatenumber1=generate_numbers_by_level(userchoices.level);
    userchoices.generatenumber2=generate_numbers_by_level(userchoices.level);
    return userchoices;}



string tab(short number)
{
     string t=" ";
for(int i=1;i<=number;i++)
    {t=t+"\t";
      cout<<t;
    }
    return t;

}




void show_game_over()
{
    cout<<tab(2)<<"_______________________________________\n";
 cout<<tab(2)<<"          G A M E  O V E R             \n";
 cout<<tab(2)<<"_______________________________________\n";
 }

string print_level(short number)
{
     {
         if (number==1)
         return "EASY";
      if (number==2)
         return "MED";
      if (number==3)
         return "HARD";
       if (number==4)
         return "MIX" ;
     }
}
 string passe_or_fall(int num1 ,int num2)
 {
     if(num1>num2)
   return "PASSE";
  else if(num1<
          num2)
   return "FAIl";
   else return "DRAW YOU HAVE TO STAY FOR ANOTHER QUIZ: \n";

 }



 void check_user_answer()
{
stuserchoice userchoices;
    get_user_choices( userchoices);
    short trueanswer=0;
    short falseanswer=0;
    for(int i=1;i<=userchoices.numberofq;i++)
    {      userchoices.generatenumber1=generate_numbers_by_level(userchoices.level);
           userchoices.generatenumber2=generate_numbers_by_level(userchoices.level);
           cout<<"\nQUESTION["<<i<<"/"<<userchoices.numberofq<<"]\n\n";
       cout<<userchoices.generatenumber1;
       cout<<"\n  ";
       print_operation(userchoices.operation);
       cout<<"\n"<<userchoices.generatenumber2;
         cout<<"\n_____________\n";

          int x=read_user_answer();
          int z=calcul_numbers(userchoices.generatenumber1,userchoices.generatenumber2,userchoices.operation);
           if(x==z)
          {cout<< "RIGHT ANSWER :-)\n";
           trueanswer++;
          system("color 2F");}
          else
            {cout<< "WRONG ANSWER\n\a";
            system("color 4F");
            falseanswer++;
            cout<<"result is: "<<calcul_numbers(userchoices.generatenumber1,userchoices.generatenumber2,userchoices.operation);}
            cout<<"\n";
            }
            show_game_over();
            cout<<"\nLEVEL OF GAME          : "<<print_level(userchoices.level);
            cout<<"\nNUMBER OF QUESTION     : "<<userchoices.numberofq;
            cout<<"\nOPERATION TYPE         : ";
            print_operation(userchoices.operation);
            cout<<"\nNUMBER OF TRUE ANSWERS : "<<trueanswer;
            cout<<"\nNUMBER OF WRONG ANSWERS: "<<falseanswer;
            cout<<endl<<passe_or_fall(trueanswer,falseanswer);


}
void  reset_screen()
{
    system("cls");
 system("color 0F");

}

void start_game()
    {
    char choice='y';
               do{
                  reset_screen();
                    check_user_answer();
                cout<<"\ndo you want to play again: Y/n ";
               cin>>choice;}
                while(choice=='y'||choice=='Y');





             }


int main()
{
srand((unsigned)time(NULL));

start_game();

}




