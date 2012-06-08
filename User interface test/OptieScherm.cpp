/*
 * OptieScherm.cpp
 *
 *  Created on: 5 mrt. 2012
 *      Author: Luuk
 */


#include "OptieScherm.h"

bool hit; // boolean om te kijken of een label is geraakt

OptieScherm::OptieScherm( Screen* parent )
{
	//schermgroottes definieren
	MAExtent screenSize = maGetScrSize();
	int screenWidth = EXTENT_X( screenSize );
	int screenHeight = EXTENT_Y( screenSize );

	this->parent = parent;

	//font halen uit res.lst
	Font* font = new MAUI::Font(RES_FONT);
	WidgetSkin* skin = new WidgetSkin( RES_SELECTED, RES_UNSELECTED, 16, 32, 16, 32, false, false );

	//label maken
	Label* label = new Label(0,0,0,0,NULL);

	//stelt achtergrondkleur in
	label->setBackgroundColor(0x000000);

	// zet als standaard en wisselt met fotoscherm
	this->setMain( label );


	//maakt rode knop
	this->roodLabel = new Label( screenWidth/2-50, 155, 80, 30, label, "  Rood", 0, font );
	roodLabel->setSkin( skin );
	this->kleurLabels.add( roodLabel );	//voeg toe aan vector

	//maakt groene knop
	this->groenLabel = new Label( screenWidth/2-50, 190, 80, 30, label, "  Groen", 0, font );
	groenLabel->setSkin( skin );
	this->kleurLabels.add( groenLabel );	//voeg toe aan vector

	//maakt blauwe knop
	this->blauwLabel = new Label( screenWidth/2-50, 225, 80, 30, label, "  Blauw", 0, font );
	blauwLabel->setSkin( skin );
	this->kleurLabels.add( blauwLabel );	//voeg toe aan vector

	//maakt toepas knop
	this->toepasLabel = new Label( screenWidth/2-50, 275, 80, 30, label, "  toepassen", 0, font );
	toepasLabel->setSkin( skin );

	//stelt naam in van plaatje
	this->imageTekst = new EditBox( 50, 50, 150, 30, label, "   plaatje1", 0x555500, font, true, false, 20, EditBox::IM_STANDARD );
	this->imageTekst->setSkin(skin);


	//stelt breedte in van plaatje
	this->imageSize = new EditBox( 50, 80, 40, 30, label, "120", 0x555500, font, true, false, 3, EditBox::IM_QWERTY);
	this->imageSize->setSkin(skin);

}


OptieScherm::~OptieScherm()
{
}


//kleurveranderingen als je op knop drukt (pijltjes omhoog omlaag)
void OptieScherm::keyPressEvent(int keyCode, int nativeCode)
{
	for( int i= 0; i<kleurLabels.size(); i++ )
	{
		if (keyCode == MAK_DOWN)
		{
			if (kleurLabels[0]->isSelected()) // van rood naar groen
			{
				achtergrondKleur = 0x00ff00;
				kleurLabels[0]->setSelected(false);
				kleurLabels[1]->setSelected(true);
				break;
			}
			else if (kleurLabels[1]->isSelected())// van groen naar blauw
			{
				achtergrondKleur= 0x0000ff;
				kleurLabels[1]->setSelected(false);
				kleurLabels[2]->setSelected(true);
				break;
			}
		}
		if (keyCode == MAK_UP)
		{
			if (kleurLabels[2]->isSelected()) // van blauw naar groen
			{
				achtergrondKleur = 0x00ff00;
				kleurLabels[2]->setSelected(false);
				kleurLabels[1]->setSelected(true);
				break;
			}
			else if (kleurLabels[1]->isSelected())// van groen naar rood
			{
				achtergrondKleur = 0xff0000;
				kleurLabels[1]->setSelected(false);
				kleurLabels[0]->setSelected(true);
				break;
			}
		}
	}


	if (keyCode == MAK_FIRE)
	{
		parent->show();
	}
}


// in geval van touching
void OptieScherm::pointerPressEvent(MAPoint2d point)
{

	for( int i= 0; i<kleurLabels.size(); i++ )
	{
		// ... controleer of er label is geraakt. Dit is nodig om deselecten bij klik niet op label te voorkomen.
		if (kleurLabels[i]->contains( point.x, point.y))
		{
			hit = true;
		}
		else if(!hit)
		{
			hit = false;
		}
	}

	// als er inderdaad een label geraakt is, controleer welk label dit is, en stel kleur in.
	if (hit)
	{
		hit = false;
		for( int i= 0; i<kleurLabels.size(); i++ )
		{
			if ( kleurLabels[i]->contains( point.x, point.y) )
			{
				kleurLabels[i]->setSelected(true);
				if (i == 0 ) // rood
				{
					achtergrondKleur = 0xff0000;
				}
				else if (i == 1) // groen
				{
					achtergrondKleur = 0x00ff00;
				}
				else if (i == 2 ) // blauw
				{
					achtergrondKleur= 0x0000ff;
				}
			}
			else
			{
				kleurLabels[i]->setSelected(false);
			}
		}
	}

	if ( imageTekst->contains(point.x, point.y) )
	{
		imageTekst->setSelected(true);
	}
	else
	{
		imageTekst->setSelected(false);
	}

	if (imageSize->contains(point.x, point.y))
	{
		imageSize->setSelected(true);
	}
	else
	{
		imageSize->setSelected(false);
	}

	if (imageSize->contains(point.x, point.y))
	{
		imageSize->setSelected(true);
	}
	else
	{
		imageSize->setSelected(false);
	}


	if ( toepasLabel->contains(point.x, point.y ) )
	{
		parent->show();
	}
}

//geef ingestelde achtergrondkleur terug
int OptieScherm::getAchtergrondOptie()
{
	return this->achtergrondKleur;
}

//geef ingestelde ImageSize terug
int OptieScherm::getImageSize()
{
	grootte = atoi( this->imageSize->getCaption().c_str() );
	return grootte;
}


//geef ingestelde ImageTekst terug
const BasicString<char> OptieScherm::getImagetekst()
{
	return this->imageTekst->getCaption();
}



