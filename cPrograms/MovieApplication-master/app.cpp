#include <bits/stdc++.h>
using namespace std;

void display_Home_Screen(void);
int display_Admin_Log_In_Screen();
void display_Admin_Home_Screen();
void view_Movie_Details(char mode);
void create_Movie_List(char mode);
void edit_Movie_Item();
void delete_Movie_Item();
void view_Customer_DB();
void view_Tickets_Sold();
void create_Recharge_Pin();
void view_Recharge_History();
void display_Mail_Menu(char caller_user_name[]);
void inbox_Message(char user_name[]);
void display_Sent_Message(char user_name[]);
void compose_Message(char sender_user_name[]);
void change_Admin_Password();
//--------------------------------------------
void display_User_Home_Screen();
void register_New_User();
void user_Log_In();
void display_User_Operation(char user_name[10]);
void recharge_Account();
void  book_Movie_Ticket();
void transfer_User_Fund(char user_name[]);
void view_User_History();
void display_Seats(char seats[]);
int available_Seats(char seats[]);
void print_Spaces(int n);
int check_User_Name(char user_name[]);
void print_New_Line(int n);
int is_Invalid_Movie_Id(char movie_id[]);
char* get_info();
char* parse_And_Print_Info(char info[]);
char* remove_Underscore(char expression[]);
char* insert_Underscore(char expression[]);
//---------------------------------------------------------------------------------------------------------------------------
struct mail_structure
{
    char sender_user_name[50],receiver_user_name[50],message_subject[50],message[1000];
    char info[50];
}mail;
//---------------------------------------------------------------------------------------------------------------------------
struct admin_password
{
    char pWord[50];
}admin;
//---------------------------------------------------------------------------------------------------------------------------
struct movie_seat
{
    char m_seat[10];
};
//-------------------------------------------------------------------------------------------------------------------------------
struct movie_list{
    char movie_name[50];
    int ticket_price;
    char movie_id[10];
    char movie_language[50];
    char movie_genre[50];
    char movie_length[50];
    struct movie_seat ms;
}mList;
//-------------------------------------------------------------------------------------------------------------------------------
struct user_Account{
    char fName[10],lName[10],pWord[20];
    int user_balance;
    char user_name[10];
    char info[50];
}uAccount;
//-------------------------------------------------------------------------------------------------------------------------------
struct recharge_History{
    char user_name[50];
    int recharge_amt;
    char info[50];
}rHistory;
//-------------------------------------------------------------------------------------------------------------------------------
struct bookedHistory{//ticket booked history
    char user_name[50],movie_name[50],info[50],movie_id[50];
    int ticket_price;

}bHistory;
//-------------------------------------------------------------------------------------------------------------------------------
struct recharge_Pin
{
    char pin_number[12];
    int recharge_amount;
}pNumber;
//-------------------------------------------------------------------------------------------------------------------------------
struct fund_transfer_history{
    char transferer_user_name[50],receiver_user_name[50],info[50];
    int transfer_amount;
}fHistory;
//--------------------------------------------------------------------------------------------------------------
int clear_input_buffer(void) {
    int ch;
    while (((ch = getchar()) != EOF) && (ch != '\n')) /* void */;
    return ch;
}
//-------------------------------------------------------------------------------------------------------------------------------
void main()
{
  // compose_Message("Resham");
    display_Home_Screen();
    system("cls");
    print_New_Line(4);
    print_Spaces(25);
    printf("Thanks for using our service!!!\n\n\n");
}

