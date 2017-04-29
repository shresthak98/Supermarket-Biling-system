/*                Programmed by -
                                Harshit jalan   and    Shrestha kumar
*/
//***************************************************************
// HEADER FILE USED IN PROJECT
//***************************************************************
#include<bits/stdc++.h>
using namespace std;

char password[20];

void intro()          /*Introduction function showing the title of the project*/
{
cout<<"\n\n\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\tSUPER MARKET BILLING SYSTEM\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";

}

//Declaring and defining of gotoxy function
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Declaring and defining the delay function
void delay(unsigned int mseconds)				/*To bring a time gap before printing the next character etc.*/
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


//Time and date function

time_t ti;
int t(void) 									/*For displaying current date and time*/
{
    time(&ti);
    printf("Date and time:%s\n",ctime(&ti));        //Using ctime() for showing the present time and date
    return 0 ;
}

int dscan()													/*Scan function for input of only non-negative integers*/
{
	string ch;												/*Taking initial input through string*/
	int i,v;
	do{
		v=1;
		cin>>ch;
		for(i=0;i<ch.size();i++)							/*Checking each of the character is digit or not*/
		{
			if(!isdigit(ch[i]))
			{
				cout<<"\n\n\tWrong entry. Try again."<<endl;
				cout<<"\n\n\tEnter the required data : ";
				v=0;
				break;
			}
		}
	}
	while(!v);
	return atoi(ch.c_str());								/*Converting string back to integer*/
}



fstream fp;
fstream fp1;
int spdis[50][2];
int dis;
int arrival[10];
int arrid[20];
int arrval;
int arridcount;


void Password()													/*Password function is used for taking entry of the password from the user*/
{
	char ch;
	int i=0, j=0;
	system("cls");
    intro();
	gotoxy(10,4);
	gotoxy(10,6);
	cout<<"\n\n\tEnter password : ";
	while(ch!=13)												/*For converting each character of password in a '*'(encoding)*/
	{
		ch=getch();
		if(ch!=13)
		{
			if(ch!='\b')
			{
				putch('*');
				password[i] = ch;
				i++;
			}
			else
			{
				if(i)
				{
					cout<<"\b \b";
					i--;
				}
			}
		}
   }
   password[i] = '\0';

}

//**********************************************************************************************************
// Starting of Product class containing variables of product and function used of the product
//*********************************************************************************************************

class product                               //Starting of class product
{
    int pno;
    char name[50];
    float price,qty,tax,dis,fresh;
    public:
    void create_product()                   /* For creating the product */
    {
        cout<<"\n\n\tPlease Enter The Product No. of The Product :  ";
        pno=dscan();
        cin.ignore();                                         /*For making the gets() function useful*/
        cout<<"\n\n\tPlease Enter The Name of The Product : ";
        gets(name);
        cout<<"\n\n\tPlease Enter The Price of The Product : ";
        cin>>price;
        cout<<"\n\n\tPlease Enter The Discount (%) : ";
        cin>>dis;

    }

    void show_product()                        /*For displaying the details of the product */
     {
        cout<<"\n\n\tThe Product No. of The Product : "<<pno;
        cout<<"\n\n\tThe Name of The Product : ";
        printf("%s",name);
        cout<<"\n\n\tThe Price of The Product : "<<price;
        cout<<"\n\n\tDiscount : "<<dis;
    }

    int retpno()              /*As the pno,price,name,dis are the private members of the class so they cannot be accessed directly */
    {return pno;}

    float retprice()
    {return price;}

    char* retname()
    {return name;}

    int retdis()
    {return dis;}

}; //class products ends here

class customer                      //Starting of the class customer
{
    public:                          //Declaring the variable of the class as public so that they can be further accessed directly in the program
    int cid,reg,spdis,alert;
    int phno;
    char name[50];
    int cart[50][2];
    int num;
    float tot;
    void refresh()             //Refreshing function is to rewind or reschedule the values of the variables if the class
    {
        cid=0;reg=0;phno=0;spdis=0;alert=0;num=0,tot=0.0;
    }


