#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<iomanip.h>
#include<dos.h>
#include<process.h>
void Design();
class Quiz
{
 int qusno,score,pid;
 char qusnm[100],a[50],b[50],c[50],d[50],ans,nm[50],city[50],state[50],cont[50];
 Quiz *next,*head,*tail;
 public:
	Quiz()
	{
	 qusno=0;
	 pid=1111;
	}
	void getdata();
	void showdata();
	void modifydata();
	int retqusno();
	int user();
	void getDetails();
	void putDetails1();
	void putDetails2();
	void showdataDesign();
	void readfile();
};
//****************************************************************************
       void Quiz::getdata()
       {
	fstream file;
	Quiz ob;
	file.open("quiz.dat",ios::in|ios::out|ios::binary|ios::app);
	file.clear();
	file.seekg(ios::beg);
	while(file.read((char*)&ob,sizeof(ob)));//reaching end value
	++qusno;
	cout<<"\n Enter Question: ";
	gets(qusnm);
	cout<<"\n Enter Option 1(a): ";
	gets(a);
	cout<<"\n Enter Option 2(b): ";
	gets(b);
	cout<<"\n Enter Option 3(c): ";
	gets(c);
	cout<<"\n Enter Option 4(d): ";
	gets(d);
	cout<<"\n Enter Correct Answer(a, b, c or d): ";
	cin>>ans;
       }
//****************************************************************************
       void Quiz::showdata()
       {
	cout<<"\n\n Question Number is: "<<qusno
	    <<"\n\n Question is: "<<qusnm
	    <<"\n\n Option 1(a) is: "<<a
	    <<"\n\n Option 2(b) is: "<<b
	    <<"\n\n Option 3(c) is: "<<c
	    <<"\n\n Option 4(d) is: "<<d
	    <<"\n\n Correct Answer(a, b, c or d): "<<ans;
       }
//****************************************************************************
       void Quiz::modifydata()
       {
	char ch;
	cout<<"\n\n\t\t OLD DETAILS";
	showdata();
	getch();
	while(1)
	{
	 textcolor(WHITE);
	 clrscr();
	 cout<<"\n\t\t   ==============="
	     <<"\n\t\t     MODIFY MENU"
	     <<"\n\t\t   ==============="
	     <<"\n\n\t\t 1.QUESTION"
	     <<"\n\n\t\t 2.OPTION 1(a)"
	     <<"\n\n\t\t 3.OPTION 2(b)"
	     <<"\n\n\t\t 4.OPTION 3(c)"
	     <<"\n\n\t\t 5.OPTION 4(d)"
	     <<"\n\n\t\t 6.ANSWER(a, b, c or d)"
	     <<"\n\n\t\t 7.RETURN TO ADMINISTRATOR MENU"
	     <<"\n\n\t\t Enter your choice <1-7>: ";
	 ch=getch();
	 cout<<ch;
	 switch(ch)
	 {
	  case '1':clrscr();
		   cout<<"\n\n Enter New Question: ";
		   gets(qusnm);
		   break;
	  case '2':clrscr();
		   cout<<"\n\n Enter New Option 1(a): ";
		   gets(a);
		   break;
	  case '3':clrscr();
		   cout<<"\n\n Enter New Option 2(d): ";
		   gets(b);
		   break;
	  case '4':clrscr();
		   cout<<"\n\n Enter New Option 3(c): ";
		   gets(c);
		   break;
	  case '5':clrscr();
		   cout<<"\n\n Enter New Option 4(d): ";
		   gets(d);
		   break;
	  case '6':clrscr();
		   cout<<"\n\n Enter New Correct Answer(a, b, c or d): ";
		   cin>>ans;
		   break;
	  case '7':return;
	  default:cout<<"\n\n\t\t Please choose correct option !!!"
		      <<"\n\n\t\t Press any key to continue....................";
		  getch();
	 }
	}
       }
//****************************************************************************
       int Quiz::retqusno()
       {
	return qusno;
       }
//****************************************************************************
       void Quiz::getDetails()
       {
	cout<<"\n\n\t Enter your name: ";
	gets(nm);
	cout<<"\n\n\t Enter your city: ";
	gets(city);
	cout<<"\n\n\t Enter your state: ";
	gets(state);
	cout<<"\n\n\t Enter your country: ";
	gets(cont);
       }
