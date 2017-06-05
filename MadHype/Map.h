#pragma once

#include "resource.h"


using namespace System;
using namespace System::Drawing;


ref class Map
{
	

public:
	Map(int x, int y, Bitmap^ zal)
	{
		X = x;
		Y = y;
		Zal = zal;
		
	}

private:
	int X,
		Y;
	Bitmap^ Zal;

	int** mapBin;

	

public:



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
		case 1: //вниз
		{
		
				Y -= Speed;
			break;
		}
		case 2: //влево
		{
		
				X += Speed;
			break;
		}
		case 3: //вправо
		{
			
				X -= Speed;
			break;
		}
		case 4://вверх
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




};

