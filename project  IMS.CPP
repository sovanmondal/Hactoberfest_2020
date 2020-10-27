#include<cstring>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<vector>
using namespace std;
class register_customer{
      public:
      char customer_name[30];
      char customer_mob[10];
      char customer_add[30];
      char policy_name[20];
      bool claim=false;
      bool claim_issued=false;
     //function to add details of customer

      void add_customer(){
          system("cls");
            cout<<"enter name:"<<endl;
            cin>>customer_name;
             cout<<"enter address"<<endl;
            cin>>customer_add;
            cout<<"enter mobile number:"<<endl;
            cin>>customer_mob;

             addpolicy();
            ofstream fout;
            fout.open("file9.dat",ios::app|ios::binary);
            fout.write((char*)this,sizeof(*this));
            fout.close();

        }


        void showdata(){
        cout<<this->customer_name<<"****"<<this->customer_add<<"*****"<<this->customer_mob<<"****"<<this->policy_name<<"****"<<claim<<"****"<<claim_issued<<endl;
        }

        void displayallrecord(){
          ifstream fin;
       fin.open("file9.dat",ios::in|ios::binary);
       if(!fin){
        cout<<"\nfile not found";
       }
       else{
        fin.read((char*)this,sizeof(*this));
         cout<<"NAME"<<"****"<<"ADDRESS"<<"****"<<"MOBILE NUMBER"<<"****"<<"POLICY NAME"<<"****"<<"CLAIM"<<endl;

        while(!fin.eof()){
                showdata();
                fin.read((char*)this,sizeof(*this));
        }

       }

    fin.close();
        }

    void admin_searchh(){
     char mob[10];
     cout<<"ENTER YOUR REGISTERED MOBILE NUMBER:"<<endl;
      cin>>mob;
        fstream file;
       file.open("file9.dat",ios::in|ios::out|ios::ate|ios::binary);
       file.seekg(0);
        file.read((char*)this,sizeof(*this));
        while(!file.eof()){
            if(!strcmp(mob,customer_mob)){
                    if(claim!=true){
                        cout<<"policy not claimed"<<endl;
                        break;
                    }
                claim_issued=true;
                 file.seekp(file.tellp()-sizeof(*this));
                file.write((char*)this,sizeof(*this));
            }
             file.read((char*)this,sizeof(*this));
        }
    }



 void addpolicy(){
         cout<<"THREE POLICIES OFFERED BY COMPANY:"<<endl;
         cout<<"1.VIP WHICH WILL COST 5000 PER ANNUM AND POLICY BENEFITS BE USED ONE TIME AFTER CLAIM"<<endl;
         cout<<"2.PREMIUM WHICH WILL COST 10000 PER ANNUM AND POLICY BENEFITS BE USED ONE TIME AFTER CLAIM"<<endl;
         cout<<"3.ROYAL WHICH WILL COST 15000 PER ANNUM AND POLICY BENEFITS BE USED TWO TIME AFTER CLAIM"<<endl;
         cout<<"ENTER POLICY NUMBER: ABOVE OPTIONS MENTIONED"<<endl;
         cin>>policy_name;
    }

    void claimpolicy(){
      char mob[10];
        cout<<"ENTER YOUR REGISTERED MOBILE NUMBER:"<<endl;
        cin>>mob;
       ifstream fin;
       fin.open("file9.dat",ios::in|ios::binary);

       if(!fin){

        cout<<"\nfile not found";
       }

       else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){

                if(!strcmp(mob,customer_mob)){
                   claimed_status_update(mob);
                   }
                fin.read((char*)this,sizeof(*this));
        }
       }
  fin.close();
    }
    void claimed_status_update(char *mob){
       fstream file;
       file.open("file9.dat",ios::in|ios::out|ios::ate|ios::binary);
       file.seekg(0);
        file.read((char*)this,sizeof(*this));
        while(!file.eof()){
            if(!strcmp(mob,customer_mob)){
                claim=true;
                  if(claim_issued){
                     cout<<"ISSUED"<<endl;
                   }
                    else{
                      cout<<"NOT ISSUED"<<endl;
                    }
                 file.seekp(file.tellp()-sizeof(*this));
                file.write((char*)this,sizeof(*this));
            }
             file.read((char*)this,sizeof(*this));
        }
    }

};
int main(){
  vector<register_customer> v;
  register_customer c1,c2;
   int num;
 while(num!=3){
  cout<<"ENTER 1. IF YOU ARE ADMIN"<<endl;
  cout<<"ENTER 2.IF YOU ARE CUSTOMER"<<endl;
  cout<<"ENTER 3.FOR EXIT"<<endl;
  cin>>num;
  switch(num){
     case 1:  int password;
              // system("cls");
              cout<<"ENTER PASSWORD"<<endl;
              cin>>password;
              int num1;
              if(password==1234){
                cout<<"1.SEARCH PARTICULAR RECORD:"<<endl;
                cout<<"2.DISPLAY CUSTOMER LIST WHO CLAIMED POLICY:"<<endl;
                cin>>num1;
                if(num1==1){
                     c1.admin_searchh();
                }
                else {
                    c1.displayallrecord();
                }
              }
              break;
     case 2: int num2;
            //  system("cls");
                cout<<"PRESS 1 FOR REGISTER:"<<endl;
                cout<<"PRESS 2 FOR CLAIM POLICY AND CHECK CLAIM ISSUED OR NOT"<<endl;
                cin>>num2;
                 if(num2==1){
                    c2.add_customer();
                    v.push_back(c2);
                    break;
                }
                else  {
                        c2.claimpolicy();
                        break;
                }
     default:
        break;
  }
 }
}
