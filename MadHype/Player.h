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
	int Level, // Текущий уровень
		HP, // Текущее здоровье
		MP, // Текущая мана
		X, // Текущая координата по оси X
		Y, // Текущая координата по оси Y
		XP, // Текущее количество опыта
		XPNeededToLVLUP = 100, // Стартовое значение для получения след. уровня  
		direct; // Текущее направление движения
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

	void setLevel(int x)  //Установка значения текущего уровня
	{
		Level = x;
	}



	int getLevel() { return Level; } //Получение значения текущего уровня

	void setHP(int x) //Установка значения здоровья
	{
		HP = x;
	}

	int getHP() { return HP; } //Получение значения здоровья

	void setMP(int x) //Установка значения маны
	{
		MP = x;
	}

	int getMP() { return MP; } //Получение значения маны

	void setX(int x) //Установка текущей координаты X
	{
		X = x;
	}

	int getX() { return X; } //Получение текущей координаты X

	void setY(int x) //Установка текущей координаты Y
	{
		this->Y = x;
	}

	int getY() { return Y; } //Получение текущей координаты X


	void setXP(int x) //Установка текущего значения опыта
	{
		XP = x;
	}



	int getXP() { return XP; } //Получение текущего значения опыта


	void setXPNeededToLVLUP(int x) //Установка значения опыта, необходимого для перехода на новый уровень
	{
		XPNeededToLVLUP = x;
	}

	int getXPNeededToLVLUP() { return XPNeededToLVLUP; } //Получение значения опыта, необходимого для перехода на новый уровень



	int getDirect() //Получение значения направления движения
	{
		return direct;
	}

	bool checkStop(int Direct, char** Map) //Проверка остановки персонажа
	{


		switch (Direct)
		{
		case 1: //вниз
		{
			if (Map[X][Y + 1] == 'w' || Map[X][Y + 1] == 'd' || Map[X][Y + 1] == 'r')
				return false;
			break;

		}
		case 2: //влево
		{

			if (Map[X - 1][Y] == 'w' || Map[X - 1][Y] == 'd' || Map[X - 1][Y] == 'r')
				return false;
			break;
		}
		case 3: //вправо
		{

			if (Map[X + 1][Y] == 'w' || Map[X + 1][Y] == 'd' || Map[X + 1][Y] == 'r')
				return false;
			break;
		}
		case 4://вверх
		{

			if (Map[X][Y - 1] == 'w' || Map[X][Y - 1] == 'd' || Map[X][Y - 1] == 'r')
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

	void rotation(int Direct) //Поворот модели игрока в зависимости от направления движения
	{
		switch (Direct)
		{
		case 1: //вниз
		{


			setPersL(gcnew Bitmap(".\\images\\pers\\persL.png", true));
			setPersR(gcnew Bitmap(".\\images\\pers\\persR.png", true));
			direct = 1;
			break;


		}
		case 2: //влево
		{
			setPersL(gcnew Bitmap(".\\images\\pers\\persSL.png", true));
			setPersR(gcnew Bitmap(".\\images\\pers\\persSLM.png", true));
			direct = 2;

			break;
		}
		case 3: //вправо
		{
			setPersL(gcnew Bitmap(".\\images\\pers\\persSR.png", true));
			setPersR(gcnew Bitmap(".\\images\\pers\\persSRM.png", true));
			direct = 3;

			break;
		}
		case 4: //вверх
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

	void move(int Direct, int Speed) //Передвижение игрока по карте в зависимости от его скорости и направления движения
	{
		switch (Direct)
		{
		case 1: //вниз
		{
			Y += Speed;
			break;
		}
		case 2: //влево
		{
			X -= Speed;
			break;
		}
		case 3: //вправо
		{
			X += Speed;
			break;
		}
		case 4://вверх
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