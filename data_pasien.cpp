#include "data_pasien.h"

void createPasien(list_P &P){
    first(P) = nil;
}
adr_pasien createElementPasien(infotype_P x){
    adr_pasien z = new elmPasien;
    infoPasien(z) = (x);
    nextPasien(z) = nil;
    return z;
}
void insertLastPasien(list_P &P, adr_pasien y){
    if(first(P) == nil){
        first(P) = y;
    }else{
        adr_pasien p = first(P);
        while(nextPasien(p) != nil){
            p = nextPasien(p);
        }
        nextPasien(p) = y;
    }
}
void showPasien(list_P &P){

}
void deleteLastPasien(list_P &P, adr_pasien y){
    adr_pasien p;
    if(first(P) == nil){
        y = nil;
        cout<<"Tidak ada Pasien"<<endl;
    }else if(nextPasien(first(P)) == nil){
        y = first(P);
        first(P) = nil;
    }else{
        p = first(P);
        y = first(P);
        while(nextPasien(y) != nil){
            p = y;
            y = nextPasien(p);
        }
        nextPasien(p) = nil;
    }
}
adr_pasien searchPasien(list_P &P, string namaPasien){
    if(first(P) == nil){
        return nil;
    }else{
        adr_pasien p;
        while(p != nil && infoPasien(p).namaPasien != namaPasien){
            p = nextPasien(p);
        }
        return p;
    }
}


void createRuangan(list_R &R);
adrRuangan createElementRuangan(infotype_R a);
void insertRuangan(list_R &R, string namaPasien, adrRuangan b);
void showAll(list_P P, list_R R);
void deleteRuangan(list_R &R, adrRuangan &c);
bool findRuangan(list_R R, int id);
