#pragma once


#include <windows.h>
#include < ctime > 
#include "Player.h"
#include "Enemy.h"
#include "Map.h"

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
				 this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Game::Tick);
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
			 
			 static System::Drawing::Font^ osmain = gcnew System::Drawing::Font("DS Pixel Cyr", 50.00F, FontStyle::Regular);

			 static Bitmap^ door = gcnew Bitmap(".\\images\\door.png", true);


			 static int** x = new int*[16];

			 static int arrow = 0, a = 0;
			 static bool flag = true;

			 static Player player;
			 static Map map;





	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		this->backgroundWorker1->WorkerReportsProgress = true;
		this->backgroundWorker1->RunWorkerAsync();

		
		for (int i = 0; i < 16; i++) x[i] = new int[16];

		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{

				x[i][j] = 0;
				if (j == 1 || j == 14)
					x[i][j] = 1;
				if (i == 1 || i == 14)
					x[i][j] = 1;
			}

		}

		map.setMap(x); 

	}

	protected:
		virtual void OnPaint(PaintEventArgs^ e) override
		{
			e->Graphics->DrawImageUnscaled(map.getLocation(), map.getX(), map.getY());
		


			if (flag)
			{
				e->Graphics->DrawImage(player.getPersL(), this->Width/2, this->Width / 2, this->Width / 16, this->Width / 16);

			}
			else
			{
				e->Graphics->DrawImage(player.getPersR(), this->Width / 2, this->Width / 2, this->Width / 16, this->Width / 16);

			}



			e->Graphics->DrawString(Convert::ToString(player.getX()), osmain, gcnew SolidBrush(Color::Black), 0, 0);

			e->Graphics->DrawString(Convert::ToString(player.getY()), osmain, gcnew SolidBrush(Color::Black), 100, 0);


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
	private: System::Void Tick(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {


		while (true)
		{
			int direct = arrow;
			

			
			
			if (player.checkStop(direct, map.getMap()))
			{
				player.move(direct, 1);
				for (int i = 0; i < this->Width / 16; i++)
				{
					map.move(direct, 1);
					Sleep(5);
					this->Invalidate();
				}

			}


			

		}

	}

	private: System::Void backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) 
	 {

	 }
	private: System::Void Form1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {


	}
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {


		if (e->KeyValue == VK_DOWN)
		{
			
			arrow = 1;
		}
		if (e->KeyValue == VK_LEFT)
		{	
			arrow = 2;
		}

		if (e->KeyValue == VK_RIGHT)
		{
			
			arrow = 3;
		}

		if (e->KeyValue == VK_UP)
		{
			
			arrow = 4;
		}

		if (e->KeyValue == VK_SPACE)
		{

		}

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
