#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <TimeLib.h>

byte enie[8] = {B11111,
                B00000,
                B10001,
                B11001,
                B10101,
                B10011,
                B10001,
                B0000};
const byte nfilas = 4;
const byte ncolumnas = 4;
char keys[nfilas][ncolumnas] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
const byte pinsFilas[nfilas] = {9, 8, 7, 6};
const byte pinsColumnas[ncolumnas] = {5, 4, 3, 2};
Keypad teclado = Keypad(makeKeymap(keys), pinsFilas, pinsColumnas, nfilas, ncolumnas);
LiquidCrystal_I2C lcd(0x3f, 16, 2);
time_t t = now();
char key;
String diaSemana;
boolean luz = false;
//Variables Zona 1
Array diasSemanaZ1 = [{
  false},{false},{false},{false},{false},{false},{false}
}];
byte horaZ1;
byte minutoZ1;
byte horaFinZ1;
byte minutFinZ1;
boolean pinz1 = false;
//Variables Zona2
Array diasSemanaZ2 = [{
  false},{false},{false},{false},{false},{false},{false}
}];
byte horaZ2;
byte minutoZ2;
byte horaFinZ2;
byte minutFinZ2;
boolean pinz2 = false;
//Variables Zona3
Array diasSemanaZ3 = [{
  false},{false},{false},{false},{false},{false},{false}
}];
byte horaZ3;
byte minutoZ3;
byte horaFinZ3;
byte minutFinZ3;
boolean pinz3 = false;
//Variables Zona4
Array diasSemanaZ4 = [{
  false},{false},{false},{false},{false},{false},{false}
}];
byte horaZ4;
byte minutoZ4;
byte horaFinZ4;
byte minutFinZ4;
boolean pinz4 = false;
//Variables Zona5
Array diasSemanaZ5 = [{
  false},{false},{false},{false},{false},{false},{false}
}];
byte horaZ5;
byte minutoZ5;
byte horaFinZ5;
byte minutFinZ5;
boolean pinz5 = false;
//PINES SALIDA
byte salida1 = A1;
byte salida2 = A2;
byte salida3 = 10;
byte salida4 = 11;
byte salida5 = 12;
                                          //SETUP INICIO
void setup()
{
  pinMode(salida1, OUTPUT);
  digitalWrite(salida1, HIGH);
  pinMode(salida2, OUTPUT);
  digitalWrite(salida2, HIGH);
  pinMode(salida3, OUTPUT);
  digitalWrite(salida3, HIGH);
  pinMode(salida4, OUTPUT);
  digitalWrite(salida4, HIGH);
  pinMode(salida5, OUTPUT);
  digitalWrite(salida5, HIGH);
  Serial.begin(9600);
  lcd.init();
  lcd.noBacklight();
  lcd.createChar(0, enie);
}
                                            //METODO LOOP
void loop()
{
  imprSemana();
  imprimirHora();
  key = teclado.getKey();
  if (key == '#')
  {
    menu();
  }

  if (key == '*')
  {

    if (luz == true)
    {
      lcd.noBacklight();
      luz = false;
    }
    else
    {
      lcd.backlight();
      luz = true;
    }
  }
  ComprobarPrograma(horaZ1,minutoZ1,horaFinZ1,minutFinZ1,diasSemanaZ1,salida1,pinz1);
  ComprobarPrograma(horaZ2,minutoZ2,horaFinZ2,minutFinZ2,diasSemanaZ2,salida2,pinz2);
  ComprobarPrograma(horaZ3,minutoZ3,horaFinZ3,minutFinZ3,diasSemanaZ3,salida3,pinz3);
  ComprobarPrograma(horaZ4,minutoZ4,horaFinZ4,minutFinZ4,diasSemanaZ4,salida4,pinz4);
  ComprobarPrograma(horaZ5,minutoZ5,horaFinZ5,minutFinZ5,diasSemanaZ5,salida5,pinz5);
  imprimirEstado();
}

                                    //Metodo Configurar Hora

