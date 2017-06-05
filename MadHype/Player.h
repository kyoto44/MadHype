#pragma once


using namespace System::Drawing;


ref class Player
{
	
public:
	Player(int level, int hp, int mp, int x, int y, int xp,Bitmap^ persl, Bitmap^ persr)
	{
		Level = level;
		HP = hp;
		MP = mp;
		X = x;
		Y = y;
		XP = xp;
		persL = persl;
		persR = persr;
	}

private:
	int Level,
		HP,	
		MP,
		X,
		Y,
		XP;
	Bitmap^ persL;
	Bitmap^ persR;



public:

	Bitmap^ getPersL()
	{
		return persL;
	}

	Bitmap^ getPersR()
	{
		return persR;
	}

	void setPersL(Bitmap^ x)
	{
		persL = x;
	}

	void setPersR(Bitmap^ x)
	{
		persR = x;
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
		default:
		{
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


			setPersL( gcnew Bitmap(".\\images\\persL.png", true));
			setPersR(gcnew Bitmap(".\\images\\persR.png", true));
			Y += Speed;
			break;

			
		}
		case 2: //влево
		{
			setPersL(gcnew Bitmap(".\\images\\persSL.png",true));
			setPersR (gcnew Bitmap(".\\images\\persSLM.png", true));
			X -= Speed;
			break;
		}
		case 3: //вправо
		{
			setPersL(gcnew Bitmap(".\\images\\persSR.png", true));
			setPersR(gcnew Bitmap(".\\images\\persSRM.png", true));
			
			X += Speed;
			break;
		}
		case 4://вверх
		{
			setPersL (gcnew Bitmap(".\\images\\persBL.png", true));
			setPersR (gcnew Bitmap(".\\images\\persBR.png", true));

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



