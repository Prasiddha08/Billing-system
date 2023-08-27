#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
	private:
		int pcode;
		float price;
		float dis;
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
			void createAdministrator();
            void authenticateAdministrator();
            bool isUsernameTaken(const string& username);

};

void shopping :: menu()
{
	m:
	int choice;
	string username;
	string password;

	cout<<"\t\t\t\t______________________________________\n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t          Supermarket Main Menu       \n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t______________________________________\n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t|  1) Administrator   |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\t\t\t\t|  2) Buyer           |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\t\t\t\t|  3) Exit            |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\n\t\t\t Please select your choice : ";
	cin>>choice;

	switch(choice)
	{
		case 1:
		    system("cls");
		    int c;
		    cout<<"\n\t\t\t| 1)Signup \n\n";
		    cout<<"\t\t\t| 2)Login \n\n";
		    cout<<"\t\t\t| 3)Back to Main Menu\n ";
            cout<<"\t\t\t Enter your choice : ";
            cin>>c;
            switch(c)
            {
            case 1:
                system("cls");
                createAdministrator();
                break;
            case 2:
                system("cls");
                authenticateAdministrator();
                break;
            case 3:
                system("cls");
                menu();
            default:
                cout<<"Enter valid choice in valid format";

            }
			break;

	case 2:
		{
			buyer();

		}

	case 3:
		{
			exit(0);
		}

		default :
			{
				cout<< "Please select from the given options";

			}


}
goto m;

}

void shopping:: administrator()
{
    system("cls");
	m:
	int choice;
	cout<<"\n\n\n\t\t\t\t Administrator menu";
	cout<<"\n\t\t\t\t|_____1) Add the product_____|";
	cout<<"\n\t\t\t\t|                            |";
	cout<<"\n\t\t\t\t|_____2) Modify the product__|";
	cout<<"\n\t\t\t\t|                            |";
	cout<<"\n\t\t\t\t|_____3) Delete the product__|";
    cout<<"\n\t\t\t\t|                            |";
    cout<<"\n\t\t\t\t|_____4) Back to main menu___|";
    cout<<"\n\n\t\t\t Please enter your choice : ";
    cin>>choice;
    switch(choice)
    {
    	case 1:
    	    system("cls");
    		add();
    		break;
    	case 2:
    	    system("cls");
    		edit();
    		break;
    	case 3:
    	    system("cls");
    		rem();
    		break;
    	case 4:
    	    system("cls");
    		menu();
    		break;
    	default :
    		cout<<"Invalid choice!";
	}
	goto m;
}

void shopping:: buyer()
{
    system("cls");
	int choice;
	cout<<"\t\t\t  Buyer \n";
	cout<<"\t\t\t_____________  \n";
	cout<<"                     \n";
	cout<<"\t\t\t1) Buy product \n";
	cout<<"                     \n";
	cout<<"\t\t\t2) Go back     \n";
	cout<<"\t\t\t Enter your choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2:
		    system("cls");
			menu();
		default :
			cout<<"invalid choice";
	}
	menu();
}

void shopping ::add()
{
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	cout<<"\n\n\t\t\t Add new product";
	cout<<"\n\n\t Product code of the product ";
	cin>>pcode;
	cout<<"\n\n\t Name of the product : ";
	cin>>pname;
	cout<<"\n\n\t Price of the product : ";
	cin>>price;
	cout<<"\n\n\t Discount on product : ";
	cin>>dis;
	data.open("database.txt",ios::in);
	if(!data)
	{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;
		while(!data.eof())
		{
			if(c ==pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	if(token==1)
	 goto m;
	else{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
}
	system("cls");
	cout<<"\n\n\t\t Record inserted !";
}

void shopping ::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	list();
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Product code :";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\nFile doesn't exist! ";
	}
	else{

		data1.open("database1.txt", ios::app|ios::out);

		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t Product new code :";
				cin>>c;
				cout<<"\n\t\t Name of the product :";
				cin>>n;
				cout<<"\n\t\t Price :";
				cin>>p;
				cout<<"\n\t\t Discount :";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				system("cls");
				cout<<"\n\n\t\t Record edited ";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0)
		{
		    system("cls");
			cout<<"\n\n Record not found sorry!";
		}
	}
}

void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	list();
	cout<<"\n\n\t Delete product";
	cout<<"\n\n\t Product code :";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"File doesnt exist";

	}

	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
			    system("cls");
				cout<<"\n\n\t Product deleted succesfully";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");

		if(token==0)
		{
		    system("cls");
			cout<<"\n\n Record not found";
		}
	}
}