void ponerHora()
{
  lcd.clear();
  bool puls = false;
  byte hora = 0;
  byte cont = 0;
  lcd.setCursor(0, 0);
  lcd.print(" AJUSTAR HORA ");
  while (puls == false)
  {
    lcd.setCursor(4, 1);
    lcd.print("HH: ");
    if (hora < 10)
    {
      lcd.print("0");
      lcd.print(hora);
    }
    else
    {
      lcd.print(hora);
    }
    key = teclado.getKey();
    if (key == 'B')
    {
      if (hora > 0)
      {
        hora--;
      }
    }
    if (key == 'A')
    {
      if (hora < 24)
      {
        hora++;
      }
    }
    if (key == '1')
    {
      if (cont == 0)
      {
        hora = 10;
        cont = 1;
      }
      else if (cont == 1 or cont == 2)
      {
        hora++;
        cont = 0;
      }
    }
    if (key == '2')
    {
      if (cont == 0)
      {
        hora = 20;
        cont = 2;
      }
      else if (cont == 2 or cont == 1)
      {
        hora += 2;
        cont = 0;
      }
    }
    if (key == '3' && (cont == 1 or cont == 2))
    {
      hora += 3;
      cont = 0;
    }
    if (key == '4' && (cont == 1 or cont == 2))
    {
      hora += 4;
      cont = 0;
    }
    if (key == '5' && cont == 1)
    {
      hora += 5;
      cont = 0;
    }
    if (key == '6' && cont == 1)
    {
      hora += 6;
      cont = 0;
    }
    if (key == '7' && cont == 1)
    {
      hora += 7;
      cont = 0;
    }
    if (key == '8' && cont == 1)
    {
      hora += 8;
      cont = 0;
    }
    if (key == '9' && cont == 1)
    {
      hora += 9;
      cont = 0;
    }

    if (key == 'D')
    {
      puls = true;
      cont = 0;
    }
  }
  byte minutos = 0;
  while (puls == true)
  {
    lcd.setCursor(4, 1);
    lcd.print("MM: ");
    if (minutos < 10)
    {
      lcd.print("0");
      lcd.print(minutos);
    }
    else
    {
      lcd.print(minutos);
    }
    key = teclado.getKey();
    if (key == 'B')
    {
      if (minutos > 0)
      {
        minutos--;
      }
    }
    if (key == 'A')
    {
      if (minutos < 59)
      {
        minutos++;
      }
    }
    if (key == '1')
    {
      if (cont == 0)
      {
        minutos = 10;
        cont = 1;
      }
      else
      {
        minutos += 1;
        ;
        cont = 0;
      }
    }
    if (key == '2')
    {
      if (cont == 0)
      {
        minutos = 20;
        cont = 2;
      }
      else
      {
        minutos += 2;
        cont = 0;
      }
    }
    if (key == '3')
    {
      if (cont == 0)
      {
        minutos = 30;
        cont = 3;
      }
      else
      {
        minutos += 3;
        cont = 0;
      }
    }
    if (key == '4')
    {
      if (cont == 0)
      {
        minutos = 40;
        cont = 4;
      }
      else
      {
        minutos += 4;
        cont = 0;
      }
    }
    if (key == '5')
    {
      if (cont == 0)
      {
        minutos = 50;
        cont = 5;
      }
      else
      {
        minutos += 5;
        cont = 0;
      }
    }
    if (key == '6' && cont != 0)
    {
      minutos += 6;
      cont = 0;
    }
    if (key == '7' && cont != 0)
    {
      minutos += 7;
      cont = 0;
    }
    if (key == '8' && cont != 0)
    {
      minutos += 8;
      cont = 0;
    }
    if (key == '9' && cont != 0)
    {
      minutos += 9;
      cont = 0;
    }

    if (key == 'D')
    {
      puls = false;
      cont = 0;
    }
  }
  byte dia = 1;
  lcd.clear();
  while (puls == false)
  {
    lcd.setCursor(0, 0);
    lcd.print("Dia del mes:  ");
    lcd.setCursor(13, 0);
    if (dia < 10)
    {
      lcd.print("0");
      lcd.print(dia);
    }
    else
    {
      lcd.print(dia);
    }
    key = teclado.getKey();
    if (key == 'B')
    {
      if (dia > 1)
      {
        dia--;
      }
    }
    if (key == 'A')
    {
      if (dia < 31)
      {
        dia++;
      }
    }
    if (key == '1')
    {
      if (cont == 0)
      {
        dia = 10;
        cont = 1;
      }
      else if (cont == 1 or cont == 2 or cont == 3)
      {
        dia += 1;
        cont = 0;
      }
    }
    if (key == '2')
    {
      if (cont == 0)
      {
        dia = 20;
        cont = 2;
      }
      else if (cont == 2 or cont == 1)
      {
        dia += 2;
        cont = 0;
      }
    }
    if (key == '3')
    {
      if (cont == 0)
      {
        dia = 30;
        cont = 3;
      }
      else if (cont == 2 or cont == 1)
      {
        dia += 3;
        cont = 0;
      }
    }
    if (key == '4' && (cont == 1 or cont == 2))
    {
      dia += 4;
      cont = 0;
    }
    if (key == '5' && (cont == 1 or cont == 2))
    {
      dia += 5;
      cont = 0;
    }
    if (key == '6' && (cont == 1 or cont == 2))
    {
      dia += 6;
      cont = 0;
    }
    if (key == '7' && (cont == 1 or cont == 2))
    {
      dia += 7;
      cont = 0;
    }
    if (key == '8' && (cont == 1 or cont == 2))
    {
      dia += 8;
      cont = 0;
    }
    if (key == '9' && (cont == 1 or cont == 2))
    {
      dia += 9;
      cont = 0;
    }
    if (key == 'D')
    {
      puls = true;
      cont = 0;
      lcd.clear();
    }
  }
  byte mes = 1;
  while (puls == true)
  {
    lcd.setCursor(0, 0);
    lcd.print("Mes");
    lcd.setCursor(13, 0);
    if (mes < 10)
    {
      lcd.print("0");
      lcd.print(mes);
    }
    else
    {
      lcd.print(mes);
    }
    key = teclado.getKey();
    if (key == 'B')
    {
      if (mes > 1)
      {
        mes--;
      }
    }
    if (key == 'A')
    {
      if (mes < 12)
      {
        mes++;
      }
    }
    if (key == '1')
    {
      if (cont == 0)
      {
        mes = 10;
        cont = 1;
      }
      else
      {
        mes += 1;
        cont = 0;
      }
    }
    if (key == '2')
    {
      if (cont == 1)
      {
        mes += 2;
        cont = 0;
      }
      else
      {
        mes = 2;
      }
    }
    if (key == '3')
    {
      mes = 3;
      cont = 0;
    }
    if (key == '4')
    {
      mes = 4;
      cont = 0;
    }
    if (key == '5')
    {
      mes = 5;
      cont = 0;
    }
    if (key == '6')
    {
      mes = 6;
      cont = 0;
    }
    if (key == '7')
    {
      mes = 7;
      cont = 0;
    }
    if (key == '8')
    {
      mes = 8;
      cont = 0;
    }
    if (key == '9')
    {
      mes = 9;
      cont = 0;
    }
    if (key == '0')
    {
      if (cont == 1)
      {
        mes = 10;
        cont = 0;
      }
    }
    if (key == 'D')
    {
      puls = false;
      lcd.clear();
    }
  }
  long anio = 2020;
  while (puls == false)
  {
    lcd.setCursor(0, 0);
    lcd.print("A");
    lcd.write(0);
    lcd.print("O:");
    lcd.setCursor(10, 0);
    lcd.print(anio);
    key = teclado.getKey();
    if (key == 'B')
    {
      anio--;
    }
    if (key == 'A')
    {
      anio++;
    }
    if (key == 'D')
    {
      puls = true;
      lcd.clear();
    }
  }
  setTime(hora, minutos, 00, dia, mes, anio);
}

                                //Metodo Imprimir dia de la semana pantalla
