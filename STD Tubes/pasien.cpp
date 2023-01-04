#include "pasien.h"

void createlistPasien(listPasien &PS){
    firstPasien(PS) = nil;
}

adrPasien createPasien(infotypePasien infoPasien){
    adrPasien P = new elmPasien;
    infoPasien(P) = infoPasien;
    nextPasien(P) = nil;
    return P;
}

void createlistRuang(listRuang &RG){
    firstRuangan(RG) = nil;
}

adrRuang createRuang(infotypeRuang infoRuangan){
    adrRuang R = new elmRuang;
    infoRuangan(R) = infoRuangan;
    nextRuangan(R) = nil;
    Pas(R) = nil;

    return R;
}

void addPasien(listRuang &RG, listPasien &PS, adrPasien P, string namaRuangan){
    adrRuang R;
    adrPasien P1, P2;

    R = findRuang(RG, namaRuangan);
    if(Pas(R) == nil){
         Pas(R) = P;
        if(firstPasien(PS) == nil){
            firstPasien(PS) = P;
        }else{
            P1 = firstPasien(PS);
            while(nextPasien(P1) != nil){
                P1 = nextPasien(P1);
            }
            nextPasien(P1) = P;
        }
    } else {
        P2 = Pas(R);
        while(nextPasien(P2) != nil){
            P2 = nextPasien(P2);
        }
        nextPasien(P) = nextPasien(P2);
        nextPasien(P2) = P;
    }
}

void addRuang(listRuang &RG, adrRuang Ruang){
    if(firstRuangan(RG) == nil){
        firstRuangan(RG) = Ruang;
        nextRuangan(Ruang) = firstRuangan(RG);
    } else {
        adrRuang R = firstRuangan(RG);
        while(nextRuangan(R) != firstRuangan(RG)){
            R = nextRuangan(R);
        }
        nextRuangan(R) = Ruang;
        nextRuangan(Ruang) = firstRuangan(RG);
    }
}

void showAllDataRuang(listRuang RG){
    adrRuang R;
    if(firstRuangan(RG) == nil){
        cout << "Tidak ada Ruangan" << endl;
    } else {
        R = firstRuangan(RG);
        cout << infoRuangan(R).namaRuangan << " " << infoRuangan(R).noRuang << endl;
        R = nextRuangan(R);
        while(R != firstRuangan(RG)){
            cout << infoRuangan(R).namaRuangan << " " << infoRuangan(R).noRuang << endl;
            R = nextRuangan(R);
        }
    }
}

adrRuang findRuang(listRuang RG, string namaRuangan){
    adrRuang R;
    R = firstRuangan(RG);
    if(infoRuangan(R).namaRuangan == namaRuangan){
            return R;
        }
        R = nextRuangan(R);
    while(R != firstRuangan(RG)){
        if(infoRuangan(R).namaRuangan == namaRuangan){
            return R;
            break;
        }
        R = nextRuangan(R);
    }if(R == nil){
        return R;
        cout << "Ruangan tersebut tidak ada" << endl;
    }
}

void DeleteRuangAndPasien(listRuang &RG, adrRuang &Ruang, string namaRuangan, int noRuang){
    adrRuang R;
    R = findRuang(RG, namaRuangan);

    if(firstRuangan(RG) == nil){
        cout << "Ruangan sudah kosong" << endl;
    } else if ( R == firstRuangan(RG)) {
        firstRuangan(RG) = nextRuangan(R);
        nextRuangan(R) = nil;
    } else {
        //R = findParent(LJ, namaJur);
        Ruang = firstRuangan(RG);
        while(nextRuangan(Ruang) != R) {
            Ruang = nextRuangan(Ruang);
        }
        if(nextRuangan(R) == firstRuangan(RG)) {
            nextRuangan(Ruang) = firstRuangan(RG);
            R = nil;
        }else{
            nextRuangan(Ruang) = nextRuangan(R);
            nextRuangan(R) = nil;
            R = nil;
        }
    }
}