void shopping:: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|___________________________________________________________\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n|___________________________________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;

	}
	data.close();
}

void shopping::receipt()
	{
		system("cls");
		fstream data;

		int arrc[100],arrq[100];
		char choice;
		int c=0;
		float amount=0;
		float dis=0;
		float total=0;
		cout<<"\n\n\t\t\t Receipt ";
		data.open("database.txt",ios::in);
		if(!data)
		{
			cout<<"\n\n Empty database";
		}
		else
		{
			data.close();
			list();
			cout<<"\n____________________________\n";
			cout<<"\n|                            |";
			cout<<"\n|    Please place the order  |";
			cout<<"\n|____________________________|\n";
			do
			{
				m:
				cout<<"\n\n Product Code : ";
				cin>>arrc[c];
				cout<<"\n Product Quantity : ";
				cin>>arrq[c];
				for(int i=0;i<c;i++)
				{
					if(arrc[c] == arrc[i])
					{
						cout<<"\n\n Duplicate Product Code. Please try again!";
						goto m;
					}
				}
				c++;
				cout<<"\n\n Want to buy another product? Press y for yes and n for no : ";
				cin>>choice;
			}

			while(choice == 'y');
			system("cls");

			cout<<"\n\n\t\t\t__________RECEIPT______________\n";
			cout<<"\nProduct Num.\tProduct Name\tQuantity \tPrice \tAmount \tAmount with discount\n";


			for(int i=0;i<c;i++)
			{
				data.open("database.txt",ios::in);
				data>>pcode>>pname>>price>>dis;
				while(!data.eof())
				{
					if(pcode == arrc[i])
					{
						amount = price*arrq[i];
						dis = amount - (amount*dis/100);
						total =total+ dis;
						cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
					}
					   data>>pcode>>pname>>price>>dis;
				}
				data.close();
			}
			cout<<"\n\n----------------------------------------";
			cout<<"\n Total Amount : "<<total<<endl;
			char a;
			n:
			cout<<"\n\n\t\t\t Press n to go back :   ";
			cin>>a;
			if(a=='n' || a=='N')
            {
                system("cls");
                return;
            }
            else
            {
                cout<<"\n\n\t\t\tInvalid option!!!!"<<endl;
                goto n;
            }
		}
	}
	void shopping::createAdministrator() {
    string username, password;
    cout << "\n\t\t\t Create New Administrator Account \n\n";
    m:
    cout << "\t\t\t Enter new username : ";
    cin >> username;
    if (isUsernameTaken(username)) {
        cout << "\n\t\t\t Username already taken. Please choose another username.\n\n";
        goto  m;
    }
    cout << "\t\t\t Enter new password : ";
    cin >> password;
    ofstream adminFile("admin_credentials.txt", ios::app);
    if (!adminFile) {
        cout << "\n\t\t\t Error creating administrator account!\n";
        return;
    }

    adminFile << username << " " << password << "\n";
    adminFile.close();
    system("cls");
    cout << "\n\t\t\t Administrator account created successfully!\n";
}
bool shopping::isUsernameTaken(const string& username) {
    ifstream adminFile("admin_credentials.txt");
    if (!adminFile) {
        cout << "\n\t\t\t Administrator credentials file not found!\n";
        return false;
    }

    string storedUsername, storedPassword;
    while (adminFile >> storedUsername >> storedPassword) {
        if (storedUsername == username) {
            adminFile.close();
            return true; // Username already exists
        }
    }

    adminFile.close();
    return false; // Username is available
}
void shopping::authenticateAdministrator() {
    string username, password;
    cout << "\n\t\t\t Please Login!!! \n\n";
    m:
    cout << "\t\t\t Enter username : ";
    cin >> username;
    cout << "\t\t\t Enter Password : ";
    cin >> password;

    ifstream adminFile("admin_credentials.txt");
    if (!adminFile) {
        cout << "\n\t\t\t Administrator credentials file not found!\n";
        return;
    }

    string storedUsername, storedPassword;
    int authenticated = 0;

    while (!adminFile.eof()) {
        adminFile >> storedUsername >> storedPassword;
        if (storedUsername == username && storedPassword == password) {
            authenticated = 1;
            break;
        }
    }
if (authenticated==1)
    {
        administrator();
    }
    else {
        cout << "\n\t\t\t Invalid username or password!\n\n";
    }
    goto m;
    adminFile.close();
}
int main()
{
	shopping s;
	s.menu();
	return 0;
}


