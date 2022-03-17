#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{

    // starting menu

    string load;

    load = "/";

    for(int i = 0; i < 10000; i++)
        {
            cout << load << endl;
            if(i % 800 == 0){
                load += "/";
            }

        }

    cout << "\n\n\n\n" << endl;

    cout << "   / / /  / / /   / / /" << endl;
    cout << "  / / /            / / /" << endl;
    cout << "/ / / /            / / / /" << endl;
    cout << "/ / / /            / / / /" << endl;
    cout << "/ / / /            / / / /" << endl;
    cout << "/ / / /   Oma4     / / / /" << endl;
    cout << "/ / / /            / / / /" << endl;
    cout << "/ / / /            / / / /" << endl;
    cout << "/ / / /            / / / /" << endl;
    cout << "  / / /            / / /" << endl;
    cout << "   / / /   / / /   / / /\n\n" << endl;

    // end starting menu ^

    cout << "\t\t*** Registration and Login system version 1.0.0 by Omar Ashraf ***\n" << endl;
    cout << "Welcome to said system! Are you new here or are you already registered with us?" << endl;

    int wrongChoiceC = 0;
    bool est3bat = false;

    string currentUserE; // current user

    while(true)
        {
            // check if the limit of wrong choices entered is reached
            if(est3bat == true)
                {
                    return 0;
                }
            else{
                ;
            }

            cout << "1 - Login\n2 - Register\n3 - View the user you're logged in as" << endl;

            int choice;
            cout << "Enter >> ";
            cin >> choice;

            int log = 1;
            int reg = 2;
            int view = 3;

            // logging in
            if(choice == log){

                string emailInput, passInput;
                string line;
                int numAccounts = 0;
                fstream file("accounts.txt");

                // lists to store emails and passwords in
                vector<string> emails;
                vector<string> passes;

                // inputs
                cout << "Email: ";
                cin >> emailInput;

                cout << "Password: ";
                cin >> passInput;


                // get all emails and their respective passwords
                while(getline(file, line))
                    {
                        numAccounts++;
                        string email;
                        string pass;

                        bool collectPass = false;

                        for(int i = 0; i < line.length(); i++){

                            char each = line[i];

                            //check if each reached ':' character to collect pass
                            if(collectPass){
                                pass += line[i];
                            }

                            else if (!collectPass){
                                if(each == ':'){
                                    collectPass = true;
                                }
                                else{
                                    email += line[i];
                                }
                            }

                        }

                        emails.push_back(email);
                        passes.push_back(pass);
                    }

                /*
                Blank stored in emails[0] and passes[0] due to
                the file containing an empty line at the beginning.
                To be fixed in later versions.
                */

                numAccounts--; // remove the count of the first blank line

                // check if the user exists
                bool userExists = false;
                string storePass;

                for(int i = 1; i <= numAccounts; i++){ // change the i to fit the length
                    if(emailInput == emails[i]){
                        storePass = passes[i];
                        userExists = true;
                        break;
                    }
                }

                if(userExists){
                    if(passInput == storePass){
                        currentUserE = emailInput;
                        system("CLS");
                        cout << "\t\t**You have now logged in as " << currentUserE << "**" << endl;
                    }
                    else{
                        system("CLS");
                        cout << "\t\t**You have entered the wrong password!**" << endl;
                    }
                }
                else if (!userExists){
                    system("CLS");
                    cout << "\t\t**User does not exist**" << endl;
                }

                file.close();
            }

            // registration
            else if(choice == reg){
                system("CLS");
                cout << "\t\t**Register a new account**\n" << endl;
                string email, password;

                // new account
                cout << "Email: ";
                cin >> email;

                cout << "Password: ";
                cin >> password;

                // add new account to text file
                fstream file;
                file.open("accounts.txt", std::ios_base::app);
                file << "\n" << email << ":" << password;
                file.close();

                system("CLS");
                cout << "\t\t**Thank you for registering! You can now login with your new account.**" << endl;
            }

            // view current logged in user
            else if(choice == view){
                system("CLS");
                cout << "\t\t**You are currently logged in as " << currentUserE << "**" << endl;
            }

            // wrong choice entered >>>>>>
            else{

                // clear screen
                system("CLS");

                switch(wrongChoiceC)
                {
                case 0:
                    cout << "\t\t**Please enter a valid choice**\n" << endl;
                    wrongChoiceC++;
                    break;

                case 1:
                    cout << "\t\t**PLEASE enter a valid choice**\n" << endl;
                    wrongChoiceC++;
                    break;

                case 2:
                    cout << "\t\t**Really now?**\n" << endl;
                    wrongChoiceC++;
                    break;

                case 3:
                    cout << "\t\t**Let's try this again, you got this**\n" << endl;
                    wrongChoiceC++;
                    break;

                case 4:
                    cout << "\t\t**ONE more chance**\n" << endl;
                    wrongChoiceC++;
                    break;

                default:
                    cout << "\t\t**Have a good day**\n" << endl;
                    est3bat = true;
                    break;
                }

            } // <<<<<

        }

    return 0;
}