void imprSemana()
{
  if (weekday() == 2)
  {
    diaSemana = "LUNS";
  }
  else if (weekday() == 3)
  {
    diaSemana = "MART";
  }
  else if (weekday() == 4)
  {
    diaSemana = "MIER";
  }
  else if (weekday() == 5)
  {
    diaSemana = "JUEV";
  }
  else if (weekday() == 6)
  {
    diaSemana = "VIER";
  }
  else if (weekday() == 0)
  {
    diaSemana = "SABA";
  }
  else if (weekday() == 1)
  {
    diaSemana = "DOMI";
  }
  lcd.setCursor(12, 0);
  lcd.print(diaSemana);
}

                                    //Metodo imprimir hora pantalla
void imprimirHora()
{
  lcd.setCursor(0, 0);
  if (hour() < 10)
  {
    lcd.print("0");
    lcd.print(hour());
  }
  else
  {
    lcd.print(hour());
  }
  lcd.print(":");
  if (minute() < 10)
  {
    lcd.print("0");
    lcd.print(minute());
  }
  else
  {
    lcd.print(minute());
  }
  lcd.print(":");
  lcd.setCursor(6, 0);
  if (second() < 10)
  {
    lcd.print("0");
    lcd.print(second());
  }
  else
  {
    lcd.print(second());
    lcd.setCursor(8, 0);
    lcd.print(" ");
  }
}

                                                  //MENU
