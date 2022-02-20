#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <time.h>

using namespace std;

//-------------------------------------------------------------------------------------------------------------//
//-- HOME PAGE FUNCTIONS --//
int log_in();
int sign_up();
int forgot_pass();
int failed_login();
int database();
int account_info();
int search_account();
int about_program();
int exit_program();
int game_menu();
//------------------------//
//-- GAME FUNCTIONS --//
int game();
int new_game();
int account_settings();
int log_out();
int house();
int work();
int casino();
int restaurant();
int coffee_shop();
//------------------------//
//-- CASINO FUNCTIONS --//
int blackjack();
int roulette();
int scratch_and_win();
int slot_machine();
int guess_the_cup();
int heads_or_tails();
//------------------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------------------//
//-- UNIVERSAL VARIABLES --//
int choice, coins, energy , pay, cooldown(8);
int bet, total ;
string username , password , first_name , last_name , magic_word , iuser , ipass , ipass2 ;
string yes1 , yes2 , yes3 , no1 , no2 , no3 ; 
//------------------------//

//------------------------------------------------------------------------------------------------------------//

int main()
{
	system("cls");
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "                                   HOME PAGE                                    " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          [1] LOG-IN          " << endl;
	cout << "          [2] SIGN-UP         " << endl;
	cout << "          [3] FORGOT PASSWORD " << endl;
	cout << "          [4] PLAYER DATABASE " << endl;
	cout << "          [5] ACCOUNT INFO    " << endl;
	cout << "          [6] ABOUT PROGRAM   " << endl;
	cout << "          [7] EXIT PROGRAM    " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          YOUR DESTINATION : " ;
	cin >> choice;
	switch (choice)
	{
		case 1:
			system("cls");
			log_in();
			break;
		case 2:
			system("cls");
			sign_up();
			break;
		case 3:
			system("cls");
			forgot_pass();
			break;
		case 4:
			system("cls");
			database();
			break;
		case 5:
			system("cls");
			account_info();
			break;
		case 6:
			system ("cls");
			about_program();
			break;
		case 7:
			system("cls");
			exit_program();
			break;
		default:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "-                               [INVALID INPUT]                                -" << endl << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			system("cls");
			return main();
			break;
	}
	
}

int log_in()
{
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "                                     LOG IN                                     " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;	
	cout << "          USERNAME : " ;
	cin >> iuser;
	cout << "          PASSWORD : " ;
	cin >> ipass;
	ifstream login;
	login.open(iuser.c_str() );
	if ( login.fail() )
	{
		system("cls");
		failed_login();
	}
	login >> username >> password >> first_name >> last_name >> magic_word >> coins >> energy ;
	if ( iuser == username && ipass == password)
	{
		system("cls");
		cout << endl << "--------------------------------------------------------------------------------" << endl;
		cout << "                                   LOGGED-IN!                                   " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "          USERNAME: " << username << endl;
		cout << "          PASSWORD: " << password << endl;
		cout << "          FIRST NAME: " << first_name << endl;
		cout << "          LAST NAME: " << last_name << endl;
		cout << "          MAGIC WORD: " << magic_word << endl;
		cout << "          COINS: $" << coins << endl;
		cout << "          ENERGY: " << energy << "/30" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		Sleep(3000);
		system("cls");
		game_menu();   
	}
	else
	{
		system("cls");
		failed_login();
	}
}

int sign_up()
{
	string re_password, answer, user;
	yes1 = "Yes"; yes2 = "yes" ; yes3 = "YES" ;
	no1 = "No" ; no2 = "no" ; no3 = "NO" ; 	
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "                                  REGISTRATION                                  " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          FIRST NAME : " ;
	cin >> first_name ;
	cout << "          LAST NAME : " ;
	cin >> last_name ;
	cout << "          MAGIC WORD ( FOR SECURITY ) : " ;
	cin >> magic_word ;
	cout << "          USERNAME : " ;
	cin >> username;
	ifstream username_test;
	username_test.open( username.c_str() );
	if ( !(username_test.fail()) )
	{
		system("cls");
		cout << endl << "--------------------------------------------------------------------------------" << endl;
		cout << "                             USERNAME ALREADY TAKEN                             " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		username_test.close();
		Sleep(2000);
		system("cls");
		return sign_up();		
	}
	
	cout << "          PASSWORD : " ;
	cin >> password;
	cout << "          RE-ENTER PASSWORD : " ;
	cin >> re_password;
	if ( password == re_password )
	{
		cout << "          CREATE ACCOUNT (Yes/No) : " ;
		cin >> answer;
		if (answer == yes1 || answer == yes2 || answer == yes3)
		{
			energy = 30 ; coins = 5000 ; 
			ofstream signup;
			signup.open( username.c_str() );
			signup << username << ' ' << password << ' ' << first_name << ' ' << last_name << ' '<< magic_word << ' '<< coins << ' ' << energy ;
			signup.close();
			ofstream db;
			db.open("database.txt", ios::app);
			db << username << endl;
			db.close();
			sup_finish:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "          ACCOUNT HAS BEEN REGISTERED!  " << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "          USERNAME : " << username << endl ;
			cout << "          PASSWORD : " << password << endl;
			cout << "          FIRST NAME : " << first_name << endl;
			cout << "          LAST NAME : " << last_name << endl;
			cout << "          MAGIC WORD : " << magic_word << endl;
			cout << "          COINS : $" << coins << endl;
			cout << "          ENERGY : " << energy << "/30" << endl << endl;
			cout << "--------------------------------------------------------------------------------" << endl; 
			cout << "          [1] GO BACK TO HOME PAGE	" << endl;
			cout << "          [2] EXIT PROGRAM         " << endl << endl;
			cout << "--------------------------------------------------------------------------------" << endl; 
			cout << "          YOUR DESTINATION : " ;
			cin >> choice;
			switch(choice)
			{
				case 1:
					system("cls");
					return main();
					break;
				case 2:
					exit_program();
					break;
				default:
					system("cls");
					cout << endl << "--------------------------------------------------------------------------------" << endl;
					cout << "                                 INVALID INPUT                                  " << endl << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					system("cls");
					goto sup_finish;
					break;
			}
		}
		else if (answer == no1 || answer == no2 || answer == no3)
		{
			system("cls");
			prompt:
			cout << endl << "--------------------------------------------------------------------------------" << endl;	
			cout << "                                     PROMPT!                                    " << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "          [1] GO BACK TO HOME PAGE " << endl;
			cout << "          [2] CONTINUE REGISTERING " << endl;
			cout << "          [3] EXIT PROGRAM         " << endl << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "          YOUR DESTINATION : " ;
			cin >> choice ;
			switch (choice)
			{
				case 1:
					system("cls");
					return main();
					break;
				case 2:
					system("cls");
					return sign_up();
					break;
				case 3:
					exit_program();
					break;
				default:
					system("cls");
					cout << endl << "--------------------------------------------------------------------------------" << endl;
					cout << "          [INVALID INPUT] " << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					system("cls");
					goto prompt;
					break;
			}
		}
		else
		{
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "          [INVALID INPUT] " << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep (2000);
			system("cls");
			return sign_up();
		}
	}
	else
	{
		system("cls");
		cout << endl << "--------------------------------------------------------------------------------" << endl;
		cout << "          [PASSWORD DOESN'T MATCH] " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		Sleep(2000);
		system("cls");
		return sign_up();
		
	}
	
}

int failed_login()
{
	system("cls");
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "                          [WRONG USERNAME OR PASSWORD]                          " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-         [1] RETURN TO HOME PAGE                                              -" << endl;
	cout << "-         [2] EXIT PROGRAM                                                     -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          YOUR DESTINATION : " ;
	cin >> choice;
	switch(choice)
	{
		case 1:
			main();
			break;
		case 2:
			exit_program();
			break;
		default:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "                                [INVALID INPUT]                                 " << endl << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			system("cls");
			return failed_login();
			break;
	}
}

