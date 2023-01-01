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
void insertPasien(list_P &P, adr_pasien y){
    if(first(P) == nil){
        first(P) = y;
        nextPasien(y) = first(P);
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
void deletePasien(list_P &P, adr_pasien y){
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


void createRuangan(list_R &R){
    first(R) = nil;
}
adrRuangan createElementRuangan(infotype_R a){
    adrRuangan p;
    p = new elmRuangan;
    infoRuangan(p) = a;
    nextRuangan(p) = nil;
    return p;
}
void insertRuangan(list_R &R, string namaPasien, adrRuangan b){
    if(first(R) == nil){
        first(R) = b;
    } else {
        adrRuangan Q;
        Q = first(R);
        while(Q != nil){
            Q = nextRuangan(Q);
        }
        nextRuangan(Q) = b;
    }
}
void showAll(list_R R){
    adrRuangan x;
    if(first(R) != nil){
        x = first(R);
        while(x != nil){
            cout << "Kasur Tersedia : " << infoRuangan(x).kasurTersedia << endl;
            cout << "No Ruang : " << infoRuangan(x).noRuang << endl;

            x = nextRuangan(x);
        }
        cout << endl;
    } else {
        cout << "Kasur tidak tersedia" << endl;
    }
}
void deleteRuangan(list_R &R, adrRuangan &c){
    adrRuangan Q;
    if(first(R) == nil){
        cout << "Ruangan Kosong" << endl;
    } else if (nextRuangan(first(R)) == nil){
        c = first(R);
        first(R) = nil;
    } else {
        Q = first(R);
        while(nextRuangan(Q) != nil){
            Q = nextRuangan(Q);
        }
        first(R) = nextRuangan(c);
        nextRuangan(Q) = nextRuangan(c);
        nextRuangan(c) = nil;

    }
}
bool findRuangan(list_R R, int id){
    adrRuangan P;
    if(first(R) != nil){
        P = first(R);
        while(P != nil & infoRuangan(P).kasurTersedia != kasur){
            P = nextRuangan(P);
        }
    } else {
        return nil;
    }

    if(infoRuangan(P).noRuang == id){
        return P;
    } else {
        return nil;
    }
}
