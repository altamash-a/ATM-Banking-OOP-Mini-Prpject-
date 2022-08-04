#include <iostream>
#include<conio.h>
#include<string>
using namespace std;

/*Mini projet - ATM
 -> Check Balance
 -> CAsh Withdraw
 -> Update Mobile No.
*/
class atm{
private:
    long int account_no;
    string name;
    int pin;
    double balance;
    string mobile_no;

public:

    void setData(long int account_no_a,string name_a,int pin_a, double balance_a, string mobile_no_a)
    {
        account_no = account_no_a;
        name = name_a;
        pin = pin_a;
        balance = balance_a;
        mobile_no = mobile_no_a;
    }

    long int getAccountNo()
    {
        return account_no;
    }

    string getName()
    {
        return name;
    }

    int getPIN()
    {
        return pin;
    }

    double getBalance()
    {
        return balance;
    }

    string getMobileNo()
    {
        return mobile_no;
    }

    void setMobile(string mob_prev, string mob_new)
    {
        if(mob_prev == mobile_no)
        {
            mobile_no = mob_new;
            cout<< endl << "Sucessfully Updated Your Mobile No!!";
            getch();


        }
        else
        {
            cout<< endl << "Incorrect !!!  Old Mobile No.";
            getch();
        }
    }


    void cashWithDraw(int amount_a)
    {
        if(amount_a > 0  &&  amount_a < balance)
        {
            balance -= amount_a;
            cout<< endl << "Please Collect Your Cash.";
            cout<< endl << "Available Balance : " << balance;
            getch();
        }
        else
        {
            cout<< endl << "Invalid Input or Insufficient Balance";
            getch();
        }
    }
};


int main()
{
   int choice = 0, enterPIN;
   long int enterAcountNo;

   atm user1;

   user1.setData(1234567, "Altamash", 9999, 55000.90, "9999999999");


   do
   {
       system("cls");

       cout<< endl << "******* WELCOME  TO  ATM *******"<<endl;
       cout<< endl << "Enter Your Account No ";
       cin>>enterAcountNo;

       cout<< endl << "Enter PIN ";
       cin>>enterPIN;


       if((enterAcountNo == user1.getAccountNo())  &&  (enterPIN == user1.getPIN()))
       {
           do
           {
               int amount = 0;
               string oldMobileNo, newMobileNo;

               system("cls");

               cout<< endl << "******* WELCOME  TO  ATM *******"<<endl;
               cout<< endl << "SELECT OPTIONS ";
               cout<< endl << "1. Check Balance";
               cout<< endl << "2. Cash Withdraw";
               cout<< endl << "3. Update Mobile No.";
               cout<< endl << "4. Show User Details";
               cout<< endl << "5. Exit" << endl;

               cin>> choice;

               switch(choice)
               {
               case 1:
                cout<< endl << "Your Balance is : " << user1.getBalance();
                getch();
                break;

               case 2:
                   cout <<endl << "Enter The Amount : ";
                   cin>> amount;
                   user1.cashWithDraw(amount);
                   break;

               case 4:
                cout<< endl << "     USER DETAILS ARE :- ";
                cout<< endl << " -> Account No " << user1.getAccountNo();
                cout<< endl << " -> Name       " << user1.getName();
                cout<< endl << " -> Balance    " << user1.getBalance();
                cout<< endl << " -> Mobile No. " << user1.getMobileNo();
                _getch();
                break;

               case 3:
                cout<< endl << "Enter Old Mobile No. ";
                cin>> oldMobileNo;

                cout<< endl << "Enter New Mobile No. ";
                cin>> newMobileNo;

                user1.setMobile(oldMobileNo, newMobileNo);
                break;

               case 5:
                exit(0);

               default:
                cout<< endl << "Enter valid Data !!!";
               }
           }while (1);

       }
   }while(1);
}
