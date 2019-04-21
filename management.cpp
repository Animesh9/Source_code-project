//Hotel Management System Code in C++


#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdlib.h>


//********************************************
// THIS CLASS CONTAINS FUNTIONS FOR FOOD
//********************************************


class food
{
private:
    fstream p1;
    int c;
    char ap;
    struct fd

    
    
    {
        char name[55];
        float price;
    } f;
public:
    food()
    {
        c=0;
    }
    void food_menu(void);
    void app_fmenu(void);
    void food_bill();
    void del_all();
};
//*****************************************************
//  FUNCTION FOR DISPLAYING FOOD MENU
//*****************************************************

void food::food_menu(void)
{
    cleardevice();
    setfillstyle(7,1);
    floodfill(0,0,4);
    setfillstyle(7,10);
    bar(17,40,605,420);
    rectangle(17,40,605,420);
    setfillstyle(1,10);
    bar(24,47,598,413);
    rectangle(24,47,598,413);
    p1.close();
    c=0;
    p1.open("food.txt",ios::in|ios::binary);
    outtextxy(30,50,"S.N.       ITEM NAME             PRICE");
    gotoxy(4,5);
    char h[5],pr[15];
    while(p1.read((char*)&f,sizeof(f)))
    {
        c++;
        settextstyle(4,0,1);
        itoa(c,h,10);
        outtextxy(40,60+20*c,h);
        outtextxy(150,60+20*c,f.name);
        itoa(f.price,pr,10);
        outtextxy(390,60+20*c,pr);
    }//END OF WHILE
    p1.close();
    settextstyle(15,0,1);
    outtextxy(30,325,"DO YOU WANT TO ADD AN ITEM - (Y/N)");
    gotoxy(60,20);
    cin>>ap;
    if(ap=='y'||ap=='Y')
    {
        app_fmenu();
        //CALLING APPEND FUNCTION
    }
    else
    {
        if(ap=='n'||ap=='N')
        {
            outtextxy(30,360,"DO YOU WANT TO DELETE ALL  (Y/N)");
            char ch;
            gotoxy(60,23);
            cin>>ch;
            if(ch=='y'||ch=='Y')
            {
                del_all();
                //CALLING DELETE FUNCTION
            }
        }
    }
}


//***************************************
//  FUNCTION TO APPEND IN FOOD MENU
//***************************************

void food::app_fmenu(void)
{
    p1.open("food.txt",ios::app|ios::binary);
    outtextxy(30,360,"ENTER ITEM NAME U WANTTO ADD");
    gotoxy(60,23);
    gets(f.name);
    outtextxy(30,380,"ENTER THE PRICE");
    gotoxy(60,24);
    cin>>f.price;
    p1.write((char*)&f,sizeof(f));
    p1.close();
    getch();
}


//*****************************
//  FUNCTION FOR FOOD BILL
//*****************************

void food::food_bill()
{
    double bill=-1;
    char c_name[20],f_name[20];
    int dt;
    cleardevice();
    setfillstyle(7,1);
    floodfill(0,0,4);
    setfillstyle(7,10);
    bar(17,40,605,420);
    rectangle(17,40,605,420);
    setfillstyle(1,7);
    bar(24,47,598,413);
    rectangle(24,47,598,413);
    setcolor(4);
    settextstyle(7,0,1);
    outtextxy(30,70,"ENTER CUSTOMER NAME ");
    gotoxy(50,6);
    cin>>c_name;
    outtextxy(30,120,"ENTER ITEM NAME TAKEN");
    gotoxy(50,9);
    cin>>f_name;
    outtextxy(30,170,"ENTER THE QUANTITY");
    gotoxy(50,12);
    cin>>dt;
    p1.close();
    p1.open("food.txt",ios::in|ios::binary);
    while(p1.read((char*)&f,sizeof(f)))
    {
        if(strcmp(f.name,f_name)==0)
        {
            bill=dt*f.price;
        }
    }//END OF WHILE
    if(bill==-1)
    {
        setcolor(1);

        for(int i=0; i<=20; i++)
        {
            setcolor(1);
            outtextxy(30,220,"ITEM IS NOT PRESENT");
            delay(100);
            setcolor(WHITE);
            outtextxy(30,220,"ITEM IS NOT PRESENT");
            delay(100);
            //  delay(2500);
        }
    }
    else
    {
        char t[5],b[5];
        setcolor(1);
        itoa(dt,t,10);
        itoa(bill,b,10);
        outtextxy(30,250,"NAME FOOD.NAME      QUANTITY      BILL ");
        setcolor(1);
        settextstyle(4,0,1);
        outtextxy(30,280,c_name);
        outtextxy(140,280,f_name);
        outtextxy(320,280,t);
        outtextxy(445,280,b);
        getch();
    }
}

