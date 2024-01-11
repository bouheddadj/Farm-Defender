#include "Jeu.h"
#include <unistd.h> //sleep?
#include <iostream>
#include <vector>
using namespace std;



void Jeu::BCproduction(bool est_vivant)
{
    if(est_vivant){
    stockage.ajouterRessource("gold", 10);
    stockage.ajouterRessource("pierre", 10);
    stockage.ajouterRessource("bois", 10);
    stockage.ajouterRessource("nourriture", 10);}
}

void Jeu::BCdegat(int degat)
{
    BCm_pointsDeVie -= degat;
}

bool Jeu::BCest_vivant()
{
    if(BCm_pointsDeVie<=0){
        return false;
    }else{return true;}
}

void Jeu::BCsetPos (float x, float y){
    BCpos.x = x;
    BCpos.y = y;
}

Vect2 Jeu::BCgetPos(){
    return BCpos;
}





Jeu::Jeu(){

    BCm_pointsDeVie = 3000;



    jeu_largeur=40; jeu_hauteur=20;
    const int haut = 30;
    const int larg = 60;
    BCsetPos(((larg/2)+0.5)-1,((haut*haut)/50)-(haut/2)+11);
 
    BCm_carac = 'O';
    BCfloatdeg=0.1;
    BatimentDefense bat1(TypeBatiment::Tourelle);
    BatimentDefense bat2(TypeBatiment::Canon);  

    BatimentDefense bat3(TypeBatiment::Canon);  
    bat3.setPosition (10,2);

    tabBatDef.push_back(bat1);
    tabBatDef.push_back(bat2);
    tabBatDef.push_back(bat3);

  //  tabBatDef.at(0).setPosition(100,100);
   // tabBatDef.at(1).setPosition(750,200);
     tabBatDef.at(0).setPosition(5,5);
    tabBatDef.at(1).setPosition(7,7);

    Ennemi enm1(Type_ennemi::zombi);
    tabEnnemi.push_back(enm1);

    Vect2 pos1(15,17);

    Vect2 dire(1,0);

    tabEnnemi.at(0).set_pos(pos1);

    tabEnnemi.at(0).set_direction(dire);

    Ennemi zombiTest;

    Vect2 posZombi(12,17);
    zombiTest.set_pos(posZombi);
    Vect2 dire2(1,0);
    zombiTest.set_direction(dire2);
    tabEnnemi.push_back(zombiTest);
    
     Vect2 posZombi2(11,19);
    zombiTest.set_pos(posZombi2);
    tabEnnemi.push_back(zombiTest);
    placerEnnemis(pillard,3);

    Vect2 pos_1(14,6);
    Ferme ferme1(stockage);
    ferme1.creation(pos_1);
    TabFerme.push_back(ferme1);

    Vect2 pos_2(45,6);
    Ferme ferme2(stockage);
    ferme2.creation(pos_2);
    TabFerme.push_back(ferme2);

    Vect2 pos_3(14,23);
    Ferme ferme3(stockage);
    ferme3.creation(pos_3);
    TabFerme.push_back(ferme3);

    Vect2 pos_4(45,23);
    Ferme ferme4(stockage);
    ferme4.creation(pos_4);
    TabFerme.push_back(ferme4);

}

Jeu::~Jeu(){

}



