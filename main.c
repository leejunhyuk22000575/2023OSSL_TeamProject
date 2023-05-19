#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "library.h"

int main(){
    Library *pl[100];
    Library *apply[100];
    int apply_book_num = 0;
    int book_num = 0;
    int menu;
    
    book_num = loadBookList(pl);
    apply_book_num = loadApplyBookList(apply);

  while (1){
        menu = selectMenu();
        if (menu == 0) {
            printf("醫낅즺�맖!\n");
            break;
        }
        else if(menu == 1){
            pl[book_num] = (Library *)malloc(sizeof(Library));
            newBook(pl[book_num], book_num);
            book_num++;

        }
        else if (menu == 2) {
            wholeBookList(pl, book_num);
        }
        else if (menu == 3) {
            updateBook(pl, book_num);
        }
        else if (menu == 4) {
            deleteBook(pl, book_num);
        }
        else if (menu == 5) {
            borrowBook(pl, book_num);
        }
        else if (menu == 6) {
            returnBook(pl, book_num);
        }
        else if(menu == 7){
            apply[apply_book_num] = (Library *)malloc(sizeof(Library));
            applyBook(apply[apply_book_num], apply_book_num);
            apply_book_num++;
        }
        else if(menu == 8) {
            applyList(apply, apply_book_num);
        }
        else if(menu == 9) {
            searchBook(pl, book_num);
        }
        else if(menu == 10) {
            listBookGenre(pl, book_num);
        }
        else if(menu = 11){
            saveBookList(pl, book_num);
            saveApplyBookList(apply, apply_book_num);
        }
  }
    return 0;

}
