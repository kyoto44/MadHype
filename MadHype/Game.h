#pragma once


#include <windows.h>
#include < ctime > 
#include "Math.h"
#include "resource.h"
#include <conio.h>
#include <string>
#include <tchar.h>
#include <mmsystem.h>
#include <fstream>

namespace MadHype {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Collections::Generic;
	using namespace System::Configuration;
	using namespace System::Media;

	/// <summary>
	/// —водка дл€ Game
	/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{
	public:
		Game(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Game()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;

	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Game::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &Game::backgroundWorker1_ProgressChanged);
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1018, 999);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Game";
			this->Text = L"Game";
			this->Load += gcnew System::EventHandler(this, &Game::Form1_Load);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Game::Form1_KeyPress);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Form1_KeyUp);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Form1_KeyDown);
			this->ResumeLayout(false);

		}

		static Bitmap^ persL = gcnew Bitmap(".\\images\\persL.png", true);
		static Bitmap^ persR = gcnew Bitmap(".\\images\\persR.png", true);
		static Bitmap^ stenZ = gcnew Bitmap(".\\images\\stenZ.png", true);
		static Bitmap^ zal = gcnew Bitmap(".\\images\\Location.png", true);
		static System::Drawing::Font^ osmain = gcnew System::Drawing::Font("DS Pixel Cyr", 50.00F, FontStyle::Regular);

		static Bitmap^ door = gcnew Bitmap(".\\images\\door.png", true);

		static List <Bitmap ^> ^pers = pers = gcnew List <Bitmap ^>();
		static int** s = new int*[16];

		static int x = 1024 / 2, y = 1024 / 2, arrow = 0, sx = 8, sy = 8, zalX = 0, zalY = 0, a = 0;
		static bool flag = true;


		//static System::Drawing::FontFamily^ fntFamily = gcnew System::Drawing::FontFamily("Times New Roman");
		//static System::Drawing::Font^ osmain = gcnew System::Drawing::Font(fntFamily, 20.00F, FontStyle::Regular);


	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		this->backgroundWorker1->WorkerReportsProgress = true;
		this->backgroundWorker1->RunWorkerAsync();

		for (int i = 0; i < 16; i++) s[i] = new int[16];

		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{

				s[i][j] = 0;
				if (j == 1 || j == 14)
					s[i][j] = 1;
				if (i == 1 || i == 14)
					s[i][j] = 1;
			}

		}

		s[16][10] = 2;



	}

	protected:
		virtual void OnPaint(PaintEventArgs^ e) override
		{
			e->Graphics->DrawImageUnscaled(zal, zalX, zalY);
			e->Graphics->DrawImageUnscaled(door, zalX + 1024 - 64, zalY + 640);


			if (flag)
			{
				e->Graphics->DrawImage(persL, x, y, this->Width / 16, this->Width / 16);

			}
			else
			{
				e->Graphics->DrawImage(persR, x, y, this->Width / 16, this->Width / 16);

			}



			e->Graphics->DrawString(Convert::ToString(sx), osmain, gcnew SolidBrush(Color::Black), 0, 0);

			e->Graphics->DrawString(Convert::ToString(sy), osmain, gcnew SolidBrush(Color::Black), 100, 0);


			if (a == 20)
			{
				if (flag)
					flag = false;
				else
					flag = true;
				a = 0;
			}
			else
				a++;


		}

#pragma endregion
	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {


		while (true)
		{



			switch (arrow)
			{
			case 1: //вниз
			{
				persL = gcnew Bitmap(".\\images\\persL.png", true);
				persR = gcnew Bitmap(".\\images\\persR.png", true);
				if (s[sx][sy + 1] == 0)
				{
					//y+=this->Width/16;
					sy++;
					for (int i = 0; i < this->Width / 16; i++)
					{
						zalY--;
						Sleep(5);
						this->Invalidate();
					}


					//zalY-=this->Width/16;

				}
				break;
			}
			case 2: //влево
			{
				persL = gcnew Bitmap(".\\images\\persSL.png", true);
				persR = gcnew Bitmap(".\\images\\persSLM.png", true);

				if (s[sx - 1][sy] == 0)
				{
					//x-=this->Width/16;
					sx--;
					for (int i = 0; i < this->Width / 16; i++)
					{
						zalX++;
						Sleep(5);
						this->Invalidate();
					}
					//zalX+=this->Width/16;


				}
				break;
			}
			case 3: //вправо
			{
				persL = gcnew Bitmap(".\\images\\persSR.png", true);
				persR = gcnew Bitmap(".\\images\\persSRM.png", true);
				if (s[sx + 1][sy] == 0)
				{
					//x+=this->Width/16;
					sx++;
					for (int i = 0; i < this->Width / 16; i++)
					{
						zalX--;
						Sleep(5);
						this->Invalidate();
					}
					//zalX-=this->Width/16;

				}
				break;
			}
			case 4://вверх
			{
				persL = gcnew Bitmap(".\\images\\persBL.png", true);
				persR = gcnew Bitmap(".\\images\\persBR.png", true);
				if (s[sx][sy - 1] == 0)
				{
					//y-=this->Width/16;
					sy--;

					for (int i = 0; i < this->Width / 16; i++)
					{
						zalY++;
						Sleep(5);
						this->Invalidate();
					}

					//zalY+=this->Width/16;

				}
				break;
			}
			default:
			{
				Sleep(5);
				this->Invalidate();
				break;
			}
			}

		}

	}
	private: System::Void Form1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {


	}
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {


		if (e->KeyValue == VK_DOWN)
		{
			// y+=8;
			arrow = 1;
		}
		if (e->KeyValue == VK_LEFT)
		{
			//x-=8;
			arrow = 2;
		}
		if (e->KeyValue == VK_RIGHT)
		{
			//x+=8;
			arrow = 3;
		}

		if (e->KeyValue == VK_UP)
		{
			//y-=8;
			arrow = 4;
		}

		if (e->KeyValue == VK_SPACE)
		{

		}

	}

	private: System::Void backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {

	}
	private: System::Void Form1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyValue == VK_DOWN)
		{
			// y+=8;
			arrow = 0;
		}
		if (e->KeyValue == VK_LEFT)
		{
			//x-=8;
			arrow = 0;
		}
		if (e->KeyValue == VK_RIGHT)
		{
			//x+=8;
			arrow = 0;
		}

		if (e->KeyValue == VK_UP)
		{
			//y-=8;
			arrow = 0;
		}
	}

	};
}

