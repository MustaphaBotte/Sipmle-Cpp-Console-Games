#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;
short readpositivenumber(string message)
{short number;
    do{cout<<message;
cin>>number;}
while(number<=0);
return number;}

int randomnumber(int from,int to)
 {
     int random=rand()%(to-from+1)+from;
     return random;}

short user_choice()
{short userchoice;

cout<<"your choice: stone [1], paper [2] , scissors[3]: " ;
userchoice=readpositivenumber("!");
return userchoice;
}

short computer_choice()
{short computerchoice;
{computerchoice=randomnumber(1,3);
}return computerchoice;}


string gamecheck(short computerchoice,short userchoice)
{

     if(computerchoice==1&&userchoice==1)
     {system("Color 6F");
      return  "NO WINNER";}

else if(computerchoice==1&&userchoice==2)
     {system("Color 2F");
      return "YOU WIN";}

else if(computerchoice==1&&userchoice==3)
      {system("Color 4F");
      return  "COMPUTER WIN";}

else if(computerchoice==2&&userchoice==1)
      {system("Color 4F");
          return   "COMPUTER WIN";}

else if(computerchoice==2&&userchoice==2)
      {system("Color 6F");
      return    "NO WINNER";}

else if(computerchoice==2&&userchoice==3)
      {system("Color 2F");
      return "YOU WIN";}

else if(computerchoice==3&&userchoice==1)
      {system("Color 2F");
     return  "YOU WIN";}

else if(computerchoice==3&&userchoice==2)
      {system("Color 4F");
     return "COMPUTER WIN";}

else if(computerchoice==3&&userchoice==3)
     {system("Color 6F");
     return   "NO WINNER";}
}


void gamecheckwinner(short counter,short computerchoice,short userchoice)
{
cout<<"\n___________________ROUND["<<counter<<"]_________________\n";
cout<<"\ncomputer choice: ";
        if(computerchoice==1)
            cout<<"stone\n";
        else if(computerchoice==2)
            cout<<"paper\n";
        else if(computerchoice==3)
            cout<<"scissors\n";

cout<<"user choice: ";
        if(userchoice==1)
            cout<<"stone\n";
        else if(userchoice==2)
            cout<<"paper\n";
        else if(userchoice==3)
            cout<<"scissors\n";



}


void gamecheckwinner2(short number)
{short user=0,computer=0,draw=0,winner=0;
    short counter=1;
    for(short i=1;i<=number;i++)
{short computerchoice=computer_choice();
short userchoice=user_choice();
cout<<"ROUND["<<i<<"]BEGGIN : \n";
gamecheckwinner(counter++,computerchoice,userchoice);
string result=gamecheck( computerchoice, userchoice);
cout<<"[WINNER]: "<<result<<"\n";
cout<<"_______________________________________________________\n";
if(result=="YOU WIN")
    user++;
else if(result=="NO WINNER")
    draw++;
else if(result== "COMPUTER WIN")
    computer++;

}

cout<<"\n\n\t\t___________________________________________";
cout<<"\n\t\t              +++GAME OVER\n";
cout<<"\n\t\t___________________________________________";
cout<<"\n\n\t\t______________[GAME RESULT]__________________\n";
cout<<"\t\tGAME ROUND    :"<<--counter<<"\n";
cout<<"\t\tUSER WIN      :"<<user;
cout<<"\n\t\tCOMPUTER WIN  :"<<computer;
cout<<"\n\t\tDRAW          :"<<draw;
cout<<"\n\t\tWINNER IS     :";
if(user>computer)
        cout<<"USER WIN";
        else if(computer>user)
        cout<< "COMPUTER WIN";
else cout<< "NO WINNER";
}

void playgame(short number)
{char choice;


do{number=readpositivenumber(" HOW MANY ROUND:");
        gamecheckwinner2( number);
cout<<"\n\t\tDO YOU WANT TO PLAY AGAIN: [y]/[n]";
cin>>choice;
system("cls");
system("Color 0F");
}
 while(choice=='y'||choice=='Y');

}





int main()
{srand((unsigned)time(NULL));
short number;
short computerchoice,userchoice;
playgame( number);

}

