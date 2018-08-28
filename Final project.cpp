#include<ctime>
#include <stdio.h>
#include<fstream.h>
#include <iostream.h>
#include <graphics.h>
#include<string.h>
#include<conio.h>
using namespace std;
//The eye check up 2 has error in showing result

//void deleteapp();
void showappointment(int);
class doctor;
class patient;

//patdoc addappdoc(patdoc t);
void admitdoctor(int);
void appointment(int,char [],char []);
void addapp(char name[100],char field[100]);
void appointment(char name[100]);
void regpatient();
//void graphic_gets(char buffer[],int x,int y,int fore=WHITE,int back=BLACK,int limit=80);
void graphic_gets(char buffer[],int x,int y,int fore=WHITE,int back=BLACK,int limit=80)
{
    clearmouseclick(WM_LBUTTONDOWN); clearmouseclick(WM_RBUTTONDOWN); 
	int width=textwidth("W");
	int height=textheight("A");
	int cursor=x,i=0;
	char ch;
	buffer[0]='\0';
	setcolor(fore);
	setfillstyle(1,back);
	while(1)
	{	
		ch=getch();
		if(isprint(ch))
		{
			if(i<limit)
			{
				buffer[i++]=ch;
				buffer[i]='\0';
				char tempstr[2]={ch,'\0'};
				setcolor(back);
				setfillstyle(1,back);
				int a[8]={cursor,y,cursor+width,y,cursor+width,y+height+1,cursor,y+height+1};
				fillpoly(4,a);
				setcolor(fore);
				outtextxy(cursor,y,tempstr);
				cursor+=width;
			}
		}
		else if(ch==8)
		{
			if(i>0)
			{
				buffer[--i]='\0';
				cursor-=width;
				setcolor(back);
				setfillstyle(1,back);
				int a[8]={cursor,y,cursor+width,y,cursor+width,y+height-1,cursor,y+height-1};
				fillpoly(4,a);
				setcolor(fore);
			}
		}
		else if(ch==13)
			break;
	} 
	setcolor(fore);
}

class doctor
{     char name[100];
      char id[10];
      char password[10];
      char department[20];
      int dcode;
      public:
      void get(int i)
      {         switch(i)
                {        case 1:
                         strcpy(name,"Dr.Arnav Agarwal");
                         strcpy(id,"AA123");
                         strcpy(password,"aa");
                         strcpy(department,"ENT Specialist");
                         dcode=1;
                         break;
                         case 2:
                         strcpy(name,"Dr.Harsh Singhal");
                         strcpy(id,"HS123");
                         strcpy(password,"hs");
                         strcpy(department,"Opthalmologist");
                         dcode=2;
                         break;
                         case 3:
                         strcpy(name,"Dr.Hitesh Mehra");
                         strcpy(id,"HM123");
                         strcpy(password,"hm");
                         strcpy(department,"General Physician");
                         dcode=3;
                         break;
                         case 4:
                         strcpy(name,"Dr.Arsh Goyal");
                         strcpy(id,"AG123");
                         strcpy(password,"ag");
                         strcpy(department,"Dentist");
                         dcode=4;
                         break;
                         case 5:
                         strcpy(name,"Dr.Kush Mathur");
                         strcpy(id,"KM123");
                         strcpy(password,"km");
                         strcpy(department,"Neurologist");
                         dcode=5; 
                         break;
                         case 6:
                         strcpy(name,"Dr.Mushoor Gulati");
                         strcpy(id,"MG123");
                         strcpy(password,"mg");
                         strcpy(department,"Cardiologist");
                         dcode=6; 
                         break;
                         case 7:
                         strcpy(name,"Dr.Balasubramanium Iyer");
                         strcpy(id,"BI123");
                         strcpy(password,"bi");
                         strcpy(department,"Dermatologist");
                         dcode=7; 
                         break;
                         case 8:
                         strcpy(name,"Dr.Keshav Bendra");
                         strcpy(id,"KB123");
                         strcpy(password,"kb");
                         strcpy(department,"Paediatrician");
                         dcode=8; 
                         break;
                         case 9:
                         strcpy(name,"Dr.Kushal Dutta");
                         strcpy(id,"KD123");
                         strcpy(password,"kd");
                         strcpy(department,"Psychiatrist");
                         dcode=9; 
                         break;
                         case 10:
                         strcpy(name,"Dr.Ravichetan Thumbe");
                         strcpy(id,"RT123");
                         strcpy(password,"rt");
                         strcpy(department,"Pulmonologist");
                         dcode=10; 
                         break;
                }
      }         
      char* getdepartment() { return department; }
      int getdcode() { return dcode; }
      char* getname() 
      {              return name; 
      }
      char* getid() 
      {            return id; 
      }
      char* getpass()
      {              return password;
      }
};     
class patient
{
      int id;
      char name[100],age[100],gender[100],ph[100],pass[100];
       
