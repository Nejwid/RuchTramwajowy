#include "MainFrame.h"
#include "Dyspozytornia.h"

void MainFrame::RodzajeTramwaj�w() {
	wyb�rTramwaju->Append("Moderus Beta MF 24 AC");
	wyb�rTramwaju->Append("Moderus Gamma LF 07 AC");
	wyb�rTramwaju->Append("Pesa Twist 2010 Nw");
	wyb�rTramwaju->Append("Pesa Twist 146n");
	wyb�rTramwaju->Append("Konstal 105 Na");
	wyb�rTramwaju->Append("Protram 105 NWr");
}

void MainFrame::RodzajeLinii() {
	wyb�rLinii->Append("2");
	wyb�rLinii->Append("4");
	wyb�rLinii->Append("5");
	wyb�rLinii->Append("10");
	wyb�rLinii->Append("11");
	wyb�rLinii->Append("12");
	wyb�rLinii->Append("17");
	wyb�rLinii->Append("21");
	wyb�rLinii->Append("22");
}

void MainFrame::Wyb�rTramwaju(wxCommandEvent& event) {
	int index = event.GetSelection();
	if (index != wxNOT_FOUND) {
		wybranyTramwaj = event.GetString();
	}
	wxLogStatus(wybranyTramwaj);
	return;
}

void MainFrame::Wyb�rLinii(wxCommandEvent& event) {
	int index = event.GetSelection();
	if (index != wxNOT_FOUND) {
		wybranaLinia = event.GetString();
	}
	wxLogStatus(wybranaLinia);
	return;
}

void MainFrame::Wyb�rCzasu(wxCommandEvent& event) {
	long temp = -1;
	czasOdjazdu->GetValue().ToLong(&temp); // konwersja string na long int 
	if (temp >= 0 && temp <= 60) wybranyCzas = temp; // sprawdzenie czy miesci sie w godzine bo tyle maks trwa symulacja
	wxLogStatus(wxString::Format("%ld", wybranyCzas) + " minut(y)");
	return;
}

void MainFrame::DodajElementy(wxCommandEvent& event) {
	if(wybranaLinia != "" && wybranyTramwaj != "" && wybranyCzas != INT_MIN)
	parametryKonfiguracji->Append(wybranyTramwaj + ", linia " + wybranaLinia + ", odjazd +" + wxString::Format("%ld", wybranyCzas) + " minut(y)");
	parametryKonfiguracji->Refresh();
	tramwaje.push_back(string(wybranyTramwaj.ToStdString()));
	linie.push_back(wybranaLinia.ToStdString());
	odjazdy.push_back(static_cast<int>(wybranyCzas));
	wybranyCzas = INT_MIN;
}

void MainFrame::ResetKonfiguracji(wxCommandEvent& event) {
	parametryKonfiguracji->Clear();
	tramwaje.clear();
	linie.clear();
	odjazdy.clear();
}

void MainFrame::RozpocznijSymulacje(wxCommandEvent& event) {

	wyb�rTramwaju->Hide();
	wyb�rLinii->Hide();
	dodajTramwaj->Hide();
	resetKonfiguracji->Hide();
	rozpocznijSymulacj�->Hide();
	parametryKonfiguracji->Hide();
	czasOdjazdu->Hide();
	ustawCzas->Hide();

	text = new wxStaticText(panel, wxID_ANY, "symulacja w toku", wxPoint(200,200));
	wxFont font(18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	text->SetFont(font);
	text->Show();
	wxYield(); // wymuszanie wy�wieltenia static textu

	Layout();

	for (int i = 0; i < tramwaje.size(); i++) {
		Dy�urny->GUI_Setup(tramwaje[i], linie[i], odjazdy[i]);
	}
	Dy�urny->RealizujKursy(); // celowo ta funkcja blokuje nam g��wny w�tek �eby by�o wida� �e trwa symulacja
	
	text->Hide();
	this->PobierzWyniki();
	wynikSymulacji->Show();

	Layout();
}

void MainFrame::PobierzWyniki() {
	vector<string> wyniki = Dy�urny->Statystyki();
	for (string& it : wyniki) {
		wynikSymulacji->Append(it);
	}
}

void MainFrame::Za�adujT�o(const string& nazwa) {
	wxInitAllImageHandlers();
	wxBitmap bitmap(nazwa, wxBITMAP_TYPE_PNG);
	if (bitmap.IsOk()) {
		t�o = new wxStaticBitmap(panel, wxID_ANY, bitmap);
		t�o->SetPosition(wxPoint(800, 100));

	}
}








MainFrame::MainFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {

	Dy�urny = Dyspozytornia::GetInstance();
	
	wybranaLinia = ""; wybranyTramwaj = ""; wybranyCzas = INT_MIN;
	
	panel = new wxPanel(this, wxID_ANY);

	this->Za�adujT�o("Konstal105Na_bitmap.png");

	CreateStatusBar();

	wyb�rTramwaju = new wxListBox(panel, TRAM_SETUP_ID, wxPoint(100, 100), wxSize(150, 100), 0, nullptr, wxLB_SINGLE);
	this->RodzajeTramwaj�w();
	wyb�rLinii = new wxListBox(panel, LINE_SETUP_ID, wxPoint(260, 100), wxSize(50, 100), 0, nullptr, wxLB_SINGLE);
	this->RodzajeLinii();

	dodajTramwaj = new wxButton(panel, DODAJ_TRAMWAJ_ID, "dodaj do symulacji", wxPoint(155, 220), wxSize(120, 50));

	resetKonfiguracji = new wxButton(panel, CONFIG_RESET_ID, "reset", wxPoint(155, 280), wxSize(120, 50));

	rozpocznijSymulacj� = new wxButton(panel, START_SIMULATION_ID, "rozpocznij symulacje", wxPoint(155, 340), wxSize(120, 50));

	parametryKonfiguracji = new wxListBox(panel, SHOW_SETUP_ID, wxPoint(430, 100), wxSize(300, 100));

	czasOdjazdu = new wxTextCtrl(panel, WYBIERZ_CZAS_ID, "", wxPoint(355, 170), wxSize(30, 30));

	ustawCzas = new wxButton(panel, USTAW_CZAS_ID, "ustaw czas", wxPoint(320, 220), wxSize(100, 30));

	wynikSymulacji = new wxListBox(panel, WYNIKI_ID, wxPoint(260, 100), wxSize(350, 300));
	wynikSymulacji->Hide();

}

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_LISTBOX(TRAM_SETUP_ID, MainFrame::Wyb�rTramwaju)
EVT_LISTBOX(LINE_SETUP_ID, MainFrame::Wyb�rLinii)
EVT_BUTTON(DODAJ_TRAMWAJ_ID, MainFrame::DodajElementy)
EVT_BUTTON(CONFIG_RESET_ID, MainFrame::ResetKonfiguracji)
EVT_BUTTON(USTAW_CZAS_ID, MainFrame::Wyb�rCzasu)
EVT_BUTTON(START_SIMULATION_ID, MainFrame::RozpocznijSymulacje)
wxEND_EVENT_TABLE()