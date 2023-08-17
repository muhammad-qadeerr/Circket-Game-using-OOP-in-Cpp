
#include<iostream>
#include<fstream>
#include<string>
#include"Team.h"
#include<Windows.h>           //For text Color and Beep Sound 





using namespace std;

int main()

{
	Team T1;
	fstream myfile;
	string array[100];                 //String array to handle file data 
	char ch = ' ';
	myfile.open("teamplayer.txt", ios::in);
	for (int i = 0; i < 100; i++)
	{
		getline(myfile, array[i]);
	}
	myfile.close();
	string array11player[11];                   //array for storing 11 player squad
	int n;
	system("Color E4");                    //E=For Light Yellow background color and 4=Red text color 
	cout << "******welcome*******\n";
	cout << " 1. play\n 2. rule\n 3. exit\n";
	Beep(200, 900); //System beep of 200hertz for 900millisecond 

	int choice = 0;
	cout << "Your Choice: ";
	cin >> choice;
	while (choice < 1 || choice>3)               //Input validaion
	{
		cout << "wrong input select choice again : ";
		cin >> choice;

	}




	switch (choice)
	{
	case 1:

		cout << "select team \n";
		cout << " 1. pakistan\n 2. india\n 3. australia\n 4. england\n 5. new zealand\n ";
		int teamchoice;
		cout << "Your Choice :";
		cin >> teamchoice;
		while (teamchoice < 0 || teamchoice>5)           //Input validation for team selection
		{
			cout << "wrong Input Select again : ";
			cin >> teamchoice;
		}
		switch (teamchoice)
		{
		case 1:
			T1.setTeamID("pakistan");
			cout << "your team is " << T1.getTeamID() << endl;

			for (int i = 0; i <= 16; i++)           //To show 16 player squad
			{
				cout << i << "." << array[i] << endl;
			}

			cout << "\nselect your 11 player squad \n";            //for selecting 11 player
			for (int i = 0; i < 11; i++)
			{
				cout << "enter player " << i + 1 << " :";
				cin >> n;
				array11player[i] = array[n]; //This will make the i index player of 11 player squad equal to i index player from 16 player squad 
			}
			cout << "\n your 11 player squad is : \n";
			for (int i = 0; i < 11; i++)
			{

				cout << i + 1 << "." << array11player[i] << endl;
			}
			break;
		case 2:
			T1.setTeamID("india");
			cout << "your team is " << T1.getTeamID() << endl;
			for (int i = 18; i < 35; i++)             //India squad is in this range of stored array
			{
				cout << i - 18 << "." << array[i + 1] << endl;
			}
			cout << "\nselect your 11 player squad \n";
			for (int i = 0; i < 11; i++)
			{
				cout << "enter player " << i + 1 << " :";
				cin >> n;
				array11player[i] = array[n + 19];
			}
			cout << "\n your 11 player squad is : \n";
			for (int i = 0; i < 11; i++)
			{

				cout << i + 1 << "." << array11player[i] << endl;
			}
			break;
		case 3:
			T1.setTeamID("australia");
			cout << "your team is " << T1.getTeamID() << endl;
			for (int i = 36; i < 53; i++)            //Austrilia squad is in this range of array
			{
				cout << i - 36 << "." << array[i + 2] << endl;
			}
			cout << "\nselect your 11 player squad \n";
			for (int i = 0; i < 11; i++)
			{
				cout << "enter player " << i + 1 << " :";
				cin >> n;
				array11player[i] = array[n + 38];
			}
			cout << "\n your 11 player squad is : \n";
			for (int i = 0; i < 11; i++)
			{

				cout << i + 1 << "." << array11player[i] << endl;
			}
			break;
		case 4:
			T1.setTeamID("england");
			cout << "your team is " << T1.getTeamID() << endl;
			for (int i = 54; i < 71; i++)              //England squad is in this range of array
			{
				cout << i - 54 << "." << array[i + 3] << endl;
			}
			cout << "\nselect your 11 player squad \n";
			for (int i = 0; i < 11; i++)
			{
				cout << "enter player " << i + 1 << " :";
				cin >> n;
				array11player[i] = array[n + 57];
			}
			cout << "\n your 11 player squad is : \n";
			for (int i = 0; i < 11; i++)
			{

				cout << i + 1 << "." << array11player[i] << endl;
			}
			break;
		case 5:
			T1.setTeamID("new zeland");
			cout << "your team is " << T1.getTeamID() << endl;
			for (int i = 72; i < 89; i++)     //New Zealand Squad is in this range of array
			{
				cout << i - 72 << "." << array[i + 4] << endl;
			}
			cout << "\nselect your 11 player squad \n";
			for (int i = 0; i < 11; i++)
			{
				cout << "enter player " << i + 1 << " :";
				cin >> n;
				array11player[i] = array[n + 76];
			}
			cout << "\n your 11 player squad is : \n";
			for (int i = 0; i < 11; i++)
			{

				cout << i + 1 << "." << array11player[i] << endl;
			}
			break;


		}


		while (1)
		{
			cout << "do you want to modified the batting order ? reply with (y/n): ";
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
			{
				string tempplayer;         //temp name variable to store the position of player for swaping purpose
				int position;
				int modified;
				cout << "enter the position of player which is to be modifed : ";
				cin >> position;
				cout << "enter the position in which is to be placed : ";
				cin >> modified;

				tempplayer = array11player[position - 1];
				array11player[position - 1] = array11player[modified - 1];
				array11player[modified - 1] = tempplayer;


				cout << "\n\nsquad after modification is : \n";
				for (int i = 0; i < 11; i++)
				{
					cout << i + 1 << "." << array11player[i] << endl;
				}
			}
			else
			{
				cout << "\n\nfinal squad is : \n";
				for (int i = 0; i < 11; i++)                //Will Display the Final Squad
				{
					cout << i + 1 << "." << array11player[i] << endl;
				}
				break;
			}

		}
		T1.DecisionOfToss();




		break;

	case 2:
		cout << "   **rules**   " << endl;
		cout << "1. 1 over match (6 balls)" << endl;
		cout << "2. only select teams from given options " << endl;
		cout << "3. can select 11 players for match" << endl;
		cout << "4. there are some fixed conditions in which batsman will be out " << endl;
		break;
	case 3:
		cout << "The Game has been successfully Exit! ";
		exit(0);
	default:
		cout << " Wrong Input!";
		break;
	}






	return 0;
}