//-------------------------------------------------------------------------------------------------------------------------------
void display_Home_Screen(void)
{
    int loop = 1;
    int choice;
    while(loop)
    {
        system("cls");
        print_New_Line(7);
        print_Spaces(30);
        printf("HOME SCREEN\n");
        print_New_Line(3);
        print_Spaces(15);
        printf("1. Admin");
        print_Spaces(10);
        printf("2. User");
        print_Spaces(10);
        printf("3.EXIT\n");
        print_New_Line(3);
        print_Spaces(25);
        printf("Enter your choice(1-4) : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                int login_success = display_Admin_Log_In_Screen();
                if(login_success)
                {
                     display_Admin_Home_Screen();
                }
                break;
            }
            case 2:
            {
                display_User_Home_Screen();
                break;
            }
            case 3:
            {
                loop = 0;
                break;
            }
            default:
            {
                print_New_Line(2);
                print_Spaces(25);
                printf("Please enter correct option.\n");
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------
int display_Admin_Log_In_Screen()
{
    system("cls");
    char admin_password[50];
    print_New_Line(4+2);
    print_Spaces(30);
    printf("LOGIN MENU");
    print_New_Line(4);
    print_Spaces(28);
    printf("Username : Admin");
    print_New_Line(2);
    print_Spaces(28);
    printf("Password : ");
    scanf("%s",admin_password);
    FILE *fp = fopen("AdminPassword.txt","r");
    fscanf(fp,"%s",admin.pWord);
    if(strcmp(admin.pWord,admin_password) == 0)
    {
        fclose(fp);
        return 1;
    }
    else
    {
        print_New_Line(4);
        print_Spaces(30-2);
        printf("Unable to log in.");
        print_New_Line(3);
        print_Spaces(30-2);
        printf("Press any key to return...");
        getch();
        fclose(fp);
        return 0;
    }
}
//-------------------------------------------------------------------------------------------------------------------------------
void display_Admin_Home_Screen()
{
    char name[100];
    gets(name);
    puts(name);
    int loop = 1;
    while(loop)
    {
        system("cls");
        print_New_Line(4);
        print_Spaces(30);
        printf("ADMIN HOME SCREEN\n");
        print_New_Line(3);
        print_Spaces(15);
        printf("1. View Movie List");
        print_Spaces(10);
        printf("2. Create Movie List\n");
        print_New_Line(2);
        print_Spaces(15);
        printf("3. Add Movie List");
        print_Spaces(11);
        printf("4. Edit Movie.\n");
        print_New_Line(2);
        print_Spaces(15);
        printf("5. Delete Movie");
        print_Spaces(13);
        printf("6. Customer Database\n");
        print_New_Line(2);
        print_Spaces(15);
        printf("7. Tickets Sold");
        print_Spaces(13);
        printf("8. Create Recharge PIN\n");
        print_New_Line(2);
        print_Spaces(15);
        printf("9. Recharge History");
        print_Spaces(9);
        printf("10. Mail");
        print_New_Line(3);
        print_Spaces(15);
        printf("11. Change Password");
        print_Spaces(13-4);
        printf("12. Log out");
        int admin_choice;
        print_New_Line(3);
        print_Spaces(30);
        printf("Enter your choice : ");
        scanf("%d",&admin_choice);
        switch(admin_choice)
        {
            case 1:
            {
                view_Movie_Details('v');
                break;
            }
            case 2:
            {
                create_Movie_List('c');//create new movie list
                break;
            }
            case 3:
            {
                create_Movie_List('a'); //append movie list
                break;
            }
            case 4:
            {
                edit_Movie_Item();
                break;
            }
            case 5:
            {
                delete_Movie_Item();
                break;
            }
            case 6:
            {
                view_Customer_DB();
                break;
            }
            case 7:
            {
                view_Tickets_Sold();
                break;
            }
            case 8:
            {
                create_Recharge_Pin();
                break;
            }
            case 9:
            {
                 view_Recharge_History();
                 break;
            }
            case 10:
            {
                display_Mail_Menu("Admin");
                break;
            }
            case 11:
            {
                change_Admin_Password();
                break;
            }
            case 12:
            {
                loop = 0;
                break;
            }
            default:
            {
                print_New_Line(2);
                print_Spaces(25);
                printf("Please enter correct option.\n");
            }
        }//switch
    }
}
//------------------------------------------------------------------------------------------------------

void view_Movie_Details(char mode)
{
    system("cls");
    FILE *fp;
    fp = fopen("MovieList.txt","r");
    print_New_Line(4);
    print_Spaces(26);
    printf("CURRENT SHOWS AT QFX CIVIL MALL\n");
    print_Spaces(26);
    print_New_Line(4);
    if(fscanf(fp,"%s%s%d%s%s%s%s\n",mList.movie_id,mList.movie_name,&mList.ticket_price,
                                    mList.movie_length,mList.movie_genre,
                                    mList.movie_language,mList.ms.m_seat)==EOF)
    {
        print_Spaces(26);
        printf("Movie list is currently empty.\n\n");
        fclose(fp);
    }else
    {
        fclose(fp);
        fp = fopen("MovieList.txt","r");
        printf("Movie Title");
        print_Spaces(23);
        printf("Details\n");
        printf("-----------------------------------------------------------------------------\n");
        while(fscanf(fp,"%s%s%d%s%s%s%s\n",mList.movie_id,mList.movie_name,&mList.ticket_price,
                                    mList.movie_length,mList.movie_genre,
                                    mList.movie_language,mList.ms.m_seat)!=EOF)
        {
            print_Spaces(34);
            printf("ID              : %s\n",mList.movie_id);
            print_Spaces(34);
            printf("Length          : ",mList.movie_length);
            char movie_length[50];
            strcpy(movie_length,remove_Underscore(mList.movie_length));
            printf("%s\n",movie_length);
            char movie_name_clone[50];
            strcpy(movie_name_clone,remove_Underscore(mList.movie_name));
            printf("%s",movie_name_clone);
            print_Spaces(34 - strlen(mList.movie_name));
            char movie_genre_clone[50];
            strcpy(movie_genre_clone,remove_Underscore(mList.movie_genre));
            printf("Genre           : %s\n",movie_genre_clone);
            print_Spaces(34);
            char movie_language_clone[50];
            strcpy(movie_language_clone,remove_Underscore(mList.movie_language));
            printf("Language        : %s\n",movie_language_clone);
            print_Spaces(34);
            printf("Ticket Price(Rs): %d\n",mList.ticket_price);
            print_Spaces(34);
            printf("Available Seats : %d\n",available_Seats(mList.ms.m_seat));
            printf("-----------------------------------------------------------------------------\n");
        }
        fclose(fp);
    }
    if(mode == 'v')// v = view
    {
        print_New_Line(2);
        print_Spaces(26);
        printf("Press any key to return...");
        getch();
    }
}

void create_Movie_List(char mode)
{
    system("cls");
    char loop[] = "y";
    print_New_Line(4);
    print_Spaces(26);
    if(mode == 'c')
    {
        printf("CREATE MOVIE LIST\n");
        remove("MovieList.txt");
    }else
    {
        print_New_Line(1);
        print_Spaces(26);
        printf("ADD MOVIES\n");
        print_New_Line(1);
        print_Spaces(26);
    }
    FILE *fp;
    print_Spaces(26);
    while(strcmp(loop,"y") == 0)
    {
        fp = fopen("MovieList.txt","a");
        int invalid_movie_id = 1,ticket_price;
        char movie_name[50];
        print_New_Line(1);
        print_Spaces(26);
        printf("Movie name      : ");
        clear_input_buffer();//important for gets() to work
        gets(movie_name);
        char movie_name_clone[50];
        strcpy(movie_name_clone,insert_Underscore(movie_name));
        while(invalid_movie_id)
        {
            char movie_id_temp[50];
            print_New_Line(1);
            print_Spaces(26);
            printf("Movie ID        : ");
            scanf("%s",movie_id_temp);
            invalid_movie_id = is_Invalid_Movie_Id(movie_id_temp);
            if(invalid_movie_id)
            {
               print_New_Line(1);
               print_Spaces(26);
               printf("Movie ID already used.\n");
           }else
           {
                strcpy(mList.movie_id,movie_id_temp);
           }
        }// while loop
        strcpy(mList.movie_name,movie_name_clone);
        print_New_Line(1);
        print_Spaces(26);
        printf("Ticket Price(Rs): ");
        scanf("%d",&mList.ticket_price);
        print_New_Line(1);
        print_Spaces(26);
        printf("Length          : ");
        char movie_length_clone[50];
        clear_input_buffer();
        char movie_length[50];
        gets(movie_length);
        strcpy(movie_length_clone,insert_Underscore(movie_length));
        strcpy(mList.movie_length,movie_length_clone);
        print_New_Line(1);
        print_Spaces(26);
        printf("Genre           : ");
        char movie_genre[50],movie_genre_clone[50];
        gets(movie_genre);
        strcpy(movie_genre_clone,insert_Underscore(movie_genre));
        strcpy(mList.movie_genre,movie_genre_clone);
        print_New_Line(1);
        print_Spaces(26);
        char movie_language[50],movie_language_clone[50];
        printf("Language        : ");
        gets(movie_language);
        strcpy(movie_language_clone,insert_Underscore(movie_language));
        strcpy(mList.movie_language,movie_language_clone);
        print_New_Line(1);
        strcpy(mList.ms.m_seat,"0123456789");
        fprintf(fp,"%s\t%s\t%d\t%s\t%s\t%s\t%s\n",mList.movie_id,mList.movie_name,mList.ticket_price,
                                    mList.movie_length,mList.movie_genre,
                                    mList.movie_language,mList.ms.m_seat);
        print_Spaces(26);
        printf("-----------------\n");
        print_Spaces(26);
        printf("Enter more(y/n):");
        scanf("%s",loop);
        print_Spaces(26);
        printf("-----------------\n");
        fclose(fp);
    }
    print_New_Line(2);
    print_Spaces(26);
    printf("Press any key to return...");
    getch();
}

void edit_Movie_Item()
{
    system("cls");
    print_New_Line(4);
    print_Spaces(30);
    printf("EDIT MOVIES\n");
    print_Spaces(30);
    print_New_Line(2);
    FILE *fp,*fp1;
    char movie_id[10],loop[] = "y";
    int invalid_movie_id = 1;
    while(strcmp(loop,"y") == 0)
    {
        int found_Item = 0;
        fp = fopen("MovieList.txt","r");
        fp1 = fopen("TempMovieList.txt","w");
        print_New_Line(2);
        print_Spaces(30);
        printf("Movie ID to be edited : ");
        scanf("%s",movie_id);
        while(fscanf(fp,"%s%s%d%s%s%s%s\n",mList.movie_id,mList.movie_name,&mList.ticket_price,
                                    mList.movie_length,mList.movie_genre,
                                    mList.movie_language,mList.ms.m_seat)!=EOF)
        {
            char movie_id1[50];
            if(strcmp(movie_id,mList.movie_id) == 0)
            {
                found_Item = 1;
                print_New_Line(1);
                print_Spaces(26+4);
                char movie_name[50];
                printf("New Movie name        : ");
                clear_input_buffer();
                char movie_name_clone[50];
                gets(movie_name);
                strcpy(movie_name_clone,insert_Underscore(movie_name));
                while(invalid_movie_id)
                {
                    print_New_Line(1);
                    print_Spaces(26+4);
                    printf("New Movie ID          : ");
                    scanf("%s",movie_id1);
                    if(strcmp(movie_id,movie_id1) == 0)
                    {
                        invalid_movie_id = 0;
                    }else
                    {
                        invalid_movie_id = is_Invalid_Movie_Id(movie_id1);
                    }
                    if(invalid_movie_id)
                        printf("Movie Id already used!\n");
                }// while
                invalid_movie_id = 1;
                print_New_Line(1);
                print_Spaces(26+4);
                printf("New Ticket Price(Rs)  : ");
                scanf("%d",&mList.ticket_price);
                print_New_Line(1);
                print_Spaces(26+4);
                printf("New Length            : ");
                char movie_length[50],movie_length_clone[50];
                clear_input_buffer();
                gets(movie_length);
                strcpy(movie_length_clone,insert_Underscore(movie_length));
                print_New_Line(1);
                print_Spaces(26+4);
                char movie_genre[50],movie_genre_clone[50];
                printf("New Genre             : ");
                gets(movie_genre);
                strcpy(movie_genre_clone,insert_Underscore(movie_genre));
                print_New_Line(1);
                print_Spaces(26+4);
                char movie_language[50],movie_language_clone[50];
                printf("New Language          : ");
                gets(movie_language);
                strcpy(movie_language_clone,insert_Underscore(movie_language));
                strcpy(mList.movie_language,movie_language_clone);
                strcpy(mList.movie_name,movie_name_clone);
                strcpy(mList.movie_length,movie_length_clone);
                strcpy(mList.movie_id,movie_id1);
                strcpy(mList.movie_genre,movie_genre_clone);
                print_New_Line(1);
                fprintf(fp1,"%s\t%s\t%d\t%s\t%s\t%s\t%s\n",mList.movie_id,mList.movie_name,mList.ticket_price,
                                    mList.movie_length,mList.movie_genre,
                                    mList.movie_language,mList.ms.m_seat);
            }
            else
            {
                fprintf(fp1,"%s\t%s\t%d\t%s\t%s\t%s\t%s\n",mList.movie_id,mList.movie_name,mList.ticket_price,
                                    mList.movie_length,mList.movie_genre,
                                    mList.movie_language,mList.ms.m_seat);
            }
         }//while loop
        fclose(fp);
        fclose(fp1);
        remove("MovieList.txt");
        rename("TempMovieList.txt","MovieList.txt");
        if(found_Item)
        {
            print_New_Line(1);
            print_Spaces(26+4);
            printf("Movie Item successfully edited.\n");
        }
        else
        {
            print_New_Line(2);
            print_Spaces(26+4);
            printf("Cannot find specified movie.\n");
        }
        print_New_Line(2);
        print_Spaces(30);
        printf("------------------");
        print_New_Line(1);
        print_Spaces(30);
        printf("Edit more(y/n):");
        scanf("%s",loop);
        print_Spaces(30);
        printf("------------------");
    }
    print_New_Line(2);
    print_Spaces(26+4);
    printf("Press any key to return...");
    getch();
}

void delete_Movie_Item()
{
    system("cls");
    char loop[]="y";
    print_New_Line(4);
    print_Spaces(30);
    printf("DELETE MOVIES\n");
    print_Spaces(30);
    FILE *fp,*fp1;
    char movie_id[10];
    while(strcmp(loop,"y") == 0)
    {
        int found_Movie_Item = 0;
        fp = fopen("MovieList.txt","r");
        fp1 = fopen("TempMovieList.txt","w");
        print_New_Line(2);
        print_Spaces(30);
        printf("Enter Movie ID:");
        scanf("%s",movie_id);
        while(fscanf(fp,"%s%s%d%s%s%s%s\n",mList.movie_id,mList.movie_name,&mList.ticket_price,
                                    mList.movie_length,mList.movie_genre,
                                    mList.movie_language,mList.ms.m_seat)!=EOF)
        {
            if(strcmp(movie_id,mList.movie_id) == 0)
            {
                found_Movie_Item = 1;
            }else
            {
                fprintf(fp1,"%s\t%s\t%d\t%s\t%s\t%s\t%s\n",mList.movie_id,mList.movie_name,mList.ticket_price,
                                    mList.movie_length,mList.movie_genre,
                                    mList.movie_language,mList.ms.m_seat);
            }
        }
    fclose(fp);
    fclose(fp1);
    remove("MovieList.txt");
    rename("TempMovieList.txt","MovieList.txt");
    if(found_Movie_Item)
    {
        print_New_Line(2);
        print_Spaces(30);
        printf("Movie item deleted successfully.");
    }
    else
    {
        print_New_Line(2);
        print_Spaces(30);
        printf("Cannot find specified movie.");
    }
    print_New_Line(2);
    print_Spaces(30);
    printf("---------------------");
    print_New_Line(1);
    print_Spaces(30);
    printf("Delete more(y/n) : ");
    scanf("%s",loop);
    print_Spaces(30);
    printf("---------------------");
}
    print_New_Line(2);
    print_Spaces(30);
    printf("Press any key to return...");
    getch();
}


void view_Customer_DB()
{   //14-4
    //27 39 54
    system("cls");
    print_New_Line(4);
    print_Spaces(30);
    printf("CUSTOMER DATABASE\n");
    print_Spaces(30);
    print_New_Line(2);
    printf("First Name    Last Name    Username    Balance(Rs)   Registration Details\n");
    printf("--------------------------------------------------------------------------------");
    FILE *fp = fopen("UserAccount.txt","r");
    while(fscanf(fp,"%s%s%s%s%d%s",uAccount.fName,uAccount.lName,
                 uAccount.user_name,uAccount.pWord,
                 &uAccount.user_balance,uAccount.info)!= EOF)
    {
        printf("%s",uAccount.fName);
        print_Spaces(14 - strlen(uAccount.fName));
        printf("%s",uAccount.lName);
        print_Spaces(27 - strlen(uAccount.lName) - 14);
        printf("%s",uAccount.user_name);
        print_Spaces(39 - 27 - strlen(uAccount.user_name));
        printf("%d",uAccount.user_balance);
        print_Spaces(54 - 39 - number_Digits(uAccount.user_balance)-1);
        char info_clone[50];
        strcpy(info_clone,remove_Underscore(uAccount.info));
        printf("%s\n",info_clone);
    }
    printf("--------------------------------------------------------------------------------");
    fclose(fp);
    print_New_Line(2);
    print_Spaces(26+4);
    printf("Press any key to return...");
    getch();
}
void view_Tickets_Sold()
{//14 29 42 56
    system("cls");
    int total_revenue = 0;
    int found_ticket_sold_history = 1;
    print_New_Line(4);
    print_Spaces(30);
    printf("TICKETS SOLD\n");
    print_Spaces(30);
    print_New_Line(2);
    FILE *fp = fopen("TicketBookedHistory.txt","r");
    while(fscanf(fp,"%s%s%s%d%s",bHistory.user_name,bHistory.movie_name,bHistory.movie_id,
                                &bHistory.ticket_price,bHistory.info) == EOF)
    {
        found_ticket_sold_history = 0;
        break;
    }
    fclose(fp);
    if(found_ticket_sold_history)
    {
        fp = fopen("TicketBookedHistory.txt","r");
        printf("User Name     Movie Name             ID     Price      Info\n");
        printf("-----------------------------------------------------------------------------\n");
        while(fscanf(fp,"%s%s%s%d%s",bHistory.user_name,bHistory.movie_name,bHistory.movie_id,
                                &bHistory.ticket_price,bHistory.info)!= EOF)
        {
            printf("%s",bHistory.user_name);
            print_Spaces(14 - strlen(bHistory.user_name));
            char movie_name_clone[50];
            strcpy(movie_name_clone,remove_Underscore(bHistory.movie_name));
            printf("%s",movie_name_clone);
            print_Spaces(29 - 14 - strlen(bHistory.movie_name)+2+4+2);
            printf("%s",bHistory.movie_id);
            print_Spaces(42 - 29 - strlen(bHistory.movie_id)-2-4);
            printf("%d",bHistory.ticket_price);
            print_Spaces(56 - 42 - number_Digits(bHistory.ticket_price)-1-2);
            char info_clone[50];
            strcpy(info_clone,remove_Underscore(bHistory.info));
            printf("%s\n",info_clone);
            total_revenue = total_revenue + bHistory.ticket_price;
        }
        fclose(fp);
        printf("-----------------------------------------------------------------------------\n");
        printf("TOTAL(Rs) : ");
        print_Spaces(30+4-4+2);
        printf("%d",total_revenue);
    }else
    {
        print_New_Line(1);
        print_Spaces(30);
        printf("List is currently empty.");
    }
    print_New_Line(5);
    print_Spaces(30);
    printf("Press any key to return...");
    getch();
}


void create_Recharge_Pin()
{
    system("cls");
    print_New_Line(4);
    print_Spaces(30);
    printf("CREATE RECHARGE PIN\n");
    print_Spaces(30);
    printf("-------------------");
    FILE *fp;
    char more[2] ="y";
    fp = fopen("RechargePinList.txt","a");
    while(strcmp(more,"y") == 0)
    {
        print_New_Line(2);
        print_Spaces(30);
        printf("PIN Number:");
        scanf("%s",pNumber.pin_number);
        print_New_Line(1);
        print_Spaces(30);
        printf("Recharge value:");
        scanf("%d",&pNumber.recharge_amount);
        fprintf(fp,"%s\t%d\n",pNumber.pin_number,pNumber.recharge_amount);
        print_New_Line(1);
        print_Spaces(30);
        printf("-----------------");
        print_New_Line(1);
        print_Spaces(30);
        printf("Enter more(y/n):");
        scanf("%s",more);
        print_Spaces(30);
        printf("-----------------");
    }
    fclose(fp);
    print_New_Line(2);
    print_Spaces(26+4);
    printf("Press any key to return...");
    getch();
}

void view_Recharge_History()
{
    system("cls");
    print_New_Line(4);
    print_Spaces(30);
    printf("RECHARGE HISTORY\n");
    print_Spaces(30);
    printf("----------------");
    print_New_Line(3);
    FILE *fp;
    fp = fopen("RechargeHistory.txt","r");
    if(fscanf(fp,"%s\t%d\t%s\n",rHistory.user_name,&rHistory.recharge_amt,rHistory.info)== EOF)
    {
        print_New_Line(2);
        print_Spaces(30);
        printf("Recharge History is currently empty.\n");
        fclose(fp);
    }
    else
    {    //17 30
        fclose(fp);
        fp = fopen("RechargeHistory.txt","r");
        printf("User Name        Amount      Info\n");
        printf("-----------------------------------------------------------------\n");
        while(fscanf(fp,"%s%d%s",rHistory.user_name,&rHistory.recharge_amt,rHistory.info)!= EOF)
        {
            printf("%s",rHistory.user_name);
            print_Spaces(17 - strlen(rHistory.user_name));
            printf("%d",rHistory.recharge_amt);
            print_Spaces(29 - 17 - number_Digits(rHistory.recharge_amt));

            parse_And_Print_Info(rHistory.info);
            }
        fclose(fp);
    }
    print_New_Line(2);
    print_Spaces(26+4);
    printf("Press any key to return...");
    getch();
}


void display_Mail_Menu(char caller_user_name[])
{
    char caller_user_name_clone[50];
    strcpy(caller_user_name_clone,caller_user_name);
    int loop = 1;
    while(loop)
    {
        system("cls");
        print_New_Line(3);
        print_Spaces(35);
        printf("MAIL");
        print_New_Line(5);
        print_Spaces(15);
        printf("Hi %s,",caller_user_name_clone);
        print_New_Line(3);
        print_Spaces(15);
        printf("1. Inbox");
        print_Spaces(13-1-2);
        printf("2. Sent Mail");
        print_Spaces(13-4);
        printf("3. Compose");
        print_New_Line(2);
        print_Spaces(30+3);
        printf("4. EXIT");
        print_New_Line(4);
        print_Spaces(30);
        int ch;
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
            {
                inbox_Message(caller_user_name_clone);
                break;
            }
            case 2:
            {
                display_Sent_Message(caller_user_name_clone);
                break;
            }
            case 3:
            {
                compose_Message(caller_user_name_clone);
                break;
            }
            case 4:
            {
                loop = 0;
                break;
            }
            default:
            {
                print_New_Line(4);
                print_Spaces(30);
                printf("Please enter correct option.");
            }
    }
   }
   print_New_Line(4);
   print_Spaces(30);
   printf("Press any key to continue...");
   getch();
}

void inbox_Message(char user_name[])
{
    char user_name_clone[50];
    strcpy(user_name_clone,user_name);
    int loop = 1;
    int mail_inbox_not_empty=0;
    FILE *fp1 = fopen("Mail.txt","r");
    while(fscanf(fp1,"%s%s%s%s%s",mail.sender_user_name,mail.receiver_user_name,mail.message_subject,
                    mail.message,mail.info) != EOF)
    {
        if(strcmp(user_name_clone,mail.receiver_user_name) == 0)
        {
            mail_inbox_not_empty = 1;
            break;
        }
    }
    fclose(fp1);
    if(mail_inbox_not_empty)
    {
        while(loop)
        {
            system("cls");
            print_New_Line(4);
            print_Spaces(35);
            printf("INBOX");
            print_New_Line(3);
            int sn = 0;
            FILE *fp = fopen("Mail.txt","r");
            printf(" SN.     Sender            Subject                    Info");
            print_New_Line(1);
            printf("------------------------------------------------------------------------------");
            print_New_Line(1);
            while(fscanf(fp,"%s%s%s%s%s",mail.sender_user_name,mail.receiver_user_name,mail.message_subject,
                    mail.message,mail.info) != EOF)
            {//9 27 55
                if(strcmp(user_name_clone,mail.receiver_user_name) == 0)
                {
                    print_Spaces(1);
                    printf("%d",sn);
                    print_Spaces(9-1-number_Digits(sn));
                    printf("%s",mail.sender_user_name);
                    print_Spaces(27-9-strlen(mail.sender_user_name));
                    char message_subject_clone[100];
                    strcpy(message_subject_clone,remove_Underscore(mail.message_subject));
                    printf("%s",message_subject_clone);
                    print_Spaces(55-27-strlen(mail.message_subject)-1);
                    char info_clone[50];
                    strcpy(info_clone,remove_Underscore(mail.info));
                    printf("%s\n",info_clone);
                    sn++;
                }
            }
            printf("------------------------------------------------------------------------------");
            fclose(fp);
            print_New_Line(4);
            print_Spaces(20);
            printf("1.Open Mail.");
            print_Spaces(15);
            printf("2. <- (Back)");
            print_New_Line(3);
            int ch;
            print_Spaces(30);
            printf("Enter your choice : ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                {
                    int inner_loop = 1;
                    while(inner_loop)
                    {
                        int serial_number;
                        //view email in detail
                        print_New_Line(1);
                        print_Spaces(30);
                        printf("Enter Email SN : ");
                        scanf("%d",&serial_number);
                        if(serial_number < 0 || serial_number > sn)
                        {
                            printf("Invalid Email SN.");
                        }else
                        {
                            //proceed to extract email
                            system("cls");
                            FILE *fp = fopen("Mail.txt","r");
                            int count = 0;
                            print_New_Line(4);
                            print_Spaces(35);
                            printf("INBOX MAIL");
                            while(fscanf(fp,"%s%s%s%s%s",mail.sender_user_name,mail.receiver_user_name,mail.message_subject,
                                    mail.message,mail.info) != EOF)
                            {
                                if(strcmp(user_name_clone,mail.receiver_user_name) == 0 )
                                {
                                    if(serial_number == count)
                                    {
                                        print_New_Line(2);
                                        print_Spaces(3);
                                        printf("From    : %s" ,mail.sender_user_name);
                                        print_New_Line(2);
                                        char subject_clone[100];
                                        strcpy(subject_clone,remove_Underscore(mail.message_subject));
                                        print_Spaces(3);
                                        printf("Subject : %s",subject_clone);
                                        print_New_Line(2);
                                        char info_clone[50];
                                        strcpy(info_clone,remove_Underscore(mail.info));
                                        print_Spaces(3);
                                        printf("Details : %s",info_clone);
                                        print_New_Line(3);
                    //                    print_Spaces(15);//as per compose format
                                        print_Spaces(4);
                                        printf("----------------------------------------------------------------------------");
                                        char message_clone[1000];
                                        strcpy(message_clone,remove_Underscore(mail.message));
                                        printf("%s",message_clone);
                                        print_New_Line(4);
                                        print_Spaces(15);
                                        fclose(fp);
                                        printf("Press any key to return back...");
                                        getch();
                                        inner_loop = 0;
                                        break; //while
                                    }else
                                    {
                                        count++;
                                    }

                            }
                        }
                        fclose(fp);
                }
            }
        break;//switch
        }
    case 2:
        {
            loop = 0;
            break;
        }
    default:
        {
            print_New_Line(3);
            print_Spaces(30);
            printf("Please enter correct option.\n");
            break;
        }
    }
    }
    }
    else
    {
        system("cls");
        print_New_Line(4);
        print_Spaces(35);
        printf("INBOX");
        print_New_Line(3);
        print_Spaces(25);
        printf("Inbox Mail is currently empty...");
    }
    print_New_Line(3);
    print_Spaces(27);
    printf("Press any key to continue...");
    getch();
}


void display_Sent_Message(char user_name[])
{
    char user_name_clone[50];
    strcpy(user_name_clone,user_name);
    int found_sent_message=0;
    FILE *fp = fopen("Mail.txt","r");
    while(fscanf(fp,"%s%s%s%s%s",mail.sender_user_name,mail.receiver_user_name,mail.message_subject,
                    mail.message,mail.info) != EOF)
    {
        if(strcmp(user_name_clone,mail.sender_user_name) == 0)
        {
            found_sent_message = 1;
            break;
        }
    }
    fclose(fp);
    int loop = 1;
    while(loop)
    {
        system("cls");
        print_New_Line(4);
        print_Spaces(35);
        printf("SENT MESSAGE");
        print_New_Line(3);
        if(found_sent_message)
        {//11 31 63
            FILE *fp = fopen("Mail.txt","r");
            printf("  SN       Sender Name       Subject                Info");
            print_New_Line(1);
            printf("-------------------------------------------------------------------------------");
            print_New_Line(1);
            int count=0;
            while(fscanf(fp,"%s%s%s%s%s",mail.sender_user_name,mail.receiver_user_name,mail.message_subject,
                    mail.message,mail.info) != EOF)
            {
                if(strcmp(user_name_clone,mail.sender_user_name) == 0)
                {
                    print_Spaces(2);
                    printf("%d",count);
                    print_Spaces(11-2-number_Digits(count));
                    printf("%s",mail.sender_user_name);
                    print_Spaces(31 - 11 - strlen(mail.sender_user_name)-2);
                    char subject_clone[100];
                    strcpy(subject_clone,remove_Underscore(mail.message_subject));
                    printf("%s",subject_clone);
                    char info_clone[50];
                    strcpy(info_clone,remove_Underscore(mail.info));
                    print_Spaces(63-39-strlen(mail.message_subject)-1);
                    printf("%s",info_clone);
                    count++;
                    print_New_Line(1);
                }
            }
            fclose(fp);
            print_New_Line(1);
            printf("------------------------------------------------------------------------------");
            print_New_Line(4);
            print_Spaces(20);
            printf("1.Open Mail.");
            print_Spaces(15);
            printf("2. <- (Back)");
            print_New_Line(3);
            int ch;
            print_Spaces(30);
            printf("Enter your choice : ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                {
                    int serial_number;
                    int inner_loop = 1;
                    while(inner_loop)
                    {
                        print_New_Line(2);
                        print_Spaces(30);
                        printf("Enter Email SN : ");
                        scanf("%d",&serial_number);
                        if(serial_number <0 || serial_number > count)
                        {
                            print_New_Line(1);
                            print_Spaces(30);
                            printf("Invalid Email SN.");
                        }
                        else
                        {
                            inner_loop = 0;
                        }
                    }//while
            system("cls");
            int counter = 0;
            FILE *fp = fopen("Mail.txt","r");
            while(fscanf(fp,"%s%s%s%s%s",mail.sender_user_name,mail.receiver_user_name,mail.message_subject,
                    mail.message,mail.info) != EOF)
            {
                if(strcmp(user_name_clone,mail.sender_user_name) == 0)
                {
                    if(counter == serial_number)
                    {
                        print_New_Line(4);
                        print_Spaces(30);
                        printf("MESSAGE SENT");
                        print_New_Line(3);
                        print_Spaces(4);
                        printf("From    : %s",mail.sender_user_name);
                        print_New_Line(2);
                        print_Spaces(4);
                        printf("To      : %s",mail.receiver_user_name);
                        print_New_Line(2);
                        print_Spaces(4);
                        char message_subject_clone[50];
                        strcpy(message_subject_clone,remove_Underscore(mail.message_subject));
                        printf("Subject : %s",message_subject_clone);
                        print_New_Line(2);
                        printf("    --------------------------------------------------------------------------");
                        print_New_Line(1);
                   //     print_Spaces(15);
                        char message_clone[10000];
                        strcpy(message_clone,remove_Underscore(mail.message));
                        printf("%s",message_clone);
                        print_New_Line(4);
                        print_Spaces(25);
                        printf("Press any key to continue...");
                        break; // while
                    }else
                    {
                        counter++;
                    }
                }
            }
            fclose(fp);
            getch();
            break;
        }
        case 2:
            {
                loop = 0;
                break;
            }
        default:
            {
                print_New_Line(4);
                print_Spaces(25);
                printf("Please enter correct option.");
                break;
            }
        }
    }
    else
    {
        print_New_Line(3);
        print_Spaces(25);
        printf("Message sent is currently empty...");
        loop = 0;
    }
    }
    print_New_Line(4);
    print_Spaces(25);
    printf("Press any key to continue...");
    getch();
}


