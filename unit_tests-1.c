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
	
	

	return UNITY_END();
}