int forgot_pass()
{
	string ifirst_name , ilast_name , imagic_word , iuser;
	cout << endl<< "--------------------------------------------------------------------------------" << endl;
	cout << "                               ACCOUNT RECOVERY                                 " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          USERNAME : " ;
	cin >> iuser;
	cout << "--------------------------------------------------------------------------------" << endl;
	ifstream forgot_password;
	forgot_password.open(iuser.c_str());
	if (forgot_password.fail())
	{
		system("cls");
		cout << endl<< "--------------------------------------------------------------------------------" << endl;
		cout << "                              USERNAME NOT FOUND                                " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;				Sleep(2000);
		system("cls");
		return forgot_pass();
	}
	forgot_password >> username >> password >> first_name >> last_name >> magic_word >> coins >> energy ;
	forgot_password.close();
	system("cls");
	ac_w_user:
	cout << endl<< "--------------------------------------------------------------------------------" << endl;
	cout << "                               ACCOUNT RECOVERY                                 " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          USERNAME : " << username << endl;
	cout << "          [1] RECOVER ACCOUNT USING PERSONAL INFORMATIONS                       " << endl;
	cout << "          [2] RECOVER ACCOUNT USING USERNAME AND MAGIC WORD                     " << endl;
	cout << "          [3] GO BACK TO HOME PAGE                                              " << endl;
	cout << "          [4] EXIT PROGRAM                                                      " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          YOUR DESTINATION : ";
	cin >> choice;
	switch (choice)
	{
		case 1:
			number_one:
			system("cls");
			cout << endl<< "--------------------------------------------------------------------------------" << endl;
			cout << "                               ACCOUNT RECOVERY                                 " << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "          FIRST NAME : " ;
			cin >> ifirst_name;
			cout << "          LAST NAME : " ;
			cin >> ilast_name;
			if( ifirst_name == first_name && ilast_name == last_name )
			{
				cout << "          PASSWORD : " << password << endl;
				destination:
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "          [1] GO BACK TO HOMEPAGE " << endl;
				cout << "          [2] EXIT PROGRAM " << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "          YOUR DESTINATION : " ;
				cin >> choice;
				switch (choice)
				{
					case 1:
						system("cls");
						main();
						break;
					case 2:
						system("cls");
						exit_program();
						break;
					default:
						system("cls");
						cout << endl << "--------------------------------------------------------------------------------" << endl;
						cout << "                                 INVALID INPUT                                  " << endl << endl;
						cout << "--------------------------------------------------------------------------------" << endl;
						Sleep(2000);
						system("cls");
						goto destination;
						break;
				}
				
			}
			else
			{
				system("cls");
				cout << endl<< "--------------------------------------------------------------------------------" << endl;
				cout << "                         WRONG FIRST NAME OR LAST NAME                          " << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				goto destination;
			}
			break;
		case 2:
			number_two:
			system("cls");
			cout << endl<< "--------------------------------------------------------------------------------" << endl;
			cout << "                               ACCOUNT RECOVERY                                 " << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "          MAGIC WORD : " ;
			cin >> imagic_word;
			if ( imagic_word == magic_word )
			{
				cout << "          PASSWORD : " << password << endl;
				destination2:
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "          [1] GO BACK TO HOMEPAGE " << endl;
				cout << "          [2] EXIT PROGRAM " << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "          YOUR DESTINATION : " ;
				cin >> choice;
				switch (choice)
				{
					case 1:
						system("cls");
						main();
						break;
					case 2:
						system("cls");
						exit_program();
						break;
					default:
						system("cls");
						cout << endl << "--------------------------------------------------------------------------------" << endl;
						cout << "                                 INVALID INPUT                                  " << endl << endl;
						cout << "--------------------------------------------------------------------------------" << endl;
						Sleep(2000);
						system("cls");
						goto destination2;
						break;
	   			}
			}
			else
			{
				system("cls");
				cout << endl<< "--------------------------------------------------------------------------------" << endl;
				cout << "                               WRONG MAGIC WORD                                 " << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				goto destination2;
			}
			break;
		case 3:
			system("cls");
			return main();
			break;
		case 4:
			system("cls");
			exit_program();
			break;
		default:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "                                 INVALID INPUT                                  " << endl << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			system("cls");
			goto ac_w_user;
			break;
			
	}
}

int database()
{
	string user;
	system("cls");
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "                                 PLAYER DATABASE                                " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	//cout << "          USERS:                                                                " << endl;
	ifstream db;
	db.open("database.txt");
	if( db.fail() )
	{
		system("cls");
		cout << endl << "--------------------------------------------------------------------------------" << endl;
		cout << "                            [ERROR LOADING DATABASE]                            " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		Sleep(2000);
		system("cls");
		return main();
	}
	while ( !db.eof() )
	{
		db >> user ;
		cout << "          USERNAME : " << user << endl;
	}
	db.close();
	ddb:
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          [1] RETURN TO HOME PAGE " << endl;
	cout << "          [2] ACCOUNT INFO        " << endl;
	cout << "          [3] EXIT PROGRAM        " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          YOUR DESTINATION : " ;
	cin >> choice;
	switch (choice)
	{
		case 1:
			system("cls");
			return main();
			break;
		case 2:
			system("cls");
			account_info();
			break;
		case 3: 
			exit_program();
			break;
		default:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "                                [INVALID INPUT]                                 " << endl << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			system("cls");
			goto ddb;
			
	}
}

int account_info()
{
	system("cls");
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "                                 ACCOUNT INFO                                   " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;	
	cout << "          USERNAME : " ;
	cin >> iuser;
	cout << "          PASSWORD : " ;
	cin >> ipass;
	ifstream accountinfo;
	accountinfo.open( iuser.c_str() );
	if ( accountinfo.fail() )
	{
		system("cls");
		failed_login();
		
	}
	accountinfo >> username >> password >> first_name >> last_name >> magic_word >> coins >> energy ;
	accountinfo.close();
	if ( iuser == username && ipass == password )
	{
		system("cls");
		acc_info:
		cout << endl << "--------------------------------------------------------------------------------" << endl;
		cout << "                           ACCOUNT INFO'S MENU                                  " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;	
		cout << "          USERNAME : " << username << endl;
		cout << "          [1] YOUR ACCOUNT INFO " << endl;
		cout << "          [2] SEARCH FOR OTHER PLAYER'S ACCOUNT INFO " << endl;
		cout << "          [3] LOG-OUT IN ACCOUNT INFO " << endl;
		cout << "          [4] RETURN HOME PAGE " << endl;
		cout << "          [5] EXIT PROGRAM     " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "          YOUR DESTINATION : " ;
		cin >> choice;
		switch (choice)
		{
			case 1:
				system("cls");
				cout << endl << "--------------------------------------------------------------------------------" << endl;
				cout << "                               YOUR ACCOUNT INFO                                " << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "          USERNAME: " << username << endl;
				cout << "          FIRST NAME: " << first_name << endl;
				cout << "          LAST NAME: " << last_name << endl;
				cout << "          MAGIC WORD: " << magic_word << endl;
				cout << "          COINS: $" << coins << endl;
				cout << "          ENERGY: " << energy << "/30" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				goto acc_info;
				break;
			case 2:
				search_account();
				break;
			case 3:
				system ("cls");
				username = "" ; first_name = "" ; last_name = "" ; password = "" ; magic_word = "" ;
				coins = 0 ; energy = 0;
				return account_info();
				break;
			case 4:
				system("cls");
				main();
				break;
			case 5:
				exit_program();
				break;
			default:
				system("cls");
				cout << endl << "--------------------------------------------------------------------------------" << endl;
				cout << "                                [INVALID INPUT]                                 " << endl << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				goto acc_info;			
				break;
		}
		
	}
	else
	{
		system("cls");
		failed_login();
	}
	
}

int search_account()
{
	system("cls");
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "                             SEARCH ACCOUNT INFO                                " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          USERNAME : " ;
	cin >> iuser ;
	ifstream accinfo;
	accinfo.open( iuser.c_str() );
	if ( accinfo.fail() )
	{
		system("cls");
		w_userpass:
		cout << endl << "--------------------------------------------------------------------------------" << endl;
		cout << "                          [WRONG USERNAME OR PASSWORD]                          " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "          [1] CONTINUE SEARCHING " << endl;
		cout << "          [2] GO BACK TO ACCOUNT INFO " << endl;
		cout << "          [3] RETURN TO HOME PAGE " << endl;
		cout << "          [4] EXIT PROGRAM " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "          YOUR DESTINATION : " ;
		cin >> choice;
		switch (choice)
		{
			case 1:
				search_account();
				break;
			case 2:
				account_info();
				break;
			case 3:
				main();
				break;
			case 4:
				exit_program();
				break;
			default:
				system("cls");
				cout << endl << "--------------------------------------------------------------------------------" << endl;
				cout << "                                [INVALID INPUT]                                 " << endl << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				goto w_userpass;
				break;
		}
	}
	accinfo >> username >> password >> first_name >> last_name >> magic_word >> coins >> energy ;
	accinfo.close();
	system("cls");
	searched_acc:
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "                             SEARCHED ACCOUNT INFO                                " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          USERNAME : " << username << endl;
	cout << "          COINS : $" << coins << endl;
	cout << "          ENERGY : " << energy << "/30" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          [1] GO BACK TO ACCOUNT INFO " << endl;
	cout << "          [2] RETURN HOME PAGE " << endl;
	cout << "          [3] EXIT PROGRAM " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          YOUR DESTINATION : " ;
	cin >> choice;
	switch (choice)
	{
		case 1:
			account_info();
			break;
		case 2:
			main();
			break;
		case 3:
			exit_program();
			break;
		default:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "                                [INVALID INPUT]                                 " << endl << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			system("cls");
			goto searched_acc;
			break;
	}
}
int about_program()
{
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << " WELCOME PLAYER!                                                                " << endl;
	cout << " I HOPE YOU ARE ENJOYING YOUR TIME LOOKING THROUGH THIS PROGRAM OF MINE.        " << endl;
	cout << " I'VE STARTED CREATING THIS PROGRAM ON NOVEMBER 21 , 2018.                      " << endl;
	cout << " THIS PROGRAM WAS MADE AS A FINAL PROJECT ON MY SUBJECT CPEN.                   " << endl;
	cout << " THE PROGRAM ISN'T THAT FANCY UNLIKE THE OTHER GAMES OUT THERE ON THE MARKET,   " << endl;
	cout << " BUT I AM NONETHELESS PROUD OF THIS PROJECT AS I'VE LEARNED QUITE A LOT WHILE   " << endl;
	cout << " MAKING THIS PROJECT.                                                           " << endl << endl;
	cout << " I HOPE YOU ARE HAVING FUN PLAYING AND GOING THROUGH MY HARDWORK , AND IT WOULD " << endl;
	cout << " BE AN HONOR OF MINE IF YOU ARE INDEED HAVING FUN AS THAT WOULD MEAN THAT MY    " << endl;
	cout << " PROGRAM ISN'T ONLY A 'PROJECT' MEANT TO BE SUBMITTED FOR GRADES.               " << endl << endl;
	cout << "                     PROGRAM'S CREATOR: RAHMANI P. DIBANSA                      " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          [1] RETURN TO HOME PAGE                                               " << endl;
	cout << "          [2] EXIT PROGRAM                                                      " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          YOUR DESTINATION :                                                " ;
	cin >> choice ;
	switch (choice)
	{
		case 1:
			main();
			break;
		case 2:
			exit_program();
			break;
		default:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "                                [INVALID INPUT]                                 " << endl << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			system("cls");
			about_program();
			break;
	}
}

