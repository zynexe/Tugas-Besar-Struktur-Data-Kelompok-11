#include "pasien.h"
#include <iostream>

using namespace std;


int main() {

    listPasien PS;
    listRuang RG;
    infotypePasien infoPasien;
    infotypeRuang infoRuangan;
    adrRuang R;
    adrPasien P;
    int pilihan, t, total;
    string namaRuangan, namaPasien, keluhanPasien;
    int idPasien, noRuang;
    char subMenu;

    createlistPasien(PS);
    createlistRuang(RG);

    pilihan = Select_Menu();
    while (pilihan!=0){
        switch(pilihan){
        case 1:
            cout<<" Banyaknya Ruangan yang ditambahkan : ";
            cin>>total;
            for(t=1 ; t <= total ; t++){
                cout<<"Masukkan Nama Ruangan : ";
                cin>>infoRuangan.namaRuangan;
                cout<<"Masukkan noRuang : ";
                cin>>infoRuangan.noRuang;

                R = createRuang(infoRuangan);
                addRuang(RG, R);
            }
            break;
        case 2:
            cout<<"Berapa Pasien yang akan Ditambahkan : ";
            cin>> total;
            for(t=1;t <= total ; t++){
                cout<<"Masukkan Nama Pasien : ";
                cin>>infoPasien.namaPasien;
                cout<<"Masukkan Ruangan Pasien : ";
                cin>>infoPasien.namaPasien;
                cout<<"Masukkan id Pasien : ";
                cin>>infoPasien.idPasien;

                P = createPasien(infoPasien);
                cout<<" Ruangan yang tersedia : ";
                cin>>namaRuangan;
                addPasien(RG, PS, P, namaRuangan);
            }
            break;
        case 3:
            cout<<"Masukkan Ruangan yang ingin dihapus : ";
            cin>>namaRuangan;
            //DeleteParentsAndChild(LJ, Jurusan, namaJur, kelas);
            break;
        case 4:
            showAllDataRuang(RG);
            break;
        case 5:
            showAllData(RG);
            break;
        case 6:
            cout<<"Masukkan Nama Ruangan : ";
            cin>>namaRuangan;
            R = findRuang(RG, namaRuangan);
            cout<<infoRuangan(R).namaRuangan<< " " <<infoRuangan(R).noRuang<<endl;
            break;
        case 7:
            cout<<"Masukkan Nama Pasien : ";
            cin>> namaPasien;
//            cout<<"Masukkan Ruangan Pasien : ";
//            cin>>namaRuangan;
            P = findPasien(PS, namaRuangan, namaPasien, RG);
            cout<<infoPasien(P).namaPasien<<" "<<infoPasien(P).namaPasien<<" "<<infoPasien(P).idPasien<< endl;
            break;
        case 8:
            cout<<"Masukkan Ruangan : ";
            cin>>namaRuangan;
            cout<<"Jumlah Pasien : "<<countPasien(RG, namaRuangan)<<endl;
            break;
        case 9:
            cout<<"Masukkan id Pasien : ";
            cin>>idPasien;
            cout<<"Masukkan Nama Ruangan : ";
            cin>>namaRuangan;
            //deleteChild(LM,namaJur, kelas, LJ, Murid);
            break;
        }
        cout<<"Kembali ke menu utama?(Y/N)";
        cin>>subMenu;
        if(subMenu=='Y'){
            pilihan = Select_Menu();
        }else{
            pilihan = 0;
        }
    }
    cout<<"ANDA TELAH KELUAR DARI PROGRAM"<<endl;
    cout << endl;
}
//int main() {

//    listP PS;
//    listR RS;
//    infotypeP infoPasien;
//    infotypeR infoRuangan;
//    adrPasien Pasien;
//    adrRuangan Ruang;
//    int pilihan, t, total;
//    string kasurTersedia, namaPasien;
//    int idPasien, noRuang;
//    char subMenu;
//
//    createPasien(infoPasien);
//    createRuangan(infoRuangan);
//
//    pilihan = Select_Menu();
//    while (pilihan != 0){
//        switch(pilihan){
//        case 1:
//            cout<<" Banyaknya Ruangan yang ditambahkan : ";
//            cin>>total;
//            for(t=1 ; t <= total ; t++){
//                cout<<"Masukkan Nama Ruangan : ";
//                cin>>infoRuangan.kasurTersedia;
//                cout<<"Masukkan idPasien : ";
//                cin>>infoPasien.idPasien;
//
//                Ruang = createRuangan(infoRuangan);
//                //adrRuangan(Ruang, RS);
//            }
//            break;
//        }
//    }
//}
//        case 2:
//            cout<<"Pasien yang akan Ditambahkan : ";
//            cin>> total;
//            for(t=1;t <= total ; t++){
//                cout<<"Masukkan Nama Pasien : ";
//                cin>>infoPasien.namaPasien;
//                cout<<"Masukkan Ruangan Pasien : ";
//                cin>>infoPasien.keluhanPasien;
//                cout<<"Masukkan NISN Murid : ";
//                cin>>infoM.NISN;
//
//                M = createPasien(infoPasien);
//                cout<<" Ruangan yang diambil : ";
//                cin>>kasurTersedia;
//                addPasien(R, P, M, kasurTersedia);
//            }
//            break;
//        case 3:
//            cout<<"Masukkan Jurusan yang ingin dihapus : ";
//            cin>>namaJur;
//            //DeleteParentsAndChild(LJ, Jurusan, namaJur, kelas);
//            break;
//        case 4:
//            showAllDataParent(LJ);
//            break;
//        case 5:
//            showAllData(LJ);
//            break;
//        case 6:
//            cout<<"Masukkan Nama Jurusan : ";
//            cin>>namaJur;
//            J = findParent(LJ, namaJur);
//            cout<<infoJur(J).namaJur<< " " <<infoJur(J).kelas<<endl;
//            break;
//        case 7:
//            cout<<"Masukkan Nama Murid : ";
//            cin>> nama;
//            cout<<"Masukkan Jurusan Murid : ";
//            cin>>namaJur;
//            M = findChild(LM, namaJur, nama, LJ);
//            cout<<infoM(M).nama<<" "<<infoM(M).namaJurusan<<" "<<infoM(M).NISN<< endl;
//            break;
//        case 8:
//            cout<<"Masukkan Jurusan : ";
//            cin>>namaJur;
//            cout<<"Jumlah Murid : "<<countchild(LJ, namaJur)<<endl;
//            break;
//        case 9:
//            cout<<"Masukkan NISN Murid : ";
//            cin>>NISN;
//            cout<<"Masukkan Nama Jurusan : ";
//            cin>>namaJur;
//            //deleteChild(LM,namaJur, kelas, LJ, Murid);
//            break;
//        }
//        cout<<"Kembali ke menu utama?(Y/N)";
//        cin>>subMenu;
//        if(subMenu=='Y'){
//            pilihan = Select_Menu();
//        }else{
//            pilihan = 0;
//        }
//    }
//    cout<<"ANDA TELAH KELUAR DARI PROGRAM"<<endl;
//return 0;
//   }
//}