    void create_customer()              //Function for creating the customers i.i taking the details of the customer
    {
        cout<<"\n\n\tPlease Enter your name : ";
        scanf("%s",name);
        cout<<"\n\n\tPlease Enter your Mobile Number : ";
        phno=dscan();
        cout<<"\n\n\tThank You for registering with us \n";

        srand((unsigned) time(&ti));      //This function is used for changing the seed of the rand function so that it should print different values at different time

        for(int i=0;i<5;i++)
        {
            cid=cid*10+(rand()%9);       //Rand function for randomly generating the customer id
        }
        cout<<"\n\n\tYour Customer id is:- "<<cid;
        cout<<"\n\n\tPlease use it on your next transaction with us";

        cout<<"\n\n\tPress ENTER to proceed to our store";
        getch();
    }

    void welcome_customer()
    {
        cout<<"\n\n\tWelcome to our store Mr."<<name<<endl;
    }

    void show_customer_name()            //Function for showing the details of the customer and the special discount offered to him
    {
        cout<<"\n\n\tCustomer Id:- "<<cid;
        cout<<"\n\n\tName :- "<<name;
        cout<<"\n\n\tPhone Number : "<<phno;
        if(spdis!=0)
        cout<<"\n\n\tSpecial Discount : "<<spdis;
    }
    void add_purchase(int pid,int qua)          //Function for adding the purchase of the customer to the account of the customer
    {

        float amount=0.0;
        if(reg==0)
        {
             cart[num][0]=pid;
            cart[num][1]=qua;
        }
        else{
            int flag=0;
            for(int i=0;i<num;i++)
            {
                if(cart[i][0]==pid)
                {
                    cart[i][1]+=qua;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                cart[num][0]=pid;
                cart[num][1]=qua;
            }
            else{
                num--;
            }

        }


        fp1.open("Shop.dat",ios::in);       //Opening the file Shop.dat in reading mode with the pointer fp1
        product pr1;
        while(fp1.read((char*)&pr1,sizeof(product)))
        {
            if(pr1.retpno()==cart[num][0] )
            {
                 amount=(pr1.retprice()*qua) -(pr1.retdis()*(pr1.retprice()*qua))/100;
                 break;
            }
        }
        fp1.close();
        tot = tot + amount;
        num++;

    }

};
//***************************************************************
// global declaration for stream object, object
//****************************************************************

product pr;                                     //Creating the objects of the class project and customer
customer cu;
int display_sp(int);

//***************************************************************
// function to write in file
//****************************************************************
int write_customer()                                    //Starting of write_customer function which takes the entering that either the customer is new or is registered before
{
    system("cls");intro();
    int choice,n, ch;
    int flag=0;
    cout<<"\n\n\tWelcome to our store!!"<<endl;
    cout<<"\n\n\tEnter as :-"<<endl;
    cout<<"\n\n\t1) Registered Customer"<<endl;
    cout<<"\n\n\t2) New Customer"<<endl;
    cout<<"\n\n\tEnter the choice : ";
    cin>>choice;
    system("cls");intro();
    if(choice==1)
    {
        while(flag==0)
        {
            cout<<"\n\n\tEnter your unique Customer Id : ";
            n=dscan();                                    //For entering the customer id only integer and showing error if a string is entered

             for(int i=0;i<arridcount;i++)
            {
                if(arrid[i]==n)
                {
                    cout<<"\n\n\tHello ! You have been selected to show the new arrivals of our shop.\n\n\tHere are the new arrivals:-\n";
                    for(int j=0;j<arrval;j++)
                    {
                        int z=display_sp(arrival[j]);
                    }
                }
            }

            fp.open("Customer.dat",ios::in);                              //Opening the file customer.dat in read mode
            while(fp.read((char*)&cu,sizeof(customer)))
            {
                if(cu.cid==n)
                {
                    cu.welcome_customer();
                    cu.reg=1;
                    flag=1;
                    break;
                }
            }
            fp.close();
            if(flag==0)
            cout<<"\n\n\trecord not exist please check your Customer Id and try again";
            getch();
        }
    }
    else if(choice==2)
    {
        fp.open("Customer.dat",ios::out|ios::app);    //Opening the customer.dat file in writing or appending mode
        cu.refresh();                                  //Calling the refreshing function for rewinding the values of the class customer variables
        cu.create_customer();                         //If the customer is new then calling the create customer function
        fp.close();
        system("cls");intro();
    }
    else
    {
        system("cls");intro();
        cout<<"\n\n\n\t\tWrong input!Please enter the correct choice";
        getch();
        write_customer();
    }
    return flag;
}
void write_product()                              //Function for writing the products in the Shop.dat file
{
    fp.open("Shop.dat",ios::out|ios::app);
    cout<<"\n\n\tEnter the number of products you want to add : ";
    int y;
    cin>>y;
    arrval=0;
    for(int i=0;i<y;i++)
    {
    pr.create_product();
    arrival[arrval++]=pr.retpno();               //For storing the new arrivals for showing to our specific customer
    fp.write((char*)&pr,sizeof(product));
    }
    fp.close();
    cout<<"\n\nThe Product Has Been Created ";
    getch();

}


//***************************************************************
// function to read all records from file
//****************************************************************


void display_all()                      //Displaying all the products from the Shop.dat file with the help of the show_product function
{
    cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    fp.open("Shop.dat",ios::in);
    while(fp.read((char*)&pr,sizeof(product)))
    {
        pr.show_product();                  //Calling the show_product function
        cout<<"\n\n=====================================================================\n";
    }
    fp.close();
    getch();
}


//***************************************************************
// function to read specific record from file
//****************************************************************


int display_sp(int n)           //Function for displaying the details of only the specified product
{
    int flag=0;
    fp.open("Shop.dat",ios::in);
    while(fp.read((char*)&pr,sizeof(product)))
    {
        if(pr.retpno()==n)     //Comparing the product id entered by the customer with the product id saved in the file
        {
            pr.show_product();
            flag=1;
        }
    }
    fp.close();
    if(flag==0)
    cout<<"\n\n\tInvalid Product Id\n\tPlease try again.";
    return flag;
}


//***************************************************************
// function to modify record of file
//****************************************************************


void modify_product()                   //Function for modifying the details of the product
{
    system("cls");intro();              //Clearing the screen and again calling the intro function so that the heading of the file remains always on the screen
    int no,found=0;
    cout<<"\n\n\tTo Modify ";
    cout<<"\n\n\tPlease Enter The Product No. of The Product : ";
    no=dscan();                                          //Entering the product id of the product whose details is to be modified
    fp.open("Shop.dat",ios::in|ios::out);
    while(fp.read((char*)&pr,sizeof(product)) && found==0)
    {
        if(pr.retpno()==no)
        {
            pr.show_product();
            cout<<"\n\n\tPlease Enter The New Details of Product : "<<endl ;
            pr.create_product();         //For modifying the data we are creating the product again so that each and every record of that product can be changed
            int pos=-1*sizeof(pr);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&pr,sizeof(product));
            cout<<"\n\n\t Record Updated";
            found=1;
        }
    }
    fp.close();
    if(found==0)
    cout<<"\n\n\t Record Not Found ";
    getch();
}


