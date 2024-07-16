#include<iostream>
#include<ctime>
using namespace std;

char getuserchoise();
char getcomputerchoice();
void showchoice(char choice);
void choosewinner(char player,char computer);

int main(){
char player;
char computer;

player = getuserchoise();
cout<<"you chose; ";
showchoice(player);

computer = getcomputerchoice();
cout<<"computer's chose; ";
showchoice(computer);

choosewinner(player, computer);

return 0;

}

char getuserchoise(){
char player;
  cout<<"Rock-Paper-Secissor Game"<<endl;
  do{
  cout<<"Chose one of thr folloeing"<<endl;
  cout<<"************************"<<endl;
  cout<<"'r' for rock"<<endl;
  cout<<"'p' for paper"<<endl;
  cout<<"'s' for secissor"<<endl;
  cin >> player;
  }while(player != 'r' && player !='p' && player !='s');
  return player;
}

char getcomputerchoice(){
 srand(time(0));
int num = rand()%4;

switch (num)
{
case 1:
return 'r';
break;

case 2:
return 's';
break;

case 3:
return 'p';
break;

}
return 0;
}

void showchoice(char choice){
  switch (choice)
  {
  case 'r':
  cout<<"Rock"<<endl;
  break;

  case 'p':
  cout<<"Paper"<<endl;
  break;

  case 's':
  cout<<"Scissors"<<endl;
  break;
  }
}
void choosewinner(char player,char computer){
switch(player){
case 'r':
        if(computer == 'r'){
          cout<<"it's a tie ";
        }

        if(computer == 'p'){
          cout<<"you loose ";
        }

        if(computer == 's'){
          cout<<"you win ";
        }
break;

case 'p':
        if(computer == 'p'){
          cout<<"it's a tie ";
        }

        if(computer == 's'){
          cout<<"you loose ";
        }

        if(computer == 'r'){
          cout<<"you win ";
        }
break;

case 's':
        if(computer == 's'){
          cout<<"it's a tie ";
        }

        if(computer == 'r'){
          cout<<"you loose ";
        }

        if(computer == 'p'){
          cout<<"you win ";
        }
break;
}

}