void compose_Message(char sender_user_name[])
{
    system("cls");
    print_New_Line(4);
    print_Spaces(35);
    printf("COMPOSE");
    print_New_Line(2);
    print_Spaces(4);
    char receiver_user_name[52];
    char message_subject[100];
    printf("New Message");
    int is_valid_user_name=1;
    int loop = 1;
    while(loop)
    {
        print_New_Line(2);
        print_Spaces(4);
        printf("To ");
        scanf("%s",receiver_user_name);
        char receiver_user_name_clone[50];
        strcpy(receiver_user_name_clone,receiver_user_name);
        if(strcmp("Admin",receiver_user_name) != 0)
        {
            if(strcmp(receiver_user_name,sender_user_name) == 0)
            {
                is_valid_user_name = 0;
            }else
            {
                is_valid_user_name=check_User_Name(receiver_user_name_clone);
            }
            if(is_valid_user_name == 1)
                loop = 0;
            else
            {
                print_New_Line(1);
                print_Spaces(4);
                printf("Invalid Username.");
            }

        }else
        {
            loop = 0;
        }
    }
    print_New_Line(1);
    print_Spaces(4);
    printf("Subject ");
    clear_input_buffer();
    gets(message_subject);
    print_New_Line(1);
    print_Spaces(4);
    printf("----------------------------------------------------------------------------");
    char message[10000];//message limit is 10000 characters
    gets(message);

    FILE * fp = fopen("Mail.txt","a");
    char info_clone[50];
    strcpy(mail.sender_user_name,sender_user_name);
    strcpy(mail.receiver_user_name,receiver_user_name);
    char message_subject_clone[100];
    strcpy(message_subject_clone,insert_Underscore(message_subject));
    strcpy(mail.message_subject,message_subject_clone);
    char message_clone[10000];
    strcpy(message_clone,insert_Underscore(message));
    strcpy(mail.message,message_clone);
    strcpy(info_clone,get_info());
    strcpy(mail.info,info_clone);
    fprintf(fp,"%s\t%s\t%s\t%s\t%s\n",mail.sender_user_name,mail.receiver_user_name,mail.message_subject,
                    mail.message,mail.info);
    fclose(fp);
    print_New_Line(1);
    print_Spaces(4);
    printf("----------------------------------------------------------------------------");
    print_New_Line(3);
    print_Spaces(30);
    printf("Message sent successfully.");
    print_New_Line(3);
    print_Spaces(30);
    printf("Press any key to continue...");
    getch();
}

