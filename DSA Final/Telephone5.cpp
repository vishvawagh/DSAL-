#include<iostream>
#include<string.h>
using namespace std;
class Telephone{
    int hash_address, i , j , x;
    long int key ;
    int mobno[10];
    string name[10];
    public  : 
    Telephone(){
        for(int i = 0; i < 10;i++){
            mobno[i] = -1;

        }
    }
    void insertRecordLP(){
        cout<<"Entet the no of records"<<endl;
        cin>>x;
        for(int i =0 ; i < x ;i++){
        cout<<"Enter Telephone no  :";
        cin>>key;
        hash_address = key%10;
         if(mobno[hash_address] == -1){
            cout<<"Enter name : " ;
            cin>>name[hash_address];


         }else{
            int  i =1 ;
            while(mobno[hash_address + i ] < 10){
                if(mobno[hash_address + i] == -1){
                    mobno[hash_address + i] = key;
                    cout<<"Enter name :";
                    cin>>mobno[hash_address + i];
                    break;
                }else if (mobno[hash_address + i] != -1){
                    i++;
                }
            }
         }
        }
    }
    void insertRecordQP(){
        cout<<"Enter no of record :  " ;
        cin >> x;
        for(int i = 0 ; i  < x ;i++){
            cout<<"Enter Telephone no :";
            cin>>key;
            hash_address = key %10;
            if(mobno[hash_address] == -1){
                mobno[hash_address]  = key;
                cout<<"Enter name : ";
                cin >> name[hash_address];

            }else{
                int i =1 ;
                hash_address = hash_address +(i*i);
                while(mobno[hash_address] == -1 ){
                    if(mobno[hash_address ] == -1){
                        mobno[hash_address]   = key;
                        cout<<"Enter name : " ;
                        cin >> name[hash_address];
                    }
                    else if(mobno[hash_address] != -1 ){
                        i++;
                        hash_address = hash_address+(i*i);
                    }
                }
            }
        }
    }
    void display(){
       for(int  address = 0;address < 10; address++){
        cout<< address << " "<<mobno[address] << " " <<name[address] << endl;
       } 
    }
};
int main(){
    Telephone t1;
    int ch;
    do {
          cout<<"\n1.Insert Record(Linear Probing)";
        cout<<"\n2.Insert Record(Quadratic Probing)";
        cout<<"\n3.Display";
        cout<<"\n4.Exit";
        cout<<"\nEnter your choice:";
        cin>>ch;
        switch(ch)
         {
            case 1:
                t1.insertRecordLP();
                break;
            case 2:
                t1.insertRecordQP();
                break;
            case 3:
                 t1.display();
                 break;
            case 4:
                exit(0);
                break;
        }
    }while(ch!=4);

    return 0;
    }

