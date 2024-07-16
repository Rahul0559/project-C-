#include <iostream>
#include<ctime>
using namespace std;
int main(){
 int guess;
 int tries;
 srand(time(0));
 int rand_num = rand()%101;
 cout<<"************NUMBER GUSSING**************"<<endl;
 do{
  cout<<"enter a gess between(1-100): ";
  cin>>guess;
  tries+=tries;
  if(guess > rand_num){
    cout<<"to high\n";
  }
   else if(guess < rand_num){
    cout<<"to low\n";
  }
     else{
    cout<<"correct! # of tries; "<<tries<<endl;
  }
 }while(rand_num!=guess);
 cout<<"************************************"<<endl;

}