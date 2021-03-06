/*
This Source Code Form is subject to the
terms of the Mozilla Public License, v.
2.0. If a copy of the MPL was not
distributed with this file, You can
obtain one at
http://mozilla.org/MPL/2.0/.
*/

#ifndef ClassesH
#define ClassesH
//---------------------------------------------------------------------------
// Ra: zestaw klas do robienia wska�nik�w, aby uporz�dkowa� nag��wki
//---------------------------------------------------------------------------
class TTrack; // odcinek trajektorii
class TEvent;
class TTrain; // pojazd sterowany
class TDynamicObject; // pojazd w scenerii
class TGroundNode; // statyczny obiekt scenerii
class TAnimModel; // opakowanie egzemplarz modelu
class TAnimContainer; // fragment opakowania egzemplarza modelu
// class TModel3d; //siatka modelu wsp�lna dla egzemplarzy
class TSubModel; // fragment modelu (tu do wy�wietlania terenu)
class TMemCell; // kom�rka pami�ci
class cParser;
class TRealSound; // d�wi�k ze wsp�rz�dnymi XYZ
class TTextSound; // d�wi�k ze stenogramem
class TEventLauncher;
class TTraction; // drut
class TTractionPowerSource; // zasilanie drut�w

class TMoverParameters;
namespace _mover
{
class TLocation;
class TRotation;
};

namespace Mtable
{
class TTrainParameters; // rozk�ad jazdy
};

class TController; // obiekt steruj�cy poci�giem (AI)
class TNames; // obiekt sortuj�cy nazwy

typedef enum
{ // binarne odpowiedniki komend w kom�rce pami�ci
    cm_Unknown, // ci�g nierozpoznany (nie jest komend�)
    cm_Ready, // W4 zezwala na odjazd, ale semafor mo�e zatrzyma�
    cm_SetVelocity, // pr�dko�� poci�gowa zadawana na semaforze
    cm_RoadVelocity, // pr�dko�� drogowa
    cm_SectionVelocity, //ograniczenie pr�dko�ci na odcinku
    cm_ShuntVelocity, // pr�dko�� manewrowa na semaforze
    cm_SetProximityVelocity, // informacja wst�pna o ograniczeniu
    cm_ChangeDirection,
    cm_PassengerStopPoint,
    cm_OutsideStation,
    cm_Shunt,
    cm_Command // komenda pobierana z kom�rki
} TCommandType;

#endif
