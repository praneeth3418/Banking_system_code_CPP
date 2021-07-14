#include<iostream>
#include<fstream>
using namespace std;

class newcustomer{
    string account_number;
    string password;
    string first_name;
    string last_name;
    int balance;
    public:
    void account_details(){
        cout<<"enter 10 digits account number: ";
        cin>>account_number;
        cout<<"enter password: ";
        cin>>password;
        cout<<"enter first name: ";
        cin>>first_name;
        cout<<"enter last name: ";
        cin>>last_name;
        cout<<"enter initial balance: ";
        cin>>balance;
        create_record();
    }
    void create_record(){
        string a="C:/Users/Praneeth/Documents/c++_projects/account_details/";
        string b=".txt";
        string c=a+account_number+b;
        ofstream file(c);
        file<<account_number<<endl;
        file<<password<<endl;
        file<<first_name<<endl;
        file<<last_name<<endl;
        file<<balance;
        cout<<"account created succesfully";
    }
};

class oldcustmer{
    string account_number;
    string password;
    string fir_name,la_name;
    int bal;
    public:
    void verification(){
        cout<<"enter account number";
        cin>>account_number;
        cout<<"enter password";
        cin>>password;
        string a="C:/Users/Praneeth/Documents/c++_projects/account_details/";
        string b=".txt";
        string c=a+account_number+b;
        string an,pw,balan;
        ifstream read(c);
        getline(read,an);
        getline(read,pw);
        getline(read,fir_name);
        getline(read,la_name);
        getline(read,balan);
        bal=stoi(balan);
        if(an==account_number && pw==password){
            cout<<"select your choice";
            cout<<"1.credit money \n2.debit money \n3.check balance\n4.delete account";
            int get_choice;
            cin>>get_choice;
            if(get_choice==1){
                credit_money();
            }
            else if (get_choice==2)
            {
                debit_money();
            }
            else if (get_choice==3)
            {
                 check_balance();
            }
            else if (get_choice==4)
            {
                delete_account();
            }
        }
        else{
            cout<<"incorrect password or username";
        }
    }
    void credit_money(){
        cout<<"enter crediting amount";
        int adding_bal;
        cin>>adding_bal;
        bal=bal+adding_bal;
        string a="C:/Users/Praneeth/Documents/c++_projects/account_details/";
        string b=".txt";
        string c=a+account_number+b;
        ofstream file(c);
        file<<account_number<<endl;
        file<<password<<endl;
        file<<fir_name<<endl;
        file<<la_name<<endl;
        file<<bal;
        cout<<"money added successfully";

    }
    void debit_money(){
        cout<<"enter debiting amount: ";
        int debiting_bal;
        cin>>debiting_bal;
        if(debiting_bal<=bal){
           bal=bal-debiting_bal;
           string a="C:/Users/Praneeth/Documents/c++_projects/account_details/";
           string b=".txt";
           string c=a+account_number+b;
           ofstream file(c);
           file<<account_number<<endl;
           file<<password<<endl;
           file<<fir_name<<endl;
           file<<la_name<<endl;
           file<<bal;
           cout<<"money debited successfully";
           }
           else{
               cout<<"insufficient balance ";
           }
    }
    
    void check_balance(){
        cout<<"your account balance is "<<bal;
    }
    void delete_account(){
        string a="C:/Users/Praneeth/Documents/c++_projects/account_details/";
        string b=".txt";
        string str=a+account_number+b;
        const char* filename=str.c_str();
        remove(filename);
    }
};


int main(){
  int choice;
  cout<<"press \n 1.create account \n2.to add credit or debit money from account ";
  cin>>choice;
  if(choice==1){
      newcustomer a;
      a.account_details();
  }
  else if(choice==2){
      oldcustmer o;
      o.verification();
  }
  return 0;
}

