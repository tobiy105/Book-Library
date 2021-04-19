#include <stdio.h>
#include "book_management.h"
#include "user_management.h"

//tracks which users it is
char current_user[20];

static void login_menu() {
  
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
			//if the user account is not a librarian type account
			//then user will have access to normal menu
			if (login(username, password) == 0) {
				strcpy(current_user, username);
				menu();
			}
			//if the user account is a librarian type account
			//then user will have access to librarian menu
			else if (login(username, password) == 1)
			{	
        		strcpy(current_user, username);
				librarian_menu();
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

void menu() {
  FILE * file;
  create_book_array();
  load_books(file);		
  int num = 0;
  do {
    
    printf("Please select one of the following options:\n");
	printf("1 to log out and return to main menu\n");
    printf("2 to return a book\n");
    printf("3 to borrow a book\n");
    printf("4 to Find a book by title \n");
    printf("5 to Find a book by author\n");
    printf("6 to Find a book by year\n");

    scanf("%d", & num);

    switch (num) {

	case 1:
      {
        break;
      }	

    case 2:
      {
        char temp;
        char temp2;
        char * username;
        username = (char * ) malloc(20 * sizeof(char));
        strcpy(username, current_user);
        char title[50];
        char author[50];
        unsigned int year;
        printf("Please enter book's title:");
        scanf("%c",&temp);
        scanf("%[^\n]", title);
        
        printf("Please enter book's author:");
        scanf("%c",&temp2);
        scanf("%[^\n]", author);
        
        printf("Please enter book's year:");
        scanf("%u", & year);
        return_book(username, title, author, year);
        break;
      }

    case 3:
      {
        char temp;
        char temp2;
        char * title;
        title = (char * ) malloc(50 * sizeof(char));
        char * author;
        author = (char * ) malloc(50 * sizeof(char));
        unsigned int year;
        char * username;
        username = (char * ) malloc(20 * sizeof(char));
        strcpy(username, current_user);
        printf("Please enter book's title:");
        scanf("%c",&temp);
        scanf("%[^\n]", title);
        
        printf("Please enter book's author:");
        scanf("%c",&temp2);
        scanf("%[^\n]", author);
        
        printf("Please enter book's year:");
        scanf("%u", & year);
        borrow_book(username, title, author, year);
        break;

      }

    case 4:
      {
        char * findbooktitle;
        findbooktitle = (char * ) malloc(50 * sizeof(char));
        char temp;
        printf("Please enter book's title:");
        scanf("%c",&temp);
        scanf("%[^\n]", findbooktitle);
        

        print_books(find_book_by_title(findbooktitle));
        break;
      }

    case 5:
      {
        char * findbookauthors;
        findbookauthors = (char * ) malloc(50 * sizeof(char));
        char temp;
        printf("Please enter book's author:");
        scanf("%c",&temp);
        scanf("%[^\n]", findbookauthors);
        
        print_books(find_book_by_author(findbookauthors));
        break;
      }

    case 6:
      {
        unsigned int findbookyear;
        printf("Please enter book's year:");
        scanf("%u", & findbookyear);
        print_books(find_book_by_year(findbookyear));
        break;
      }

    default:
      printf("Please enter a valid choice and try again:\n");
      break;

    }
  } while (num != 1);

  return;
}


void librarian_menu() {
  FILE * file;
  create_book_array();
  load_books(file);	
  int num = 0;
  do {
 
    printf("Please select one of the following options:\n");
	printf("1 to log out and return to main menu\n");
    printf("2 to return a book\n");
    printf("3 to borrow a book\n");
    printf("4 to Find a book by title \n");
    printf("5 to Find a book by author\n");
    printf("6 to Find a book by year\n");
	printf("7 to add a new book\n");
    printf("8 to remove a book\n");

    scanf("%d", & num);

    switch (num) {

	case 1:
      {
        break;
      }	

    case 2:
      {
        char temp;
        char temp2;
        char * username;
        username = (char * ) malloc(20 * sizeof(char));
        strcpy(username, current_user);
        char title[50];
        char author[50];
        unsigned int year;
        printf("Please enter book's title:");
        scanf("%c",&temp);
        scanf("%[^\n]", title);
        
        printf("Please enter book's author:");
        scanf("%c",&temp2);
        scanf("%[^\n]", author);
        
        printf("Please enter book's year:");
        scanf("%u", & year);
        return_book(username, title, author, year);
        break;
      }

    case 3:
      {
        char temp;
        char temp2;
        char * title;
        title = (char * ) malloc(50 * sizeof(char));
        char * author;
        author = (char * ) malloc(50 * sizeof(char));
        unsigned int year;
        char * username;
        username = (char * ) malloc(20 * sizeof(char));
        strcpy(username, current_user);
        printf("Please enter book's title:");
        scanf("%c",&temp);
        scanf("%[^\n]", title);
        
        printf("Please enter book's author:");
        scanf("%c",&temp2);
        scanf("%[^\n]", author);
        
        printf("Please enter book's year:");
        scanf("%u", & year);
        borrow_book(username, title, author, year);
        break;

      }

    case 4:
      {
        char * findbooktitle;
        findbooktitle = (char * ) malloc(50 * sizeof(char));
        char temp;
        printf("Please enter book's title:");
        scanf("%c",&temp);
        scanf("%[^\n]", findbooktitle);
        

        print_books(find_book_by_title(findbooktitle));
        break;
      }

    case 5:
      {
        char * findbookauthors;
        findbookauthors = (char * ) malloc(50 * sizeof(char));
        char temp;
        printf("Please enter book's author:");
        scanf("%c",&temp);
        scanf("%[^\n]", findbookauthors);
        
        print_books(find_book_by_author(findbookauthors));
        break;
      }

    case 6:
      {
        unsigned int findbookyear;
        printf("Please enter book's year:");
        scanf("%u", & findbookyear);
        print_books(find_book_by_year(findbookyear));
        break;
      }

    case 7:
      {
        struct Book newbook;
        newbook.title = (char * ) malloc(60 * sizeof(char));
        newbook.authors = (char * ) malloc(60 * sizeof(char));
        char temp;
        char temp2;
        printf("Please enter book's title:");
        scanf("%c",&temp);
        scanf("%[^\n]", newbook.title);
        printf("Please enter book's author:");
        scanf("%c",&temp2);
        scanf("%[^\n]", newbook.authors);
        scanf("%c",&temp2);
        printf("Please enter book's year:");
        scanf("%u", & newbook.year);
        printf("Enter the number of copies of the title\n");
        scanf("%u", & newbook.copies);
        printf("Operation complete!\n");
        add_book(newbook);
        break;
      }

    case 8:
      {
        struct Book newbook;
        newbook.title = (char * ) malloc(60 * sizeof(char));
        newbook.authors = (char * ) malloc(60 * sizeof(char));
        char temp;
        char temp2;
        printf("Please enter book's title:");
        scanf("%c",&temp);
        scanf("%[^\n]", newbook.title);
        printf("Please enter book's author:");
        scanf("%c",&temp2);
        scanf("%[^\n]", newbook.authors);
        scanf("%c",&temp2);
        printf("Please enter book's year:");
        scanf("%u", & newbook.year);
        printf("Enter the number of copies of the title\n");
        scanf("%u", & newbook.copies);
        remove_book(newbook);
        printf("Operation complete!\n");

        break;
      }

    default:
      printf("Please enter a valid choice and try again:\n");
      break;

    }
  } while (num != 1);

  return;
}


int main(){

  login_menu();
  
  return 0;
}
