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



    //Aman's part of code


    //  THIS CLASS CONTAINS INFORMATION ABOUT HOTEL
class hotel
{
private:
    fstream f1;

    struct cust
    {
        int c_no;
        char c_name[20];
        char c_add[20];
        int a_date;
        int a_month;
        int a_year;
        int d_date;
        int d_month;
        int d_year;
        int room_no;
        char room_type[25];
    } x;

public:
};

// THIS PART OF CODE IS FOR CLASS CONTROLLING ALL THE CLASSES

class control
{
private:
    int ch;

public:
    hotel h;
    customer cust;
    food d;


//  FUNCTION FOR PASSWORD

    void pass()
    {
        char passw[20];
        for(;;)
        {
            hot_name();
            setcolor(4);
            setfillstyle(7,1);
            floodfill(0,0,4);
            setfillstyle(7,10);
            bar(50,60,600,450);
            rectangle(50,60,600,450);
            setfillstyle(1,7);
            bar(57,67,593,443);
            rectangle(57,67,593,443);
            setcolor(4);
            settextstyle(7,0,1);
            settextstyle(7,0,2) ;
            outtextxy(200,220,"ENTER PASSWORD :-");
            gotoxy(55,15);
            cin>>passw;
            if (strcmp(passw,"a")==0)
            {
                cleardevice();
                break;
            }
            else
            {
                setcolor(4);
                settextstyle(7,0,1);
                for(int i=0; i<=10; i++)
                {
                    setcolor(4);
                    outtextxy(200,320,"ENTER CORRECT  PASSWORD ");
                    delay(100);
                    setcolor(WHITE);
                    outtextxy(200,320,"ENTER CORRECT  PASSWORD ");
                    delay(100);
                    settextstyle(7,0,1);
                    outtextxy(200,340,"PRESS ANY KEY TO  CONTINUE");
                }
                cleardevice();

            }
        }
        do
        {
            ch=mmenu();
            choice(ch);
        }
        while(ch!=5); //END OF WHILE
    }


    // FUNCTION FOR HOTEL NAame
    void hot_name()
    {
        settextstyle(4,0,5);
        setcolor(WHITE);
        outtextxy(200,3,"THE TIME HOTEL");
        line(200,50,440,50);
    }

//  FUNCTION FOR MAIN MENU


    int mmenu()
    {
        cleardevice();
        int c;
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
        bar(210,140,410,238);
        rectangle(210,140,410,158);
        rectangle(210,140,410,174);
        rectangle(210,140,410,190);
        rectangle(210,140,410,206);
        rectangle(210,140,410,222);
        rectangle(210,140,410,238);
        setcolor(WHITE);
        settextstyle(4,0,4);
        outtextxy(160,20,"HOTEL MANAGEMENT SYSTEM");
        setcolor(14);
        line(163,60,515,60);
        setcolor(4);
        settextstyle(1,0,1);
        outtextxy(225,137,"  MAIN MENU");
        outtextxy(210,154," 1. INFORMATION");
        outtextxy(210,170," 2. CUSTOMER DETAIL");
        outtextxy(210,186," 3. FOOD DETAIL ");
        outtextxy(210,202," 4. CUSTOMER BILL ");
        outtextxy(210,218," 5. EXIT ");
        setcolor(4);
        settextstyle(7,0,2);
        outtextxy(210,300,"ENTER CHOICE :- ");
        fflush(stdin);
        gotoxy(53,20);
        cin>>c;
        return c;
    }


    //  FUNCTION for ENDING
    void bye()
    {
        cleardevice();
        setcolor(12);
        settextstyle(1,0,5);
        setbkcolor(BLUE);
        outtextxy(70,150,"THANKS FOR VISITING");
        setcolor(10);
        settextstyle(1,0,8);
        outtextxy(100,250,"PROJECT");
        settextstyle(1,0,3);
        outtextxy(150,450,"SHUTTING DOWN.. . .");
        getch();
        setcolor(12);
        settextstyle(1,0,5);
        outtextxy(70,150,"THANKS FOR VISITING");
        setcolor(10);
        settextstyle(1,0,8);
        outtextxy(100,250,"PROJECT");
        settextstyle(1,0,3);
        outtextxy(150,450,"SHUTTING DOWN.. . .");

        for(int i=0; i<=10; i++)
        {
            sound(1000*i);
            setbkcolor(i);
            nosound();
        }
    }

//  FUNCTION OF CHOICE FOR INFORMATION

    void choice(int a)
    {
        switch(a)
        {
        case 1:
        {
            information();
            break;
        }
        case 2:
        {
            cust.cust_detail();
            break;
        }
        case 3:
        {
            d.food_menu();
            break;
        }
        case 4:
        {
            cust.cust_bill();
            break;
        }

        }
    }

//  FUNCTION FOR INFORMATION

    void information()
    {
        cleardevice();
        setfillstyle(7,1);
        floodfill(0,0,4);
        setfillstyle(7,10);
        bar(17,50,605,470);
        rectangle(17,50,605,470);
        setfillstyle(1,7);
        bar(24,57,598,463);
        rectangle(24,57,598,463);
        gotoxy(6,4);
        setcolor(4);
        getch();
    }
};