void menu()
{
  byte opc = 0;
  byte opce = 0;
  boolean salir = false;
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("--MENU--");
  while (salir == false)
  {
    key = teclado.getKey();
    if (key == 'A')
    {
      if (opc < 6)
      {
        opc++;
      }
      else
      {
        opc = 0;
      }
    }
    else if (key == 'B')
    {
      if (opc > 0)
      {
        opc--;
      }
      else
      {
        opc = 6;
      }
    }
    else if (key == 'C')
    {
      salir = true;
    }
    else if (key == 'D')
    {
      opc = 7;
    }
    switch (opc)
    {
    case 0:
      lcd.setCursor(0, 1);
      lcd.print("AJUST HORA/FECHA");
      opce = 0;
      break;
    case 1:
      lcd.setCursor(0, 1);
      lcd.print("PROGRAMAR ZONA 1");
      opce = 1;
      break;

    case 2:
      lcd.setCursor(0, 1);
      lcd.print("PROGRAMAR ZONA 2");
      opce = 2;
      break;
    case 3:
      lcd.setCursor(0, 1);
      lcd.print("PROGRAMAR ZONA 3");
      opce = 3;
      break;
    case 4:
      lcd.setCursor(0, 1);
      lcd.print("PROGRAMAR ZONA 4");
      opce = 4;
      break;
    case 5:
      lcd.setCursor(0, 1);
      lcd.print("PROGRAMAR ZONA 5");
      opce = 5;
      break;
    case 6:
      lcd.setCursor(0, 1);
      lcd.print("   MODO MANUAL  ");
      opce = 6;
      break;
    case 7:
      switch (opce)
      {
      case 0:
        ponerHora();
        salir = true;
        break;
      case 1:
        programarZona(horaZ1, minutoZ1, horaFinZ1, minutFinZ1, diasSemanaZ1);
        salir = true;
        break;
      case 2:
        programarZona(horaZ2, minutoZ2, horaFinZ2, minutFinZ2, diasSemanaZ2);
        salir = true;
        break;
      case 3:
        programarZona(horaZ3, minutoZ3, horaFinZ3, minutFinZ3, diasSemanaZ3);
        salir = true;
        break;
      case 4:
        programarZona(horaZ4, minutoZ4, horaFinZ4, minutFinZ4, diasSemanaZ4);
        salir = true;
        break;
      case 5:
        programarZona(horaZ5, minutoZ5, horaFinZ5, minutFinZ5, diasSemanaZ5);
        salir = true;
        break;
      case 6:
        manual();
        salir = true;
        break;
      }
    }
  }
  delay(500);
  lcd.clear();
}
                                                //METODO PROGRAMAR ZONA

