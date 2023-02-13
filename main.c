#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

//declaration global
int NB=0,NM=0;

//struct
struct books{

         int book_pages,readed_books,member_code,book_code;

         float price;

         char book_name[27] ,book_cat[14] ,book_writer[14] ,member_first_name[20],member_family_name[20];

};
struct books a[1000];


//des functions
int search_book_by_category();

int search_Book_by_name();

int search_Book();

void Available_Books();

int add_books();

int delete_book();

int search_book_by_name_of_writer();

int search_book_by_number_of_pages();

int search_book_by_price();

int search_book_by_code();

int see_a_Book();

int The_available_members();

int see_a_member();

int add_member();

int delete_member();

int borrow_a_book();

void about_us();

int buy_a_book();

int search_member();

int search_member_by_fname();

int search_member_by_lname();

int search_Member_by_code();

//main function
int main(){

    int choose,VR=0;

    refresh:system("cls");

    printf("********************************************************library*********************************************************\n");



    //show options or menu in the first page

    printf("\n\n\n\t\t\t\t\t0: The Available Books\n\n\t\t\t\t\t1: Search a Book\n\n\t\t\t\t\t2: The Members\n\n\t\t\t\t\t3: Search a Member\n\n\t\t\t\t\t4: About Us\n\n\t\t\t\t\t5: Exit\n\n");

    //to verify that the user does not enter another choose outlist

        if(VR==1){printf("you have to enter a number from the list!!\n");}

    // ask to choose a number from the menu

   printf("\t\t\t\t\tenter your choose :");
   scanf("%d",&choose);

    // verify his choose for the menu

                                switch(choose){
                                               case 0:system("cls");
                                                      Available_Books();
                                                                        break;

                                               case 1:system("cls");
                                                      search_Book();
                                                                        break;

                                               case 2:system("cls");
                                                     The_available_members();
                                                                        break;

                                               case 3:system("cls");
                                                         search_member();
                                                                        break;

                                               case 4:system("cls");
                                                      about_us();
                                                                        break;

                                               case 5:exit(1) ;

                                                                        break;

                                               default: VR=1;
                                                       goto refresh;
                                                                        break;

                                              }
getchar();}


//Available_Books
void Available_Books(){

    int choose;

    printf("\t\t\t\t\t\tAvailable_Books\n\n|N°|\t\tname\t\t||\tcat\t||\twriter\t||\tpages\t||\tprice$\t||\tcode\t|\n*****************************************************************************************************************\n");
//'for' to show the user the available books
   for(int i=1;i<=NB;i++){
                          printf("|%d°|%27s||%14s||%14s||\t%d\t||\t%.2f\t||\t%d\t|\n",i,a[i].book_name,a[i].book_cat,a[i].book_writer,a[i].book_pages,a[i].price,a[i].book_code);
                         }
//to show the user the control menu
    printf("\n\n\t\t\t\t\t_____control menu_____\n\t\t\t\t\t| 0: see the book     |\n\t\t\t\t\t| 1: add a book       |\n\t\t\t\t\t| 2: delete a book    |\n\t\t\t\t\t| 3: Back             |\n\t\t\t\t\t|_____________________|");
//ask him to enter a number from the control menu
    printf("\n enter your choose :");
    scanf("%d",&choose);
                          switch(choose){//'switch' to go where the user choos from the control menu
                                         case 0:
                                                see_a_Book();
                                                              break;
                                         case 1:system("cls");
                                                add_books();
                                                              break;
                                         case 2:delete_book();

                                                              break;
                                         case 3:main();

                                                              break;
                                        }

getchar();}