//****************************************************************************
       void Quiz::putDetails1()
       {
	clrscr();
	fstream file;
	Quiz ob;
	file.open("data.dat",ios::in|ios::out|ios::binary|ios::app);
	file.clear();
	file.seekg(ios::beg);
	while(file.read((char*)&ob,sizeof(ob)))++pid;//reaching end value
	cout<<"\n\n\t\t DETAILS are: "
	    <<"\n\n\t Player id is: "<<pid
	    <<"\n\n\t Your name is: "<<nm
	    <<"\n\n\t Your city is: "<<city
	    <<"\n\n\t Your state is: "<<state
	    <<"\n\n\t Your country is: "<<cont
	    <<"\n\n\t Your score is: "<<score;
	getch();
       }
//****************************************************************************
       void Quiz::putDetails2()
       {
	clrscr();
	cout<<"\n\n\t\t DETAILS are: "
	    <<"\n\n\t Player id is: "<<pid
	    <<"\n\n\t Your name is: "<<nm
	    <<"\n\n\t Your city is: "<<city
	    <<"\n\n\t Your state is: "<<state
	    <<"\n\n\t Your country is: "<<cont
	    <<"\n\n\t Your score is: "<<score;
	getch();
       }
//****************************************************************************
       void Quiz::showdataDesign()
       {
	Design();
	gotoxy(6,3);
	cout<<qusnm;
	gotoxy(6,8);
	cout<<"A: "<<a;
	gotoxy(43,8);
	cout<<"B: "<<b;
	gotoxy(6,11);
	cout<<"C: "<<c;
	gotoxy(43,11);
	cout<<"D: "<<d;
       }
//****************************************************************************
       void Exit()
       {
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t !!*****THANKYOU FOR PLAYING******!!"
	    <<"\n\n\t\t\t !!**********VISIT AGAIN**********!!";
	getch();
       }
//****************************************************************************
       void shuffle(int values[], int size)
       {
	srand((int)time(NULL));
	for (int i=0;i<(size*20);i++)
	{
	 int randvalue1=(rand()%size),randvalue2=(rand()%size);
	 int temp = values[randvalue1];
	 values[randvalue1] = values[randvalue2];
	 values[randvalue2] = temp;
	}
       }
//****************************************************************************
       int Quiz::user()
       {
	clrscr();
	int f=0;
	char answer;
	score=0;
	Quiz ob;
	fstream file;
	file.open("quiz.dat",ios::in|ios::out|ios::binary|ios::app);
	file.clear();
	file.seekg(ios::beg);
	while(file.read((char*)&ob,sizeof(ob)));//reaching end value
	file.close();
	int min=1,max=ob.qusno,range=(max-min),*values = new int[range];
	for(int i=0;i<=range;i++)
	 values[i]=min+i;
	shuffle(values,range+1);
	for(i=0;i<=range;i++)
	{
	 file.open("quiz.dat",ios::in|ios::out|ios::binary|ios::app);
	 file.clear();
	 file.seekg(ios::beg);
	 while(file.read((char*)&ob,sizeof(ob)))
	 {
	  if(ob.qusno==values[i])
	  {
	   clrscr();
	   ob.showdataDesign();
	   gotoxy(21,14);
	   cout<<"ANS(options a, b, c or d)";
	   gotoxy(21,15);
	   cout<<"(if you want to quit press 'q'): ";
	   int time=30;
	   while(!kbhit())
	   {
	    gotoxy(33,18);
	    cout<<"Time left: "<<setw(2)<<setfill('0')<<time;
	    if(time==0)
	    {
	     delay(1000);
	     score-=10;
	     goto lable;
	    }
	    delay(1000);
	    time--;
	   }
	   textcolor(WHITE);
	   answer=getch();
	   gotoxy(54,15);
	   cout<<answer;
	   if('q'==tolower(answer))
	   {
	    gotoxy(5,21);
	    cout<<"BYE BYE!!!";
	    getch();
	    return 1;
	   }
	   else
	   if(tolower(ob.ans)==tolower(answer))
	   {
	    textcolor(GREEN);
	    gotoxy(5,21);
	    cprintf("Bravo!!! Correct Answer\nPress any key for next question....................");
	    score+=10;
	    getch();
	   }
	   else
	   if(tolower(ob.ans)!=tolower(answer))
	   {
	    textcolor(RED);
	    gotoxy(5,21);
	    cprintf("Sorry!!! Wrong Answer");
	    gotoxy(5,22);
	    cprintf("The correct answer is: %c",ob.ans);
	    cprintf("\nPress any key for next question....................");
	    score-=5;
	    getch();
	   }
	  }
	  f=1;
	 }
	 file.close();
	 lable:f=1;
	}
	return f;
       }
