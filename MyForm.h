#pragma once
int mas1[5];        // одновимірний масив
int matrix[5][5];   // двовимірний масив
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
			InitializeComponent(); comboBox1->SelectedIndex = 0;

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
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label1;

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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(11) {
				L"Заповнити масив ", L"Сума ", L"Мінімум", L"Максимум    ",
					L"Парні/непарні", L"Заповнити матрицю  ", L"Сума рядків", L"Діагональ", L"Транспонування", L"Сортування обміном  ", L"Сортування екстремальних"
			});
			this->comboBox1->Location = System::Drawing::Point(48, 213);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(133, 28);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->Text = L"Завдання";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(351, 252);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 53);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Виконати ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(218, 50);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 40;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(404, 148);
			this->dataGridView1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(487, 252);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(739, 408);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		Random^ rnd = gcnew Random();

		if (comboBox1->SelectedIndex == 0) // Заповнити масив
		{
			for (int i = 0; i < 5; i++) 
				mas1[i] = rnd->Next(1, 20);

			dataGridView1->ColumnCount = 5;
			dataGridView1->RowCount = 1;
			for (int i = 0; i < 5; i++) 
				dataGridView1->Rows[0]->Cells[i]->Value = mas1[i];
		}
		if (comboBox1->SelectedIndex == 1) // Сума
		{
			int sum = 0;
			for (int i = 0; i < 5; i++)
				sum += mas1[1];
			label1->Text = "Сума елементів масиву = " + Convert:: ToString(sum);

		}

		if (comboBox1->SelectedIndex == 2) // Мінімум
		{
			int min = mas1[0];
			for (int i = 1; i < 5; i++)
			{
				if (mas1[i] < min)
					min = mas1[i];
			}
			label1->Text = "Мінімальний елемент масиву = " + Convert::ToString(min);
		}

		if (comboBox1->SelectedIndex == 3) // Максимум
			{
				int max = mas1[0];
				for (int i = 1; i < 5; i++)
				{
					if (mas1[i] > max)
						max = mas1[i];
				}
				label1->Text = "Максимальний елемент масиву = " + Convert::ToString(max);
			}

		if (comboBox1->SelectedIndex == 4) // Парні/непарні
		{
			int p = 0;
			int n = 0;

			for (int i = 0; i < 5; i++)
			{
				if (mas1[i] % 2 == 0)
				{
					p++;
				}
				else
				{
					n++;
				}
			}

			label1->Text = "Парних елементів: " + Convert::ToString(p) + "\nНепарних елементів: " + Convert::ToString(n);
		}

		if (comboBox1->SelectedIndex == 5) // Заповнити матрицю
		{
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					matrix[i][j] = rnd->Next(1, 20);
			
			dataGridView1->ColumnCount = 5;
			dataGridView1->RowCount = 5;
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					dataGridView1->Rows[i]->Cells[j]->Value = matrix[i][j];
		}
		if (comboBox1->SelectedIndex == 6) // Сума рядків
		{
			for (int i = 0; i < 5; i++)
			{
				int rowSum = 0;
				for (int j = 0; j < 5; j++) 
					rowSum += matrix[i][j];
				MessageBox::Show("Сума рядка " + i + " = " + rowSum.ToString());
			}
		}

		if (comboBox1->SelectedIndex == 7) // Діагональ
		{
			int diagsum = 0;
			for (int i = 0; i < 5; i++)
				diagsum += matrix[i][i];
			MessageBox::Show("Діагональ: " + diagsum.ToString());
		}

		if (comboBox1->SelectedIndex == 8) // Транспонування
		{
			for (int i = 0; i < 5; i++)
				for (int j = i + 1; j < 5; j++)
				{
				// обмін елементів
				
				}

			dataGridView1->ColumnCount = 5;
			dataGridView1->RowCount = 5;
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					dataGridView1->Rows[i]->Cells[j]->Value = matrix[i][j];
		}

		if (comboBox1->SelectedIndex == 9) // Сортування обміном
		{
			// Сортування методом обміну 
			for (int i = 0; i < 5 - 1; i++)
			{
				for (int j = 0; j < 5 - i - 1; j++)
				{
					if (mas1[j] > mas1[j + 1])
					{
						int temp = mas1[j];
						mas1[j] = mas1[j + 1];
						mas1[j + 1] = temp;
					}
				}
			}

			// Вивід у DataGridView
			dataGridView1->ColumnCount = 5;
			dataGridView1->RowCount = 1;
			for (int i = 0; i < 5; i++)
				dataGridView1->Rows[0]->Cells[i]->Value = mas1[i];
		}

		if (comboBox1->SelectedIndex == 10) // Сортування екстремальних
		{
			// Сортування методом вибору (екстремальних елементів)
			for (int i = 0; i < 5 - 1; i++)
			{
				int minIndex = i;
				for (int j = i + 1; j < 5; j++)
					if (mas1[j] < mas1[minIndex])
						minIndex = j;

				// обмін
				int temp = mas1[i];
				mas1[i] = mas1[minIndex];
				mas1[minIndex] = temp;
			}

			// Вивід у DataGridView
			dataGridView1->ColumnCount = 5;
			dataGridView1->RowCount = 1;
			for (int i = 0; i < 5; i++)
				dataGridView1->Rows[0]->Cells[i]->Value = mas1[i];
		}
	}
	
	};
}
