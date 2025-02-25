#include "Rozk³adJazdy.h"
#include "Przystanek.h"

Rozk³adJazdy::Rozk³adJazdy() {
	
	list<pair<shared_ptr<Przystanek>, int>> _2, _4, _5, _10, _11, _12, _17, _21, _22;

	this->ArkadyCapitol = make_shared<Przystanek>("Arkady Capitol");
	this->ArkadyCapitol_2 = make_shared<Przystanek>("Arkady Capitol 2");
	this->Bardzka = make_shared<Przystanek>("Bardzka");
	this->Biskupin = make_shared<Przystanek>("Biskupin");
	this->DworzecAutobusowy = make_shared<Przystanek>("Dworzec Autobusowy");
	this->DworzecG³ówny = make_shared<Przystanek>("Dworzec Glowny");
	this->FAT = make_shared<Przystanek>("FAT");
	this->Gaj = make_shared<Przystanek>("Gaj");
	this->GaleriaDominikañska = make_shared<Przystanek>("Galeria Dominikanska");
	this->Hallera = make_shared<Przystanek>("Hallera");
	this->Kochanowskiego = make_shared<Przystanek>("Kochanowskiego");
	this->Kromera = make_shared<Przystanek>("Kromera");
	this->Krakowska = make_shared<Przystanek>("Krakowska");
	this->Ksiê¿eMa³e = make_shared<Przystanek>("Ksieze Male");
	this->Kwiska = make_shared<Przystanek>("Kwiska");
	this->PlacBema = make_shared<Przystanek>("Pl Bema");
	this->PlacGrunwaldzki = make_shared<Przystanek>("Pl Grunwaldzki");
	this->PlacJanaPaw³a = make_shared<Przystanek>("Pl Jana Pawla");
	this->PlacLegionów = make_shared<Przystanek>("Pl Legionow");
	this->PlacWróblewskiego = make_shared<Przystanek>("Pl Wroblewskiego");
	this->Sêpolno = make_shared<Przystanek>("Sepolno");
	this->StadionLotnicza = make_shared<Przystanek>("Stadion Lotnicza");
	this->Œwidnicka = make_shared<Przystanek>("Swidnicka");
	this->Tarnogaj = make_shared<Przystanek>("Tarnogaj");
	this->Zoo = make_shared<Przystanek>("ZOO");

	//-----------------------------------------------------// tworzymy rozk³ad

	_2 = {
		{Hallera, 4},
		{ArkadyCapitol_2, 8},
		{DworzecG³ówny, 3},
		{GaleriaDominikañska, 4},
		{PlacGrunwaldzki, 9},
		{Zoo, 5},
		{Biskupin, 6}
	}; for (const auto& it : _2) linia_2.push(it);

	_4 = {
		{FAT, 5},
		{PlacLegionów, 10},
		{ArkadyCapitol, 2},
		{DworzecG³ówny, 3},
		{PlacWróblewskiego, 7},
		{PlacGrunwaldzki, 4},
		{Zoo, 5},
		{Biskupin, 6}
	}; for (const auto& it : _4) linia_4.push(it);

	_5 = {
		{FAT, 3},
		{PlacLegionów, 10},
		{ArkadyCapitol, 2},
		{DworzecG³ówny, 3},
		{GaleriaDominikañska, 4},
		{PlacWróblewskiego, 2},
		{Krakowska, 5},
		{Ksiê¿eMa³e, 5},
	}; for (const auto& it : _5) linia_5.push(it);

	_10 = {
		{StadionLotnicza, 12},
		{Kwiska, 9},
		{PlacJanaPaw³a, 10},
		{Œwidnicka, 6},
		{GaleriaDominikañska, 2},
		{PlacGrunwaldzki, 9},
		{Zoo, 5},
		{Biskupin, 6}
	}; for (const auto& it : _10) linia_10.push(it);

	_11 = {
		{FAT, 5},
		{PlacLegionów, 10},
		{Œwidnicka, 5},
		{GaleriaDominikañska, 3},
		{PlacBema, 5},
		{Kromera, 9},
	}; for (const auto& it : _11) linia_11.push(it);

	_12 = {
		{Kwiska, 8},
		{PlacJanaPaw³a, 10},
		{Œwidnicka, 6},
		{GaleriaDominikañska, 2},
		{PlacGrunwaldzki, 8},
		{Kochanowskiego, 4},
		{Sêpolno, 7}
	}; for (const auto& it : _12) linia_12.push(it);

	_17 = {
		{Hallera, 10},
		{ArkadyCapitol_2, 8},
		{GaleriaDominikañska, 8},
		{PlacBema, 5},
		{Kochanowskiego, 7},
		{Sêpolno, 7}
	}; for (const auto& it : _17) linia_17.push(it);

	_21 = {
		{Kwiska, 9},
		{PlacJanaPaw³a, 10},
		{ArkadyCapitol, 7},
		{DworzecAutobusowy, 4},
		{Bardzka, 8},
		{Gaj, 5}
	}; for (const auto& it : _21) linia_21.push(it);

	_22 = {
		{Kwiska, 7},
		{PlacJanaPaw³a, 10},
		{ArkadyCapitol, 7},
		{DworzecG³ówny, 3},
		{Bardzka, 9},
		{Tarnogaj, 5}
	}; for (const auto& it : _22) linia_22.push(it);
}

queue<pair<shared_ptr<Przystanek>, int>> Rozk³adJazdy::Linia_2() const {
	return linia_2;
}

queue<pair<shared_ptr<Przystanek>, int>> Rozk³adJazdy::Linia_4() const {
	return linia_4;
}

queue<pair<shared_ptr<Przystanek>, int>> Rozk³adJazdy::Linia_5() const {
	return linia_5;
}

queue<pair<shared_ptr<Przystanek>, int>> Rozk³adJazdy::Linia_10() const {
	return linia_10;
}

queue<pair<shared_ptr<Przystanek>, int>> Rozk³adJazdy::Linia_11() const {
	return linia_11;
}

queue<pair<shared_ptr<Przystanek>, int>> Rozk³adJazdy::Linia_12() const {
	return linia_12;
}

queue<pair<shared_ptr<Przystanek>, int>> Rozk³adJazdy::Linia_17() const {
	return linia_17;
}

queue<pair<shared_ptr<Przystanek>, int>> Rozk³adJazdy::Linia_21() const {
	return linia_21;
}

queue<pair<shared_ptr<Przystanek>, int>> Rozk³adJazdy::Linia_22() const {
	return linia_22;
}