      static int no;
      public:
             //patient() { no=no+1; id=no*16; }
             patient *link;
             void allocateid(int i) { id=i*16+1; }
             char* getname() { return name; }
             char* getage() { return age; }
             char* getgender() { return gender; }
             char* getph() { return ph; }
             char* getpass() { return pass; }
             int getid() { return id; }
             void put(char str[],char a[],char b[],char c[],char d[]) 
             { strcpy(name,str); 
             strcpy(age,a); strcpy(gender,b); strcpy(ph,c); strcpy(pass,d);
             }
}*temp=NULL,*first=NULL;
int patient::no=0;
void edit(patient p);
class patdoc: public doctor, public patient
{
       char docfield[100];
       char patname[100];
       int hour,min;
       char date[50];
       char dur;
       //char docname[100];
       public:
              void allocatetime()
              {
              }
              void putdnf(char d[50],char n[100],char f[100],char du) { strcpy(date,d); strcpy(patname,n); strcpy(docfield,f); dur=du; }
              char getdur() { return dur; }
              char* getdate() { return date; }
              int gethour() { return hour; }
              char* getdf() { return docfield; }
              int getmin() { return min; }
              void puthm(int a,int b) { hour=a; min=b; }
              char* getpat() { return patname; }
              char* getdocname(patdoc t) {
                    ifstream fin("Doctors list.dat",ios::in | ios::binary);
                    //fin.seekg(0,ios::beg);
                    
                    
                    doctor d; char str[100]; //puts(t.getdf());
                    //fin.read((char*)&d,sizeof(d));
                    //puts(d.getdepartment()); puts(d.getname());
                    fin.seekg(0,ios::beg);
                    while(!fin.eof())
                    {
                                     fin.read((char*)&d,sizeof(d));
                                     if(strcmp(d.getdepartment(),t.getdf())==0)
                                     {     //cout<<"in"<<endl; puts(d.getdepartment());
                                           strcpy(str,d.getname());
                                           break;
                                     }
                    }
                    //puts(str);
                    fin.close();
                     return str;
                      }
              //void filldocname() { 
              //patdoc *link2;
}t;       
void doctorfile()
{                fstream file;
                 file.open("Doctors list.dat",ios::out | ios::binary);
                 doctor d;
                 int i=1;
                 while(i<11)
                 {         d.get(i);
                           //puts(d.getname());
                           file.write((char*)&d,sizeof(d));
                           i=i+1;;
                 }
                 file.close();
}
int selectdoctor()
{
                   cleardevice();    
                   setbkcolor(BLACK);
                   settextstyle(0,0,5);
                   outtextxy(0,0,"CHOOSE WHO YOU ARE");
                   fstream file;
                   int x,y;
                   file.open("Doctors list.dat",ios::in);
                   doctor d;
                   int i=0;
                   char *ptr;
                   cout<<"i am here";
                   while(!file.eof())
                   {          if(file.read((char*)&d,sizeof(d)))
                              {                strcpy(ptr,d.getname());
                                               setcolor(YELLOW);
                                               setbkcolor(BLUE);
                                               //cout<<i<<endl;
                                               settextstyle(10,0,5);
                                               if(i<361)
                                               {        outtextxy(50,90+i,ptr);
                                               }
                                               else
                                               {        outtextxy(550,i-360,ptr);
                                               }
                              }
                              i=i+90;
                   }
                   file.close();
                   while(1)
                   {
                 
                   while(1)
                   {
                           if(ismouseclick(WM_LBUTTONDOWN))
                           {                               getmouseclick(WM_LBUTTONDOWN,x,y); 
                                                           break; 
                           }
                   }
                   //cout<<"see"<<endl<<x<<endl<<y<<endl;
                   setbkcolor(BLACK);
                   setcolor(WHITE);
                   
                   if(x>=50 && y>=90 && x<=450 && y<=130)
                   {               settextstyle(0,0,5); cleardevice();
                                   outtextxy(0,0,"Dr.Arnav Agarwal");
                                   i=1; admitdoctor(i); break;       
                   }
                   else if(x>=50 && y>=180 && x<=450 && y<=220)
                   {              settextstyle(0,0,5); cleardevice();
                                  outtextxy(0,0,"Dr.Harsh Singhal");
                                  i=2; admitdoctor(i); break;
                   }
                   else if(x>=50 && y>=270 && x<=425 && y<=310)
                   {              settextstyle(0,0,5); cleardevice();
                                  outtextxy(0,0,"Dr.Hitesh Mehra");
                                  i=3; admitdoctor(i); break;
                   }
                   else if(x>=50 && y>=360 && x<=375 && y<=400)
                   {              settextstyle(0,0,5); cleardevice();
                                  outtextxy(0,0,"Dr.Arsh Goyal");
                                  i=4; admitdoctor(i); break;
                   }
                   else if(x>=50 && y>=450 && x<=400 && y<=490)
                   {              settextstyle(0,0,5); cleardevice();
                                  outtextxy(0,0,"Dr.Kush Mathur");
                                  i=5; admitdoctor(i); break;
                   }
                   else if(x>=550 && y>=90 && x<=975 && y<=130)
                   {              settextstyle(0,0,5); cleardevice();
                                  outtextxy(0,0,"Dr.Mushoor Gulati");
                                  i=6; admitdoctor(i); break;
                   }
                   else if(x>=550 && y>=180 && x<=1125 && y<=220)
                   {              settextstyle(0,0,5); cleardevice();
                                  outtextxy(0,0,"Dr.Balasubramanium Iyer");
                                  i=7; admitdoctor(i); break;
                   }
                   else if(x>=550 && y>=270 && x<=950 && y<=310)
                   {              settextstyle(0,0,5); cleardevice();
                                  outtextxy(0,0,"Dr.Keshav Bendra");
                                  i=8; admitdoctor(i); break;
                   }
                   else if(x>=550 && y>=360 && x<=925 && y<=400)
                   {              settextstyle(0,0,5); cleardevice();
                                  outtextxy(0,0,"Dr.Kushal Dutta");
                                  i=9; admitdoctor(i); break;
                   }
                   else if(x>=550 && y>=450 && x<=1050 && y<=490)
                   {              settextstyle(0,0,5); cleardevice();
                                  outtextxy(0,0,"Dr.Ravichetan Thumbe");
                                  i=10; admitdoctor(i); break;
                   }
                   }
                   clearmouseclick(WM_LBUTTONDOWN);
                   
                    
}
void admitdoctor(int i)
{                 doctor d;
                  int k=1;
                  char b[2][100];
                  char a[10][100];
                  settextstyle(6,0,5);
                  while(kbhit()) getch();
                  outtextxy(350,100,"Please Enter The Following Details");
                  settextstyle(0,0,4);
                  outtextxy(0,200,"ID : ");
                  outtextxy(0,300,"Password : ");
                  graphic_gets(a[0],125,200,YELLOW);
                  graphic_gets(a[1],315,300,YELLOW);
                  fstream file;
                  file.open("Doctors list.dat",ios::in);
                  while(file)
                  {          if(file.read((char*)&d,sizeof(d)))
                             {                  if(k==i)
                                                {       strcpy(b[0],d.getid());
                                                        strcpy(b[1],d.getpass());
                                                        strcpy(a[2],d.getname());
                                                        strcpy(a[3],d.getdepartment());
                                                        break;
                                                }
                                                else
                                                {   k++;
                                                }
                             }
                  }
                  file.close();
                  if(strcmp(a[0],b[0])==0 && strcmp(a[1],b[1])==0)
                  {                       cleardevice();
                                          appointment(i,a[2],a[3]);
                                          cout<<"back"<<endl;
                                          setcolor(WHITE);
                                          setbkcolor(BLACK);
                  }
                  else
                  {   settextstyle(0,0,4);
                      setcolor(WHITE);
                      outtextxy(300,500,"Your Password is Incorrect");
                      delay(2000);
                      cleardevice();
                      selectdoctor();
                  }  
}
/*class patdoc : public doctor, public patient
{            
};*/
void appointment(int i,char s[100],char s2[100])
{                     
                      cout<<"in"<<endl;
                      setcolor(WHITE);
                      settextstyle(10,0,6);
                      outtextxy(150,0,s);
                      outtextxy(150,80,s2);
                      int x,y,op=0;
                      setcolor(RED);
                      setbkcolor(BLUE);
                      outtextxy(50,200,"Appointments");
                      outtextxy(50,580,"EXIT");
                      clearmouseclick(WM_LBUTTONDOWN);
                      while(1)
                      {       if(ismouseclick(WM_LBUTTONDOWN))
                              {                               getmouseclick(WM_LBUTTONDOWN,x,y); 
                                                              break; 
                              }
                      }
                      //clearmouseclick(WM_LBUTTONDOWN);
                      //cout<<x<<endl<<y<<endl;
                      if(x>=50 && y>=200 && x<=420 && y<=250)
                      {        settextstyle(10,0,5);
                               op=1; 
                               setcolor(YELLOW);
                               setbkcolor(BLUE);
                               outtextxy(50,270,"Upcoming Appointments");
                               outtextxy(50,320,"Delete Appointment");        
                      }
                      //clearmouseclick(WM_LBUTTONDOWN);
                      while(1 && op==1)
                      {       if(ismouseclick(WM_LBUTTONDOWN))
                              {                               getmouseclick(WM_LBUTTONDOWN,x,y); 
                                                              break; 
                              }
                      }
                      //cout<<"see"<<x<<endl<<y<<endl;
                      if(x>=50 && y>=270 && x<=575 && y<=310)
                      {
                               showappointment(i); settextstyle(10,0,6);
                                          setcolor(WHITE); cout<<"in2"<<endl; appointment(i,s,s2);    cout<<"back2";                          
                      }
                      else if(x>=50 && y>=320 && x<=500 && y<=360)
                      {
                          // deleteapp();                          
                      }
                      else if(x>=50 && y>=600 && x<=175 && y<=630)
                      {
                           cout<<"in3"<<endl;
                           setcolor(WHITE); setbkcolor(BLACK);
                           return;
                      }
}
void showappointment(int i)
{
     settextstyle(10,0,4);
     setbkcolor(BLACK);
     cleardevice();
     fstream file;
     file.open("Doctors list.dat",ios::in | ios:: binary);
     fstream sfile;
     sfile.open("Appointment.dat",ios::in | ios::binary);
     doctor d;
     while(!file.eof())
     {
                       file.read((char*)&d,sizeof(d));
                       if(i==d.getdcode())
                       break;
     }
     file.close();
     patdoc p;
     setbkcolor(BLUE);
     setcolor(YELLOW);
     outtextxy(0,0,"DATE"); outtextxy(400,0,"TIME"); outtextxy(800,0,"NAME OF THE PATIENT");
     int j=50;
     setbkcolor(BLACK);
     setcolor(WHITE);
     while(!sfile.eof())
     {
                        sfile.read((char*)&p,sizeof(p));
                        if(!sfile.eof())
                        if(strcmp(d.getdepartment(),p.getdf())==0)
                        {
                                                                  outtextxy(0,j,p.getdate());
                                                                  outtextxy(800,j,p.getpat()); 
                                                                  int l,m;
                                                                  l=p.gethour(); m=p.getmin();
                                                                  char strh[10],strm[10];
                                                                  itoa(l,strh,10); 
                                                                  itoa(m,strm,10);
                                                                  outtextxy(400,j,strh);
                                                                  outtextxy(430,j," : ");
                                                                  if(m==0)
                                                                  {
                                                                          outtextxy(470,j,strm);
                                                                          outtextxy(490,j,strm);
                                                                  }
                                                                  else
                                                                  outtextxy(470,j,strm);                                                                                                                             
                                                                  j=j+40;
                        }
     }                                                                                   
     sfile.close();
     if(j==50)
     {
              cleardevice();     outtextxy(0,100,"You have no upcoming appointments");
     }
     outtextxy(10,600,"Click to go back");
     clearmouseclick(WM_LBUTTONDOWN);
     while(1)
     {
             if(ismouseclick(WM_LBUTTONDOWN))
             break;
     }             
     //puts(d.getname());
     delay(1000);
     cleardevice();
}
     
