#pragma once
#include "Settings.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace MadHype {

	/// <summary>
	/// Сводка для StartMenul
	/// </summary>
	public ref class StartMenu : public System::Windows::Forms::UserControl
	{
	public:
		StartMenu(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~StartMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  Play;
	private: System::Windows::Forms::Panel^  panel1;
	public: System::Windows::Forms::Label^  Exit;
	private:
	public:

	private:
	public: System::Windows::Forms::Label^  Settings;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Play = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Exit = (gcnew System::Windows::Forms::Label());
			this->Settings = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Play
			// 
			this->Play->AutoSize = true;
			this->Play->Font = (gcnew System::Drawing::Font(L"DS Pixel Cyr", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Play->ForeColor = System::Drawing::Color::Black;
			this->Play->Location = System::Drawing::Point(47, 0);
			this->Play->Name = L"Play";
			this->Play->Size = System::Drawing::Size(198, 54);
			this->Play->TabIndex = 0;
			this->Play->Text = L"Играть";
			this->Play->Click += gcnew System::EventHandler(this, &StartMenu::Play_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel1->Controls->Add(this->Exit);
			this->panel1->Controls->Add(this->Settings);
			this->panel1->Controls->Add(this->Play);
			this->panel1->Location = System::Drawing::Point(374, 393);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(283, 165);
			this->panel1->TabIndex = 1;
			// 
			// Exit
			// 
			this->Exit->AutoSize = true;
			this->Exit->Font = (gcnew System::Drawing::Font(L"DS Pixel Cyr", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Exit->ForeColor = System::Drawing::Color::Black;
			this->Exit->Location = System::Drawing::Point(52, 108);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(193, 54);
			this->Exit->TabIndex = 2;
			this->Exit->Text = L"Выход";
			this->Exit->Click += gcnew System::EventHandler(this, &StartMenu::Exit_Click);
			// 
			// Settings
			// 
			this->Settings->AutoSize = true;
			this->Settings->Font = (gcnew System::Drawing::Font(L"DS Pixel Cyr", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Settings->ForeColor = System::Drawing::Color::Black;
			this->Settings->Location = System::Drawing::Point(3, 54);
			this->Settings->Name = L"Settings";
			this->Settings->Size = System::Drawing::Size(289, 54);
			this->Settings->TabIndex = 1;
			this->Settings->Text = L"Настройки";
			this->Settings->Click += gcnew System::EventHandler(this, &StartMenu::Settings_Click);
			// 
			// StartMenu
			// 
			this->BackColor = System::Drawing::Color::White;
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(0);
			this->Name = L"StartMenu";
			this->Size = System::Drawing::Size(1024, 1024);
			this->Load += gcnew System::EventHandler(this, &StartMenu::StartMenu_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	public:
		bool gameLife = false;

	public: bool GameLife()
		{
			return gameLife;
		}
	
	private: System::Void Play_Click(System::Object^  sender, System::EventArgs^  e) {

		gameLife = true;
		this->DestroyHandle();
	}
			 
	private: System::Void Settings_Click(System::Object^  sender, System::EventArgs^  e) {
		
		this->DestroyHandle();

	}

	private: System::Void Exit_Click(System::Object^  sender, System::EventArgs^  e) {

		Application::Exit();
}
private: System::Void StartMenu_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
