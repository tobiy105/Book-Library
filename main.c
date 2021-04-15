#include <stdio.h>
#include "book_management.h"
#include "user_management.h"


char current_user[20];

static void login_menu() {
  FILE * file;
  int num = 0;
  do {
    //print menu
    printf("Please select one of the following options:\n");
    printf("1. Login \n");
    printf("2. Register \n");
    printf("3. Exit \n");
    scanf("%d", & num);
	switch (num) {
		//login
		case 1: {
			char * username;
			char * password;
			username = (char * ) malloc(20 * sizeof(char));
			password = (char * ) malloc(20 * sizeof(char));
			printf("Please enter your username:");
			scanf("%s", username);
			printf("Please enter your password:");
			scanf("%s", password);
			//if the user account is a librarian type account
			//then user will have access to librarian menu
			if (login(username, password) == 0) {
				strcpy(current_user, username);
       
				printf("login");
			}
			//if the user account is not a librarian type account
			//then user will have access to normal menu
			else if (login(username, password) == 1)
			{
				
        		strcpy(current_user, username);
				printf("login for librarian");
			}
			
			break;
		}

		//register users
		case 2: {
			char * username;
			char * password;
			char * librarian;
			int lib = 0;
			username = (char * ) malloc(20 * sizeof(char));
			password = (char * ) malloc(20 * sizeof(char));
			librarian = (char * ) malloc(5 * sizeof(char));
			//asking the user is a librarian
			printf("Is this user a librarian? (yes/no): ");
			scanf("%s", librarian);
			//if the user says yes then the user account will be librarian type
			if (strcmp(librarian, "yes")==0) {
				printf("Please enter your username:");
				scanf("%s", username);
				printf("Please enter your password:");
				scanf("%s", password);
				lib = 1;
				if (user_register(username, password, lib) == -1) {
					break;
				}
				
			}
			//if nthe user says no the the user account will be a normal one
			else if (strcmp(librarian, "no")==0){
				lib = 0;
				if (user_register(username, password, lib) == -1) {
					break;
				}
			}
			break;
		
		}
		//exit out of the program
		case 3: {
			break;
		}

		default:
		printf("Please enter a valid choice and try again:\n");
		break;

    }
      
    
  } while (num != 3);
  exit(0);
}

int main(){

  login_menu();
  
  return 0;
}