void eyecheckup()
{         settextstyle(10,0,4);
          outtextxy(0,0,"Get Ready for your Eye Checkup");
          outtextxy(0,40,"INSTRUCTIONS :");
          outtextxy(0,70,"A line of text will appear across the screen.");
          outtextxy(0,110,"You must type what letters you see onto the screen.");
          outtextxy(0,150,"Each time, the letters will become smaller.");
          outtextxy(0,190,"At the end,we will tell you your eye strength.");
          outtextxy(0,240,"BEST OF LUCK");
          settextstyle(0,0,4);
          outtextxy(0,600,"Click To Continue");
          //while(kbhit()) getch();
          while(1)
          {       if(ismouseclick(WM_LBUTTONDOWN) || ismouseclick(WM_RBUTTONDOWN))
                  {                      cleardevice();  
                                         break;          
                  }     
          }
          clearmouseclick(WM_LBUTTONDOWN);
          unsigned int seedval;
          time_t t;
          seedval=(unsigned)time (&t);
          srand(seedval);
          int i=0;
          int x;
          char y[2];
          char f[5][10];
          y[1]='\0';
          int b=0;
          char stack[5][10];
          while(kbhit()) getch();
          while(b<5)
          {         setcolor(WHITE);
                    for(int z=0;z<250;z=z+50)
                    {       x=rand()%26+65;
                            y[0]=char(x);
                            f[b][z/50]=y[0];
                            settextstyle(0,0,6-b);
                            outtextxy(500+z,100,y);        
                    }
                    f[b][5]='\0';
                    settextstyle(0,0,5);
                    graphic_gets(stack[b],500,200,YELLOW);
                    b++;
                    cleardevice();
          }
          int ctr=0;
          b=0;
          while(b<5)
          {         if(strcmpi(stack[b],f[b])==0)
                    {                           ctr=ctr+1;
                    }
                    b++;
          }
          setcolor(WHITE);
          settextstyle(10,0,4);
          outtextxy(0,0,"The percentage efficiency of your eyes is ");
          char per[100];
          ctr=ctr*20;
          int k;
          if(ctr<60)
          k=0;
          itoa(ctr,per,10);
          setcolor(YELLOW);
          outtextxy(810,0,per);
          outtextxy(880,0,"%");
          setcolor(WHITE);
          if(k==0)
          {
                  outtextxy(0,300,"Based on the results, we suggest that you meet an opthalmologist.");
                  outtextxy(0,350,"We have BEST IN CLASS doctors!!");
                  outtextxy(0,400,"You can book an appointment with us.");
          }
          else 
          outtextxy(0,300,"Your eyes are healthy");
          outtextxy(0,600,"Click To Go Back To Main Menu");
          while(1)
          {       if(ismouseclick(WM_LBUTTONDOWN) || ismouseclick(WM_RBUTTONDOWN))
                  {                      cleardevice();  
                                         break;          
                  }     
          }
          clearmouseclick(WM_LBUTTONDOWN);        
}