void showAllData(listRuang RG){
    adrRuang R;
    adrPasien P;

    cout << "========== Data Ruangan dan Pasien ===========" << endl;
    R = firstRuangan(RG);
    cout << "Ruangan :" << endl;
    cout << infoRuangan(R).namaRuangan << " " << infoRuangan(R).noRuang << endl;
    if(Pas(R) != nil){
        P = Pas(R);
        cout << "Daftar Pasien :" << endl;
        while(P != nil){
            if(infoPasien(P).namaPasien == infoRuangan(R).namaRuangan){
                cout << infoPasien(P).namaPasien << " " << infoPasien(P).idPasien << endl;
            }

            P = nextPasien(P);
        }
        cout << endl;
    }
    R = nextRuangan(R);
    while(R != firstRuangan(RG)){
        cout << "Ruangan :" << endl;
        cout << infoRuangan(R).namaRuangan << " " << infoRuangan(R).noRuang << endl;
        if(Pas(R) != nil){
            P = Pas(R);
            cout << "Daftar Pasien :" << endl;
            while(P != nil){
                if(infoPasien(P).namaPasien == infoRuangan(R).namaRuangan){
                    cout << infoPasien(P).namaPasien << " " << infoPasien(P).idPasien << endl;
                }
                cout << endl;
                P = nextPasien(P);
            }
        }
        R = nextRuangan(R);
    }
}

adrPasien findPasien(listPasien PS, string namaRuangan, string namaPasien, listRuang RG)
{
    adrPasien P;
    adrRuang R;

    R = findRuang(RG, namaRuangan);
    P = Pas(R);
    while(P != nil){
        if(infoPasien(P).namaPasien == namaPasien && infoRuangan(R).namaRuangan == infoPasien(P).namaPasien){
            return P;
            break;
        }
        P = nextPasien(P);
    }
    if( P == nil){
        return P;
    }
}

void deletePasien(listPasien &PS, string namaRuangan, string namaPasien, int noRuang, listRuang &RG, adrPasien &P){
    adrRuang R;
    adrPasien Pasien;

    R = findRuang(RG, namaRuangan);
    P = findPasien(PS, namaRuangan, namaPasien, RG);

    Pasien = Pas(R);
    if(Pasien == P){
        if(nextPasien(P) == nil){
            Pas(R) = nil;
        }else{
            Pas(R) = nextPasien(Pas(R));
        }
    } else {
        while(Pasien != nil) {
            if(infoPasien(nextPasien(Pasien)).namaPasien == infoPasien(P).namaPasien){
                if(nextPasien(P) == nil){
                    nextPasien(Pasien) = nil;
                    break;
                }else{
                    Pas(R) == Pasien;
                    break;
                }
            }
            Pasien = nextPasien(Pasien);
        }
    }
}

int countPasien(listRuang RG, string namaRuangan){
    adrRuang R;
    adrPasien P;
    int i = 0;

    R = findRuang(RG, namaRuangan);
    if(Pas(R) != nil){
        P = Pas(R);
        while(P != nil){
            if(infoPasien(P).namaPasien == infoRuangan(R).namaRuangan){
                i++;
            }
            P = nextPasien(P);
        }
    }
    return i;
}

int Select_Menu(){

    int pilihan;

    cout<<"==========MENU=========="<<endl;
    cout<<"1. Menambah Ruangan "<<endl;
    cout<<"2. Menambah Pasien dan Menghubungkan ke Ruangan"<<endl;
    cout<<"3. Menghapus Ruangan dan Pasien"<<endl;
    cout<<"4. Menampilkan Semua Ruangan"<<endl;
    cout<<"5. Menampilkan Semua Ruangan dan Pasien"<<endl;
    cout<<"6. Mencari Ruangan "<<endl;
    cout<<"7. Mencari Pasien "<<endl;
    cout<<"8. Menghitung Jumlah Pasien yang berada di Ruangan "<<endl;
    cout<<"9. Hapus Pasien pada Ruangan "<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Pilih Menu : ";
    cin>>pilihan;
    return pilihan;
}
