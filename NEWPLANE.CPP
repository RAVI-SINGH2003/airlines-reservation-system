// --------------Header files used in the program-------------
#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
class airlines
{
public:
// Variables......
int aadhar,age,tkt_pr,flt_no,seat_no,mobile,newtkt_pr;
char clss[30],name[50],user[30],passport[30],loc[30];
char dest[30],date[30],country[30],pass[20],depttime[30];
public:
// Functions......
void regi();
void login();
void book();
void cancel();
void display();
void list();
void Continue();
void climax();
void climaxlogin();
void list1();
}a;   //Object of class airlines

//Function to decide whether to continue with the program or not.

void airlines::Continue()
{
 char ch_list;
 cout<<"\n\n\tDo you want to continue(y/n)  ?";
 cin>>ch_list;
 if(ch_list=='y'||ch_list=='Y')

{ clrscr();
 a.list();

 }else
 a.climax();
}

//----------------- Functions used for payments----------------
void debit()
{
 char card[20], pin[20],cvv[20],mnno[10],otp[10];
 cout<<"\n\tEnter Card No. : ";

 gets(card);
 cout<<"\tEnter Pin No. : "; // Payment using debit card
 gets(pin);
 cout<<"\tEnter CVV No. : ";
 gets(cvv);
 cout<<"\tEnter Phone NO.: ";
 gets(mnno);
 cout<<"\tOTP has been sent to your no. \n\tEnter OTP: ";
 gets(otp);
 cout<<"\n\t~~~~~~~~ THANKS FOR BOOKING YOUR TICKET~~~~~~~~~";
a.Continue();
}
void credit()
{
 char card[20],pin[20],otp[10],mnno[10];
 cout<<"\n\tEnter Card No. : ";
 gets(card);
 cout<<"\tEnter PIN No. : "; // Payment using credit card
 gets(pin);
 cout<<"\tEnter Phone No.: ";
 gets(mnno);
 cout<<"\tOTP has been sent to your no. \n\tEnter OTP: ";
 gets(otp);
 cout<<"\n\t ~~~~~~~~ THANKS FOR BOOKING YOUR TICKET~~~~~~~~~";
 a.Continue();
}
void netbank()
{
 char accno[20],pin[20],mnno[10],otp[10];
 cout<<"\n\tEnter Account No.: ";
 gets(accno);                      // Payment using net banking
 cout<<"\tEnter PIN No. : ";
 gets(pin);
 cout<<"\tEnter Phone No. : ";
 gets(mnno);
 cout<<"\tOTP has been sent to your no. \n\tEnter OTP: ";
 gets(otp);
 cout<<"\n\t ~~~~~~~~ THANKS FOR BOOKING YOUR TICKET~~~~~~~~~";
 a.Continue();
}
//-------------- function to exit if login fail -------------------

void airlines::climaxlogin()
{
  char a[]="*!*!*!*!* -> YOU ENTERED WRONG PASSWORD OR USER NAME<-*!*!*!*!*";
 int l;
 clrscr();
 gotoxy(15,9);
 l =strlen(a);
 for(int i=0;i<=l;i++)
 {
delay(30);
textcolor(14);
textbackground(10);
cprintf("%c",a[i]);
}
delay(1000);
exit(0);
clrscr();


}
//------------------ Function to exit from program-------------------
void airlines ::climax()
{
 char a[]="*!*!*!*!*!*!* -> HAVE A NICE TRIP <-*!*!*!*!*!*!*";
 int l;
 clrscr();
 gotoxy(15,9);
 l =strlen("*!*!*!*!*!*!*-> HAVE A NICE TRIP <-*!*!*!*!*!*!*");
 for(int i=0;i<=l;i++)
 {
delay(30);
textcolor(14);
textbackground(10);
cprintf("%c",a[i]);
}
 delay(1000);
 exit(0);
clrscr();
}
//------------------Function used for registration-----------------
void airlines::regi()
{  clrscr();

cout<<"\n\n\t ********-----Register Your Account-----********";
fstream r;
r.open("reg.dat",ios::binary|ios::out);

cout<<"\n\n\tCreate your user name : ";
gets(user);
cout<<"\n\tCreate your password : ";
gets(pass);
cout<<"\n\tEnter your mobile no : ";
cin>>mobile;
cout<<"\n\tEnter your aadhar no : ";
cin>>aadhar;
r.write((char*)&a,sizeof (a));
r.close();
cout<<"\n\n\t *******> REGISTRATION COMPLETED <********";
cout<<"\n\n\t -------------*-------------*-------------*-------------";
}
// ----------------------Function used for LOG IN -------------------------
void airlines::login()
{
clrscr();
int check=0;

cout<<"\n\t |----------- lOGIN TO YOUR ACCOUNT  -----------|";
char user_n[30],pass_n[30];
cout<<"\n\n\tEnter Your User Name : ";
gets(user_n);
cout<<"\n\tEnter Your Password : ";
gets(pass_n);
fstream r;
r.open("reg.dat",ios::binary|ios::in);
while(r.read((char*)&a,sizeof(a)));
{
if(strcmp(user_n,user)==0&&strcmp(pass_n,pass)==0)
{

 check=1;
}
}
r.close();
if(check==1)
a.list1();
else
{
a.climaxlogin();
}

}