time_t now = time(0);
tm *ltm = localtime(&now);

void eyecheckup1()
{
    initwindow(1360,720);
    outtextxy(0,0,"Welcome to the Eye Check Up!!");
    outtextxy(0,20,"Instructions:");
    outtextxy(0,35,"Coloured dots will flash across the screen. Each time you see one, click the left mouse button.");
    outtextxy(0,55,"BEST OF LUCK!!");
    outtextxy(0,200,"Click to continue");
    while(1)
    
    {
            if(ismouseclick(WM_LBUTTONDOWN))
            break;
    }
    //delay(1300);
    cleardevice();
    settextstyle(1,0,8);
    setcolor(RED);
    outtextxy(600,300,"3"); outtextxy(200,1,"COUNTDOWN"); delay(1000);
    cleardevice();
    outtextxy(600,300,"2"); outtextxy(200,1,"COUNTDOWN"); delay(1000);
    cleardevice();
    outtextxy(600,300,"1"); outtextxy(200,1,"COUNTDOWN"); delay(1000);
    cleardevice();
    settextstyle(1,0,2);
   
    int a,b,w,x,y,z,ctr=0; 
    unsigned int seedval;
    time_t t;
    seedval=(unsigned)time(&t);
    srand(seedval);
    a=rand()%12+5; cout<<a<<endl;
    for(int i=0;i<a;++i)
    {
            clearmouseclick(WM_LBUTTONDOWN); 
            setcolor(WHITE);
            outtextxy(550,0,"EYE CHECK UP");
            x=rand()%1231+10;
            y=rand()%631+10;
            z=rand()%4+2;
            w=rand()%15+1;
            b=rand()%301+400;
            for(int j=0;j<z;++j)
            {
                    setcolor(w);
                    circle(x,y,j);
            }
            delay(b);
            cleardevice();
            setcolor(WHITE);
            outtextxy(550,0,"EYE CHECK UP"); 
             
            if(ismouseclick(WM_LBUTTONDOWN))
                                         ctr=ctr+1; 
            clearmouseclick(WM_LBUTTONDOWN);
                                                              
    }
    
    cleardevice();
    delay(1000);
    //cout<<"see"<<endl<<ctr<<endl; 
    int eff=0;
     
    //eff=ctr/a;
    //cout<<eff<<" % "<<endl;
    settextstyle(1,0,3); 
    outtextxy(2,10,"Congratulations! You have achieved a score of ");
    char str[50],str1[50];
    itoa(ctr,str,10);
    itoa(a,str1,10); setcolor(YELLOW);
    outtextxy(770,10,str); 
    outtextxy(830,10,"out of  ");
    outtextxy(950,10,str1);
    setcolor(WHITE);
    outtextxy(2,50,"The percentage efficiency of your eyes is ");
    eff=(ctr*100)/a;
    //cout<<"see"<<eff<<endl;
    int k;
    if(eff<60)
    k=0;
    char str2[50];
    itoa((int)(eff),str2,10);
    setcolor(YELLOW);
    outtextxy(680,50,str2); outtextxy(740,50,"%");
    setcolor(WHITE);
    if(k==0)
    {             outtextxy(0,300,"Based on the results, we suggest that you meet an opthalmologist.");
                  outtextxy(0,350,"We have BEST IN CLASS doctors!!");
                  outtextxy(0,400,"You can book an appointment with us.");
    }
    else 
          outtextxy(0,300,"Your eyes are healthy");
    
            
    clearmouseclick(WM_LBUTTONDOWN);
    outtextxy(10,500,"Click to go back to the main menu");
    while(1)
    {
            if(ismouseclick(WM_LBUTTONDOWN))
            { break; }
    }
            
    //delay(5000);
    closegraph();
}
ofstream fio;



