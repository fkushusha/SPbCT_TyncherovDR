#pragma once
#include "Library.h" // подключение созданной DLL-библиотеки
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <mutex>
#include <iterator>
#include <chrono>
#include <iomanip>

namespace TyncherovDR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;
	using namespace System::Threading;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			DateTime datetime = DateTime::Now;
			this->label4->Text = "Дата: " + datetime.ToString(); // запись времени и даты в label 4 на форму
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
	private: System::Windows::Forms::TextBox^ textBox1;

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;



	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: Thread^ thread1;
	private: Thread^ thread2;
	private: Thread^ thread3;// создание потоков
	private: System::Windows::Forms::Button^ File1ShowButton;
	private: System::Windows::Forms::Button^ SortFileButton;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->File1ShowButton = (gcnew System::Windows::Forms::Button());
			this->SortFileButton = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(342, 147);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(378, 153);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(339, 124);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(273, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Исходный файл (Original.txt):";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(726, 124);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(341, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Отсортированный файл (Sorted.txt):";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(730, 147);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(378, 254);
			this->textBox2->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 30);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(315, 25);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Тынчеров Даниил, группа 590";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(725, 30);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 25);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Дата:";
			// 
			// File1ShowButton
			// 
			this->File1ShowButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->File1ShowButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->File1ShowButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->File1ShowButton->Location = System::Drawing::Point(12, 147);
			this->File1ShowButton->Name = L"File1ShowButton";
			this->File1ShowButton->Size = System::Drawing::Size(273, 54);
			this->File1ShowButton->TabIndex = 7;
			this->File1ShowButton->Text = L"Отобразить исходный файл";
			this->File1ShowButton->UseVisualStyleBackColor = false;
			this->File1ShowButton->Click += gcnew System::EventHandler(this, &MyForm::File1ShowButton_Click);
			// 
			// SortFileButton
			// 
			this->SortFileButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->SortFileButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SortFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SortFileButton->Location = System::Drawing::Point(12, 236);
			this->SortFileButton->Name = L"SortFileButton";
			this->SortFileButton->Size = System::Drawing::Size(273, 54);
			this->SortFileButton->TabIndex = 5;
			this->SortFileButton->Text = L"Отобразить отсортированный файл";
			this->SortFileButton->UseVisualStyleBackColor = false;
			this->SortFileButton->Click += gcnew System::EventHandler(this, &MyForm::SortFileButton_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(8, 86);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(1110, 24);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Задание: Отсортировать вектора по убыванию и в файле по диагонали слева направо з"
				L"аменить бувкы \"О\" на звездочку.";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(328, 338);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 17);
			this->label6->TabIndex = 12;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->ClientSize = System::Drawing::Size(1118, 413);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->SortFileButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->File1ShowButton);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"Educational Practice";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: void T1() { //функция, которую передадим 1-му потоку
		char letter[100];
		ifstream file1;
		std::vector<char> v1, v2, v3, v4; //инициализация векторов
		file1.open("Original.txt");
		for (int i = 0; i < 10; i++)
		{
			file1 >> letter[i]; //присваиваем переменной списка значение буквы из файла
			v1.push_back(letter[i]); //добавляем эту букву в вектор
		}
		sort(v1.begin(), v1.end()); // сортировка вектора по алфавиту
		if (v1[0] == 'o') { v1[0] = '*'; } // замена в 1-ом векторе 1-ой буквы на звездочку, если это буква "O"
		writeToSortFile(v1); //обращение к функции из созданной DLL-библиотеки, которая записывает отсортированный вектор во 2-файл (Sorted.txt)
		for (int i = 10; i < 20; i++)
		{
			file1 >> letter[i];
			v2.push_back(letter[i]);
		}
		sort(v2.begin(), v2.end());
		if (v2[1] == 'o') { v2[1] = '*'; }
		writeToSortFile(v2);
		for (int i = 20; i < 30; i++)
		{
			file1 >> letter[i];
			v3.push_back(letter[i]);
		}
		sort(v3.begin(), v3.end());
		if (v3[2] == 'o') { v3[2] = '*'; }
		writeToSortFile(v3);
		for (int i = 30; i < 40; i++)
		{
			file1 >> letter[i];
			v4.push_back(letter[i]);
		}
		sort(v4.begin(), v4.end());
		if (v4[3] == 'o') { v4[3] = '*'; }
		writeToSortFile(v4);
		file1.close();
	}
	public: void T2() { //функция, которую передадим 2-му потоку
		char letter[100];
		ifstream file1;
		std::vector<char> v5, v6, v7;
		file1.open("Original.txt");
		for (int i = 40; i < 50; i++)
		{
			file1 >> letter[i];
			v5.push_back(letter[i]);
		}
		sort(v5.begin(), v5.end());
		if (v5[4] == 'o') { v5[4] = '*'; }
		writeToSortFile(v5);
		for (int i = 50; i < 60; i++)
		{
			file1 >> letter[i];
			v6.push_back(letter[i]);
		}
		sort(v6.begin(), v6.end());
		if (v6[5] == 'o') { v6[5] = '*'; }
		writeToSortFile(v6);
		for (int i = 60; i < 70; i++)
		{
			file1 >> letter[i];
			v7.push_back(letter[i]);
		}
		sort(v7.begin(), v7.end());
		if (v7[6] == 'o') { v7[6] = '*'; }
		writeToSortFile(v7);
	}
	public: void T3() { //функция, которую передадим 3-му потоку
		char letter[100];
		ifstream file1;
		std::vector<char> v8, v9, v10; //инициализация векторов
		file1.open("Original.txt");
		for (int i = 70; i < 80; i++)
		{
			file1 >> letter[i];
			v8.push_back(letter[i]);
		}
		sort(v8.begin(), v8.end());
		if (v8[7] == 'o') { v8[7] = '*'; }
		writeToSortFile(v8);
		for (int i = 80; i < 90; i++)
		{
			file1 >> letter[i];
			v9.push_back(letter[i]);
		}
		sort(v9.begin(), v9.end());
		if (v9[8] == 'o') { v9[8] = '*'; }
		writeToSortFile(v9);
		for (int i = 90; i < 100; i++)
		{
			file1 >> letter[i];
			v10.push_back(letter[i]);
		}
		sort(v10.begin(), v10.end());
		if (v10[9] == 'o') { v10[9] = '*'; }
		writeToSortFile(v10);
		file1.close();
	}

	private: System::Void File1ShowButton_Click(System::Object^ sender, System::EventArgs^ e) { //кнопка для отображения содержимого 1-го файла (1.txt) в textbox1
		String^ file1Path = "Original.txt"; // создаем переменную для хранения пути к файлу
		try
		{
			StreamReader^ file = File::OpenText(file1Path); //открываем файл
			textBox1->Text = file->ReadToEnd(); //записываем содержимое файла в TextBox
		}
		catch (Exception^ e)
		{
			MessageBox::Show(this, "Файл не был открыт", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
	}

	private: System::Void SortFileButton_Click(System::Object^ sender, System::EventArgs^ e) { //кнопка для отображения содержимого 2-го отсортированного файла (2.txt) в textbox2
		thread1 = gcnew Thread(gcnew ThreadStart(this, &MyForm::T1)); //создаем поток, выполняющий функцию T1
		thread2 = gcnew Thread(gcnew ThreadStart(this, &MyForm::T2));
		thread3 = gcnew Thread(gcnew ThreadStart(this, &MyForm::T3));
		thread1->Start(); // начинаем поток
		thread1->Join(); // функция для блокировки вызывающегося потока до тех пор, пока поток выполнения не завершится
		thread2->Start();
		thread2->Join();
		thread3->Start();
		thread3->Join();
		String^ file2Path = "Sorted.txt"; // создаем переменную для хранения пути к файлу
		try
		{
			StreamReader^ file = File::OpenText(file2Path); //открываем файл
			textBox2->Text = file->ReadToEnd(); //записываем содержимое файла в TextBox
		}
		catch (Exception^ e)
		{
			MessageBox::Show(this, "Файл не был открыт", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
	}
	};
}
