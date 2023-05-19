#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "library.h"

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
    printf("8. 책 신청 리스트 조회\n");
    printf("9. 책 검색 \n");
    printf("10. 장르별 책 조회 \n");
    printf("11. 파일저장\n");
    printf("0. 종료 \n");
    printf("\n => 원하시는 메뉴가 무엇인가요? ");
    scanf("%d", &menu);
    return menu;
}
void newBook(Library* L, int codeNum){
    char status[20] = "대여가능";
    printf("\n***************************************\n");
    printf("도서관에 새로 추가하실 책의 정보를 입력해주세요\n");
    printf("책의 이름은? : ");
    scanf("%s", L->bookName);
    printf("책의 장르는?(역사, 문학, 자연과학, 경제, 종교, 사회과학, 철학, 언어, 예술, 교육) : ");
    scanf("%s", L->genre);
    codeNum++;
    L->code = codeNum;
    strcpy(L->borrowStatus, status);
}
void wholeBookList(Library *L[], int num){
    int a = 1;
    printf("\n----------------------------------\n");  
    printf("고유코드  책 이름(장르 : / 대여가능여부)\n");
    printf("----------------------------------\n");
    for(int i=0; i<num; i++){
    if(L[i]->code=='\0') continue;
    printf("   %d      %s(장르 : %s / %s)\n", L[i]->code, L[i]->bookName, L[i]->genre, L[i]->borrowStatus);
  }
}
void updateBook(Library *L[], int num){
    int code_to_update;
    wholeBookList(L, num);
    printf("\n수정하고 싶은 책의 고유번호를 입력하세요: ");
    scanf("%d", &code_to_update);

    for(int i=0; i<num; i++){
        if(L[i]->code == code_to_update){
            printf("\n**************************************\n");
            printf("수정하실 책의 정보를 입력해주세요\n");
            printf("책의 이름은? : ");
            scanf("%s", L[i]->bookName);
            printf("책의 장르는?(역사, 문학, 자연과학, 경제, 종교, 사회과학, 철학, 언어, 예술, 교육) : ");
            scanf("%s", L[i]->genre);
            printf("책의 정보가 수정되었습니다.\n");
            break;
        }
    }
}

