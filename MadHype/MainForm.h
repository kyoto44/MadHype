#pragma once

#include "Game.h"
#include "StartMenu.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace MadHype {

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	static ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
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
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>

	private:
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1024, 1024);
			this->DoubleBuffered = true;
			this->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->KeyPreview = true;
			this->Name = L"MainForm";
			this->Text = L"MadHype";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
			this->ResumeLayout(false);

		}
	public:
		
		Game^ game = gcnew Game();
		Settings^ settings = gcnew Settings();

	private:
#pragma endregion
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {

		
		

		
		
		StartMenu^ startmenu = gcnew StartMenu(game,settings);
		
		startmenu->Parent = this;
		
		
		
		

	}



	
	private: System::Void MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		/*
		if (e->KeyValue == VK_DOWN)
		{

			game->setArrow(1);
		}
		if (e->KeyValue == VK_LEFT)
		{
			game->setArrow(2);
		}

		if (e->KeyValue == VK_RIGHT)
		{

			game->setArrow(3);
		}

		if (e->KeyValue == VK_UP)
		{

			game->setArrow(4);
		}
		*/
	}
	private: System::Void MainForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	

		/*
		if (e->KeyValue == VK_DOWN)
		{
			// y+=8;
			game->setArrow(0);
		}
		if (e->KeyValue == VK_LEFT)
		{
			//x-=8;
			game->setArrow(0);
		}
		if (e->KeyValue == VK_RIGHT)
		{
			//x+=8;
			game->setArrow(0);
		}

		if (e->KeyValue == VK_UP)
		{
			//y-=8;
			game->setArrow(0);
		}

		if (e->KeyValue == VK_SPACE)
		{
			game->maps[game->numMap]->openDoor(game->player->getDirect(), game->player->getX(), game->player->getY());

		}
		*/
	}
};
}