void Jeu::placerEnnemis(Type_ennemi type_en,int effectif){
    int Largeur=40, Hauteur=20;
    Vect2 posZCentre(Largeur/2,Hauteur-5);
	Vect2 posZDroite(Largeur-2,Hauteur/2);
	Vect2 posZGauche(5,Hauteur/2);
    Vect2 posC1(5,Hauteur/5);
    Vect2 posC2(Largeur-5,Hauteur/5);
    Vect2 posC4(5,Hauteur/5*4);
    Vect2 posC3(Largeur-5,Hauteur/5*4);
	Vect2 pos;
	int r;

	switch(type_en){
		
		case zombi:{
			for(int i=0;i<effectif;i++)
			{
				r=rand()%3;
				switch(r){
				case 0: {pos=posZCentre;
						break;}
				case 1: {pos=posZDroite;
						break;}
				case 2: pos=posZGauche;
						break;}
				Ennemi enm1(type_en);
				Vect2 posi(pos.x+((float)(rand()%21-10)),pos.y+((float)(rand()%21-10)));
				enm1.set_pos(posi);
				tabEnnemi.push_back(enm1);
				
			}
			break;
		}
		case z_infectieu:{
			for(int i=0;i<effectif;i++)
			{
				r=rand()%3;
				switch(r){
				case 0: {pos=posC1;
						break;}
				case 1: {pos=posC2;
						break;}
				case 2: {pos=posC3;
						break;}
                case 3: pos=posC4;
						break;}
				Ennemi enm1(type_en);
				Vect2 posi(pos.x+((float)(rand()%21-10)),pos.y+((float)(rand()%21-10)));
				enm1.set_pos(posi);
				tabEnnemi.push_back(enm1);
				
			}
			break;
		}
		case pillard:{
			for(int i=0;i<effectif;i++)
			{
				r=rand()%4;
				switch(r){
				case 0: {pos=posC1;
						break;}
				case 1: {pos=posC2;
						break;}
				case 2: {pos=posC3;
						break;}
                case 3: pos=posC4;
						break;}
				Ennemi enm1(type_en);
				Vect2 posi(pos.x+((float)(rand()%21-10)),pos.y+((float)(rand()%21-10)));
				enm1.set_pos(posi);
				tabEnnemi.push_back(enm1);
			}
			break;
		}
		case z_berserker:{
			for(int i=0;i<effectif;i++)
			{
				r=rand()%4;
				switch(r){
				case 0: {pos=posC1;
						break;}
				case 1: {pos=posC2;
						break;}
				case 2: {pos=posC3;
						break;}
                case 3: pos=posC4;
						break;}
				Ennemi enm1(type_en);
				Vect2 posi(pos.x+((float)(rand()%21-10)),pos.y+((float)(rand()%21-10)));
				enm1.set_pos(posi);
				tabEnnemi.push_back(enm1);
				
			}
			break;
		}
	}
}


void Jeu::bat_proche_ennemi(Ennemi & enboucle, bool & initBat,float & distanceMinimale,Vect2 & cible,long unsigned int & indiceMinDistance ){
    initBat=false;
    float distanceActuelle;
    long unsigned int bat;

    if(tabBatDef.size()>0){
        BatimentDefense batiment;
        for(bat=0;bat<tabBatDef.size();bat++){ //parcours de tous les batiments
            batiment=tabBatDef.at(bat);
            if(batiment.getDetruit()==false){//est vivant
                distanceActuelle=enboucle.get_position().distance(batiment.getPosition());
                if(initBat==false){
                    initBat=true; indiceMinDistance=bat;
                    distanceMinimale=distanceActuelle;
                }else{
                    if(distanceActuelle<distanceMinimale){
                        distanceMinimale=distanceActuelle;
                        indiceMinDistance=bat;
                    }

                }
            }
        }
        if(initBat) {
            cible=tabBatDef.at(indiceMinDistance).getPosition();
        }
    }

}

void Jeu::ferme_proche_ennemi(Ennemi & enboucle, bool & initFerme,float & distanceMinimale,Vect2 & cible, long unsigned int & indiceMinDistance){
    initFerme=false;
    float distanceActuelle;
    long unsigned int ferme;

    StockageRessources stockage;
    Ferme fermeActuelle(stockage);
    Vect2 pos(0,0);
    fermeActuelle.creation(pos);

    if(TabFerme.size()>0){
        for(ferme=0;ferme<TabFerme.size();ferme++){ //parcours de tous les batiments
            fermeActuelle=TabFerme.at(ferme);
            if(fermeActuelle.est_vivant()==true){//est vivante
                Vect2 pos=enboucle.get_position();
                distanceActuelle=pos.distance(fermeActuelle.get_position());
                if(initFerme==false){
                    initFerme=true; indiceMinDistance=ferme;
                    distanceMinimale=distanceActuelle;
                }else{
                    if(distanceActuelle<distanceMinimale){
                        distanceMinimale=distanceActuelle;
                        indiceMinDistance=initFerme;
                    }

                }
            }
        }
        if(initFerme){
            cible=TabFerme.at(indiceMinDistance).get_position();
        }
    }

}

void Jeu::baseCentrale_proche_ennemi(Ennemi & enboucle, float & distance,Vect2 & cible ){
    //Vect2 baseCentre(jeu_largeur/2, jeu_hauteur/2);
    cible=BCpos;
    distance=enboucle.get_position().distance(cible);
}

