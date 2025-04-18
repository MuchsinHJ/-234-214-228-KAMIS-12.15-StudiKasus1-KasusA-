#include <iostream>
#include <fstream>
using namespace std;

class SPBU {
  friend istream& operator >>(istream& in, SPBU& oplos);
  friend ostream& operator <<(ostream& out, SPBU& oplos);
  public:
    SPBU();
    
    string showBensin(int jenis){
      if (jenis == 1)
      {
        return "Pertalite";
      } else if(jenis == 2){
        return "Pertamax";
      }
      else {
        return "Bensin yang anda masukkan tidak tersedia";
      }
    }

    int hitungPembelian(int jumlahLiter, int jenisBensin){
      int pertalite = 7000, pertamax = 9000;
      int harga = 0;
      if(jenisBensin == 1){
        harga = jumlahLiter * pertalite;
      } else if(jenisBensin == 2){
        harga = jumlahLiter * pertamax;
      }
      return harga;
    }

  private:
  int liter, jenisBensin, totalHarga;
  string nama;
};

SPBU::SPBU() {
  cout << "======= SELAMAT DATANG DI POM BENSIN SI MERAH OPLOS =======" << endl;
  cout << "Silahkan anda pilih jenis bensin yang ingin anda isi: " << endl << endl;
  cout << "1. Pertalite (Rp. 7000/liter)\n2. Pertamax (Rp. 9000/liter)" <<endl << endl;
  
}

istream& operator >>(istream& in, SPBU& oplos) {
  bool kondisi = true;
  cout << "Masukkan Nama Pelanggan: ";
  getline(in, oplos.nama);

  do {
    cout << "Pilih Jenis Bensin (1 = Pertalite, 2 = Pertamax): ";
    in >> oplos.jenisBensin;
    if (oplos.jenisBensin != 1 && oplos.jenisBensin != 2) {
      cout << "Jenis bensin tidak valid, silahkan pilih ulang!" << endl;
      cout << endl;
    }
  } while (oplos.jenisBensin != 1 && oplos.jenisBensin != 2);
  
    cout << "Masukkan Jumlah Liter: ";
    in >> oplos.liter;
  
    oplos.totalHarga = oplos.hitungPembelian(oplos.liter, oplos.jenisBensin);
    cout << endl;
    return in;
  
}

ostream& operator <<(ostream& out, SPBU& oplos){
  out << "======== NOTA PEMBELIAN BENSIN SI MERAH OPLOS ========" << endl;
  cout << endl;
  out << "\tNama Pelangggan\t\t: " << oplos.nama << endl;
  out << "\tJenis Bensin\t\t: " << oplos.showBensin(oplos.jenisBensin) << endl;
  out << "\tTotal liter bensin\t: " << oplos.liter << " liter" << endl;
  out << "\tTotal harga Bensin\t: Rp." << oplos.totalHarga << endl;
  cout << endl;
  out << "=================== TERIMA KASIH =====================" << endl;

}

int main (){
  SPBU pom;
  cin >> pom;
  cout << pom;
  return 0;
}