void addnodenewp(patient *x)
{
     fio.open("PatientList.dat",ios::out | ios::app | ios::binary);
     fio.write((char*)x,sizeof(patient));  
     fio.close(); 
     //cout<<i<<endl;
     /*
     char *str[10];
     str[0]=p.getname();
     puts(str[0]);
     fin.close();
     str[1]=p.getage();
     puts(str[1]); */
}    
void newpatient()
{
     fio.open("PatientList.dat",ios::out | ios::app);
     fio.close();
     char n[10][100];
     temp=new patient;temp->link=NULL;
     outtextxy(1,1,"Enter your details ");
     outtextxy(1,50,"Name:  ");
     outtextxy(1,80,"Gender (m/f):  ");
     outtextxy(1,110,"Age:  ");
     outtextxy(1,140,"Phone No:  ");
     outtextxy(1,170,"Password:  ");
     graphic_gets(n[0],100,50,YELLOW);
     graphic_gets(n[1],265,80,YELLOW,BLACK,1);
     graphic_gets(n[2],80,110,YELLOW,BLACK,3);
     graphic_gets(n[3],180,140,YELLOW,BLACK,10);
     graphic_gets(n[4],180,170,YELLOW,BLACK,10);
     /*for(int i=0;i<4;i++)
     puts(n[i]);*/
     ifstream fin("PatientList.dat",ios::in);
     patient p;
     //fin.seekg(-410,ios::end);
     //int a=sizeof(p); cout<<a<<endl;
     //cout<<sizeof(int)<<endl;
     int k=0;
     while(!fin.eof())
     {
     fin.read((char*)&p,sizeof(p));
     k=k+1;
     }
     fin.close(); cout<<k<<endl;
     temp->allocateid(k);
     temp->put(n[0],n[2],n[1],n[3],n[4]);
     addnodenewp(temp);
     setcolor(WHITE);
     outtextxy(100,200,"Congratulations!! You are now a registered patient with us.");
     int i=temp->getid();
     cout<<i<<endl;
     outtextxy(100,250,"Your Unique ID is ");
     char s[50];
     itoa(i,s,10);
     outtextxy(450,250,s);
     outtextxy(100,450,"Click     to go back to main menu");
     outtextxy(100,500,"Click     to book an appointment with a doctor");
     setbkcolor(BLUE);
     setcolor(YELLOW);
     outtextxy(200,450,"here");
     outtextxy(200,500,"here");
     setbkcolor(BLACK);
     setcolor(WHITE);
     
     
     int x,y;
     while(1)
     {
             if(ismouseclick(WM_LBUTTONDOWN))
             { 
                                             getmouseclick(WM_LBUTTONDOWN,x,y);
                                             break;
             }
     }
     if(x>=200 && y>=500 && x<=280 && y<=530)
     {appointment(temp->getname()); 
     }     
      
     else if(x>=200 && y>=450 && y<=480 && x<=480)
     {
        return;       
     }       
     delete temp;
}