void change_Admin_Password()
{
    system("cls");
    int old_admin_password_matched = 0;
    int valid_new_admin_password = 0;
    char admin_old_password[50],admin_new_password[50],admin_new_password_rentered[50];
    print_New_Line(4);
    print_Spaces(30);
    printf("CHANGE PASSWORD");
    print_New_Line(4);
    print_Spaces(30);
    printf("Enter old password  : ");
    scanf("%s",admin_old_password);
    print_New_Line(2);
    print_Spaces(30);
    printf("Enter new password  : ");
    scanf("%s",admin_new_password);
    print_New_Line(2);
    print_Spaces(30);
    printf("Renter new password : ");
    scanf("%s",admin_new_password_rentered);
    FILE *fp = fopen("AdminPassword.txt","r");
    fscanf(fp,"%s",admin.pWord);
    if(strcmp(admin.pWord,admin_old_password) == 0 )
        old_admin_password_matched = 1;
    fclose(fp);
    if(old_admin_password_matched)
    {
        if(strcmp(admin_new_password,admin_new_password_rentered) == 0)
        {
            //proceed to change admin password
            FILE *fp = fopen("AdminPassword.txt","w");
            strcpy(admin.pWord,admin_new_password);
            fprintf(fp,"%s",admin.pWord);
            fclose(fp);
            print_New_Line(2);
            print_Spaces(30);
            printf("Password changed successfully.");
         }else
         {
            print_New_Line(2);
            print_Spaces(30);
            printf("New password didn\'t match.");
         }
    }else
    {
        print_New_Line(2);
        print_Spaces(30);
        printf("Old password didn\'t match.");
    }
    print_New_Line(4);
    print_Spaces(30);
    printf("Press any key to return...");
    getch();
}



