#pragma once

#include "RoboCupReferee.h"

#define SCORE_RATE 0.5

namespace RoboCupReferee {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		cli::array<System::String^>^ args;
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_srv = nullptr;
			m_connected = false;

			// 接続を試みる
			m_srv = gcnew Referee("RoboCupReferee");
			args = System::Environment::GetCommandLineArgs();

			//if(m_srv->connect("socio4.iir.nii.ac.jp", 9333)){
			if(m_srv->connect(args[1], System::Convert::ToInt32(args[2]))){
				m_connected = true;
					 
				m_srv->connectToViewer();
				m_srv->setAutoExitProc(true);
			}
		}
		void setText(System::String^ text)
		{
			this->label1->Text = text;
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			m_srv = nullptr;
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	private: System::Windows::Forms::Label^  label1;



	private: System::Windows::Forms::Timer^  timer1;


	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ListBox^  listBox2;
			 
			 
			 //sigverse::SIGService ^srv = gcnew sigverse::SIGService("RobocupReferee");
			 Referee ^m_srv;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label10;
			 bool m_connected;
			 //srv->connect("socio4.iir.nii.ac.jp", 9333);
			 
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"HGSｺﾞｼｯｸE", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(237, 383);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 21);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Total";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// listBox1
			// 
			this->listBox1->BackColor = System::Drawing::SystemColors::InfoText;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->listBox1->ForeColor = System::Drawing::SystemColors::Menu;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->HorizontalScrollbar = true;
			this->listBox1->ItemHeight = 21;
			this->listBox1->Location = System::Drawing::Point(0, 95);
			this->listBox1->Name = L"listBox1";
			this->listBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->listBox1->Size = System::Drawing::Size(300, 172);
			this->listBox1->TabIndex = 4;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox1_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"HGSｺﾞｼｯｸE", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(303, 76);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Score";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::InfoText;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->textBox1->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->textBox1->Location = System::Drawing::Point(293, 377);
			this->textBox1->Name = L"textBox1";
			this->textBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->textBox1->Size = System::Drawing::Size(86, 31);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"0";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// listBox2
			// 
			this->listBox2->BackColor = System::Drawing::SystemColors::InfoText;
			this->listBox2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->listBox2->ForeColor = System::Drawing::SystemColors::Menu;
			this->listBox2->FormattingEnabled = true;
			this->listBox2->HorizontalScrollbar = true;
			this->listBox2->ItemHeight = 21;
			this->listBox2->Location = System::Drawing::Point(300, 95);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(80, 172);
			this->listBox2->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"HGSｺﾞｼｯｸE", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label3->Location = System::Drawing::Point(4, 76);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Comment";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::InfoText;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->textBox2->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->textBox2->Location = System::Drawing::Point(166, 328);
			this->textBox2->Name = L"textBox2";
			this->textBox2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->textBox2->Size = System::Drawing::Size(66, 31);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"00:00";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"HGSｺﾞｼｯｸE", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label4->Location = System::Drawing::Point(111, 333);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 21);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Time";
			this->label4->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::InfoText;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->textBox3->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->textBox3->Location = System::Drawing::Point(261, 420);
			this->textBox3->Name = L"textBox3";
			this->textBox3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->textBox3->Size = System::Drawing::Size(44, 31);
			this->textBox3->TabIndex = 10;
			this->textBox3->Text = L"0";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"HGSｺﾞｼｯｸE", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label5->Location = System::Drawing::Point(100, 426);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(161, 21);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Number of Trials";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"HGSｺﾞｼｯｸE", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label6->Location = System::Drawing::Point(308, 423);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(27, 27);
			this->label6->TabIndex = 11;
			this->label6->Text = L"/";
			this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::InfoText;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->textBox4->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->textBox4->Location = System::Drawing::Point(335, 420);
			this->textBox4->Name = L"textBox4";
			this->textBox4->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->textBox4->Size = System::Drawing::Size(44, 31);
			this->textBox4->TabIndex = 12;
			this->textBox4->Text = L"0";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"HGPｺﾞｼｯｸE", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button3->Location = System::Drawing::Point(144, 460);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(88, 34);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Give Up";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"HGSｺﾞｼｯｸE", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label7->Location = System::Drawing::Point(1, 300);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(227, 21);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Use of special functions";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(236, 306);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(49, 16);
			this->radioButton1->TabIndex = 15;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"None";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(286, 306);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(53, 16);
			this->radioButton2->TabIndex = 16;
			this->radioButton2->Text = L"Either";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(338, 306);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(47, 16);
			this->radioButton3->TabIndex = 17;
			this->radioButton3->Text = L"Both";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::SystemColors::InfoText;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->textBox5->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->textBox5->Location = System::Drawing::Point(293, 328);
			this->textBox5->Name = L"textBox5";
			this->textBox5->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->textBox5->Size = System::Drawing::Size(86, 31);
			this->textBox5->TabIndex = 19;
			this->textBox5->Text = L"0";
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &Form1::textBox5_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"HGSｺﾞｼｯｸE", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label8->Location = System::Drawing::Point(237, 333);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(61, 21);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Score";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(302, 270);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(80, 16);
			this->checkBox1->TabIndex = 20;
			this->checkBox1->Text = L"Auto scroll";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::SystemColors::InfoText;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->textBox6->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->textBox6->Location = System::Drawing::Point(125, 3);
			this->textBox6->Name = L"textBox6";
			this->textBox6->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->textBox6->Size = System::Drawing::Size(224, 31);
			this->textBox6->TabIndex = 22;
			this->textBox6->Text = L"Intaractive Clean Up";
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &Form1::textBox6_TextChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"HGSｺﾞｼｯｸE", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label9->Location = System::Drawing::Point(10, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(109, 21);
			this->label9->TabIndex = 21;
			this->label9->Text = L"Task name";
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::SystemColors::InfoText;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->textBox7->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->textBox7->Location = System::Drawing::Point(125, 38);
			this->textBox7->Name = L"textBox7";
			this->textBox7->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->textBox7->Size = System::Drawing::Size(224, 31);
			this->textBox7->TabIndex = 24;
			this->textBox7->Text = L"Team 01";
			this->textBox7->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &Form1::textBox7_TextChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"HGSｺﾞｼｯｸE", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label10->Location = System::Drawing::Point(10, 44);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(114, 21);
			this->label10->TabIndex = 23;
			this->label10->Text = L"Team name";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(380, 500);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"Robocup@home 2016";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ClientSizeChanged += gcnew System::EventHandler(this, &Form1::Form1_ClientSizeChanged);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if(m_srv != nullptr){
				 m_srv->checkRecvData(100);
				 int ssize = m_srv->getScoreSize();
				 // メッセージが来た
				 for(int i = 0; i < ssize; i++){
					 int score = m_srv->getScore();
					 System::String^ msg = m_srv->getMessage();
					 System::String^ listitem_msg = msg;// + "                    " + score.ToString();
					 System::String^ listitem_score = score.ToString();
					 this->listBox1->Items->Add(listitem_msg);
					 this->listBox2->Items->Add(listitem_score);
					 if (checkBox1->Checked == true){
						 this->listBox1->SelectedIndex = listBox1->Items->Count - 1;
						 this->listBox2->SelectedIndex = listBox2->Items->Count - 1;
						 this->listBox1->ClearSelected();
						 this->listBox2->ClearSelected();
					 }
				 }


				 //commentを更新
				 int msize = m_srv->getMessageSize();
				 for (int i = 0; i < msize; i++){
					 System::String^ comment = m_srv->getMessage();
					 this->listBox1->Items->Add(comment);
					 this->listBox2->Items->Add("");
					 if (checkBox1->Checked == true){
						 this->listBox1->SelectedIndex = listBox1->Items->Count - 1;
						 this->listBox2->SelectedIndex = listBox2->Items->Count - 1;
						 this->listBox1->ClearSelected();
						 this->listBox2->ClearSelected();
					 }
				 }
				 if (listBox1->Focused == true){
					 this->listBox2->SelectedIndex = this->listBox1->SelectedIndex;
				 }
				 else if (listBox2->Focused == true){
					 this->listBox1->SelectedIndex = this->listBox2->SelectedIndex;
				 }


				 //試行を繰り返す回数と現在の試行回数を更新
				 int trialCount = m_srv->getTrialCount();
				 this->textBox3->Text = trialCount.ToString();
				 int numberOfRepetition = m_srv->getNumberOfRepetition();
				 this->textBox4->Text = numberOfRepetition.ToString();


				 //TotalとScoreを更新
				 double scoreRate = 1.0;
				 if (radioButton2->Checked == true){
					 scoreRate *= SCORE_RATE;
				 }
				 else if (radioButton3->Checked == true){
					 scoreRate *= SCORE_RATE * SCORE_RATE;
				 }
				 std::vector<int> penalty = m_srv->getPenalty();
				 std::vector<int> tmpTotal = m_srv->getTmpTotal();
				 
				 double score = 0;
				 if (0 < trialCount && trialCount <= tmpTotal.size()){
					 score = tmpTotal[trialCount - 1] * scoreRate + penalty[trialCount - 1];
				 }
				 this->textBox5->Text = score.ToString();

				 double total = 0;
				 for (int i = 0; i < trialCount; i++){
					 score = tmpTotal[i] * scoreRate + penalty[i];
					 if (score < 0) score = 0;
					 total += score;
				 }

				 this->textBox1->Text = total.ToString();


				//Timeを更新
				System::String^ msg =  m_srv->getRemainingTime();
				if(msg!=""){
					this->textBox2->Text = msg;
				}
				else{
					this->textBox2->Text = "00:00";
				}
			 }
		 }
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 m_srv->setTotal(0);
			 this->textBox1->Text = L"0";
			 this->listBox1->Items->Clear();
			 this->listBox2->Items->Clear();
		 }
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 m_srv->sendMsgToCtr("moderator_0", "Give_up");
}
private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Form1_ClientSizeChanged(System::Object^  sender, System::EventArgs^  e) {
			 int formWidth = this->Size.Width - 20;
			 if (formWidth < 360){
				 this->ClientSize = System::Drawing::Size(380, 500);
			 }
			 else{
				 this->label1->Location = System::Drawing::Point(formWidth - 143, 383);
				 this->listBox1->Size = System::Drawing::Size(formWidth - 80, 172);
				 this->label2->Location = System::Drawing::Point(formWidth - 77, 76);
				 this->textBox1->Location = System::Drawing::Point(formWidth - 87, 377);
				 this->listBox2->Location = System::Drawing::Point(formWidth - 80, 95);
				 this->textBox2->Location = System::Drawing::Point(formWidth - 224, 328);
				 this->label4->Location = System::Drawing::Point(formWidth - 279, 223);
				 this->textBox3->Location = System::Drawing::Point(formWidth - 119, 420);
				 this->label5->Location = System::Drawing::Point(formWidth - 280, 426);
				 this->label6->Location = System::Drawing::Point(formWidth - 72, 423);
				 this->textBox4->Location = System::Drawing::Point(formWidth - 45, 420);
				 this->button3->Location = System::Drawing::Point((formWidth / 2) - 46, 460);
				 this->label7->Location = System::Drawing::Point(formWidth - 379, 300);
				 this->radioButton1->Location = System::Drawing::Point(formWidth - 144, 306);
				 this->radioButton2->Location = System::Drawing::Point(formWidth - 94, 306);
				 this->radioButton3->Location = System::Drawing::Point(formWidth - 42, 306);
				 this->textBox5->Location = System::Drawing::Point(formWidth - 87, 328);
				 this->label8->Location = System::Drawing::Point(formWidth - 153, 333);
				 this->checkBox1->Location = System::Drawing::Point(formWidth - 78, 270);
				 this->textBox6->Size = System::Drawing::Size(formWidth - 156, 31);
				 this->textBox7->Size = System::Drawing::Size(formWidth - 156, 31);
			 }
}
private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ tmp = this->textBox6->Text + "_" + this->textBox7->Text + ".csv";
			 m_srv->logFileName = tmp->Replace(' ', '_');
			 System::IO::File::Copy(m_srv->logFileName_old, m_srv->logFileName);
			 m_srv->changeOutputLogFile();
			 System::IO::File::Delete(m_srv->logFileName_old);
			 m_srv->logFileName_old = m_srv->logFileName;
}
private: System::Void textBox7_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ tmp = this->textBox6->Text + "_" + this->textBox7->Text + ".csv";
			 m_srv->logFileName = tmp->Replace(' ', '_');
			 System::IO::File::Copy(m_srv->logFileName_old, m_srv->logFileName);
			 m_srv->changeOutputLogFile();
			 System::IO::File::Delete(m_srv->logFileName_old);
			 m_srv->logFileName_old = m_srv->logFileName;
}
};
}