//add_books
int add_books(){
    NB++;

    int cat_choose;
    char f;

    printf("\t\t\t\t\t\t\tadd a book\n\t\t\t\t\t\t\t**********\n\n");

    printf("enter the name of the book :");
   scanf("%c",a[NB].book_name);
    scanf("%[^\n]s",a[NB].book_name);

    printf("\nthe categorie of the book :\n\t\t\t\t\t\t0: art/architecture\n\t\t\t\t\t\t1: autobiography\n\t\t\t\t\t\t2: business/economics\n\t\t\t\t\t\t3: craft/hobbies\n\t\t\t\t\t\t4: cookbook\n\t\t\t\t\t\t5: history\n\t\t\t\t\t\t6: philosophy\n\t\t\t\t\t\t7: science\n\t\t\t\t\t\t8: sports");

    options:printf("\n\t\t\tenter your choose :");
    scanf("%d",&cat_choose);
    if(cat_choose>8||cat_choose<0)
    {
        printf("enter one from this options");
        goto options;
    }

    switch(cat_choose){

    case 0:strcpy(a[NB].book_cat,"art/architect");

    break;

    case 1:strcpy(a[NB].book_cat,"autobiography");

    break;

    case 2:strcpy(a[NB].book_cat,"business/econ");

    break;

    case 3:strcpy(a[NB].book_cat,"craft/hobbies");

    break;

    case 4:strcpy(a[NB].book_cat,"cookbook     ");

    break;

    case 5:strcpy(a[NB].book_cat,"history      ");

    break;

    case 6:strcpy(a[NB].book_cat,"philosophy   ");

    break;

    case 7:strcpy(a[NB].book_cat,"science      ");

    break;

    case 8:strcpy(a[NB].book_cat,"sports       ");

    break;

    }



    printf("\nenter the author :");
scanf("%c",a[NB].book_writer);
    scanf("%[^\n]s",a[NB].book_writer);

   page: printf("\nthe pages   :");

    scanf("%d",&a[NB].book_pages);
    if(a[NB].book_pages<=49)
        {
            printf("according to UNISCO The books must be more than 49 pages!!");
           goto page;
    }

    price:printf("\nenter the price in dollar $:");
    scanf("%f",&a[NB].price);
    if(a[NB].price<=0){
        printf("\n you must enter a number positive");
        goto price;

    }



  int R;
   code:srand(time(NULL));

   R=1000+(rand()%(9000));

   for(int j=0;j<NB;j++){

    if(R==a[j].book_code)
        {
            goto code;
        }

}


a[NB].book_code=R;
       system("cls");
       Available_Books();

getchar();}



search_Book(){

    int choose;

//name|cat|writer|pages|price|code

printf("\n\n\t\t\t\t\t ___search menu by____\n\t\t\t\t\t| 0: book name        |\n\t\t\t\t\t| 1: book category    |\n\t\t\t\t\t| 2: the writer       |\n\t\t\t\t\t| 3: pages            |\n\t\t\t\t\t| 4: price            |\n\t\t\t\t\t| 5: code             |\n\t\t\t\t\t| 6: back             |\n\t\t\t\t\t|_____________________|");

printf("\n\n\n\n\n\t\t\t\t\tenter your choose :");

scanf("%d",&choose);
switch(choose){

case 0:search_Book_by_name();
break;
case 1:search_book_by_category();
break;
case 2:search_book_by_name_of_writer();
break;
case 3:search_book_by_number_of_pages();
break;
case 4:search_book_by_price();
break;
case 5:search_book_by_code();
break;
case 6:main();
break;
}

getchar();}



//search_Book_by_name
int search_Book_by_name(int f) {



    char bookname[27],verify_back;
int c=1,make_sure,K;
    printf("enter the name of the book :");
scanf("%c",bookname);
    scanf("%[^\n]s",bookname);

    system("cls");

    printf("\t\t\t\t\t\tAvailable_Books\n\n|N院|\t\tname\t\t||\tcat\t||\twriter\t||\tpages\t||\tprice$\t||\tcode\t|\n*****************************************************************************************************************\n");

    for(int i=0;i<=NB;i++){

        if(strcmp(bookname,a[i].book_name)==0){

        printf("|%d°|%27s||%14s||%14s||\t%d\t||\t%.2f\t||\t%d\t|\n",i,a[i].book_name,a[i].book_cat,a[i].book_writer,a[i].book_pages,a[i].price,a[i].book_code);
     c=0;

    }
    else if(i==NB && c!=0) {
            printf("\t\t\t\tthis book not found\n\n");
    }




    }


  if(f==0){

        f=1;}

   //control menu------------------------------------------------------------------
int x;
printf("\n\n\n\n\t\t\t\t\t\t   _____control menu_____\n\t\t\t\t\t\t   | 0: BACK             |\n\t\t\t\t\t\t   | 1: MENU             |\n\t\t\t\t\t\t   | 2: EXIT             |\n\t\t\t\t\t\t   |_____________________|");
CM:
printf("\n\t\t\t enter your choose :");
    scanf("%d",&x);
                          switch(x){//'switch' to go where the user choose from the control menu
                                         case 0:system("cls");
                                                search_Book();
                                                              break;
                                         case 1:system("cls");
                                                   main();   break;
                                         case 2:
                                                exit(0) ;
                                                              break;
                                         default:printf("\nplease add number from the choose ");
                                         goto CM;
                                         break;

    //-------------------------------------------------------------------------------
}
    return f;}


