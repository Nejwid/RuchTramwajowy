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
	Dyspozytornia* Dy¿urny;

	vector<string> tramwaje, linie;
	vector<int> odjazdy;

	wxPanel* panel;

	wxStaticBitmap* t³o;
	wxStaticText* text;

	wxButton* konfiguracja;
	wxButton* resetKonfiguracji;
	wxButton* dodajTramwaj;
	wxButton* ustawCzas;
	wxButton* rozpocznijSymulacjê;

	wxTextCtrl* czasOdjazdu;

	wxListBox* wybórTramwaju;
	wxListBox* wybórLinii;
	wxListBox* parametryKonfiguracji;
	wxListBox* wynikSymulacji;

	wxString wybranyTramwaj, wybranaLinia;
	long wybranyCzas;

	void RodzajeTramwajów();
	void RodzajeLinii();

	void ResetKonfiguracji(wxCommandEvent& event);
	void DodajElementy(wxCommandEvent& event);

	void WybórTramwaju(wxCommandEvent& event);
	void WybórLinii(wxCommandEvent& event);
	void WybórCzasu(wxCommandEvent& event);

	void RozpocznijSymulacje(wxCommandEvent& event);
	void PobierzWyniki();

	void Za³adujT³o(const string&nazwa);

public:
	MainFrame(const wxString& title);

	wxDECLARE_EVENT_TABLE();
};