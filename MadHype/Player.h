#pragma once


using namespace System::Drawing;


ref class Player
{

public:
	Player(int level, int hp, int mp, int x, int y, int xp, Bitmap^ persl, Bitmap^ persr)
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
		XP,
		XPNeededToLVLUP = 100,
		direct;
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
		X = x;
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


	void setXPNeededToLVLUP(int x)
	{
		XPNeededToLVLUP = x;
	}

	int getXPNeededToLVLUP() { return XPNeededToLVLUP; }



	int getDirect()
	{
		return direct;
	}

	bool checkStop(int Direct, char** Map)
	{


		switch (Direct)
		{
		case 1: //âíèç
		{
			if (Map[X][Y + 1] == 'w' || Map[X][Y + 1] == 'd')
				return false;
			break;

		}
		case 2: //âëåâî
		{

			if (Map[X - 1][Y] == 'w' || Map[X - 1][Y] == 'd')
				return false;
			break;
		}
		case 3: //âïðàâî
		{

			if (Map[X + 1][Y] == 'w' || Map[X + 1][Y] == 'd')
				return false;
			break;
		}
		case 4://ââåðõ
		{

			if (Map[X][Y - 1] == 'w' || Map[X][Y - 1] == 'd')
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

	void rotation(int Direct)
	{
		switch (Direct)
		{
		case 1: //âíèç
		{


			setPersL(gcnew Bitmap(".\\images\\pers\\persL.png", true));
			setPersR(gcnew Bitmap(".\\images\\pers\\persR.png", true));
			direct = 1;
			break;


		}
		case 2: //âëåâî
		{
			setPersL(gcnew Bitmap(".\\images\\pers\\persSL.png", true));
			setPersR(gcnew Bitmap(".\\images\\pers\\persSLM.png", true));
			direct = 2;

			break;
		}
		case 3: //âïðàâî
		{
			setPersL(gcnew Bitmap(".\\images\\pers\\persSR.png", true));
			setPersR(gcnew Bitmap(".\\images\\pers\\persSRM.png", true));
			direct = 3;

			break;
		}
		case 4://ââåðõ
		{
			setPersL(gcnew Bitmap(".\\images\\pers\\persBL.png", true));
			setPersR(gcnew Bitmap(".\\images\\pers\\persBR.png", true));
			direct = 4;

			break;
		}
		default:
		{
			break;
		}
		}
	}

	void move(int Direct, int Speed)
	{
		switch (Direct)
		{
		case 1: //âíèç
		{
			Y += Speed;
			break;
		}
		case 2: //âëåâî
		{
			X -= Speed;
			break;
		}
		case 3: //âïðàâî
		{
			X += Speed;
			break;
		}
		case 4://ââåðõ
		{
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