void programarZona(byte horaIni, byte minutoIni, byte horaFin, byte minutFin, Array diasSemana)
{
  boolean salir = false;
  horaIni = 0;
  minutoIni = 0;
  horaFin = 0;
  minutFin = 0;
  diaSemana[0] = false;
  diaSemana[1] = false;
  diaSemana[2] = false;
  diaSemana[3] = false;
  diaSemana[4] = false;
  diaSemana[5] = false;
  diaSemana[6] = false;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" HORA DE INICIO");
  //Llamar metodo hora
  programarHoraZona(horaIni, minutoIni);
  lcd.print(" HORA FINAL");
  programarHoraZona(horaFin, minutFin);
  lcd.print("   DIAS SEMANA   ");
  //LlamarProgramarDias
  programarDiaSemana("Lunes", diasSemana[0]);
  programarDiaSemana("Martes", diasSemana[1]);
  programarDiaSemana("Miercoles", diasSemana[2]);
  programarDiaSemana("Jueves", diasSemana[3]);
  programarDiaSemana("Viernes", diasSemana[4]);
  programarDiaSemana("Sabado", diasSemana[5]);
  programarDiaSemana("Domingo", diasSemana[6]);
}

                                              //METODO PROGRAMAR HORA DE ZONA

void programarHoraZona(byte hora, byte minuto)
{
  byte cont = 0;
  boolean salir = false;
  while (salir == false)
  {
    lcd.setCursor(4, 1);
    lcd.print("HH: ");
    if (hora < 10)
    {
      lcd.print("0");
      lcd.print(hora);
    }
    else
    {
      lcd.print(hora);
    }
    key = teclado.getKey();
    if (key == 'B')
    {
      if (hora > 0)
      {
        hora--;
      }
    }
    if (key == 'A')
    {
      if (hora < 24)
      {
        hora++;
      }
    }
    if (key == '1')
    {
      if (cont == 0)
      {
        hora = 10;
        cont = 1;
      }
      else if (cont == 1 or cont == 2)
      {
        hora++;
        cont = 0;
      }
    }
    if (key == '2')
    {
      if (cont == 0)
      {
        hora = 20;
        cont = 2;
      }
      else if (cont == 2 or cont == 1)
      {
        hora += 2;
        cont = 0;
      }
    }
    if (key == '3' && (cont == 1 or cont == 2))
    {
      hora += 3;
      cont = 0;
    }
    if (key == '4' && (cont == 1 or cont == 2))
    {
      hora += 4;
      cont = 0;
    }
    if (key == '5' && cont == 1)
    {
      hora += 5;
      cont = 0;
    }
    if (key == '6' && cont == 1)
    {
      hora += 6;
      cont = 0;
    }
    if (key == '7' && cont == 1)
    {
      hora += 7;
      cont = 0;
    }
    if (key == '8' && cont == 1)
    {
      hora += 8;
      cont = 0;
    }
    if (key == '9' && cont == 1)
    {
      hora += 9;
      cont = 0;
    }
    if (key == 'D')
    {
      salir = true;
      cont = 0;
    }
  }
  while (salir == true)
  {
    lcd.setCursor(4, 1);
    lcd.print("MM: ");
    if (minuto < 10)
    {
      lcd.print("0");
      lcd.print(minuto);
    }
    else
    {
      lcd.print(minuto);
    }
    key = teclado.getKey();
    if (key == 'B')
    {
      if (minuto > 0)
      {
        minuto--;
      }
    }
    if (key == 'A')
    {
      if (minuto < 59)
      {
        minuto++;
      }
    }
    if (key == '1')
    {
      if (cont == 0)
      {
        minuto = 10;
        cont = 1;
      }
      else
      {
        minuto += 1;
        ;
        cont = 0;
      }
    }
    if (key == '2')
    {
      if (cont == 0)
      {
        minuto = 20;
        cont = 2;
      }
      else
      {
        minuto += 2;
        cont = 0;
      }
    }
    if (key == '3')
    {
      if (cont == 0)
      {
        minuto = 30;
        cont = 3;
      }
      else
      {
        minuto += 3;
        cont = 0;
      }
    }
    if (key == '4')
    {
      if (cont == 0)
      {
        minuto = 40;
        cont = 4;
      }
      else
      {
        minuto += 4;
        cont = 0;
      }
    }
    if (key == '5')
    {
      if (cont == 0)
      {
        minuto = 50;
        cont = 5;
      }
      else
      {
        minuto += 5;
        cont = 0;
      }
    }
    if (key == '6' && cont != 0)
    {
      minuto += 6;
      cont = 0;
    }
    if (key == '7' && cont != 0)
    {
      minuto += 7;
      cont = 0;
    }
    if (key == '8' && cont != 0)
    {
      minuto += 8;
      cont = 0;
    }
    if (key == '9' && cont != 0)
    {
      minuto += 9;
      cont = 0;
    }
    if (key == 'D')
    {
      salir = false;
      cont = 0;
    }
  }
  lcd.clear();
  lcd.setCursor(0, 0);
}
                                      //METODO PROGRAMAR DIA DE LA SEMANA