//search_book_by_category
int search_book_by_category(){

    int bookcat;

    char f[20] ,verify_back;

printf("\nthe categorie of the book :\n\t\t\t\t\t\t0: art/architecture\n\t\t\t\t\t\t1: autobiography\n\t\t\t\t\t\t2: business/economics\n\t\t\t\t\t\t3: craft/hobbies\n\t\t\t\t\t\t4: cookbook\n\t\t\t\t\t\t5: history\n\t\t\t\t\t\t6: philosophy\n\t\t\t\t\t\t7: science\n\t\t\t\t\t\t8: sports");

start_choise:printf("\n\t\t\tenter your choose :");

    scanf("%d",&bookcat);

        switch(bookcat){

    case 0:strcpy(f,"art/architect");

    break;

    case 1:strcpy(f,"autobiography");

    break;

    case 2:strcpy(f,"business/econ");

    break;

    case 3:strcpy(f,"craft/hobbies");

    break;

    case 4:strcpy(f,"cookbook     ");

    break;

    case 5:strcpy(f,"history      ");

    break;

    case 6:strcpy(f,"philosophy   ");

    break;

    case 7:strcpy(f,"science      ");

    break;

    case 8:strcpy(f,"sports       ");


    break;

    default: printf("\n\n\t\tthis number is not from the choises");
goto start_choise;
    }

system("cls");

int c=1;

    printf("\t\t\t\t\t\tAvailable_Books\n\n|N院|\t\tname\t\t||\tcat\t||\twriter\t||\tpages\t||\tprice$\t||\tcode\t|\n*****************************************************************************************************************\n");

    for(int i=0;i<=NB;i++){

        if(strcmp(f,a[i].book_cat)==0){

        printf("|%d°|%27s||%14s||%14s||\t%d\t||\t%.2f\t||\t%d\t|\n",i,a[i].book_name,a[i].book_cat,a[i].book_writer,a[i].book_pages,a[i].price,a[i].book_code);
     c=0;
    }
    else if(i==NB && c!=0) {printf("\t\t\t\tthis book not found\n\n");
    }}



             //control menu------------------------------------------------------------------
int x;
printf("\n\n\n\n\t\t\t\t\t\t   _____control menu_____\n\t\t\t\t\t\t   | 0: BACK             |\n\t\t\t\t\t\t   | 1: MENU             |\n\t\t\t\t\t\t   | 2: EXIT             |\n\t\t\t\t\t\t   |_____________________|");
CM:
printf("\n\t\t\t enter your choose :");
    scanf("%d",&x);
                          switch(x){//'switch' to go where the user choose from the control menu
                                         case 0:system("cls");
                                                search_Book();
                                                              break;
                                         case 1:system("cls");
                                                   main();   break;
                                         case 2:
                                                exit(0) ;
                                                              break;
                                         default:printf("\nplease add number from the choose ");
                                         goto CM;
                                         break;
                                        }
      //-------------------------------------------------------------------------------

  getch();}

int delete_book(){
    int code_delete,verify_delete;
     system("cls");
     printf("\t\t\t\t\t\tdelete a book\n\t\t\t\t\t\t*************\n\n\n\n");
     printf("enter the code of the book: ");
     scanf("%d",&code_delete);
for(int i=0;i<=NB;i++)
{
    if(a[i].book_code==code_delete){
  system("cls");
  printf("\t\t\t\t\t\tAvailable_Books\n\n|N院|\t\tname\t\t||\tcat\t||\twriter\t||\tpages\t||\tprice$\t||\tcode\t|\n*****************************************************************************************************************\n");
printf("| 1院%27s||%14s||%14s||\t%d\t||\t%.2f\t||\t%d\t|\n",a[i].book_name,a[i].book_cat,a[i].book_writer,a[i].book_pages,a[i].price,a[i].book_code);
printf("\n\nare you sure do you want to delete this book \n\n\t\t\t0 : yes\n\n\t\t\t1 : no");
printf("\n\n\t\t\tenter your choose: ");
scanf("%d",&verify_delete);
if(verify_delete==1){
    system("cls");
    Available_Books();
}else if(verify_delete==0)
{
    for(int j=i;j<NB;j++)
    {
        strcpy(a[j].book_name,a[j+1].book_name);
        strcpy(a[j].book_cat,a[j+1].book_cat);
        strcpy(a[j].book_writer,a[j+1].book_writer);
        a[j].book_code=a[j+1].book_code;
        a[j].book_pages=a[j+1].book_pages;
        a[j].price=a[j+1].price;
    }NB--;

        system("cls");
    Available_Books();
}
    }
}



getch();}
//search_book_by_name_of_writer
int search_book_by_name_of_writer(){


char author_name[27],verify_back;
int c=1;
    printf("enter the name of writer :");
scanf("%c",author_name);
    scanf("%[^\n]s",author_name);

    system("cls");

    printf("\t\t\t\t\t\tAvailable_Books\n\n|N院|\t\tname\t\t||\tcat\t||\twriter\t||\tpages\t||\tprice$\t||\tcode\t|\n*****************************************************************************************************************\n");

    for(int i=0;i<=NB;i++){

        if(strcmp(author_name,a[i].book_writer)==0){

        printf("|%d°|%27s||%14s||%14s||\t%d\t||\t%.2f\t||\t%d\t|\n",i,a[i].book_name,a[i].book_cat,a[i].book_writer,a[i].book_pages,a[i].price,a[i].book_code);
     c=0;
    }
    else if(i==NB && c!=0) {printf("\t\t\t\tthis book not found\n\n");
    }




    }
      //control menu------------------------------------------------------------------
int x;
printf("\n\n\n\n\t\t\t\t\t\t   _____control menu_____\n\t\t\t\t\t\t   | 0: BACK             |\n\t\t\t\t\t\t   | 1: MENU             |\n\t\t\t\t\t\t   | 2: EXIT             |\n\t\t\t\t\t\t   |_____________________|");
CM:
printf("\n\t\t\t enter your choose :");
    scanf("%d",&x);
                          switch(x){//'switch' to go where the user choose from the control menu
                                         case 0:system("cls");
                                                search_Book();
                                                              break;
                                         case 1:system("cls");
                                                   main();   break;
                                         case 2:
                                                exit(0) ;
                                                              break;
                                         default:printf("\nplease add number from the choose ");
                                         goto CM;
                                         break;
                                        }
      //-------------------------------------------------------------------------------

}

