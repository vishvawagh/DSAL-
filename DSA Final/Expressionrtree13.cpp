#include<iostream>
#include<string>
#include<stack>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
class Ntree{
    public :
    char d;
    Ntree *l,*r;
    Ntree(char d){
        this->d = d;
        this->l = NULL;
        this->r = NULL;
    }
};
class Stack_Node{
    public :
    Ntree *ntree;
    Stack_Node *n;
    Stack_Node(Ntree *ntree){
        this->ntree = ntree;
        n = NULL;
    }
};
class ExpressTree{
    Stack_Node *top;
    public:
    ExpressTree(){
        top = NULL;
    }
    void clrar(){
        top = NULL;
    }
    void push(Ntree *ptr){
        if(top == NULL){
            top = new Stack_Node(ptr);
           
        }else{
            Stack_Node *nptr = new Stack_Node(ptr);
            nptr->n = top;
            top = nptr;
        }
    }
    Ntree *pop(){
        if(top == NULL){
            cout<<"Underflow !!!"<<endl;
        }else{
            Ntree *ptr = top->ntree;
            top = top->n;
            return ptr;
        }
        return 0;
    }
    Ntree *peek(){
        return top->ntree;
    }
    void insertT(char val){
        if(isOperand(val)){
            Ntree * nptr = new Ntree(val);
            push(nptr);
        }
        else if(isOperator(val)){
            Ntree *nptr = new Ntree(val);
            nptr->l = pop();
            nptr->r  = pop();
            push(nptr);
        }
        else{
            cout<<"Invalid Expression !!"<<endl;
            return;
        }
    }
    bool isOperand(char ch){
        return ch >= 'a' && ch <= 'z';
    }
    bool isOperator(char ch){
        return (ch = '+'  || ch == '-'|| ch  == '*' || ch == '/');

    }
    void Build_Tree(string eqn){
     for(int i = eqn.length() -1 ; i>= 0 ;i--){
        insertT(eqn[i]);
     }
    }
    void postfix(){
        Post(peek());
    }
    void Post(Ntree *ptr){
        if(ptr != NULL){
            Post(ptr->l);
            Post(ptr->r);
            cout<<ptr->d;
        }
    }
    void infix(){
        inOrder(peek());
    }
    void inOrder(Ntree *ptr){
        if(ptr != NULL){
            inOrder(ptr->l);
            cout<<ptr->d;
            inOrder(ptr->r);
        }
    }
    void prefix(){
        preOrder(peek());
    }
    void preOrder(Ntree *ptr){
        if(ptr != NULL){
            cout<<ptr->d;
            preOrder(ptr->l);
            preOrder(ptr->r);
        }
    }
};
int main(){
    Ntree *ntree;
    string s;
    ExpressTree et ;
    cout<<"\n Enter equation in prefix form :";
    cin>>s;
    et.Build_Tree(s);
    cout<<"Postfix :";
    et.postfix();
   
}
