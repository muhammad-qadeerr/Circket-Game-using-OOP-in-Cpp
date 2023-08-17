//*******    Group Members     *********
//Raheeb Ahmad                    BCSF20M020
//Muhammad Qadeer                 BCSF20M037
//Muhammad Bilal                  BCSF20M040



#ifndef TEAM
#define TEAM
#include <iostream>
using namespace std;

class Team
{
private:
	string TeamID;
	int numberOfWickets;
	int numberOfPlayers;
	int TeamScore;
	int balls;
	int statusWin;         //For checking whoose team goona win

	//different balling legal deliveries ranges

	const int const_distanceV = 50;
	const int const_distanceH = 10;
	const int const_Height = 5;
	const int angle_of_deviation = 90;

	int Entered_distanceV;
	int Entered_distanceH;
	int Entered_Height;
	int Entered_angle_of_deviation;

public:
	Team();
	void setTeamID(string t);
	string getTeamID();
	void DecisionOfToss();
	void Batting();
	void Bowling();
	int DecisionOfGame(int a, int b);           //will cout which team have won
	void displayScore();
	void displayWickets();
};

class Player : public Team
{
public:
	void isStrike(bool b);




};
#endif 


