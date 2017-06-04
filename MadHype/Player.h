#pragma once


using namespace System::Drawing;

ref class Player
{
	

public:

	Player()
	{

	}


private:
	int Level = 0,
		HP = 50,
		MP = 50,
		X = 8,
		Y = 8,
		XP = 0;
	Bitmap^ persL = gcnew Bitmap(".\\images\\persL.png", true);
	Bitmap^ persR = gcnew Bitmap(".\\images\\persR.png", true);


public:

	Bitmap^ getPersL()
	{
		return persL;
	}

	Bitmap^ getPersR()
	{
		return persR;
	}


	void setLevel(int x)
	{
		Level = x;
	}



	int getLevel() { return Level; }

	void setHP(int x)
	{
		HP = x;
	}

	int getHP() { return HP; }

	void setMP(int x)
	{
		MP = x;
	}

	int getMP() { return MP; }

	void setX(int x)
	{
		this->X = x;
	}

	int getX() { return X; }

	void setY(int x)
	{
		this->Y = x;
	}

	int getY() { return Y; }


	void setXP(int x)
	{
		XP = x;
	}

	int getXP() { return XP; }

	bool checkStop(int Direct, int** Map)
	{
		switch (Direct)
		{
		case 1: //вниз
		{
			if (Map[X][Y + 1] == 1)
				return false;
			break;
		}
		case 2: //влево
		{
			
			if (Map[X - 1][Y] == 1)
				return false;
			break;
		}
		case 3: //вправо
		{
			
			if (Map[X + 1][Y] == 1)
				return false;
			break;
		}
		case 4://вверх
		{
			
			if (Map[X][Y - 1] == 1)
				return false;
			break;
		}

		}
		return true;
	}

	void move(int Direct, int Speed)
	{
		switch (Direct)
		{
		case 1: //вниз
		{


			persL = gcnew Bitmap(".\\images\\persL.png", true);
			persR = gcnew Bitmap(".\\images\\persR.png", true);
				Y += Speed;
			break;
		}
		case 2: //влево
		{
			persL = gcnew Bitmap(".\\images\\persSL.png", true);
			persR = gcnew Bitmap(".\\images\\persSLM.png", true);
				X -= Speed;
			break;
		}
		case 3: //вправо
		{
			persL = gcnew Bitmap(".\\images\\persSR.png", true);
			persR = gcnew Bitmap(".\\images\\persSRM.png", true);
			
				X += Speed;
			break;
		}
		case 4://вверх
		{
			persL = gcnew Bitmap(".\\images\\persBL.png", true);
			persR = gcnew Bitmap(".\\images\\persBR.png", true);
		
				Y -= Speed;
			break;
		}
		default:
		{
			break;
		}

		}

	}







	};



