#pragma once
#include "GraphVisualisationSFML.h"
#define fileName "PPI-I.txt"
Graph g;


static std::string toStandardString(System::String^ string)
{
	using System::Runtime::InteropServices::Marshal;
	System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
	char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
	std::string returnString(charPointer, string->Length);
	Marshal::FreeHGlobal(pointer);

	return returnString;
}
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
			
			if (g.initialise(fileName)) {
				this->totalNodes_text->Text = System::Convert::ToString(g.totalNodes());
				string min, max;
				if (g.totalNodes() < 800) {
					g.maxminDegree(max, min);
				}
				else {
					System::Windows::Forms::DialogResult msgboxID = MessageBox::Show("The Data is Too Large, It will take time to compute max and min Degrees\nAre you sure you want to continue?", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
					if (msgboxID == System::Windows::Forms::DialogResult::Yes) {
						g.maxminDegree(max, min);
					}
					else {
						min = "-";
						max = "-";
					}
				}
				this->maxDegreeNode_text->Text = gcnew System::String(max.c_str());
				this->minDegreeNode_text->Text = gcnew System::String(min.c_str());

				this->vertices_text->Text = System::Convert::ToString(g.getEdges());
			}
			else {
				MessageBox::Show("File Not Found", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			this->adjacencyMatrix_panel->Hide();
			this->adjacencyMatrix_panel->Dock = DockStyle::None;
			this->adjacencyMatrix_text->Hide();
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
	private: System::Windows::Forms::Button^ diplayGraph_button;
	private: System::Windows::Forms::TextBox^ vertices_text;
	protected:


	private: System::Windows::Forms::Label^ vertices_label;


	protected:








	private: System::Windows::Forms::Panel^ line1;

	private: System::Windows::Forms::Button^ exit_button;



	private: System::Windows::Forms::Button^ dispalayMatrix_button;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ minDegreeNode_text;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ maxDegreeNode_text;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ totalNodes_text;
	private: System::Windows::Forms::Label^ minDegreeNode_label;
	private: System::Windows::Forms::Label^ maxDegreeNode_label;
	private: System::Windows::Forms::Label^ totalNodes_label;
	private: System::Windows::Forms::Label^ nodeName_label;
	private: System::Windows::Forms::Button^ findNeighbour_button;

	private: System::Windows::Forms::Button^ findDegree_button;

	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ nodeName_text;

	private: System::Windows::Forms::RichTextBox^ output_text;
	private: System::Windows::Forms::Panel^ adjacencyMatrix_panel;
	private: System::Windows::Forms::RichTextBox^ adjacencyMatrix_text;
	private: System::Windows::Forms::Button^ back_button;
	private: System::Windows::Forms::Label^ warning;
	private: System::Windows::Forms::Button^ mst_button;
	private: System::Windows::Forms::Button^ dj_button;


















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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->diplayGraph_button = (gcnew System::Windows::Forms::Button());
			this->vertices_text = (gcnew System::Windows::Forms::TextBox());
			this->vertices_label = (gcnew System::Windows::Forms::Label());
			this->line1 = (gcnew System::Windows::Forms::Panel());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->dispalayMatrix_button = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->findNeighbour_button = (gcnew System::Windows::Forms::Button());
			this->findDegree_button = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->nodeName_text = (gcnew System::Windows::Forms::TextBox());
			this->nodeName_label = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->minDegreeNode_text = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->maxDegreeNode_text = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->totalNodes_text = (gcnew System::Windows::Forms::TextBox());
			this->minDegreeNode_label = (gcnew System::Windows::Forms::Label());
			this->maxDegreeNode_label = (gcnew System::Windows::Forms::Label());
			this->totalNodes_label = (gcnew System::Windows::Forms::Label());
			this->output_text = (gcnew System::Windows::Forms::RichTextBox());
			this->adjacencyMatrix_panel = (gcnew System::Windows::Forms::Panel());
			this->adjacencyMatrix_text = (gcnew System::Windows::Forms::RichTextBox());
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->warning = (gcnew System::Windows::Forms::Label());
			this->mst_button = (gcnew System::Windows::Forms::Button());
			this->dj_button = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->adjacencyMatrix_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// diplayGraph_button
			// 
			this->diplayGraph_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->diplayGraph_button->BackColor = System::Drawing::Color::Black;
			this->diplayGraph_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->diplayGraph_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->diplayGraph_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->diplayGraph_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->diplayGraph_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Red;
			this->diplayGraph_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->diplayGraph_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->diplayGraph_button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->diplayGraph_button->Location = System::Drawing::Point(82, 586);
			this->diplayGraph_button->Name = L"diplayGraph_button";
			this->diplayGraph_button->Size = System::Drawing::Size(128, 32);
			this->diplayGraph_button->TabIndex = 0;
			this->diplayGraph_button->Text = L"Display Graph";
			this->diplayGraph_button->UseVisualStyleBackColor = false;
			this->diplayGraph_button->Click += gcnew System::EventHandler(this, &MyForm::diplayGraph_button_Click);
			// 
			// vertices_text
			// 
			this->vertices_text->BackColor = System::Drawing::Color::Black;
			this->vertices_text->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->vertices_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->vertices_text->ForeColor = System::Drawing::Color::White;
			this->vertices_text->Location = System::Drawing::Point(390, 80);
			this->vertices_text->Name = L"vertices_text";
			this->vertices_text->ReadOnly = true;
			this->vertices_text->Size = System::Drawing::Size(130, 24);
			this->vertices_text->TabIndex = 1;
			this->vertices_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vertices_label
			// 
			this->vertices_label->AutoSize = true;
			this->vertices_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->vertices_label->Location = System::Drawing::Point(77, 79);
			this->vertices_label->Name = L"vertices_label";
			this->vertices_label->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->vertices_label->Size = System::Drawing::Size(253, 25);
			this->vertices_label->TabIndex = 2;
			this->vertices_label->Text = L"Total Number of Edges";
			// 
			// line1
			// 
			this->line1->BackColor = System::Drawing::Color::White;
			this->line1->Location = System::Drawing::Point(390, 101);
			this->line1->Name = L"line1";
			this->line1->Size = System::Drawing::Size(130, 2);
			this->line1->TabIndex = 5;
			// 
			// exit_button
			// 
			this->exit_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->exit_button->BackColor = System::Drawing::Color::Red;
			this->exit_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->exit_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->exit_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->exit_button->FlatAppearance->BorderSize = 2;
			this->exit_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->exit_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exit_button->ForeColor = System::Drawing::Color::Black;
			this->exit_button->Location = System::Drawing::Point(1034, 586);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(128, 32);
			this->exit_button->TabIndex = 7;
			this->exit_button->Text = L"Exit";
			this->exit_button->UseVisualStyleBackColor = false;
			this->exit_button->Click += gcnew System::EventHandler(this, &MyForm::exit_button_Click);
			// 
			// dispalayMatrix_button
			// 
			this->dispalayMatrix_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->dispalayMatrix_button->BackColor = System::Drawing::Color::Black;
			this->dispalayMatrix_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->dispalayMatrix_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->dispalayMatrix_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->dispalayMatrix_button->FlatAppearance->BorderSize = 2;
			this->dispalayMatrix_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Red;
			this->dispalayMatrix_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dispalayMatrix_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dispalayMatrix_button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->dispalayMatrix_button->Location = System::Drawing::Point(315, 586);
			this->dispalayMatrix_button->Name = L"dispalayMatrix_button";
			this->dispalayMatrix_button->Size = System::Drawing::Size(128, 32);
			this->dispalayMatrix_button->TabIndex = 9;
			this->dispalayMatrix_button->Text = L"Display Matrix";
			this->dispalayMatrix_button->UseVisualStyleBackColor = false;
			this->dispalayMatrix_button->Click += gcnew System::EventHandler(this, &MyForm::dispalayMatrix_button_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->findNeighbour_button);
			this->panel1->Controls->Add(this->findDegree_button);
			this->panel1->Controls->Add(this->panel5);
			this->panel1->Controls->Add(this->nodeName_text);
			this->panel1->Controls->Add(this->nodeName_label);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->minDegreeNode_text);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->maxDegreeNode_text);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->totalNodes_text);
			this->panel1->Controls->Add(this->minDegreeNode_label);
			this->panel1->Controls->Add(this->maxDegreeNode_label);
			this->panel1->Controls->Add(this->totalNodes_label);
			this->panel1->Location = System::Drawing::Point(618, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(670, 492);
			this->panel1->TabIndex = 11;
			// 
			// findNeighbour_button
			// 
			this->findNeighbour_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->findNeighbour_button->BackColor = System::Drawing::Color::Black;
			this->findNeighbour_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->findNeighbour_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->findNeighbour_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->findNeighbour_button->FlatAppearance->BorderSize = 2;
			this->findNeighbour_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Red;
			this->findNeighbour_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->findNeighbour_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->findNeighbour_button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->findNeighbour_button->Location = System::Drawing::Point(416, 431);
			this->findNeighbour_button->Name = L"findNeighbour_button";
			this->findNeighbour_button->Size = System::Drawing::Size(150, 35);
			this->findNeighbour_button->TabIndex = 17;
			this->findNeighbour_button->Text = L"Find Neighbours";
			this->findNeighbour_button->UseVisualStyleBackColor = false;
			this->findNeighbour_button->Click += gcnew System::EventHandler(this, &MyForm::findNeighbour_button_Click);
			// 
			// findDegree_button
			// 
			this->findDegree_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->findDegree_button->BackColor = System::Drawing::Color::Black;
			this->findDegree_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->findDegree_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->findDegree_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->findDegree_button->FlatAppearance->BorderSize = 2;
			this->findDegree_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Red;
			this->findDegree_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->findDegree_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->findDegree_button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->findDegree_button->Location = System::Drawing::Point(149, 431);
			this->findDegree_button->Name = L"findDegree_button";
			this->findDegree_button->Size = System::Drawing::Size(150, 32);
			this->findDegree_button->TabIndex = 16;
			this->findDegree_button->Text = L"Find Degree";
			this->findDegree_button->UseVisualStyleBackColor = false;
			this->findDegree_button->Click += gcnew System::EventHandler(this, &MyForm::findDegree_button_Click);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::White;
			this->panel5->Location = System::Drawing::Point(495, 345);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(130, 2);
			this->panel5->TabIndex = 15;
			// 
			// nodeName_text
			// 
			this->nodeName_text->BackColor = System::Drawing::Color::Black;
			this->nodeName_text->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->nodeName_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nodeName_text->ForeColor = System::Drawing::Color::White;
			this->nodeName_text->Location = System::Drawing::Point(495, 323);
			this->nodeName_text->Name = L"nodeName_text";
			this->nodeName_text->Size = System::Drawing::Size(130, 24);
			this->nodeName_text->TabIndex = 14;
			this->nodeName_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// nodeName_label
			// 
			this->nodeName_label->AutoSize = true;
			this->nodeName_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nodeName_label->Location = System::Drawing::Point(83, 322);
			this->nodeName_label->Name = L"nodeName_label";
			this->nodeName_label->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->nodeName_label->Size = System::Drawing::Size(228, 25);
			this->nodeName_label->TabIndex = 13;
			this->nodeName_label->Text = L"Enter Name Of Node";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->Location = System::Drawing::Point(495, 258);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(130, 2);
			this->panel4->TabIndex = 11;
			// 
			// minDegreeNode_text
			// 
			this->minDegreeNode_text->BackColor = System::Drawing::Color::Black;
			this->minDegreeNode_text->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->minDegreeNode_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->minDegreeNode_text->ForeColor = System::Drawing::Color::White;
			this->minDegreeNode_text->Location = System::Drawing::Point(495, 237);
			this->minDegreeNode_text->Name = L"minDegreeNode_text";
			this->minDegreeNode_text->ReadOnly = true;
			this->minDegreeNode_text->Size = System::Drawing::Size(130, 24);
			this->minDegreeNode_text->TabIndex = 10;
			this->minDegreeNode_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Location = System::Drawing::Point(495, 170);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(130, 2);
			this->panel3->TabIndex = 9;
			// 
			// maxDegreeNode_text
			// 
			this->maxDegreeNode_text->BackColor = System::Drawing::Color::Black;
			this->maxDegreeNode_text->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->maxDegreeNode_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->maxDegreeNode_text->ForeColor = System::Drawing::Color::White;
			this->maxDegreeNode_text->Location = System::Drawing::Point(495, 149);
			this->maxDegreeNode_text->Name = L"maxDegreeNode_text";
			this->maxDegreeNode_text->ReadOnly = true;
			this->maxDegreeNode_text->Size = System::Drawing::Size(130, 24);
			this->maxDegreeNode_text->TabIndex = 8;
			this->maxDegreeNode_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(495, 88);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(130, 2);
			this->panel2->TabIndex = 7;
			// 
			// totalNodes_text
			// 
			this->totalNodes_text->BackColor = System::Drawing::Color::Black;
			this->totalNodes_text->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->totalNodes_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totalNodes_text->ForeColor = System::Drawing::Color::White;
			this->totalNodes_text->Location = System::Drawing::Point(495, 67);
			this->totalNodes_text->Name = L"totalNodes_text";
			this->totalNodes_text->ReadOnly = true;
			this->totalNodes_text->Size = System::Drawing::Size(130, 24);
			this->totalNodes_text->TabIndex = 6;
			this->totalNodes_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// minDegreeNode_label
			// 
			this->minDegreeNode_label->AutoSize = true;
			this->minDegreeNode_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->minDegreeNode_label->Location = System::Drawing::Point(83, 236);
			this->minDegreeNode_label->Name = L"minDegreeNode_label";
			this->minDegreeNode_label->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->minDegreeNode_label->Size = System::Drawing::Size(304, 25);
			this->minDegreeNode_label->TabIndex = 5;
			this->minDegreeNode_label->Text = L"Node With Minimum Degree";
			// 
			// maxDegreeNode_label
			// 
			this->maxDegreeNode_label->AutoSize = true;
			this->maxDegreeNode_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->maxDegreeNode_label->Location = System::Drawing::Point(83, 148);
			this->maxDegreeNode_label->Name = L"maxDegreeNode_label";
			this->maxDegreeNode_label->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->maxDegreeNode_label->Size = System::Drawing::Size(310, 25);
			this->maxDegreeNode_label->TabIndex = 4;
			this->maxDegreeNode_label->Text = L"Node With Maximum Degree";
			// 
			// totalNodes_label
			// 
			this->totalNodes_label->AutoSize = true;
			this->totalNodes_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totalNodes_label->Location = System::Drawing::Point(83, 66);
			this->totalNodes_label->Name = L"totalNodes_label";
			this->totalNodes_label->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->totalNodes_label->Size = System::Drawing::Size(258, 25);
			this->totalNodes_label->TabIndex = 3;
			this->totalNodes_label->Text = L"Total Number Of Nodes";
			// 
			// output_text
			// 
			this->output_text->BackColor = System::Drawing::Color::Black;
			this->output_text->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->output_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->output_text->ForeColor = System::Drawing::Color::White;
			this->output_text->Location = System::Drawing::Point(82, 161);
			this->output_text->Name = L"output_text";
			this->output_text->ReadOnly = true;
			this->output_text->Size = System::Drawing::Size(440, 366);
			this->output_text->TabIndex = 12;
			this->output_text->Text = L"";
			// 
			// adjacencyMatrix_panel
			// 
			this->adjacencyMatrix_panel->Controls->Add(this->adjacencyMatrix_text);
			this->adjacencyMatrix_panel->Controls->Add(this->back_button);
			this->adjacencyMatrix_panel->Location = System::Drawing::Point(622, 640);
			this->adjacencyMatrix_panel->Name = L"adjacencyMatrix_panel";
			this->adjacencyMatrix_panel->Size = System::Drawing::Size(223, 10);
			this->adjacencyMatrix_panel->TabIndex = 13;
			// 
			// adjacencyMatrix_text
			// 
			this->adjacencyMatrix_text->BackColor = System::Drawing::Color::Black;
			this->adjacencyMatrix_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->adjacencyMatrix_text->ForeColor = System::Drawing::Color::White;
			this->adjacencyMatrix_text->Location = System::Drawing::Point(12, 12);
			this->adjacencyMatrix_text->Name = L"adjacencyMatrix_text";
			this->adjacencyMatrix_text->ReadOnly = true;
			this->adjacencyMatrix_text->Size = System::Drawing::Size(1273, 588);
			this->adjacencyMatrix_text->TabIndex = 9;
			this->adjacencyMatrix_text->Text = L"";
			// 
			// back_button
			// 
			this->back_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->back_button->BackColor = System::Drawing::Color::Red;
			this->back_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->back_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->back_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->back_button->FlatAppearance->BorderSize = 2;
			this->back_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->back_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->back_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->back_button->ForeColor = System::Drawing::Color::Black;
			this->back_button->Location = System::Drawing::Point(83, -34);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(128, 32);
			this->back_button->TabIndex = 8;
			this->back_button->Text = L"Back";
			this->back_button->UseVisualStyleBackColor = false;
			this->back_button->Click += gcnew System::EventHandler(this, &MyForm::back_button_Click);
			// 
			// warning
			// 
			this->warning->AllowDrop = true;
			this->warning->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->warning->AutoSize = true;
			this->warning->BackColor = System::Drawing::Color::Transparent;
			this->warning->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->warning->Location = System::Drawing::Point(258, 628);
			this->warning->Name = L"warning";
			this->warning->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->warning->Size = System::Drawing::Size(230, 13);
			this->warning->TabIndex = 14;
			this->warning->Text = L"(Works Perfect For Nodes Less than 25)";
			// 
			// mst_button
			// 
			this->mst_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->mst_button->BackColor = System::Drawing::Color::Black;
			this->mst_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->mst_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mst_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->mst_button->FlatAppearance->BorderSize = 2;
			this->mst_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Red;
			this->mst_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mst_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mst_button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->mst_button->Location = System::Drawing::Point(549, 586);
			this->mst_button->Name = L"mst_button";
			this->mst_button->Size = System::Drawing::Size(128, 32);
			this->mst_button->TabIndex = 15;
			this->mst_button->Text = L"Spanning Tree";
			this->mst_button->UseVisualStyleBackColor = false;
			this->mst_button->Click += gcnew System::EventHandler(this, &MyForm::mst_button_Click);
			// 
			// dj_button
			// 
			this->dj_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->dj_button->BackColor = System::Drawing::Color::Black;
			this->dj_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->dj_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->dj_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->dj_button->FlatAppearance->BorderSize = 2;
			this->dj_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Red;
			this->dj_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dj_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dj_button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->dj_button->Location = System::Drawing::Point(789, 586);
			this->dj_button->Name = L"dj_button";
			this->dj_button->Size = System::Drawing::Size(128, 32);
			this->dj_button->TabIndex = 16;
			this->dj_button->Text = L"Dijkstra Algo";
			this->dj_button->UseVisualStyleBackColor = false;
			this->dj_button->Click += gcnew System::EventHandler(this, &MyForm::dj_button_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InfoText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1300, 650);
			this->Controls->Add(this->dj_button);
			this->Controls->Add(this->mst_button);
			this->Controls->Add(this->warning);
			this->Controls->Add(this->adjacencyMatrix_panel);
			this->Controls->Add(this->output_text);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dispalayMatrix_button);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->line1);
			this->Controls->Add(this->vertices_label);
			this->Controls->Add(this->vertices_text);
			this->Controls->Add(this->diplayGraph_button);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GRAPH VISULAISATION";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->adjacencyMatrix_panel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	
