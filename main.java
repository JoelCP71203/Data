
class Main{

    public static void main(String[] args){
        System.out.println("Program sukses dijalankan");
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
  }
  public void stop{
    mesin.off();
  }
}

class Mesin{
    int cc;
    String no;

    public void on{}
    public void off{}
}

class Spion{
    String warna;
}

class Bensin{}

class Stnk{
  Mobil mobil;
}

class Truk extends Mobil{
    int box;
}
