#pragma once


#include <windows.h>
#include <ctime> 
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include <fstream>
#include "StartMenu.h"

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
			InitializeMyComponent();
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



	private: StartMenu^ startmenu = gcnew StartMenu();

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
			 /// содержимое этого метода с помощью редактора кода.
			 /// </summary>
			 void InitializeMyComponent(void)
			 {
				 this->startmenu = gcnew StartMenu();
				 this->Controls->Add(startmenu);

			 }
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
				 this->ClientSize = System::Drawing::Size(1014, 994);
				 this->DoubleBuffered = true;
				 this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(204)));
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				 this->Name = L"Game";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"Game";
				 this->Load += gcnew System::EventHandler(this, &Game::Form1_Load);
				 this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Form1_KeyDown);
				 this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Game::Form1_KeyPress);
				 this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Form1_KeyUp);
				 this->ResumeLayout(false);

			 }
			 
	public: 
			  System::Drawing::Font^ osmain = gcnew System::Drawing::Font("DS Pixel Cyr", 35.00F, FontStyle::Regular);

			  Bitmap^ closeDoor = gcnew Bitmap(".\\images\\doors\\closedoor.png", true);

			  Bitmap^ openDoor = gcnew Bitmap(".\\images\\doors\\opendoor.png", true);

			 

			  int arrow = 0, timeChangeSpriteOfPlayer = 0;

			  bool flagChangeSpriteOfPlayer = true;
			  			
			  Map^ map = gcnew Map(0,0, gcnew Bitmap(".\\images\\Locations\\Location.png", true));

			  Player^ player = gcnew Player(1, 100, 100, 8, 8, 0, gcnew Bitmap(".\\images\\pers\\persL.png", true), gcnew Bitmap(".\\images\\pers\\persR.png", true));

			  

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

		this->backgroundWorker1->WorkerReportsProgress = true;
		this->backgroundWorker1->RunWorkerAsync();

		
		
		map->setMap(map->readFileMap(".\\maps\\mapZal.txt"));



	}

	

	protected:
		virtual void OnPaint(PaintEventArgs^ e) override
		{
			e->Graphics->DrawImageUnscaled(map->getLocation(), map->getX(), map->getY());
			
			
			for (int i = 0; i < map->getLine(); i++)
			{
				for (int j = 0; j < map->getColumn(); j++)
				{
					if (map->getMap()[i][j] == 2)
					{
						e->Graphics->DrawImageUnscaled(closeDoor, i * 64 + map->getX(), j * 64 - 28 + map->getY());
					}
					else if (map->getMap()[i][j] == 3)
					{
						e->Graphics->DrawImageUnscaled(openDoor, i * 64 + map->getX(), j * 64 - 28  + map->getY());
					}
				}
			}
			

			if (flagChangeSpriteOfPlayer)
			{
				e->Graphics->DrawImage(player->getPersL(), this->Width/2, this->Width / 2,this->Width/16, this->Width / 16);

			}
			else
			{
				e->Graphics->DrawImage(player->getPersR(), this->Width / 2, this->Width / 2, this->Width / 16, this->Width / 16);

			}

			
		

			e->Graphics->DrawString(Convert::ToString(player->getX()), osmain, gcnew SolidBrush(Color::Black), 0, 0);
			e->Graphics->DrawString(Convert::ToString(player->getY()), osmain, gcnew SolidBrush(Color::Black), 100, 0);
			e->Graphics->DrawString(Convert::ToString(player->getHP()), osmain, gcnew SolidBrush(Color::Red), 825, 0);
			e->Graphics->DrawString(Convert::ToString(player->getMP()), osmain, gcnew SolidBrush(Color::Blue), 900, 0);
			e->Graphics->DrawString(Convert::ToString(player->getLevel()), osmain, gcnew SolidBrush(Color::Yellow), 975, 0);
			e->Graphics->DrawString(Convert::ToString(player->getXP()), osmain, gcnew SolidBrush(Color::Yellow), 875, 50);
			e->Graphics->DrawString("I", osmain, gcnew SolidBrush(Color::Yellow), 910, 50);
			e->Graphics->DrawString(Convert::ToString(player->getXPNeededToLVLUP()), osmain, gcnew SolidBrush(Color::Yellow), 930, 50);


			if (timeChangeSpriteOfPlayer == 20)
			{

				flagChangeSpriteOfPlayer = !flagChangeSpriteOfPlayer;

				timeChangeSpriteOfPlayer = 0;
			}
			else
				timeChangeSpriteOfPlayer++;
		}

#pragma endregion
	private: System::Void Tick(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

		while (true)
		{
			bool gameLife = startmenu->GameLife();
			
			while (gameLife)
			{		
				
				if (player->getXP() > player->getXPNeededToLVLUP())
				{
					player->setXP(0);
					player->setXPNeededToLVLUP(player->getXPNeededToLVLUP() + 100);
				}

				int direct = arrow;
				player->rotation(direct);
				if (player->checkStop(direct, map->getMap()))
				{
					player->move(direct, 1);
					for (int i = 0; i < this->Width / 16; i++)
					{
						map->move(direct, 1);
						Sleep(5);
						this->Invalidate();
					}

				}


				this->Invalidate();
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
			map->openDoor(player->getDirect(), player->getX(), player->getY());

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
