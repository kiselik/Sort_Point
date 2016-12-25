#pragma once
#include "To_String.h"
#include "queue.h"

int *cur;
string *mem;
namespace Sort_Point {
	int count = 0;
	int sizemem;
	int k = 0;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	void MarshalString(String ^ s, string& os)
	{
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button2;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(33, 165);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(148, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Пошаговое выполнение";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(28, 57);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(251, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(28, 122);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(251, 20);
			this->textBox2->TabIndex = 2;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCellsExceptHeaders;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 216);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(479, 134);
			this->dataGridView1->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(146, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Неупорядоченный массив :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(30, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(135, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Упорядоченный массив :";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(302, 80);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(87, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Упорядочить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(707, 380);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->DoubleBuffered = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		string str;
		MarshalString(textBox1->Text, str);
		mem = new string[2 + str.length()];
		To_String(str, sizemem, mem);
		cur = new int[sizemem];


		for (int i = 0; i<sizemem; i++)
			cur[i] = atoi(mem[i].c_str());

		int max = -1;                             
		for (int i = 0; i<sizemem; i++)                 
		{									    
			if (cur[i]>max)                      
				max = cur[i];                     
		}										 
		int k = 0;                                
		while (max != 0)                           
		{                                       
			k++;                               
			max = max / 10;                        
		} 

		dataGridView1->Rows->Clear();
		dataGridView1->ColumnCount = 10;
		dataGridView1->Columns[0]->HeaderText = "0";
		dataGridView1->Columns[1]->HeaderText = "1";
		dataGridView1->Columns[2]->HeaderText = "2";
		dataGridView1->Columns[3]->HeaderText = "3";
		dataGridView1->Columns[4]->HeaderText = "4";
		dataGridView1->Columns[5]->HeaderText = "5";
		dataGridView1->Columns[6]->HeaderText = "6";
		dataGridView1->Columns[7]->HeaderText = "7";
		dataGridView1->Columns[8]->HeaderText = "8";
		dataGridView1->Columns[9]->HeaderText = "9";
		dataGridView1->RowCount = sizemem+1;

		queue Q[10];

		for (int j = 0; j<sizemem; j++)
		{
			if (count<k)
			{
				int index = (cur[j] / (int)pow(10, count)) % 10;
				Q[index].Push(cur[j]);
				int m = 0;
				queue qs;
				qs = Q[index];
				while (!qs.Is_Empty())
					dataGridView1[index, m++]->Value = qs.Pop();
			}
		};

		int sizemem = 0;

		for (int j = 0; j<10; j++)
		{
			while (!Q[j].Is_Empty())
				cur[sizemem++] = Q[j].Pop();
		}

		count++;
		delete[]mem;
		delete[]cur;
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	textBox2->Clear();
	string str;
	MarshalString(textBox1->Text, str);
	mem = new string[2 + str.length()];
	To_String(str, sizemem, mem);
	cur = new int[sizemem];
	for (int i = 0; i <sizemem; i++)
		cur[i] = atoi(mem[i].c_str());

	int max = -1;
	for (int i = 0; i < sizemem; i++)
	{
		if (cur[i] > max)
			max = cur[i];
	}

	while (max != 0)
	{

		k++;
		max = max / 10;
	}
	SortPoint(cur, sizemem);
	for (int i = 0;i < sizemem;i++)
	{
		textBox2->Text += Convert::ToString(cur[i]) + " ";
	}
	delete[]mem;
	delete[]cur;
}

private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) 
{
	textBox2->Clear();
	dataGridView1->Rows->Clear();

	count = 0;

	if (textBox1->Text == "0")
	{
		textBox1->Clear();
	}
}
};

}