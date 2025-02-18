
#include<stdio.h>
#include<windows.h>//use for gotoxy()
#include<conio.h>//use for delay(),getch(),etc.
#include<ctype.h>//use for toupper(),tolower(),etc.
#include<string.h>//use for strcmp(),strlen(),etc.
#include<stdlib.h>
char ans;
int ok;
int b,valid=0;

//function declaration

void WelcomeScreen(void);//Welcomescreen function declaration
void Title(void);//Title function declaration
void MainMenu(void);//MainMenu function declaration
void LoginScreen(void);//LoginScreen function declaration
void Add_rec(void);//Add_rec function declaration
void func_list(void);//function to list the patient details
void Search_rec(void);//Search_rec function declaration
void Edit_rec (void);//Edit_rec function declaration
void Dlt_rec(void);//Dlt_rec function declaration
void ex_it (void);//exit function declaration
void gotoxy(short x, short y)
{
    COORD pos ={x,y}; //sets coordinates in (x,y).
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

//List of global variable

struct patient
{
int age;
char Gender;
char First_Name[20];
char Last_Name[20];
char contact_no[15];
char Address[30];
char Email[30];
char Doctor[20];
char Problem[20];
};
struct patient p,temp_c;
main(void)
{
WelcomeScreen();
Title();
LoginScreen();
}

void WelcomeScreen(void)
{

printf("\n\n\n\n\n\n\n\t\t\t\t\t#########################################");
printf("\n\t\t\t\t\t#\t\t WELCOME TO\t\t#");
printf("\n\t\t\t\t\t# CIVIL HOSPITAL MANAGEMENT SYSTEM      #");
printf("\n\t\t\t\t\t#########################################");
printf("\n\n\n\n\n Press any key to continue........\n");
getch();
system("cls");

}
void Title(void)
{
    printf("\n");
    printf("\n\t\t\t\t****  *****  *       *  *****  *             *    *  *****  *****  *****  *****   *****     *     *  ");
    printf("\n\t\t\t\t*       *     *     *     *    *             *    *  *   *  *      *   *    *       *      * *    *  ");
    printf("\n\t\t\t\t*       *      *   *      *    *             ******  *   *  *****  *****    *       *     *****   *");
    printf("\n\t\t\t\t*       *       * *       *    *             *    *  *   *      *  *        *       *    *     *  *");
    printf("\n\t\t\t\t****  *****      *      *****  *****         *    *  *****  *****  *      *****     *   *       * *****");
}
void LoginScreen(void)
{
    int e=0;
    int i=4;
    char Username[15];
    char Password[15];
    char original_Username[25]="biogroup";
    char original_Password[15]="1234";
    do {
    printf("\n\n\n\n\t\t\t\tEnter the username and password :) ");
    printf("\n\n\n\t\t\t\t\tUSERNAME:");
    scanf("%s",Username);
    printf("\n\n\t\t\t\t\tPASSWORD:");
    scanf("%s",Password);
     if(strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
       {
           printf("\n\n\n\t\t\t\t\t...Login Successfull...");
           getch();
           MainMenu();
           break;
       }
else
{
i--;
 if(strcmp(Username,original_Username)!=0)
 {
    printf("\n\t\t\t\t\tincorrect username!!(%d remaining)",i);
 }
 if(strcmp(Password,original_Password)!=0)
 {
     printf("\n\n\t\t\t\t\tincorrect password!!(%d remaining)",i);
 }
 getch();
 e++;
}}
while(e<4);
if(e>=4)
{

    printf("\n\n\t\t\t\t\tYou have cross the limit. You cannot login.:( :(");
    getch();
    ex_it();
}
system("cls");



}
void MainMenu(void)
{
    system("cls");
    int choose;
    Title();
    printf("\n\n\n\n\n\t\t\t\t1. Add Patient record\n");
    printf("\n\t\t\t\t2. List Patient Record\n");
    printf("\n\t\t\t\t3. Search Patient Record\n");
    printf("\n\t\t\t\t4. Edit Patient Record\n");
    printf("\n\t\t\t\t5. Delete Patient Record\n");
    printf("\n\t\t\t\t6. Exit\n");
    printf("\n\n\n\n\t\t\t\tChoose from 1 to 6:");
    scanf("%d",&choose);

    switch(choose)
{

case 1:
    Add_rec();
    break;
case 2:
    func_list();
    break;
case 3:
    Search_rec();
    break;
case 4:
    Edit_rec();
    break;
case 5:
    Dlt_rec();
    break;
case 6:
    ex_it();
    break;

default:
    printf("\t\t\tInvalid entry. Please enter right option:)");
    getch();
    MainMenu();
}

}
void Add_rec() {
    system("cls");
    Title();
    char ans;
    FILE *ek;
    ek = fopen("Record2.dat", "a");

    if (ek == NULL) {
        printf("\n\t\tError opening file.");
        getch();
        MainMenu();
    }

    printf("\n\n\n\n\t\t\t!!!!!!!!!!!!!!!Add Patient Record!!!!!!!!!!!!!!!!!\n");
    printf("\n\t\tFirst Name: ");
    scanf("%s", p.First_Name);
    p.First_Name[0] = toupper(p.First_Name[0]);

    printf("\n\t\tLast Name: ");
    scanf("%s", p.Last_Name);
    p.Last_Name[0] = toupper(p.Last_Name[0]);

    do {
        printf("\n\t\tGender[F/M]: ");
        scanf(" %c", &p.Gender);
        p.Gender = toupper(p.Gender);
    } while (p.Gender != 'F' && p.Gender != 'M');

    printf("\n\t\tAge: ");
    scanf("%d", &p.age);

    printf("\n\t\tAddress: ");
    scanf("%s", p.Address);
    p.Address[0] = toupper(p.Address[0]);
    B:
    printf("\n\t\tContact no: ");
    scanf("%s", p.contact_no);
    if(strlen(p.contact_no)<=10){
    printf("\n Contact number must be 10-digit\n");
    getch();
    goto B;
    }

    printf("\n\t\tEmail: ");
    scanf("%s", p.Email);

    printf("\n\t\tProblem: ");
    scanf("%s", p.Problem);
    p.Problem[0] = toupper(p.Problem[0]);

    printf("\n\t\tPrescribed doctor: ");
    scanf("%s", p.Doctor);
    p.Doctor[0] = toupper(p.Doctor[0]);

    fprintf(ek, "%s %s %c %d %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.contact_no, p.Email, p.Problem, p.Doctor);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);
A:
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c", &ans);

    if (toupper(ans) == 'Y') {
        Add_rec();
    } else if (toupper(ans) == 'N') {
        printf("\n\t\t Thank you:) :) ");
        getch();
        MainMenu();
    } else {
        printf("\n\t\tInvalid Input\n");
        goto A;
    }
}

void func_list(void) {
    int row;
    system("cls");
    Title();
    FILE *ek;
    ek=fopen("Record2.dat","r");
    printf("\n\n\n\n\n\n\t\t\t||||||||||||||||||||||List of Patients Record||||||||||||||||||");
    gotoxy(1,15);
    printf("|Full Name");
    gotoxy(20,15);
    printf("|Gender");
    gotoxy(32,15);
    printf("|Age");
    gotoxy(40,15);
    printf("|Address");
    gotoxy(60,15);
    printf("|Contact No. ");
    gotoxy(76,15);
    printf("|Email");
    gotoxy(100,15);
    printf("|Problem");
    gotoxy(110,15);
    printf("|Prescribed Doctor");
    gotoxy(130,15);
    printf("|\n");
    for(int i=0;i<=130;i++)
    {
        printf("=");
    }
    row=17;
    while(fscanf(ek,"%s %s %c %d %s %s %s %s %s\n",p.First_Name,p.Last_Name,&p.Gender,&p.age,p.Address,p.contact_no,p.Email,p.Problem,p.Doctor)!=EOF)
    {
        gotoxy(1,row);
        printf("|%s %s",p.First_Name,p.Last_Name);
        gotoxy(20,row);
        printf("|%c",p.Gender);
        gotoxy(32,row);
        printf("|%d",p.age);
        gotoxy(40,row);
        printf("|%s",p.Address);
        gotoxy(60,row);
        printf("|%s",p.contact_no);
        gotoxy(76,row);
        printf("|%s",p.Email);
        gotoxy(100,row);
        printf("|%s",p.Problem);
        gotoxy(110,row);
        printf("|%s",p.Doctor);
        gotoxy(130,row);
        printf("|\n");
        for(int j=0;j<=130;j++)
        {
            printf("_");
        }
        row=row+2;
    }
    fclose(ek);
    getch();
    MainMenu();
}


void Search_rec(void)
{
    char name[20];
    system("cls");
    Title();
    FILE *ek;
    ek=fopen("Record2.dat","r");
    printf("\n\n\n\n\t\t\t!!!!!!!!!!!!!!!Search patient Record!!!!!!!!!!!!!!!!\n");
    printf("\n Enter Patient Name to be viewed: ");
    scanf("%s",name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    while(fscanf(ek,"%s %s %c %d %s %s %s %s %s\n",p.First_Name,p.Last_Name,&p.Gender,&p.age,p.Address,p.contact_no,p.Email,p.Problem,p.Doctor)!=EOF)
    {
        if(strcmp(p.First_Name,name)==0)
        {
            gotoxy(1,15);
            printf("|Full Name");
            gotoxy(20,15);
            printf("|Gender");
            gotoxy(32,15);
            printf("|Age");
            gotoxy(40,15);
            printf("|Address");
            gotoxy(60,15);
            printf("|Contact No.");
            gotoxy(76,15);
            printf("|Email");
            gotoxy(100,15);
            printf("|Problem");
            gotoxy(110,15);
            printf("|Prescribed Doctor\n");
            gotoxy(130,15);
            printf("|\n");
            for(int i=1;i<=130;i++)
            {
                printf("=");
            }
            gotoxy(1,17);
        printf("|%s %s ",p.First_Name,p.Last_Name);
        gotoxy(20,17);
        printf("|%c",p.Gender);
        gotoxy(32,17);
        printf("|%d",p.age);
        gotoxy(40,17);
        printf("|%s",p.Address);
        gotoxy(60,17);
        printf("|%s",p.contact_no);
        gotoxy(76,17);
        printf("|%s",p.Email);
        gotoxy(100,17);
        printf("|%s",p.Problem);
        gotoxy (110,17);
        printf("|%s",p.Doctor);
        gotoxy(130,17);
        printf("|");
        printf("\n");
        break;
        }
    }
    if(strcmp(p.First_Name,name)!=0)
    {
    gotoxy(5,15);
        printf("Record not found!");
        getch();
    }
    fclose(ek);
    L:
        getch();
        printf("\n\n\t\t\tDo you want to view more[Y/N]");
        scanf("%c",&ans);
        if(toupper(ans)=='Y')
        {
            Search_rec();
        }
        else if(toupper(ans)=='N')
        {
            printf("\n\t\t Thank you :) :)");
            getch();
            MainMenu();
        }
        else
        {
            printf("\n\tInvalid Input. :(");
            goto L;
        }
}
void Edit_rec(void) {
    FILE *ek, *ft;
    int found = 0;
    char name[20];
    system("cls");
    Title();
    ft = fopen("temp2.dat", "wt");
    ek = fopen("Record2.dat", "r");

    if (ek == NULL) {
        printf("\n\t\t Can not open file !!");
        getch();
        MainMenu();
    }

    printf("\n\n\n\n\t\t\t!!!!!!!!!!!!!!!Edit Patients Record!!!!!!!!!!!!!!!!!\n");
    gotoxy(12, 13);
    printf("Enter the first Name of the Patient: ");
    scanf("%s", name);
    fflush(stdin);
    name[0] = toupper(name[0]);
    gotoxy(12, 15);

    if (ft == NULL) {
        printf("\n Can not open file");
        getch();
        MainMenu();
    }

    while (fscanf(ek, "%s %s %c %d %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.contact_no, p.Email, p.Problem, p.Doctor) != EOF)
        {
        if (strcmp(p.First_Name, name) == 0) {
            found = 1;
            gotoxy(25, 17);
            printf("***Existing Record***");
            gotoxy(1,18);
            printf("|Full Name");
            gotoxy(20,18);
            printf("|Gender");
            gotoxy(32,18);
            printf("|Age");
            gotoxy(40,18);
            printf("|Address");
            gotoxy(60,18);
            printf("|Contact No.");
            gotoxy(76,18);
            printf("|Email");
            gotoxy(100,18);
            printf("|Problem");
            gotoxy(110,18);
            printf("|Prescribed Doctor\n");
            gotoxy(130,18);
            printf("|\n");
            for(int i=1;i<=130;i++)
            {
                printf("=");
            }
            gotoxy(1,20);
        printf("|%s %s ",p.First_Name,p.Last_Name);
        gotoxy(20,20);
        printf("|%c",p.Gender);
        gotoxy(32,20);
        printf("|%d",p.age);
        gotoxy(40,20);
        printf("|%s",p.Address);
        gotoxy(60,20);
        printf("|%s",p.contact_no);
        gotoxy(76,20);
        printf("|%s",p.Email);
        gotoxy(100,20);
        printf("|%s",p.Problem);
        gotoxy (110,20);
        printf("|%s",p.Doctor);
        gotoxy(130,20);
        printf("|");
        printf("\n");

            printf("\n\nEnter new name: ");
            scanf("%s", p.First_Name);
            p.First_Name[0]=toupper(p.First_Name[0]);
            printf("Enter New Last Name: ");
            scanf("%s", p.Last_Name);
            printf("Enter New Gender(F/M): ");
            scanf(" %c", &p.Gender);
            p.Gender = toupper(p.Gender);
            printf("Enter New age: ");
            scanf("%d", &p.age);
            printf("Enter New Address: ");
            scanf("%s", p.Address);
            p.Address[0] = toupper(p.Address[0]);
            Z:
            printf("Enter Contact no: ");
            scanf("%s", p.contact_no);
            if(strlen(p.contact_no)!=10)
            {
                printf("contact no must be of 10-digit\n");
                goto Z;
            }
            printf("Enter New Email: ");
            scanf("%s", p.Email);
            printf("Enter New Problem: ");
            scanf("%s", p.Problem);
            p.Problem[0] = toupper(p.Problem[0]);
            printf("Enter New Doctor: ");
            scanf("%s", p.Doctor);
            p.Doctor[0] = toupper(p.Doctor[0]);
        printf("\n\n\t\t\tPatient record updated successfully....");}
        fprintf(ft, "%s %s %c %d %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.contact_no, p.Email, p.Problem, p.Doctor);


    }

    if (!found) {
        printf("\n\t\tNo Record Found....");
        M:
            getch();
        printf("\n\nDo you want to still edit(Y/N)\n");

        scanf("%c",&ans);
        if(toupper(ans)=='Y')
        {
            Edit_rec();
        }
        else if(toupper(ans)=='N')
        {
            printf("\n\t\t Thank you :) :)");
            getch();
            MainMenu();
        }
        else
        {
            printf("\n\tInvalid Input. :(");
            goto M;
        }

    }

    fclose(ft);
    fclose(ek);
    remove("Record2.dat");
    rename("temp2.dat", "Record2.dat");
    getch();
    MainMenu();
}

void Dlt_rec() {
    char name[20];
    int found = 0;
    system("cls");
    Title();
    FILE *ek, *ft;
    ft = fopen("temp_file2.dat", "wt");
    ek = fopen("Record2.dat", "r");
    printf("\n\n\n\n\t\t\t!!!!!!!!!!!!!!!!!!!Delete Patients Record!!!!!!!!!!!!!!!!\n");
    gotoxy(12, 8);
    printf("\n\n\n\n Enter Patient Name to delete: ");
    fflush(stdin);
    gets(name);
    name[0] = toupper(name[0]);

    while (fscanf(ek, "%s %s %c %d %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.contact_no, p.Email, p.Problem, p.Doctor) != EOF) {
        if (strcmp(p.First_Name, name) != 0) {
            fprintf(ft, "%s %s %c %d %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.contact_no, p.Email, p.Problem, p.Doctor);
        } else {
            printf("\n\n\t\t\t Record deleted successfully :)");
            found = 1;
        }
    }

    if (!found) {
        printf("\n\n\t\t\t Record not found.....");
    }

    fclose(ek);
    fclose(ft);
    remove("Record2.dat");
    rename("temp_file2.dat", "Record2.dat");
    getch();
    MainMenu();
}

void ex_it()
{
    system("cls");
    Title();
    printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");
    getch();
}