int exit_program()
{
	system("cls");
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "                                 EXITING PROGRAM                                " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	system("pause");
	exit(1000);
	return 0;
}

int game_menu()
{
	system("cls");
	cout << endl << "--------------------------------------------------------------------------------" << endl;	
	cout << "-                                   GAME MENU                                  -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-         [1] CONTINUE GAME                                                    -" << endl;
	cout << "-         [2] NEW GAME                                                         -" << endl;
	cout << "-         [3] ACCOUNT SETTINGS                                                 -" << endl;
	cout << "-         [4] LOG OUT                                                          -" << endl;
	cout << "-         [5] EXIT GAME                                                        -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;	
	cout << "          DESTINATION : " ;
	cin >> choice;
	switch (choice)
	{
		case 1:
			game();
			break;
		case 2:
			new_game();
			break;
		case 3:
			account_settings();
			break;
		case 4:
			log_out();
			break;
		case 5:
			exit_program();
			break;
		default:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "-                               [INVALID INPUT]                                -" << endl << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			system("cls");
			game_menu();
			break;
	}
}

int game()
{
	ofstream save_game;
	save_game.open( username.c_str() );
	save_game << username << ' ' << password << ' ' << first_name << ' ' << last_name << ' '<< magic_word << ' '<< coins << ' ' << energy ;
	save_game.close();
	system("cls");
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "          NAME : " << first_name << " " << last_name << endl;
	cout << "          COINS : $" << coins << endl;
	cout << "          ENERGY : " << energy << "/30" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;	
	cout << "-          [1] GO TO YOUR HOUSE                                                -" << endl;
	cout << "-          [2] GO TO WORK                                                      -" << endl;
	cout << "-          [3] GO TO CASINO                                                    -" << endl;
	cout << "-          [4] GO TO A RESTAURANT                                              -" << endl;
	cout << "-          [5] GO TO A COFFEE SHOP                                             -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-          [6] GAME MENU                                                       -" << endl;
	cout << "-          [7] EXIT PROGRAM                                                    -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "           WHERE DO YOU WANT TO GO : " ;
	cin >> choice;
	switch (choice)
	{
		case 1:
			system("cls");
			house();
			break;
		case 2:
			system("cls");
			if ( energy > 0)
			{
				work();
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-         PLEASE RESTORE YOUR ENERGY ABOVE ZERO TO BE ABLE TO ENTER            -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				game();
			}
			break;
		case 3:
			system("cls");
			if ( energy > 0 )
			{
				casino();
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-         PLEASE RESTORE YOUR ENERGY ABOVE ZERO TO BE ABLE TO ENTER            -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				game();
			}
			break;
		case 4:
			system("cls");
			restaurant();
			break;
		case 5:
			system("cls");
			coffee_shop();
			break;
		case 6:
			system("cls");
			game_menu();
			break;
		case 7:
			system("cls");
			exit_program();
			break;
		default:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "-                               [INVALID INPUT]                                -" << endl << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			system("cls");
			game();
			break;
	}
}

int new_game()
{
	system("cls");
	coins = 5000;
	energy = 30 ;
	ofstream new_game;
	new_game.open( username.c_str());
	new_game << username << ' ' << password << ' ' << first_name << ' ' << last_name << ' '<< magic_word << ' '<< coins << ' ' << energy ;
	new_game.close();
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "-                           GAME STATS HAS BEEN RESET                          -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	Sleep(2000);
	system("cls");
	game_menu();		
}

