#pragma once


#include <fstream>
#include <string>


using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::IO;

ref class Map
{


public:
	Map(int x, int y, Bitmap^ zal,Bitmap^ front, const char *mapbin, int startxplayer, int startyplayer)
	{
		X = x;
		Y = y;
		Zal = zal;
		Front = front;
		mapBin = readFileMap(mapbin);
		startxPlayer = startxplayer;
		startyPlayer = startyplayer;
	}

private:
	int X,
		Y,
		column,
		line,
		startxPlayer,
		startyPlayer;
	Bitmap^ Zal;
	Bitmap^ Front;

	
	char** mapBin;

public:

	int getStartxPlayer() {
		return startxPlayer;
	}

	int getStartyPlayer()
	{
		return startyPlayer;
	}

	int getColumn() {
		return column;
	}

	int getLine()
	{
		return line;
	}

	char** readFileMap(const char *name)
	{
		

		std::ifstream file(name);
		char c;

		int x, y;
		file >> x;
	
		file >> y;
		
		
		column = x;
		line = y;

		char** mass = new char*[column];

		for (int i = 0; i < column; i++) mass[i] = new char[line];
		
		
		for (int j = 0; j < line; j++)
		
		{
			for (int i = 0; i < column; i++)
			
			{
			
					file >> mass[i][j];
			}
		}

		file.close();

		return mass;

	}


	Bitmap^ getLocation()
	{
		return Zal;
	}

	void setLocation(Bitmap^ x)
	{
		Zal = x;


	}

	Bitmap^ getFront()
	{
		return Front;
	}

	void setFront(Bitmap^ x)
	{
		Front = x;


	}


	void setMap(char** x)
	{
		mapBin = x;
	}

	char** getMap() { return mapBin; }

	void setX(int x)
	{
		X = x;
	}

	int getX() { return X; }

	void setY(int x)
	{
		Y = x;
	}

	int getY() { return Y; }


	void move(int Direct, int Speed)
	{
		switch (Direct)
		{
		case 1: //âíèç
		{

			Y -= Speed;
			break;
		}
		case 2: //âëåâî
		{

			X += Speed;
			break;
		}
		case 3: //âïðàâî
		{

			X -= Speed;
			break;
		}
		case 4://ââåðõ
		{

			Y += Speed;
			break;
		}
		default:
		{
			break;
		}

		}

	}

	void openDoor(int Direct, int x, int y)
	{
		switch (Direct)
		{
		case 1: //âíèç
		{

			if (mapBin[x][y + 1] == 'd')
				mapBin[x][y + 1] = 'D';
			else if (mapBin[x][y + 1] == 'D')
				mapBin[x][y + 1] = 'd';

			if (mapBin[x][y + 1] == 'r')
				mapBin[x][y + 1] = 'R';
			else if (mapBin[x][y + 1] == 'R')
				mapBin[x][y + 1] = 'r';
			break;

		}
		case 2: //âëåâî
		{


			if (mapBin[x - 1][y] == 'd')
				mapBin[x - 1][y] = 'D';
			else if (mapBin[x - 1][y] == 'D')
				mapBin[x - 1][y ] = 'd';

			if (mapBin[x - 1][y] == 'r')
				mapBin[x - 1][y] = 'R';
			else if (mapBin[x - 1][y] == 'R')
				mapBin[x - 1][y] = 'r';
			break;
		}
		case 3: //âïðàâî
		{

			if (mapBin[x + 1][y] == 'd')
				mapBin[x + 1][y] = 'D';
			else if (mapBin[x + 1][y] == 'D')
				mapBin[x + 1][y ] = 'd';

			if (mapBin[x + 1][y] == 'r')
				mapBin[x + 1][y] = 'R';
			else if (mapBin[x + 1][y] == 'R')
				mapBin[x + 1][y] = 'r';
			break;

		}
		case 4://ââåðõ
		{
			if (mapBin[x][y - 1] == 'd')
				mapBin[x][y - 1] = 'D';
			else if (mapBin[x][y - 1] == 'D')
				mapBin[x][y - 1] = 'd';

			if (mapBin[x][y - 1] == 'r')
				mapBin[x][y - 1] = 'R';
			else if (mapBin[x][y - 1] == 'R')
				mapBin[x][y - 1] = 'r';
			break;
		}
		default:
		{
			break;
		}

		}

	}







};