int search_book_by_number_of_pages(){

int min_page,max_page,c=1;
char verify_back;
restore_min:printf("\n\n\t\t\t\tenter the number of the pages \n\t\t\t\t\t\tMIN :");
scanf("%d",&min_page);
if(min_page<49){
    printf("\n\tThere is no book less than 49 pages");
    goto restore_min;
}
restore:printf("\n\t\t\t\t\t\tMAX :");
scanf("%d",&max_page);
if(max_page<min_page){
    printf("\n warening !! the number incorect");
    goto restore;
}

system("cls");

    printf("\t\t\t\t\t\tAvailable_Books\n\n|N院|\t\tname\t\t||\tcat\t||\twriter\t||\tpages\t||\tprice$\t||\tcode\t|\n*****************************************************************************************************************\n");

    for(int i=0;i<=NB;i++){

        if(a[i].book_pages>=min_page && a[i].book_pages<=max_page){
            printf("|%d°|%27s||%14s||%14s||\t%d\t||\t%.2f\t||\t%d\t|\n",i,a[i].book_name,a[i].book_cat,a[i].book_writer,a[i].book_pages,a[i].price,a[i].book_code);
c=0;
        }
else if(c==1 && i==NB){
    printf("\t\t\t\tthis book not found\n\n");
}}
      //control menu------------------------------------------------------------------
int x;
printf("\n\n\n\n\t\t\t\t\t\t   _____control menu_____\n\t\t\t\t\t\t   | 0: BACK             |\n\t\t\t\t\t\t   | 1: MENU             |\n\t\t\t\t\t\t   | 2: EXIT             |\n\t\t\t\t\t\t   |_____________________|");
CM:
printf("\n\t\t\t enter your choose :");
    scanf("%d",&x);
                          switch(x){//'switch' to go where the user choose from the control menu
                                         case 0:system("cls");
                                                search_Book();
                                                              break;
                                         case 1:system("cls");
                                                   main();   break;
                                         case 2:
                                                exit(0) ;
                                                              break;
                                         default:printf("\nplease add number from the choose ");
                                         goto CM;
                                         break;
                                        }
      //-------------------------------------------------------------------------------


getch();
}
int search_book_by_price(){
int min_price,max_price,c=1;
char verify_back;
restore_min:printf("\n\n\t\t\t\tenter the price \n\t\t\t\t\t\tMIN :");
scanf("%d",&min_price);
if(min_price<0){
    printf("\n\tundefined");
    goto restore_min;
}
restore:printf("\n\t\t\t\t\t\tMAX :");
scanf("%d",&max_price);
if(max_price<min_price){
    printf("\n warening !! this value incorect");
    goto restore;
}

system("cls");

    printf("\t\t\t\t\t\tAvailable_Books\n\n|N院|\t\tname\t\t||\tcat\t||\twriter\t||\tpages\t||\tprice$\t||\tcode\t|\n*****************************************************************************************************************\n");

    for(int i=0;i<=NB;i++){

        if(a[i].price>=min_price && a[i].price<=max_price){
            printf("|%d°|%27s||%14s||%14s||\t%d\t||\t%.2f\t||\t%d\t|\n",i,a[i].book_name,a[i].book_cat,a[i].book_writer,a[i].book_pages,a[i].price,a[i].book_code);
c=0;
        }
else if(c==1 && i==NB){
    printf("\t\t\t\tthere is no book with this price\n\n");
}}
      //control menu------------------------------------------------------------------
int x;
printf("\n\n\n\n\t\t\t\t\t\t   _____control menu_____\n\t\t\t\t\t\t   | 0: BACK             |\n\t\t\t\t\t\t   | 1: MENU             |\n\t\t\t\t\t\t   | 2: EXIT             |\n\t\t\t\t\t\t   |_____________________|");
CM:
printf("\n\t\t\t enter your choose :");
    scanf("%d",&x);
                          switch(x){//'switch' to go where the user choose from the control menu
                                         case 0:system("cls");
                                                search_Book();
                                                              break;
                                         case 1:system("cls");
                                                   main();   break;
                                         case 2:
                                                exit(0) ;
                                                              break;
                                         default:printf("\nplease add number from the choose ");
                                         goto CM;
                                         break;
                                        }
      //-------------------------------------------------------------------------------


getch();
}
int search_book_by_code(){
 int book_code,c=1;
 restore:printf("enter the book code: ");
 scanf("%d",&book_code);
 if(book_code<1000 || book_code>9999){
    printf(" this number does not exict !! \n");
    goto restore;
 }
 system("cls");
 printf("\t\t\t\t\t\tAvailable_Books\n\n|N院|\t\tname\t\t||\tcat\t||\twriter\t||\tpages\t||\tprice$\t||\tcode\t|\n*****************************************************************************************************************\n");

 for(int i=0;i<=NB;i++){
    if(book_code==a[i].book_code){
        printf("|%d°|%27s||%14s||%14s||\t%d\t||\t%.2f\t||\t%d\t|\n",i,a[i].book_name,a[i].book_cat,a[i].book_writer,a[i].book_pages,a[i].price,a[i].book_code);
c=0;
    }
    else if(c==1 && i==NB){
    printf("\t\t\t\tthere is no book with this code\n\n");}
 }
      //control menu------------------------------------------------------------------
int x;
printf("\n\n\n\n\t\t\t\t\t\t   _____control menu_____\n\t\t\t\t\t\t   | 0: BACK             |\n\t\t\t\t\t\t   | 1: MENU             |\n\t\t\t\t\t\t   | 2: EXIT             |\n\t\t\t\t\t\t   |_____________________|");
CM:
printf("\n\t\t\t enter your choose :");
    scanf("%d",&x);
                          switch(x){//'switch' to go where the user choose from the control menu
                                         case 0:system("cls");
                                                search_Book();
                                                              break;
                                         case 1:system("cls");
                                                   main();   break;
                                         case 2:
                                                exit(0) ;
                                                              break;
                                         default:printf("\nplease add number from the choose ");
                                         goto CM;
                                         break;
                                        }
      //-------------------------------------------------------------------------------



getch();
}
int see_a_Book(){
  int book_number;
 book_number:printf("enter the number of the book: ");
 scanf("%d",&book_number);
 if(book_number>NB || book_number==0){
    printf("this number does not exist\n");
    goto book_number;
 }
 system("cls");
 int i=book_number;
 printf("\t\t\t\t\t\tBOOK NUMBER %d\n\n\n\t\t\t\t\t book name : %s\n\n\t\t\t\t\t book category : %s \n\n\t\t\t\t\t author : %s\n\n\t\t\t\t\t pages number : %d\n\n\t\t\t\t\t book price : %.2f\n\n\t\t\t\t\t book code : %d",i,a[i].book_name,a[i].book_cat,a[i].book_writer,a[i].book_pages,a[i].price,a[i].book_code);

getchar();
}
int The_available_members(){
int choise;
system("cls");
printf("\t\t\t\t\t\tThe Members\n\n\t|N°|\t\tfirst name\t||\tfamily name\t||\tbook bundle\t||\tcode\t|\n\t*************************************************************************************************\n");
for(int i=1;i<=NM;i++){
printf("\t|%d°|\t\t%14s\t||\t%14s\t||\t%d\t\t||\t%d\t|\n",i,a[i].member_first_name,a[i].member_family_name,a[i].readed_books,a[i].member_code);

}
//to show the user the control menu
    printf("\n\n\t\t\t\t\t_____control menu_____\n\t\t\t\t\t| 0: see a member     |\n\t\t\t\t\t| 1: add a member     |\n\t\t\t\t\t| 2: delete a member  |\n\t\t\t\t\t| 3: Back             |\n\t\t\t\t\t|_____________________|");
//ask him to enter a number from the control menu
    printf("\n enter your choose :");
    scanf("%d",&choise);
                          switch(choise){//'switch' to go where the user choos from the control menu
                                         case 0:
                                                see_a_member();
                                                              break;
                                         case 1:system("cls");
                                                add_member();
                                                              break;
                                         case 2:delete_member();

                                                              break;
                                         case 3:main();

                                                              break;
                                        }
getch();
}