//****************************************************************************
       void Quiz::readfile()
       {
	int x=0,y,f=0;
	fstream file;
	Quiz ob,*t=NULL,*i=NULL;
	head=NULL;
	file.open("data.dat",ios::in|ios::out|ios::binary|ios::app);
	file.clear();
	file.seekg(ios::beg);
	while(file.read((char*)&ob,sizeof(ob)))
	{
	 t=new Quiz;
	 *t=ob;
	 if(head==NULL)
	 {
	  head=t;
	  tail=t;
	  tail->next=NULL;
	 }
	 else
	 {
	  if(t->score > head->score)
	  {
	   t->next=head;
	   head=t;
	  }
	  else
	  {
	   for(i=head;i->next!=NULL;i=i->next)
	   {
	    if(t->score>=i->next->score)
	    {
	     t->next=i->next;
	     i->next=t;
	     i=t;
	     break;
	    }
	   }
	   if(t->score < i->score)
	   {
	    i->next=t;
	    tail=t;
	    tail->next=NULL;
	   }
	  }
	 }
	 f=1;
	}
	file.close();
	if(f==1)
	{
	 cout<<"================================================================================";
	 cout<<"RANK PLAYER ID  NAME          CITY          STATE          COUNTRY         SCORE";
	 cout<<"================================================================================";
	 for(y=4,t=head;t!=NULL;t=t->next,y+=1)
	 {
	  gotoxy(1,y);
	  cout<<++x;
	  gotoxy(6,y);
	  cout<<t->pid;
	  gotoxy(16,y);
	  cout<<t->nm;
	  gotoxy(30,y);
	  cout<<t->city;
	  gotoxy(44,y);
	  cout<<t->state;
	  gotoxy(59,y);
	  cout<<t->cont;
	  gotoxy(77,y);
	  cout<<setw(2)<<setfill('0')<<t->score;
	 }
	}
	else
	 cout<<"\n\n\t\t\t No winners.";
	cout<<"\n\n\t\t\t Press any key to continue....................";
       }