void display_User_Home_Screen()
{
    int choice,loop = 1;
    while(loop)
    {
        system("cls");
        print_New_Line(7);
        print_Spaces(30);
        printf("USER HOME SCREEN\n");
        print_New_Line(3);
        print_Spaces(15);
        printf("1. Register");
        print_Spaces(10);
        printf("2. Log In");
        print_Spaces(10);
        printf("3. <- (BACK)");
        print_New_Line(4);
        print_Spaces(30);
        printf("Enter your choice(1-3) : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                {
                    register_New_User();
                    break;
                }
            case 2:
                {
                    user_Log_In();
                    break;
                }
            case 3:
                {
                    loop = 0;
                    break;
                }
            default:
                {
                    print_New_Line(2);
                    print_Spaces(30);
                    printf("Please enter correct option.\n");

                    break;
                }
        }
    }
}


void register_New_User()
{
    // Admin is reserved username!!!!
    system("cls");
    print_New_Line(7);
    print_Spaces(30);
    printf("REGISTER SCREEN\n");
    print_Spaces(30);
    FILE *fp;
    char user_name_clone[100];
    int duplicate_user_name = 1;
    char fName[50],lName[50],user_name[50],pWord[50];
    fp = fopen("UserAccount.txt","a");
    print_New_Line(2);
    print_Spaces(30);
    printf("First Name : ");
    scanf("%s",fName);
    print_New_Line(1);
    print_Spaces(30);
    printf("Last Name  : ");
    scanf("%s",lName);
    while(duplicate_user_name)
    {
        print_New_Line(1);
        print_Spaces(30);
        printf("User name  : ");
        scanf("%s",user_name);
        strcpy(user_name_clone,user_name);
        if(strcmp(user_name_clone,"Admin")==0)
        {
            duplicate_user_name =1; //  cannot make username as "Admin"
        }
        else{
            duplicate_user_name = check_User_Name(user_name_clone);
        }

        if(duplicate_user_name)
        {
            print_New_Line(1);
            print_Spaces(30);
             printf("Sorry, User name already in use.\n");
        }

    }
    print_New_Line(1);
    print_Spaces(30);
    printf("PassWord   : ");
    scanf("%s",pWord);
    uAccount.user_balance = 0;
    strcpy(uAccount.user_name,user_name);
    strcpy(uAccount.fName,fName);
    strcpy(uAccount.lName,lName);
    strcpy(uAccount.user_name,user_name);
    strcpy(uAccount.pWord,pWord);
    strcpy(uAccount.info,get_info());
    fprintf(fp,"%s\t%s\t%s\t%s\t%d\t%s\n",uAccount.fName,uAccount.lName,
                                                uAccount.user_name,uAccount.pWord,
                                                uAccount.user_balance,uAccount.info);
    fclose(fp);
    print_New_Line(2);
    print_Spaces(30);
    printf("Registered successfully.");
    print_New_Line(2);
    print_Spaces(26+4);
    printf("Press any key to return...");
    getch();
}


void user_Log_In()
{
    system("cls");
    print_New_Line(7);
    print_Spaces(30);
    printf("LOGIN MENU\n");
    print_Spaces(30);
    print_New_Line(3);
    char user_name[10],pWord[20];
    char user_name_clone[50];
    int user_matched = 0;
    int user_balance;
    char fName[10];
    print_Spaces(30);
    printf("Username : ");
    scanf("%s",user_name);
    print_New_Line(1);
    print_Spaces(30);
    printf("Password : ");
    scanf("%s",pWord);
    FILE *fp;
    fp = fopen("UserAccount.txt","r");
    while(fscanf(fp,"%s%s%s%s%d%s",uAccount.fName,
                                    uAccount.lName,uAccount.user_name,
                                    uAccount.pWord,
                                    &uAccount.user_balance,uAccount.info) != EOF)
    {
        if((strcmp(user_name,uAccount.user_name)==0) && (strcmp(pWord,uAccount.pWord)==0))
        {
            strcpy(user_name_clone,uAccount.user_name);
            strcpy(fName,uAccount.fName);
            user_balance = uAccount.user_balance;
            user_matched = 1;
            break;
        }
    }
    fclose(fp);
    if(user_matched)
    {
        display_User_Operation(user_name_clone);
    }else
    {
        print_New_Line(1);
        print_Spaces(30);
        printf("Cannot Log In!!!\n");
    }
    print_New_Line(1);
    print_Spaces(30);
    printf("Press any key to return...");
    getch();
}