void programarDiaSemana(String diaString, boolean diaVar)
{
  boolean salir = false;
  lcd.setCursor(0, 1);
  lcd.print("   " + diaString + ": NO   ");
  while (salir == false)
  {
    key = teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B')
    {
      lcd.print("   " + diaString + ": NO   ");
      diaVar = false;
    }
    if (key == 'A')
    {
        lcd.print("   "+diaString+": SI   "));
        diaVar = true;
    }
    if (key == 'D')
    {
      diaVar = true;
    }
  }
  lcd.clear();
}

                                              //ComprobarPrograma

void ComprobarPrograma(byte horaIni,byte minutoIni,byte horaFin,byte minutoFin,Array diasSemana,byte PinSalida,boolean salida)
{
  if (hour() == horaIni && minutoIni == minute())
  {
    if (weekday() == 2 && diasSemana[0] == true)
    {
      digitalWrite(PinSalida, LOW);
      salida = true;
    }
    if (weekday() == 3 && diasSemana[1] == true)
    {
      digitalWrite(PinSalida, LOW);
      salida = true;
    }
    if (weekday() == 4 && diasSemana[2] == true)
    {
      digitalWrite(PinSalida, LOW);
      salida = true;
    }
    if (weekday() == 5 && diasSemana[3] == true)
    {
      digitalWrite(PinSalida, LOW);
      salida = true;
    }
    if (weekday() == 6 && diasSemana[4] == true)
    {
      digitalWrite(PinSalida, LOW);
      salida = true;
    }
    if (weekday() == 0 && diasSemana[5] == true)
    {
      digitalWrite(PinSalida, LOW);
      salida = true;
    }
    if (weekday() == 1 && diasSemana[6] == true)
    {
      digitalWrite(PinSalida, LOW);
      salida = true;
    }
  }
  if (hour() == horaFin && minutoFin == minute())
  {
    digitalWrite(PinSalida, HIGH);
    salida = false;
  }
}

                                        //Metodo Imprimir Estado Zonas