//************************************
//  FUNCTION TO DELETE FOOD MENU
//******************************
void food::del_all()
{
    remove("food.txt");
    p1.open("food.txt",ios::out);
    p1.close();
    c=0;
}


//END OF CLASS FOOD

//***************************************
// THIS CLASS CONTAINS INFORMATION
//   RELATED TO CUSTOMER
//***************************************


class customer
{
private:
    int q,w;
    fstream f1;
    struct cust
    {
        int c_no;
        char c_name[20];
        char c_add[80];
        int a_date;
        int a_month;
        int a_year;
        int d_date;
        int d_month;
        int d_year;
        int room_no;
        char room_type[25];
    } p;
public:
    food j;

    customer()
    {
        p.c_no=0;
        p.d_date=0;
        p.d_month=0;
    }
  
  
//My name is Devansh Markan and I am one of the Collaborator with Animesh's Project

    //FUNCTION FOR CUSTOMER BILL


     void cust_bill()
    {
        int cho;
        do
        {
            cleardevice();
            f1.close();
            setfillstyle(7,1);
            floodfill(0,0,4);
            setfillstyle(7,10);
            bar(10,70,600,450);
            rectangle(10,70,600,450);
            setfillstyle(1,7);
            bar(17,77,593,443);
            rectangle(17,77,593,443);
            setcolor(5);
            setfillstyle(1,2);
            settextstyle(7,0,1);
            setcolor(9);
            setfillstyle(1,2);
            bar(210,140,410,238);
            rectangle(210,140,410,158);
            rectangle(210,140,410,174);
            rectangle(210,140,410,190);
            rectangle(210,140,410,206);
            rectangle(210,140,410,222);
            rectangle(210,140,410,238);
            setcolor(4);
            settextstyle(1,0,4);
            outtextxy(180,20,"HOTEL BILL");
            line(180,60,383,60);
            setcolor(4);
            settextstyle(1,0,1);
            outtextxy(210,137,"  1.  ROOM BILL");
            outtextxy(210,170,"  2.  FOOD BILL");
            outtextxy(210,200,"  3.  MAIN MENU");
            outtextxy(63,318,"ENTER CHOICE FOR WHICH YOU WANT THE BILL");
            gotoxy(67,21);
            cin>>cho;
            choose(cho);
        }
        while(cho!=3); //END OF WHILE
    }

    void choose(int a)
    {
        switch(a)
        {


        case 1:
        {
            room_bill();
            break;
        }
        case 2:
        {
            j.food_bill();
            break;
        }
        case 3:
            break;
        }
    }




   // FUNCTION FOR ROOM BILL