void display_User_Operation(char user_name[10])
{
    int choice,loop = 1,user_balance;
    char user_name_clone[50],fName_clone[50];
    strcpy(user_name_clone,user_name);
    FILE *fp;
    while(loop)
    {
    fp = fopen("UserAccount.txt","r");
    while(fscanf(fp,"%s%s%s%s%d%s",uAccount.fName,
                                    uAccount.lName,uAccount.user_name,
                                    uAccount.pWord,
                                    &uAccount.user_balance,uAccount.info) != EOF)
    {
        system("cls");
        if(strcmp(user_name_clone,uAccount.user_name) == 0)
        {
            user_balance = uAccount.user_balance;
            strcpy(fName_clone,uAccount.fName);
        }
    }
    fclose(fp);
    print_New_Line(2);
    print_Spaces(10);
    printf("Hi %s,\n\n",fName_clone);
    print_Spaces(30);
    printf("Balance(Rs) : %d\n\n",user_balance);
    print_New_Line(4);
    print_Spaces(10);
    printf("1. Recharge");
    print_Spaces(10);
    printf("2. Book Ticket");
    print_Spaces(10);
    printf("3. Fund Transfer");
    print_New_Line(2);
    print_Spaces(10);
    printf("4. Mail");
    print_Spaces(11+3);
    printf("5. History.");
    print_Spaces(10+3);
    printf("6. Log out.");
    print_New_Line(4);
    print_Spaces(30);
    printf("Enter your choice(1-4) : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
            recharge_Account(user_name_clone);
            break;
        }
    case 2:
        {
            book_Movie_Ticket(user_name_clone);
            break;
        }
    case 3:
        {
            transfer_User_Fund(user_name_clone);
            break;
        }
    case 4:
        {
            display_Mail_Menu(user_name_clone);
            break;
        }
    case 5:
        {
            view_User_History(user_name_clone);
            break;
        }
    case 6:
        {
            print_New_Line(1);
            print_Spaces(30);
            printf("Logged out successfully.");
            print_New_Line(1);
            loop = 0;
            break;
        }
    default:
        {
            print_New_Line(1);
            print_Spaces(30);
            printf("Please enter correct number(1-4).\n\n");

            break;
        }
    }//switch
 }//loop
}

void recharge_Account(char user_name[])
{
    system("cls");
    FILE *fp,*fp1,*fp2,*fp3;
    char pin_id[12],user_name_clone[10];
    int pin_matched = 0,recharge_amount;
    strcpy(user_name_clone,user_name);
    print_New_Line(8);
    print_Spaces(30);
    printf("PIN number:");
    scanf("%s",pin_id);
    fp = fopen("RechargePinList.txt","r");
    fp1 = fopen("UserAccount.txt","r");
    fp2 = fopen("UserAccount1.txt","w");
    fp3 = fopen("RechargeHistory.txt","a");
    while(fscanf(fp,"%s%d",pNumber.pin_number,&pNumber.recharge_amount)!=EOF)
    {
        if(strcmp(pin_id,pNumber.pin_number) == 0)
        {
            //update user balance
          pin_matched = 1;
          while(fscanf(fp1,"%s%s%s%s%d%s",uAccount.fName,uAccount.lName,
                                          uAccount.user_name,uAccount.pWord,
                                          &uAccount.user_balance,uAccount.info)!= EOF)
          {
                if(strcmp(user_name_clone,uAccount.user_name) == 0)
                {
                    //make modification to user balance
                    recharge_amount = pNumber.recharge_amount;
                    uAccount.user_balance = uAccount.user_balance + pNumber.recharge_amount;
                    //Save username,recharged balance and info
                    char clone_info[50];
                    strcpy(rHistory.user_name,uAccount.user_name);
                    rHistory.recharge_amt=pNumber.recharge_amount;
                    strcpy(rHistory.info,get_info());
                    fprintf(fp3,"%s\t%d\t%s\n",rHistory.user_name,rHistory.recharge_amt,rHistory.info);
                }
                fprintf(fp2,"%s\t%s\t%s\t%s\t%d\t%s\n",uAccount.fName,uAccount.lName,
                                                uAccount.user_name,uAccount.pWord,
                                                uAccount.user_balance,uAccount.info);
            }//while
          }//if
    }//while
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    //remove recharged PIN number from PIN List
    if(pin_matched)
    {
        print_New_Line(2);
        print_Spaces(30);
        printf("Your account has been credited Rs : %d.",recharge_amount);
        remove("UserAccount.txt");
        rename("UserAccount1.txt","UserAccount.txt");
        fp = fopen("RechargePinList.txt","r");
        fp1 = fopen("RechargePinList1.txt","w");
        while(fscanf(fp,"%s%d",pNumber.pin_number,&pNumber.recharge_amount)!=EOF)
         {
            if(strcmp(pin_id,pNumber.pin_number) != 0)
            fprintf(fp1,"%s\t%d\n",pNumber.pin_number,pNumber.recharge_amount);
         }
        fclose(fp);
        fclose(fp1);
        remove("RechargePinList.txt");
        rename("RechargePinList1.txt","RechargePinList.txt");
    }
    else
    {
        print_New_Line(2);
        print_Spaces(30);
        printf("Invalid PIN number.\n");
    }
    print_New_Line(2);
    print_Spaces(30);
    printf("Press any key to return...");
        getch();
}



void book_Movie_Ticket(char user_name[])
{
    view_Movie_Details('b');
    print_New_Line(4);
    print_Spaces(30);
    printf("MOVIE BOOKING");
    int seat_Num;
    char user_name_clone[10];
    strcpy(user_name_clone,user_name);
    char movie_id[10];
    int movie_found = 0;
    int enough_balance = 0;
    int ticket_price;
    print_New_Line(3);
    print_Spaces(30);
    printf("Movie ID : ");
    scanf("%s",movie_id);
    FILE *fp,*fp1,*fp3,*fp4,*fp5,*fp6,*fp7;
    char movie_name[100];
    fp = fopen("MovieList.txt","r");
    fp1 = fopen("UserAccount.txt","r");
    fp7 = fopen("TicketBookedHistory.txt","a");
    //check if movie ID is valid
       while(fscanf(fp,"%s%s%d%s%s%s%s\n",mList.movie_id,mList.movie_name,&mList.ticket_price,
                                    mList.movie_length,mList.movie_genre,
                                    mList.movie_language,mList.ms.m_seat)!=EOF)
       {
            if(strcmp(movie_id,mList.movie_id)==0  )
            {
                //movie ID matched
                movie_found = 1;
                ticket_price = mList.ticket_price;
                strcpy(movie_name,mList.movie_name);
                //movie ID is valid so check User balance
                 while(fscanf(fp1,"%s%s%s%s%d%s",uAccount.fName,uAccount.lName,
                                                uAccount.user_name,uAccount.pWord,
                                                &uAccount.user_balance,uAccount.info)!= EOF)
                 {
                    if(strcmp(user_name_clone,uAccount.user_name)== 0 && (uAccount.user_balance >= ticket_price))
                    {
                        enough_balance = 1;
                    }
                 }
            }
       }//while
    fclose(fp);//MovieList.txt 'r'
    fclose(fp1);//UserAccount.txt 'r'
    if(movie_found)
    {
        fp = fopen("MovieList.txt","r");
        while(fscanf(fp,"%s%s%d%s%s%s%s\n",mList.movie_id,mList.movie_name,&mList.ticket_price,
                                    mList.movie_length,mList.movie_genre,
                                    mList.movie_language,mList.ms.m_seat)!=EOF)
       {
           if(strcmp(movie_id,mList.movie_id) == 0)
           {
               display_Seats(mList.ms.m_seat);
               break;
           }
       }
        fclose(fp);
        print_New_Line(1);
        print_Spaces(30);
        printf("Seat Number : ");
        scanf("%d",&seat_Num);
        if(enough_balance)
        {
            fp3 = fopen("MovieList.txt","r");
            fp4 = fopen("MovieList1.txt","w");
            while(fscanf(fp3,"%s%s%d%s%s%s%s\n",mList.movie_id,mList.movie_name,&mList.ticket_price,
                                    mList.movie_length,mList.movie_genre,
                                    mList.movie_language,mList.ms.m_seat)!=EOF)
            {
                if(strcmp(movie_id,mList.movie_id)==0)
                {
                    if(mList.ms.m_seat[seat_Num] == 'B' )
                    {
                        print_New_Line(1);
                        print_Spaces(30);
                        printf("Sorry, seat already reserved.\n");
                    }else if(seat_Num < 0 || seat_Num >9)
                    {
                        print_New_Line(1);
                        print_Spaces(30);
                        printf("Invalid seat number.\n");
                    }
                    else
                    {
                        mList.ms.m_seat[seat_Num] = 'B';
                        //decrease user balance
                        fp5 = fopen("UserAccount.txt","r");
                        fp6 = fopen("UserAccount1.txt","w");
                        while(fscanf(fp5,"%s%s%s%s%d%s",uAccount.fName,uAccount.lName,
                                    uAccount.user_name,uAccount.pWord,
                                    &uAccount.user_balance,uAccount.info)!= EOF)
                            {
                                        if(strcmp(user_name_clone,uAccount.user_name) == 0)
                                        {
                                            uAccount.user_balance = uAccount.user_balance - ticket_price;
                                        }
                                        fprintf(fp6,"%s\t%s\t%s\t%s\t%d\t%s\n",uAccount.fName,uAccount.lName,
                                                uAccount.user_name,uAccount.pWord,
                                                uAccount.user_balance,uAccount.info);
                            }//whiile
                           fclose(fp5);//UserAccount 'r'
                           fclose(fp6);//UserAccount 'w'
                           remove("UserAccount.txt");
                           rename("UserAccount1.txt","UserAccount.txt");
                           char info[50];
                           strcpy(bHistory.info,get_info());
                           strcpy(bHistory.user_name,user_name_clone);
                           strcpy(bHistory.movie_name,movie_name);
                           strcpy(bHistory.movie_id,movie_id);
                           bHistory.ticket_price = ticket_price;
                           fprintf(fp7,"%s\t%s\t%s\t%d\t%s\n",bHistory.user_name,
                                                           bHistory.movie_name,bHistory.movie_id,
                                                           bHistory.ticket_price,bHistory.info);
                            print_New_Line(1);
                            print_Spaces(30);
                            printf("Ticket Booked...\n");
                    }//else
                }
                fprintf(fp4,"%s\t%s\t%d\t%s\t%s\t%s\t%s\n",mList.movie_id,mList.movie_name,mList.ticket_price,
                                    mList.movie_length,mList.movie_genre,
                                    mList.movie_language,mList.ms.m_seat);
            }//while
            fclose(fp3);//MovieList 'r'
            fclose(fp4);//MovieList1 'w'
            fclose(fp7);
            remove("MovieList.txt");
            rename("MovieList1.txt","MovieList.txt");
        }//if enough balance
        else
        {
            print_New_Line(1);
            print_Spaces(30);
            printf("Insufficient fund!\n");
        }
    }// if movie_found
    else
    {
        print_New_Line(1);
        print_Spaces(30);
        printf("Cannot find movie... \n");
    }
    print_New_Line(1);
    print_Spaces(30);
    printf("Press any key to return...");
    getch();
}