//****************************************************************************
void intro()
{
 clrscr();
 cout<<"\n++++++++++++++++++++++++++++++++++++++++*++++++++++++++++++++++++++++++++++++++"
     <<"\n+                                      ***                                    +"
     <<"\n+                                     *****                                   +"
     <<"\n+                                    *******                                  +"
     <<"\n+                                   *********                                 +"
     <<"\n+                                  ***********                                +"
     <<"\n+                                 *************                               +"
     <<"\n+                                ***************                              +"
     <<"\n+                               *****************                             +"
     <<"\n+                              *******************                            +"
     <<"\n+                             *******WELCOME*******                           +"
     <<"\n+                              *******************                            +"
     <<"\n+                               *****************                             +"
     <<"\n+                                ***************                              +"
     <<"\n+                                 *************                               +"
     <<"\n+                                  ***********                                +"
     <<"\n+                                   *********                                 +"
     <<"\n+                                    *******                                  +"
     <<"\n+                                     *****                                   +"
     <<"\n+                                      ***          By:- Sayan Halder         +"
     <<"\n++++++++++++++++++++++++++++++++++++++++*++++++++++++++++++++++++++++++++++++++"
     <<"\n ************************************QUIZ*************************************"
     <<"\n                          PRESS ANY BUTTON TO CONTINUE...............";
 getch();
}
//****************************************************************************
void Administrator()
{
 clrscr();
 char *password,*pass="12345678";
 char ch;
 int qno,pos,t,f;
 fstream file,temp;
 Quiz ob;
 clrscr();
 password=getpass("\n\n\t Enter Password:- ");
 if(strcmp(pass,password)!=0)
 {
  cout<<"\n\n\t Enter the password correctly.\n\n\t You are not permitted to enter.";
  cout<<"\n\n\t Press any key to continue....................";
  getch();
  clrscr();
 }
 else
 if(strcmp(pass,password)==0)
 {
  while(1)
  {
   textcolor(WHITE);
   clrscr();
   cout<<"\n\t\t   ======================"
       <<"\n\t\t     ADMINISTRAROR MENU"
       <<"\n\t\t   ======================"
       <<"\n\n\t\t 1.ADD QUESTION"
       <<"\n\n\t\t 2.LIST QUESTION"
       <<"\n\n\t\t 3.MODIFY QUESTION"
       <<"\n\n\t\t 4.DELETE QUESTION"
       <<"\n\n\t\t 5.DELETE ALL QUESTIONS"
       <<"\n\n\t\t 6.RETURN TO MAIN MENU"
       <<"\n\n\t\t Enter your choice <1-6>: ";
   ch=getch();
   cout<<ch;
   switch(ch)
   {
    case '1':clrscr();
	     file.open("quiz.dat",ios::in|ios::out|ios::binary|ios::app);
	     file.clear();
	     file.seekp(ios::end);
	     ob.getdata();
	     file.write((char*)&ob,sizeof(ob));
	     file.close();
	     break;
    case '2':clrscr();
	     f=0;
	     file.open("quiz.dat",ios::in|ios::out|ios::binary|ios::app);
	     file.clear();
	     file.seekg(ios::beg);
	     while(file.read((char*)&ob,sizeof(ob)))
	     {
	      ob.showdata();
	      cout<<"\n\n\n Press any key to continue....................";
	      getch();
	      clrscr();
	      f=1;
	     }
	     file.close();
	     if(f==0)
	     {
	      cout<<"\n\n\t\t\t No questions are their."
		  <<"\n\n\t\t\t Press any key to continue....................";
	      getch();
	     }
	     break;
    case '3':clrscr();
	     file.open("quiz.dat", ios::binary|ios::out|ios::in);
	     cout<<"\n\n Enter Question Number to Modify:- ";
	     cin>>qno;
	     while(!file.eof())
	     {
	      pos=file.tellg();
	      file.read((char*)&ob,sizeof(ob));
	      t=ob.retqusno();
	      if(t==qno)
	      {
	       ob.modifydata();
	       file.seekg(pos);
	       file.write((char*)&ob,sizeof(ob));
	       f=1;
	       break;
	      }
	      else
	      f=0;
	     }
	     if(f==0)
	     {
	      cout<<"\n\n Not found the entered question number."
		  <<"\n\n Press any key to continue....................";
	      getch();
	     }
	     file.close();
	     break;
    case '4':clrscr();
	     cout<<"\n\n Enter Question Number to Delete:- ";
	     cin>>qno;
	     file.open("quiz.dat",ios::in|ios::out|ios::binary|ios::app);
	     temp.open("temp.dat",ios::out|ios::binary);
	     file.clear();
	     file.seekg(0,ios::beg);
	     while(file.read((char*)&ob,sizeof(ob)))
	     {
	      t=ob.retqusno();
	      if(t!=qno)
	       temp.write((char*)&ob,sizeof(ob));
	      else
	       f=1;
	     }
	     if(f==1)
	     {
	      cout<<"\n\n Record has been deleted.";
	      file.close();
	      temp.close();
	      remove("quiz.dat");
	      rename("temp.dat","quiz.dat");
	      cout<<"\n\n Press any key to continue....................";
	      getch();
	      clrscr();
	     }
	     else
	     {
	      temp.close();
	      remove("temp.dat");
	      cout<<"\n\n Not found the entered question number."
		  <<"\n\n Press any key to continue....................";
	      getch();
	     }
	     file.close();
	     break;
    case '5':remove("quiz.dat");
	     clrscr();
	     cout<<"\n\n\t\t\t All question are deleted."
		 <<"\n\n\t\t\t Press any key to continue....................";
	     getch();
	     break;
    case '6':return;
    default:cout<<"\n\n\t\t Please choose correct option !!!"
		<<"\n\n\t\t Press any key to continue....................";
	    getch();
   }
  }
 }
}
//****************************************************************************
void rules()
{
 clrscr();
 cout<<"\n\t\t   ========="
     <<"\n\t\t     RULES"
     <<"\n\t\t   ========="
     <<"\n\n1.All question are compulsary."
     <<"\n\n2.Total 15 question are their."
     <<"\n\n3.Press 'a', 'b', 'c' or 'd' as answer for the question."
     <<"\n\n4.30 seconds will be given for every question to answer."
     <<"\n\n5.If you want to quit the game press 'q'."
     <<"\n\n6.Every correct answer will give you 10 points."
     <<"\n\n7.Every wrong answer will deduct 5 points from total score."
     <<"\n\n8.If time limit exceeds for the question 10 points will be deducted from total    score."
     <<"\n\n\t\t\t Press any key to continue....................";
 getch();
 clrscr();
}
//****************************************************************************
void Play()
{
 clrscr();
 int f;
 rules();
 fstream file;
 Quiz ob;
 ob.getDetails();
 f=ob.user();
 if(f==1)
 {
  file.open("data.dat",ios::in|ios::out|ios::binary|ios::app);
  file.clear();
  file.seekp(ios::end);
  ob.putDetails1();
  file.write((char*)&ob,sizeof(ob));
  file.close();
 }
 else
 {
  cout<<"\n\n\t\t\t No questions are available to play"
      <<"\n\n\t\t\t Press any key to continue....................";
  getch();
 }
}
//****************************************************************************
void Detail()
{
 clrscr();
 fstream file;
 Quiz ob;
 char rep;
 char ch;
 int f=0;
 while(1)
 {
  textcolor(WHITE);
  clrscr();
  cout<<"\n\t\t   ======================"
      <<"\n\t\t     SCORE DETAILS MENU"
      <<"\n\t\t   ======================"
      <<"\n\n\t\t 1.SHOW SCORE DETAILS"
      <<"\n\n\t\t 2.WINNERS"
      <<"\n\n\t\t 3.DELETE SCORES"
      <<"\n\n\t\t 4.RETURN TO MAIN MENU"
      <<"\n\n\t\t Enter your choice <1-4>:- ";
  ch=getch();
  cout<<ch;
  switch(ch)
  {
   case '1':clrscr();
	    file.open("data.dat",ios::in|ios::out|ios::binary|ios::app);
	    file.clear();
	    file.seekg(ios::beg);
	    while(file.read((char*)&ob,sizeof(ob)))
	    {
	     ob.putDetails2();
	     f=1;
	    }
	    file.close();
	    if(f==0)
	    {
	     cout<<"\n\n\t\t\t No previous scores are available."
		 <<"\n\n\t\t\t Press any key to continue....................";
	     getch();
	    }
	    break;
   case '2':clrscr();
	    Quiz ob;
	    ob.readfile();
	    getch();
	    break;
   case '3':remove("data.dat");
	    clrscr();
	    cout<<"\n\n\t\t\t All scores are deleted."
		<<"\n\n\t\t\t Press any key to continue....................";
	    getch();
	    break;
   case '4':return;
   default:cout<<"\n\n\t\t Please choose correct option!!!"
	       <<"\n\n\t\t Press any key to continue....................";
	   getch();
  }
 }
}
//****************************************************************************
void main()
{
 clrscr();
 char ch;
 _setcursortype(_NOCURSOR);
 intro();
 while(1)
 {
  textcolor(WHITE);
  clrscr();
  cout<<"\n\t\t   ============="
      <<"\n\t\t     MAIN MENU"
      <<"\n\t\t   ============="
      <<"\n\n\t\t 1.ADMINISTRAROR"
      <<"\n\n\t\t 2.PLAY"
      <<"\n\n\t\t 3.SCORE DETAILS"
      <<"\n\n\t\t 4.EXIT"
      <<"\n\n\t\t Enter your choice <1-4>:- ";
  ch=getch();
  cout<<ch;
  switch(ch)
  {
   case '1':Administrator();
	    break;
   case '2':Play();
	    break;
   case '3':Detail();
	    break;
   case '4':Exit();
	    exit(1);
   default:cout<<"\n\n\t\t Please choose correct option!!!"
	       <<"\n\n\t\t Press any key to continue....................";
	   getch();
  }
 }
}
//****************************************************************************
#define TL 218
#define TR 191
#define H 196
#define V 179
#define BL 192
#define BR 217
void mybox(int x1,int y1,int x2,int y2)
{
 int i;
 textcolor(LIGHTBLUE);
 gotoxy(x1,y1);
 cprintf("%c",TL);
 gotoxy(x2,y1);
 cprintf("%c",TR);
 gotoxy(x1,y2);
 cprintf("%c",BL);
 gotoxy(x2,y2);
 cprintf("%c",BR);
 for(i=x1+1;i<x2;i++)  //Horizontal Line
 {
  gotoxy(i,y1);
  cprintf("%c",H);
  gotoxy(i,y2);
  cprintf("%c",H);
  delay(5);
  sound(i*10);
 }
 for(i=y1+1;i<y2;i++)  //Verticalal Line
 {
  gotoxy(x1,i);
  cprintf("%c",V);
  gotoxy(x2,i);
  cprintf("%c",V);
  delay(20);
  sound(i*300);
 }
 nosound();
}
void Design()
{
 int x1,y1,x2,y2;
 mybox(5,2,80,6);//qus
 mybox(5,7,41,9);//a
 mybox(42,7,80,9);//b
 mybox(5,10,41,12);//c
 mybox(42,10,80,12);//d
 mybox(20,13,62,16);//ans
 mybox(32,17,49,19);//time
}