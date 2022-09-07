#include<iostream>
#include<malloc.h>
#include<conio.h>
#include<windows.h>
#include<graphics.h> //for delay() and playsound()
#include<MMsystem.h>//for playsound()
#include<string.h>
using namespace std;
struct student
{
    string name;
    char regno[9];             //necessary details of the student
    char DOB[10];
    float gpa[8];
    int credpersem[8];
    string programtype;
    int semester;
    int credcomp;
    int curcred;
    float cgpa;
    char residence[7];
    struct courses *h,*t;
    struct student *nt;
}*head=NULL,*tail=NULL;
struct courses
{
    char code[8];
    char components[12];  //details of each and every course
    int cred;               //registered by each student
    int sem;
    char grade;
    struct courses *next;
};
void updatedetails();
struct student* addstudent();
struct student* searchbyname(struct student*);
struct student* searchbyregno(struct student *h);
void deleterec(struct student*);
struct courses* courselist(struct courses*,struct student*);
void insertstudent(struct student*);
void displaydetails(struct student*);
void addcourse(struct student*);
void updatecourselist(struct student*);
void computeother(struct student*);
int main()
{

    PlaySound(TEXT("mbgm.wav"),GetModuleHandle(NULL),SND_FILENAME|SND_ASYNC|SND_LOOP);
    cout<<"                                         **************************************************************************************\n";
    cout<<"                                         **************************************************************************************\n";
    cout<<"                                         **************************************************************************************\n";
    cout<<"                                                          ----  -----  |   |  --*      -----  |\\      |  -----\n";
    cout<<"                                                         |        |    |   |  |   \\    |      | \\     |    |\n";
    cout<<"                                                         |        |    |   |  |    |   |      |  \\    |    |\n";
    cout<<"                                                          ---     |    |   |  |    |   |--    |   \\   |    |\n";
    cout<<"                                                             |    |    |   |  |    |   |      |    \\  |    |\n";
    cout<<"                                                             |    |    |   |  |   /    |      |     \\ |    |\n";
    cout<<"                                                         ----     |     ---   --*      -----  |      \\|    |\n";
    cout<<endl;
    cout<<"                                            --*         /\\       -----      /\\        --          /\\          ----  -----\n";
    cout<<"                                            |   \\      /  \\        |       /  \\       |  \\       /  \\        |      |\n";
    cout<<"                                            |    |    /    \\       |      /    \\      |   |     /    \\       |      |\n";
    cout<<"                                            |    |   /      \\      |     /      \\     |--/     /      \\        ---  |--\n";
    cout<<"                                            |    |  / ------ \\     |    / ------ \\    |  \\    / ------ \\          | |\n";
    cout<<"                                            |   /  /          \\    |   /          \\   |   |  /          \\         | |\n";
    cout<<"                                            --*   /            \\   |  /            \\  -- /  /            \\   ----   -----\n";
    cout<<endl;
    cout<<"                            |\\       /|       /\\       |\\      |       /\\        -----      ----- |\\      /|  ----- |\\      | -----\n";
    cout<<"                            | \\     / |      /  \\      | \\     |      /  \\      /          |      | \\    / | |      | \\     |   |\n";
    cout<<"                            |  \\   /  |     /    \\     |  \\    |     /    \\     |          |      |  \\  /  | |      |  \\    |   |\n";
    cout<<"                            |   \\ /   |    /      \\    |   \\   |    /      \\    |      --  |--    |   \\/   | |--    |   \\   |   |\n";
    cout<<"                            |         |   / ------ \\   |    \\  |   / ------ \\   |     |  | |      |        | |      |    \\  |   |\n";
    cout<<"                            |         |  /          \\  |     \\ |  /          \\  \\     |    |      |        | |      |     \\ |   |\n";
    cout<<"                            |         | /            \\ |      \\| /            \\  -----      ----- |        |  ----- |      \\|   |\n";
    cout<<endl;
    cout<<"                                                         ----  \\       /   ----  -----  -----  |\\      /|\n";
    cout<<"                                                        |       \\     /   |        |    |      | \\    / |\n";
    cout<<"                                                        |        \\   /    |        |    |      |  \\  /  |\n";
    cout<<"                                                         ---      \\ /      ---     |    |--    |   \\/   |\n";
    cout<<"                                                            |      |          |    |    |      |        |\n";
    cout<<"                                                            |      |          |    |    |      |        |\n";
    cout<<"                                                        ----       |      ----     |    -----  |        |\n";
    cout<<endl;
    cout<<"                                         **************************************************************************************\n";
    cout<<"                                         **************************************************************************************\n";
    cout<<"                                         **************************************************************************************\n\n\n";

   cout<<"                                                                          PROJECT WORKED OUT BY:                  \n\n";
   cout<<"Name:                                     ARJUNADITYA                         KHUSHEE JAIN                   GAURAV GOVERDHAN       \n";
   cout<<"Registeration Number:                      19BCI0047                           19BCE0914                        19BCB0098              \n";
   int gd=DETECT,gm;;
   initgraph(&gd,&gm,"C:\\TC\\BGI");
   readimagefile("sdms.jpg",50,100,600,400);
   getch();
   closegraph();
   int i=0;
   system("pause");
   cout<<"Please Wait ";
while(i<4)
{
    i++;
    cout<<". ";
    delay(1000);

}
   int ask=1,choice;
while(ask)
{
    system("CLS");
cout<<"Enter 1 to Insert Student"<<endl<<"Enter 2 to Delete Student"<<endl<<"Enter 3 to Search Student"<<endl<<"Enter 4 to Update Student Record"<<endl;
cout<<"Enter 5 to Display Student"<<endl<<"Enter -1 to exit: ";
cin>>choice;
 if(choice==1)
    insertstudent(addstudent());
else if(choice==2)
    deleterec(head);
else if(choice==3)
{
    system("CLS");
    int n;
    cout<<"Enter 1 to search by name\n"<<"Enter 2 to search by Registration Number: ";
    cin>>n;
    if(n==1)
        searchbyname(head);
    else
    {
        struct student *s=searchbyregno(head);
        if(s!=NULL)
        {   char c;
            cout<<"Do you want the details? :Y/N ";
            cin>>c;
            if(c=='Y')
                displaydetails(s);}
    }
}
else if(choice==4)
{
   updatedetails();
}
else if(choice==5)
{
    system("CLS");
    struct student *s=searchbyregno(head);
    if(s!=NULL)
        displaydetails(s);
}
else if(choice==-1)
    ask=0;
else
{
     cout<<endl<<"Please enter a valid choice!\n ";
            system("pause");
}
}


}
struct student* addstudent()
{
    system("CLS");
    struct student *n=new struct student,*t;
    struct courses *temp;
    cout<<"Welcome to Vellore Institute Of Technology\n";
    cout<<"Please Enter your name: ";
    cin.ignore();
    getline(cin,n->name);
    cout<<"Enter the date of birth in DD-MM-YYYY Format: ";
    cin>>n->DOB;
    cout<<"Enter your 9-Digit Registration Number in format 15XYZ0001: ";
    cin>>n->regno;
    int f;
    while(1)
    {
    f=1;
    t=head;
    if(strlen(n->regno)!=9)
        {
        cout<<endl<<"Incorrect Format!\nEnter again: ";
            cin>>n->regno;
            f=0;
        }
    while(t!=NULL)
    {
        if(strcmp(t->regno,n->regno)==0)
        {
            cout<<endl<<"This Registeration number is already Present\nEnter again: ";
            cin>>n->regno;
            f=0;
            break;
        }
        t=t->nt;
    }
    if(f==1)
    break;}
    n->semester=1;
    n->credcomp=0;
    cout<<"Enter Programme Type: ";
    cin>>n->programtype;
    cout<<"Enter residence in Block-room format: ";
    cin>>n->residence;
    n->h=NULL;
    n->t=NULL;
    n->nt=NULL;
    n->h=courselist(n->h,n);
    temp=n->h;
    while(temp->next!=NULL)
    temp=temp->next;
    n->t=temp;
    system("pause");
    return n;
}
struct courses* courselist(struct courses *h,struct student* H)
{
    system("CLS");
    int num;
    cout<<"How many courses have you registered for in this semester ?: ";
    cin>>num;
    cout<<"NOTE:"<<endl;
    cout<<""<<"For example, if it has theory and lab , enter ELA+ETH\n"<<"If it has only labs, enter LO\n";
    H->curcred=0;
    for(int i=0;i<num;i++)
    {
        struct courses *nw=new struct courses,*t;
        cout<<"Enter the course code for course "<<i+1<<" : ";
        cin>>nw->code;
        int f;
    while(1)
    {
    f=1;
    t=h;
    while(t!=NULL)
    {
        if(strcmp(t->code,nw->code)==0)
        {
            cout<<"This course has already been taken\nEnter again: ";
            cin>>nw->code;
            f=0;
            break;
        }
        t=t->next;
    }
    if(f==1)
        break;
    }
        cout<<"Enter the Components: ";
        cin>>nw->components;
        cout<<"Enter credits: ";
        cin>>nw->cred;
        H->curcred=H->curcred+nw->cred;
        cout<<"Semester: "<<H->semester<<endl<<endl;
        nw->sem=H->semester;
        nw->grade='\0';
        nw->next=NULL;
        if(h==NULL)
            h=nw;
        else
        {
            struct courses *temp=h;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=nw;
        }

    }
    return h;

}
struct student* searchbyregno(struct student *h)
{
    system("CLS");
    char rno[10];
    cout<<"Enter the registration number: ";
    cin>>rno;
    struct student* temp=h;
    while(temp!=NULL){
        if(strcmp(temp->regno,rno)==0)
            {cout<<"record found"<<endl;
            return temp;}
            temp=temp->nt;
        }
        cout<<"Record Not Found\n";
        system("pause");
        return NULL;
};
struct student* searchbyname(struct student *h)
{
    system("CLS");
    string n;
    int c=0,ask;
    cout<<"Enter the name: ";
    cin.ignore();
    getline(cin,n);
    struct student* temp=h,*f=NULL,*l=NULL;
    while(temp!=NULL){
        if(temp->name==n)
        {
        c++;
        if(c==1)
            f=l=temp;
        l=temp;
        }
        temp=temp->nt;
        }
        if(c==0)
        {cout<<"NO record found!!\n";
        system("pause");}
        else if(c==1)
            displaydetails(f);
        else
        {
            cout<<"More than one records are found !\n";
            cout<<"Enter 1 to print them all\n";
            cout<<"Enter 2 to try searching by registration number instead: ";
            cin>>ask;
            if(ask==1)
            {
            temp=f;
            while(temp!=l->nt){
           if(temp->name==n)
            displaydetails(temp);
            temp=temp->nt;}
            }
            else
                {temp=searchbyregno(h);
                displaydetails(temp);
                }
        }
};
void displaydetails(struct student *s)
{
system("CLS");
    cout<<"Name: "<<s->name<<endl;
    cout<<"Registration Number: "<<s->regno<<endl;
    cout<<"Date Of Birth: "<<s->DOB<<endl;
    cout<<"Program Type: "<<s->programtype<<endl;
    cout<<"Semester: "<<s->semester<<endl;
    cout<<"Credits Completed: "<<s->credcomp<<endl;
    cout<<"Credits In this Semester: "<<s->curcred<<endl;
    if(s->semester==1&&(s->h->grade=='\0'))
        cout<<"CGPA will be calculated after first semester\n";
    else
        cout<<"CGPA: "<<s->cgpa<<endl;
    cout<<"Current residence: "<<s->residence<<endl;
    cout<<"Courses opted:           Components:            Semester:            Credits:"<<endl;
    struct courses *temp;
    temp=s->h;
    while(temp!=NULL)
    {
        cout<<temp->code<<"                    "<<temp->components<<"                    "<<temp->sem<<"                   "<<temp->cred<<endl;
        temp=temp->next;
    }
    system("pause");
}
void insertstudent(struct student *nw)
{
    if(head==NULL)
        {head=nw;
        tail=nw;}
    else
    {
        tail->nt=nw;
        tail=nw;
    }
};
void deleterec(struct student *h)
{
    if(head!=NULL)
    {
    struct student *rec=searchbyregno(h);
    if(rec!=NULL)
    {
        struct student *temp=h;
        if(temp==rec)
        {
            head=head->nt;
            delete temp;
            cout<<endl<<"Record Deleted !\n";
        system("pause");
        }
        else{
        while(temp->nt!=rec)
            temp=temp->nt;
        temp->nt=rec->nt;
        delete (rec);
        cout<<endl<<"Record Deleted !\n";
        system("pause");}
    }
}
else
{
    cout<<endl<<"No records now!!\n";
    system("pause");
    return;
}
}
void updatedetails()
{
    system("CLS");
    struct student *s=searchbyregno(head);
    if(s!=NULL)
    {cout<<"Name: "<<s->name<<endl;
    int choice;
    cout<<"Enter 1 to Update Semester\nEnter 2 to Update residence\nEnter 3 to save grades for current semester\nEnter 4 to update course list for current semester: ";
    cin>>choice;
    switch (choice)
    {
    case 1 :
        {
            struct courses* t=s->h;
            while(t!=NULL)
            {
                if(t->sem==s->semester)
                    break;
                else
                    t=t->next;
            }
            if(t->grade=='\0')
            {
            cout<<endl<<"Please update grades of current courses before updating the semester?\n";
            while(t!=NULL&&(t->sem==s->semester))
            {
                cout<<endl<<"Enter grade for course code "<<t->code<<" : ";
                cin>>t->grade;
                s->credcomp=s->credcomp+t->cred;
                t=t->next;
            }
            computeother(s);}
            cout<<endl<<"Semester Updated !\n";
            s->semester++ ;
            cout<<"Would you like to add courses for the new semester ? (y/n) : ";
            char i;
            cin>>i;
            if(i=='y')
                addcourse(s);
            break;
        }
    case 2:
        {
        cout<<endl<<"Enter residence in Block-room format: ";
        cin>>s->residence;
        break;
        }
    case 3:
        {
            struct courses* t=s->h;
            while(t!=NULL)
            {
                if(t->sem==s->semester)
                    break;
                else
                    t=t->next;
            }
            char c='y';
                if(t!=NULL&&t->grade!='\0')
                {cout<<endl<<"The Grades have already been awarded, Do you want to overwrite the Grades? (y/n): ";
                cin>>c;}
                if(t==NULL)
            {
                cout<<"No Courses Registered for semester "<<s->semester<<endl;
                system("pause");
            }
            while(t!=NULL&&t->sem==s->semester)
            {
                if(c=='y')
                {cout<<endl<<"Enter grade for course code "<<t->code<<" : ";
                if(t->grade=='\0')
                s->credcomp=s->credcomp+t->cred;
                cin>>t->grade;

                t=t->next;}
                else
                    break;
            }
            if(c=='y')
            computeother(s);
            break;
        }
    case 4:
        {
            updatecourselist(s);
            break;
        }
    default:
        {
            cout<<endl<<"Please enter a valid choice!\n ";
            system("pause");
            break;

        }

    }
}
}
void updatecourselist(struct student *s)
{
    system("CLS");
cout<<"Enter 1 to add courses for the current semester\nEnter 2 to delete course in the current semester: ";
int c;
cin>>c;
switch(c)
    {
case 1:
    {
        if((s->t->grade=='\0')||((s->t->grade!='\0')&&(s->t->sem!=s->semester)))
    {system("CLS");
    int num;
    cout<<"How many courses would you like to add?: ";
    cin>>num;
    cout<<"NOTE:"<<endl;
    if(s->t->grade!='\0')
        s->curcred=0;
    cout<<""<<"For example, if it has theory and lab , enter ELA+ETH\n"<<"If it has only labs, enter LO\n";
    for(int i=0;i<num;i++)
    {
        struct courses *nw=new struct courses,*t;
        cout<<"Enter the course code for course "<<i+1<<" : ";
        cin>>nw->code;
        int f;
    while(1)
    {
    f=1;
    t=s->h;
    while(t!=NULL)
    {
        if(strcmp(t->code,nw->code)==0)
        {
            cout<<"This course has already been taken!\n\nEnter again: ";
            cin>>nw->code;
            f=0;
            break;
        }
        t=t->next;
    }
    if(f==1)
        break;
    }
        cout<<"Enter the Components: ";
        cin>>nw->components;
        cout<<"Enter credits: ";
        cin>>nw->cred;
        s->curcred=s->curcred+nw->cred;
        nw->sem=s->semester;
        cout<<"Semester: "<<s->semester<<endl<<endl;
        nw->grade='\0';
        nw->next=NULL;
        if(s->h==NULL)
            s->h=s->t=nw;
        else
        {s->t->next=nw;
         s->t=nw;
        }
    }
    cout<<endl<<endl<<"Courses added Successfully!\n";
    system("pause");
    }
    else
    {
        cout<<endl;
        cout<<"Please Update the semester as the grades of the courses of the  previous semester have already been evaluated\n ";
        system("pause");
    }
    break;
    }
case 2:
        {
            system("CLS");
            string cc;
            cout<<"Enter the course code: ";
            cin>>cc;
            struct courses *t=s->h;
            if(t!=NULL&&t->grade=='\0')
                {struct courses *p;
                if(s->h->code==cc)
                {
                    p=s->h;
                    s->h=s->h->next;
                    s->curcred=s->curcred-p->cred;
                    delete(p);
                    cout<<"Course Deleted Succesfully!\n";
                    system("pause");
                    return;
                }
                }
                else if(t==NULL)
                {
                cout<<"Oops! The courselist is Empty!\n ";
                system("pause");
                return;
                }
                else if(t->grade!='\0')
                {
                    cout<<"Sorry,the course has already been graded and cannot be deleted\n";
                    system("pause");
                    return;
                }
            while(t!=NULL)
            {
                if((t->next!=NULL&&t->next->code==cc))
                    break;
                else
                    t=t->next;
            }
            cout<<endl;
            if(t==NULL)
                {cout<<"Course not found !\n";
                system("pause");}
            else
            {
                if(t->next->grade=='\0')
                {struct courses *p;
                    p=t->next;
                    t->next=p->next;
                    if(p==s->t)
                        s->t=t;
                    s->curcred=s->curcred-p->cred;
                    delete(p);
                    cout<<"Course Deleted Succesfully!\n";
                    system("pause");
                }
                else
                {
                    cout<<"Sorry,the course has already been graded and cannot be deleted\n";
                    system("pause");
                }
                }

            break;}

default:
    {
      cout<<endl<<"Please enter a valid choice!\n "<<endl;
            system("pause");
            break;
    }
}
}
void addcourse(struct student *s)
{
    system("CLS");
    int num;
    cout<<"How many courses would you like to add?: ";
    cin>>num;
    cout<<"NOTE:"<<endl;
    cout<<"For example, if it has theory and lab , enter ELA+ETH\n"<<"If it has only labs, enter LO\n";
    s->curcred=0;
    for(int i=0;i<num;i++)
    {
        struct courses *nw=new struct courses,*t;
        cout<<"Enter the course code for course "<<i+1<<" : ";
        cin>>nw->code;
         int f;
    while(1)
    {
    f=1;
    t=s->h;
    while(t!=NULL)
    {
        if(strcmp(t->code,nw->code)==0)
        {
            cout<<"This course has already been taken!\n\nEnter again: ";
            cin>>nw->code;
            f=0;
            break;
        }
        t=t->next;
    }
    if(f==1)
        break;
    }
        cout<<"Enter the Components: ";
        cin>>nw->components;
        cout<<"Enter credits: ";
        cin>>nw->cred;
        s->curcred=s->curcred+nw->cred;
        cout<<"Semester: "<<s->semester<<endl<<endl;
        nw->sem=s->semester;
        nw->grade='\0';
        nw->next=NULL;
        if(s->h==NULL)
            s->h=s->t=nw;
        else
        {s->t->next=nw;
         s->t=nw;
        }
    }
    system("pause");
}
void computeother(struct student *s)
{
int st=s->semester;
struct courses *temp=s->h;
float g=0;
while(temp!=NULL&&temp->sem<=st)
{
    if(temp->sem==st)
    {
        switch(temp->grade)
        {
        case 'S':
            {g=g+temp->cred*10;
                break;}
        case 'A':
            {g=g+temp->cred*9;
                break;}
        case 'B':
            {g=g+temp->cred*8;
                break;}
        case 'C':
            {g=g+temp->cred*7;
                break;}
        case 'D':
            {g=g+temp->cred*6;
                break;}
        case 'E':
            {g=g+temp->cred*5;
                break;}
        case 'F':
            {break;}
        case 'N':
            {
                cout<<s->name<<" failed to appear for the examination for course "<<temp->code<<" and hence cannot be evaluated!\n";
                break;
            }
        }
    }
    temp=temp->next;
}
g=g/s->curcred;
s->credpersem[st-1]=s->curcred;
s->gpa[st-1]=g;
s->cgpa=0;
for(int i=0;i<st;i++)
    s->cgpa=s->cgpa+(s->gpa[i])*(s->credpersem[i]);
s->cgpa=s->cgpa/s->credcomp;
}

