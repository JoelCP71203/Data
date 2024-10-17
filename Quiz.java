package QuizTerakhir; 

import java.util.Scanner;
import java.util.*;

abstract class Bidang {
    private String warna;

    public void setWarna(String warna) {
        this.warna = warna;
    }

    public String getWarna() {
        return warna;
    }

    public abstract double getKeliling();

    public abstract double getLuas();
}

class SegiEmpat extends Bidang {
    private int panjang;
    private int lebar;

    public void setPanjang(int panjang) {
        this.panjang = panjang;
    }

    public int getPanjang() {
        return panjang;
    }

    public void setLebar(int lebar) {
        this.lebar = lebar;
    }

    public int getLebar() {
        return lebar;
    }

    public double getDiagonal() {
        return Math.sqrt(panjang * panjang + lebar * lebar);
    }

    @Override
    public double getKeliling() {
        return 2 * (panjang + lebar);
    }

    @Override
    public double getLuas() {
        return panjang * lebar;
    }
}

class Lingkaran extends Bidang {
    private double radius;

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public double getDiameter() {
        return 2 * radius;
    }

    @Override
    public double getKeliling() {
        return 2 * Math.PI * radius;
    }

    @Override
    public double getLuas() {
        return Math.PI * radius * radius;
    }
}

public class Quiz {
	public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Bidang bidang = null;

        while (true) {
            System.out.println("Menu:");
            System.out.println("1. Segi Empat");
            System.out.println("2. Lingkaran");
            System.out.println("3. Keluar");

            System.out.print("Pilih: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    bidang = new SegiEmpat();
                    System.out.print("Masukkan panjang segi empat: ");
                    int panjang = scanner.nextInt();
                    ((SegiEmpat) bidang).setPanjang(panjang);
                    System.out.print("Masukkan lebar segi empat: ");
                    int lebar = scanner.nextInt();
                    ((SegiEmpat) bidang).setLebar(lebar);
                    break;
                case 2:
                    bidang = new Lingkaran();
                    System.out.print("Masukkan radius lingkaran: ");
                    double radius = scanner.nextDouble();
                    ((Lingkaran) bidang).setRadius(radius);
                    break;
                case 3:
                    System.exit(0);
                default:
                    System.out.println("Pilihan tidak valid. Silakan pilih lagi.");
                    continue;
            }

            System.out.print("Masukkan warna: ");
            String warna = scanner.next();
            bidang.setWarna(warna);

            System.out.println("Informasi Bidang:");
            System.out.println("Warna: " + bidang.getWarna());
            System.out.println("Keliling: " + bidang.getKeliling());
            System.out.println("Luas: " + bidang.getLuas());
        }
    }
}
