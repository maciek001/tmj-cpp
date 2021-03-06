/*
This Source Code Form is subject to the
terms of the Mozilla Public License, v.
2.0. If a copy of the MPL was not
distributed with this file, You can
obtain one at
http://mozilla.org/MPL/2.0/.
*/

#include "system.hpp"
#include "classes.hpp"

#include "opengl/glew.h"
#include "opengl/glut.h"

#pragma hdrstop

#include "Camera.h"
#include "Usefull.h"
#include "Globals.h"
#include "Timer.h"
#include "mover.h"
#include "Console.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// TViewPyramid TCamera::OrgViewPyramid;
//={vector3(-1,1,1),vector3(1,1,1),vector3(-1,-1,1),vector3(1,-1,1),vector3(0,0,0)};

const vector3 OrgCrossPos = vector3(0, -10, 0);

void TCamera::Init(vector3 NPos, vector3 NAngle)
{

    pOffset = vector3(-0.0, 0, 0);
    vUp = vector3(0, 1, 0);
    //    pOffset= vector3(-0.8,0,0);
    CrossPos = OrgCrossPos;
    CrossDist = 10;
    Velocity = vector3(0, 0, 0);
    OldVelocity = vector3(0, 0, 0);
    Pitch = NAngle.x;
    Yaw = NAngle.y;
    Roll = NAngle.z;
    Pos = NPos;

    //    Type= tp_Follow;
    Type = (Global::bFreeFly ? tp_Free : tp_Follow);
    //    Type= tp_Free;
};

void TCamera::OnCursorMove(double x, double y)
{
    // McZapkie-170402: zeby mysz dzialala zawsze    if (Type==tp_Follow)
    Pitch += y;
    Yaw += -x;
    if (Yaw > M_PI)
        Yaw -= 2 * M_PI;
    else if (Yaw < -M_PI)
        Yaw += 2 * M_PI;
    if (Type == tp_Follow) // je�eli jazda z pojazdem
    {
        Fix(Pitch, -M_PI_4, M_PI_4); // ograniczenie k�ta spogl�dania w d� i w g�r�
        // Fix(Yaw,-M_PI,M_PI);
    }
}

void TCamera::Update()
{
    // ABu: zmiana i uniezaleznienie predkosci od FPS
    double a = (Console::Pressed(VK_SHIFT) ? 5.00 : 1.00);
    if (Console::Pressed(VK_CONTROL))
        a = a * 100;
    //    OldVelocity=Velocity;
    if (FreeFlyModeFlag == true)
        Type = tp_Free;
    else
        Type = tp_Follow;
    if (Type == tp_Free)
    {
        if (Console::Pressed(Global::Keys[k_MechUp]))
            Velocity.y += a;
        if (Console::Pressed(Global::Keys[k_MechDown]))
            Velocity.y -= a;
        // McZapkie-170402: zeby nie bylo konfliktow
        /*
                if (Console::Pressed(VkKeyScan('d')))
                    Velocity.x+= a*Timer::GetDeltaTime();
                if (Console::Pressed(VkKeyScan('a')))
                    Velocity.x-= a*Timer::GetDeltaTime();
                if (Console::Pressed(VkKeyScan('w')))
                    Velocity.z-= a*Timer::GetDeltaTime();
                if (Console::Pressed(VkKeyScan('s')))
                    Velocity.z+= a*Timer::GetDeltaTime();

                if (Console::Pressed(VK_NUMPAD4) || Console::Pressed(VK_NUMPAD7) ||
           Console::Pressed(VK_NUMPAD1))
                    Yaw+= +1*M_PI*Timer::GetDeltaTime();

                if (Console::Pressed(VK_NUMPAD6) || Console::Pressed(VK_NUMPAD9) ||
           Console::Pressed(VK_NUMPAD3))
                    Yaw+= -1*M_PI*Timer::GetDeltaTime();

                if (Pressed(VK_NUMPAD2) || Console::Pressed(VK_NUMPAD1) ||
           Console::Pressed(VK_NUMPAD3))
                    Pitch+= -1*M_PI*Timer::GetDeltaTime();

                if (Console::Pressed(VK_NUMPAD8) || Console::Pressed(VK_NUMPAD7) ||
           Console::Pressed(VK_NUMPAD9))
                    Pitch+= +1*M_PI*Timer::GetDeltaTime();
                if (Console::Pressed(VkKeyScan('.')))
                    Roll+= -1*M_PI*Timer::GetDeltaTime();
                if (Console::Pressed(VkKeyScan(',')))
                    Roll+= +1*M_PI*Timer::GetDeltaTime();

                if (Console::Pressed(VK_NUMPAD5))
                    Pitch=Roll= 0.0f;
        */

        // McZapkie-170402: poruszanie i rozgladanie we free takie samo jak w follow
        if (Console::Pressed(Global::Keys[k_MechRight]))
            Velocity.x += a;
        if (Console::Pressed(Global::Keys[k_MechLeft]))
            Velocity.x -= a;
        if (Console::Pressed(Global::Keys[k_MechForward]))
            Velocity.z -= a;
        if (Console::Pressed(Global::Keys[k_MechBackward]))
            Velocity.z += a;
        // gora-dol
        // if (Console::Pressed(VK_NUMPAD9)) Pos.y+=0.1;
        // if (Console::Pressed(VK_NUMPAD3)) Pos.y-=0.1;

        // McZapkie: zeby nie hustalo przy malym FPS:
        //        Velocity= (Velocity+OldVelocity)/2;
        //    matrix4x4 mat;
        vector3 Vec = Velocity;
        Vec.RotateY(Yaw);
        Pos = Pos + Vec * Timer::GetDeltaRenderTime(); // czas bez pauzy
        Velocity = Velocity / 2; // p�ynne hamowanie ruchu
        //    double tmp= 10*DeltaTime;
        //        Velocity+= -Velocity*10 * Timer::GetDeltaTime();//( tmp<1 ? tmp : 1 );
        //        Type= tp_Free;
    }
}

