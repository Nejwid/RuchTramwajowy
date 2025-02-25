#include "App.h"
#include "MainFrame.h"

bool App::OnInit() {
	MainFrame* frame = new MainFrame("Symulacja Agentowa");
	frame->Show(true);
	return true;
}