void transfer_User_Fund(char user_name[])
{
    system("cls");
    char transferer_user_name_clone[50],receiver_user_name[50];
    int transfer_amount;
    strcpy(transferer_user_name_clone,user_name);
    print_New_Line(6);
    print_Spaces(30);
    printf("FUND TRANSFER\n");
    print_New_Line(3);
    print_Spaces(15);
    printf("Note: Cannot make transfer of less than Rs 100.\n");
    print_New_Line(2);
    print_Spaces(27);
    printf("Username(Receiver) : ");
    scanf("%s",receiver_user_name);
    print_New_Line(1);
    print_Spaces(27);
    printf("Transfer Amount(Rs) : ");
    scanf("%d",&transfer_amount);
    int valid_transfer_amount  = 0,valid_receiver_user_name = 0;
    FILE *fp,*fp1;
    fp = fopen("UserAccount.txt","r");
        if(strcmp(transferer_user_name_clone,receiver_user_name) == 0)
        {
            valid_receiver_user_name = 0;
        }
        else
        {
         //check for receiver user_name
         while(fscanf(fp,"%s%s%s%s%d%s",uAccount.fName,uAccount.lName,
                 uAccount.user_name,uAccount.pWord,
                 &uAccount.user_balance,uAccount.info)!= EOF)
            {
                if(strcmp(receiver_user_name,uAccount.user_name) == 0)
                {
                    valid_receiver_user_name = 1;
                    break;
                }
            }

        }
    fclose(fp);
    // check for transferrer balance
    if(valid_receiver_user_name)
    {
        fp = fopen("UserAccount.txt","r");
        while(fscanf(fp,"%s%s%s%s%d%s",uAccount.fName,uAccount.lName,
                 uAccount.user_name,uAccount.pWord,
                 &uAccount.user_balance,uAccount.info)!= EOF)
            {

                if(strcmp(transferer_user_name_clone,uAccount.user_name)==0)
                {

                    if(transfer_amount > 99 && transfer_amount <= uAccount.user_balance)
                    {

                        valid_transfer_amount = 1;
                        break;
                    }
                }
            }
        fclose(fp);
        if(valid_transfer_amount)
        {
            //decrease transferer balance
            fp = fopen("UserAccount.txt","r");
            fp1 = fopen("UserAccount1.txt","w");
            while(fscanf(fp,"%s%s%s%s%d%s",uAccount.fName,uAccount.lName,
                 uAccount.user_name,uAccount.pWord,
                 &uAccount.user_balance,uAccount.info)!= EOF)
            {
                if(strcmp(uAccount.user_name,transferer_user_name_clone) == 0)
                {
                    //reduce user_balance
                    uAccount.user_balance = uAccount.user_balance - transfer_amount;
                }
                fprintf(fp1,"%s\t%s\t%s\t%s\t%d\t%s\n",uAccount.fName,uAccount.lName,
                                                uAccount.user_name,uAccount.pWord,
                                                uAccount.user_balance,uAccount.info);
            }
            fclose(fp);
            fclose(fp1);
            remove("UserAccount.txt");
            rename("UserAccount1.txt","UserAccount.txt");
            //increase receiver balance
            fp = fopen("UserAccount.txt","r");
            fp1 = fopen("UserAccount1.txt","w");
            while(fscanf(fp,"%s%s%s%s%d%s",uAccount.fName,uAccount.lName,
                 uAccount.user_name,uAccount.pWord,
                 &uAccount.user_balance,uAccount.info)!= EOF)
            {
                if(strcmp(uAccount.user_name,receiver_user_name) == 0)
                {
                    //reduce user_balance
                    uAccount.user_balance = uAccount.user_balance + transfer_amount;
                }
                fprintf(fp1,"%s\t%s\t%s\t%s\t%d\t%s\n",uAccount.fName,uAccount.lName,
                                                uAccount.user_name,uAccount.pWord,
                                                uAccount.user_balance,uAccount.info);
            }
            fclose(fp);
            fclose(fp1);
            remove("UserAccount.txt");
            rename("UserAccount1.txt","UserAccount.txt");
            fp = fopen("FundTransferHistory.txt","a");
            strcpy(fHistory.transferer_user_name,transferer_user_name_clone);
            strcpy(fHistory.receiver_user_name,receiver_user_name);
            char info[50];
            strcpy(info,get_info());
            strcpy(fHistory.info,info);
            fHistory.transfer_amount = transfer_amount;
            fprintf(fp,"%s\t%s\t%d\t%s\n",fHistory.transferer_user_name,
                    fHistory.receiver_user_name,
                    fHistory.transfer_amount,fHistory.info);
            fclose(fp);
            print_New_Line(1);
            print_Spaces(27);
            printf("Fund Transferred Successfully.\n");
        }else
        {
            print_New_Line(1);
            print_Spaces(27);
            printf("Invalid transfer amount.\n");
        }
    }else
    {
            print_New_Line(1);
            print_Spaces(30);
            printf("Invalid Username.\n");
    }
            print_New_Line(3);
            print_Spaces(27);
            printf("Press any key to return...");
getch();
}