vector3 TCamera::GetDirection()
{
    matrix4x4 mat;
    vector3 Vec;
    Vec = vector3(0, 0, 1);
    Vec.RotateY(Yaw);

    return (Normalize(Vec));
}

// bool TCamera::GetMatrix(matrix4x4 &Matrix)
bool TCamera::SetMatrix()
{
    glRotated(-Roll * 180.0f / M_PI, 0, 0, 1); // po wy��czeniu tego kr�ci si� pojazd, a sceneria
    // nie
    glRotated(-Pitch * 180.0f / M_PI, 1, 0, 0);
    glRotated(-Yaw * 180.0f / M_PI, 0, 1, 0); // w zewn�trznym widoku: kierunek patrzenia

    if (Type == tp_Follow)
    {
        //        gluLookAt(Pos.x+pOffset.x,Pos.y+pOffset.y,Pos.z+pOffset.z,
        //                LookAt.x+pOffset.x,LookAt.y+pOffset.y,LookAt.z+pOffset.z,vUp.x,vUp.y,vUp.z);
        //        gluLookAt(Pos.x+pOffset.x,Pos.y+pOffset.y,Pos.z+pOffset.z,
        //                LookAt.x+pOffset.x,LookAt.y+pOffset.y,LookAt.z+pOffset.z,vUp.x,vUp.y,vUp.z);
        gluLookAt(Pos.x, Pos.y, Pos.z, LookAt.x, LookAt.y, LookAt.z, vUp.x, vUp.y,
                  vUp.z); // Ra: pOffset is zero
        //        gluLookAt(Pos.x,Pos.y,Pos.z,Pos.x+Velocity.x,Pos.y+Velocity.y,Pos.z+Velocity.z,0,1,0);
        //        return true;
    }

    if (Type == tp_Satelite)
        Pitch = M_PI * 0.5;

    if (Type != tp_Follow)
    {
        glTranslated(-Pos.x, -Pos.y, -Pos.z); // nie zmienia kierunku patrzenia
    }

    Global::SetCameraPosition(Pos); // by�o +pOffset
    return true;
}

void TCamera::SetCabMatrix(vector3 &p)
{ // ustawienie widoku z kamery bez przesuni�cia robionego przez OpenGL - nie powinno tak trz���
    glRotated(-Roll * 180.0f / M_PI, 0, 0, 1);
    glRotated(-Pitch * 180.0f / M_PI, 1, 0, 0);
    glRotated(-Yaw * 180.0f / M_PI, 0, 1, 0); // w zewn�trznym widoku: kierunek patrzenia
    if (Type == tp_Follow)
        gluLookAt(Pos.x - p.x, Pos.y - p.y, Pos.z - p.z, LookAt.x - p.x, LookAt.y - p.y,
                  LookAt.z - p.z, vUp.x, vUp.y, vUp.z); // Ra: pOffset is zero
}

void TCamera::RaLook()
{ // zmiana kierunku patrzenia - przelicza Yaw
    vector3 where = LookAt - Pos + vector3(0, 3, 0); // troch� w g�r� od szyn
    if ((where.x != 0.0) || (where.z != 0.0))
        Yaw = atan2(-where.x, -where.z); // k�t horyzontalny
    double l = Length3(where);
    if (l > 0.0)
        Pitch = asin(where.y / l); // k�t w pionie
};

void TCamera::Stop()
{ // wy��cznie bezw�adnego ruchu po powrocie do kabiny
    Type = tp_Follow;
    Velocity = vector3(0, 0, 0);
};
