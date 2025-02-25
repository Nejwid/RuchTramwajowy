#pragma once
#include <wx/wx.h>
#include <wx/listbox.h>
#include <vector>

class Dyspozytornia;

using namespace ::std;

enum IDs {
	TRAM_SETUP_ID = 0,
	LINE_SETUP_ID = 1,
	START_SIMULATION_ID = 2,
	WYBIERZ_TRAMWAJ_ID = 3,
	WYBIERZ_CZAS_ID = 4,
	DODAJ_TRAMWAJ_ID = 5,
	SHOW_SETUP_ID = 6,
	CONFIG_RESET_ID = 7,
	USTAW_CZAS_ID = 8,
	WYNIKI_ID = 9,
};

class MainFrame : public wxFrame {
private:
	Dyspozytornia* Dy�urny;

	vector<string> tramwaje, linie;
	vector<int> odjazdy;

	wxPanel* panel;

	wxStaticBitmap* t�o;
	wxStaticText* text;

	wxButton* konfiguracja;
	wxButton* resetKonfiguracji;
	wxButton* dodajTramwaj;
	wxButton* ustawCzas;
	wxButton* rozpocznijSymulacj�;

	wxTextCtrl* czasOdjazdu;

	wxListBox* wyb�rTramwaju;
	wxListBox* wyb�rLinii;
	wxListBox* parametryKonfiguracji;
	wxListBox* wynikSymulacji;

	wxString wybranyTramwaj, wybranaLinia;
	long wybranyCzas;

	void RodzajeTramwaj�w();
	void RodzajeLinii();

	void ResetKonfiguracji(wxCommandEvent& event);
	void DodajElementy(wxCommandEvent& event);

	void Wyb�rTramwaju(wxCommandEvent& event);
	void Wyb�rLinii(wxCommandEvent& event);
	void Wyb�rCzasu(wxCommandEvent& event);

	void RozpocznijSymulacje(wxCommandEvent& event);
	void PobierzWyniki();

	void Za�adujT�o(const string&nazwa);

public:
	MainFrame(const wxString& title);

	wxDECLARE_EVENT_TABLE();
};