//-----------------Function used for booking the ticket---------------
void airlines::book()
{ clrscr();

 cout<<"\n\t *********> BOOK YOUR TICKET <*********";
  fstream book;
  book.open("book.dat",ios::binary|ios::out);
  cout<<"\n\n\tEnter the following details : ";
  cout<<"\n\n\tName : ";
  gets(name);
  cout<<"\tPassport ID : ";
  gets(passport);
  cout<<"\tCountry : ";
 gets(country);
 cout<<"\tLocation : ";
 gets(loc);
 cout<<"\tDeparture Date : ";
 gets(date);
 cout<<"\tDestination : ";
 gets(dest);
 clrscr();
 int c;
 cout<<"\n";
 cout<<"\n\t **********>CLASS TYPE <**************";
 cout<<"\n\n\tChoose Class:";
 cout<<"\n\t1.BUSSINESS CLASS";
 cout<<"\n\t2.ECONOMY CLASS\n"<<"\n\tEnter your choice :";
 cin>>c;
 if(c==1)
 strcpy(clss,"BUSSINESS CLASS");
 else
 strcpy(clss,"ECONOMY CLASS");
 srand(time(NULL));

 tkt_pr=rand()%1000+10000;
 flt_no=rand()%100+1000;
 seat_no=rand()%100;
 cout<<"\n\n\tTicket price: INR "<<tkt_pr;
 cout<<"\n\tFlight Name : "<<"SKYLINE";
 cout<<"\n\tFlight no.  : "<<flt_no;
 cout<<"\n\tSeat no.    : "<<seat_no;
 int dept;
 cout<<"\n\n\tSelect the time of departure:";

 cout<<"\n\t1.09:30 am"<<"\n\t2.02:00 pm"<<"\n\t3.06:00 am"<<"\n\t4.09:00 pm"<<"\n\t5.10:00 pm\n\t";
 cout<<"\n\tEnter your choice : ";
 cin>>dept;
 if(dept==1)
 strcpy(depttime,"09:30 am");
 else if(dept==2)
 strcpy(depttime,"02:00 pm");
 else if(dept==3)
 strcpy(depttime,"06:00 am");
 else if(dept==4)
 strcpy(depttime,"09:00 pm");
 else
 strcpy(depttime,"10:00 pm");

 clrscr();
 cout<<"\n\tEnter your Age : ";
 cin>>age;


if(age>=60)
{
 cout<<"\n\t!! YOU ARE A SENIOR CITIZEN !!"; //Giving Discount for senior citizen.....
 newtkt_pr=(tkt_pr*0.7);
 cout<<"\n\n\tYour new ticket price ->INR"<<newtkt_pr;
 cout<<"\n\tDISCOUNT PROVIDED       -> 30% ";
}
 else
{ newtkt_pr=tkt_pr;
 cout<<"\n\tYOU ARE NOT A SENIOR CITIZEN !!";
 cout<<"\n\n\tNo discount on ticket for you";
 cout<<"\n\tYour ticket price is INR"<<newtkt_pr;
}
book.write((char*)&a,sizeof(a));
book.close();
cout<<"\n\n\t ********> YOUR TICKET HAS BEEN BOOKED!!!<*******";
cout<<"\n -------------*---------------*---------------*----------------";

}

