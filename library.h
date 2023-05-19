#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
char bookName[20];
int code;           //도서관에 저장된 책의 고유번호
char genre[20];
char borrowStatus[10];
}Library;

int selectMenu();
void newBook(Library* L, int codeNum);
void wholeBookList(Library *L[], int num);
void updateBook(Library *L[], int num);
void deleteBook(Library *L[], int num);
void borrowBook(Library *L[], int num);
void returnBook(Library *L[], int num);
void applyBook(Library *apply, int applyCodeNum);
void applyList(Library *apply[], int num);
void searchBook(Library *L[], int num);
void showSearchBook(Library L);
void listBookGenre(Library *L[], int num);
void listGenre(Library L);