int add_member(){
    NM++;
printf("\t\t\t\t\t\t\tadd a member\n\t\t\t\t\t\t\t************\n\n");
printf("\n\n\t\t\t first name : ");
scanf("%c",a[NM].member_first_name);
scanf("%[^\n]s",a[NM].member_first_name);
printf("\n\n\t\t\t family name : ");
scanf("%c",a[NM].member_family_name);
scanf("%[^\n]s",a[NM].member_family_name);
a[NM].readed_books=0;

  int R;
   code:srand(time(NULL));

   R=1000+(rand()%(9000));

   for(int j=0;j<=NM;j++){

    if(R==a[j].member_code)
        {
            goto code;
        }

}
a[NM].member_code=R;
system("cls");
The_available_members();
getchar(); }

int see_a_member(){
 int the_chosen_person,from_the_menu;
choseperson:printf("\tenter the number of the person : ");
scanf("%d",&the_chosen_person);
if(the_chosen_person>NM){
    printf("this number does not exist");
    goto choseperson;
    }
system("cls");
printf("\t\t\t\t\t\tTHE MEMBER N %d \n\t\t\t\t\t\t**************",the_chosen_person);
printf("\n\n\n\n\t\t\t\t\tfirst name : %s\n\n\t\t\t\t\tfamily name : %s\n\n\t\t\t\t\tcode : %d\n\n\t\t\t\t\tthe number of books read : %d\n\n\n************************************************************************************************************************\n",a[the_chosen_person].member_first_name,a[the_chosen_person].member_family_name,a[the_chosen_person].member_code,a[the_chosen_person].readed_books);


printf("\n\n\t\t\t\t\t_____control menu_____\n\t\t\t\t\t| 0: borrow a book    |\n\t\t\t\t\t| 1: buy a book       |\n\t\t\t\t\t| 2: delete a book    |\n\t\t\t\t\t| 3: Back             |\n\t\t\t\t\t|_____________________|");
rtn:printf("\n\t\t\t\t\tenter your choise :");
scanf("%d",&from_the_menu);


switch(from_the_menu)
{
    case 0:borrow_a_book();
        break;
    case 1:buy_a_book();
        break;
    case 2:
        break;
    case 3:The_available_members();
        break;
    default:goto rtn;
}


}



