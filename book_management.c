#include "book_management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern struct BookArray library_books;

int store_books(FILE * file){
    
    file = fopen("books.txt","w+");
    if(file == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        fclose(file);
        return -1;
    }
    else{
        for(int i =0; i< library_books.length;i++)
        {
            fprintf(file, "%s|%s|%u|%u\n",library_books.array[i].title,library_books.array[i].authors,library_books.array[i].year,library_books.array[i].copies);
        }
        fclose(file);
        return 0;
    }
    
    
}

int load_books(FILE * file){
  library_books.array = (struct Book * ) malloc(100 * sizeof(struct Book));
  for (int i = 0; i < 100; i++) {
    library_books.array[i].title = (char * ) malloc(50 * sizeof(char));
    library_books.array[i].authors = (char * ) malloc(50 * sizeof(char));

  }
  library_books.length = 0;
  file = fopen("books.txt", "a+");
  fclose(file);
  file = fopen("books.txt", "r");
  if (file == NULL) {
    /* File not created hence exit */
    printf("Unable to create file.\n");
    fclose(file);
    return -1;

  }
  char * token;
  token = (char * ) malloc(50 * sizeof(char));
  char str[100];
  while (fgets(str, sizeof(str), file) != NULL) {
    token = strtok(str, "|");
    strcpy(library_books.array[library_books.length].title, token);
    token = strtok(NULL, "|");
    strcpy(library_books.array[library_books.length].authors, token);
    token = strtok(NULL, "|");
    library_books.array[library_books.length].year = atoi(token);
    token = strtok(NULL, "|");
    library_books.array[library_books.length].copies = atoi(token);
    library_books.length++;
  }
  return 0;

}

int add_book(struct Book book){
  FILE * file;  
  library_books.array[library_books.length] = book;
  library_books.length = library_books.length + 1;
  
  store_books(file);
  return 0;
    
}
int remove_book(struct Book book){
  FILE * file;
  
  for (int i = 0; i < library_books.length; i++) {
    if (strcmp(book.title, library_books.array[i].title) == 0) {
        if (strcmp(book.authors, library_books.array[i].authors) == 0) {
            if (book.year == library_books.array[i].year) {
                library_books.array[i] = library_books.array[i + 1];
                for(int j=i; j<library_books.length; j++){
                  library_books.array[j] = library_books.array[j + 1];
                }
                library_books.length--;
                store_books(file);
                return 0;
            }
        }
    
      
    }
  }
  
  
  printf("Error:  Could not find book\n Please check you have typed the book's details correctly!\n");
  return -1;

  
}

struct BookArray find_book_by_title (const char *title){
  struct BookArray titles;
  titles.array = (struct Book * ) malloc(sizeof(library_books));
  titles.length = 0;

  for (int i = 0; i < library_books.length; i++) {
    if (strcmp(title, library_books.array[i].title) == 0) {
      titles.array[i].title = (char * ) malloc(50 * sizeof(char));
      titles.array[i].authors = (char * ) malloc(50 * sizeof(char));
      titles.array[titles.length++] = library_books.array[i];
    }
  }
  if (titles.length == 0) {
    printf("The book you have searched for can't be found\n Please check you have typed the book's details correctly!\n");
    titles.array = NULL;

  } 
  else {
    printf("Matching books found!\n");
  }
  return titles;
}

struct BookArray find_book_by_author (const char *author){
  struct BookArray authors;
  authors.array = (struct Book * ) malloc(sizeof(library_books));
  authors.length = 0;

  for (int i = 0; i < library_books.length; i++) {
    if (strcmp(author, library_books.array[i].authors) == 0) {
      authors.array[i].title = (char * ) malloc(50 * sizeof(char));
      authors.array[i].authors = (char * ) malloc(50 * sizeof(char));
      authors.array[authors.length++] = library_books.array[i];
    }
  }
  if (authors.length == 0) {
    printf("The book you have searched for can't be found\n Please check you have typed the book's details correctly!\n");
    authors.array = NULL;

  } else {
    printf("Matching books found!\n");
  }
  return authors;
}

struct BookArray find_book_by_year (unsigned int year){
  struct BookArray date_year;
  date_year.array = (struct Book * ) malloc(sizeof(library_books));
  date_year.length = 0;

