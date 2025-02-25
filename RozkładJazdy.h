#pragma once
#include <list>
#include <string>
#include <memory>
#include <queue>
#include <list>

using namespace::std;

class Przystanek;

class Rozk³adJazdy {
private:
	queue<pair<shared_ptr<Przystanek>, int>> linia_2, linia_4, linia_5, linia_10, linia_11, linia_12, linia_17, linia_21, linia_22;

	shared_ptr<Przystanek> StadionLotnicza, Kwiska, PlacJanaPaw³a, FAT, PlacLegionów, Hallera, ArkadyCapitol, ArkadyCapitol_2, DworzecG³ówny, Œwidnicka, Krakowska, Ksiê¿eMa³e,
		GaleriaDominikañska, PlacBema, PlacWróblewskiego, PlacGrunwaldzki, Kochanowskiego, Sêpolno, Zoo, Biskupin, Bardzka, Tarnogaj, Gaj, DworzecAutobusowy, Kromera;

public:
	
	Rozk³adJazdy();

	queue<pair<shared_ptr<Przystanek>, int>> Linia_2() const;

	queue<pair<shared_ptr<Przystanek>, int>> Linia_4() const;

	queue<pair<shared_ptr<Przystanek>, int>> Linia_5() const;

	queue<pair<shared_ptr<Przystanek>, int>> Linia_10() const;

	queue<pair<shared_ptr<Przystanek>, int>> Linia_11() const;

	queue<pair<shared_ptr<Przystanek>, int>> Linia_12() const;

	queue<pair<shared_ptr<Przystanek>, int>> Linia_17() const;

	queue<pair<shared_ptr<Przystanek>, int>> Linia_21() const;

	queue<pair<shared_ptr<Przystanek>, int>> Linia_22() const;
};