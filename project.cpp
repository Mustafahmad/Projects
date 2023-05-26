#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<windows.h>
using namespace std;

class login     //base class1
{                     
	string password;
	string email;            
	string name;
	string searchpass;              //data members of login class
	string su2;
	string sp2;
	string searchuser;
	string se;
	string sp;
	int choices;
	int ch;
public:
    friend void choice();      //where user will choose the options
   	void Register();		  //provoke when when user want to register
	void user_login();	     //provoke when user want to login
	void forgot();          //provoke when user forgot his password
	void username();       //retireve password through username 
	void passwords();     //retireve username through password
}; 

void choice ()               //friend function for choices
{ 
	  login l;
	  system("cls");

		cout << "\t\t		*********************************************************" << endl;
		cout << "\t\t		*                                                       *" << endl;
		cout << "\t\t		*                         WELCOME                       *" << endl;         //display
		cout << "\t\t		*                                                       *" << endl;
		cout << "\t\t		*********************************************************" << endl;
		cout << "\n************************************"<<endl;
		cout << "1.LOGIN" << endl;
		cout << "2.REGISTER" << endl;
		cout << "3.FORGOT PASSWORD (or) USERNAME" << endl;
		cout << "4.Exit" << endl;
		cout << "\nEnter your choice :";
		cout << "\n************************************"<<endl;
		cin >> l.choices;
		cout << endl;
		switch (l.choices)
		{
		case 1:
			l.user_login();       //login function
			break;
			
		case 2:
			l.Register();       //register function
			break;
			
		case 3:
			l.forgot();        //forgot
			break;
			
		case 4:
			system("cls");
 			cout << "\n\t\tSolarify";
			cout << "\n************************************************"<<endl;
			cout << "\n\n\nTHANKS FOR COMING. HOPE TO SEE YOU AGAIN" ;
			cout << "\n\n\n\n************************************************"<<endl;
			exit(0);          //command to exit program
			system("pause");
			break;
			
		default:
			cout<<"You've made a mistake , Try again with the given choices.\n"<<endl;
			exit(0);
			system("pause");			
		}	
}

void login :: Register ()
{        
		system("cls");

		cout << "\t\t		********************************************************" << endl;
		cout << "\t\t		*                                                      *" << endl;
		cout << "\t\t		*     Welcome to the registration site of Solarify     *" << endl;         //display
		cout << "\t\t		*                                                      *" << endl;
		cout << "\t\t		********************************************************" << endl;

		cout << "Enter the Name :";
		cin  >> name;
		cout << "Enter the Username :";
		cin  >> email;
		cout << "Enter the Password :";
		cin  >> password;

		ofstream reg("RegisteredUsers.txt", ios::app);   //file handling
		reg << email << ' ' << password << ' ' << name << endl;
		system("cls");

		cout << "\t\t		********************************************************" << endl;
		cout << "\t\t		*                                                      *" << endl;
		cout << "\t\t		*                  Registration Successfull            *" << endl;         //display
		cout << "\t\t		*                                                      *" << endl;
		cout << "\t\t		********************************************************" << endl;
		system("pause");
		choice();
}
void login :: user_login()
{
	system("cls");
		cout << "\t\t		********************************************************" << endl;
		cout << "\t\t		*                                                      *" << endl;
		cout << "\t\t		*                 WELCOME TO LOGIN PAGE                *" << endl;         //display
		cout << "\t\t		*                                                      *" << endl;
		cout << "\t\t		********************************************************" << endl;

		int counts = 0;
		string mail, pass, u, p;
		cout << "PLEASE ENTER THESE DETAILS : \n\n" << endl;
		cout << "USERNAME    :";
		cin  >> mail;
		cout << "PASSWORD :";
		cin  >> pass;

		ifstream input("RegisteredUsers.txt");   //input
		while (input >> u >> p)
		{
			if (u == mail && p == pass)
			{
				counts = 1;
				system("cls");
			}
		}
		if (counts == 1)
		{

			cout << "\t\t		********************************************************" << endl;
			cout << "\t\t		*                                                      *" << endl;
			cout << "\t\t		*                        HELLO !                       *" << endl;         //display
			cout << "\t\t		*                                                      *" << endl;
			cout << "\t\t		*              'YOUR LOGIN IS SUCCESSFUL'              *" << endl;
			cout << "\t\t		*                                                      *" << endl;
			cout << "\t\t		********************************************************" << endl;
			cin.get();
			cin.get();


		}
		else if(counts == 0 || counts == 2 || counts == 3)
		{
			cout << "\t\t		********************************************************" << endl;
			cout << "\t\t		*                                                      *" << endl;
			cout << "\t\t		*                     LOGIN ERROR                      *" << endl;         //display
			cout << "\t\t		*                                                      *" << endl;
			cout << "\t\t		*         Please check your username and password      *" << endl;
			cout << "\t\t		*                                                      *" << endl;
			cout << "\t\t		********************************************************" << endl;
			cin.get();
			cout << "\n\nPlease check your username or password\n";
			system("pause");
			choice();
		}

		input.close();	
}

