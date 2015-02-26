#pragma once

#include "Cell.h"
#include "ReadFile.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		Graphics^g;
		Pen^blackPen;
		array<Cell^>^ world;
		ReadFile *reader;

	private: System::Windows::Forms::Panel^  panel1;

			 Bitmap^ Karel = gcnew Bitmap("Karel.bmp");
			 Bitmap^ beeper = gcnew Bitmap("beeper.bmp");

	private: System::Windows::Forms::Label^  label_num;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label_num = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(53, 40);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(569, 436);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// label_num
			// 
			this->label_num->AutoSize = true;
			this->label_num->Location = System::Drawing::Point(127, 511);
			this->label_num->Name = L"label_num";
			this->label_num->Size = System::Drawing::Size(249, 20);
			this->label_num->TabIndex = 1;
			this->label_num->Text = L"Number of Beepers in Karel\'s bag:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(770, 564);
			this->Controls->Add(this->label_num);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"Karel The Robot";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 
	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 g = panel1->CreateGraphics();
				 //blackPen = gcnew System::Drawing::Pen(Color::Black);

				 

	}

	

	};
}
