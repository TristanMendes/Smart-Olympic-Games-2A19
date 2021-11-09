#include "moyensdetransport.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>
#include <QMessageBox>


MoyensDeTransport::MoyensDeTransport()
{
id=0;nom=""; type="";nbr_voyages=0;destination_depart="";destination_arrivee="";capacite=0;nbr_billet=0;
}
MoyensDeTransport::MoyensDeTransport (int id,QString nom,QString type,int nbr_voyages,QString destination_depart,QString destination_arrivee,int capacite,int nbr_billet)
{ this->id=id;this->nom=nom; this->type=type; this->nbr_voyages=nbr_voyages; this->destination_depart=destination_depart; this->destination_arrivee=destination_arrivee; this->capacite=capacite; this->nbr_billet=nbr_billet;}


int MoyensDeTransport::getid()  {return id;}
QString MoyensDeTransport::getnom() {return nom;}
QString MoyensDeTransport::gettype()  {return type;}
int MoyensDeTransport::getnbr_voyages() {return nbr_voyages;}
QString MoyensDeTransport::getdestination_depart() {return destination_depart;}
QString MoyensDeTransport::getdestination_arrivee() {return destination_arrivee;}
int MoyensDeTransport::getcapacite() {return capacite;}
int MoyensDeTransport::getnbr_billet() {return nbr_billet;}


void MoyensDeTransport::setid (int id)  {this->id=id;}
void MoyensDeTransport::setnom (QString nom) {this->nom=nom;}
void MoyensDeTransport::settype (QString type) {this->type=type;}
void MoyensDeTransport::setnbr_voyages (int nbr_voyages)  {this->nbr_voyages=nbr_voyages;}
void MoyensDeTransport::setdestination_depart (QString destination_depart)  {this->destination_depart=destination_depart;}
void MoyensDeTransport::setdestination_arrivee (QString destination_arrivee)  {this->destination_arrivee=destination_arrivee;}
void MoyensDeTransport::setcapacite (int capacite) {this->capacite=capacite;}
void MoyensDeTransport::setnbr_billet(int nbr_billet) {this->nbr_billet=nbr_billet;}


bool MoyensDeTransport::ajouter()
{



    QString id_string=QString::number(id);
    QString nbr_voyages_string=QString::number(nbr_voyages);
    QString capacite_string=QString::number(capacite);
    QString nbr_billet_string=QString::number(nbr_billet);

    QSqlQuery query;
    query.prepare("INSERT INTO Moyens_De_Transport (id_moyen, nom_moyen,type_moyen,nbr_voyages,destination_depart,destination_arrivee,capacite,nbr_billet)"
                       "VALUES (:id, :nom, :type,:nbr_voyages,:destination_depart,:destination_arrivee,:capacite,:nbr_billet)");
         query.bindValue(0, id_string);
         query.bindValue(1, nom);
         query.bindValue(2, type);
         query.bindValue(3,nbr_voyages_string);
         query.bindValue(4,destination_depart);
         query.bindValue(5, destination_arrivee);
         query.bindValue(6, capacite_string);
         query.bindValue(7, nbr_billet_string);

         return query.exec();




}
bool MoyensDeTransport::supprimer(int ide)
{   QMessageBox msgbox;
    QSqlQuery query;
    QString res=QString::number(ide);


    query.prepare("Delete FROM Moyens_De_Transport where id_moyen= :id");
         query.bindValue(":id", res);




return query.exec();}





QSqlQueryModel* MoyensDeTransport::afficher()
{
QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM Moyens_De_Transport");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("nbr_voyages"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("destination_depart"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("destination_arrivee"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("capacite"));








return model;


}


bool MoyensDeTransport::modifier(int idd)
{
QSqlQuery query;
QString res=QString::number(idd);
query.prepare("Update Moyens_De_Transport set id_moyen = :id , nom_moyen= :nom, type_moyen= :type , nbr_voyages= :nbr_voyages , destination_depart= :destination_depart , destination_arrivee= :destination_arrivee,capacite=:capacite where id_moyen = :id ");
query.bindValue(":id", res);
query.bindValue(":nom",nom);
query.bindValue(":type",type);
query.bindValue(":nbr_voyages", nbr_voyages);
query.bindValue(":destination_depart", destination_depart);
query.bindValue(":destination_arrivee", destination_arrivee);
query.bindValue(":capacite", capacite);
return    query.exec();
}