int main()
{
    doctorfile();
    fio.open("PatientList.dat",ios::out | ios::binary | ios::app);
     fio.close();
     fio.open("Appointment.dat",ios::out | ios::binary | ios::app);
     fio.close();
    /*fstream b;
    b.open("PatientList.dat");//,ios::binary | ios::out | std_ios::_noreplace);
    b.close();
    b.open("Doctors list.dat");//,ios::binary | ios::out | ios::noreplace);
    b.close();
    b.open("Appointment.dat");//,ios::binary | ios::out | ios::noreplace);
    b.close();*/
    initwindow(1350,650,"abc");
    readimagefile("dumble2.JPG",500,10,700,200);
    settextstyle(0,0,7);
    setbkcolor(RED);
    setcolor(WHITE);
    outtextxy(125,250,"ABC HEALTH CENTRE");
    setbkcolor(BLACK);
    settextstyle(10,0,4);
    outtextxy(750,400,"Developed by: Manan Gupta");
    outtextxy(1015,450,"Rishabh Jain");
    outtextxy(350,615,"Click to prove you are human"); 
    while(1)
    {
                if(ismouseclick(WM_LBUTTONDOWN) || ismouseclick(WM_RBUTTONDOWN))
                    {cleardevice();  break;}     
    } 
    /*while(kbhit()) getch();
      doctorfile();
       fio.open("PatientList.dat",ios::out | ios::app | ios::binary);
       fio.close();*/
    //char ch='y';
    while(1)
    {
                  
                  setbkcolor(BLACK);
                  settextstyle(10,0,4);
                outtextxy(450,1,"Welcome to ABC Health Centre");
  outtextxy(1,80,"Select the relevant option");
  setbkcolor(BLUE);
  outtextxy(250,300,"PATIENT");
  outtextxy(800,300,"DOCTOR");
  outtextxy(250,500,"EYE CHECK UP - 1");
  outtextxy(800,500,"EYE CHECK UP - 2");
  //outtextxy(400,500,"Eye Check Up");
  int op=0,x,y;
  clearmouseclick(WM_LBUTTONDOWN);
  while(1)
  {
          if(ismouseclick(WM_LBUTTONDOWN))
                                        {  getmouseclick(WM_LBUTTONDOWN,x,y); break; }
  }
  if(x>=250 && x<385 && y>=300 && y<330)
  op=1;
  else if(x>=800 && y>=300 && y<330)
  op=2;
  else if(x>=250 && x<=555 && y>=500 && y<=530)
  op=3;
  else if(x>=800 && x<=1105 && y>=500 && y<=530)
  op=4;
  /*else if(x>=400 && y>500 && y<530)
  op=3;*/
  setbkcolor(RED);
  //cout<<op<<endl<<x<<endl<<y<<endl;  
  if(op==1)
  {
           
           outtextxy(150,400,"New Patient");
           outtextxy(450,400,"Registered Patient");
  }       
  else if(op==2)
  {
       setbkcolor(BLACK);
       cleardevice();
       // while(kbhit()) getch();
      doctorfile();
       while(kbhit()) getch();
                                      selectdoctor();
                                      cleardevice();
  } 
  
  else if(op==3)
  {
       cleardevice(); 
       eyecheckup1();
       initwindow(1360,720);
       
  }
  else if(op==4)
  {
       
       setbkcolor(BLACK);
       cleardevice();
       eyecheckup();
  }
       
  //delay(1000);
  clearmouseclick(WM_LBUTTONDOWN);
   if(op==1)
{
   while(1)
  {  
  if(op==1)
  {
           
        
  while(1)
  {
          if(ismouseclick(WM_LBUTTONDOWN))
          {
                                          getmouseclick(WM_LBUTTONDOWN,x,y); break;
          }
  }
  }
  setbkcolor(BLACK);
  if(x>=150 && x<=360 && y>=400 && y<431)    //Placing a call to the fuction that will create new patient    
  {  cleardevice(); while(kbhit()) getch();  newpatient();  cleardevice();  break; }
  else if(x>=450 && x<=790 && y>=400 && y<431)  //Placing a call to function dealing with registered patient
  {
       cleardevice(); regpatient(); cleardevice(); break;
  }
  }}}
    system("pause");
}
void regpatient()
{
     clearmouseclick(WM_LBUTTONDOWN);
     while(kbhit()) getch();
     outtextxy(1,1,"Enter your ID: ");
     char str[100],str1[100];
     graphic_gets(str,300,1,YELLOW,BLACK,10);
     //puts(str);
     ifstream fin("PatientList.dat",ios::in | ios::binary);
     patient p;
     while(!fin.eof())
     {
                      fin.read((char*)&p,sizeof(p));
                      itoa(p.getid(),str1,10);
                      //cout<<"in"<<endl;
                      if(strcmp(str,str1)==0)
                      break;
     }
     fin.close();
     setcolor(WHITE);
     outtextxy(1,50,"Enter your Password: ");
     char str2[100]; int x,y;
     graphic_gets(str2,400,50,YELLOW,BLACK,10);    
     setcolor(WHITE);
     if(strcmp(str2,p.getpass())==0)
     {
                                    cleardevice();
                                    setcolor(RED);
                                    outtextxy(1,1,"Welcome");
                                    outtextxy(160,1,p.getname());
                                    setcolor(WHITE);
                                    outtextxy(1,50,"     your Profile");
                                    outtextxy(1,100,"     an Appointment");
                                    setbkcolor(BLUE);
                                    setcolor(YELLOW);
                                    outtextxy(1,50,"Edit");
                                    outtextxy(1,100,"Book");
                                    setbkcolor(BLACK);
                                    setcolor(WHITE);
                                    clearmouseclick(WM_LBUTTONDOWN);
                                    while(1)
                                    {
                                    while(1)
                                    {
                                            if(ismouseclick(WM_LBUTTONDOWN))
                                            {getmouseclick(WM_LBUTTONDOWN,x,y); break; }
                                    }
                                    //cout<<x<<endl<<y; 
                                    if(x>=1 && x<=76 && y<=81 && y>=50) //Calling edit function to edit object
                                    {
                                             edit(p); delay(100); break;
                                    }
                                    else if(x>=1 && y>=100 && y<=131 && x<=76)
                                    {
                                         appointment(p.getname()); break;
                                    }         
                                    }      
                                    delay(2000);
                                   
     }
     else
     {
         outtextxy(1,100,"The username or password you entered is wrong"); delay(2000);
     }
}
void edit(patient p)
{
     fstream fio("PatientList.dat",ios::in | ios::out | ios::binary);
     char n[10][100];
     cleardevice();
     outtextxy(1,50,"Name:  ");
     outtextxy(1,80,"Gender (m/f):  ");
     outtextxy(1,110,"Age:  ");
     outtextxy(1,140,"Phone No:  ");
     outtextxy(1,170,"Password:  ");
     graphic_gets(n[0],100,50,YELLOW);
     graphic_gets(n[1],265,80,YELLOW,BLACK,1);
     graphic_gets(n[2],80,110,YELLOW,BLACK,3);
     graphic_gets(n[3],180,140,YELLOW,BLACK,10);
     graphic_gets(n[4],180,170,YELLOW,BLACK,10);
     p.put(n[0],n[2],n[1],n[3],n[4]);
     patient p2; long pos;
     int i=0,k=0;
     i=sizeof(p)-sizeof(k);
     while(!fio.eof())
     {
                      pos=fio.tellg();
                      fio.read((char*)&p2,sizeof(p2));
                      if(p.getid()==p2.getid())
                      {
                                               fio.seekg(pos);
                                               fio.write((char*)&p,sizeof(p));
                                               break;
                      }
     }
     fio.close();
     setcolor(WHITE);
     cleardevice();
     outtextxy(1,1,"Your Profile has been successfully edited");
     delay(2000);     
}