int account_settings()
{
	string npass , npass2 , ifirst_name , ifirst_name2 , nfirst_name , nfirst_name2 , ilast_name , ilast_name2 ;
	string imagic_word , imagic_word2 , nmagic_word , nmagic_word2 , nlast_name , nlast_name2 , ipass , ipass2 ;
	string iuser , iuser2 , nuser , nuser2 ;
	system("cls");
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "-                              ACCOUNT SETTINGS                                -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-         [1] CHANGE PASSWORD                                                  -" << endl;
	cout << "-         [2] CHANGE FIRST NAME                                                -" << endl;
	cout << "-         [3] CHANGE LAST NAME                                                 -" << endl;
	cout << "-         [4] CHANGE MAGIC WORD                                                -" << endl;
	cout << "-         [5] GAME MENU                                                        -" << endl;
	cout << "-         [6] EXIT PROGRAM                                                     -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          YOUR DESTINATION : " ;
	cin >> choice;
	switch (choice)
	{
		case 1:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "-                               CHANGE PASSWORD                                -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "          YOUR PREVIOUS PASSWORD : " ;
			cin >> ipass;
			cout << "          RE-ENTER PREVIOUS PASSWORD : " ;
			cin >> ipass2;
			if( ipass == ipass2 )
			{
				if( ipass == password )
				{
					cout << "          YOUR NEW PASSWORD : " ;
					cin >> npass;
					cout << "          RE-ENTER NEW PASSWORD : " ;
					cin >> npass2;
					if ( npass == npass2 )
					{
						password = npass;
					}
					else
					{
						system("cls");
						cout << endl << "--------------------------------------------------------------------------------" << endl;
						cout << "-                      NEW PASSWORD INPUTS DOESN'T MATCH                       -" << endl;
						cout << "--------------------------------------------------------------------------------" << endl;
						Sleep(2000);
						system("cls");
						account_settings();
					}
					
				}
				else
				{
					system("cls");
					cout << endl << "--------------------------------------------------------------------------------" << endl;
					cout << "-                      THIS ISN'T YOUR PREVIOUS PASSWORD                       -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					system("cls");
					Sleep(2000);
					account_settings();
				}
			}
			else
			{
				system("cls");
				cout << endl << "--------------------------------------------------------------------------------" << endl;
				cout << "-                   PREVIOUS PASSWORD INPUTS DOESN'T MATCH                     -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				system("cls");
				Sleep(2000);
				account_settings();	
			}
			break;
		case 2:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "-                             CHANGE FIRST NAME                                -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "          YOUR PREVIOUS FIRST NAME : " ;
			cin >> ifirst_name;
			cout << "          RE-ENTER PREVIOUS FIRST NAME : " ;
			cin >> ifirst_name2;
			if( ifirst_name == ifirst_name2 )
			{
				if( ifirst_name == first_name )
				{
					cout << "          YOUR NEW FIRST NAME : " ;
					cin >> nfirst_name;
					cout << "          RE-ENTER NEW FIRST NAME : " ;
					cin >> nfirst_name2;
					if ( nfirst_name == nfirst_name2 )
					{
						first_name = nfirst_name;
					}
					else
					{
						system("cls");
						cout << endl << "--------------------------------------------------------------------------------" << endl;
						cout << "-                    NEW FIRST NAME INPUTS DOESN'T MATCH                       -" << endl;
						cout << "--------------------------------------------------------------------------------" << endl;
						Sleep(2000);
						system("cls");
						account_settings();
					}
					
				}
				else
				{
					system("cls");
					cout << endl << "--------------------------------------------------------------------------------" << endl;
					cout << "-                    THIS ISN'T YOUR PREVIOUS FIRST NAME                       -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					system("cls");
					account_settings();
				}
			}
			else
			{
				system("cls");
				cout << endl << "--------------------------------------------------------------------------------" << endl;
				cout << "-                 PREVIOUS FIRST NAME INPUTS DOESN'T MATCH                     -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				account_settings();	
			}
			break;
		case 3:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "-                              CHANGE LAST NAME                                -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "          YOUR PREVIOUS LAST NAME : " ;
			cin >> ilast_name;
			cout << "          RE-ENTER PREVIOUS LAST NAME : " ;
			cin >> ilast_name2;
			if( ilast_name == ilast_name2 )
			{
				if( ilast_name == last_name )
				{
					cout << "          YOUR NEW LAST NAME : " ;
					cin >> nlast_name;
					cout << "          RE-ENTER NEW LAST NAME : " ;
					cin >> nlast_name2;
					if ( nlast_name == nlast_name2 )
					{
						last_name = nlast_name;
					}
					else
					{
						system("cls");
						cout << endl << "--------------------------------------------------------------------------------" << endl;
						cout << "-                     NEW LAST NAME INPUTS DOESN'T MATCH                       -" << endl;
						cout << "--------------------------------------------------------------------------------" << endl;
						Sleep(2000);
						system("cls");
						account_settings();
					}
					
				}
				else
				{
					system("cls");
					cout << endl << "--------------------------------------------------------------------------------" << endl;
					cout << "-                     THIS ISN'T YOUR PREVIOUS LAST NAME                       -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					system("cls");
					account_settings();
				}
			}
			else
			{
				system("cls");
				cout << endl << "--------------------------------------------------------------------------------" << endl;
				cout << "-                  PREVIOUS LAST NAME INPUTS DOESN'T MATCH                     -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				account_settings();	
			}
			break;
		case 4:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "-                             CHANGE MAGIC WORD                                -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "          YOUR PREVIOUS MAGIC WORD : " ;
			cin >> imagic_word;
			cout << "          RE-ENTER PREVIOUS MAGIC WORD : " ;
			cin >> imagic_word2;
			if( imagic_word == imagic_word2 )
			{
				if( imagic_word == magic_word )
				{
					cout << "          YOUR NEW MAGIC WORD : " ;
					cin >> nmagic_word;
					cout << "          RE-ENTER NEW MAGIC WORD : " ;
					cin >> nmagic_word2;
					if ( nmagic_word == nmagic_word2 )
					{
						first_name = nfirst_name;
					}
					else
					{
						system("cls");
						cout << endl << "--------------------------------------------------------------------------------" << endl;
						cout << "-                    NEW MAGIC WORD INPUTS DOESN'T MATCH                       -" << endl;
						cout << "--------------------------------------------------------------------------------" << endl;
						Sleep(2000);
						system("cls");
						account_settings();
					}
					
				}
				else
				{
					system("cls");
					cout << endl << "--------------------------------------------------------------------------------" << endl;
					cout << "-                    THIS ISN'T YOUR PREVIOUS MAGIC WORD                       -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					system("cls");
					account_settings();
				}
			}
			else
			{
				system("cls");
				cout << endl << "--------------------------------------------------------------------------------" << endl;
				cout << "-                 PREVIOUS MAGIC WORD INPUTS DOESN'T MATCH                     -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				account_settings();	
			}
			break;
		case 5:
			system("cls");
			game_menu();
			break;
		case 6:
			system("cls");
			return exit_program();
			break;
		default:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "                                [INVALID INPUT]                                 " << endl << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			system("cls");
			account_settings();
			break;
	}
	ofstream change_info;
	change_info.open( username.c_str() );
	change_info << username << ' ' << password << ' ' << first_name << ' ' << last_name << ' '<< magic_word << ' '<< coins << ' ' << energy ;
	change_info.close();
	system("cls");
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "-                     ACCOUNT INFO SUCCESSFULLY CHANGED                        -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	Sleep(2000);
	system("cls");
	account_settings();	
}

int log_out()
{
	system("cls");
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "                                   LOGGING OUT                                  " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	coins = 0 ; energy = 0 ;
	username = "" ; password = "" ; first_name = "" ; last_name = "" ; magic_word = "" ;
	Sleep(2000);
	system("cls");
	main();
}

