#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace MadHype {

	/// <summary>
	/// ������ ��� StartMenul
	/// </summary>
	public ref class StartMenu : public System::Windows::Forms::UserControl
	{
	public:
		StartMenu(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~StartMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  Play;
	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Play = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Play
			// 
			this->Play->AutoSize = true;
			this->Play->Font = (gcnew System::Drawing::Font(L"DS Pixel Cyr", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Play->Location = System::Drawing::Point(128, 60);
			this->Play->Name = L"Play";
			this->Play->Size = System::Drawing::Size(164, 44);
			this->Play->TabIndex = 0;
			this->Play->Text = L"������";
			this->Play->Click += gcnew System::EventHandler(this, &StartMenu::Play_Click);
			
			// 
			// StartMenu
			// 
			this->BackColor = System::Drawing::Color::White;
			this->Controls->Add(this->Play);
			this->Location = System::Drawing::Point(10, 10);
			this->Name = L"StartMenu";
			this->Size = System::Drawing::Size(423, 315);
			this->ResumeLayout(false);
			this->PerformLayout();

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

	};
}