//***************************************************************
// function to delete record of file
//****************************************************************


void delete_product()               //Function for deleting the product
{
    system("cls");intro();
    int no;
    cout<<"\n\n\n\tDelete Record";
    cout<<"\n\n\tPlease Enter The product no. of The Product You Want To Delete : ";
    no=dscan();                                     //Checking that the entered product no is a integer or not
    fp.open("Shop.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&pr,sizeof(product)))
    {
        if(pr.retpno()!=no)
        {
            fp2.write((char*)&pr,sizeof(product));
        }
    }
    fp2.close();
    fp.close();
    remove("Shop.dat");
    rename("Temp.dat","Shop.dat");
    cout<<"\n\n\tRecord Deleted ..";
    getch();
}


//***************************************************************
// function to display all products price list
//****************************************************************

void menu()
{
    fp.open("Shop.dat",ios::in);         //Opening the file Shop.dat in read mode with pointer fp
    if(!fp)
    {
        cout<<"\n\n\tERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
        cout<<"\n\n\n\t Program is closing ....";
        getch();
        exit(0);
    }

    cout<<"\n\n\t\tProduct MENU\n\n";                       //Displaying the product menu with all the details of the product
    cout<<"==========================================================================\n";
    cout<<"\tP.NO.\t\tNAME\t\t\tPRICE\n";
    cout<<"==========================================================================\n";

    while(fp.read((char*)&pr,sizeof(product)))
    {
        cout<<"\t"<<pr.retpno()<<"\t\t"<<pr.retname()<<"\t\t\t"<<pr.retprice()<<endl;          //Printing the variables of the class product
    }
    fp.close();
}

//***************************************************************
// function to place order and generating bill for Products
//****************************************************************
void customer_list();
void place_order()     //MAIN function of our program.Used for placing the order by the customer and then billing the items bought
{
    system("cls");intro();
    int order_arr[50],quan[50],price[50],c=0,h=0,special=0;
    int regi;
    char des;
    float amt,damt,total=0.0;
    char ch='Y';
    char name[50][50];
    regi=write_customer();
    for(int i=0;i<dis;i++)
    {
        if(spdis[i][0]==cu.cid)
        {
            special=spdis[i][1];
            break;
        }
    }

    menu();


    cout<<"\n================================================";
    cout<<"\n\t PLACE YOUR ORDER";
    cout<<"\n================================================\n";

    while(ch=='y' ||ch=='Y')
    {
        while(1)
        {
            cout<<"\n\n\tEnter The Product No. Of The Product : ";
            order_arr[c]=dscan();
            if(display_sp(order_arr[c])==1)
            {
                cout<<"\n\n\tQuantity in number : ";
                cin>>quan[c];
                cu.add_purchase(order_arr[c],quan[c]);          //Calling the add_purchase function for adding the data into the account of the customer

                c++;
                cout<<"\n\n\tDo You Want To Order Another Product ? (y/n) : ";
                ch=getche();
                break;
            }
        }
    }
    if(regi==0)
    {
        fstream fp2;
        fp2.open("Customer.dat",ios::out|ios::app);
        fp2.write((char*)&cu,sizeof(customer));
        fp2.close();
    }
    else
    {
        fstream fp2;
        fp2.open("Customer.dat",ios::in);
        fstream fp3;
        fp3.open("Temp.dat",ios::out);
        fp2.seekg(0,ios::beg);
        customer cu1;                                  //Creating the object of the class customer
        while(fp2.read((char*)&cu1,sizeof(customer)))
        {
            if(cu1.cid==cu.cid)        //Comparing the details stored in cu1 and cu object of the customer class
            {
                fp3.write((char*)&cu,sizeof(customer));
            }
            else
            fp3.write((char*)&cu1,sizeof(customer));
        }
        fp3.close();
        fp2.close();
        remove("Customer.dat");
        rename("Temp.dat","Customer.dat");
    }

    cout<<"\n\n\tThank You For Placing The Order";
    cout<<"\n\n\tPress enter for moving to bill counter ";
    getch();
    system("cls");intro();
    cout<<"\n\n\t1.Sort the bill items by price";
    cout<<"\n\n\t2.Sort the bill items by name";
    cout<<"\n\n\tEnter the choice(You cannot undo if you enter a wrong choice) : ";
    int ch1;
    cin>>ch1;
    switch(ch1)
    {
        case 1:
            system("cls");intro();
            cout<<"\n\n\t\tSorting bill items by price";
            //getch();
            cout<<"\n\n*******************************************INVOICE************************************************\n\n";
            t();                                                                                        //Using the function t() for printing the time and date
            cout<<"\n\t\tName - "<<cu.name<<"                            "<<"Phone no - "<<cu.phno;
            cout<<"\n\n============================================================================================";
            cout<<"\n\n\tPr No.\t        Pr Name\t       Quantity\t        Price\t       Amount \n";  //Printing the bill automatically
            cout<<"\n============================================================================================";


            for(int x=0;x<c;x++)
            {
                fp.open("Shop.dat",ios::in);                 //Opening again the Shop.dat file in read mode
                fp.read((char*)&pr,sizeof(product));
                while(!fp.eof())
                {
                    if(pr.retpno()==order_arr[x])
                    {
                        price[h++]=pr.retprice();
                    }
                    fp.read((char*)&pr,sizeof(product));

                }
                fp.close();
            }
            for(int x=0;x<h;x++)
            {
                for(int y=0;y<h;y++)
                {
                    if(price[x]<price[y])
                    {
                        int temp=price[x];                      //Sorting the details of the item according to their price
                        price[x]=price[y];                      //Sorting the price of the items
                        price[y]=temp;
                        temp=quan[x];
                        quan[x]=quan[y];                        //Sorting the quantity of the items
                        quan[y]=temp;
                    }
                }
            }
            for(int x=0;x<c;x++)
            {
                fp.open("Shop.dat",ios::in);
                fp.read((char*)&pr,sizeof(product));
                while(!fp.eof())
                {
                    if(pr.retprice()==price[x])
                    {
                        amt=pr.retprice()*quan[x];
                        cout<<"\n\t"<<order_arr[x]<<"\t        "<<pr.retname()
                         <<"\t       "<<quan[x]<<"\t        "<<pr.retprice()<<"\t        "<<amt;
                         total+=amt;


                    }
                    fp.read((char*)&pr,sizeof(product));
                }

                fp.close();
            }
            if(special!=0)
            {
                total-=(total*special)/100;
                cout<<"\n\n\tCongratulations !!! You have been selected as a special customer and we offer you a special discount of "<<special<<"%"<<endl;  //Showing the extra discount to the customer
            }

            cout<<"\n\n\t\tTotal amount = "<<total<<endl;
            cout<<"\n\n\tEnter either you are a student(S) or a professional(P) : ";
            des=getche();
            if(des=='S' || des=='s')
            {
                cout<<"\n\n\tCongratulation!We are providing 5% extra discount for the student"<<endl;
                damt=total-(total*0.05);
            }
            if(des=='P' || des=='p')
            {
                cout<<"\n\n\tSorry we doesn't have any extra offer for professionals"<<endl;
                damt=total;
            }
            cout<<"\n\n\t\t Gross Total  = "<<total;
            cout<<"\n\n\t\tGross amount after discount = "<<damt;
            cout<<"\n\n\n\t\tVAT percentage = 12.5%";     //Applying the vat percentage of 12.5% on the bill
            damt+=(damt*12.5)/100;
            cout<<"\n\n\t\tTotal payable amount(including all taxes) = "<<damt;
            getch();
            cout<<"\n\n\t\tThank you for shopping at us ! Please visit again";
            getch();
            system("cls");intro();
            break;

        case 2:
            system("cls");intro();
            cout<<"\n\n\t\tSorting bill items by name ";

            cout<<"\n\n*******************************************INVOICE************************************************\n\n";
            t();
            cout<<"\n\t\tName - "<<cu.name<<"                            "<<"Phone no - "<<cu.phno;
            cout<<"\n\n=============================================================================================";
            cout<<"\n\tPr No.\t        Pr Name\t       Quantity\t        Price\t       Amount \n";         //Printing the bill automatically
            cout<<"\n=============================================================================================";


            for(int x=0;x<c;x++)
            {
                fp.open("Shop.dat",ios::in);
                fp.read((char*)&pr,sizeof(product));
                while(!fp.eof())
                {
                    if(pr.retpno()==order_arr[x])
                    {
                        strcpy(name[h++],pr.retname());
                    }
                    fp.read((char*)&pr,sizeof(product));

                }
                fp.close();
            }
            for(int x=0;x<h;x++)
            {
                for(int y=0;y<h;y++)
                {
                    if(strcmp(name[x],name[y])<0)
                    {
                        char temp[50];
                        strcpy(temp,name[x]);                       //Sorting the bill with respect to the name of the items
                        strcpy(name[x],name[y]);
                        strcpy(name[y],temp);                      //Copying the name
                        int temp1=quan[x];
                        quan[x]=quan[y];
                        quan[y]=temp1;                             //Accordingly sorting the quantity
                    }
                }
            }
            for(int x=0;x<c;x++)
            {
                fp.open("Shop.dat",ios::in);
                fp.read((char*)&pr,sizeof(product));
                while(!fp.eof())
                {
                    if(strcmp(pr.retname(),name[x])==0)
                    {
                        amt=pr.retprice()*quan[x];
                        cout<<"\n\t"<<order_arr[x]<<"\t        "<<pr.retname()
                         <<"\t       "<<quan[x]<<"\t        "<<pr.retprice()<<"\t        "<<amt;
                         total+=amt;

                    }
                    fp.read((char*)&pr,sizeof(product));
                }

                fp.close();
            }
            if(special!=0)
            {
            total-=(total*special)/100;
            cout<<"\n\n\tCongratulations !!! You have been selected as a special customer and we offer you a special discount of "<<special<<"%"<<endl;
            }
             cout<<"\n\n\t\tTotal amount = "<<total<<endl;
            cout<<"\n\n\tEnter either you are a student(S) or a professional(P) : ";
            des=getche();
            if(des=='S' || des=='s')        //Checking either the customer is a student or a professional
            {
                cout<<"\n\tCongratulation!We are providing 5% extra discount for the student"<<endl;
                damt=total-(total*0.05);
            }
            if(des=='P' || des=='p')
            {
                cout<<"\n\tSorry we doesn't have any extra discount for professionals"<<endl;
                damt=total;
            }
            cout<<"\n\n\t\tGross Total = "<<total;
            cout<<"\n\n\t\tGross amount after discount = "<<total;
            cout<<"\n\n\n\n\t\tVAT percentage = 12.5%";
            total+=(total*12.5)/100;
            cout<<"\n\n\t\tTotal payable amount(including all taxes) = "<<total;
            getch();
            cout<<"\n\n\t\tThank you for shopping at us ! Please visit again ";
            getch();
            system("cls");intro();
            break;

        default :
                cout<<"\n\n\tYou have entered a wrong choice !\n";


    }
}


void customer_list()         //Staring of the function customer list which prints the details of the customer and provide admin to do extra operation on the customer
{
    system("cls");intro();
    string g;
    int ch;
    fp.open("Customer.dat",ios::in);
    char a[50][50];
    int i=0,j;
    if(!fp)
    {
        cout<<"\n\n\tERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
        cout<<"\n\n\n Program is closing ....\n";
        getch();
        exit(0);
    }

    cout<<"\n\n\t\tCustomer List\n\n";                 //Printing the list of the customer
    cout<<"================================================================================================================\n";
    cout<<"\tCust.Id\t\t\tNAME\t\t\tPh.no\t\t\tPurchase_Record\n";
    cout<<"================================================================================================================\n";

    while(fp.read((char*)&cu,sizeof(customer)))
    {
        strcpy(a[i++],cu.name);
    }
    fp.close();
    for(int x=0;x<i;x++)
    {
        for(int y=0;y<i;y++)
        {
            if(strcmp(a[x],a[y])<0)
            {
                char temp[50];
                strcpy(temp,a[x]);     //Printing the list of the customer after sorting them
                strcpy(a[x],a[y]);
                strcpy(a[y],temp);
            }
        }
    }
    for(int x=0;x<i;x++)
    {
        fp.open("Customer.dat",ios::in);
        customer cu2;
        fp.read((char*)&cu2,sizeof(customer));
        while(!fp.eof())
        {
            if(strcmp(cu2.name,a[x])==0)
            {
                cout<<"\t"<<cu2.cid<<"\t\t\t"<<cu2.name<<"\t\t\t";
                printf("%d",cu2.phno);
                cout<<"\t\t\t"<<cu2.tot<<"\n";
            }
            fp.read((char*)&cu2,sizeof(customer));

        }
        fp.close();
    }
    while(1)
    {
        cout<<"\n\t\t1. View the products purchased by a customer ";        //For viewing the purchase record of the customer
        cout<<"\n\t\t2. Providing new arrivals to the particular customer ";   //For providing new arrivals to the customer
        cout<<"\n\t\t3. Give extra rebate to specific customers ";           //For providing extra rebate to specific customer
        cout<<"\n\t\t4. For going back to admin mode ";
        cout<<"\n\n\tEnter the choice : ";
        cin>>ch;

        switch(ch)
        {

            case 1:
            {
                int flag=0;
                while(true)
                {
                cout<<"\n\n\tEnter the customer id of the customer OR enter 0 to go back : ";
                int x;
                x=dscan();      //Checks the entry is only integer or not

                if(x==0)
                return;

                cout<<"\n==========================================================================";
                cout<<"\n\t\tProduct_Id\t\tProduct_name\t\tQuantity";
                cout<<"\n==========================================================================";
                fp.open("Customer.dat",ios::in);

                while(fp.read((char*)&cu,sizeof(customer)))
                {
                    int i=0;
                    if(cu.cid==x)
                    {
                        flag=1;
                        while(i<cu.num)
                        {
                            cout<<"\n\t\t"<<cu.cart[i][0]<<"\t\t\t";
                            fp1.open("Shop.dat",ios::in);
                            while(fp1.read((char*)&pr,sizeof(product)))
                             {
                                 if(pr.retpno()==cu.cart[i][0])
                                 {
                                    cout<<pr.retname();
                                 }
                             }
                            fp1.close();
                            cout<<"\t\t\t"<<cu.cart[i][1]<<'\t'<<endl;
                            i++;
                        }
                        break;
                    }
                }
                fp.close();
                if(flag==1)
                {
                cout<<"\n==========================================================================";
                if(cu.spdis!=0)
                cout<<"\n                  Special Discount offered = "<<cu.spdis<<"%"<<endl;       //Printing the special discount offered to the customer
                cout<<"\n                  Total Purchasing done = $"<<cu.tot<<endl;                //Printing the net purchasing amount of the customer
                cout<<"\n==========================================================================";
                break;
                }
                else
                {
                    cout<<"\nInvalid customer id!Please try again\n";
                }
                }
                break;
            }
            case 2:
            {

                    cout<<"\n\tEnter the customer id to whom the new arrivals are to be shown : ";
                    int x;
                    x=dscan();
                    arrid[arridcount++]=x;     //Storing the entered customer id into the array for showing the new arrivals to the specific customer
                    cout<<"\nNew arrivals will be shown to him\n";
                    break;

            }
            case 3:
            {
                cout<<"\n\n\tEnter the customer id of the customer OR enter 0 to go back : ";
                int x;
                x=dscan();          //Entering the customer id to who the extra discount is to be shown

                if(x==0)
                return;

                fp.open("Customer.dat",ios::in);
                while(fp.read((char*)&cu,sizeof(customer)))
                {
                    if(cu.cid==x)
                    {
                        cout<<"\n\n\tEnter the extra discount you want to give to Mr."<<cu.name<<endl;
                        cin>>spdis[dis][1];           //Storing the extra discount in the array spdis
                        spdis[dis++][0]=x;
                        cout<<"\n\n\tExtra Discount successfully offered\n"<<endl;
                    }
                }
                fp.close();
                break;
            }
            case 4:
                return;
                break;

            default :
                cout<<"\n\n\tWrong choice ! Please enter the correct choice ";


              }
          }
}





//***************************************************************
// ADMINSTRATOR MENU FUNCTION
//****************************************************************
void admin_menu()                          //Staring the main menu function
{
    system("cls");intro();
    string no;
    char ch2;
    cout<<"\n\n\n\tADMIN MENU";
    cout<<"\n\n\t1.CREATE PRODUCT";
    cout<<"\n\n\t2.DISPLAY ALL PRODUCTS";
    cout<<"\n\n\t3.QUERY ";
    cout<<"\n\n\t4.MODIFY PRODUCT";
    cout<<"\n\n\t5.DELETE PRODUCT";
    cout<<"\n\n\t6.VIEW PRODUCT MENU";
    cout<<"\n\n\t7.VIEW CUSTOMER DETAILS";
    cout<<"\n\n\t8.SEARCHING THE CUSTOMER BY NAME";
    cout<<"\n\n\t9.BACK TO MAIN MENU";
    cout<<"\n\n\tPlease Enter Your Choice (1-9) : ";
    ch2=getche();

    switch(ch2)
    {
    case '1':
            system("cls");intro();
            write_product();           //Function for creating the product
            system("cls");intro();
            admin_menu();
            break;

    case '2':
            display_all();         //Displaying all the products with the details
            admin_menu();
            break;
    case '3':
             system("cls");intro();

            int num;
            cout<<"\n\n\tPlease Enter The Product No. : ";
            num=dscan();
            display_sp(num);        //Displaying only the special product
            getch();
            admin_menu();
            break;
    case '4':
            modify_product();      //Calling the modify product function
            getch();
            admin_menu();
            break;
    case '5':
            delete_product();       //Calling the delete product function
            admin_menu();
            break;
    case '6':
            menu();                //For showing the bill report
            getch();
            admin_menu();
            break;

    case '7':

            customer_list();        //For printing the list of the customers with all the details
            admin_menu();
            break;
    case '8':
        system("cls");intro();
        //while(1)
        {
            cout<<"\n\n\n\tEnter the name of the customer : ";
            cin>>no;
            int flag=0;
            fp.open("Customer.dat",ios::in);
            while(fp.read((char*)&cu,sizeof(customer)))
            {
                int i=0;
                if(cu.name==no)
                {
                    flag=1;
                    cout<<"\n==========================================================================";
                    cout<<"\n\tCustomer id\t\tCustomer name\t\tPhone no\t";
                    cout<<"\n==========================================================================";
                    cout<<"\n\t"<<cu.cid<<"\t\t\t"<<cu.name<<"\t\t\t"<<cu.phno<<"\t";
                    cout<<"\n\n\tProducts bought by Mr."<<cu.name<<" are as follows"<<endl;
                    cout<<"\n==========================================================================";
                    cout<<"\n\n\tProduct Id\tProduct name\t\tQuantity";
                    cout<<"\n==========================================================================";
                    while(i<cu.num)
                            {
                            cout<<"\n\t"<<cu.cart[i][0]<<"\t\t";
                            fp1.open("Shop.dat",ios::in);
                             while(fp1.read((char*)&pr,sizeof(product)))
                             {
                                 if(pr.retpno()==cu.cart[i][0])
                                 {
                                 cout<<pr.retname();
                                /* int z=strlen(pr.retname());
                                 z=z/3;
                                 for(int l=1-z;l>=0;l--)
                                 cout<<'\t\t';
                                */
                                 }
                             }
                                fp1.close();
                                cout<<"\t\t\t"<<cu.cart[i][1]<<'\t'<<endl;
                                i++;

                            }
                    cout<<"\n==========================================================================";
                    if(cu.spdis!=0)
                    cout<<"\n                  Special Discount offered = "<<cu.spdis<<"%"<<endl;
                    cout<<"\n                  Total Purchasing done = $"<<cu.tot<<endl;



                    break;
                }
            }
            fp.close();
            if(flag==0)
                cout<<"\n\t\t\tRecord does not exist please try again\n";
            else
                {
            cout<<"\n==========================================================================";
                }
        }
        getch();
        admin_menu();
        break;

    case '9':
            system("cls");intro();
            break;
    default:
    cout<<"\a";
    admin_menu();        //If a wrong choice is entered then again the admin menu will be printed
    }
}


//***************************************************************
// THE MAIN FUNCTION OF PROGRAM
//***************************************************************

int main()                  //Staring of the main function
{
    system("color B");
    gotoxy(10,6);
    cout<<"\t\t\tSUPERMARKET BILING SYSTEM PROJECT\n";
    cout<<"\n\tProgrammed by :- ";
    cout<<"\n\t\t\tHarshit jalan \t\t\t\t Shrestha kumar\n\t\t\tBranch-EE \t\t\t\t Branch-EE\n\t\t\tRoll no-150002017 \t\t\t Roll no-150002034";
   // gotoxy(2,10);
    //cout<<"\n\t\tShrestha kumar\n\t\tBranch-EE\n\t\tRoll no-150002034";

    gotoxy(10,15);
	cout<<"Store is opening ";								//Informs that project is loading
	for(int m=0;m<10;m++)
	{
		delay(300);
		cout<<".";
	}
	delay(1000);
    system("cls");intro();
    int ch;
    while(1)
    {
        cout<<"\n\n\n\tMAIN MENU";         //Starting of main menu
        cout<<"\n\n\t01. CUSTOMER";             //Entering as customer
        cout<<"\n\n\t02. ADMINISTRATOR";        //Entering as administrator
        cout<<"\n\n\t03. EXIT";
        cout<<"\n\n\tPlease Select Your Option (1-3) : ";
        ch=getche();
        switch(ch)
        {
            case '1':
            {
                place_order();           //calling the place order function
                getch();
                break;
            }
            case '2':
            {
                Password();              //Calling the password function
                if(strcmp(password,"project")==0)
                {
                    cout<<"\n\n\tWelcome ! Admin ";
                    cout<<"\n\n\tPress enter for moving to admin menu";
                    getch();
                    admin_menu();             //Calling the admin menu if the password matches
                }
                else
                {
                        cout<<"\n\n\tWrong password ! You are not authorized to use admin mode";
                }

                break;
            }
            case '3':
            {
                system("cls");
                cout<<"\n\n\n\n\n\t\t\tThank you for coming to our store\n\n\n\t";
                delay(1000);
                system("cls");
                exit(0);
            }
            default :
            {
                system("cls");
                intro();
                cout<<"\n\n\tEnter the correct option";
                cout<<"\a";
            }
        }
}
return 0;
}

//***************************************************************
// END OF PROJECT