void login :: forgot ()
{
		system("cls");
		cout << "\nForgotten ? We're here to help";
		cout << "\n************************************";
		cout << "\n1.Search your id by username";
		cout << "\n2.Search your id by password";
		cout << "\n3.Main menu";
		cout << "\nEnter your choice :";
		cout << "\n************************************"<<endl;
		cin  >> ch;
		switch (ch)
		{
		case 1:
		{
			username();
			break;
		}
		case 2:
		{  
			passwords();
			break;
		}

		case 3:
		{
			choice();
		}
		default:
			cout << "Sorry, You entered wrong choice. Kindly try again" << endl;
			system("pause");
			forgot();
		}	
}
void login :: username ()
{
	int count = 0;
	cout << "\nEnter your remembered Email :";
	cin >> searchuser;

	ifstream searchu("RegisteredUsers.txt");
	while (searchu >> se >> sp)
	{
		if (se == searchuser)    //searching data in file
		{
			count = 1;
		}
	}
	searchu.close();
	if (count == 1)
	{

		cout << "\t\t		********************************************************"<< endl;
		cout << "\t\t		*                                                      *" << endl;
		cout << "\t\t		*                     Account Found !                  *" << endl;         //display
		cout << "\t\t		*                                                      *" << endl;
		cout << "\t\t		********************************************************" << endl;
		cout << "\n\n Hi! "<< "Forgotten your Password?\n";
		cout << "\nYour password is " << sp;
		cin.get();
		cin.get();
		system("cls");
		choice();	
	}
	else
	{
    	cout << "\n\n\nSorry, Your userID is not found in our database\n";
		cout << "\nPlease kindly contact your system administrator for more details \n";
		cin.get();
		cin.get();
		choice();	
	}
}
void login :: passwords()
{
		int count = 0;
		cout << "\nEnter the remembered password :";
		cin  >> searchpass;
		ifstream searchp("RegisteredUsers.txt");    //through password finding email
		while (searchp >> su2 >> sp2)
		{
			if (sp2 == searchpass)
			{
				count = 1;
			}
		}
		searchp.close();
		if (count == 1)
		{
			cout << "\t\t		********************************************************" << endl;
			cout << "\t\t		*                                                      *" << endl;
			cout << "\t\t		*        Your password was found in the database !     *" << endl;         //display
			cout << "\t\t		*                                                      *" << endl;
			cout << "\t\t		*                                                      *" << endl;
			cout << "\t\t		********************************************************" << endl;
			cout << " \n\nHi!"<< " Forgotten your Email?";
			cout << "\nYour EMAIL is : " << su2;
			cin.get();
			cin.get();
			system("cls");
			choice();
		}
		else
		{
			cout << "Sorry, We cannot found your password in our database \n";
			cout << "\nkindly contact your administrator for more information\n";
			cin.get();
			cin.get();
			choice();
		}
}
class viewpage : public login {      //inheritance 
	int options;
	int op;
	int blub;
	int tv;
	int fans;
	int ac;	
	int pla150=8000; 
	int pla100=6000; 
	int pla300=12000; 
	int pla500=15000; 
	int del1=30000; 
	int sel;
	int cash;
	float bhours;
	float fhours;
	float ahours;
	float thours;
	float total;
	float units;
	float price;
public:
	void option();            //option
	void rate();             //rate list
	void info();            //information
	void power();          //power comsumption
	void services();      //services  
	void suggestion(float);   //suggestion for panels
	void billing();     //billing
	void buy();        //order
	void buy(int);    //payment
	void exits();      //exit
  
};

