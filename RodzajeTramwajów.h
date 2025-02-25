#pragma once
#include "Tramwaj.h"

// ---------------------------- RODZAJE TRAMWAJÓW ---------------------------- //

class ModerusGamma : public Tramwaj {

private:

public:
	ModerusGamma(int nr);
	string ModelTramwaju() override;
};

// -------------------------------------------- //

class ModerusBeta : public Tramwaj {

private:

public:
	ModerusBeta(int nr);
	string ModelTramwaju() override;
};

// -------------------------------------------- //

class PesaTwist : public Tramwaj {

private:

public:
	PesaTwist(int nr);
	string ModelTramwaju() override;
};

// -------------------------------------------- //

class PesaTwist2010 : public Tramwaj {

private:

public:
	PesaTwist2010(int nr);
	string ModelTramwaju() override;
};

// -------------------------------------------- //

class Konstal : public Tramwaj {

private:

public:
	Konstal(int nr);
	string ModelTramwaju() override;
};

// -------------------------------------------- //

class Protram : public Tramwaj {

private:

public:
	Protram(int nr);
	string ModelTramwaju() override;
};
