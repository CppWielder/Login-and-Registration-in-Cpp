#include<iostream>
#include<fstream>
#include<ctime>
#include<cstring>
#include<limits>

void auth_user() {
	// std::cout << "Authenticating user...\n";
	char name[20];
	std::cout << "Enter your name (20 characters limit): ";
	std::cin >> name;
	std::cin.clear();
	char passwd[10];
	std::cout << "Enter a password (10 characters limit): ";
	std::cin >> passwd;
	int lPasswd = strlen(passwd);
	char fileName[35];
	int k = 0;
	// i = 6; j = 6; k = 12;
	// a6k5s4h3a2t1
	/* a6k5s4h3a2t1 */
	// akshat
	// 123456
	int i,j;
	for(i = 0,j = 0;(name[i]!='\0')||(passwd[j]!='\0');) {
		if(name[i] == '\0') {
		    fileName[k] = passwd[lPasswd- j - 1];
		    j++;
		    k++;
		}
		if(!((name[i]!='\0')||(passwd[j]!='\0'))) {
		    break;
		}
		if(passwd[j] == '\0') {
		    fileName[k] = name[i];
		    i++;
		    k++;
		}
		if((name[i]!='\0')&&(passwd[j]!='\0')) {
		    if(k % 2 == 0) {
		        fileName[k] = name[i];
		        i++;
		    }
		    else {
		        fileName[k] = passwd[lPasswd- j - 1];
		        j++;
		    }
		    k++;
		}
	}
	fileName[k] = '.';
	k++;
	fileName[k] = 't';
	k++;
	fileName[k] = 'x';
	k++;
	fileName[k] = 't';
	k++;
	fileName[k] = '\0';
	std::cout << fileName << std::endl;
	char path[46] = "./database/";
	strcat(path,fileName);
	std::ifstream userfile_check;
	userfile_check.open(path);
	if(!userfile_check) {
		std::cout << "Sorry, invalid username or password.\n";
		userfile_check.close();
		return;
	}
	else {
		char choice;
		std::cout << "\nWelcome to your blog.\n\n";
		std::cout << "Do you want to read your blogs or write a new blog?(R for read, W for write) : ";
		std::cin >> choice;
		if(choice == 'R') {
			std::cout << std::endl;
			char c;
			while(!userfile_check.eof()) {
				userfile_check.get(c);
				std::cout << c;
			}
			userfile_check.close();
		}
		if(choice == 'W') {
			std::ofstream userfile_write;
			userfile_write.open(path,std::ios::app);
			time_t current_time = time(NULL);
			userfile_write << "\nEntry of " << ctime(&current_time) << std::endl;
			std::cout << "\nEntry of " << ctime(&current_time) << std::endl;
			std::string line;
			while(true) {
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(std::cin,line);
				userfile_write << line << '\n';
				std::cout << "\nNext line?(Y for next line) : ";
				char c;
				std::cin >> c;
				std::cout << '\n';
				if(c == 'Y') {
					continue;
				}
				else {
					break;
				}
			}
		}
	}
}

void register_user() {
	// std::cout << "Registering user...\n";
	char name[20];
	std::cout << "Enter your name (20 characters limit): ";
	std::cin >> name;
	std::cin.clear();
	char passwd[10];
	std::cout << "Enter a password (10 characters limit): ";
	std::cin >> passwd;
	int lPasswd = strlen(passwd);
	char fileName[35];
	int k = 0;
	// i = 6; j = 6; k = 12;
	// a6k5s4h3a2t1
	/* a6k5s4h3a2t1 */
	// akshat
	// 123456
	int i,j;
	for(i = 0,j = 0;(name[i]!='\0')||(passwd[j]!='\0');) {
		if(name[i] == '\0') {
		    fileName[k] = passwd[lPasswd- j - 1];
		    j++;
		    k++;
		}
		if(!((name[i]!='\0')||(passwd[j]!='\0'))) {
		    break;
		}
		if(passwd[j] == '\0') {
		    fileName[k] = name[i];
		    i++;
		    k++;
		}
		if((name[i]!='\0')&&(passwd[j]!='\0')) {
		    if(k % 2 == 0) {
		        fileName[k] = name[i];
		        i++;
		    }
		    else {
		        fileName[k] = passwd[lPasswd- j - 1];
		        j++;
		    }
		    k++;
		}
	}
	fileName[k] = '.';
	k++;
	fileName[k] = 't';
	k++;
	fileName[k] = 'x';
	k++;
	fileName[k] = 't';
	k++;
	fileName[k] = '\0';
	std::cout << fileName << std::endl;
	char path[46] = "./database/";
	strcat(path,fileName);
	std::ifstream userfile_check;
	userfile_check.open(path);
	if(userfile_check) {
		userfile_check.close();
		return;
	}
	userfile_check.close();
	std::ofstream userfile;
	userfile.open(path,std::ios::app);
	time_t current_time = time(NULL);
	userfile << "Entry of " << ctime(&current_time) << std::endl;
	std::cout << "\nEntry of " << ctime(&current_time) << std::endl;
	std::string line;
	while(true) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin,line);
		userfile << line << '\n';
		std::cout << "\nNext line?(Y for next line) : ";
		char c;
		std::cin >> c;
		std::cout << '\n';
		if(c == 'Y') {
			continue;
		}
		else {
			break;
		}
	}
	userfile << '\n';
	userfile.close();
}
