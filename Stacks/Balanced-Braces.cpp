#include<iostream>
#include<string>
#include<stack>

using namespace std;
int scan(string);

int main(){
    string st;
    cout<<"Enter the code snippet (press'^' to exit):\n";
    getline(cin,st,'^');
    scan(st);
    return 0;
}

int scan(string st){
   stack<char> S;
   for(int i=0;i<st.length();i++){  
       if(st[i]== '{' || st[i]=='[' || (st[i]=='('))
         S.push(st[i]);
       else if((st[i]=='}'&& S.top()=='{' ) || (st[i]==']'&& S.top()=='[') || (st[i]==')'&& S.top()=='('))
         S.pop();
       else if(st[i]=='}' || st[i]==']' || st[i]==')'){
           printf("! Missing alternative of '%c' !", S.top());
           exit(0);
       }
    }
    if(!S.empty()){
       printf("! Missing alternative of '%c' !", S.top());
       exit(0);
    }
    printf("Braces are balanced");
   return 0;
}