void viewpage :: option ()
{
		system("cls");    //used to clear screen	
		cout << "\t\t\t		********************************************" << endl;
		cout << "\t\t\t		*                                          *" << endl;
		cout << "\t\t\t		*          Welcome to the Solarify         *" << endl;
		cout << "\t\t\t		*                                          *" << endl;
		cout << "\t\t\t		********************************************" << endl;

		cout << "\n************************************";
		cout << "\nSelect an option to continue." << endl;                     //services on our application
		cout << "\n1.Check Rate list.";
		cout << "\n2.Get information from us.";
		cout << "\n3.Check our services.";
		cout << "\n4.Want to do business.";
		cout << "\n5.Exit." << endl;
		cout << "\n**************************************"<<endl;
		cin  >> options;

		switch (options)
		{
		case 0:
			cout << "Not valid Option.";
			system("pause");
			option();
			break;

		case 1:
			rate();        //rate list
			system("pause");
			option();                      // to go back to menu
			break;
			
		case 2:
			info();      //info
			system ("pause");
			option();
			break;
			
		case 3:             //services
			services ();
			system ("pause");
			option();
			break;
			
		case 4:
			billing ();
			system ("pause");
			option();
			break;
			
		case 5:
	    	exits();   //exit
	    	break;
		}

}
void viewpage::rate ()          //rate function
{
	system("cls");
	cout << "\n\tRates of the services we provide." << endl;
	cout << "\n*************************************************************";
	cout << "\n1.100 watt solar plate will cost 6000 only." << endl;                     //rate list
	cout << "\n2.150 watt solar plate will cost 8000 only." << endl;
	cout << "\n3.300 watt of solar plate will cost 12000 only." << endl;
	cout << "\n4.500 watt of solar plate will cost 15000 only." << endl;
	cout << "\n5.100 watt plates with 100 watt battery will cost 30000 only." << endl;
	cout << "\n*************************************************************** \n";
}
void viewpage :: info(void)    //information
{
	system("cls");
	cout << "\t\t\t\t\tInformation about Solarify"<<endl;
	cout << "\n\t\t\t*************************************************************************";
	cout << "\n\t\t\tWe all know about the Energy crisis in Pakistan.Being on tropical";
	cout << "\n\t\t\tSide of earth,there is no better option then solar system.We are ";
	cout << "\n\t\t\tProviding the wide facility to the user of solar panels and batteries";
	cout << "\n\t\t\tThis Application provide the full range of Solar panels with batteries.";      //basic information
	cout << "\n\t\t\tSolar Panels are available in four different types.";
	cout << "\n\t\t\t100 watt , 150 watt , 300 watt and 500 watts.";
	cout << "\n\t\t\tCombination of these plates or same plates can be used to fulfill the need.";
	cout << "\n\t\t\t***************************************************************************\n";
	cout << "\n\n\t\t\t************Some information about the panels power**********************";
	cout << "\n\t\t\tYou have to calculate the total consumption of your electricity."<<endl;
	cout << "\n\npress 1 to calculate the power consumption or press 2 to continue without it.";
	cin  >> op;
	if (op==1)
	{
	power();
	}
	else
	{
	//	else 
	}
	
}
void viewpage :: power()    //power consumption
{
	system ("cls");
	cout << "\n    To calculate the power consumption of your house, please choose the right options.";
	cout << "\n******************************************************************************************";
	cout << "\n\nNumber of Energy savers you want to be on solar plates:";
	cin  >> blub;
	cout <<"For how many hours they will be used :";
	cin  >> bhours;
	cout << "\nNumber of Fans you want to be on solar plates:";    //taking input from user
	cin  >> fans;
	cout << "For how many hours they will be used :";                             //according to 
	cin  >> fhours;
	cout << "\nNumber of Air conditioners you want to be on solar plates:";            //their requirement
	cin  >> ac;
	cout << "For how many hours they will be used :";                                            //to calculate
	cin  >> ahours;
	cout << "\nNumber of tv you want to be on solar plates:";                                      //power consumption
	cin  >> tv;
	cout << "For how many hours they will be used :";
	cin  >> thours;
	total = (blub * bhours *0.03)+(fans * fhours * 0.10)+(ac * ahours * 1.95) + (tv * thours * 0.40);
	cout << "\nYour Total electricity consumption in one days  will be "<<total<<" KWhs"<<endl;
	units =  total * 30;
	cout << "\nYou are consuming "<<units<<" units in one month.";
	if(units<=200)
	{
		price = units * 9.68;    //if units below 200 it cost 9.68 rupees per unit 
		cout<<"Units will be charged at the rate of 9.68"<<endl;
	}
	else if(units>200 && units<300)
	{
		price = units * 12.15;    //if units above 200 and below 300 it cost 12.15 rupees per unit
		cout<<"Units will be charges at the rate of 12.15"<<endl;
	}
	else if(units>300 && units<700)
	{
		price = units * 20.85;      //if units above 300 and below 700 it cost 12.15 rupees per unit
		cout<<"Units will be charged at the rate of 20.85"<<endl;
	}
	else if(units>700)
	{
		price = units * 23.92;    //if units above 700 it cost 23.92 rupees per unit
		cout<<"Units will be charged at the rate of 23.92"<<endl;
	}
	
	if (price<=30000)
	{
		price += 3000;   //3,000 tax amount added in the bill if it is below 30,000
		cout<<"Tax on bill will be 3000"<<endl;
	}
	else if(price >30000 && price<=50000)
	{
		price += 5000;    //5,000 tax amount added in the bill if it is above 30,000 and below 50,000
		cout<<"Tax on bill will be 5,000"<<endl;
	}
		else if(price > 50000)
	{
		price += 10000;    //10,000 tax amount added in the bill if it is above 50,000
		cout<<"Tax on bill will be 1,0000"<<endl;
	}
	cout << "\nBy using Solar Plates you  can save upto "<<price<<" rupees in a month";
	cout << "\n******************************************************************************************"<<endl;
	cout << "Press enter ";
	system("pause > nul");
	suggestion(total);
}
void viewpage :: suggestion (float t)
{
	system("cls");
	cout << "\n\t\t\tSuggestions";
	cout << "\n*********************************************************************************" <<endl;
	cout << "\nWe have multiple options from which you can buy solar plates of different watts." <<endl;
	cout << "\n********************************";
	cout << "\n1.100 watt solar plate." << endl;                     //rate list
	cout << "\n2.150 watt solar plate." << endl;
	cout << "\n3.300 watt of solar plate." << endl;
	cout << "\n4.500 watt of solar plate." << endl;
	cout << "\n5.100 watt plates with 100." << endl;
	cout << "\n*********************************** \n";
	cout << "\nIf your demand of one day consumption is "<<total<<" kwhs";
	cout << "\nFor your ease,We can recommend you that you can buy the following pair of panels"<<endl;
	total  = total * 1000;  //converting kwhs in watts
	if(total <= 100 && total >= 0 )
	{
		cout << "\nYou can buy 100 watt plate which will do the purpose for you. ";
	} 
	else if(total <= 200 && total > 100)
	{
		cout << "\n1.You can buy two 100 watt plates which will do the purpose for you. ";
	}
	else if(total <= 300 && total > 200)
	{
		cout << "\n1.You can buy 3 plates of 100 watts which will do the purpose for you. ";
		cout << "\n2.You can buy two plates of 150 watts. ";
	}
	else if(total <= 500 && total > 300)
	{
		cout << "\n1.You can buy 2 plates of 300 watt .";
		cout << "\n2.You can buy 3 plates of 150 watts with a 100 watt plate.";
		cout << "\n3.You can buy a plate of 500 watts";
	}
	else if(total <= 1000 && total > 500)
	{
		cout << "\n1.You can buy 2 plates of 500 watts.";
		cout << "\n2.Or You can buy a plate of 500 watts with 2 plates of 300 watts.";
	}
	else if(total <= 1500 && total > 1000)
	{
		cout << "\n1.You can buy 3 plates of 500 watts.";
		cout << "\n2.Or You can buy 2 plate of 500 watts with 2 plates of 300 watts.";
	}
	else if(total <= 2000 && total > 1500)
	{
		cout << "\n1.You can buy 4 plates of 500 watts.";
		cout << "\n2.Or You can buy 3 plate of 500 watts with two plates of 300 watts.";
	}
	else if(total <= 3000 && total > 2000)
	{
		cout << "\n1.You can buy 6 plates of 500 watts.";
		cout << "\n2.Or You can buy 5 plate of 500 watts with 2 plates of 300 watts.";
	}
		else if(total <= 5000 && total > 3000)
	{
		cout << "\n1.You can buy 10 plates of 500 watts.";
		cout << "\n2.Or You can buy 8 plate of 500 watts with 4 plates of 300 watts.";
		cout << "\n3.Or You can buy 9 plate of 500 watts with 2 plates 300 watts.";
    }
    else if(total <= 7000 && total > 5000)
	{
		cout << "\n1.You can buy 14 plates of 500 watts.";
		cout << "\n2.Or You can buy 11 plate of 500 watts with 5 plates of 300 watts.";
		cout << "\n3.Or You can buy 13 plate of 500 watts with 2 plates of 300 watts.";
    }
    else if(total <= 9000 && total > 7000)
	{
		cout << "\n1.You can buy 18 plates of 500 watts.";
		cout << "\n2.Or You can buy 15 plate of 500 watts with 5 plates of 300 watts.";
		cout << "\n3.Or You can buy 17 plate of 500 watts with 2 plates of 300 watts.";
    }
    else if(total <= 10000 && total > 9000)
	{
		cout << "\n1.You can buy 20 plates of 500 watts.";
		cout << "\n2.Or You can buy 17 plate of 500 watts with 5 plates of 300 watts.";
		cout << "\n3.Or You can buy 19 plate of 500 watts with 2 plates of 300 watts.";
    }
    else if(total > 10000)
	{
		cout << "\n1.You have to buy at least 21 plates of 500 watts.";
		cout << "\n With multiple 300 watts plates and 150 plates to meet your requirement.";
    }
    else
	{
    	cout << "\nSorry, For your requirement we dont have any suggestion.";
	}
	cout << "\n*********************************************************************************" <<endl;
}
void viewpage :: services()     //services
{
	system ("cls");
	cout << "\n\t\t Services we provide." << endl;
	cout << "\n*****************************************************************************";
	cout << "\nWe aim to provide the best faclities in town and to educate the masses.";
	cout << "\nThere are number of faclities we are providing which are as follows "<<endl;
	cout << "\n1.We make sure that the services are transparent so we record user data.";          // services 
	cout << "\n2.We provide the best rates to our customer to choose wisely.";                
	cout << "\n3.We provide the mechanism where user can calculate his requirement.";
	cout << "\n4.We provide the plateform where user can actually buy the product.";
	cout << "\n5.User can exit whenever he wants without billing unless he buy something."<<endl;
	cout << "\n****************************************************************************\n";
}
void viewpage :: billing ()         //billing
{
	system ("cls");
	cout << "\n\t\t     Payment Gateway." << endl;
	cout << "\n*************************************************************";
	cout << "\n\t\tList to choose our product"<<endl;
	cout << "\n1.100 watt solar plates. " <<endl;                     //Menu
	cout << "\n2.150 watt solar plate. " <<endl;
	cout << "\n3.300 watt of solar plate." <<endl;
	cout << "\n4.500 watt of solar plate." <<endl;
	cout << "\n5.100 watt plates with 100 watt battery." <<endl;
	cout << "\n*************************************************************** \n";
	cout << "\nPress 1 to buy the product or Press 2 to go back to main window.";
	cin  >> sel;
		
	if (sel==1)
	{
			buy();
	}
	
	else if (sel==2)
	{
		system("pause");
		option();
	}
	
	else
	{
		cout<<"Invalid Command,plz try again"<<endl;
		system("pause > nul");
		billing();
	}
}
void viewpage :: buy ()   //order placing
{
	int pla; int total; string bat;
	system ("cls");
	
	cout << "\n\t\t     Payment Gateway." << endl;
	cout << "\n*************************************************************";
	cout << "\nHow many solar plates of 100 watts you want to buy: ";
	cin  >> pla;
	
	total = pla * pla100;    //adding bill to the total
	cout << "How many solar plates of 150 watts you want to buy: ";
	cin  >> pla;
	
	total +=  pla * pla150;    //adding bill to the total
	cout << "How many solar plates of 300 watts you want to buy: ";
	cin  >> pla; 
	
	total +=  pla * pla300;     //adding bill to the total
	cout << "How many solar plates of 500 watts you want to buy: ";
	cin  >> pla;
	
	total +=  pla * pla500;	    //adding bill to the total
	cout << "Do you want to buy the deal (yes/no): ";
	cin  >> bat;
	if (bat =="Yes" || bat =="yes" || bat == "YES")
	{
	total +=  1 * del1;	     //adding bill to the total
    }
    else
	{
	}
	cout << "\n*************************************************************"<<endl;
	cout << "Press enter ";
	system("pause > nul");
	buy(total);
}
void viewpage :: buy (int t)     //payment options
{
	system("cls");
	cout << "\n\t\tPayment option";
	cout << "\n*************************************************************"<<endl;
	cout << "\nYou can pay through different channels."<<endl;
	cout << "\n************************************"<<endl;
	cout << "\n1.Press 1 for Online gateways.";
	cout << "\n2.Press 2 for Cash on delivery."<<endl;
	cout << "\n************************************"<<endl;
	cin  >> cash;

	if(cash == 1)
	{
		cout << "\nYou have to pay "<<t<<" through your bank account."<<endl;
		cout << "\nOrder will be place at your destination."<<endl;
		cout << "\nThank you, For shopping from us.";
		cout << "\nContact us for any other query.";
	}
	else if(cash == 2)
	{
		cout << "\nYou have to pay "<<t<<" on cash delivery."<<endl;
		cout << "\nOrder will be place at your destination."<<endl;
		cout << "\nThank you, For shopping from us.";
		cout << "\nContact us for any other query.";
	}
	else 
	{
		cout << "Wrong Command!!!!";
		system("pause > nul");
		exit(0);
	}
	cout << "\n*************************************************************"<<endl;
}
void viewpage :: exits()     //exit
{
	system("cls");
	cout << "\n\t\tSolarify";
	cout << "\n************************************************"<<endl;
	cout << "\n\n\nTHANKS FOR COMING. HOPE TO SEE YOU AGAIN" ;
	cout << "\n\n\n\n************************************************"<<endl;
}
int main()
{
	viewpage m;   //object creation
	choice();    //friend function calling
	m.option();  //function calling
}