void Jeu::deplacerEnnemis(){ 
    long unsigned int e,indiceMinDistBatDef,indiceMinDistFerme;
    bool initBat=false,initFerme=false,deplacerEnnemiBool;
    Vect2 cibleBatDef,cibleFerme,cibleBaseCentrale;
    Vect2 nouveauDepl,cibleGenerale;
    float distMinBatDef,distMinFerme,distBaseCentrale;
    float distMinGenerale;
    Ennemi enboucle;
    int aiguillageAttaque=0;  // 0 vers baseCentrale 1 vers Batiment at intBat 2 vers Ferme at indFerme
    Type_ennemi typeEnnemi;

    for(e=0;e<tabEnnemi.size();e++){
        aiguillageAttaque=0;

        if(tabEnnemi.at(e).get_statut()==true){ //si ennemi est vivant

            
            initBat=false;initFerme=false;
            deplacerEnnemiBool=true;

            enboucle=tabEnnemi.at(e);

            /////if enboucle de type zombi alors deplacement vers la base centrale

            typeEnnemi=enboucle.getType();

            if(typeEnnemi==zombi){
                baseCentrale_proche_ennemi(enboucle,distBaseCentrale,cibleBaseCentrale);
                if(distBaseCentrale<2.f){ //6.f
                     BCdegat(enboucle.get_degat());
                }else{
                    nouveauDepl=cibleBaseCentrale-enboucle.get_position();
                    nouveauDepl.normailiser();
                    tabEnnemi.at(e).set_direction(nouveauDepl);
                    tabEnnemi.at(e).deplacer();

                }

            }else{
                bat_proche_ennemi(enboucle,initBat,distMinBatDef,cibleBatDef,indiceMinDistBatDef);
                ferme_proche_ennemi(enboucle,initFerme,distMinFerme,cibleFerme,indiceMinDistFerme);
                baseCentrale_proche_ennemi(enboucle,distBaseCentrale,cibleBaseCentrale);

                distMinGenerale=distBaseCentrale;
                if(initBat==true){
                    if(distMinBatDef<distMinGenerale){
                    aiguillageAttaque=1;
                    distMinGenerale=distMinBatDef;
                }
                }
                if(initFerme==true){
                    if(distMinFerme<distMinGenerale){
                    aiguillageAttaque=2;
                    distMinGenerale=distMinFerme;
                }
                }
                

                if(distMinGenerale<2.f){
                    deplacerEnnemiBool=false;
                    switch(aiguillageAttaque)
                    {
                        case 0:
                            BCdegat(enboucle.get_degat());
                            //BaseCentrale.degat(enboucle.get_degat());
                            break;
                        case 1:
                            tabBatDef.at(indiceMinDistBatDef).enleverPointsVie(enboucle.get_degat());
                            break;
                        case 2:
                            TabFerme.at(indiceMinDistFerme).degat(enboucle.get_degat());
                            break;

                    }
                }

                if(deplacerEnnemiBool==true){

                    switch(aiguillageAttaque)
                    {
                        case 0:
                            cibleGenerale=cibleBaseCentrale;
                            break;
                        case 1:
                            cibleGenerale=cibleBatDef;
                            break;
                        case 2:
                            cibleGenerale=cibleFerme;
                            break;

                    }
                    
                    //Pour normaliser le vecteur de deplacemetdistance_pour_normaliser;
                    nouveauDepl=cibleGenerale-enboucle.get_position();
                    nouveauDepl.normailiser();
                    tabEnnemi.at(e).set_direction(nouveauDepl);
                    tabEnnemi.at(e).deplacer();
                }

            }

        }   
            
    }

}



void Jeu::ennemi_vivant_proche_bat(BatimentDefense batiment, bool & initEnne,long unsigned int & indiceMinDistance ){
    initEnne=false;
    float distanceActuelle,distanceMinimale;
    long unsigned int e;

    if(tabEnnemi.size()>0){
        Ennemi enne;
        for(e=0;e<tabEnnemi.size();e++){ //parcours de tous ennemis
            
            if(tabEnnemi.at(e).get_statut()==true){
                enne=tabEnnemi.at(e);
                distanceActuelle=enne.get_position().distance(batiment.getPosition());
                if(initEnne==false){
                    initEnne=true; indiceMinDistance=e;
                    distanceMinimale=distanceActuelle;
                }else{
                    if(distanceActuelle<distanceMinimale){
                        distanceMinimale=distanceActuelle;
                        indiceMinDistance=e;
                    }
                }
            }
        }

        if(initEnne==true){
            if(distanceMinimale>batiment.getRayonAttaque()){
            initEnne=false;}
        }

    }

}


void Jeu::faireDegatBat(){

    long unsigned int bat;
    bool initEnne;
    long unsigned int indiceMinDistance;

    if(tabBatDef.size()>0){
        BatimentDefense batiment;
        for(bat=0;bat<tabBatDef.size();bat++){ //parcours de tous les batiments
            batiment=tabBatDef.at(bat);
            if(batiment.getDetruit()==false){
                //trouve lennemi vivant le plus proche
                initEnne=false;
                ennemi_vivant_proche_bat(batiment,initEnne,indiceMinDistance );
                if(initEnne==true){
                    tabEnnemi.at(indiceMinDistance).enleverSante(batiment.getDegats()*batiment.getVitesseAttaque());
                    //cout<<"degat by bat "<<batiment.getDegats()*batiment.getVitesseAttaque();
                    //cout<<"ennemi santes"<<tabEnnemi.at(indiceMinDistance).get_sante();
                }
            }

        }
    }
}