void appointment(char name[100])
{
     cleardevice();
     outtextxy(1,1,"Click on the required Doctor");
     settextstyle(3,0,6);
     setbkcolor(BLUE);
     setcolor(YELLOW);
     outtextxy(10,100,"General Physician");
     outtextxy(10,200,"Paediatrician");
     outtextxy(10,300,"ENT Specialist");
     outtextxy(10,400,"Cardiologist");
     outtextxy(10,500,"Pulmonologist");
     outtextxy(600,100,"Neurologist");
     outtextxy(600,200,"Dentist");
     outtextxy(600,300,"Opthalmologist");
     outtextxy(600,400,"Dermatologist");
     outtextxy(600,500,"Psychiatrist");
     clearmouseclick(WM_LBUTTONDOWN);
     int x,y;
     while(1)
     {     while(1)
     {
             if(ismouseclick(WM_LBUTTONDOWN))
             {
                                              getmouseclick(WM_LBUTTONDOWN,x,y);
                                              break;
             }
     }
     int op;
     //cout<<endl<<x<<endl<<y<<endl;
     
     if(x>=10 && y>=100 && y<=150 && x<=435)
     {op=1; addapp(name,"General Physician"); break; }
     else if(x>=10 && y>=200 && y<=250 && x<=315)
     {op=2; addapp(name,"Paediatrician");  break; }
     else if(x>=10 && y>=300 && y<=350 && x<=350)
     {op=3; addapp(name,"ENT Specialist");  break;}
     else if(x>=10 && y>=400 && y<=450 && x<=280)
     {op=4; addapp(name,"Cardiologist");  break;}
     else if(x>=10 && y>=500 && y<=550 && x<=335)
     {op=5; addapp(name,"Pulmonologist");  break;}
     else if(x>=600 && y>=100 && y<=150 && x<=865)
     {op=6; addapp(name,"Neurologist");  break;}
     else if(x>=600 && y>=200 && y<=250 && x<=765)
     {op=7; addapp(name,"Dentist");  break;}
     else if(x>=600 && y>=300 && y<=350 && x<=945)
     {op=8; addapp(name,"Opthalmologist"); break; }
     else if(x>=600 && y>=400 && y<=450 && x<=920)
     {op=9; addapp(name,"Dermatologist");  break;}
     else if(x>=600 && y>=500 && y<=550 && x<=865)
     {op=10; addapp(name,"Psychiatrist");  break;}
     }
     
     /*switch(op)
     {
               case 1:
                    */
     setbkcolor(BLACK);
     setcolor(WHITE);
     
     
     delay(2000);
}