int delete_member(){
       int code_delete,verify_delete;
     system("cls");
     printf("\t\t\t\t\t\tdelete a member\n\t\t\t\t\t\t***************\n\n\n\n");
     printf("enter the code of the member: ");
     scanf("%d",&code_delete);
for(int i=0;i<=NM;i++)
{
    if(a[i].member_code==code_delete){
  system("cls");
  printf("\t\t\t\t\t\tThe Members\n\n\t|N°|\t\tfirst name\t||\tfamily name\t||\tbook bundle\t||\tcode\t|\n\t*************************************************************************************************\n");
printf("\t|%d°|\t\t%14s\t||\t%14s\t||\t%d\t\t||\t%d\t|\n",i,a[i].member_first_name,a[i].member_family_name,a[i].readed_books,a[i].member_code);
printf("\n\nare you sure do you want to delete this member \n\n\t\t\t0 : yes\n\n\t\t\t1 : no");
printf("\n\n\t\t\tenter your choose: ");
scanf("%d",&verify_delete);
if(verify_delete==1){
    system("cls");
    The_available_members();
}else if(verify_delete==0)
{
    for(int j=i;j<NM;j++)
    {
        strcpy(a[j].member_first_name,a[j+1].member_first_name);
        strcpy(a[j].member_family_name,a[j+1].member_family_name);
        a[j].member_code=a[j+1].member_code;
        a[j].readed_books=a[j+1].readed_books;

    }NM--;

        system("cls");
    The_available_members();
}
    }
}



getch();}


