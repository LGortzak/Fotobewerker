/*
 * FotoScherm.cpp
 *
 *  Created on: 5 mrt. 2012
 *      Author: Luuk
 */


#include "FotoScherm.h"

FotoScherm::FotoScherm()
{
	//schermgroottes definieren
	MAExtent screenSize = maGetScrSize();
	int schermBreedte = EXTENT_X( screenSize );
	int schermHoogte = EXTENT_Y( screenSize );

	//font en skin instellen uit res.lst
	Font* font = new MAUI::Font(RES_FONT);
	WidgetSkin* skin = new WidgetSkin( RES_SELECTED, RES_UNSELECTED, 16, 32, 16, 32, false, false );

	//maak een label die andere widgets straks bevat, en een achtergrondkleur heeft
	achtergrondLabel = new Label(0,0,0,0,NULL);

	//stelt achtergrondkleur in
	achtergrondLabel->setBackgroundColor(0x000000);

	// stelt plaats van plaatje in
	imageTekst = new Label( schermBreedte/2 - 40, 250, 80, 30, achtergrondLabel, "", 0, font);
	imageTekst->setSkin(skin);
	image = new Image(schermBreedte/2-60,schermHoogte/2-60, 120, 160, achtergrondLabel, false, false, RES_IMAGE1);

	//zet als standaard, wisselt met optiescherm
	this->setMain(achtergrondLabel);

	//het optiescherm
	this->optieScherm = new OptieScherm( this );
}


FotoScherm::~FotoScherm()
{

}


//show() override de show() van de super klasse (Screen), omdat we bij showen eerst opties willen ophalen
void FotoScherm::show()
{
	//roep de show() van de superklasse (Screen) aan
	this->Screen::show();

	//haal informatie achtergrondkleur op van optiescherm
	this->achtergrondLabel->setBackgroundColor( this->optieScherm->getAchtergrondOptie() );

	//haal informatie imagetekst op van optiescherm
	imageTekst->setCaption(this->optieScherm->getImagetekst());

	//haal informatie over afmetingen afbeeldingen
	this->image->setWidth(this->optieScherm->getImageSize());
	this->image->setHeight(this->optieScherm->getImageSize());
}


//bij indrukken van de MAK_FIRE toets, laat optiescherm zien
void FotoScherm::keyPressEvent(int keyCode, int nativeCode)
{
	if (keyCode == MAK_FIRE)
	{
		optieScherm->show();
	}
}

//bij touch op scherm, laat optiescherm zien.
void FotoScherm::pointerPressEvent(MAPoint2d point)
{
	optieScherm->show();
}
