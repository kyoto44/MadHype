#pragma once

using namespace System::Drawing;

ref class Map
{
public:
	Map()
	{
	}

private:
	int X = 0,
		Y = 0;
	Bitmap^ zal = gcnew Bitmap(".\\images\\Location.png", true);

	int** map;

public:



	Bitmap^ getLocation()
	{
		return zal;
	}


	void setMap(int** x)
	{
		map = x;
	}

	int** getMap() { return map; }

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




};