void imprimirEstado()
{
  lcd.setCursor(0, 1);
  lcd.print("REGANDO Z:");
  if (pinz1 == true)
  {
    lcd.setCursor(11, 1);
    lcd.print("1");
  }
  else
  {
    lcd.setCursor(11, 1);
    lcd.print(" ");
  }
  if (pinz2 == true)
  {
    lcd.setCursor(12, 1);
    lcd.print("2");
  }
  else
  {
    lcd.setCursor(12, 1);
    lcd.print(" ");
  }
  if (pinz3 == true)
  {
    lcd.setCursor(13, 1);
    lcd.print("3");
  }
  else
  {
    lcd.setCursor(13, 1);
    lcd.print(" ");
  }
  if (pinz4 == true)
  {
    lcd.setCursor(14, 1);
    lcd.print("4");
  }
  else
  {
    lcd.setCursor(14, 1);
    lcd.print(" ");
  }
  if (pinz5 == true)
  {
    lcd.setCursor(15, 1);
    lcd.print("5");
  }
  else
  {
    lcd.setCursor(15, 1);
    lcd.print(" ");
  }
}
                                                //METODO MANUAL
void manual()
{
  byte opcm = 0;
  byte opcem = 0;
  boolean salirm = false;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" -MODO MANUAL- ");
  while (salirm == false)
  {
    key = teclado.getKey();
    if (key == 'A')
    {
      if (opcm < 4)
      {
        opcm++;
      }
      else
      {
        opcm = 0;
      }
    }
    else if (key == 'B')
    {
      if (opcm > 0)
      {
        opcm--;
      }
      else
      {
        opcm = 4;
      }
    }
    else if (key == 'C')
    {
      salirm = true;
    }
    else if (key == 'D')
    {
      opcm = 5;
    }
    switch (opcm)
    {
    case 0:
      lcd.setCursor(0, 1);
      lcd.print("ZONA 1");
      opcem = 0;
      break;
    case 1:
      lcd.setCursor(0, 1);
      lcd.print("ZONA 2");
      opcem = 1;
      break;

    case 2:
      lcd.setCursor(0, 1);
      lcd.print("ZONA 3");
      opcem = 2;
      break;
    case 3:
      lcd.setCursor(0, 1);
      lcd.print("ZONA 4");
      opcem = 3;
      break;
    case 4:
      lcd.setCursor(0, 1);
      lcd.print("ZONA 5");
      opcem = 4;
      break;
    case 5:
      switch (opcem)
      {
      case 0:
        if (pinz1 == true)
        {
          digitalWrite(salida1, HIGH);
          pinz1 = false;
        }
        else if (pinz1 == false)
        {
          digitalWrite(salida1, LOW);
          pinz1 = true;
        }
        salirm = true;
        break;
      case 1:
        if (pinz2 == true)
        {
          digitalWrite(salida2, HIGH);
          pinz2 = false;
        }
        else if (pinz2 == false)
        {
          digitalWrite(salida2, LOW);
          pinz2 = true;
        }
        salirm = true;
        break;
      case 2:
        if (pinz3 == true)
        {
          digitalWrite(salida3, HIGH);
          pinz3 = false;
        }
        else if (pinz3 == false)
        {
          digitalWrite(salida3, LOW);
          pinz3 = true;
        }
        salirm = true;
        break;
      case 3:
        if (pinz4 == true)
        {
          digitalWrite(salida4, HIGH);
          pinz4 = false;
        }
        else if (pinz4 == false)
        {
          digitalWrite(salida4, LOW);
          pinz4 = true;
        }
        salirm = true;
        break;
      case 4:
        if (pinz5 == true)
        {
          digitalWrite(salida5, HIGH);
          pinz5 = false;
        }
        else if (pinz5 == false)
        {
          digitalWrite(salida5, LOW);
          pinz5 = true;
        }
        salirm = true;
        break;
      }
    }
  }
  delay(500);
  lcd.clear();
}
