#include "Game.h"



using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(int Arg_N, char ** Arg_V) {
	SDL_Init(SDL_INIT_EVERYTHING);
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MadHype::Game form;
	Application::Run(%form);
	return 0;
}

