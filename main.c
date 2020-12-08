// HOSPITAL MANGEMENT
#include <stdio.h>
#include <stdlib.h>
struct patient
{
    char name[30],address[30],disease[20],gender[6],dr_name[20];
    unsigned int  age;
    char phone[11];
    int id;
    char bloodT[3];
} x[100];


int main()
{
    // read();
    int opt =0 ;
    printf("------------------------------------|");
    printf(" \n  Welcome to om l masreen Hospital  \n");
    printf("------------------------------------|\n\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("*please inter ur option : *\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    printf("1:|Add New Member. \n------------------\n2:|Edit An Existent Member. \n---------------------------\n3:|View An A Member. \n--------------------\n4:|Show All The Patients. \n-------------------------\n5:|Delete Member. \n-----------------\n6:|Exit. \n--------\n");
    scanf("%d",&opt);
    while(opt!=6)
    {
        while(opt>5||opt<=0)
        {
            printf(" 1:Add new member \n 2:edit an existent member \n 3:view an a member \n 4:delete member \n5:|Exit \n");
            printf("\n\n please inter a valid value\n");
            scanf("%d",&opt);
        }
        if(opt==1)
        {
            system("cls");
            add();
            main();
            break ;
        }
        else if (opt == 2)
        {
            system("cls");
            edit();
            main();
            break ;

        }
        else if (opt == 3)
        {
            system("cls");
            view();
            main();
            break ;

        }
        else if (opt==4)
        {
            system("cls");
            printAllData();
            main();
            break ;

        }
        else if (opt==5)
        {
            system("cls");
            del();
            main();
            break ;
        }
    }
    return 0 ;
}


void add()

{
    char f;
    FILE *patr=NULL, *patw=NULL;
    int i = 0 ;
    printf("please enter your information :\n-------------------------------\n");
    patr=fopen("El-zereba hospital.txt","r");
    patw=fopen("El-zereba hospital.txt","a");
    fprintf(patw,"%20s %20s %27s %20s %20s %20s %20s %20s %20s \n","ID#","Name,","Age,","Doctor's Name,","Address,","Blood Type,","Disease,","Gender,","Phone,");

    do
    {


        FILE *patr=NULL, *patw=NULL;
        patr=fopen("El-zereba hospital.txt","r");
        patw=fopen("El-zereba hospital.txt","a");

        fscanf(patr, "%d %s %u %s %s %s %s %s %s",x[i].id,x[i].name,x[i].age,x[i].dr_name,x[i].address,x[i].bloodT,x[i].disease,x[i].gender,x[i].phone);

        printf("Enter your id :\n");
        scanf("%d",&x[i].id);
        fflush(stdin);
        printf("Enter your name :\n");
        gets(x[i].name);

        fflush(stdin);
        printf("Enter your age :\n");
        scanf("%u",&x[i].age);
        fflush(stdin);
        printf("Enter doctor's name :\n");
        gets(x[i].dr_name);
        fflush(stdin);
        printf("Enter your address :\n");
        gets(x[i].address);
        fflush(stdin);
        printf("Enter your Blood Type :\n");
        gets(x[i].bloodT);
        fflush(stdin);

        printf("Enter the disease name :\n");
        gets(x[i].disease);
        fflush(stdin);
        printf("Enter your gender :\n");
        gets(x[i].gender);
        printf("Enter your phone number :\n");
        scanf("%s",x[i].phone);
        fflush(stdin);

        fprintf(patw,"%20d %27s %18u %20s %22s %20s %22s %22s %25s \n",x[i].id,x[i].name,x[i].age,x[i].dr_name,x[i].address,x[i].bloodT,x[i].disease,x[i].gender,x[i].phone);

        printf("If u want to add more datas press Y otherwise press N: ");
        scanf("%s",&f);
        fflush(stdin);
        i++;
    }
    while (( f == 'y') || ( f == 'Y'));

    printf("You decided not to continue.\n");


    fclose(patw);
    fclose(patr);


}

void edit()
{
    int i=0;
    FILE *patr=NULL, *patw=NULL;
    patr=fopen("El-zereba hospital.txt","r");
    patw=fopen("El-zereba hospital.txt","a");

    fscanf(patr, "%d %s %u %s %s %s %s %s %s",x[i].id,x[i].name,x[i].age,x[i].dr_name,x[i].address,x[i].bloodT,x[i].disease,x[i].gender,x[i].phone);


    printf("Please, enter the Id of the patient to edit :\n---------------------------------------------\nThe ID Is : ");
    int ID, index;
    scanf("%d", &ID);
    fflush(stdin);
// asking about the id and check that the id is found in the file
    while (ID < 1 || ID >=100)
    {
        printf("you entered invalid Id, Please enter the valid Id.\n");
        scanf("%d", &ID);
        fflush(stdin);

    }
    //taking from the user the id that he,she want to be editting
    for (int i = 0; i < 100; i++)
    {
        if (x[i].id == ID)
        {
            index = i;
            break;
        }
    }
    int option =0;
    do
    {
        printf("Please choose from the list to edit.\n");

        printf("1-name.\n2-address.\n3-disease.\n4-bloodType.\n5-gender.\n6-dr_name.\n7-age.\n8-phone.\n9:EXIT \n");
        scanf("%d", &option);
        fflush(stdin);

        while (option < 1 || option > 9)
        {
            // the user enter unvaild choose
            printf("You entered invalid option, choose again");
            scanf("%d", &option);
            fflush(stdin);

        }


        if(option == 1)
        {
            // edit the name
            printf("Enter the new name.\n");
            scanf("%s", x[index].name);
            fflush(stdin);

            printf("your new name is %s.\n", x[index].name);
        }
        else if(option == 2)
        {
            // edit the address
            printf("Enter the new address.\n");
            scanf("%s", x[index].address);
            fflush(stdin);

            printf("your new address is %s.\n", x[index].address);
        }
        else if(option == 3)
        {
            // edit the disease
            printf("Enter the new disease.\n");
            scanf("%s", x[index].disease);
            fflush(stdin);

            printf("your new disease is %s.\n", x[index].address);
        }
        else if(option == 4)
        {
            // edit the blood type
            printf("Enter the new bloodType is .\n");
            scanf("%s", x[index].bloodT);
            fflush(stdin);

            printf("your new bloodType is %s.\n", x[index].bloodT);
        }
        else if(option == 5)
        {
            // edit the gender
            printf("Enter the new gender.\n");
            scanf("%s", x[index].gender);
            fflush(stdin);

            printf("your new gender is %s.\n", x[index].gender);
        }
        else if(option == 6)
        {
            // edit the dr name
            printf("Enter the new dr_name.\n");
            scanf("%s", x[index].dr_name);
            fflush(stdin);

            printf("your new dr_name is %s.\n", x[index].dr_name);
        }
        else if(option == 7)
        {
            // edit the age
            printf("Enter the new age.\n");
            scanf("%d", &x[index].age);
            fflush(stdin);

            printf("your new age is %d.\n", x[index].age);
        }
        else if(option == 8)
        {
            // edit the phone
            printf("Enter the new phone.\n");
            scanf("%s", &x[index].phone);
            fflush(stdin);

            printf("your new phone is %s.\n", x[index].phone);
        }

    }
    while(option!=9);
    fprintf(patw,"%20d %20s %18u %20s %20s %20s %20s %20s %20s \n",x[index].id,x[index].name,x[index].age,x[index].dr_name,x[index].address,x[index].bloodT,x[index].disease,x[index].gender,x[index].phone);

}
void view()
{
    int i=0;
    FILE *patr=NULL ;// *patw=NULL;
    patr=fopen("El-zereba hospital.txt","r");

    printf("Enter the ID to view the information of the patient:\n----------------------------------------------------\nID Of The patient = ");
    int ID, index;
    scanf("%d", &ID);
    fflush(stdin);
// asking about the id and check that the id is found in the file
    while (ID < 1 || ID > 100)
    {
        printf("you entered invalid Id, Please enter the valid Id.\n");
        scanf("%d", &ID);
        fflush(stdin);

    }
// checking for all id and get the id that you want to appear
    for (int i = 0; i < 100; i++)
    {
        fscanf(patr, "%d %s %u %s %s %s %s %s %s",x[i].id,x[i].name,x[i].age,x[i].dr_name,x[i].address,x[i].bloodT,x[i].disease,x[i].gender,x[i].phone);

        if (x[i].id == ID)
        {
            index = i;
            //break;
            printf("\n");
            printf("ID = %d.\n", x[index].id);
            printf("Name = %s.\n", x[index].name);
            printf("Age = %u.\n", x[index].age);
            printf("DR/Name = %s.\n", x[index].dr_name);
            printf("ADDRESS = %s.\n", x[index].address);
            printf("Disease = %s.\n", x[index].disease);
            printf("Blood Type = %s.\n", x[index].bloodT);
            printf("Gender = %s.\n",x[index].gender);
            printf("Phone number = %s.\n", x[index].phone);
            fprintf(patr,"%20d %20s %18u %20s %20s %20s %20s %20s %20s \n",x[index].id,x[index].name,x[index].age,x[index].dr_name,x[index].address,x[index].bloodT,x[index].disease,x[index].gender,x[index].phone);
            break;
        }
        //break;
    }

}

void printAllData()

{
    int i=0 ;
    FILE *patr=NULL;
    patr=fopen("El-zereba hospital.txt","r");
    //printing all data that you entered
    for (int i = 0 ; i < 100 ;  i++)
    {

        FILE *patr=NULL;
        patr=fopen("El-zereba hospital.txt","r+");
        fscanf(patr, "%d %s %u %s %s %s %s %s %s",x[i].id,x[i].name,x[i].age,x[i].dr_name,x[i].address,x[i].bloodT,x[i].disease,x[i].gender,x[i].phone);
//        fscanf(patr, "%d %s %u %s %s %s %s %s %s",x[i-1].id,x[i-1].name,x[i-1].age,x[i-1].dr_name,x[i-1].address,x[i-1].bloodT,x[i-1].disease,x[i-1].gender,x[i-1].phone);
//      fprintf(patr,"%20d %20s %18u %20s %20s %20s %20s %20s %20s \n",x[i].id,x[i].name,x[i].age,x[i].dr_name,x[i].address,x[i].bloodT,x[i].disease,x[i].gender,x[i].phone);
        printf("patient number %d informations: \nName: %s.\n ID: %d.\n Age: %d.\n Dr-Name: %s.\n Address: %s.\n Disease: %s.\n Blood Type: %s.\n Gender: %s.\n Phone Number: %s.\n", i+1, x[i].name, x[i].id, x[i].age, x[i].dr_name, x[i].address, x[i].disease, x[i].bloodT, x[i].gender, x[i].phone);
//        printf("patient number %dth informations:\n\n\nName: %s.\n ID: %d.\n Age: %d.\n Dr-Name: %s.\n Address: %s.\n Disease: %s.\n Blood Type: %s.\n Gender: %s.\n Phone Number: %s.\n", i, x[i-1].name, x[i-1].id, x[i-1].age, x[i-1].dr_name, x[i-1].address, x[i-1].disease, x[i-1].bloodT, x[i-1].gender, x[i-1].phone);
        printf("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");

        if (i==NULL)
        {
            break ;
        }

    }

    fclose(patr);
}

// this a fuction to delete a sepecific  information
void del ()
{
    int i =0,q=0 ;

    FILE *patr=NULL, *patw=NULL;
    patr=fopen("El-zereba hospital.txt","r");
    patw=fopen("El-zereba hospital.txt","a");

    fscanf(patr, "%d %s %u %s %s %s %s %s %s",x[i].id,x[i].name,x[i].age,x[i].dr_name,x[i].address,x[i].bloodT,x[i].disease,x[i].gender,x[i].phone);

    int s=0;
    // asking fpr the patient id to search or it in my data
    printf("please inter the id of the patien u want to delete : \n----------------------------------------------------\nThe ID Is : ");
    scanf("%d",&s);
    fflush(stdin);

    for (i=0; i <100; i++)

    {
        // if i had found it i 'll operate some operation he will choose among them
        if(x[i].id==s)
        {


            printf("-------------------------------------------------");
            printf(" \n please inter the operation nmber u wanna do :\n");
            printf("-------------------------------------------------\n ");

            printf("1:delet name.\n2:delete age.\n3:delete phone.\n4:delete id.\n5:delete adress.\n6:delete blood type.\n7:delete gender.\n8:|delete doctor name \n9:| delete disease \n10:remove the whole account.\n \n");
            scanf("%d",&q);
            fflush(stdin);

            // if he chose a wrong choice i ' ll ask him to re ener his choice with a valid vlue

            while(q<0&&q>=10)
            {
                printf("1:delet name.\n2:delete age.\n3:delete phone.\n4:delete id.\n5:delete adress.\n6:delete blood type.\n7:delete gender.\n 8:|delete dr name \n 9:| delete the disease \n 10:remove the whole account. \n");
                printf("\n please inter a valid value \n");
                scanf("%d",&q);
                fflush(stdin);
            }
            // making the operatin he ha choose
            if(q==1)
            {
                // this to delete onley his name
                strcpy( x[i].name,"deleted");
                printf("ur name is : %s \n",x[i].name);

            }
            else if (q==2)
            {
                // this to delete his age from data
                x[i].age=0;
                printf("ur age is :%u \n ",x[i].age);
            }
            else if (q==3)
            {
                // this to delete his phone number
                strcpy(x[i].phone,"0");
                // zero(dataP[i]);
                printf("ur phone is : %s \n",x[i].phone);

            }
            else if (q==4)
            {
                // this to delete his id
                //zeroid(dataP);
                x[i].id='0';
                printf("ur id is : %d \n",x[i].id);
            }
            else if (q==5)
            {
                strcpy(x[i].address,"deleted");
                printf("ur adress is : %s \n",x[i].address);
            }
            else if (q==6)
            {
                strcpy(x[i].bloodT,"xx");
                printf("ur blood type is : %s \n ",x[i].bloodT);
            }
            else if (q==7)
            {
                strcpy(x[i].gender,"x");
                printf("ur gender is :%s \n",x[i].gender);
            }
            else if (q==8)
            {
                strcpy(x[i].dr_name,"deleted");
                printf("the doctor name is %s",x[i].dr_name);
            }
            else if (q==9)
            {
                strcpy(x[i].disease,"deleted");
                printf("the disesse is %s",x[i].disease);
            }
            else if (q==10)
            {

                strcpy(x[i].gender,"x");
                strcpy (x[i].bloodT,"xx");
                strcpy (x[i].address,"deleted");
                strcpy (x[i].phone,"0");
                fflush(stdin);
                // x[i].id='0';
                x[i].age='0';
                strcpy (x[i].name,"deleted");
                strcpy(x[i].dr_name,"deleted");
                strcpy(x[i].disease,"deleted");

                printf("ur name is : %s \n ur age is :%u \n ur id : %d \n ur phone : %s \n ur address :%s \n ur blood type :%s \n ur  gender:%s \n ",x[i].name,x[i].age,x[i].id,x[i].phone,x[i].address,x[i].bloodT,x[i].gender);
                printf("the disesse is %s",x[i].disease);
                printf("the doctor name is %s",x[i].dr_name);

            }
            fprintf(patw,"%20d %20s %18u %20s %20s %20s %20s %20s %20s \n",x[i].id,x[i].name,x[i].age,x[i].dr_name,x[i].address,x[i].bloodT,x[i].disease,x[i].gender,x[i].phone);


        }

    }
}
