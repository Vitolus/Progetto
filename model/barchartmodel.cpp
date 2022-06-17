#include "barchartmodel.h"

BarChartModel::BarChartModel(AdminModel *m){
    for(const QString& classe : *m->getClassiList()){
        unsigned int occ= 0, tot= 0;
        for(Record* r : m->getRecordList()){
            if(r->getClasse() == classe){
                occ++;
                tot+= r->getLivello();
            }
        }
        if(occ>0) livelliMedi.insert(classe, tot/occ);
        else livelliMedi.insert(classe, 0);
    }
}

QMap<QString,unsigned int> BarChartModel::getLivelliMedi() const{return livelliMedi;}
