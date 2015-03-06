#pragma once

#include "Karel.h"
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

		Graphics ^g , ^gBuff;
		Bitmap ^buffImg;
		Pen^blackPen;
		Karel ^k;
		array<Cell^, 2>^ world;
		ReadFile *reader;
		char **commands;



			 Bitmap^ ka = gcnew Bitmap("Karel.bmp");
			 Bitmap^ beeper = gcnew Bitmap("beeper.bmp");
			 Bitmap^ beeper2 = gcnew Bitmap("beeper2.bmp");
			 Bitmap^ beeper3 = gcnew Bitmap("beeper3.bmp");


	private: System::Windows::Forms::Label^  label_num;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel1;

	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label_num = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// label_num
			// 
			this->label_num->AutoSize = true;
			this->label_num->Location = System::Drawing::Point(61, 477);
			this->label_num->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_num->Name = L"label_num";
			this->label_num->Size = System::Drawing::Size(167, 13);
			this->label_num->TabIndex = 1;
			this->label_num->Text = L"Number of Beepers in Karel\'s bag:";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(35, 26);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(400, 400);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(559, 515);
			this->Controls->Add(this->label_num);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"Karel The Robot";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		int WORLD_WIDTH, WORLD_HEIGHT, commandLine = 0, cellWidth, cellHeight, num_commands;
	
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 
				 initVariables();	 
	}

	private: System::Void initVariables(){
				 reader = new ReadFile();
				 commands = reader->parseCommandFile();

				 g = panel1->CreateGraphics();
				 buffImg = gcnew Bitmap(panel1->Width, panel1->Height, Imaging::PixelFormat::Format32bppArgb);
				 gBuff = Graphics::FromImage(buffImg);
				 blackPen = gcnew System::Drawing::Pen(Color::Black);

				 //used for for loops
				 num_commands = reader->getNumCommands();
				 int num_args = 5;
				 //bool firstCycle = true;

				 for (int loop = 0; loop < num_commands; loop++){
					 if (tolower(commands[loop][0]) == 'w'){
						 WORLD_WIDTH = commands[loop][1] - '0';
						 WORLD_HEIGHT = commands[loop][2] - '0';
					 }
					 /*
					 //Finds the first command for Karel to run and starts there
					 if (firstCycle){
						 if (tolower(commands[loop][0]) == 'm' ||
							 tolower(commands[loop][0]) == 't' ||
							 tolower(commands[loop][0]) == 'k' ||
							 tolower(commands[loop][0]) == 'p' ||
							 tolower(commands[loop][0]) == 'o'){

							 if (firstCycle){
								 commandLine = loop;
							 }
							 firstCycle = false;
						 }
					 }*/
				 }

				 world = gcnew array<Cell^, 2>(WORLD_WIDTH, WORLD_HEIGHT);

				 cellWidth = panel1->Width / WORLD_WIDTH;
				 cellHeight = panel1->Height / WORLD_HEIGHT;

				 for (int x = 0; x < WORLD_WIDTH; x++){
					 for (int y = 0; y < WORLD_HEIGHT; y++){
						 world[x, y] = gcnew Cell(x,y);
					 }
				 }

				 for (int c = 0; c < num_commands; c++){
					 for (int a = 0; a < num_args; a++){
						 if (commands[c][a] == 'l'){
							 world[commands[c][a + 1] - '0', commands[c][a + 2] - '0']->setWall(commands[c][a + 3] - '0');
						 }
						 else if (commands[c][a] == 'b'){
							 world[commands[c][a + 1] - '0', commands[c][a + 2] - '0']->setBeeper((int)(commands[c][a + 3] - '0'));
						 }
						 else if (commands[c][a] == 'r'){
							 k = gcnew Karel(commands[c][a + 1] - '0', commands[c][a + 2] - '0', commands[c][a + 3] - '0', commands[c][a + 4] - '0');
						 }
						 
					 }
				 }
	}

	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				//Don't Use 
	}

			 private: System::Void drawWorld(){
						  for (int x = 0; x < WORLD_HEIGHT; x++){
							  for (int y = 0; y < WORLD_WIDTH; y++){

								  Rectangle ^r = gcnew Rectangle();
								  r->X = x * cellWidth;
								  r->Y = y * cellHeight;
								  r->Width = cellWidth;
								  r->Height = cellHeight;

								  if (k->get_x() == x && k->get_y() == y)
									  world[x, y]->DrawCell(gBuff, r, ka);
								  else if (world[x, y]->getBeepers() == 1)
									  world[x, y]->DrawCell(gBuff, r, beeper);
								  else if (world[x, y]->getBeepers() == 2)
									  world[x, y]->DrawCell(gBuff, r, beeper2);
								  else if (world[x, y]->getBeepers() == 3)
									  world[x, y]->DrawCell(gBuff, r, beeper3);
								  else
									  world[x, y]->DrawCell(gBuff, r);

							  }
						  }
						  panel1->Refresh();
						  g->DrawImage(buffImg, Point(0, 0));
						  clearBuffer();
						  
			 }

	private: System::Void clearBuffer(){
				 gBuff->FillRectangle(gcnew SolidBrush(Color::White),0,0,buffImg->Width, buffImg->Height);
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 commandLine++;
				 if (commandLine < num_commands){
					 if (commands[commandLine][0] == 'm'){
						 switch (k->getDirection()){
						 case 1:
							 //not at top and no wall on top of current block or bottom of next block
							 if (k->get_y() != 0){
								 if (world[k->get_x(), k->get_y()]->canMoveUp() && world[k->get_x(), k->get_y() - 1]->canMoveDown()){
									 k->move();
								 }
							 }
							 break;
						 case 2:
							 //not at Right side and no wall on right of current block or left of next block
							 if (k->get_x() != WORLD_WIDTH){
								 if (world[k->get_x(), k->get_y()]->canMoveRight() && world[k->get_x() + 1, k->get_y()]->canMoveLeft()){
									 k->move();
								 }
							 }
							 break;
						 case 3:
							 //not at bottom and no wall on bottom of current block or top of next block
							 if (k->get_y() != WORLD_HEIGHT){
								 if (world[k->get_x(), k->get_y()]->canMoveDown() && world[k->get_x(), k->get_y() + 1]->canMoveUp()){
									 k->move();
								 }
							 }
							 break;
						 case 4:
							 //not at left side and no wall on left of current block or right of next block
							 if (k->get_x() != 0){
								 if (world[k->get_x(), k->get_y()]->canMoveLeft() && world[k->get_x() - 1, k->get_y()]->canMoveRight()){
									 k->move();
								 }
							 }
							 break;
						 }
					 }
					 if (commands[commandLine][0] == 't'){
						 k->turnLeft();
					 }
					 if (commands[commandLine][0] == 'k'){
						 if (world[k->get_x(), k->get_y()]->getBeepers() > 0){
							 k->pickbeeper();
							 world[k->get_x(), k->get_y()]->setBeeper(world[k->get_x(), k->get_y()]->getBeepers() - 1);
						 }
					 }
					 if (commands[commandLine][0] == 'p'){
						 if (k->getNumBeepers() > 0){
							 k->putbeeper();
							 world[k->get_x(), k->get_y()]->setBeeper(world[k->get_x(), k->get_y()]->getBeepers() + 1);
						 }
					 }
					 if (commands[commandLine][0] == 'o'){
						 timer1->Stop();
					 }
				 }
				 label_num->Text = "Number of Beepers in Karel's Bag: " + k->getNumBeepers();
				 drawWorld();


	}
};
}
