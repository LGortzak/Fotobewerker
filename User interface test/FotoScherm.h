/*
 * FotoScherm.h
 *
 *  Created on: 5 mrt. 2012
 *      Author: Luuk
 */

#ifndef FOTOSCHERM_H_
#define FOTOSCHERM_H_


//De includes zijn nodig zodat we screens, labels, images en fonts kunnen maken
#include <MAUtil/Moblet.h>
#include <MAUI/Screen.h>
#include <MAUI/Label.h>
#include <MAUI/Image.h>
#include <MAUI/Font.h>

// standaard librarys
#include <ma.h>
#include "MAHeaders.h"

//fotoscherm bevat een optiescherm
#include "OptieScherm.h"


//zorgt ervoor dat je niet overal MAUtil:: en MAUI:: achter hoeft te zetten
using namespace MAUtil;
using namespace MAUI;



//screen klasse
class FotoScherm : public Screen
{
private:
	OptieScherm* optieScherm; // het OptieScherm
	Label* achtergrondLabel; // achtergrondkleur
	Label* imageTekst; // tekst onder het plaatje
	Image* image; // het plaatje

public:
	FotoScherm();
	virtual ~FotoScherm();
	void run( MAEvent event );

	//kan key en touch events opvangen
	void keyPressEvent(int keyCode, int nativeCode);
	void pointerPressEvent(MAPoint2d point);

	//bevat een show() functie die alle eigenschappen update bij aanroep met waarden uit OptieScherm
	void show();
};

#endif /* FOTOSCHERM_H_ */