void Jeu::enleveEntDetruites(){
    //long unsigned int bat,ferme;  //,e
    int ferme,eint,bat;
    bat=tabBatDef.size();
    if(tabBatDef.size()>0){
        //cout<<" size "<<tabBatDef.size()<<"  taille tab  ";
        for(bat=tabBatDef.size()-1;bat>=0;bat--)
            { 
                   // cout<<"Batiment indice"<< bat-1 <<" "; 
                    if (tabBatDef.at((unsigned long int)bat).getDetruit()==true ||  tabBatDef.at((unsigned long int)bat).getPointsDeVie()<=0 )
                    {
                    tabBatDef.erase( tabBatDef.begin() + (unsigned long int)bat);
                        cout<<"BATIMENT "<<bat-1<< " EFFACEE"<<endl; 
                        //usleep(1000000);          
                    }
            }
    }
   
   if(TabFerme.size()>0)
    {
        for(ferme=TabFerme.size()-1;ferme>=0;ferme--)
        {
            if (TabFerme.at((unsigned long int)ferme).est_vivant()==false)  //si la ferme n'est plus vivante
            {
                TabFerme.erase(TabFerme.begin() + (unsigned long int)ferme);
            }
        }
    }

    if(tabEnnemi.size()>0)
    {
       
        for(eint=tabEnnemi.size()-1;eint>=0;eint--)
        {
            if (tabEnnemi.at((unsigned long int)eint).get_statut()==false && tabEnnemi.at((unsigned long int)eint).get_temps_mort()>100 ) //&& tabEnnemi.at((unsigned long int)eint).get_temps_mort()>20 )  //si l'ennemi est eliminé
            {
                tabEnnemi.erase(tabEnnemi.begin()+(unsigned long int)eint);
                //cout<<(unsigned long int)eint <<"ennemi indice eliminé";
                //sleep(2);
            }
        }
    
    }
    
    
}

void Jeu::ajouteTempsMortEnnemis(float tempsMort){
     int e;

    if(tabEnnemi.size()>0)
    {

        for(e=tabEnnemi.size()-1;e>=0;e--)
        {
            if (tabEnnemi.at((unsigned long int)e).get_statut()==false )  //si l'ennemi est eliminé
            {
                tabEnnemi.at((unsigned long int)e).add_temps_mort(tempsMort);
            }
        }
        cout<<endl;
    
    }
}

void Jeu::declancherVague(int num_vague){

    switch(num_vague) {
        case 0:
            placerEnnemis( zombi,3);
            break;
        case 1:
            placerEnnemis( zombi,2);
            placerEnnemis(pillard,2);
            break;
        case 2:
            placerEnnemis(pillard,7);
            break;
        case 3:
            placerEnnemis(pillard,5);
            placerEnnemis( zombi,6);
            break;
        case 4:
            placerEnnemis(z_infectieu,5);
            placerEnnemis( zombi,8);
            break;
        case 5:
            placerEnnemis(z_berserker ,6);
            placerEnnemis( zombi,4);
            break;
        case 6:
            placerEnnemis(z_infectieu ,3);
            placerEnnemis( zombi,4);
            placerEnnemis(pillard,1);
            break;
        default:
            placerEnnemis( zombi,rand()%6+6);
            placerEnnemis(pillard,rand()%3+4);
            break;
        placerEnnemis( zombi,num_vague);
    }
    

}

void Jeu::BCAttaque(){
    float distance,distanceMinimale;
    unsigned long int indMin;
    unsigned long int e;
    bool init=false;
    Ennemi enboucle;
    Vect2 cible=BCgetPos();
    for(e=0;e<tabEnnemi.size();e++){ //parcours des ennemis
        enboucle=tabEnnemi.at(e);
        
        if(tabEnnemi.at(e).get_statut()==true){ //si ennemi est vivant
            distance=enboucle.get_position().distance(cible);
            if(init==false){
                init=true;
                distanceMinimale=distance;
                indMin=e;
            }else{
                if(distance<distanceMinimale){
                    indMin=e;
                    distanceMinimale=distance;
                }
            }

        }
    }
    if(init==true){
        if(distanceMinimale<5){
            tabEnnemi.at(indMin).enleverSante(BCfloatdeg);
        }
    }


}