int house()
{
	int sleep , nap , eat;
	sleep = 8; nap = 4 ; eat = 2;
	
	ofstream save_game;
	save_game.open( username.c_str() );
	save_game << username << ' ' << password << ' ' << first_name << ' ' << last_name << ' '<< magic_word << ' '<< coins << ' ' << energy ;
	save_game.close();
	system("cls");
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "          NAME : " << first_name << " " << last_name << endl;
	cout << "          COINS : $" << coins << endl;
	cout << "          ENERGY : " << energy << "/30" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                               HOME SWEET HOME                                -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-          [1] SLEEP                                                           -" << endl;
	cout << "-          [2] NAP                                                             -" << endl;
	cout << "-          [3] EAT                                                             -" << endl;
	cout << "-          [4] GO OUT OF HOUSE                                                 -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-          [5] GAME MENU                                                       -" << endl;
	cout << "-          [6] EXIT PROGRAM                                                    -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "           WHERE DO YOU WANT TO GO : " ;
	cin >> choice;
	switch (choice)
	{
		case 1:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "-                               IN A DEEP SLEEP                                -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl << endl;
			while ( sleep != 0)
			{
				Sleep(1000);
				cout << ".........." ;
				sleep--;
			}
			energy = 30 ;
			return house();
			break;
		case 2:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "-                                 TAKING A NAP                                 -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl << endl;
			while ( nap != 0)
			{
				Sleep(1000);
				cout << "...................." ;
				nap--;
			}
			if ( energy <= 10 )
			{
				energy += 10;
			}
			else if ( energy >= 25 )
			{
				energy = 30 ;
			}
			else
			{
				energy += 7 ;
			}
			return house();
			break;
		case 3:
			system ("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "-                             TAKING A QUICK SNACK                             -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl << endl;
			while ( eat != 0)
			{
				Sleep(1000);
				cout << "........................................" ;
				eat--;
			}
			coins -= 5;
			if ( energy >= 28 )
			{
				energy = 30;
			}
			else if ( energy >=20 && energy < 27 )
			{
				energy += 3;
			}
			else
			{
				energy += 2;
			}
			return house();
			break;
		case 4:
			system("cls");
			game();
			break;
		case 5:
			system("cls");
			game_menu();
			break;
		case 6:
			system("cls");
			exit_program();
			break;
		default:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "-                               [INVALID INPUT]                                -" << endl << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			system("cls");
			return house();
			break;
			
	}
}

int work()
{
	int worktime;
	ofstream save_game;
	save_game.open( username.c_str() );
	save_game << username << ' ' << password << ' ' << first_name << ' ' << last_name << ' '<< magic_word << ' '<< coins << ' ' << energy ;
	save_game.close();
	system("cls");
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "          NAME : " << first_name << " " << last_name << endl;
	cout << "          COINS : $" << coins << endl;
	cout << "          ENERGY : " << energy << "/30" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                  JOB BUILDING                                  " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          [1] BE A FREELANCE PHOTOGRAPHER                                       " << endl;
	cout << "          [2] BE A FREELANCE MUSICIAN                                           " << endl;
	cout << "          [3] HOST YOUR OWN GAMBLING PARTY (YOU NEED TO INVEST $300)            " << endl;
	cout << "          [4] INVEST IN THE STOCK MARKET (INVEST ATLEAST $700)                  " << endl;
	cout << "          [5] PRODUCE MOVIES (INVEST $2000)                                     " << endl;
	cout << "          [6] GO OUT OF JOB BUILDING                                            " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          [7] GAME MENU                                                         " << endl;
	cout << "          [8] EXIT PROGRAM                                                      " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          YOUR CHOICE : " ;
	cin >> choice;
	switch(choice)
	{
		case 1:
			system("cls");
			worktime = 5 ;
			cout << endl << endl << endl << endl ;
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "                           WORKING AS A PHOTOGRAPHER                            " << endl;
			cout << "--------------------------------------------------------------------------------" << endl << endl;
			while ( worktime != 0 )
			{
				Sleep(1000);
				cout << "================" ;
				worktime-- ;
			}
			pay = rand() % 100 + 1;
			energy--;
			break;
		case 2:
			system("cls");
			worktime =  8 ;
			cout << endl << endl << endl << endl ;
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "                              WORKING AS A MUSICIAN                             " << endl;
			cout << "--------------------------------------------------------------------------------" << endl << endl ;
			while ( worktime != 0 )
			{
				Sleep(1000);
				cout << "==========" ;
				worktime-- ;
			}
			pay = rand() % 100 + 10;
			energy--;
			break;
		case 3:
			if ( coins >= 300 )
			{
				system("cls");
				worktime = 20 ;
				cout << endl << endl << endl << endl ;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "                            HOSTING A GAMBLING PARTY                            " << endl;
				cout << "--------------------------------------------------------------------------------" << endl << endl ;
				while ( worktime != 0 )
				{
					Sleep(1000);
					cout << "====" ;
					worktime-- ;
				}
				pay = rand() % 950 ;
				energy--;
				
			}
			else
			{
				system("cls");
				cout << endl << endl << endl << endl ;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "              YOU NEED TO HAVE $300 COINS TO HOST A GAMBLING PARTY              " << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				work();
			}
			break;
		case 4:
			if ( coins >= 700 )
			{
				system("cls");
				worktime = 40 ;
				cout << endl << endl << endl << endl ;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "                         INVESTING IN THE STOCK MARKET                          " << endl;
				cout << "--------------------------------------------------------------------------------" << endl << endl ;
				while ( worktime != 0 )
				{
					Sleep(1000);
					cout << "==" ;
					worktime-- ;
				}
				pay = rand() % 3000 ;
				energy--;
				
			}
			else
			{
				system("cls");
				cout << endl << endl << endl << endl ;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "            YOU NEED TO HAVE $700 COINS TO INVEST IN THE STOCK MARKET           " << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				work();
			}
			break;
		case 5:
			if ( coins >= 2000 )
			{
				system("cls");
				worktime = 80 ;
				cout << endl << endl << endl << endl ;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "                                PRODUCING MOVIES                                " << endl;
				cout << "--------------------------------------------------------------------------------" << endl << endl ;
				while ( worktime != 0 )
				{
					Sleep(1000);
					cout << "=" ;
					worktime-- ;
					energy--;
				}
				pay = rand() % 12000  ;
				
			}
			else
			{
				system("cls");
				cout << endl << endl << endl << endl ;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "                  YOU NEED TO HAVE $2000 COINS TO PRODUCE MOVIES                " << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				work();
			}
			break;
		case 6:
			system("cls");
			game();
			break;
		case 7:
			game_menu();
			break;
		case 8:
			exit_program();
			break;
		default:
			system("cls");
			cout << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "-                               [INVALID INPUT]                                -" << endl << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			system("cls");
			work();
			break;
	}
	system("cls");
	cout << endl << endl << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                         YOU HAVE EARNED $" << pay << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	Sleep(2000);
	system("cls");
	coins += pay ;
	work();
}

int restaurant()
{
	cooldown= 8;
	system("cls");
	ofstream save_game;
	save_game.open( username.c_str() );
	save_game << username << ' ' << password << ' ' << first_name << ' ' << last_name << ' '<< magic_word << ' '<< coins << ' ' << energy ;
	save_game.close();
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "          NAME : " << first_name << " " << last_name << endl;
	cout << "          COINS : $" << coins << endl;
	cout << "          ENERGY : " << energy << "/30" << endl;
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "-                                  RESTAURANT                                  -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-    DISHES:                         ||||     DRINKS:                          -" << endl;
	cout << "-         [1] PIZZA ($20)            ||||          [6] LEMONADE ($15)           -" << endl;
	cout << "-         [2] CHICKEN WINGS ($30)    ||||          [7] WATER ($5)              -" << endl;
	cout << "-         [3] LENTIL SOUP ($50)      ||||          [8] RED WINE ($50)          -" << endl;
	cout << "-         [4] HOUSE SALAD ($15)      ||||          [9] WATER OF VITALITY ($60) -" << endl;
	cout << "-         [5] BEEF GOULASH ($55)     ||||          [10] NECTAR OF LIFE ($50)   -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                          [11] GO OUT OF RESTAURANT                             " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                             [12] GAME MENU                                     " << endl;
	cout << "                             [13] EXIT PROGRAM                                  " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          YOUR CHOICE : " ;
	cin >> choice;
	system("cls");
	cout << endl << endl << endl;
	switch (choice)
	{
		case 1:
			if ( coins > 20)
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                              JUST BOUGHT PIZZA                               -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 20;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 2:
			if ( coins > 30 )
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                           JUST BOUGHT CHICKEN WINGS                          -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 30;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 3:
			if ( coins > 50 )
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                            JUST BOUGHT LENTIL SOUP                           -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 50;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 4:
			if ( coins > 15 )
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                            JUST BOUGHT HOUSE SALAD                           -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 15;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 5:
			if ( coins > 55 )
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                            JUST BOUGHT BEEF GOULASH                          -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 55;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 6:
			if ( coins > 15 )
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                         JUST BOUGHT A GLASS OF LEMONADE                      -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 15;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 7:
			if ( coins > 5 )
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          JUST BOUGHT A GLASS OF WATER                        -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 5;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 8:
			if ( coins > 50)
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                             JUST BOUGHT RED WINE                             -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 50;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 9:
			if ( coins > 60 )
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                         JUST BOUGHT WATER OF VITALITY                        -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 50;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 10:
			if ( coins > 50 )
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          JUST BOUGHT NECTAR OF LIFE                          -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 50;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 11:
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "-                         GOING OUT OF THE RESTAURANT                          -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(1000);
			game();
			break;
		case 12:
			game_menu();
			break;
		case 13:
			return exit_program();
			break;
		default:
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "-                               [INVALID INPUT]                                -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			system("cls");
			return restaurant();
			break;	
	}
	cout << endl << endl;
	while ( cooldown != 0 )
	{
		cout << "==========" ;
		Sleep(200);
		cooldown-- ; 
	}
	system("cls");
	restaurant();
}

int coffee_shop()
{
	cooldown= 8;
	system("cls");
	ofstream save_game;
	save_game.open( username.c_str() );
	save_game << username << ' ' << password << ' ' << first_name << ' ' << last_name << ' '<< magic_word << ' '<< coins << ' ' << energy ;
	save_game.close();
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "          NAME : " << first_name << " " << last_name << endl;
	cout << "          COINS : $" << coins << endl;
	cout << "          ENERGY : " << energy << "/30" << endl;
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "-                                 COFFEE SHOP                                  -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-    MENU:                           ||||                                      -" << endl;
	cout << "-        [1] ESPRESSO ($30)          ||||       [6] CARAMEL CREME ($30)        -" << endl;
	cout << "-        [2] CAPPUCCINO  ($25)       ||||       [7] HOT CHOCOLATE ($20)        -" << endl;
	cout << "-        [3] LATTE ($35)             ||||       [8] DOLCE CREME ($20)          -" << endl;
	cout << "-        [4] CHOCOLATE CREME ($31)   ||||       [9] STEAMED APPLE JUICE ($30)  -" << endl;
	cout << "-        [5] MILK TEA ($20)          ||||       [10] VANILLA CREME ($40)       -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                          [11] GO OUT OF RESTAURANT                             " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                             [12] GAME MENU                                     " << endl;
	cout << "                             [13] EXIT PROGRAM                                  " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "          YOUR CHOICE : " ;
	cin >> choice;
	system("cls");
	cout << endl << endl << endl;
	switch (choice)
	{
		case 1:
			if ( coins > 30)
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                             JUST BOUGHT ESPRESSO                             -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 30;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 2:
			if ( coins > 25 )
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                            JUST BOUGHT CAPPUCCINO                            -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 25;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 3:
			if ( coins > 35 )
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                               JUST BOUGHT LATTE                              -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 35;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 4:
			if ( coins > 31 )
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          JUST BOUGHT CHOCOLATE CREME                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 31;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 5:
			if ( coins > 20 )
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                              JUST BOUGHT MILK TEA                            -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 20;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 6:
			if ( coins > 30 )
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                             JUST BOUGHT CARAMEL CREME                        -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 30;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 7:
			if ( coins > 20 )
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                            JUST BOUGHT HOT CHOCOLATE                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 20;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 8:
			if ( coins > 20)
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                            JUST BOUGHT DOLCE CREME                           -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 20;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 9:
			if ( coins > 30 )
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                        JUST BOUGHT STEAMED APPLE JUICE                       -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 30;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 10:
			if ( coins > 40 )
			{
				if ( energy <= 28 )
				{
				energy += 2 ;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          JUST BOUGHT VANILLA CREME                           -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				coins -= 40;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU DON'T HAVE ENOUGH COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				restaurant();
			}
			break;
		case 11:
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "-                         GOING OUT OF THE RESTAURANT                          -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(1000);
			return game();
			break;
		case 12:
			return game_menu();
			break;
		case 13:
			return exit_program();
			break;
		default:
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "-                               [INVALID INPUT]                                -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			system("cls");
			return restaurant();
			break;	
	}
	cout << endl << endl;
	while ( cooldown != 0 )
	{
		cout << "==========" ;
		Sleep(200);
		cooldown-- ; 
	}
	system("cls");
	coffee_shop();
}

int casino()
{
	system("cls");
	ofstream save_game;
	save_game.open( username.c_str() );
	save_game << username << ' ' << password << ' ' << first_name << ' ' << last_name << ' '<< magic_word << ' '<< coins << ' ' << energy ;
	save_game.close();
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "          NAME : " << first_name << " " << last_name << endl;
	cout << "          COINS : $" << coins << endl;
	cout << "          ENERGY : " << energy << "/30" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                                    CASINO                                    -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-         [1] PLAY BLACKJACK           ||          [4] PLAY SLOT MACHINE       -" << endl;
	cout << "-         [2] PLAY ROULETTE            ||          [5] PLAY GUESS THE CUP      -" << endl;
	cout << "-         [3] PLAY SCRATCH AND WIN     ||          [6] PLAY HEADS OR TAILS     -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                           [7] GO OUT OF CASINO                               -" << endl;
	cout << "-                           [8] GO HOME                                        -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                           [9] GO TO GAME MENU                                -" << endl;
	cout << "-                           [10] EXIT PROGRAM                                  -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                 YOUR CHOICE : " ;
	cin >> choice;
	switch (choice)
	{
		case 1:
			blackjack();
			break;
		case 2:
			roulette();
			break;
		case 3:
			scratch_and_win();
			break;
		case 4:
			slot_machine();
			break;
		case 5:
			guess_the_cup();
			break;
		case 6:
			heads_or_tails();
			break;
		case 7:
			game();
			break;
		case 8:
			house();
			break;
		case 9:
			game_menu();
			break;
		case 10:
			exit_program();
			break;
		default:
			system("cls");
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "-                               [INVALID INPUT]                                -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			return casino();
			break;	
	}
}

int blackjack()
{
	int dfirst_card , dsecond_card , dthird_card , dfourth_card , dealers_total;
	int yfirst_card , ysecond_card , yfourth_card , ythird_card , your_total;
	dfirst_card = 0 ; dsecond_card = 0 ; dthird_card = 0 ; dfourth_card = 0 ; 
	yfirst_card = 0 ; ysecond_card = 0 ; ythird_card = 0 ; yfourth_card = 0 ;
	int bet , total_pot , temp_bet;
	bet = 0 ; total_pot = 0 ;
	blackj:
	system("cls");
	ofstream save_game;
	save_game.open( username.c_str() );
	save_game << username << ' ' << password << ' ' << first_name << ' ' << last_name << ' '<< magic_word << ' '<< coins << ' ' << energy ;
	save_game.close();
	srand (time(0));
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "          NAME : " << first_name << " " << last_name << endl;
	cout << "          COINS : $" << coins << endl;
	cout << "          ENERGY : " << energy << "/30" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                                   BLACKJACK                                  -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-         DEALER'S CARD               ||||                                     -" << endl;
	cout << "                    FIRST CARD : " << dfirst_card << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "         YOUR CARDS                                                             " << endl;
	cout << "                    FIRST CARD : " << yfirst_card << endl;
	cout << "                    SECOND CARD : " << ysecond_card << endl;
	cout << "                    THIRD CARD : " << ythird_card << endl;
	cout << "                    FOURTH CARD : " << yfourth_card << endl;
	cout << "                    TOTAL VALUE OF CARDS : " << your_total << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                              TOTAL POT : " << total_pot << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-         [1] RAISE BET               ||||        [2] DRAW CARD                -" << endl;
	cout << "-         [3] HOLD                    ||||        [4] HIT                      -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-         [5] GO BACK TO CASINO LOUNGE ||         [6] GO OUT OF CASINO         -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-         [7] GO TO GAME MENU          ||         [8] EXIT PROGRAM             -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                 YOUR CHOICE : " ;
	cin >> choice;
	switch (choice)
	{
		case 1:
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "                       HOW MUCH WOULD YOU LIKE TO BET : ";
			cin >> bet;
			if ( coins > bet )
			{
					if ( yfirst_card == 0)
					{
						energy-- ;
					}
					temp_bet= 0 ;
					coins -= bet;
					temp_bet = bet * 2;
					total_pot += temp_bet ;
		
			}
			else
			{
				system("cls");
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU HAVE INSUFFICIENT COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				goto blackj;
			}
			break;
		case 2:
			if ( total_pot > 0 )
			{
				if ( yfirst_card == 0 && dfirst_card == 0)
				{
					yfirst_card = rand() % 11 + 1;
					dfirst_card = rand() % 11 + 1;
				
					if ( ysecond_card == 0 && dsecond_card == 0 )
					{
						ysecond_card = rand() % 11 + 1;
						dsecond_card = rand() % 11 + 1;
					}
					system("cls");
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                           YOU BOTH DREW TWO CARDS                            -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
				}
				else if ( ythird_card == 0 )
				{
					ythird_card = rand() % 11 + 1;
					system("cls");
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                           YOU DREW YOUR THIRD CARD                           -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					if ( dealers_total < 18 )
					{
						dthird_card = rand() % 11 + 1 ;
						cout << "--------------------------------------------------------------------------------" << endl;
						cout << "-                       DEALER HAS DRAWN HIS THIRD CARD!                       -" << endl;
						cout << "--------------------------------------------------------------------------------" << endl;
						Sleep(2000);
					}
					else
					{
						system("cls");
						cout << "--------------------------------------------------------------------------------" << endl;
						cout << "-                       DEALER DOESN'T WANT TO DRAW CARD                       -" << endl;
						cout << "--------------------------------------------------------------------------------" << endl;
						Sleep(2000);
						system("cls");
					}
				}
				else if ( yfourth_card == 0 )
				{
					yfourth_card = rand() % 11 + 1 ;
					system("cls");
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                           YOU DREW YOUR FOURTH CARD                          -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					if ( dealers_total < 18 )
					{
						dfourth_card = rand() % 11 + 1;
						cout << "--------------------------------------------------------------------------------" << endl;
						cout << "-                      DEALER HAS DRAWN HIS FOURTH CARD!                       -" << endl;
						cout << "--------------------------------------------------------------------------------" << endl;
						Sleep(2000);
					}
					else
					{
						system("cls");
						cout << "--------------------------------------------------------------------------------" << endl;
						cout << "-                       DEALER DOESN'T WANT TO DRAW CARD                       -" << endl;
						cout << "--------------------------------------------------------------------------------" << endl;
						Sleep(2000);
						system("cls");
					}
				}
				else
				{
					system("cls");
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                         YOU CAN NO LONGER DRAW CARD                          -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
				}
			}
			else
			{
				system("cls");
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                        THE GAME HAS NOT STARTED YET                          -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
			}
			break;
		case 3:
			if ( total_pot > 0)
			{
				system("cls");
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                            YOU HELD YOUR GROUND !                            -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				if ( dealers_total < 18 )
				{
					if ( dthird_card == 0)
					{
						dthird_card = rand() % 11 + 1 ;
						cout << "--------------------------------------------------------------------------------" << endl;
						cout << "-                       DEALER HAS DRAWN HIS THIRD CARD!                       -" << endl;
						cout << "--------------------------------------------------------------------------------" << endl;
						Sleep(2000);
					}
					else if ( dfourth_card == 0)
					{
						dfourth_card = rand() % 11 + 1;
						cout << "--------------------------------------------------------------------------------" << endl;
						cout << "-                      DEALER HAS DRAWN HIS FOURTH CARD!                       -" << endl;
						cout << "--------------------------------------------------------------------------------" << endl;
						Sleep(2000);
					}
					else
					{
						cout << "--------------------------------------------------------------------------------" << endl;
						cout << "-                        DEALER CAN NO LONGER DRAW CARD                        -" << endl;
						cout << "--------------------------------------------------------------------------------" << endl;
						Sleep(2000);
					}
				}
				else
				{
					system("cls");
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                       DEALER DOESN'T WANT TO DRAW CARD                       -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					system("cls");
				}
			}
			else 
			{
				system("cls");
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                        THE GAME HAS NOT STARTED YET                          -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
			}
			break;
		case 4:
			if ( total_pot > 0 )
			{
				if ( dealers_total > your_total )
				{
					system("cls");
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                                 DEALER WON !                                 -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-         DEALER'S CARD                                                        -" << endl;
					cout << "                    FIRST CARD : " << dfirst_card << endl;
					cout << "                    SECOND CARD : " << dsecond_card << endl;
					cout << "                    THIRD CARD : " << dthird_card << endl;
					cout << "                    FOURTH CARD : " << dfourth_card << endl;
					cout << "                    TOTAL VALUE OF CARDS : " << dealers_total << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "         YOUR CARDS                                                             " << endl;
					cout << "                    FIRST CARD : " << yfirst_card << endl;
					cout << "                    SECOND CARD : " << ysecond_card << endl;
					cout << "                    THIRD CARD : " << ythird_card << endl;
					cout << "                    FOURTH CARD : " << yfourth_card << endl;
					cout << "                    TOTAL VALUE OF CARDS : " << your_total << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(4000);
					blackjack();
				} 
				else if ( dealers_total < your_total)
				{
					system("cls");
					coins += total_pot ;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                                  YOU WON !                                   -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-         DEALER'S CARD                                                        -" << endl;
					cout << "                    FIRST CARD : " << dfirst_card << endl;
					cout << "                    SECOND CARD : " << dsecond_card << endl;
					cout << "                    THIRD CARD : " << dthird_card << endl;
					cout << "                    FOURTH CARD : " << dfourth_card << endl;
					cout << "                    TOTAL VALUE OF CARDS : " << dealers_total << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "         YOUR CARDS                                                             " << endl;
					cout << "                    FIRST CARD : " << yfirst_card << endl;
					cout << "                    SECOND CARD : " << ysecond_card << endl;
					cout << "                    THIRD CARD : " << ythird_card << endl;
					cout << "                    FOURTH CARD : " << yfourth_card << endl;
					cout << "                    TOTAL VALUE OF CARDS : " << your_total << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(4000);
					blackjack();
				}
				else
				{
					total_pot /= 2 ;
					coins += total_pot;
					system("cls");
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                                     DRAW !                                   -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-         DEALER'S CARD                                                        -" << endl;
					cout << "                    FIRST CARD : " << dfirst_card << endl;
					cout << "                    SECOND CARD : " << dsecond_card << endl;
					cout << "                    THIRD CARD : " << dthird_card << endl;
					cout << "                    FOURTH CARD : " << dfourth_card << endl;
					cout << "                    TOTAL VALUE OF CARDS : " << dealers_total << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "         YOUR CARDS                                                             " << endl;
					cout << "                    FIRST CARD : " << yfirst_card << endl;
					cout << "                    SECOND CARD : " << ysecond_card << endl;
					cout << "                    THIRD CARD : " << ythird_card << endl;
					cout << "                    FOURTH CARD : " << yfourth_card << endl;
					cout << "                    TOTAL VALUE OF CARDS : " << your_total << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(4000);
					blackjack();
				}
			}
			else 
			{
				system("cls");
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                        THE GAME HAS NOT STARTED YET                          -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
			}
			break;
		case 5:
			system("cls");
			casino();
			break;
		case 6:
			system("cls");
			game();
			break;
		case 7:
			system("cls");
			game_menu();
			break;
		case 8:
			system("cls");
			exit_program();
			break;
		default:
			system("cls");
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "-                               [INVALID INPUT]                                -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			goto blackj;
			break;
	}
	
	if ( total_pot > 0 )
	{
		your_total = yfirst_card + ysecond_card + ythird_card + yfourth_card ;
		dealers_total = dfirst_card + dsecond_card + dthird_card + dfourth_card ;
		if ( dealers_total >= 22 )
		{
			system("cls");
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "-                  YOU WON, THE DEALER'S CARDS EXCEEDED 21!                    -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			coins += total_pot ;
			Sleep(2000);
			blackjack();
		}
		if ( your_total >= 22 )
		{
			system("cls");
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "-                  YOU LOST, YOUR CARD'S VALUE EXCEEDED 21 !                   -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
		blackjack();
		}
	}
	goto blackj;
}

int roulette()
{
	system("cls");
	ofstream save_game;
	save_game.open( username.c_str() );
	save_game << username << ' ' << password << ' ' << first_name << ' ' << last_name << ' '<< magic_word << ' '<< coins << ' ' << energy ;
	save_game.close();
	srand (time(0));
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "          NAME : " << first_name << " " << last_name << endl;
	cout << "          COINS : $" << coins << endl;
	cout << "          ENERGY : " << energy << "/30" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-              ROULETTE AREA IS CURRENTLY UNDER CONSTRUCTION!                  -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	Sleep(3000);
	casino();
}

int scratch_and_win()
{
	int scratch, lucky_number , random_prize;
	system("cls");
	ofstream save_game;
	save_game.open( username.c_str() );
	save_game << username << ' ' << password << ' ' << first_name << ' ' << last_name << ' '<< magic_word << ' '<< coins << ' ' << energy ;
	save_game.close();
	srand (time(0));
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "          NAME : " << first_name << " " << last_name << endl;
	cout << "          COINS : $" << coins << endl;
	cout << "          ENERGY : " << energy << "/30" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                               SCRATCH AND WIN                                -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-          [1] BET   ($50)             ||         [2] GO TO CASINO LOUNGE      -" << endl;
	cout << "-          [3] GO OUT OF CASINO        ||         [4] GO HOME                  -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                                [5] GAME MENU                                 -" << endl;
	cout << "-                               [6] EXIT PROGRAM                               -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                                 YOUR CHOICE : ";
	cin >> choice;
	switch (choice)
	{
		case 1:
			if ( coins > 50 )
			{
				energy-- ;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-     [1]     [2]     [3]     [4]     [5]      [6]     [7]     [8]     [9]     -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                       PICK A NUMBER TO SCRATCH : " ;
				cin >> scratch;
				lucky_number = rand() % 9 + 1;
				random_prize = rand() % 10000 + 50 ;
				if ( scratch == lucky_number )
				{
					system("cls");
					cout << endl << endl << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "                              YOU HAVE WON $" << random_prize << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					coins += random_prize ;
					Sleep(3000);
					scratch_and_win();
				}
				else
				{
					system("cls");
					cout << endl << endl << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                                 YOU LOST !                                   -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					system("cls");
					scratch_and_win();
				}
			}
			else
			{
				system("cls");
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU HAVE INSUFFICIENT COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				scratch_and_win();
			}
			break;
		case 2:
			casino();
			break;
		case 3:
			game();
			break;
		case 4:
			house();
			break;
		case 5:
			game_menu();
			break;
		case 6:
			exit_program();
			break;
		default:
			system("cls");
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "-                               [INVALID INPUT]                                -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			system("cls");
			scratch_and_win();
			break;
	}
}
int slot_machine()
{
	string result1, result2, result3;
	cooldown = 8 ;
	system("cls");
	ofstream save_game;
	save_game.open( username.c_str() );
	save_game << username << ' ' << password << ' ' << first_name << ' ' << last_name << ' '<< magic_word << ' '<< coins << ' ' << energy ;
	save_game.close();
	srand (time(0));
	const string slotmachine[5] = { "Seven" , "Cherry" , "Gold" , "Silver", "BAR" } ;
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "          NAME : " << first_name << " " << last_name << endl;
	cout << "          COINS : $" << coins << endl;
	cout << "          ENERGY : " << energy << "/30" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                                 SLOT MACHINE                                 -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                        [1] START THE MACHINE                                 -" << endl;
	cout << "-                        [2] GO BACK TO CASINO LOUNGE                          -" << endl;
	cout << "-                        [3] GO OUT OF CASINO                                  -" << endl;
	cout << "-                        [4] GO HOME                                           -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                        [5] GAME MENU                                         -" << endl;
	cout << "-                        [6] EXIT PROGRAM                                      -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                        YOUR CHOICE : " ;
	cin >> choice ;
	switch (choice)
	{
		case 1:
			if ( coins > 10 )
			{
				energy--;
				coins -= 10 ;
				while ( cooldown > 0)
				{
					string result1 = slotmachine[rand() % 5];
					string result2 = slotmachine[rand() % 5];
					string result3 = slotmachine[rand() % 5];
					system("cls");
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "                                   " << result1 << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "                                   " << result2 << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "                                   " << result3 << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(200);
					cooldown-- ;
				}
				string result1 = slotmachine[rand() % 5];
				string result2 = slotmachine[rand() % 5];
				string result3 = slotmachine[rand() % 5];
				system("cls");
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "                                   " << result1 << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "                                   " << result2 << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "                                   " << result3 << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(1000);			
				if ( result1 == result2 && result2 == result3 )
				{
					coins += 2000 ;
					cout << endl << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                                   JACKPOT!                                   -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(3000);
					slot_machine();
					
				}
				else if ( ( result1 == result2 ) || ( result1 == result3 ) || ( result2 == result3 ) )
				{
					coins += 1000 ;
					cout << endl << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                                   2 PAIRS!                                   -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(3000);
					slot_machine();
				}
				else
				{
					cout << endl << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                                  NO PAIRS!                                   -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					slot_machine();
				}
			}
			else
			{
				system("cls");
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU HAVE INSUFFICIENT COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				slot_machine();
			}
			break;
		case 2:
			casino();
			break;
		case 3:
			game();
			break;
		case 4:
			house();
			break;
		case 5:
			game_menu();
			break;
		case 6:
			exit_program();
			break;
		default:
			system("cls");
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "-                               [INVALID INPUT]                                -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			slot_machine();
			break;
	}
}

int guess_the_cup()
{
	int result , cup_choice ;
	system("cls");
	ofstream save_game;
	save_game.open( username.c_str() );
	save_game << username << ' ' << password << ' ' << first_name << ' ' << last_name << ' '<< magic_word << ' '<< coins << ' ' << energy ;
	save_game.close();
	srand (time(0));
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "          NAME : " << first_name << " " << last_name << endl;
	cout << "          COINS : $" << coins << endl;
	cout << "          ENERGY : " << energy << "/30" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                                 GUESS THE CUP                                -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-          [1] 2 CUPS                  ||         [2] 3 CUPS                   -" << endl;
	cout << "-          [3] 4 CUPS                  ||         [4] 5 CUPS                   -" << endl;
	cout << "-          [5] 6 CUPS                  ||         [6] 7 CUPS                   -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                           [7] GO TO CASINO LOUNGE                            -" << endl;
	cout << "-                            [8] GO OUT OF CASINO                              -" << endl;
	cout << "-                                 [9] GO HOME                                  -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                                [10] GAME MENU                                -" << endl;
	cout << "-                              [11] EXIT PROGRAM                               -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                  YOUR CHOICE : " ;
	cin >> choice;
	cout << "--------------------------------------------------------------------------------" << endl;
	switch (choice)
	{
		case 1:
			cout << "          BET : " ;
			cin >> bet;
			if (coins > bet)
			{
				energy-- ;
				coins -= bet;
				total = bet * 2;
				result= rand() % 2;
				cup_12:
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-          [1] CUP ONE                 ||         [2] CUP TWO                  -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				cin >> cup_choice;
				if ( cup_choice == 1 || cup_choice == 2 )
				{
					system("cls");
				}
				else
				{
					system("cls");
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                               [INVALID INPUT]                                -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					system("cls");
					goto cup_12;
				}
				
			}
			else
			{
				system("cls");
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU HAVE INSUFFICIENT COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				guess_the_cup();
			}
			break;
		case 2:
			cout << "          BET : " ;
			cin >> bet;
			if (coins > bet)
			{
				energy-- ;
				coins -= bet;
				total = bet * 3;
				result= rand() % 3;
				cup_13:
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-          [1] CUP ONE                 ||         [2] CUP TWO                  -" << endl;
				cout << "-                                [3] CUP THREE                                 -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				cin >> cup_choice;
				if ( cup_choice > 0 && cup_choice < 4 )
				{
					system("cls");
				}
				else
				{
					system("cls");
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                               [INVALID INPUT]                                -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					system("cls");
					goto cup_13;
				}
				
			}
			else
			{
				system("cls");
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU HAVE INSUFFICIENT COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				guess_the_cup();
			}
			break;
		case 3:
			cout << "          BET : " ;
			cin >> bet;
			if (coins > bet)
			{
				energy-- ;
				coins -= bet;
				total = bet * 4;
				result= rand() % 4;
				cup_14:
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-          [1] CUP ONE                 ||         [2] CUP TWO                  -" << endl;
				cout << "-          [3] CUP THREE               ||         [4] CUP FOUR                 -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				cin >> cup_choice;
				if ( cup_choice > 0 && cup_choice < 5 )
				{
					system("cls");
				}
				else
				{
					system("cls");
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                               [INVALID INPUT]                                -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					system("cls");
					goto cup_14;
				}
				
			}
			else
			{
				system("cls");
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU HAVE INSUFFICIENT COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				guess_the_cup();
			}
			break;
		case 4:
			cout << "          BET : " ;
			cin >> bet;
			if (coins > bet)
			{
				energy-- ;
				coins -= bet;
				total = bet * 5;
				result= rand() % 5;
				cup_15:
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-          [1] CUP ONE                 ||         [2] CUP TWO                  -" << endl;
				cout << "-          [3] CUP THREE               ||         [4] CUP FOUR                 -" << endl;
				cout << "-                                [5] CUP FIVE                                  -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				cin >> cup_choice;
				if ( cup_choice > 0 && cup_choice < 6 )
				{
					system("cls");
				}
				else
				{
					system("cls");
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                               [INVALID INPUT]                                -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					system("cls");
					goto cup_15;
				}
				
			}
			else
			{
				system("cls");
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU HAVE INSUFFICIENT COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				guess_the_cup();
			}
			break;
		case 5:
			cout << "          BET : " ;
			cin >> bet;
			if (coins > bet)
			{
				energy-- ;
				coins -= bet;
				total = bet * 6;
				result= rand() % 6;
				cup_16:
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-          [1] CUP ONE                 ||         [2] CUP TWO                  -" << endl;
				cout << "-          [3] CUP THREE               ||         [4] CUP FOUR                 -" << endl;
				cout << "-          [5] CUP FIVE                ||         [6] CUP SIX                  -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				cin >> cup_choice;
				if ( cup_choice > 0 && cup_choice < 7 )
				{
					system("cls");
				}
				else
				{
					system("cls");
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                               [INVALID INPUT]                                -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					system("cls");
					goto cup_16;
				}
				
			}
			else
			{
				system("cls");
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU HAVE INSUFFICIENT COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				guess_the_cup();
			}
			break;
		case 6:
			cout << "          BET : " ;
			cin >> bet;
			if (coins > bet)
			{
				energy-- ;
				coins -= bet;
				total = bet * 7;
				result= rand() % 7;
				cup_17:
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-          [1] CUP ONE                 ||         [2] CUP TWO                  -" << endl;
				cout << "-          [3] CUP THREE               ||         [4] CUP FOUR                 -" << endl;
				cout << "-          [5] CUP FIVE                ||         [6] CUP SIX                  -" << endl;
				cout << "-                               [7] CUP SEVEN                                  -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				cin >> cup_choice;
				if ( cup_choice > 0 && cup_choice < 8 )
				{
					system("cls");
				}
				else
				{
					system("cls");
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                               [INVALID INPUT]                                -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					system("cls");
					goto cup_17;
				}
				
			}
			else
			{
				system("cls");
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU HAVE INSUFFICIENT COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				guess_the_cup();
			}
			break;
		case 7:
			casino();
			break;
		case 8:
			game();
			break;
		case 9:
			house();
			break;
		case 10:
			game_menu();
			break;
		case 11:
			exit_program();
			break;
		default:
			system("cls");
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "-                               [INVALID INPUT]                                -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			guess_the_cup();
			break;
	}
	
	if( result == cup_choice )
	{
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "-                                  YOU WON !                                   -" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		coins += total ;
		Sleep(2000);
		system("cls");
	}
	else
	{
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "-                                 YOU LOST !                                   -" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		Sleep(2000);
		system("cls");
	}
	return guess_the_cup();
}

int heads_or_tails()
{
	int result , ht ;
	system("cls");
	ofstream save_game;
	save_game.open( username.c_str() );
	save_game << username << ' ' << password << ' ' << first_name << ' ' << last_name << ' '<< magic_word << ' '<< coins << ' ' << energy ;
	save_game.close();
	srand (time(0));
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "          NAME : " << first_name << " " << last_name << endl;
	cout << "          COINS : $" << coins << endl;
	cout << "          ENERGY : " << energy << "/30" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                                HEADS OR TAILS                                -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-         [1] BET                      ||         [2] GO TO CASINO LOUNGE      -" << endl;
	cout << "-         [3] GO OUT OF CASINO         ||         [4] GO HOME                  -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-                             [5] GO TO GAME MENU                              -" << endl;
	cout << "-                             [6] EXIT PROGRAM                                 -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                  YOUR CHOICE : " ;
	cin >> choice;
	switch (choice)
	{
		case 1:
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "          AMOUNT OF BET : " ;
			cin >> bet;
			if ( coins > bet )
			{
				energy-- ;
				coins -= bet ;
				total = bet * 2;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-         [1] HEADS                    ||         [2] TAILS                    -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "          YOUR CHOICE : " ;
				cin >> ht;
				result = rand() % 2 + 1;
				if ( ht == result)
				{
					system("cls");
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                                  YOU WON !                                   -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					coins += total ;
					Sleep(2000);
					heads_or_tails();
				}
				else
				{
					system("cls");
					cout << "--------------------------------------------------------------------------------" << endl;
					cout << "-                                 YOU LOST !                                   -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl;
					Sleep(2000);
					heads_or_tails();
				}
			}
			else
			{
				system("cls");
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "-                          YOU HAVE INSUFFICIENT COINS                         -" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				Sleep(2000);
				system("cls");
				heads_or_tails();
			}
			break;
		case 2:
			casino();
			break;
		case 3:
			game();
			break;
		case 4:
			house();
			break;
		case 5:
			game_menu();
			break;
		case 6:
			exit_program();
			break;
		default:
			system("cls");
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "-                               [INVALID INPUT]                                -" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			heads_or_tails();
			break;
	}
	
}


