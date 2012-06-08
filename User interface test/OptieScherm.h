/*
 * OptieScherm.h
 *
*  Created on: 5 mrt. 2012
 *      Author: Luuk
 */

#ifndef OPTIESCHERM_H_
#define OPTIESCHERM_H_


#include <MAUI/Screen.h>
#include <MAUI/Label.h>
#include <MAUI/EditBox.h>

#include <MAUTIL/Moblet.h>
#include <MAUTIL/Vector.h>

#include <mastdlib.h>

#include "MAHeaders.h"


using namespace MAUtil;
using namespace MAUI;


class OptieScherm : public Screen
{
private:
	Screen* parent; // parent screen (FotoScherm)

	Vector<Label*> kleurLabels; // array van achtergrond kleuren
	Label* roodLabel; // rode knop
	Label* groenLabel; // groene knop
	Label* blauwLabel; // blauwe knope
	EditBox* imageTekst; // tekst onder plaatje (om in te stellen)
	EditBox* imageSize; // grootte van plaatje (om in te stellen)
	Label* toepasLabel; // toepasknop
	int achtergrondKleur; // achtergrondkleur
	int grootte; // grootte van plaatje

public:
	OptieScherm( Screen* parent ); // constructor OptieScherm
	virtual ~OptieScherm(); // deconstructor OptieScherm

	void keyPressEvent(int keyCode, int nativeCode); // key event
	void pointerPressEvent(MAPoint2d point); // touch event

	int getAchtergrondOptie(); // haal op welke selectie er is gemaakt voor achtergrondkleur
	int getImageSize(); // geef grootte van plaatje
	const BasicString<char>getImagetekst(); //geeft text van editbox terug
};

#endif /* OPTIESCHERM_H_ */