void deleteBook(Library *L[], int num) {
    int code_to_delete;
    wholeBookList(L, num);
    printf("\n삭제하고 싶은 책의 고유번호를 입력하세요: ");
    scanf("%d", &code_to_delete);
    for(int i=0; i<num; i++){
        if(code_to_delete==L[i]->code){
            L[i]->code = '\0';
            printf("\n책이 삭제되었습니다.\n");
            return;
        }
    }
    printf("\n해당 고유번호를 가진 책을 찾을 수 없습니다.\n");
}
void borrowBook(Library *L[], int num){
    int borrowBookCode;
    char status[20] = "대여불가능";
    wholeBookList(L, num);
    while(1){
    printf("\n빌리고 싶은 책의 고유번호를 입력하세요: ");
    scanf("%d", &borrowBookCode);
    for(int i=0; i<num; i++){
        if(strcmp(L[i]->borrowStatus, "대여가능")==0){
        if(L[i]->code==borrowBookCode) {
            strcpy(L[i]->borrowStatus, status);
            printf("\n대여 완료되었습니다.\n");
            return;
        }
        }
    }
    printf("\n이미 대여된 책입니다. 다른 책을 골라주세요.\n");
    wholeBookList(L, num);
    }
}
void returnBook(Library *L[], int num){
    int returnBookCode;
    char status[20] = "대여가능";
    wholeBookList(L, num);
    while(1){
    printf("\n반납할 책의 고유번호를 입력하세요: ");
    scanf("%d", &returnBookCode);
    for(int i=0; i<num; i++){
        if(strcmp(L[i]->borrowStatus, "대여불가능")==0){
        if(L[i]->code==returnBookCode){
            strcpy(L[i]->borrowStatus, status);
            printf("\n반납 완료되었습니다.\n");
            return;
        }
        }
    }
    printf("\n이미 반납되어진 책입니다. 다시 골라주세요.\n");
    wholeBookList(L, num);
    }
}
void applyBook(Library *apply, int applyCodeNum){
    printf("\n푸른 초장 도서관에 새로 들어왔으면 하는 책을 신청해주세요.\n");
    printf("\n신청하는 책의 이름은? : ");
    scanf("%s", apply->bookName);
    printf("\n책의 장르는?(역사, 문학, 자연과학, 경제, 종교, 사회과학, 철학, 언어, 예술, 교육) : ");
    scanf("%s", apply->genre);
    applyCodeNum++;
    apply->code = applyCodeNum;
}
void applyList(Library *apply[], int num){
    printf("\n----------------------------------\n");  
    printf("         신청 리스트 현황\n");
    printf("----------------------------------\n");
    for(int i=0; i<num; i++){
    printf("   %d      %s(장르 : %s)\n", apply[i]->code, apply[i]->bookName , apply[i]->genre);
  }
}
void searchBook(Library *L[], int num){
  int breakPoint=0;
  char search[20];
  printf("검색할 책의 이름은? \n");
  scanf("%s", search);

  printf("\n==================================");
  for(int i=0; i<num; i++){
    if(L[i]->code=='\0') continue;
    if(strstr(L[i]->bookName, search)){
      showSearchBook(*L[i]);
      breakPoint++;
    }
  }
  if(breakPoint==0) printf("=> \n찾으시는 책이 없습니다!");
  printf("\n");
}
void showSearchBook(Library L){
  printf("\n%s(%s)의 고유코드는 %d입니다.\n", L.bookName, L.genre, L.code);
}
void listBookGenre(Library *L[], int num){
    int breakPoint=0;
    char searchGenre[20];
    printf("조회하고 싶은 책의 장르가 무엇입니까? ");
    scanf("%s", searchGenre);

    printf("\n*******%s서적 리스트*******\n");
    for(int i=0; i<num; i++){
    if(L[i]->code=='\0') continue;
    if(strstr(L[i]->genre, searchGenre)){
      listGenre(*L[i]);
      breakPoint++;
    }
  }
  if(breakPoint==0) printf("=> \n찾으시는 책이 없습니다!");
  printf("\n");
}
void listGenre(Library L){
  printf("%d   %s\n", L.code, L.bookName);
}
void saveBookList(Library *L[], int num){
    FILE* fp = fopen("bookList.txt", "w");
    for(int i=0; i<num; i++){
    if(L[i]->code=='\0') continue;
      fprintf(fp, "%d %s %s %s\n", L[i]->code, L[i]->bookName, L[i]->genre, L[i]->borrowStatus);
    }
    fclose(fp);
}
void saveApplyBookList(Library *L[], int num){
    FILE* fp = fopen("applyBookList.txt", "w");
    for(int i=0; i<num; i++){
    if(L[i]->code=='\0') continue;
      fprintf(fp, "%d %s %s\n", L[i]->code, L[i]->bookName, L[i]->genre);
    }
    fclose(fp);
    printf("=> 저장완료!\n");
}
int loadBookList(Library *L[]){
    int count = 0;
    FILE* fp = fopen("bookList.txt", "r");
    
    while (!feof(fp)) {
        L[count] = (Library*)malloc(sizeof(Library));
        fscanf(fp, "%d %s %s %s\n", &L[count]->code, L[count]->bookName, L[count]->genre, L[count]->borrowStatus);
        count++;
      if(count>=100) break;
    }
  
    fclose(fp);
    if(L[0]->code==1) {
        return count;
    }
    else return 0;
}
int loadApplyBookList(Library *L[]){
    int count = 0;
    FILE* fp = fopen("applyBookList.txt", "r");
    
    while (!feof(fp)) {
        L[count] = (Library*)malloc(sizeof(Library));
        fscanf(fp, "%d %s %s\n", &L[count]->code, L[count]->bookName, L[count]->genre);
        count++;
      if(count>=100) break;
    }
  
    fclose(fp);
    if(L[0]->code==1) {
        return count;
    }
    else return 0;
}
