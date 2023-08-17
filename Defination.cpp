
#include "Team.h"
#include <iostream>
#include <cstdlib>
#include<Windows.h>
using namespace std;


Team::Team()               //Default Constructor
{
	TeamID = " ";
	numberOfPlayers = 11;
	numberOfWickets = 10;
	TeamScore = 0;
	balls = 6;                //one over match so thats why 6 balls!
	Entered_distanceV = 0;
	Entered_distanceH = 0;
	Entered_Height = 0;
	Entered_angle_of_deviation = 0;
}
void Team::setTeamID(string t)          //For storing name of team
{
	TeamID = t;
}
string Team::getTeamID()
{
	return TeamID;
}
void Team::DecisionOfToss()
{
	int scoret1;
	int scoret2;
	cout << "\n\nNow lets Move Towards Toss\n\n";
	cout << "Heads or Tails?" << endl;
	cout << "1. Heads" << endl;
	cout << "2. Tails" << endl;

	int toss;
	cout << "Your Choice: ";
	cin >> toss;
	while (toss < 1 || toss>2)
	{
		cout << "Wrong INPUT Select Again : ";
		cin >> toss;
	}

	cout << "Your choice is: " << toss << endl;

	int toss2;

	srand(time(NULL));
	toss2 = (rand() % 2) + 1;            //random number between 1 and 2 for decision of toss

	cout << toss2 << endl;

	if (toss == toss2)
	{
		cout << "Congratulations!You won the toss..Would you like to bat or bowl ?" << endl;
		Beep(200, 900);
		cout << "1. Bat" << endl;
		cout << "2. Bowl" << endl;

		int a;
		cin >> a;
		cout << "your choice: " << a << endl;
		if (a == 1)
		{
			cout << "Its our batting!!" << endl << endl;
			int x = 1;
			while (balls != 0)                    //This will call the batting function until ball becomes zero
			{
				cout << "Ball " << x << " is: " << endl << endl;
				Batting();

				cout << endl << endl;
				++x;
			}
			scoret1 = TeamScore;                     //To store the team1 score after batting
			cout << "\n\nThe Score of Team 1 is " << scoret1 << endl << endl;
			if (balls == 0)
			{
				x = 1;
				balls = 6;
				TeamScore = 0;
				numberOfWickets = 10;
				Beep(200, 900);
				cout << "\n\n***************Next Innings ! *************\n";
				while (balls != 0)            //This will call the bowling function until ball becomes zero
				{
					cout << "Ball " << x << " is: " << endl << endl;
					Bowling();

					cout << "Remaining balls are " << balls << endl;
					cout << "Remaining wickets are " << numberOfWickets << endl;
					cout << "Score is " << TeamScore << endl << endl;
					++x;

				}
				scoret2 = TeamScore;                     //to store the team 2 score
				cout << "\n\n The score of team 2 is : " << scoret2 << endl << endl;
			}
		}
		else
		{
			int x = 1;
			cout << "Its our bowling!!" << endl << endl;
			while (balls != 0)
			{
				cout << "Ball " << x << " is: " << endl << endl;
				Bowling();

				cout << "Remaining balls are " << balls << endl;
				cout << "Remaining wickets are " << numberOfWickets << endl;
				cout << "Score is " << TeamScore << endl << endl;
				++x;
			}

			scoret2 = TeamScore;
			cout << "\n\nThe Score of Team 2 is " << scoret2 << endl << endl;
			if (balls == 0)
			{
				x = 1;
				TeamScore = 0;
				numberOfWickets = 10;
				balls = 6;
				Beep(200, 900);
				cout << "************Next Innings ! *********\n";
				while (balls != 0)
				{
					cout << "Ball " << x << " is: " << endl << endl;
					Batting();

					cout << endl << endl;
					++x;
				}
				scoret1 = TeamScore;
				cout << "\n\nThe Score of Team 1 is " << scoret1 << endl << endl;
			}
		}
	}
	else
	{
		Beep(200, 900);
		cout << "Sorry, You lost the toss.. The opponent has chosen to bat." << endl;

		int x = 1;
		while (balls != 0)
		{
			cout << "Ball " << x << " is: " << endl << endl;
			Bowling();

			cout << "Remaining balls are " << balls << endl;
			cout << "Remaining wickets are " << numberOfWickets << endl;
			cout << "Score is " << TeamScore << endl << endl;
			++x;

		}
		scoret2 = TeamScore;
		cout << "\n\nThe Score of Team 2 is " << scoret2 << endl << endl;
		if (balls == 0)           //After ball become zero we will call next innings batting or bowling
		{
			x = 1;
			balls = 6;
			TeamScore = 0;
			numberOfWickets = 10;
			Beep(200, 900);
			cout << "************Next Innings ! *********\n";
			while (balls != 0)
			{
				cout << "Ball " << x << " is: " << endl << endl;
				Batting();

				cout << endl << endl;
				++x;
			}
			scoret1 = TeamScore;
			cout << "\n\nThe Score of Team 1 is " << scoret1 << endl << endl;
		}

	}

	if (DecisionOfGame(scoret1, scoret2) == 1)
	{
		cout << "Team 1 score is :  " << scoret1 << "   and Team 2 score is : " << scoret2;
		Beep(200, 900);
		cout << "\n**************Team 1 has won the match**********\n" << endl;

	}
	else if (DecisionOfGame(scoret1, scoret2) == 0)
	{
		cout << "Team 1 score is :  " << scoret1 << "   and Team 2 score is : " << scoret2;
		Beep(200, 900);
		cout << "\n***********Team 2 has won the match***********\n" << endl;
	}
	else if (DecisionOfGame(scoret1, scoret2) == 2)
	{
		cout << "Team 1 score is :  " << scoret1 << "   and Team 2 score is : " << scoret2;
		Beep(200, 900);
		cout << "\n************The match is draw************\n" << endl;
	}

}
void Player::isStrike(bool b)        //Function to show wether batsman strikes or not
{

	if (b == 1)
	{
		cout << "Batsman strikes" << endl;
	}
	else if (b == 0)
	{
		cout << "Batsman didnt play the ball" << endl;
	}
}
void Team::Batting()              //Batting Function 
{
	Player p1;                 //Creating player object to call strike function bcz its player member function

	//Automaticallty generated values when we are gonna bat in the range of normal and slightly illegeal dilvery to make reliastic
	cout << endl;
	cout << "Bowler running distance is automatically generated " << endl;
	srand(time(NULL));
	Entered_distanceV = rand() % (52 - 45 + 1) + 45;
	cout << "Bowler running distance is: " << Entered_distanceV << endl;

	cout << "Bowler width delivery is automatically generated " << endl;
	Entered_distanceH = rand() % (11 - 4 + 1) + 4;
	cout << "Width of delievered bowl is: " << Entered_distanceH << endl;

	cout << "bowler delivery height is automatically generated: " << endl;
	Entered_Height = rand() % (8 - 4 + 1) + 4;
	cout << "Height of bowl is: " << Entered_Height << endl;

	cout << "bowler delivery angle of deviation is automatically generated : " << endl;
	Entered_angle_of_deviation = rand() % (100 - 75 + 1) + 75;
	cout << "Angle of deviation is: " << Entered_angle_of_deviation << endl;
	cout << endl;

	//for checking Noball

	if (Entered_distanceV > const_distanceV)
	{
		bool c;
		cout << "You want to strike the ball or not answer with 1 or 0 " << endl;
		cout << "Your reply : ";
		cin >> c;


		p1.isStrike(c);

		cout << "********************    Its Noball!!    *********************" << endl;
		Beep(200, 900);
		balls = balls + 1;
		TeamScore = TeamScore + 1;



		if (c == 1)
		{
			int n;
			srand(time(NULL));
			n = ((4 / 2) + rand() % (6 - 4 + 2) / 2) * 2;
			TeamScore = TeamScore + n;

		}
		else if (c == 0)
		{
			int n;
			n = 0;
			TeamScore = TeamScore + n;
		}
		cout << "Remaining balls are " << balls << endl;
		cout << "Remaining wickets are " << numberOfWickets << endl;
		cout << "Score is " << TeamScore << endl;

	}
	//for checking wide ball upper range and lower range
	else if (Entered_distanceH > const_distanceH || Entered_distanceH < const_distanceH / 2)
	{
		bool c1;
		cout << "You want to strike the ball or not answer with 1 or 0 " << endl;
		cout << "Your reply : ";
		cin >> c1;


		p1.isStrike(c1);
		cout << "***********************   Its Wide Ball!!!   ******************" << endl;
		Beep(200, 900);
		TeamScore = TeamScore + 1;



		if (c1 == 1)
		{
			int n = 4;
			TeamScore = TeamScore + n;
		}
		else if (c1 == 0)
		{
			int n;
			n = 0;
			TeamScore = TeamScore + n;
		}

		cout << "Remaining balls are " << balls << endl;
		cout << "Remaining wickets are " << numberOfWickets << endl;
		cout << "Score is " << TeamScore << endl;
	}
	//for checking bouncer delivery
	else if (Entered_Height > const_Height)
	{
		bool c2;
		cout << "You want to strike the ball or not answer with 1 or 0 " << endl;
		cout << "Your reply : ";
		cin >> c2;


		p1.isStrike(c2);
		cout << "****************     Its a Bouncer!  *********************" << endl;


		if (c2 == 1)
		{
			int n = 6;
			TeamScore = TeamScore + n;
			balls = balls - 1;
		}
		else if (c2 == 0)
		{
			//assigning differnet values to out condition and generating random number in that range to find particular label
			int zero_score = 0;
			int HitWicket = 1;
			int Catch = 2;
			srand(time(NULL));
			int random = rand() % 3;
			if (random == 0)
			{
				cout << "**********      It is a dot ball.      ************" << endl;

				TeamScore = TeamScore + zero_score;
			}
			else if (random == 1)
			{

				cout << "***************   Bowler hits the wickets and its a OUT!!!   *****************" << endl;
				Beep(200, 900);
				numberOfWickets = numberOfWickets - 1;
				TeamScore = TeamScore + zero_score;
			}
			else if (random == 2)
			{

				cout << "***************   Ball goes in the sky but is is a catch out!!  ****************" << endl;
				Beep(200, 900);
				numberOfWickets = numberOfWickets - 1;
				TeamScore = TeamScore + zero_score;
			}
		}
		cout << "Remaining balls are " << balls << endl;
		cout << "Remaining wickets are " << numberOfWickets << endl;
		cout << "Score is " << TeamScore << endl;

	}
	else if (Entered_angle_of_deviation > 85 && Entered_angle_of_deviation < 95)       //checking spin ball
	{
		bool c3;
		cout << "You want to strike the ball or not answer with 1 or 0 " << endl;
		cout << "Your reply : ";
		cin >> c3;


		p1.isStrike(c3);

		cout << "******************      Its a spin ball!!        *****************" << endl;

		if (c3 == 1)
		{
			int array[] = { 0,1,2,4,6 };
			srand(time(NULL));
			int n = rand() % 5;
			TeamScore = TeamScore + array[n];
			balls = balls - 1;
		}
		else if (c3 == 0)
		{
			int zero_score = 0;
			int HitWicket = 1;
			int LBW = 2;
			int Catch = 3;
			srand(time(NULL));
			int random = rand() % 4;

			if (random == 0)
			{
				cout << "************           It is a dot ball.       **************" << endl;

				TeamScore = TeamScore + zero_score;
			}
			else if (random == 1)
			{

				cout << "****************            Hitwickets!       ***************" << endl;
				Beep(200, 900);
				numberOfWickets = numberOfWickets - 1;
				TeamScore = TeamScore + zero_score;
			}
			else if (random == 2)
			{
				cout << "***************     Bowler appeals for LBW and umpire said its out!   ************" << endl;
				Beep(200, 900);
				numberOfWickets = numberOfWickets - 1;
				TeamScore = TeamScore + zero_score;
			}
			else if (random == 3)
			{
				cout << "***************     Ball goes in the sky but is is a catch out!!   ****************" << endl;
				Beep(200, 900);
				numberOfWickets = numberOfWickets - 1;
				TeamScore = TeamScore + zero_score;
			}
		}

		cout << "Remaining balls are " << balls << endl;
		cout << "Remaining wickets are " << numberOfWickets << endl;
		cout << "Score is " << TeamScore << endl;
	}
	else
	{

		bool c4;
		cout << "You want to strike the ball or not answer with 1 or 0 " << endl;
		cout << "Your reply : ";
		cin >> c4;


		p1.isStrike(c4);

		cout << "***********           Its a normal ball!!!          ************8" << endl;

		if (c4 == 1)
		{
			int array[] = { 0,1,2,4,6 };     //if normal balls and batsman strikes then giving score in this range 
			srand(time(NULL));
			int n = rand() % 5;
			TeamScore = TeamScore + array[n];
			balls = balls - 1;
		}
		else if (c4 == 0)
		{
			int zero_score = 0;
			int HitWicket = 1;
			int LBW = 2;
			int Catch = 3;
			srand(time(NULL));
			int random = rand() % 4;

			if (random == 0)
			{
				cout << "It is a dot ball." << endl;

				TeamScore = TeamScore + zero_score;
			}
			else if (random == 1)
			{
				cout << "************      Hitwickets! ****************" << endl;
				Beep(200, 900);
				numberOfWickets = numberOfWickets - 1;
				TeamScore = TeamScore + zero_score;
			}
			else if (random == 2)
			{
				cout << "***********     Bowler appeals for LBW and umpire said its out! *************" << endl;
				Beep(200, 900);
				numberOfWickets = numberOfWickets - 1;
				TeamScore = TeamScore + zero_score;
			}
			else if (random == 3)
			{
				cout << "*************  Ball goes in the sky but is is a catch out!!  ***************" << endl;
				Beep(200, 900);
				numberOfWickets = numberOfWickets - 1;
				TeamScore = TeamScore + zero_score;
			}
		}
		cout << "Remaining balls are " << balls << endl;
		cout << "Remaining wickets are " << numberOfWickets << endl;
		cout << "Score is " << TeamScore << endl;
	}
}
void Team::Bowling()
{
	Player p;               //player object for calling isstrike function
	cout << "Enter delivery from given option \n";
	cout << " 1. Normal \n 2. Spin \n 3. Bouncer\n";

	int option;
	cout << "your Choice: ";
	cin >> option;
	while (option < 1 || option > 3)
	{
		cout << "Wrong input select again : ";
		cin >> option;
	}
	if (option == 1)
	{
		cout << "Enter bowler running distance: (normal range is upto 50) : ";
		cin >> Entered_distanceV;
		cout << "Bowler running distance is: " << Entered_distanceV << endl;

		cout << "Enter the width of delieverd bowl: (normal range is 5 to 10) : ";
		cin >> Entered_distanceH;
		cout << "Width of delievered bowl is: " << Entered_distanceH << endl;

		if (Entered_distanceV > const_distanceV)      //checking noball and wide condition 
		{
			if (Entered_distanceH > const_distanceH || Entered_distanceH < (const_distanceH / 2))
			{
				cout << "*******         Its Noball!! and wide at the same time but considering NOBALL ! **********  " << endl;
				Beep(200, 900);
				balls = balls + 1;
				TeamScore = TeamScore + 1;

				bool d0;
				srand(time(NULL));
				d0 = rand() % 2;


				p.isStrike(d0);

				if (d0 == 1)
				{
					int n;                    //score 4 or 6
					srand(time(NULL));
					n = ((4 / 2) + rand() % (6 - 4 + 2) / 2) * 2;
					TeamScore = TeamScore + n;

				}
				else if (d0 == 0)
				{
					int n;
					n = 0;
					TeamScore = TeamScore + n;
				}
			}
			else      //only Noball condition 
			{
				cout << "**********        Its Noball!!      ***********" << endl;
				Beep(200, 900);
				balls = balls + 1;
				TeamScore = TeamScore + 1;

				bool c1;
				srand(time(NULL));
				c1 = rand() % 2;


				p.isStrike(c1);

				if (c1 == 1)
				{
					int n;                    //score 4 or 6
					srand(time(NULL));
					n = ((4 / 2) + rand() % (6 - 4 + 2) / 2) * 2;
					TeamScore = TeamScore + n;

				}
				else if (c1 == 0)
				{
					int n;
					n = 0;
					TeamScore = TeamScore + n;
				}

			}
		}

		else if (Entered_distanceH > const_distanceH || Entered_distanceH < (const_distanceH / 2))  //only wide condition
		{
			TeamScore = TeamScore + 1;
			cout << "*********       Its Wide Ball!!!  ************" << endl;
			Beep(200, 900);

			bool c2;
			srand(time(NULL));
			c2 = (rand() % 2);

			p.isStrike(c2);
			if (c2 == 1)
			{
				int n = 4;
				TeamScore = TeamScore + n;
			}
			else if (c2 == 0)
			{
				int n;
				n = 0;
				TeamScore = TeamScore + n;
			}


		}
		else   //normal ball condition
		{
			cout << "**********      Its a normal ball!!!       ***********" << endl;
			Beep(200, 900);
			balls = balls - 1;

			bool c3;
			srand(time(NULL));
			c3 = (rand() % 2);
			p.isStrike(c3);

			if (c3 == 1)
			{
				int array[] = { 0,1,2,4,6 };
				srand(time(NULL));
				int n = rand() % 5;
				TeamScore = TeamScore + array[n];
			}
			else if (c3 == 0)
			{
				int zero_score = 0;
				int HitWicket = 1;
				int LBW = 2;
				int Catch = 3;
				srand(time(NULL));
				int random = rand() % 4;

				if (random == 0)
				{
					cout << "********       It is a dot ball.    ********" << endl;

					TeamScore = TeamScore + zero_score;
				}
				else if (random == 1)
				{
					cout << "*********        Hitwickets! ************" << endl;
					Beep(200, 900);
					numberOfWickets = numberOfWickets - 1;
					TeamScore = TeamScore + zero_score;
				}
				else if (random == 2)
				{
					cout << "**********    Bowler appeals for LBW and umpire said its out!  *********" << endl;
					Beep(200, 900);
					numberOfWickets = numberOfWickets - 1;
					TeamScore = TeamScore + zero_score;
				}
				else if (random == 3)
				{
					cout << "***********   Ball goes in the sky but is is a catch out!! ************" << endl;
					Beep(200, 900);
					numberOfWickets = numberOfWickets - 1;
					TeamScore = TeamScore + zero_score;
				}
			}

		}


	}


	else if (option == 2)
	{
		cout << "Enter angle of deviation of bowl: (normal range is 90 (+5),(-5) is allowed \n";
		cin >> Entered_angle_of_deviation;
		cout << "Angle of deviation is: " << Entered_angle_of_deviation << endl;
		cout << "First we check whether its a noball or wide :\n ";
		cout << "Enter bowler running distance: (normal range is upto 50) : ";
		cin >> Entered_distanceV;
		cout << "Bowler running distance is: " << Entered_distanceV << endl;

		cout << "Enter the width of delieverd bowl: (normal range is 5 to 10) : ";
		cin >> Entered_distanceH;
		cout << "Width of delievered bowl is: " << Entered_distanceH << endl;

		if (Entered_distanceV > const_distanceV)
		{
			if (Entered_distanceH > const_distanceH || Entered_distanceH < (const_distanceH / 2))
			{
				cout << "*********       Its Noball!! and wide at the same time but considering NOBALL !  ********" << endl;
				Beep(200, 900);
				balls = balls + 1;
				TeamScore = TeamScore + 1;

				bool d0;
				srand(time(NULL));
				d0 = rand() % 2;


				p.isStrike(d0);

				if (d0 == 1)
				{
					int n;                    //score 4 or 6
					srand(time(NULL));
					n = ((4 / 2) + rand() % (6 - 4 + 2) / 2) * 2;
					TeamScore = TeamScore + n;

				}
				else if (d0 == 0)
				{
					int n;
					n = 0;
					TeamScore = TeamScore + n;
				}
			}
			else
			{
				cout << "********       Its Noball!! ***********" << endl;
				Beep(200, 900);
				balls = balls + 1;
				TeamScore = TeamScore + 1;

				bool a2;
				srand(time(NULL));
				a2 = rand() % 2;


				p.isStrike(a2);

				if (a2 == 1)
				{
					int n;                    //score 4 or 6
					srand(time(NULL));
					n = ((4 / 2) + rand() % (6 - 4 + 2) / 2) * 2;
					TeamScore = TeamScore + n;

				}
				else if (a2 == 0)
				{
					int n;
					n = 0;
					TeamScore = TeamScore + n;
				}
			}
		}

		else if (Entered_distanceH > const_distanceH || Entered_distanceH < (const_distanceH / 2))
		{
			TeamScore = TeamScore + 1;
			cout << "*********       Its Wide Ball!!!    *********" << endl;

			bool a3;
			srand(time(NULL));
			a3 = (rand() % 2);

			p.isStrike(a3);
			if (a3 == 1)
			{
				int n = 4;
				TeamScore = TeamScore + n;
			}
			else if (a3 == 0)
			{
				int n;
				n = 0;
				TeamScore = TeamScore + n;
			}
		}


		else if (Entered_angle_of_deviation >= 85 && Entered_angle_of_deviation <= 95)
		{
			cout << "********       Its a spin ball!!       *******8" << endl;
			balls = balls - 1;
			bool a4;
			srand(time(NULL));
			a4 = (rand() % 2);

			p.isStrike(a4);
			if (a4 == 1)
			{
				int array[] = { 0,1,2,4,6 };
				srand(time(NULL));
				int n = rand() % 5;
				TeamScore = TeamScore + array[n];
			}
			else if (a4 == 0)
			{
				int zero_score = 0;
				int HitWicket = 1;
				int LBW = 2;
				int Catch = 3;
				srand(time(NULL));
				int random = rand() % 4;

				if (random == 0)
				{
					cout << "*********   It is a dot ball.      *******" << endl;

					TeamScore = TeamScore + zero_score;
				}
				else if (random == 1)
				{
					cout << "*********        Bowler hits the wickets and its a bold!!!  **********" << endl;
					Beep(200, 900);
					numberOfWickets = numberOfWickets - 1;
					TeamScore = TeamScore + zero_score;
				}
				else if (random == 2)
				{
					cout << "**********       Bowler appeals for LBW and umpire said its out! **********" << endl;
					Beep(200, 900);
					numberOfWickets = numberOfWickets - 1;
					TeamScore = TeamScore + zero_score;
				}
				else if (random == 3)
				{
					cout << "*********   Ball goes in the sky but is is a catch out!!     **********" << endl;
					Beep(200, 900);
					numberOfWickets = numberOfWickets - 1;
					TeamScore = TeamScore + zero_score;
				}
			}

		}

		else if (Entered_angle_of_deviation < 85 || Entered_angle_of_deviation > 95)
		{
			cout << "******      Its a normal ball!!!    ********" << endl;
			balls = balls - 1;
			bool a5;
			srand(time(NULL));
			a5 = (rand() % 2);
			p.isStrike(a5);
			if (a5 == 1)
			{
				int array[] = { 0,1,2,4,6 };
				srand(time(NULL));
				int n = rand() % 5;
				TeamScore = TeamScore + array[n];
			}
			else if (a5 == 0)
			{
				int zero_score = 0;
				int HitWicket = 1;
				int LBW = 2;
				int Catch = 3;
				srand(time(NULL));
				int random = rand() % 4;

				if (random == 0)
				{
					cout << "*********      It is a dot ball.      ********" << endl;

					TeamScore = TeamScore + zero_score;
				}
				else if (random == 1)
				{
					cout << "*********       Hitwickets!        ******" << endl;
					Beep(200, 900);
					numberOfWickets = numberOfWickets - 1;
					TeamScore = TeamScore + zero_score;
				}
				else if (random == 2)
				{
					cout << "*********** Bowler appeals for LBW and umpire said its out! ***********" << endl;
					Beep(200, 900);
					numberOfWickets = numberOfWickets - 1;
					TeamScore = TeamScore + zero_score;
				}
				else if (random == 3)
				{
					cout << "***********  Ball goes in the sky but is is a catch out!! *************" << endl;
					Beep(200, 900);
					numberOfWickets = numberOfWickets - 1;
					TeamScore = TeamScore + zero_score;
				}
			}

		}

	}
	else if (option == 3)
	{
		cout << "Enter height of bowl: (normal range is above 5) ";
		cin >> Entered_Height;
		cout << "Height of bowl is: " << Entered_Height << endl;
		cout << "First we check whether its a noball or wide :\n ";

		cout << "Enter bowler running distance: (normal range is upto 50) : ";
		cin >> Entered_distanceV;
		cout << "Bowler running distance is: " << Entered_distanceV << endl;

		cout << "Enter the width of delieverd bowl: (normal range is 5 to 10) : ";
		cin >> Entered_distanceH;
		cout << "Width of delievered bowl is: " << Entered_distanceH << endl;
		if (Entered_distanceV > const_distanceV)
		{
			if (Entered_distanceH > const_distanceH || Entered_distanceH < (const_distanceH / 2))
			{
				cout << "Its a noball and a wide at a time... so we will consider NOBAll!!" << endl;
				balls = balls + 1;
				TeamScore = TeamScore + 1;

				bool d0;
				srand(time(NULL));
				d0 = rand() % 2;


				p.isStrike(d0);

				if (d0 == 1)
				{
					int n;                    //score 4 or 6
					srand(time(NULL));
					n = ((4 / 2) + rand() % (6 - 4 + 2) / 2) * 2;
					TeamScore = TeamScore + n;

				}
				else if (d0 == 0)
				{
					int n;
					n = 0;
					TeamScore = TeamScore + n;
				}
			}
			else
			{
				cout << "********           Its a NOBALL!!        ********" << endl;
				balls = balls + 1;
				TeamScore = TeamScore + 1;

				bool d0;
				srand(time(NULL));
				d0 = rand() % 2;


				p.isStrike(d0);

				if (d0 == 1)
				{
					int n;                    //score 4 or 6
					srand(time(NULL));
					n = ((4 / 2) + rand() % (6 - 4 + 2) / 2) * 2;
					TeamScore = TeamScore + n;

				}
				else if (d0 == 0)
				{
					int n;
					n = 0;
					TeamScore = TeamScore + n;
				}
			}

		}

		else if (Entered_distanceH > const_distanceH || Entered_distanceH < (const_distanceH / 2))
		{
			TeamScore = TeamScore + 1;
			cout << "**********         Its Wide Ball!!!     ************" << endl;

			bool d2;
			srand(time(NULL));
			d2 = (rand() % 2);

			p.isStrike(d2);
			if (d2 == 1)
			{
				int n = 4;
				TeamScore = TeamScore + n;
			}
			else if (d2 == 0)
			{
				int n;
				n = 0;
				TeamScore = TeamScore + n;
			}

		}

		else if (Entered_Height > const_Height)
		{
			cout << "*************           Its a Bouncer!         ********" << endl;
			balls = balls - 1;

			bool d3;
			srand(time(NULL));
			d3 = (rand() % 2);

			p.isStrike(d3);
			if (d3 == 1)
			{
				int n = 6;
				TeamScore = TeamScore + n;
			}
			else if (d3 == 0)
			{
				int zero_score = 0;
				int HitWicket = 1;
				int Catch = 2;
				srand(time(NULL));
				int random = rand() % 3;
				if (random == 0)
				{
					cout << "It is a dot ball." << endl;

					TeamScore = TeamScore + zero_score;
				}
				else if (random == 1)
				{
					cout << "**********     Bowler hits the wickets and its a OUT!!! ************88" << endl;
					Beep(200, 900);
					numberOfWickets = numberOfWickets - 1;
					TeamScore = TeamScore + zero_score;
				}
				else if (random == 2)
				{
					cout << "**********         Ball goes in the sky but is is a catch out!! *************" << endl;
					Beep(200, 900);
					numberOfWickets = numberOfWickets - 1;
					TeamScore = TeamScore + zero_score;
				}
			}
		}
		else if (Entered_Height <= const_Height)
		{
			cout << "Its a normal ball!!!" << endl;
			balls = balls - 1;
			bool d4;
			srand(time(NULL));
			d4 = (rand() % 2);
			p.isStrike(d4);

			if (d4 == 1)
			{
				int array[] = { 0,1,2,4,6 };
				srand(time(NULL));
				int n = rand() % 5;
				TeamScore = TeamScore + array[n];
			}
			else if (d4 == 0)
			{
				int zero_score = 0;
				int HitWicket = 1;
				int LBW = 2;
				int Catch = 3;
				srand(time(NULL));
				int random = rand() % 4;

				if (random == 0)
				{
					cout << "It is a dot ball." << endl;

					TeamScore = TeamScore + zero_score;
				}
				else if (random == 1)
				{
					cout << "**********         Hitwickets!        **********" << endl;
					Beep(200, 900);
					numberOfWickets = numberOfWickets - 1;
					TeamScore = TeamScore + zero_score;
				}
				else if (random == 2)
				{
					cout << "*********     Bowler appeals for LBW and umpire said its out! *********" << endl;
					Beep(200, 900);
					numberOfWickets = numberOfWickets - 1;
					TeamScore = TeamScore + zero_score;
				}
				else if (random == 3)
				{
					cout << "**********    Ball goes in the sky but is is a catch out!!   **********" << endl;
					Beep(200, 900);
					numberOfWickets = numberOfWickets - 1;
					TeamScore = TeamScore + zero_score;
				}


			}
		}
	}


	if (option < 1 && option>3)
	{
		cout << "Wrong Input !";
	}




}
void Team::displayScore()
{
	cout << "The score of team is: " << TeamScore << endl;
}
void Team::displayWickets()
{
	cout << "The wickets are: " << numberOfWickets << endl;
}
int Team::DecisionOfGame(int a, int b) //will recieve two teams score and after compairing change the value of statusWin for final result 
{
	if (a > b)
	{
		statusWin = 1;
		return statusWin;
	}
	else if (a < b)
	{
		statusWin = 0;
		return statusWin;
	}
	else
	{
		statusWin = 2;
		return statusWin;
	}
}