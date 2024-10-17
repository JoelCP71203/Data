package id.ac.binus.calculator;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

    TextView txtInputText;
    Button btnSatu, btnDua, btnTiga, btnEmpat, btnLima, btnEnam, btnTujuh, btnDelapan, btnSembilan,
            btnEnol, btnPlus, btnMinus, btnDivide, btnTimes, btnEquals;

    String input="";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        txtInputText = findViewById(R.id.txtInputan);

        btnSatu = findViewById(R.id.btnSatu);
        btnDua = findViewById(R.id.btnDua);
        btnTiga = findViewById(R.id.btnTiga);
        btnEmpat = findViewById(R.id.btnEmpat);
        btnLima = findViewById(R.id.btnLima);
        btnEnam = findViewById(R.id.btnEnam);
        btnTujuh = findViewById(R.id.btnTujuh);
        btnDelapan = findViewById(R.id.btnDelapan);
        btnSembilan = findViewById(R.id.btnSembilan);
        btnEnol = findViewById(R.id.btnEnol);

        btnPlus = findViewById(R.id.btnPlus);
        btnMinus = findViewById(R.id.btnMinus);
        btnDivide = findViewById(R.id.btnDivide);
        btnTimes = findViewById(R.id.btnTimes);
        btnEquals = findViewById(R.id.btnEquals);

        btnSatu.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                input += "1";
                txtInputText.setText(input);
            }
        });

        btnDua.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                input += "2";
                txtInputText.setText(input);
            }
        });

        btnTiga.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                input += "3";
                txtInputText.setText(input);
            }
        });

        btnEmpat.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                input += "4";
                txtInputText.setText(input);
            }
        });

        btnLima.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                input += "5";
                txtInputText.setText(input);
            }
        });

        btnEnam.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                input += "6";
                txtInputText.setText(input);
            }
        });

        btnTujuh.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                input += "7";
                txtInputText.setText(input);
            }
        });

        btnDelapan.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                input += "8";
                txtInputText.setText(input);
            }
        });

        btnSembilan.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                input += "9";
                txtInputText.setText(input);
            }
        });

        btnMinus.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                input += "-";
                txtInputText.setText(input);
            }
        });

        btnPlus.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                input += "+";
                txtInputText.setText(input);
            }
        });

        btnDivide.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                input += "/";
                txtInputText.setText(input);
            }
        });

        btnTimes.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                input += "*";
                txtInputText.setText(input);
            }
        });

        btnEquals.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String[] text = input.split("(?<=[-+*/])|(?=[-+*/])");
                int numberOne = Integer.parseInt(text[0]);
                int numberTwo = Integer.parseInt(text[2]);
                String operand = text[1];

                int hasil = 0;

                if(operand.equalsIgnoreCase("+")){
                    hasil = numberOne + numberTwo;
                } else if (operand.equalsIgnoreCase("-")){
                    hasil = numberOne - numberTwo;
                } else if (operand.equalsIgnoreCase("/")){
                    hasil = numberOne / numberTwo;
                } else if (operand.equalsIgnoreCase("*")){
                    hasil = numberOne * numberTwo;
                }

                txtInputText.setText(String.valueOf(hasil));
                input = "";

            }
        });
    }
}