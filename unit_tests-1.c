#include "./Unity/src/unity.h"
#include "book_management.h"
#include "user_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	//test for normal register
	void test_user_register(){
		FILE* file;
		file = fopen("users.txt", "w+");
		fclose(file);
		char* user;
		user=(char*)malloc(20*sizeof(char));
		strcpy(user,"User_Test");
		char* pass;
		pass=(char*)malloc(20*sizeof(char));
		strcpy(pass,"Password_Test");
		int test = user_register(user, pass, 0);
		TEST_ASSERT_EQUAL_INT (0, test);
	}	

	//test for librarian register
	void test_user_register_librarian(){
		
		FILE* file;
		file = fopen("users.txt", "w+");
		fclose(file);
		char* user;
		user=(char*)malloc(20*sizeof(char));
		strcpy(user,"Librarian_Test");
		char* pass;
		pass=(char*)malloc(20*sizeof(char));
		strcpy(pass,"Password_Test");
		int test = user_register(user, pass, 1);
		TEST_ASSERT_EQUAL_INT (0, test);
	}	

	//test for normal login
	void test_login(){
		
		FILE* file;
		file = fopen("users.txt", "w+");
		fclose(file);
		char* user;
		user=(char*)malloc(20*sizeof(char));
		strcpy(user,"User_Test");
		char* pass;
		pass=(char*)malloc(20*sizeof(char));
		strcpy(pass,"Password_Test");
		int test = user_register(user, pass, 0);
		int loginreturn = login(user,pass);
		TEST_ASSERT_EQUAL_INT (0, loginreturn);
		

	}

	//test for librarian login
	void test_admin_login(){
		
		FILE* file;
		file = fopen("users.txt", "w+");
		fclose(file);
		char* user;
		user=(char*)malloc(20*sizeof(char));
		strcpy(user,"User_Test");
		char* pass;
		pass=(char*)malloc(20*sizeof(char));
		strcpy(pass,"Password_Test");
		int test = user_register(user, pass, 1);
		int loginreturn = login(user,pass);
		TEST_ASSERT_EQUAL_INT (1, loginreturn);
		
	}

	//test for adding a book
	void test_add_book() {
		FILE * file;
  		create_book_array();
  		load_books(file);
		struct Book newbook;
        newbook.title = (char * ) malloc(60 * sizeof(char));
		newbook.title = "TEST_TITLE";
        newbook.authors = (char * ) malloc(60 * sizeof(char));
		newbook.authors = "TEST_AUTHORS";
		newbook.year = 2021;
		newbook.copies=1;
        int add = add_book(newbook);
		TEST_ASSERT_EQUAL_INT (0, add);
	}
	//test for removing a book
	void test_remove_book() {
		struct Book newbook;
        newbook.title = (char * ) malloc(60 * sizeof(char));
		newbook.title = "TEST_REMOVE_TITLE";
        newbook.authors = (char * ) malloc(60 * sizeof(char));
		newbook.authors = "TEST_REMORE_AUTHORS";
		newbook.year = 2021;
		newbook.copies=1;
        add_book(newbook);
		int remove = remove_book(newbook);
		TEST_ASSERT_EQUAL_INT (0, remove);
	}



void setUp() {
	 //this function is called before each test, it can be empty
}

void tearDown() {
	 //this function is called after each test, it can be empty
}

int main() {
	UNITY_BEGIN();

	RUN_TEST(test_user_register);
	RUN_TEST(test_user_register_librarian);
	RUN_TEST(test_login);
	RUN_TEST(test_admin_login);
	RUN_TEST(test_add_book);
	RUN_TEST(test_remove_book);?

	return UNITY_END();
}