int borrow_a_book(){
    int choose;
system("cls");
printf("\t\t\t\t\t\tborrow a book\n\t\t\t\t\t\t*************\n\n");
//name|cat|writer|pages|price|code

printf("\n\n\t\t\t\t\t ___search menu by____\n\t\t\t\t\t| 0: book name        |\n\t\t\t\t\t| 1: book category    |\n\t\t\t\t\t| 2: the writer       |\n\t\t\t\t\t| 3: pages            |\n\t\t\t\t\t| 4: price            |\n\t\t\t\t\t| 5: code             |\n\t\t\t\t\t| 6: back             |\n\t\t\t\t\t|_____________________|");

printf("\n\n\n\n\n\t\t\t\t\tenter your choose :");

scanf("%d",&choose);
int H=0;
switch(choose){

case 0:H=search_Book_by_name(H);
break;
case 1:H=search_book_by_category(H);
break;
case 2:H=search_book_by_name_of_writer(H);
break;
case 3:H=search_book_by_number_of_pages(H);
break;
case 4:H=search_book_by_price(H);
break;
case 5:H=search_book_by_code(H);
break;
case 6:main();
break;
}


getch();}

void about_us(){
printf("\n\n\n\t\t\t\t\t\t\t--LIBRARY--\n\n\t\t\t\t\t\t     UNDER SUPERVISION\n\n\t\t\t\t\t\t\tHallaci Samir\n\n\t\t\t\t\t\t\n\n\t\t\t\t\t\t      --PROGRAMMERS--\n\n\t\t\t\t\t\t    Tabbech Zine eddine\n\n\t\t\t\t\t\t        Daoud Houach\n\n\t\t\t\t\t\t       Bazemlal Amine");
int x;
printf("\n\n\n\n\t\t\t\t\t\t   _____control menu_____\n\t\t\t\t\t\t   | 0: BACK             |\n\t\t\t\t\t\t   | 1: EXIT             |\n\t\t\t\t\t\t   |_____________________|");
CM:
printf("\n\t\t\t enter your choose :");
    scanf("%d",&x);
                          switch(x){//'switch' to go where the user choose from the control menu
                                         case 0:system("cls");
                                                main();
                                                              break;
                                         case 1:
                                                exit(0) ;
                                                              break;
                                         default:printf("\nplease add number from the choose ");
                                         goto CM;
                                         break;
                                        }

}
//create a relation btw book and member
int buy_a_book(){
    int choose;
system("cls");
printf("\t\t\t\t\t\tbuy a book\n\t\t\t\t\t\t*************\n\n");
//name|cat|writer|pages|price|code

printf("\n\n\t\t\t\t\t ___search menu by____\n\t\t\t\t\t| 0: book name        |\n\t\t\t\t\t| 1: book category    |\n\t\t\t\t\t| 2: the writer       |\n\t\t\t\t\t| 3: pages            |\n\t\t\t\t\t| 4: price            |\n\t\t\t\t\t| 5: code             |\n\t\t\t\t\t| 6: back             |\n\t\t\t\t\t|_____________________|");

printf("\n\n\n\n\n\t\t\t\t\tenter your choose :");

scanf("%d",&choose);
int H=0;
switch(choose){

case 0:H=search_Book_by_name(H);
break;
case 1:H=search_book_by_category(H);
break;
case 2:H=search_book_by_name_of_writer(H);
break;
case 3:H=search_book_by_number_of_pages(H);
break;
case 4:H=search_book_by_price(H);
break;
case 5:H=search_book_by_code(H);
break;
case 6:main();
break;
}
}
int search_member(){
printf("\t\t\t\t\t\tsearch a member\n\t\t\t\t\t\t***************\n\n");

    int choose;

//name|cat|writer|pages|price|code

printf("\n\n\t\t\t\t\t ___search menu by____\n\t\t\t\t\t| 0: first name       |\n\t\t\t\t\t| 1: last name        |\n\t\t\t\t\t| 2: number of books  |\n\t\t\t\t\t| 3: code             |\n\t\t\t\t\t| 4: back             |\n\t\t\t\t\t|_____________________|");

printf("\n\n\n\n\n\t\t\t\t\tenter your choose :");

scanf("%d",&choose);
switch(choose){

case 0:search_member_by_fname();
break;
case 1:search_member_by_lname();
break;
case 2:
break;
case 3:search_Member_by_code();
break;
case 4:main();
break;
}

}
//-----------------
int search_member_by_fname(){
char first_name[27],verify_back;
int c=1;
    printf("enter the first name :");
scanf("%c",first_name);
    scanf("%[^\n]s",first_name);

    system("cls");

    printf("\t\t\t\t\t\tThe Members\n\n\t|N°|\t\tfirst name\t||\tfamily name\t||\tbook bundle\t||\tcode\t|\n\t*************************************************************************************************\n");

    for(int i=0;i<=NM;i++){

        if(strcmp(first_name,a[i].member_first_name)==0){

        printf("\t|%d°|\t\t%14s\t||\t%14s\t||\t%d\t\t||\t%d\t|\n",i,a[i].member_first_name,a[i].member_family_name,a[i].readed_books,a[i].member_code);
     c=0;
    }
    else if(i==NM && c!=0) {printf("\t\t\t\tthis member does not exist\n\n");
    }
 }
       //control menu------------------------------------------------------------------
int x;
printf("\n\n\n\n\t\t\t\t\t\t   _____control menu_____\n\t\t\t\t\t\t   | 0: BACK             |\n\t\t\t\t\t\t   | 1: MENU             |\n\t\t\t\t\t\t   | 2: EXIT             |\n\t\t\t\t\t\t   |_____________________|");
CM:
printf("\n\t\t\t enter your choose :");
    scanf("%d",&x);
                          switch(x){//'switch' to go where the user choose from the control menu
                                         case 0:system("cls");
                                                search_member();
                                                              break;
                                         case 1:system("cls");
                                                   main();   break;
                                         case 2:
                                                exit(0) ;
                                                              break;
                                         default:printf("\nplease add number from the choose ");
                                         goto CM;
                                         break;
                                        }
      //-------------------------------------------------------------------------------

}

