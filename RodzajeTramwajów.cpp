#include "RodzajeTramwaj�w.h"
#include "Tramwaj.h"

// ---------------------------- RODZAJE TRAMWAJ�W ---------------------------- // wzorzec fabryki

ModerusGamma::ModerusGamma(int nr) : Tramwaj(nr) {
	this->czasObs�ugiPrzystanku = 5;
}

string ModerusGamma::ModelTramwaju() {
	return "Moderus Gamma LF 07 AC " + to_string(numerBoczny);
}

// ---------------------------------------- //

ModerusBeta::ModerusBeta(int nr) : Tramwaj(nr) {
	this->czasObs�ugiPrzystanku = 5;
}

string ModerusBeta::ModelTramwaju() {
	return "Moderus Beta MF 24 AC " + to_string(numerBoczny);
}

// ---------------------------------------- //

PesaTwist::PesaTwist(int nr) : Tramwaj(nr) {
	this->czasObs�ugiPrzystanku = 7;
}

string PesaTwist::ModelTramwaju() {
	return "Pesa Twist 146n " + to_string(numerBoczny);
}

// ---------------------------------------- //

PesaTwist2010::PesaTwist2010(int nr) : Tramwaj(nr) {
	this->czasObs�ugiPrzystanku = 7;
}

string PesaTwist2010::ModelTramwaju() {
	return "Pesa Twist 2010 NW " + to_string(numerBoczny);
}

// ---------------------------------------- //

Konstal::Konstal(int nr) : Tramwaj(nr) {
	this->czasObs�ugiPrzystanku = 9;
}

string Konstal::ModelTramwaju() {
	return "Konstal 105 Na " + to_string(numerBoczny);
}

// ---------------------------------------- //

Protram::Protram(int nr) : Tramwaj(nr) {
	this->czasObs�ugiPrzystanku = 9;
}

string Protram::ModelTramwaju() {
	return "Protram 105 NWr " + to_string(numerBoczny);
}