void view_User_History(char user_name[])
{
    system("cls");
    int found_recharge_history = 0;
    int found_ticket_booked_history = 0;
    int found_fund_received_history = 0;
    int found_fund_transfered_history = 0;
    char user_name_clone[50];
    strcpy(user_name_clone,user_name);
    FILE *fp1,*fp2;
    fp1 = fopen("RechargeHistory.txt","r");
    fp2 = fopen("TicketBookedHistory.txt","r");
    print_New_Line(3);
    print_Spaces(30);
    printf("RECHARGE HISTORY");
    print_New_Line(4);
    while(fscanf(fp1,"%s%d%s",rHistory.user_name,&rHistory.recharge_amt,rHistory.info)!= EOF)
    {
        if(strcmp(user_name_clone,rHistory.user_name) == 0)
            found_recharge_history = 1;
    }
    fclose(fp1);
    if(found_recharge_history){

        fp1 = fopen("RechargeHistory.txt","r");
        printf("-----------------------------------------------------------------------------\n");
        while(fscanf(fp1,"%s\t%d\t%s\n",rHistory.user_name,&rHistory.recharge_amt,rHistory.info)!= EOF)
        {
        if(strcmp(user_name_clone,rHistory.user_name) == 0)
        {
            printf("Your account has been credited Rs : %d , ",rHistory.recharge_amt);
            parse_And_Print_Info(rHistory.info);
        }
        }
        fclose(fp1);
    }else
    {
        printf("Recharge History is currently empty.\n\n");
    }
    print_New_Line(3);
    print_Spaces(30);
    printf("TICKET BOOKED HISTORY");
    print_New_Line(4);
    while(fscanf(fp2,"%s%s%s%d%s",bHistory.user_name,bHistory.movie_name,bHistory.movie_id,
                                                     &bHistory.ticket_price,bHistory.info) != EOF)
    {
        if(strcmp(user_name_clone,bHistory.user_name) == 0)
        {
            found_ticket_booked_history = 1;
        }
    }
    fclose(fp2);
    if(found_ticket_booked_history)
    {
        fp2 = fopen("TicketBookedHistory.txt","r");
        //12 28 40 56
        printf("User Name   Movie Name                    ID    Price  Info\n");
        printf("-----------------------------------------------------------------------------\n");
        while(fscanf(fp2,"%s%s%s%d%s",bHistory.user_name,bHistory.movie_name,bHistory.movie_id,
                                                     &bHistory.ticket_price,bHistory.info)!= EOF)
        {
            if(strcmp(user_name_clone,bHistory.user_name) == 0)
            {
                printf("%s",bHistory.user_name);
                print_Spaces(12 - strlen(bHistory.user_name));
                char movie_name_clone[50];
                strcpy(movie_name_clone,remove_Underscore(bHistory.movie_name));
                printf("%s",movie_name_clone);
                print_Spaces(28 - 12 - strlen(bHistory.movie_name)+8+6);
                printf("%s",bHistory.movie_id);
                print_Spaces(40 - 28 - strlen(bHistory.movie_id)-6);
                printf("%d",bHistory.ticket_price);
                print_Spaces(56 - 40 - number_Digits(bHistory.ticket_price)-1-8);
                //   printf("%s",bHistory.info);
                parse_And_Print_Info(bHistory.info);
            }
        }
        fclose(fp2);
    }else{
        printf("Ticket booked history is currently empty.\n\n");
    }
    print_New_Line(3);
    print_Spaces(30);
    printf("FUND RECEIVED HISTORY");
    print_New_Line(4);
    fp1 = fopen("FundTransferHistory.txt","r");
    while(fscanf(fp1,"%s%s%d%s",fHistory.transferer_user_name,
                 fHistory.receiver_user_name,&fHistory.transfer_amount) != EOF)
    {
        if(strcmp(fHistory.receiver_user_name,user_name_clone) == 0)
        {
            found_fund_received_history = 1;
        }
    }
    fclose(fp1);
    if(found_fund_received_history)
    {
         printf("----------------------------------------------------------------------------\n");
        fp1 = fopen("FundTransferHistory.txt","r");
        while(fscanf(fp1,"%s%s%d%s",fHistory.transferer_user_name,
                 fHistory.receiver_user_name,&fHistory.transfer_amount,fHistory.info) != EOF)
        {
            if(strcmp(user_name_clone,fHistory.receiver_user_name)==0)
            {
                    printf("Fund received Rs. %d from %s , ",fHistory.transfer_amount,
                                                    fHistory.transferer_user_name);
                    parse_And_Print_Info(fHistory.info);
            }
        }
        fclose(fp1);
    }else
    {
        printf("Fund Received History is currently empty.");
    }
    print_New_Line(3);
    print_Spaces(30);

    printf("FUND TRANSFERED HISTORY");
    print_New_Line(4);
    fp1 = fopen("FundTransferHistory.txt","r");
    while(fscanf(fp1,"%s%s%d%s",fHistory.transferer_user_name,
                 fHistory.receiver_user_name,&fHistory.transfer_amount) != EOF)
    {
        if(strcmp(fHistory.transferer_user_name,user_name_clone) == 0)
        {
            found_fund_transfered_history = 1;
        }
    }
    fclose(fp1);
    if(found_fund_transfered_history)
    {
        printf("----------------------------------------------------------------------------\n");
        fp1 = fopen("FundTransferHistory.txt","r");
        while(fscanf(fp1,"%s%s%d%s",fHistory.transferer_user_name,
                 fHistory.receiver_user_name,&fHistory.transfer_amount,fHistory.info) != EOF)
        {
            if(strcmp(user_name_clone,fHistory.transferer_user_name)==0)
            {
            printf("Fund transferred Rs. %d to %s , ",fHistory.transfer_amount,
                                                    fHistory.receiver_user_name);
            parse_And_Print_Info(fHistory.info);
            }
        }
        fclose(fp1);
    }else
    {
        printf("Fund Transferred History is currently empty.");
    }

    print_New_Line(3);
    print_Spaces(30);
    printf("Press any key to return...");
    getch();
}


void display_Seats(char seats[])
{
        print_New_Line(1);
        print_Spaces(32);
        printf("SEATS");
        print_New_Line(2);
        print_Spaces(31);
        printf("-------");
        print_New_Line(1);
        print_Spaces(30);
        printf("| %c | %c | ",seats[0],seats[1]);
        print_New_Line(1);
        print_Spaces(28-1);
        printf("---------------");
        print_New_Line(1);
        print_Spaces(28-1-1);
        printf("| %c | %c | %c | %c | ",seats[2],seats[3],seats[4],seats[5]);
        print_New_Line(1);
        print_Spaces(28-1-1);
        printf("|---------------|");
        print_New_Line(1);
        print_Spaces(28-1-1);
        printf("| %c | %c | %c | %c | ",seats[6],seats[7],seats[8],seats[9]);
        print_New_Line(1);
        print_Spaces(28-1);
        printf("---------------\n");
        print_New_Line(1);
        print_Spaces(28-1);
        printf("Note: *B = Booked Seats.");
        print_New_Line(1);
}



int available_Seats(char seats[])
{
    int i,total_available_seats=0;
    for(i = 0; i < 10 ;i++)
    {
        if(seats[i] != 'B')
            total_available_seats = total_available_seats + 1;
    }
    return total_available_seats;
}
//-------------------------------------------------------------------------------
char* remove_Underscore(char expression[])
{
    char expression_clone[10000];
    strcpy(expression_clone,expression);
    char final_expression[10000]="";
    int i;
    for(i = 0 ; i < strlen(expression) ;i++)
    {
        if(expression_clone[i] == '_')
            final_expression[i] = ' ';
        else
            final_expression[i] = expression_clone[i];
    }
    return final_expression;
}
//--------------------------------------------------------------------------------------------------------
char* insert_Underscore(char expression[])
{
 //   printf("SSSS....\n");
    char expression_clone[10000]="";
    strcpy(expression_clone,expression);
    char final_expression[10000]="";
    int i,j,k=0;
 /*   for(i = 0 ; i < strlen(expression_clone) ; i++)
    {
        if(expression_clone[i] == ' ')
            final_expression[i]='_';
        else
            final_expression[i] = expression_clone[i];
    }*/
  //  printf("%s",final_expression);
 for(i = 0 ; i < strlen(expression_clone) ; i++)
    {
        if(expression_clone[i] == ' ')
        {
        //   printf("hercules\n");
            final_expression[k] = '_';
            k++;
        }
        else if(expression_clone[i] == '\t')
        {
           /* for(j = k ; j < 8+k ;j++)
            {
                 final_expression[j] = '_';
            }
            k = j;*/

            int max_char_per_line=79;
            int resolved_index = k % (max_char_per_line+1);

            int num_underscore = 0;

            if(resolved_index <= max_char_per_line - 6)
                num_underscore = 7;
            else
            {
                int l;
                for(l = resolved_index ; l <= max_char_per_line ; l++)
                    num_underscore++;
            }
            for(j = k ; j < (k + num_underscore) ;j++)
            {
                final_expression[j]='_';

            }
            k = j;
        }
        else
        {
             final_expression[k] = expression_clone[i];

             k++;
        }

    }
  //  printf("%s\n",final_expression);
    return final_expression;
}
//-------------------------------------------------------------------------------------------------------------------------------
int is_Invalid_Movie_Id(char movie_id[])
{
    FILE *fp;
    char movie_id_clone[50];
    strcpy(movie_id_clone,movie_id);
    fp = fopen("MovieList.txt","r");
    int invalid_movie_id = 0;
    while(fscanf(fp,"%s%s%d%s%s%s%s\n",mList.movie_id,mList.movie_name,&mList.ticket_price,
                                    mList.movie_length,mList.movie_genre,
                                    mList.movie_language,mList.ms.m_seat)!=EOF)
        {
            if(strcmp(movie_id_clone,mList.movie_id) == 0)
            {
                invalid_movie_id = 1;
                break;
            }
        }
    fclose(fp);
    return invalid_movie_id;
}
//-------------------------------------------------------------------------------------------------------------
char* parse_And_Print_Info(char info[])
{
    char info_clone[50],info_clone1[50];
    strcpy(info_clone,info);
    int i;
    for(i = 0 ; i < strlen(info_clone) ;i++)
    {
        if(info_clone[i] == '_')
            info_clone1[i] = ' ';
        else
            info_clone1[i] = info_clone[i];
    }
    for(i = 0 ; i < strlen(info) ;i++)
    {
        printf("%c",info_clone1[i]);
    }
    print_New_Line(1);
}
//-----------------------------------------------------------------------------------------------------------------------------------
int check_User_Name(char user_name[])
{
    FILE *fp = fopen("UserAccount.txt","r");
    while(fscanf( fp,"%s%s%s%s%d%s",uAccount.fName,uAccount.lName,
                                                uAccount.user_name,uAccount.pWord,
                                                &uAccount.user_balance,uAccount.info) != EOF)
    {
        if(strcmp(user_name,uAccount.user_name) == 0)
        {
        //    print_New_Line(1);
        //    print_Spaces(30);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return  0;
}
//-----------------------------------------------------------------------------------------------------------------------------------
char* get_info()
{
   time_t rawtime;
   struct tm *info;
   char buffer[80];

   time( &rawtime );
   info = localtime( &rawtime );

   strftime(buffer,80,"%a_%b_%d_%X_%Y", info);
   return buffer;
 //  printf("Formatted date & time : %s\n", buffer );
}
//-----------------------------------------------------------------------------------------------------------------------------------
void print_Spaces(int n)
{
    int i;
    for(i = 0 ; i < n; i++)
    {
        printf(" ");
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------
int number_Digits(int n)
{
    int count = 0;
    while(n!=0)
    {
      n/=10;             /* n=n/10 */
      ++count;
    }
    return (count > 0 ) ? count : 1;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void print_New_Line(int n)
{

    int i = 0 ;
    for(i = 0 ; i < n ;i++)
        printf("\n");
}
//-----------------------------------------------------------------------------------------------------------------------------------

