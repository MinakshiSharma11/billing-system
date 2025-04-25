#include <iostream>
#include <fstream>
using namespace std;

class shopping
{
    private:
    int pcode;
    float price;
    float discount;
    string pname;

    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();

};
void shopping :: menu()
{
    m:
    int choice;
    string username;
    string password;

    cout<<"\t\t\t\t_____________________________________________\n";
    cout<<"\t\t\t\t            Supermarket Main Menu            \n";
    cout<<"\t\t\t\t_____________________________________________\n";
    cout<<"\t\t\t\t                                             \n";
    cout<<"\t\t\t\t|     1) Administrator     |\n";
    cout<<"\t\t\t\t                           |\n";
    cout<<"\t\t\t\t|     2) Buyer             |\n";
    cout<<"\t\t\t\t                           |\n";
    cout<<"\t\t\t\t|     3) Exit              |\n";
    cout<<"\t\t\t\t Please select !";
    cin>> choice;

    switch (choice)
    {
    case 1:
        cout<<"\t\t\t Please Login \n";
        cout<<"\t\t\t Enter Username: \n";
        cin>>username;
        cout<<"\t\t\t Enter Password: \n";
        cin>>password;
        if( username=="annu@mail.com" && password=="Annu@22")
        {
            administrator();
        }
        else
        {
            cout<<"Invalid username/password";
        }
        break;
    
    case 2:
        {
            buyer();
        }
    case 3:
        {
        	cout<<"THANKYOU Come again !";
            exit(0);
        }
    default:
        {
            cout<<"Please select from the given option";
        }
       
    }
    goto m;
}
void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|_______1.) Add the Product________|";
    cout<<"\n\t\t\t|                                  |";
    cout<<"\n\t\t\t|_______2.) Modify the Product_____|";
    cout<<"\n\t\t\t|                                  |";
    cout<<"\n\t\t\t|_______3.) Delete the Product_____|";
    cout<<"\n\t\t\t|                                  |";
    cout<<"\n\t\t\t|_______4.) Back to the main menu__|";

    cout<<"\n\n\t Please enter your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout<<"Invalid choice";
    }
goto m;
}
void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t    Buyer \n";
    cout<<"\t\t\t_______________\n";
    cout<<"                     \n";
    cout<<"\t\t\t 1) Buy Product\n";
    cout<<"                     \n";
    cout<<"\t\t\t 2) Go Back    \n";
    cout<<"\t\t\t Enter your choice : ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();

    default:
        cout<<"Invalid Choice";
    }
goto m;
}
void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code of the product: ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product: ";
    cin>>pname;
    cout<<"\n\n\t Price of product(Rs): ";
    cin>>price;
    cout<<"\n\n\t Discount on product(%): ";
    cin>>discount;

    data.open("database.txt", ios::in);
    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<discount<<"\n";
        data.close();
    }else{
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
            token++;
            data>>c>>n>>p>>d;
        }
        data.close();
    
   if(token==1)
   goto m;
   else{
    data.open("database.txt",ios::app|ios::out);
    data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<discount<<"\n";
    data.close();
   }
}

   cout<<"\n\n\t\t Record inserted !";
 
}
void shopping::edit()
{
    m:
    fstream data,data1;
    int pkey,token=0,c;
    float p,d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code :";
    cin>>pkey;

    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\n\n File doesn't exist! ";
    }else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;
       
        while(!data.eof())
        {
            if(pkey == pcode)
           {
              cout<<"\n\t\t Product new code :";
              cin>>c;
              cout<<"\n\t\t Name of the product :";
              cin>>n;
              cout<<"\n\t\t Price :";
              cin>>p;
              cout<<"\n\t\t Discount (%) :";
              cin>>d;
              data1<<"  "<<c<<"  "<<n<<"  "<<p<<"  "<<d<<"\n";
              cout<<"\n\n\t\t Record edited ";
              token++;
           }
           else{
            data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<discount<<"\n";
           }
           data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        cout<<"\n\n Record not found sorry!";
    }
   
}
void shopping::rem()
{
    fstream data,data1;
    int pkey,token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code : ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    cout<<"File doesn't exist ";
    else{
         data1.open("database1.txt",ios::app|ios::out);
         data>>pcode>>pname>>price>>discount;
         while(!data.eof())
         {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted succesfully";
                token++;
            }
            else{
                data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<discount<<"\n";
            }
            data>>pcode>>pname>>price>>discount;
         }
         data.close();
         data1.close();
         remove("database.txt");
         rename("database1.txt","database.txt");
         if(token==0)
         cout<<"\n\n Record not fount";
    }
}
void shopping::list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|__________________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|__________________________________________________\n";
    data>>pcode>>pname>>price>>discount;
    while(!data.eof())
{
    cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
    data>>pcode>>pname>>price>>discount;
}
data.close();
}
void shopping::receipt()
{
    fstream data;
    int arrc[100],arrq[100],c=0;
    char choice;
    float amount=0,total=0,discount=0;

    cout<<"\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data)
    {
       cout<<"\n\n Empty database "; 
    }
    else{
        data.close();

        list();
        cout<<"\n___________________________________________\n";
        cout<<"\n|                                          \n";
        cout<<"\n          Please place the order           \n";
        cout<<"\n|                                          \n";
        cout<<"\n___________________________________________\n";
        do{
            m:
            cout<<"\n\n Enter product code : ";
            cin>>arrc[c];
            cout<<"\n\n Enter the product quantity : ";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code.Please try again !";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? if yes then press y else no";
            cin>>choice;
        }
        while(choice=='y');

        cout<<"\n\n\t\t\t_________________RECEIPT________________\n";
        cout<<"\n Product No \t Pro name \t Pro quantity \t price \t Amount \t Amount with discount\n";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>discount;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    discount=amount-(amount*discount/100);
                    total=total+discount;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<discount;
                }
                data>>pcode>>pname>>price>>discount;
            }
            data.close();
        }
        
    }
        cout<<"\n\n__________________________________________________";
        cout<<"\n Total Amount : "<<total;
}
int main()
{
    shopping s;
    s.menu();
}
