#include <iostream>
using namespace std;
struct stack{
  stack* next;
  int data;
  stack * top;
  int size;
};
class implementstack{
  private:
  stack  s;
  int count;
  public:
  implementstack(int size){
  s.size = size;
  count = 0;
  s.top = nullptr; 
  }
  public:
  int isempty(){
    if(s.top==nullptr){
      cout<<"Stack is underflow: "<<endl;
      return 1;
    }
    cout<<"Stack is not underflow: "<<endl;
    return 0;
  }
    int isfull(){
    if(s.size==count){
      cout<<"Stack is overflow: "<<endl;
      return 1;
    }
    cout<<"Stack is not overflow: "<<endl;
    return 0;
  }
  void push(int value){
    if(isfull()){
      cout<<"stack is overflow"<<endl;
    }
    else{
    stack * newnode = new stack();
    newnode->data=value;
    newnode->next=nullptr;
    if(s.top==nullptr){
      s.top=newnode;
      count++;
    }
    else{
      newnode->next=s.top;
      s.top=newnode;
      count++;
    } 
  }
  cout<<"push operation done succesfull"<<endl;
  }
  void pop(){
    if(isempty()){
      cout<<"stack is underflow"<<endl;
    }
    else{
    stack * temp = s.top;
    s.top=s.top->next;
    delete(temp);
    count--;

  }
  cout<<"push operation done succesfull"<<endl;
  }
  void display(){
    stack * ptr =s.top;
    while(ptr!=NULL){
      cout<<ptr->data<<endl;
      ptr=ptr->next;
    }
    cout<<endl;
  }
};
int main(){
  implementstack stack(10);
  int value,chose;
  do{
    cout<<"manu 1.push 2.pop 3.empty 4.full 5.diplay 6.exit: "<<endl;
    cin>>chose;
    switch (chose){
    case 1:
    cout<<"enter a value with you add in to a stack; ";
    cin>>value;
    stack.push(value);
      break;
    case 2:
    stack.pop();
    break;
    case 3:
    stack.isempty();
    break;
    case 4:
    stack.isfull();
    break;
    case 5:
    stack.display();
    break;
    case 6:
    cout<<"exit the program: "<<endl;
    break;
    default:
    cout<<"enter a vaild number"<<endl;
      break;
    }
  }while(chose!=6);
  return 0;
}