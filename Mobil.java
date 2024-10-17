class Main{

    public static void main(String[] args){
    }
}

class Mobil{
  int ban;
  String warna;

  Mesin mesin = new Mesin();
  Spion spion = new Spion();
  Stnk stnk = new Stnk();

  public void drive{
      Bensin bensin = new Bensin();
      if (bensin.oktan >= 95) {
             System.out.println("Mobil sedang berjalan dengan bensin berkualitas tinggi.");
         } else {
             System.out.println("Mobil sedang berjalan dengan bensin standar.");
         }
        bensin.jenisBensin();
  }
  public void stop{
    mesin.off();
    system.out.println("Mobil telah berhenti berjalan")
}

class Spion{
    String warna;
}

class Mesin{
    int cc;
    String no;

    public void on{
        System.out.println("Mesin No. "+ no +" yang memiliki cc: "+ cc +"cc dinyalakan.");
    }
    public void off{
        System.out.println("Mesin No. "+ no +" yang memiliki cc:  "+ cc +"cc dimatikan.");
    }
}

class Bensin{
    int oktan;
    
    public void jenisBensin() {
        if (oktan >= 98) {
            System.out.println("Jenis bensinnya Pertamax Turbo.");
        } else if (oktan >= 95) {
            System.out.println("Jenis bensinnya Pertamax.");
        } else if (oktan >= 92) {
            System.out.println("Jenis bensinnya Premium.");
        } else {
            System.out.println("Jenis bensinnya tidak ketahui.");
        }
    }
}

class Stnk{
  Mobil mobil;
  int nomor;
  int tahun;
  
  public void tampilkanSTNK() {
        System.out.println("Nomor STNK: " + nomor);
        System.out.println("Tahun: " + tahun);
    }
}

class Truk extends Mobil{
    int box;
}