// Functions used to display the details of flight and passengers
void airlines::display()
{

clrscr();
cout<<"\n\tPASSENGER DETAILS ";
cout<<"\n\t~~~~~~~~~~~~~~~~~ ";
cout<<"\n\n\tName : "<<name;
cout<<"\n\tPassport ID : "<<passport;
cout<<"\n\tAge : "<<age;
cout<<"\n\tCountry : "<<country;
cout<<"\n\tLocation : "<<loc;
cout<<"\n\n\tFLIGHT DETAILS ";
cout<<"\n\t~~~~~~~~~~~~~~ ";
cout<<"\n\tFlight Name : SKYLINE";
cout<<"\n\tDestination : "<<dest;
cout<<"\n\tDeparture : "<<date;
cout<<"\n\tDeparture time : "<<depttime;
cout<<"\n\tTicket price : "<<"INR"<<tkt_pr;
cout<<"\n\tFlight no. : "<<flt_no;
cout<<"\n\tSeat no. : "<<seat_no;
cout<<"\n\tClass : "<<clss;
cout<<"\n\n\t -----------*---------------*--------------*--------------";
a.Continue();
}
//---------------Function to cancel passenger ticket--------------
void airlines::cancel()
{clrscr();

cout<<"\n\t*********> CANCEL RESERVATION <*********";
fstream del;
del.open("book.dat",ios::binary|ios::in);

int fltno,seatno;
char c;
cout<<"\n\n\tEnter Flight no.: ";
cin>>fltno;
cout<<"\n\tEnter Seat no. : ";
cin>>seatno;

while(del.read((char*)&a,sizeof(a)))
{
 if(fltno==flt_no&&seatno==seat_no)

 {

cout<<"\n\n\tPassenger name : "<<name;
cout<<"\n\tAge : "<<age;
cout<<"\n\tCountry : "<<country;
cout<<"\n\tDestination : "<<dest;
cout<<"\n\tDeparture Date : "<<date;
cout<<"\n\tDeparture Time : "<<depttime;
}
else
{
 cout<<"\n\t NO RECORD FOUND !!!!!!" ;
 a.Continue();
}

}
cout<<"\n\n\tDO YOU REALLY WANT  TO CANCEL THIS RESERVATION (Y) OR (N)? : ";
cin>>c;
if(c=='y'||c=='Y')
{
cout<<"\n\tYOUR RESERVATION HAS BEEN CANCELLED!!!";
cout<<"\n\n\tTicket cost paid: "<<tkt_pr;
cout<<"\n\tREFUND CHARGES : INR 500";
cout<<"\n\tINR "<<tkt_pr-500<<" will be returned you back";

}
else {
cout<<"\n\tNO CHANGES MADE";
a.Continue();
}
del.close();
remove("book.dat");
cout<<"\n";
cout<<"\n\t -------------*------------*--------------*---------------";
a.Continue();
}
//----------Function for menu after successfullogin ---
void airlines::list1()
{ clrscr();
int choice;
cout<<"\n\n\t!!!!!! YOU HAVE  SUCCESSFULLY LOGGED IN TO YOUR ACCOUNT !!!!!!";
cout<<"\n\t ---------------*-------------*----------------*----------------";
cout<<"\n\n\t  CHOOSE FROM THE FOLLOWING OPTIONS:";
cout<<"\n\t|-----------------------------------|";
cout<<"\n\t| BOOK TICKETS..................(1) |";
cout<<"\n\t|-----------------------------------|";
cout<<"\n\t| DISPLAY PASSENGER.............(2) |";
cout<<"\n\t|-----------------------------------|";
cout<<"\n\t| CANCEL TICKETS................(3) |";
cout<<"\n\t|-----------------------------------|";
cout<<"\n\t| EXIT..........................(4) |";
cout<<"\n\t|-----------------------------------|";
cout<<"\n\n\tEnter your choice ---> ";
cin>>choice;
switch(choice)
{
  case 1:

 a.book();
 int pay;
 cout<<"\n\tChoose your payment option";
 cout<<"\n\t1. Debit";
 cout<<"\n\t2. Credit";
 cout<<"\n\t3. Net Banking";
 cout<<"\n\tEnter your choice :";
 cin>>pay;
 if(pay==1)
 debit();
 else if(pay==2)
 credit();
 else
 netbank();
 break;
 case 2: fstream disp;
 disp.open("book.dat",ios::binary|ios::in);
 if(! disp)
 {
  cout<<"\n\tNO RECORDS FOUND ";
  a.Continue();
 }
 while(disp.read((char*)&a,sizeof(a)))
 a.display();
 disp.close();


 break;
case 3: a.cancel();
	break;
case 4: a.climax();
	 break;
default:cout<<"\n\tInvalid choice!";

}
}

// -----------------------Function used for Main Menu----------------
void airlines ::list()
{

int choice,pay;

cout<<"\n\n\t *****************************************************************";
cout<<"\n\t *\t WELCOME TO SKYLINE'S ONLINE TICKET RESERVATION SYSTEM   *";
cout<<"\n\t *                                                               *";
cout<<"\n\t *****************************************************************";
cout<<"\n";
cout<<"\n\t -->Book your tickets anytime(24*7) online"<<"\n\t -->Best airlines service";
cout<<"\n";
cout<<"\n\t Please choose from the following:";
cout<<"\n\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
cout<<"\n\t |-----------------------------------|";
cout<<"\n\t | REGISTER YOURSELF..............(1)|";
cout<<"\n\t |-----------------------------------|";
cout<<"\n\t | LOGIN TO YOUR ACCOUNT..........(2)|";
cout<<"\n\t |-----------------------------------|";
cout<<"\n\t | EXIT...........................(3)|";
cout<<"\n\t |-----------------------------------|";
cout<<"\n\n\t Enter your choice -->";
cin>>choice;
switch(choice)
{
 case 1:
 a.regi();
 a.Continue();
 break;
 case 2:

 a.login();
 break;

case 3: a.climax();
	break;
default:cout<<"\n\tInvalid choice!";
}

}
void main()

{ clrscr();
  a.list();
  getch();
}