     void room_bill()
    {
        double bill;
        int days,no,dt,mth;
        cleardevice();
        setfillstyle(7,1);
        floodfill(0,0,4);
        setfillstyle(7,10);
        bar(17,40,605,420);
        rectangle(17,40,605,420);
        setfillstyle(1,7);
        bar(24,47,598,413);
        rectangle(24,47,598,413);
        setcolor(4);
        settextstyle(7,0,1);
        outtextxy(30,70,"ENTER CUSTOMER NO DEPARTING");
        gotoxy(50,6);
        cin>>no;
        outtextxy(30,120,"DATE OF DEPARTURE");
        gotoxy(50,9);
        cin>>dt;
        outtextxy(30,170,"MONTH OF DEPARTURE");
        gotoxy(50,12);
        cin>>mth;
        if(p.a_month>mth)
        {
            bill=0;
        }
        f1.close();
        f1.open("cust.txt",ios::in|ios::binary);
        int c=0;

        while(f1.read((char*)&p,sizeof(p)))
        {
            if(p.c_no==no)
            {  
              
               c++;
                if(p.a_month==mth)
                {
                    days=dt-p.a_date;
                }
                else
                {
                    days=(mth-p.a_month)*30+(dt-p.a_date);
                }
                if(p.room_no<=11)
                {
                    char d[5],m[5],h[5],mt[5],dy[5],bl[5];
                    bill=days*250;
                    setcolor(4);
                    outtextxy(30,270," NAME    ARRIVAL    DEPARTURE    DAYS IN    BILL ");
                    setcolor(1);
                    settextstyle(1,0,1);
                    outtextxy(40,300,p.c_name);
                    itoa(p.a_date,d,10);
                    outtextxy(150,300,d);
                    outtextxy(160,300,"/");
                    itoa(p.a_month,m,10);
                    outtextxy(170,300,m);
                    itoa(dt,h,10);
                    outtextxy(270,300,h);
                    outtextxy(280,300,"/");
                    itoa(mth,mt,10);
                    outtextxy(290,300,mt);
                    itoa(days,dy,10);
                    outtextxy(405,300,dy);
                    itoa(bill,bl,10);
                    outtextxy(515,300,bl);
                }
                else
                {
                    char d[5],m[5],h[5],mt[5],dy[5],bl[5];
                    bill=days*150;
                    setcolor(4);
                    outtextxy(30,270," NAME    ARRIVAL    DEPARTURE    DAYS IN    BILL ");
                    setcolor(1);
                    settextstyle(1,0,1);
                    outtextxy(40,300,p.c_name);
                    itoa(p.a_date,d,10);
                    outtextxy(150,300,d);
                    outtextxy(160,300,"/");
                    itoa(p.a_month,m,10);
                    outtextxy(170,300,m);
                    itoa(dt,h,10);
                    outtextxy(270,300,h);
                    outtextxy(280,300,"/");
                    itoa(mth,mt,10);
                    outtextxy(290,300,mt);
                    itoa(days,dy,10);
                    outtextxy(405,300,dy);
                    itoa(bill,bl,10);
                    outtextxy(510,300,bl);
                }
                f1.close();
                int count=1;
                f1.open("cust.txt",ios::in| ios::binary);
                fstream f2;
                while(f1.read((char*)&p,sizeof(p)))
                {
                    if(p.c_no==no)
                    {
                        continue;
                    }
                    else
                    {
                        f2.open("dup.txt",ios::app|ios::binary);
                        p.c_no=count;
                        f2.write((char*)&p,sizeof(p));
                        count++;
                        f2.close();
                    }
                }//END OF WHILE
                remove("cust.txt");
                rename("dup.txt","cust.txt");
                f1.close();
            }
        }//END OF WHILE
        if(c==0)
        {
            for(int i=0; i<=10; i++)
            {
                settextstyle(1,0,3);
                setcolor(4);
                outtextxy(150,300,"CUSTOMER IS NOT PRESENT");
                delay(100);
                setcolor(WHITE);
                outtextxy(150,300,"CUSTOMER IS NOT PRESENT");
                delay(100);
            }
        }


        getch();
    
    }



     // FUNCTION TO DISPLAY CUSTOMER DETAIL
     


