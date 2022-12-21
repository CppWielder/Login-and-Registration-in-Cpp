#include<iostream>

#include "reg_auth_header.h"

int main() {
	std::cout << "**********************\n";
	std::cout << "    Authentication\n";
	std::cout << "        System\n\n";
	std::cout << "Press 1 to login.\n";
	std::cout << "Press 2 to register.\n";
	std::cout << "Press anything else \n";
	std::cout << "to quit.\n\n";
	int choice;
	std::cin >> choice;
	switch(choice) {
		case 1:
		auth_user();
		break;
		case 2:
		register_user();
		break;
		default:
		break;
	}
	std::cout << "\nThank you for using \n";
	std::cout << "our services.\n";
	return 0;
}

/*
**************************
	  Authentication
		  System

Press 1 to login.
Press 2 to register.
Press anything else 
to quit.

1

Thank you for using 
our services.
**************************
*/

/*
**************************
	  Authentication
		  System

username : **********
password : **********

**************************
*/
