#pragma once


#include <fstream>


using namespace System;
using namespace System::Drawing;


ref class Map
{
	

public:
	Map(int x, int y, Bitmap^ zal, const char *mapbin)
	{
		X = x;
		Y = y;
		Zal = zal;
		mapBin = readFileMap(mapbin);
	}

private:
	int X,
		Y,
		column,
		line;
		;
	Bitmap^ Zal;

	int** mapBin;

public:

	int getColumn() {
		return column;
	}

	int getLine()
	{
		return line;
	}

	int** readFileMap(const char *name)		
	{


		std::ifstream file;

		file.open(name);

		int x, y;
		file >> x;
		
		file >> y;

		column = x;
		line = y;

		int** mass = new int*[x];

		for (int i = 0; i < x; i++) mass[i] = new int[y];

		for (int j = 0; j < y; j++)
		{
			for (int i = 0; i < x; i++)
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


	void setMap(int** x)
	{
		mapBin = x;
	}

	int** getMap() { return mapBin; }

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
		case 1: //����
		{
		
				Y -= Speed;
			break;
		}
		case 2: //�����
		{
		
				X += Speed;
			break;
		}
		case 3: //������
		{
			
				X -= Speed;
			break;
		}
		case 4://�����
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

	void openDoor(int Direct,int x, int y)
	{
		switch (Direct)
		{
		case 1: //����
		{
			
			if (mapBin[x][y + 1] == 2)
				mapBin[x][y + 1] = -2;
			else if (mapBin[x][y + 1] == -2)
				mapBin[x][y + 1] = 2;
			break;
			
		}
		case 2: //�����
		{

			if (mapBin[x - 1][y] == 2)
				mapBin[x - 1][y] = -2;
			else if (mapBin[x - 1][y] == -2)
				mapBin[x - 1][y] = 2;
			break;
		}
		case 3: //������
		{

			if (mapBin[x + 1][y] == 2)
				mapBin[x + 1][y] = -2;
			else if (mapBin[x + 1][y] == -2)
				mapBin[x + 1][y] = 2;

			 
			break;
		}
		case 4://�����
		{
			if (mapBin[x][y - 1] == 2)
				mapBin[x][y - 1] = -2;
			else if (mapBin[x][y - 1] == -2)
				mapBin[x][y - 1] = 2;
			break;
		}
		default:
		{
			break;
		}

		}

	}







};

