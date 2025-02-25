#pragma once
#include <queue>
#include <memory>
#include <mutex>
#include <future>
#include <list>
#include <iostream>

class Tramwaj;

using namespace::std;

class Przystanek {

protected:

	string nazwa;

	mutex mtx;

public:

	Przystanek();

	Przystanek(const string& nazwa);

	void RealizujPrzystanek(int czas); // funkcja przyjmuje docelowo czas obslugi przystanku przez konkretny tramwaj

	string Nazwa() const;
};