  for (int i = 0; i < library_books.length; i++) {
    if (year == library_books.array[i].year) {
      date_year.array[i].title = (char * ) malloc(50 * sizeof(char));
      date_year.array[i].authors = (char * ) malloc(50 * sizeof(char));
      date_year.array[date_year.length++] = library_books.array[i];
    }
  }
  if (date_year.length == 0) {
    printf("The book you have searched for can't be found\n Please check you have typed the book's details correctly!\n");
    date_year.array = NULL;

  } else {
    printf("Matching books found!\n");
  }
  return date_year;
}


int print_books(struct BookArray printbook) {
  if (printbook.length != 0) {
    for (int i = 0; i < printbook.length; i++) {
      printf("Title:  %s   Authors:  %s   Publication Year:  %u   Number of copies:  %u\n", printbook.array[i].title, printbook.array[i].authors, printbook.array[i].year, printbook.array[i].copies);
    }
    return 0;
  } 
  else {
    return -1;
  }
}

int borrow_book(char * username, char * title, char * author, unsigned int year) {
  FILE * file;
  file = fopen("loans.txt", "a+");
  if (file == NULL) {
    printf("Unable to create file.\n");
    fclose(file);
    return -1;
  }
  

  for (int i = 0; i < library_books.length; i++) {
    if (strcmp(title, library_books.array[i].title) == 0) {
      if (strcmp(author, library_books.array[i].authors) == 0) {
        if (year == library_books.array[i].year) {
          if (library_books.array[i].copies > 0) {
            
            fprintf(file, "%s|%s|%s|%u\n", username, title, author, year);
            library_books.array[i].copies--;
            store_books(file);
            printf("You (%s) have sucessfully borrowed a copy of following book:\n Titled %s, written by %s, published on %i.\n", username, title, author, year);
            fclose(file);
            
            return 0;
          }
        }
      }
    }
  }

  
  printf("Borrowing unsuccessful! .\n");
  printf("This was either because the book has run out of copies or.\n");
  printf("you did not enter the title, authors or dates in correctly.\n");
  
  return -2;
  

}
//split this function
int return_book(char * username, char * title, char * author, unsigned int year) {

  int copy = 0;
  int pass = 0;
  int correct = 0;
  FILE * file;
  file = fopen("loans.txt", "r");
  if (file == NULL) {
    printf("Unable to create file.\n");
    fclose(file);
    return -3;
  }

  FILE * filetwo;

  filetwo = fopen("new.txt", "w+");
  if (file == NULL) {
    printf("Unable to create file.\n");
    fclose(file);
    return -2;
  }

  for (int x = 0; x < library_books.length; x++) {
    if (strcmp(title, library_books.array[x].title) == 0) {
      if (strcmp(author, library_books.array[x].authors) == 0) {
        if (year == library_books.array[x].year) {
          
          pass = 1;
        }
      }
    }
  }
  if(pass==0){
    printf("Returning book unsuccessful! .\n");
    printf("This was either because the you don't currently have the book in order to return or\n");
    printf("you did not enter the title, authors or dates in correctly.\n");
    return -4;
  }
  char user[20];
  char tit[50];
  char aut[50];
  unsigned int yr = 0;
  char * token = (char * ) malloc(50 * sizeof(char));
  char str[100];
  while (fgets(str, sizeof(str), file) != NULL) {
    token = strtok(str, "|");
    strcpy(user, token);
    token = strtok(NULL, "|");
    strcpy(tit, token);
    token = strtok(NULL, "|");
    strcpy(aut, token);
    token = strtok(NULL, "|");
    yr = atoi(token);

    if (strcmp(username, user) == 0 && strcmp(title, tit) == 0 &&
      strcmp(author, aut) == 0 && year == yr && copy == 0) {
      copy = copy + 1;
    } 
    else {
      fprintf(filetwo, "%s|%s|%s|%u\n", user, tit, aut, yr);
    }
  }
  fclose(filetwo);

  for (int i = 0; i < library_books.length; i++) {
    if (strcmp(title, library_books.array[i].title) == 0) {
      if (strcmp(author, library_books.array[i].authors) == 0) {
        if (year == library_books.array[i].year) {
          copy = i;
          library_books.array[i].copies++;
          store_books(file);
          fclose(file);
          remove("loans.txt");
          rename("new.txt", "loans.txt");
          printf("Returning book was sucessful\n");
          return 0;

        }
      }
    }
  }

  
  printf("Error: unable to handle files correctly");
  return -1;
  

}