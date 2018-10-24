#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void  main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//TestForma es el nombre del proyecto
	//Project1::MyForm ^form;
	Application::Run(gcnew DiscRoom::MyForm()); //Project 1 es el nombre del proyecto

}