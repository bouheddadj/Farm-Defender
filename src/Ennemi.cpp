/**
@brief Description brève du fichier Ennemi.cpp
Description détaillée du fichier Ennemi.cpp
@author P2105542
@file Ennemi.cpp
@version 1.0
@date 2023/03/07
*/


#include "Vect2.h"
#include "Ennemi.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

const float XPntGenZSpw1 = 20 ;
const float YPntGenZSpw1 = 20 ;

const float XPntGenZSpw2 = 10 ;
const float YPntGenZSpw2 = 10 ;

const float XPntGenZSpw3 = 15 ;
const float YPntGenZSpw3 = 15 ;


Ennemi::Ennemi()
{   
    statut=true;
    temps_mort=0;
    type_en=zombi;
    sante=10;
    degat=5; ///1
    vitesse=0.2; //0.4;      //1
    if (type_en==zombi){
        int r=rand()%3;
        float X,Y;
    switch(r){
            case 0: {X=XPntGenZSpw1; Y=YPntGenZSpw1;
                    break;}
            case 1: {X=XPntGenZSpw2; Y=YPntGenZSpw2;
                    break;}
            case 2: {X=XPntGenZSpw3; Y=YPntGenZSpw3;
                    break;}
        }
        //cout<<X+((float)(rand()%21-10))<<" x  "<<endl;
    Vect2 pos(X+((float)(rand()%21-10)),Y+((float)(rand()%21-10)));
    position=pos;
    Vect2 dir(10.f,-10.f);
    direction=dir;
    }
}



int Ennemi::get_degat()
{
	return degat;
}

Type_ennemi Ennemi::getType()const{
return type_en;
}



void Ennemi::deplacer()
{
    position=position+direction*(vitesse*2/3);
    //cout<<"deplace correct"<<endl;
    //faire tests avec le tableau de batiments
}

void Ennemi::enleverSante(int points_enleves){
    if(statut==true)
    {
        sante=sante-points_enleves;
        if(sante<=0)
        {
            statut=false;
        }
    }
}
/*
void Ennemi::afficher()
{
    cout<<"types d'ennemis :"<<endl;
    Type_ennemi a=zombi;
    Type_ennemi c=z_infectieu;
    Type_ennemi b=z_berserker;
    Type_ennemi d=pillard;
    cout<<"zombi = "<<a; 
    cout<<"zombi infectieu = ";
    cout<<c;

    cout<<" zombi berserker = "<<b;
    cout<<"pillard = "<<d<<endl;

    cout<<" Ennemi de type "<< type_en <<" avec un statut "<< statut<<" (0 elimine 1 vivant) "<<sante<<" points de sante ";
    cout<<"degat de :"<<degat<<endl;
    cout<<vitesse<<" vitesse    position: x"<< position.x<<" y "<<position.y<<endl;
    cout<<"direction x"<<direction.x<<"  y"<<direction.y<<endl;
}*/

Ennemi::~Ennemi()
{
    //dtor
}

Vect2 Ennemi::get_position()
{
	return position;
}

void Ennemi::set_pos(Vect2 posi)
{
    position=posi;
}

void Ennemi::set_direction(Vect2 dir){
    direction=dir;

}

int Ennemi::get_sante(){
    return sante;
}

void Ennemi::afficher()
{
    cout << "Type ennemi: " <<this->getType() <<endl;
    cout << "Sante ennemi: " <<this->get_sante() <<endl;
}


bool Ennemi::get_statut(){
    return statut;
}

float Ennemi::splitX()
{
    return position.x;
}

float Ennemi::splitY()
{
    return position.y;
}

Ennemi::Ennemi(Type_ennemi typeENnemi){
    statut=true;
    temps_mort=0;
    type_en=typeENnemi;
	Vect2 dir(10.f,-10.f);
    direction=dir;
    
    /*Type_ennemi zombi;
	Type_ennemi z_infectieu;
	Type_ennemi z_berserker;
	Type_ennemi pillard;*/
    
    if (type_en==zombi)
    {
        sante=10;
        degat=1;
        vitesse=0.2;
        int r=rand()%3;
        float X,Y;
         switch(r){
            case 0: {X=XPntGenZSpw1; Y=YPntGenZSpw1;
                    break;}
            case 1: {X=XPntGenZSpw2; Y=YPntGenZSpw2;
                    break;}
            case 2: {X=XPntGenZSpw3; Y=YPntGenZSpw3;
                    break;}
        }
    Vect2 pos(X+((float)(rand()%21-10)),Y+((float)(rand()%21-10)));
    position=pos;
    }
	if(type_en==z_infectieu){
		sante=10;
        degat=2;
        vitesse=0.5;
        int r=rand()%3;
        float X,Y;
		switch(r){
            case 0: {X=XPntGenZSpw1; Y=YPntGenZSpw1;
                    break;}
            case 1: {X=XPntGenZSpw2; Y=YPntGenZSpw2;
                    break;}
            case 2: {X=XPntGenZSpw3; Y=YPntGenZSpw3;
                    break;}
        }
    Vect2 pos(X+((float)(rand()%21-10)),Y+((float)(rand()%21-10)));
    position=pos;
	}
	if(type_en==z_berserker){
		sante=10;
        degat=2;
        vitesse=0.4;
        int r=rand()%3;
        float X,Y;
		switch(r){
            case 0: {X=XPntGenZSpw1; Y=YPntGenZSpw1;
                    break;}
            case 1: {X=XPntGenZSpw2; Y=YPntGenZSpw2;
                    break;}
            case 2: {X=XPntGenZSpw3; Y=YPntGenZSpw3;
                    break;}
        }
    Vect2 pos(X+((float)(rand()%21-10)),Y+((float)(rand()%21-10)));
    position=pos;
	}
	if(type_en==pillard){
		sante=10;
        degat=3;
        vitesse=0.8;
        int r=rand()%3;
        float X,Y;
		switch(r){
            case 0: {X=XPntGenZSpw1; Y=YPntGenZSpw1;
                    break;}
            case 1: {X=XPntGenZSpw2; Y=YPntGenZSpw2;
                    break;}
            case 2: {X=XPntGenZSpw3; Y=YPntGenZSpw3;
                    break;}
        }
    Vect2 pos(X+((float)(rand()%21-10)),Y+((float)(rand()%21-10)));
    position=pos;
	}
    
}

float Ennemi::get_temps_mort(){
    return temps_mort;
}

void Ennemi::add_temps_mort(float tempsMort){
    temps_mort=temps_mort+tempsMort+5;
}