//
int search_member_by_lname(){

char family_name[27],verify_back;

int c=1;
    printf("enter the family name :");
scanf("%c",family_name);
    scanf("%[^\n]s",family_name);

    system("cls");

    printf("\t\t\t\t\t\tThe Members\n\n\t|N°|\t\tfirst name\t||\tfamily name\t||\tbook bundle\t||\tcode\t|\n\t*************************************************************************************************\n");

    for(int i=0;i<=NM;i++){

        if(strcmp(family_name,a[i].member_family_name)==0){

        printf("\t|%d°|\t\t%14s\t||\t%14s\t||\t%d\t\t||\t%d\t|\n",i,a[i].member_first_name,a[i].member_family_name,a[i].readed_books,a[i].member_code);
     c=0;
    }
    else if(i==NM && c!=0) {printf("\t\t\t\tthis member does not exist\n\n");
    }
 }
       //control menu------------------------------------------------------------------
int x;
printf("\n\n\n\n\t\t\t\t\t\t   _____control menu_____\n\t\t\t\t\t\t   | 0: BACK             |\n\t\t\t\t\t\t   | 1: MENU             |\n\t\t\t\t\t\t   | 2: EXIT             |\n\t\t\t\t\t\t   |_____________________|");
CM:
printf("\n\t\t\t enter your choose :");
    scanf("%d",&x);
                          switch(x){//'switch' to go where the user choose from the control menu
                                         case 0:system("cls");
                                                search_member();
                                                              break;
                                         case 1:system("cls");
                                                   main();   break;
                                         case 2:
                                                exit(0) ;
                                                              break;
                                         default:printf("\nplease add number from the choose ");
                                         goto CM;
                                         break;
                                        }
      //-------------------------------------------------------------------------------

}


int search_Member_by_code(){
int member_code,c=1;
 restore:printf("enter the member code: ");
 scanf("%d",&member_code);
 if(member_code<1000 || member_code>9999){
    printf(" this number does not exict !! \n");
    goto restore;
 }
 system("cls");
 printf("\t\t\t\t\t\tThe Members\n\n\t|N°|\t\tfirst name\t||\tfamily name\t||\tbook bundle\t||\tcode\t|\n\t*************************************************************************************************\n");

 for(int i=0;i<=NM;i++){
    if(member_code==a[i].member_code){
        printf("\t|%d°|\t\t%14s\t||\t%14s\t||\t%d\t\t||\t%d\t|\n",i,a[i].member_first_name,a[i].member_family_name,a[i].readed_books,a[i].member_code);
c=0;
    }
    else if(c==1 && i==NM){
    printf("\t\t\t\tthere is no book with this code\n\n");}
 }
      //control menu------------------------------------------------------------------
int x;
printf("\n\n\n\n\t\t\t\t\t\t   _____control menu_____\n\t\t\t\t\t\t   | 0: BACK             |\n\t\t\t\t\t\t   | 1: MENU             |\n\t\t\t\t\t\t   | 2: EXIT             |\n\t\t\t\t\t\t   |_____________________|");
CM:
printf("\n\t\t\t enter your choose :");
    scanf("%d",&x);
                          switch(x){//'switch' to go where the user choose from the control menu
                                         case 0:system("cls");
                                                search_member();
                                                              break;
                                         case 1:system("cls");
                                                   main();   break;
                                         case 2:
                                                exit(0) ;
                                                              break;
                                         default:printf("\nplease add number from the choose ");
                                         goto CM;
                                         break;
                                        }
      //-------------------------------------------------------------------------------

}