       void cust_detail()
    {
        int c;
        do
        {
            cleardevice();
            setfillstyle(7,1);
            floodfill(0,0,4);
            setfillstyle(7,10);
            bar(50,80,600,470);
            rectangle(50,80,600,470);
            setfillstyle(1,7);
            bar(57,87,593,463);
            rectangle(57,87,593,463);
            setcolor(9);
            setfillstyle(1,2);
            bar(210,140,410,254);
            rectangle(210,140,410,158);
            rectangle(210,140,410,174);
            rectangle(210,140,410,190);
            rectangle(210,140,410,206);
            rectangle(210,140,410,222);
            rectangle(210,140,410,238);
            rectangle(210,140,410,254);
            setcolor(4);
            settextstyle(1,0,4);
            outtextxy(160,20,"CUSTOMER DETAIL ");
            setcolor(14);
            line(163,60,475,60);
            setcolor(4);
            settextstyle(1,0,1);
            outtextxy(225,137,"  CHOICES ARE :-");
            setcolor(4);
            settextstyle(1,0,1);
            outtextxy(210,154," 1. APPEND");
            outtextxy(210,170," 2. MODIFY");
            outtextxy(210,186," 3. DELETE ");
            outtextxy(210,202," 4. DELETE ALL ");
            outtextxy(210,218," 5. DISPLAY ");
            outtextxy(210,234," 6. MAIN MENU");
            setcolor(4);
            settextstyle(7,0,2);
            outtextxy(210,300,"ENTER CHOICE :- ");
            gotoxy(53,20);
            cin>>c;
            switch(c)
            {
            case 1:
            {
                cust_app();
                break;
            }
            case 2:
            {
                cust_mod();
                break;
            }
            case 3:
            {
                cust_del();
                break;
            }
            case 4:
            {
                cust_adel();
                break;
            }
            case 5:
            {
                cust_disp();
                break;
            }
            }
        }
        while(c!=6); //END OF WHILE
  

/**********************************************************************
// FUNCTION TO APPEND CUSTOMER
/********************************************************************

   void cust_app()
   {
     int ten, temp;
     cleardevice();
     f1.open("cust.txt",ios::app|ios::binary);
     f1.seekg(0,ios::end);
     ten=f1.tellg()/sizeof(p);
     p.c_no=ten+1;
     setfillstyle(7,1);
     floodfill(0,0,4);
     setfillstyle(7,10);
     bar(17,50,605,470);
     rectabgle(17,50,605,470);
     setfillstyle(1,7);
     bar(24,57,598,463);
     rectangle(24,57,598,463);
     setcolor(4);
     settextstyle(7,0,1);
     outtextxy(70,30,"NAME");
     gotoxy(50,6);
     cin>>p.c_name;
     outtextxy(30,120,"ADDRESS");
     gotoxy(50,9);
     gets(p.c_add);
     outtextxy(30,170,"DATE OF ARRIVAL");
     gotoxy(50,12);
     cin>>p.a_date;
     outtextxy(30,220,"MONTH OF ARRIVAL");
     gotoxy(50,15);
     cin>>p.a_month;
     outtextxy(30,270,"YEAR OF ARRIVAL");
     gotoxy(50,18);
     cin>>p.a_year;
     p.room_no=ten+1;
     f1.write((char*)&p,sizeof(p));
     f1.close()
   }
 //**********************************************
//  FUNCTION TO DISPLAY CUSTOMER IN HOTEL
//**********************************************

    void cust_disp()
    {
        cleardevice();
        f1.close();
        setfillstyle(7,1);
        floodfill(0,0,4);
        setfillstyle(7,10);
        bar(20,20,620,450);
        rectangle(20,20,620,450);
        setfillstyle(1,7);
        bar(27,27,613,443);
        rectangle(27,27,613,443);
        setcolor(4);
        setfillstyle(1,2);
        settextstyle(7,0,1);
        outtextxy(25,40," CUST NO      NAME     ADDRESS      ROOM.NO     DATE");
        gotoxy(30,3);
        int c=0;
        f1.open("cust.txt",ios::in|ios::binary);
        f1.seekg(0,ios::beg);
        char h[5],pr[5],d[5],m[6];
        while(f1.read((char*)&p,sizeof(p)))
        {
            c++;
            setcolor(1);
            settextstyle(1,0,1);
            itoa(p.c_no,h,10);
            outtextxy(55,50+20*c,h);
            outtextxy(160,50+20*c,p.c_name);
            outtextxy(280,50+20*c,p.c_add);
            itoa(p.room_no,pr,10);
            outtextxy(440,50+20*c,pr);
            itoa(p.a_date,d,10);
            outtextxy(550,50+20*c,d);
            outtextxy(560,50+20*c,"/");
            itoa(p.a_month,m,10);
            outtextxy(570,50+20*c,m);
        }//END OF WHILE
        getch();
        f1.close();
    }
//************************************************
//  FUNCTION FOR MODIFYING CUSTOMER DETAIL
//************************************************

    void cust_mod()
    {
        cleardevice();
        f1.close();
        setfillstyle(7,1);
        floodfill(0,0,4);
        setfillstyle(7,10);
        bar(10,10,600,470);
        rectangle(10,10,600,470);
        setfillstyle(1,7);
        bar(17,17,593,463);
        rectangle(17,17,593,463);
        setcolor(9);
        setfillstyle(1,2);
        setcolor(4);
        int no;//,count=0;
        outtextxy(30,42,"ENTER CUSTOMER NO TO BE MODIFIED");
        gotoxy(65,4);
        cin>>no;
        f1.open("cust.txt",ios::in|ios::binary);






   

              f1.close();
                int num=sizeof(p)*(no-1);
                f1.open("cust.txt",ios::out|ios::ate|ios::binary);
                f1.seekp(num,ios::beg);
                outtextxy(30,110,"ENTER NEW RECORD ");
                outtextxy(30,150,"NAME");
                gotoxy(30,11);
                cin>>p.c_name;
                outtextxy(30,200,"ADDRESS");
                gotoxy(30,14);
                cin>>p.c_add;
                outtextxy(30,250,"DATE");
                gotoxy(30,17);
                cin>>p.a_date;
                outtextxy(30,300,"MONTH");
                gotoxy(30,20);
                cin>>p.a_month;
                outtextxy(30,350,"YEAR");
                gotoxy(30,23);
                cin>>p.a_year;
                f1.write((char*)&p,sizeof(p));
                f1.close();
            }
        }//END OF WHILE
        getch();
    }
//*************************************************
//  FUNCTION TO DELETE ALL CUSTOMER RECORDS
//*************************************************

    void cust_adel()
    {
        remove("cust.txt");
        f1.open("cust.txt",ios::out|ios::binary|ios::in);
        p.c_no=0;
        p.room_no=0;
    }

//**********************************************
//  FUNCTION TO DELETE A CUSTOMER RECORD
//**********************************************

    void cust_del()
    {
        cleardevice();
        f1.close();
        setfillstyle(7,1);
        floodfill(0,0,4);
        setfillstyle(7,10);
        bar(10,10,600,470);
        rectangle(10,10,600,470);
        setfillstyle(1,7);
        bar(17,17,593,463);
        rectangle(17,17,593,463);
        setcolor(9);
        setfillstyle(1,2);
        setcolor(4);
        int no,count=1;
        outtextxy(30,42,"ENTER CUSTOMER NO TO BE DELETED");
        gotoxy(65,4);
        cin>>no;
        f1.open("cust.txt",ios::in|ios::binary);
        fstream f2;
        while(f1.read((char*)&p,sizeof(p)))
        {
            if(p.c_no==no)
            {
                continue;
            }
            else
            {
                f2.open("dup.txt",ios::app|ios::binary);
                p.c_no=count;
                f2.write((char*)&p,sizeof(p));
                count++;
                f2.close();
            }
        }
        remove("cust.txt");
        rename("dup.txt","cust.txt");
        f1.close();
        getch();
    }
};

               