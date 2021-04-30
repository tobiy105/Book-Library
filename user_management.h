#ifndef USER_H
#define USER_H

struct user
{
    char *username;
    char *password;
    unsigned int type;
};

int user_register(char *username, char *password, unsigned int type);
/*
This function opens a a text file called "userandpass" 
standard c function, fopen, in the mode a.
The file then prints the a username while leaving a space for the next function
user_register_password to place in the password. This allows the username(and password)
to printed into the text file in one line with a space sepearting between the username and password.
returns 0 on succesful operation.s
*/


/*
This function is extremely similar to the previous function, user_register_username except
it stores in a password after the space.
*/

//int user_login(char *username, char *password)

int login(char *username, char *password);



#endif
