#include "Zajezdnia.h"

unique_ptr<Tramwaj> ZajezdniaBorek::BrygadaPierwsza(int nr) {
	return make_unique<PesaTwist>(nr);
}

unique_ptr<Tramwaj> ZajezdniaBorek::BrygadaDruga(int nr) {
	return make_unique<ModerusGamma>(nr);
}

unique_ptr<Tramwaj> ZajezdniaGaj::BrygadaPierwsza(int nr) {
	return make_unique<PesaTwist2010>(nr);
}

unique_ptr<Tramwaj> ZajezdniaGaj::BrygadaDruga(int nr) {
	return make_unique<ModerusBeta>(nr);
}

unique_ptr<Tramwaj> ZajezdniaO³bin::BrygadaPierwsza(int nr) { // po wroc³awiu jeŸd¿¹ sk³ady typu 2239+2240 (doczepa) ale uwzglêdniamy tylko numer boczny pierwszego wagonu 
	return make_unique<Konstal>(nr);
}

unique_ptr<Tramwaj> ZajezdniaO³bin::BrygadaDruga(int nr) { // tak samo jak w przypadku Konstali
	return make_unique<Protram>(nr);
}