private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}

private: System::Void diplayGraph_button_Click(System::Object^ sender, System::EventArgs^ e) {
	g.Visualise();
}

private: System::Void dispalayMatrix_button_Click(System::Object^ sender, System::EventArgs^ e) {
	//MATRIX
	if (g.Nodes > 100) {
		System::Windows::Forms::DialogResult msgboxID= MessageBox::Show("Too many Nodes !\nAre You Sure You want to Continue?", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
		if (msgboxID == System::Windows::Forms::DialogResult::No) {
			return;
		}
	}
	this->dj_button->Hide();
	this->mst_button->Hide();
	this->adjacencyMatrix_panel->Show();
	this->adjacencyMatrix_panel->Dock = DockStyle::Fill;
	this->adjacencyMatrix_text->Show();
	if (this->adjacencyMatrix_text->Text->Length == 0) {
		int flag = 0;

		for (int i = 0; i < g.Nodes; i++) {
			this->adjacencyMatrix_text->Text += L"\t";
			this->adjacencyMatrix_text->Text += gcnew System::String(g.vec[i].c_str());
		}
		this->adjacencyMatrix_text->Text += System::Environment::NewLine;

		for (int i = 0; i < g.Nodes; i++) {
			bool flag = false;
			for (int j = 0; j < g.Nodes; j++) {
				if (!flag)
					this->adjacencyMatrix_text->Text += gcnew System::String(g.vec[i].c_str());
				this->adjacencyMatrix_text->Text += L"\t" + System::Convert::ToString(g.graph[make_pair(g.vec[i], g.vec[j])]);
				flag = true;
			}
			this->adjacencyMatrix_text->Text += System::Environment::NewLine;
		}
	}
	
}
private: System::Void findDegree_button_Click(System::Object^ sender, System::EventArgs^ e) {
	if (nodeName_text->Text == "") {
		MessageBox::Show("Please Enter Name of Node", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else {
		string str = toStandardString(nodeName_text->Text);
		int degree = g.findDegree(str);
		if (degree == 0) {
			output_text->Text = L"NOT FOUND";
		}
		else {
			output_text->Text = L"DEGREEE = " + System::Convert::ToString(degree);
		}
	}
}
private: System::Void findNeighbour_button_Click(System::Object^ sender, System::EventArgs^ e) {
	if (nodeName_text->Text == "") {
		MessageBox::Show("Please Enter Name of Node", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else {
		output_text->Text = L"";
		string str = toStandardString(nodeName_text->Text);
		vector<string> temp;
		g.showNeig(str, temp);
		if (temp.size() == 0) {
			output_text->Text = L"NO NEIGHBOURS FOUND";
		}
		else {
			for (int i = 0; i < temp.size(); i++) {
				System::String^ s = gcnew System::String(temp[i].c_str());
				output_text->Text += s;
				output_text->Text += L" , ";
			}
		}
	}
}

private: System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e) {
	this->adjacencyMatrix_panel->Hide();
	this->adjacencyMatrix_panel->Dock = DockStyle::None;
	this->adjacencyMatrix_text->Hide();
	this->dj_button->Show();
	this->mst_button->Show();
}


private: System::Void mst_button_Click(System::Object^ sender, System::EventArgs^ e) {
	

	System::String^ output;
	output = L"";
	double total_w = g.prim(output);
	output_text->Text = L"";
	
	
	output_text->Text = output;
	output_text->Text += L"\n\nTOTAL WEIGHT = ";
	output_text->Text += System::Convert::ToString(total_w);
	
	
}
private: System::Void dj_button_Click(System::Object^ sender, System::EventArgs^ e) {
	if (nodeName_text->Text == "") {
		MessageBox::Show("Please Enter Name of Source Node", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else {
		System::String^ output;
		output = L"";
		output_text->Text = L"";
		string str = toStandardString(nodeName_text->Text);
		g.dijkstra(str, output);
		output_text->Text = output;
	}
}
};
}
