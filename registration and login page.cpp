#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int choose;
    // Display the menu
    cout<<"\t\t\t____________________________________\n\n\n";
    cout<<"\t\t\t        WELCOME TO THE LOGIN PAGE    \n\n\n";
    cout<<"\t\t\t_____________MENU____________________ \n\n\n";
    cout<<"\t| Press 1 to LOGIN         |"<<endl;
    cout<<"\t| Press 2 to REGISTRATION  |"<<endl;
    cout<<"\t| Press 3 if YOU FORGOT YOUR PASSWORD |"<<endl;
    cout<<"\t| Press 4 to EXIT          |"<<endl;
    cout<<"\n\t\t\t Please enter your choice: ";
    cin>>choose;
    cout<<endl;

    // Handle user's choice
    switch(choose)
    {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout<<"\t\t\t THANK YOU! \n\n";
            break;
        default:
            system("cls");
            cout<<"\t\t\t Please select from the options given above. \n "<<endl;
            main();
    }
}

void login()
{
    int count = 0;
    string userId, password, id, pass;
    system("cls");
    cout<<"\t\t\t Please enter the username and password:"<<endl;
    cout<<"\t\t\t USERNAME: ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD: ";
    cin>>password;

    // Read from the records.txt file
    ifstream input("records.txt");
    while(input>>id>>pass)
    {
        if(id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if(count == 1)
    {
        cout<<userId<<"\n Your LOGIN is successful! \n Thanks for logging in! \n";
        main();
    }
    else
    {
        cout<<"\n LOGIN ERROR \n Please check your username and password.\n";
        main();
    }
}

void registration()
{
    string ruserId, rpassword;
    system("cls");
    cout<<"\t\t\t Enter the username: ";
    cin>>ruserId;
    cout<<"\t\t\t Enter the password: ";
    cin>>rpassword;

    // Write to the records.txt file
    ofstream f1("records.txt", ios::app);
    f1<<ruserId<<" "<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Registration is successful! \n";
    main();
}

void forgot()
{
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the password? No worries!\n";
    cout<<"\t\t\t Press 1 to search your ID by username\n";
    cout<<"\t\t\t Press 2 to go back to the main menu\n";
    cout<<"\t\t\t Enter your choice: ";
    cin>>option;

    switch(option)
    {
        case 1:
        {
            int count = 0;
            string suserId, sid, spass;
            cout<<"\n\t\t\t Enter the username you remember: ";
            cin>>suserId;

            // Search for the username in records.txt
            ifstream f2("records.txt");
            while(f2>>sid>>spass)
            {
                if(sid == suserId)
                {
                    count = 1;
                }
            }
            f2.close();

            if(count == 1)
            {
                cout<<"\n\n Your account is found! \n";
                cout<<"\n\n Your password is: "<<spass;
                main();
            }
            else
            {
                cout<<"\n\t Sorry! Your account is not found! \n";
                main();
            }
            break;
        }
        case 2:
            main();
            break;
        default:
            cout<<"\t\t\t Wrong choice! Please try again.\n";
            forgot();
    }
}
