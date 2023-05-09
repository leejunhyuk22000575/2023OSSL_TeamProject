#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
char bookName[20];
int code;           //도서관에 저장된 책의 고유번호
char genre;
}Library;

int selectMenu();
void newBook(Library* L){};
void wholeBookList(Library *L[], int num);
int main(){
    Library *pl[100];
    int book_num = 0;
    int menu;


    while (1){
        menu = selectMenu();
        if (menu == 0) {
          printf("종료됨!\n");
          break;}
        else if(menu == 1){
            pl[book_num] = (Library *)malloc(sizeof(Library));
            newBook(pl[book_num]);
            book_num++;
        }
        else if (menu == 2) {
            wholeBookList(pl, book_num);
        }
    }
}

int selectMenu(){
    int menu;
    printf("\n****** 푸른초장 도서관 ******\n");
    printf("1. 책 추가 \n");
    printf("2. 도서관 책 조회 \n");
    printf("3. 도서관 책 정보 수정 \n");
    printf("4. 책 삭제 \n");
    printf("5. 책 대여 \n");
    printf("6. 책 반납 \n");
    printf("7. 원하는 책 신청 \n");
    printf("8. 책 검색 \n");
    printf("9. 장르별 책 조회 \n");
    printf("0. 종료 \n");
    printf("\n => 원하시는 메뉴가 무엇인가요? ");
    scanf("%d", &menu);
    return menu;
}
void newBook(Library* L){
    printf("\n***************************************\n");
    printf("도서관에 새로 추가하실 책의 정보를 입력해주세요\n");
    printf("책의 이름은?");
    scanf("%s", L->bookName);
    printf("책의 고유번호은?");
    scanf("%d", &L->code);
    printf("책의 장르는?");
    scanf("%s", L->genre);
}
void wholeBookList(Library *L[], int num){
  int a = 1;
    printf("********** 책 리스트 ***********\n");
  for(int i=0; i<num; i++){
    if(L[i]->code=='\0') continue;
        printf("%d", a++);
    printf("%s %d %s", L[i]->bookName, L[i]->code, L[i]->genre);
  }
}
