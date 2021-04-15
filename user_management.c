#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_management.h"

//creating different users depending on which type the user is
//if the user is a librarian (1) then will have type number of 1
int user_register(char *username, char *password, unsigned int type) {

  FILE * file;
  char str[50];
  char * token;
  token = (char * ) malloc(20 * sizeof(char));
  file = fopen("users.txt", "a+");
  //check if the file is created
  if (file == NULL) {
    printf("Unable to create file.\n");
    fclose(file);
    return -1;
  }

  while (fgets(str, sizeof(str), file) != NULL) {
    token = strtok(str, " ");
    //check if the username is already taken
    //if username is taken then user can't register
    if (strcmp(username, token) == 0) {
      printf("This username is registered already. Try a different username.\n");
      fclose(file);
      return -1;
    }

  }
  //prints the user's username, password and type in the file
  file = fopen("users.txt", "a+");
  fprintf(file, "%s %s %d\n", username, password, type);
  fclose(file);
  return 0;
}


int login(char *username, char *password) {

  FILE * file;
  char str[50];
  char * token;
  token = (char * ) malloc(20 * sizeof(char));

  file = fopen("users.txt", "r");
  //check if the file is exists
  if (file == NULL) {
    printf("Unable to create file.\n");
    fclose(file);
    return -2;
  }
  //read each line in a file and split the strings into fields 
  //using strtok to split the line after a space
  while (fgets(str, sizeof(str), file) != NULL) {
    token = strtok(str, " ");
    if (strcmp(username, token) == 0) {
      token = strtok(NULL, " ");
      if (strcmp(password, token) == 0) {
        token = strtok(NULL, " ");
        printf(token);
        //if the type field equal 1 (librarian) then return 1 
        if (strcmp("1\n", token) == 0){
            printf("Librarian login succesful!\n");
            fclose(file);
            return 1; 
        }  
        //if the type field equal 0 (normal user) then return 0 
        if (strcmp("0\n", token) == 0){
            printf("Login succesful!\n");
            fclose(file);
            return 0; 
        }  
      }
    }
  }
  fclose(file);
  printf("Error, please user a correct username and password!\n");
  return -1;
}


