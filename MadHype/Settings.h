#include "SDL.h"
#include "SDL_mixer.h"

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace MadHype {

	/// <summary>
	/// Сводка для Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::UserControl
	{
	public:
		Settings(void)
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
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	public: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	public: System::Windows::Forms::Label^  label2;
	public: System::Windows::Forms::Label^  label3;
	private:
	public:
	private:
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->trackBar1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(102, 187);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(860, 325);
			this->panel1->TabIndex = 0;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(559, 146);
			this->trackBar1->Maximum = 4;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(213, 45);
			this->trackBar1->TabIndex = 5;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Settings::trackBar1_Scroll);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"DS Pixel Cyr", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(33, 126);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(456, 54);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Громкость звука";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(698, 68);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 3;
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Settings::checkBox1_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"DS Pixel Cyr", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(33, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(592, 54);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Полноэкранный режим";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"DS Pixel Cyr", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(310, 859);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(381, 54);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Назад в меню";
			this->label3->Click += gcnew System::EventHandler(this, &Settings::label3_Click);
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel1);
			this->Name = L"Settings";
			this->Size = System::Drawing::Size(1024, 1024);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {



		if (trackBar1->Value == 0) { Mix_VolumeMusic(20); }
		if (trackBar1->Value == 1) { Mix_VolumeMusic(40); }
		if (trackBar1->Value == 2) { Mix_VolumeMusic(60); }
		if (trackBar1->Value == 3) { Mix_VolumeMusic(80); }
		if (trackBar1->Value == 4) { Mix_VolumeMusic(100); }
	}


public:
	bool openMenu = false;

	public: bool OpenMenu()
	{
		return openMenu;
	}

private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {



	this->DestroyHandle();


}
public:
	bool fullscreen = false;

	public: bool Fullscreen()
	{
		return fullscreen;
	}

private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if(checkBox1->Checked) {
		bool fullscreen = true;
	}
	else { bool fullscreen = false; }

}
};
}
