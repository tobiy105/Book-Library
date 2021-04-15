#ifndef USER_H
#define USER_H

struct user
{
    char *username;
    char *password;
    unsigned int type;
};
//saves the database of users in the specified file
//returns 0 if users were stored correctly, or an error code otherwise
int user_register(char *username, char *password, unsigned int type);

// logs user into system
//returns 0 if its a normal user, return 1 if its a libraian user,else error code
int login(char *username, char *password);



#endif