//ifstream f;
ofstream abc;
void addapp(char name[100],char field[100])
{
     abc.open("Appointment.dat",ios::out | ios::binary | ios::app);
     abc.close();
     setbkcolor(BLACK);
     setcolor(WHITE);
     cleardevice();
     settextstyle(3,0,3);
     outtextxy(1,1,"Enter date (in dd-mm-yy) : ");
     char date[50];
     graphic_gets(date,500,1,YELLOW,BLACK,8);
     /*char dchk[50],dchk2[50],dchk3[50];
     itoa(ltm->tm_year-100,dchk,10);
     itoa(1+ltm->tm_mon,dchk2,10);
     itoa(ltm->tm_mday,dchk3,10);
     strcat(dchk3,"-");
     strcat(dchk3,dchk2);
     strcat(dchk3,"-");
     strcat(dchk3,dchk);
     int check=atoi(dchk);
     int c=atoi(date);
     if(check>c)
     cout<<"valid"<<endl;*/
     int cy,cm,cd,ch,cmin;
     cy=ltm->tm_year-100;
     cm=1+ltm->tm_mon;
     cd=ltm->tm_mday;
     ch=ltm->tm_hour;
     //cout<<"hour"<<endl<<ch<<endl;
     cmin=ltm->tm_min;
     char tocd[50],tocd2[50],tocd3[50];
     tocd[0]=date[0];
     tocd[1]=date[1];
     tocd2[0]=date[3];
     tocd2[1]=date[4];
     tocd3[0]=date[6];
     tocd3[1]=date[7];
     int a,b,c;
     b=atoi(tocd2);
     c=atoi(tocd3);
     a=atoi(tocd);
     int valdat=0;
     //cout<<"kaaa"<<endl<<a<<endl;
     if(cy>c)
     valdat=0;
     //cout<<"invalid"<<endl;
     
     else if(cm>b && cy==c)
     valdat=0;
     //cout<<"invalid m"<<endl;
     else if(cd>a && cm==b && cy==c)
     valdat=0;
     //cout<<"invalid d"<<endl;}
     else
     valdat=1;
     //cout<<"valid"<<endl;
     if(valdat==0)
     {
                  cleardevice();
                  settextstyle(10,0,4);
                  outtextxy(1,1,"Invalid date");
                  delay(1000);
     }
     else
     {
     setbkcolor(BLUE);
     setcolor(YELLOW);
     char dur;
     outtextxy(100,70,"Morning");
     outtextxy(600,70,"Evening");
     int x,y;
     while(1)
     {
             if(ismouseclick(WM_LBUTTONDOWN))
             {
                                             getmouseclick(WM_LBUTTONDOWN,x,y);
                                             break;
             }
     }
     //cout<<"in"<<endl<<x<<endl<<y<<endl;
     if(x>=100 && y>=70 && x<=245 && y<=95)
     dur='m';
     else if(x>=600 && y>=70 && y<=95 && x<=745)
     dur='e';
     //cout<<"in"<<endl<<dur<<endl;
     //t=new patdoc; 
     t.putdnf(date,name,field,dur);
     puts(date);
     ifstream q("Appointment.dat",ios::in);
     q.seekg(0,ios::beg);
     //f1.open("temp.dat",ios::out | ios::binary);
     patdoc pd;
     int htemp=0,mtemp=0;
     //puts(field);
      int i=0;
     //int k=strcmp(pd.getdur(),dur);
     //cout<<"k"<<"\t"<<k<<endl;
     while(!q.eof())
     {
                      //cout<<"see"<<endl;
                      q.read((char*)&pd,sizeof(pd));
                      if(pd.getdur()==dur && (strcmp(pd.getdate(),date)==0) && (strcmp(pd.getdf(),field)==0))
                      {
                                          //cout<<"see2"<<endl;                                       
                                          //f.write((char*)&pd,sizeof(pd));
                                          if(htemp<=pd.gethour())
                                          {         
                                                   htemp=pd.gethour();
                                                   i=i+1;
                                                   
                                                   if(i>=2)
                                                   mtemp=0;                                                        
                                          }  
                                          if(mtemp<=pd.getmin() && htemp==pd.gethour())
                                          {
                                                                
                                                                mtemp=pd.getmin(); 
                                                                //cout<<"xyz"<<endl<<mtemp;
                                          }                                                                                                       
                      }
     }     
     q.close();
     if((htemp==11 && mtemp==40) || (htemp==8 && mtemp==40))
     {
                   setcolor(WHITE);
                   setbkcolor(BLACK);
                   settextstyle(10,0,4);
                   cleardevice();
                   outtextxy(1,1,"Sorry!! No slots available. Try for some other day");
                   delay(100);     
     }
     else
     {
     if(mtemp==40 && mtemp!=0)
     {
                  mtemp=0;
                  htemp=htemp+1;
     }
     else if(htemp==0 && mtemp==0)
     {
          if(dur=='e')
          htemp=4;
          else
          htemp=9;
     }
     else if(mtemp==0 && htemp!=0)
     {
         mtemp=mtemp+20;
     }
     else 
     mtemp=mtemp+20;
     t.puthm(htemp,mtemp);
     //cout<<"time"<<endl<<htemp<<"\t"<<mtemp<<endl;
     //f1.close();  
     cout<<dur<<endl<<htemp<<endl;  
     if(cd==a && (dur=='m' && ((ch>htemp) || (ch==htemp && cmin>=mtemp))) || ((dur=='e' && ((ch-12>htemp) || (ch-12==htemp && cmin>=mtemp)))))
     {
                  settextstyle(10,0,4);
                  setcolor(WHITE);
                  setbkcolor(BLACK);
                  cleardevice();
                  outtextxy(1,1,"Sorry!! Booking not possible at such a short notice.");
                  outtextxy(1,100,"Try for some other day");
                  delay(1000);
     }
     else
     {
     //t=addappdoc(t);
     abc.open("Appointment.dat",ios::app | ios::binary);
     abc.write((char*)&t,sizeof(t));
     abc.close();
     setcolor(WHITE);
     setbkcolor(BLACK);
     cleardevice();
     settextstyle(10,0,4);
     outtextxy(1,1,"Your appointment has been booked for   :");
     char strh[10],strm[100];
     itoa(t.gethour(),strh,10);
     itoa(t.getmin(),strm,10);
     outtextxy(710,1,strh);
     char dn[100]; strcpy(dn,t.getdocname(t));
     //cout<<"HERE"<<endl;
     //puts(dn);
     outtextxy(750,200,dn);
     outtextxy(0,200,"Your appointment has been booked with ");
     if(t.getmin()==0)
     {
                      outtextxy(770,1,strm);
                      outtextxy(800,1,strm);
     }
     else
     outtextxy(770,1,strm);  
     if(t.getdur()=='m')
                      outtextxy(830,1,"am");
     else
     outtextxy(830,1,"pm");
                      
     outtextxy(500,400,"THANK YOU");
     
     //cout<<"timeeeee"<<endl<<t.gethour()<<endl<<t.getmin();
     //delete t;
     delay(100);
     }
     }
     }
} 
/*patdoc addappdoc(patdoc t)
{
     ifstream fin("Doctors list.dat",ios::in | ios::binary);
     doctor d;
     abc.open("Appointment.dat",ios::app | ios::binary);
     while(!fin.eof())
     {
                      fin.read((char*)&d,sizeof(d));
                      if(strcmp(d.getdepartment(),t.getdf())==0)                          
}
*/  
/*
struct tm *localtime(const time_t *time);
This returns a pointer to the tm structure representing local time.
*/  
//About the graphic_gets function
//About the third parameter in itoa function
//while(kbhit()) getch(); what does this do?   it clears keyboard buffer
//Instead of counting patients everytime, use static variable
