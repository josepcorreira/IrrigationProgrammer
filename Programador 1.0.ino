#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <TimeLib.h>
byte enie[8]={B11111,
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
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
const byte pinsFilas[nfilas] = { 9, 8, 7, 6 };
const byte pinsColumnas[ncolumnas] = { 5, 4, 3, 2 };
Keypad teclado = Keypad(makeKeymap(keys), pinsFilas, pinsColumnas, nfilas, ncolumnas);
LiquidCrystal_I2C lcd(0x3f, 16, 2);
time_t t = now();
char key;
String diaSemana;
boolean luz=false;
//Variables Zona 1
boolean lunz1=false;
boolean marz1=false;
boolean mierz1=false;
boolean juevz1=false;
boolean vierz1=false;
boolean sabz1=false;
boolean domz1=false;
byte horaIniZ1;
byte minutIniZ1;
byte horaFinZ1;
byte minutFinZ1;
boolean pinz1=false;
//Variables Zona2
boolean lunz2=false;
boolean marz2=false;
boolean mierz2=false;
boolean juevz2=false;
boolean vierz2=false;
boolean sabz2=false;
boolean domz2=false;
byte horaIniZ2;
byte minutIniZ2;
byte horaFinZ2;
byte minutFinZ2;
boolean pinz2=false;
//Variables Zona3
boolean lunz3=false;
boolean marz3=false;
boolean mierz3=false;
boolean juevz3=false;
boolean vierz3=false;
boolean sabz3=false;
boolean domz3=false;
byte horaIniZ3;
byte minutIniZ3;
byte horaFinZ3;
byte minutFinZ3;
boolean pinz3=false;
//Variables Zona4
boolean lunz4=false;
boolean marz4=false;
boolean mierz4=false;
boolean juevz4=false;
boolean vierz4=false;
boolean sabz4=false;
boolean domz4=false;
byte horaIniZ4;
byte minutIniZ4;
byte horaFinZ4;
byte minutFinZ4;
boolean pinz4=false;
//Variables Zona5
boolean lunz5=false;
boolean marz5=false;
boolean mierz5=false;
boolean juevz5=false;
boolean vierz5=false;
boolean sabz5=false;
boolean domz5=false;
byte horaIniZ5;
byte minutIniZ5;
byte horaFinZ5;
byte minutFinZ5;
boolean pinz5=false;
//PINES SALIDA
byte salida1=A1;
byte salida2=A2;
byte salida3=10;
byte salida4=11;
byte salida5=12;
                                          //SETUP INICIO
void setup() {
  pinMode(salida1, OUTPUT);
  digitalWrite(salida1,HIGH);
  pinMode(salida2, OUTPUT);
  digitalWrite(salida2,HIGH);
  pinMode(salida3, OUTPUT);
  digitalWrite(salida3,HIGH);
  pinMode(salida4, OUTPUT);
  digitalWrite(salida4,HIGH);
  pinMode(salida5, OUTPUT);
  digitalWrite(salida5,HIGH);
  Serial.begin(9600);
  lcd.init();
  lcd.noBacklight();
  lcd.createChar(0,enie);
}
                                               //METODO LOOP 
void loop() {
  imprSemana();
  imprimirHora();
  key = teclado.getKey();
  if(key=='#'){
      menu();
    }
  if(key=='*'){
    if(luz==true){
    lcd.noBacklight();
    luz=false;
    }else{lcd.backlight();
    luz=true;}
  }
  programaz1();
  programaz2();
  programaz3();
  programaz4();
  programaz5();
  imprimirEstado();
}

                                               //Metodo Configurar Hora
      
void ponerHora() {
  lcd.clear();
  bool puls=false;
  byte hora=0;
  byte cont=0;
  lcd.setCursor(0, 0);
  lcd.print(" AJUSTAR HORA ");
  while(puls==false){
    lcd.setCursor(4, 1);
    lcd.print("HH: ");
    if(hora<10){
      lcd.print("0");
      lcd.print(hora);
    }else{
    lcd.print(hora);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(hora>0){
      hora--;
      }
    }
    if (key == 'A'){
      if(hora<24){
        hora++;
      }
    }
    if(key=='1'){
      if(cont==0){
      hora=10;
      cont=1;
      }
      else if(cont==1 or cont==2){
        hora++;
        cont=0;
        }
      }
    if (key=='2'){
      if(cont==0){
      hora=20;
      cont=2;
      }else if(cont==2 or cont==1){
      hora+=2;
      cont=0;
      }
      }
    if(key=='3' && (cont==1 or cont==2)){
      hora+=3;
      cont=0;
      }
    if(key=='4' && (cont==1 or cont==2)){
      hora+=4;
      cont=0;
      }
    if(key=='5' && cont==1){
      hora+=5;
      cont=0;
      }
    if(key=='6' && cont==1){
      hora+=6;
      cont=0;
      }
    if(key=='7' && cont==1){
      hora+=7;
      cont=0;
      }
    if(key=='8' && cont==1){
      hora+=8;
      cont=0;
      }
    if(key=='9' && cont==1){
      hora+=9;
      cont=0;
      }
    
    if (key== 'D'){
      puls=true;
      cont=0;
      }
    }
  byte minutos=0;
  while(puls==true){
    lcd.setCursor(4, 1);
    lcd.print("MM: ");
    if(minutos<10){
      lcd.print("0");
      lcd.print(minutos);
    }else{
    lcd.print(minutos);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(minutos>0){
      minutos--;
      }
    }
    if (key == 'A'){
      if(minutos<59){
        minutos++;
      }
    }
    if(key=='1'){
      if(cont==0){
      minutos=10;
      cont=1;
      }
      else{
        minutos+=1;;
        cont=0;
        }
      }
    if (key=='2'){
      if(cont==0){
      minutos=20;
      cont=2;
      }else{
      minutos+=2;
      cont=0;
      }
      }
    if (key=='3'){
      if(cont==0){
      minutos=30;
      cont=3;
      }else{
      minutos+=3;
      cont=0;
      }
      }
    if (key=='4'){
      if(cont==0){
      minutos=40;
      cont=4;
      }else{
      minutos+=4;
      cont=0;
      }
      }
    if (key=='5'){
      if(cont==0){
      minutos=50;
      cont=5;
      }else{
      minutos+=5;
      cont=0;
      }
      }
    if(key=='6' && cont != 0){
      minutos+=6;
      cont=0;
      }
    if(key=='7' && cont != 0){
      minutos+=7;
      cont=0;
      }
    if(key=='8' && cont != 0){
      minutos+=8;
      cont=0;
      }
    if(key=='9' && cont != 0){
      minutos+=9;
      cont=0;
      }
    
    if (key== 'D'){
      puls=false;
      cont=0;
      }
    }
  byte dia=1;
  lcd.clear();
  while(puls==false){
    lcd.setCursor(0, 0);
    lcd.print("Dia del mes:  ");
    lcd.setCursor(13, 0);
    if(dia<10){
      lcd.print("0");
      lcd.print(dia);
    }else{
    lcd.print(dia);  
    }
    key=teclado.getKey();
    if (key == 'B'){
      if(dia>1){
      dia--;
      }
    }
    if (key == 'A'){
      if(dia<31){
      dia++;
      }
    }
    if(key=='1'){
      if(cont==0){
      dia=10;
      cont=1;
      }
      else if(cont==1 or cont==2 or cont==3){
        dia+=1;
        cont=0;
        }
      }
    if (key=='2'){
      if(cont==0){
      dia=20;
      cont=2;
      }else if(cont==2 or cont==1){
      dia+=2;
      cont=0;
      }
      }
    if(key=='3'){
      if(cont==0){
      dia=30;
      cont=3;
      }else if(cont==2 or cont==1){
      dia+=3;
      cont=0;
      }
      }
    if(key=='4' && (cont==1 or cont==2)){
      dia+=4;
      cont=0;
      }
    if(key=='5' && (cont==1 or cont==2)){
      dia+=5;
      cont=0;
      }
    if(key=='6' && (cont==1 or cont==2)){
      dia+=6;
      cont=0;
      }
    if(key=='7' && (cont==1 or cont==2)){
      dia+=7;
      cont=0;
      }
    if(key=='8' && (cont==1 or cont==2)){
      dia+=8;
      cont=0;
      }
    if(key=='9' && (cont==1 or cont==2)){
      dia+=9;
      cont=0;
      }
    if (key== 'D'){
      puls=true;
      cont=0;
      lcd.clear();
      }
    }
  byte mes=1;
  while(puls==true){
    lcd.setCursor(0, 0);
    lcd.print("Mes");
    lcd.setCursor(13, 0);
    if(mes<10){
      lcd.print("0");
      lcd.print(mes);
    }else{
    lcd.print(mes);  
    }
    key=teclado.getKey();
    if (key == 'B'){
      if(mes>1){
      mes--;
      }
    }
    if (key == 'A'){
      if(mes<12){
      mes++;
      }
    }
    if(key=='1'){
      if(cont==0){
      mes=10;
      cont=1;
      }
      else{
        mes+=1;
        cont=0;
        }
      }
    if (key=='2'){
      if(cont==1){
      mes+=2;
      cont=0;
      }else{
        mes=2;
       }
    }
    if(key=='3'){
      mes=3;
      cont=0;
      }
    if(key=='4'){
      mes=4;
      cont=0;
      }
    if(key=='5'){
      mes=5;
      cont=0;
      }
    if(key=='6'){
      mes=6;
      cont=0;
      }
    if(key=='7'){
      mes=7;
      cont=0;
      }
    if(key=='8'){
      mes=8;
      cont=0;
      }
    if(key=='9'){
      mes=9;
      cont=0;
      }
    if(key=='0'){
      if(cont==1){
        mes=10;
        cont=0;
      }
    }
    if (key== 'D'){
      puls=false;
      lcd.clear();
      }
    }
  long anio=2019;
  while(puls==false){
    lcd.setCursor(0, 0);
    lcd.print("A");
    lcd.write(0);
    lcd.print("O:");
    lcd.setCursor(10, 0);
    lcd.print(anio);
    key=teclado.getKey();
    if (key == 'B'){
      anio--;
      }
    if (key == 'A'){
      anio++;
      }
    if (key== 'D'){
      puls=true;
      lcd.clear();
      }
    }
  setTime(hora,minutos,00,dia,mes,anio);
}

                                             //Metodo Imprimir dia de la semana pantalla
void imprSemana(){
    if(weekday()==2){
    diaSemana="LUNS";
    }else if(weekday()==3){
    diaSemana="MART";
    }else if(weekday()==4){
    diaSemana="MIER";
    }else if(weekday()==5){
    diaSemana="JUEV";
    }else if(weekday()==6){
    diaSemana="VIER";
    }else if(weekday()==0){
    diaSemana="SABA";
    }else if(weekday()==1){
    diaSemana="DOMI";
    }
    lcd.setCursor(12,0);
    lcd.print(diaSemana);
}

                                          //Metodo imprimir hora pantalla
 void imprimirHora(){
    lcd.setCursor(0,0);
    if(hour()<10){
      lcd.print("0");
      lcd.print(hour());
    }else{
      lcd.print(hour());}
    lcd.print(":");
    if(minute()<10 ){
      lcd.print("0");
      lcd.print(minute());
    }else{
      lcd.print(minute());}
    lcd.print(":");
    lcd.setCursor(6,0);
    if(second()<10){
      lcd.print("0");
      lcd.print(second());
    }else{
      lcd.print(second());
      lcd.setCursor(8,0);
      lcd.print(" ");}
  }

                                                      //MENU
 void menu(){
    byte opc=0;
    byte opce=0;
    boolean salir=false;
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("--MENU--");
    while(salir==false){
      key=teclado.getKey();
      if(key=='A'){
        if(opc<6){
          opc++;
        }else{opc=0;}
      }else if(key=='B'){
        if(opc>0){
          opc--;
        }else{opc=6;}
      }else if(key=='C'){
        salir=true;
      }else if(key=='D'){
        opc=7;
      }
      switch(opc){
        case 0:
          lcd.setCursor(0,1);
          lcd.print("AJUST HORA/FECHA");
          opce=0;
          break;
        case 1:
          lcd.setCursor(0,1);
          lcd.print("PROGRAMAR ZONA 1");
          opce=1;
          break;
          
        case 2:
          lcd.setCursor(0,1);
          lcd.print("PROGRAMAR ZONA 2");
          opce=2;
          break;
        case 3:
          lcd.setCursor(0,1);
          lcd.print("PROGRAMAR ZONA 3");
          opce=3;
          break;
        case 4:
          lcd.setCursor(0,1);
          lcd.print("PROGRAMAR ZONA 4");
          opce=4;
          break;
        case 5:
          lcd.setCursor(0,1);
          lcd.print("PROGRAMAR ZONA 5");
          opce=5;
          break;
        case 6:
          lcd.setCursor(0,1);
          lcd.print("   MODO MANUAL  ");
          opce=6;
          break;
        case 7:
          switch(opce){
            case 0:
              ponerHora();
              salir=true;
              break;
            case 1:
              programarZ1();
              salir=true;
              break;
            case 2:
              programarZ2();
              salir=true;
              break;
            case 3:
              programarZ3();
              salir=true;
              break;
            case 4:
              programarZ4();
              salir=true;
              break;
            case 5:
              programarZ5();
              salir=true;
              break;
            case 6:
              manual();
              salir=true;
              break;
            }
          }
          
        }
    delay(500);
    lcd.clear();
  }
                                             //PROGRAMAR ZONA1
 void programarZ1(){
  boolean salirz1 = false;
  byte contz1=0;
  horaIniZ1=0;
  minutIniZ1=0;
  horaFinZ1=0;
  minutFinZ1=0;
  lunz1=false;
  marz1=false;
  mierz1=false;
  juevz1=false;
  vierz1=false;
  sabz1=false;
  domz1=false;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" HORA DE INICIO");
  while(salirz1==false){
    lcd.setCursor(4,1);
    lcd.print("HH: ");
    if(horaIniZ1<10){
      lcd.print("0");
      lcd.print(horaIniZ1);
    }else{
    lcd.print(horaIniZ1);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(horaIniZ1>0){
      horaIniZ1--;
      }
    }
    if (key == 'A'){
      if(horaIniZ1<24){
        horaIniZ1++;
      }
    }
    if(key=='1'){
      if(contz1==0){
      horaIniZ1=10;
      contz1=1;
      }
      else if(contz1==1 or contz1==2){
        horaIniZ1++;
        contz1=0;
        }
      }
    if (key=='2'){
      if(contz1==0){
      horaIniZ1=20;
      contz1=2;
      }else if(contz1==2 or contz1==1){
      horaIniZ1+=2;
      contz1=0;
      }
      }
    if(key=='3' && (contz1==1 or contz1==2)){
      horaIniZ1+=3;
      contz1=0;
      }
    if(key=='4' && (contz1==1 or contz1==2)){
      horaIniZ1+=4;
      contz1=0;
      }
    if(key=='5' && contz1==1){
      horaIniZ1+=5;
      contz1=0;
      }
    if(key=='6' && contz1==1){
      horaIniZ1+=6;
      contz1=0;
      }
    if(key=='7' && contz1==1){
      horaIniZ1+=7;
      contz1=0;
      }
    if(key=='8' && contz1==1){
      horaIniZ1+=8;
      contz1=0;
      }
    if(key=='9' && contz1==1){
      horaIniZ1+=9;
      contz1=0;
      }
    if (key== 'D'){
      salirz1=true;
      contz1=0;
      }
    }
  while(salirz1==true){
    lcd.setCursor(4, 1);
    lcd.print("MM: ");
    if(minutIniZ1<10){
      lcd.print("0");
      lcd.print(minutIniZ1);
    }else{
    lcd.print(minutIniZ1);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(minutIniZ1>0){
      minutIniZ1--;
      }
    }
    if (key == 'A'){
      if(minutIniZ1<59){
        minutIniZ1++;
      }
    }
    if(key=='1'){
      if(contz1==0){
      minutIniZ1=10;
      contz1=1;
      }
      else{
        minutIniZ1+=1;;
        contz1=0;
        }
      }
    if (key=='2'){
      if(contz1==0){
      minutIniZ1=20;
      contz1=2;
      }else{
      minutIniZ1+=2;
      contz1=0;
      }
      }
    if (key=='3'){
      if(contz1==0){
      minutIniZ1=30;
      contz1=3;
      }else{
      minutIniZ1+=3;
      contz1=0;
      }
      }
    if (key=='4'){
      if(contz1==0){
      minutIniZ1=40;
      contz1=4;
      }else{
      minutIniZ1+=4;
      contz1=0;
      }
      }
    if (key=='5'){
      if(contz1==0){
      minutIniZ1=50;
      contz1=5;
      }else{
      minutIniZ1+=5;
      contz1=0;
      }
      }
    if(key=='6' && contz1 != 0){
      minutIniZ1+=6;
      contz1=0;
      }
    if(key=='7' && contz1 != 0){
      minutIniZ1+=7;
      contz1=0;
      }
    if(key=='8' && contz1 != 0){
      minutIniZ1+=8;
      contz1=0;
      }
    if(key=='9' && contz1 != 0){
      minutIniZ1+=9;
      contz1=0;
      }
    
    if (key== 'D'){
      salirz1=false;
      contz1=0;
      }
    }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" HORA FINAL");
  while(salirz1==false){
    lcd.setCursor(4,1);
    lcd.print("HH: ");
    if(horaFinZ1<10){
      lcd.print("0");
      lcd.print(horaFinZ1);
    }else{
    lcd.print(horaFinZ1);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(horaFinZ1>0){
      horaFinZ1--;
      }
    }
    if (key == 'A'){
      if(horaFinZ1<24){
        horaFinZ1++;
      }
    }
    if(key=='1'){
      if(contz1==0){
      horaFinZ1=10;
      contz1=1;
      }
      else if(contz1==1 or contz1==2){
        horaFinZ1++;
        contz1=0;
        }
      }
    if (key=='2'){
      if(contz1==0){
      horaFinZ1=20;
      contz1=2;
      }else if(contz1==2 or contz1==1){
      horaFinZ1+=2;
      contz1=0;
      }
      }
    if(key=='3' && (contz1==1 or contz1==2)){
      horaFinZ1+=3;
      contz1=0;
      }
    if(key=='4' && (contz1==1 or contz1==2)){
      horaFinZ1+=4;
      contz1=0;
      }
    if(key=='5' && contz1==1){
      horaFinZ1+=5;
      contz1=0;
      }
    if(key=='6' && contz1==1){
      horaFinZ1+=6;
      contz1=0;
      }
    if(key=='7' && contz1==1){
      horaFinZ1+=7;
      contz1=0;
      }
    if(key=='8' && contz1==1){
      horaFinZ1+=8;
      contz1=0;
      }
    if(key=='9' && contz1==1){
      horaFinZ1+=9;
      contz1=0;
      }
    if (key== 'D'){
      salirz1=true;
      contz1=0;
      }
    }
  while(salirz1==true){
    lcd.setCursor(4, 1);
    lcd.print("MM: ");
    if(minutFinZ1<10){
      lcd.print("0");
      lcd.print(minutFinZ1);
    }else{
    lcd.print(minutFinZ1);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(minutFinZ1>0){
      minutFinZ1--;
      }
    }
    if (key == 'A'){
      if(minutFinZ1<59){
        minutFinZ1++;
      }
    }
    if(key=='1'){
      if(contz1==0){
      minutFinZ1=10;
      contz1=1;
      }
      else{
        minutFinZ1+=1;;
        contz1=0;
        }
      }
    if (key=='2'){
      if(contz1==0){
      minutFinZ1=20;
      contz1=2;
      }else{
      minutFinZ1+=2;
      contz1=0;
      }
      }
    if (key=='3'){
      if(contz1==0){
      minutFinZ1=30;
      contz1=3;
      }else{
      minutFinZ1+=3;
      contz1=0;
      }
      }
    if (key=='4'){
      if(contz1==0){
      minutFinZ1=40;
      contz1=4;
      }else{
      minutFinZ1+=4;
      contz1=0;
      }
      }
    if (key=='5'){
      if(contz1==0){
      minutFinZ1=50;
      contz1=5;
      }else{
      minutFinZ1+=5;
      contz1=0;
      }
      }
    if(key=='6' && contz1 != 0){
      minutFinZ1+=6;
      contz1=0;
      }
    if(key=='7' && contz1 != 0){
      minutFinZ1+=7;
      contz1=0;
      }
    if(key=='8' && contz1 != 0){
      minutFinZ1+=8;
      contz1=0;
      }
    if(key=='9' && contz1 != 0){
      minutFinZ1+=9;
      contz1=0;
      }
    if (key== 'D'){
      salirz1=false;
      contz1=0;
      }
    }
  
    lcd.setCursor(0,0);
    lcd.print("   DIAS SEMANA   ");
    lcd.setCursor(0, 1);
    lcd.print("   Lunes: NO   ");
    while(salirz1==false){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Lunes: NO   ");
      lunz1=false;
    }
    if (key == 'A'){
      lcd.print("   Lunes: SI   ");
      lunz1=true;
    }
    if (key == 'D'){
      salirz1=true;
      }
   }
   lcd.setCursor(0, 1);
   lcd.print("   Martes: NO   ");
   while(salirz1==true){
   lcd.setCursor(0, 1);
   key=teclado.getKey();
    if (key == 'B'){
      lcd.print("   Martes: NO   ");
      marz1=false;
    }
    if (key == 'A'){
      lcd.print("   Martes: SI   ");
      marz1=true;
    }
    if (key == 'D'){
      salirz1=false;
      }
   }
  
    lcd.setCursor(0, 1);
    lcd.print(" Miercoles: NO  ");
    while(salirz1==false){
    lcd.setCursor(0, 1);
    key=teclado.getKey();
    if (key == 'B'){
      lcd.print(" Miercoles: NO  ");
      mierz1=false;
    }
    if (key == 'A'){
      lcd.print(" Miercoles: SI  ");
      mierz1=true;
    }
    if (key == 'D'){
      salirz1=true;
      }
   }
  
   lcd.setCursor(0, 1);
   lcd.print("   Jueves: NO   ");
   while(salirz1==true){
   key=teclado.getKey();
   lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Jueves: NO   ");
      juevz1=false;
    }
    if (key == 'A'){
      lcd.print("   Jueves: SI   ");
      juevz1=true;
    }
    if (key == 'D'){
      salirz1=false;
      }
   }
  
    lcd.setCursor(0, 1);
    lcd.print("   Viernes: NO  ");
    while(salirz1==false){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Viernes: NO  ");
      vierz1=false;
    }
    if (key == 'A'){
      lcd.print("   Viernes: SI  ");
      vierz1=true;
    }
    if (key == 'D'){
      salirz1=true;
      }
   }
 
    lcd.setCursor(0, 1);
    lcd.print("   Sabado: NO   ");
    while(salirz1==true){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Sabado: NO   ");
      sabz1=false;
    }
    if (key == 'A'){
      lcd.print("   Sabado: SI   ");
      sabz1=true;
    }
    if (key == 'D'){
      salirz1=false;
      }
   }
  
    lcd.setCursor(0, 1);
    lcd.print("  Domingo: NO   ");
    while(salirz1==false){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("  Domingo: NO   ");
      domz1=false;
    }
    if (key == 'A'){
      lcd.print("  Domingo: SI   ");
      domz1=true;
    }
    if (key == 'D'){
      salirz1=true;
      }
   }
  lcd.clear();
  }


                                                //PROGRAMAR ZONA 2
 void programarZ2(){
  boolean salirz2 = false;
  byte contz2=0;
  horaIniZ2=0;
  minutIniZ2=0;
  horaFinZ2=0;
  minutFinZ2=0;
  lunz2=false;
  marz2=false;
  mierz2=false;
  juevz2=false;
  vierz2=false;
  sabz2=false;
  domz2=false;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" HORA DE INICIO");
  while(salirz2==false){
    lcd.setCursor(4,1);
    lcd.print("HH: ");
    if(horaIniZ2<10){
      lcd.print("0");
      lcd.print(horaIniZ2);
    }else{
    lcd.print(horaIniZ2);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(horaIniZ2>0){
      horaIniZ2--;
      }
    }
    if (key == 'A'){
      if(horaIniZ2<24){
        horaIniZ2++;
      }
    }
    if(key=='1'){
      if(contz2==0){
      horaIniZ2=10;
      contz2=1;
      }
      else if(contz2==1 or contz2==2){
        horaIniZ2++;
        contz2=0;
        }
      }
    if (key=='2'){
      if(contz2==0){
      horaIniZ2=20;
      contz2=2;
      }else if(contz2==2 or contz2==1){
      horaIniZ2+=2;
      contz2=0;
      }
      }
    if(key=='3' && (contz2==1 or contz2==2)){
      horaIniZ2+=3;
      contz2=0;
      }
    if(key=='4' && (contz2==1 or contz2==2)){
      horaIniZ2+=4;
      contz2=0;
      }
    if(key=='5' && contz2==1){
      horaIniZ2+=5;
      contz2=0;
      }
    if(key=='6' && contz2==1){
      horaIniZ2+=6;
      contz2=0;
      }
    if(key=='7' && contz2==1){
      horaIniZ2+=7;
      contz2=0;
      }
    if(key=='8' && contz2==1){
      horaIniZ2+=8;
      contz2=0;
      }
    if(key=='9' && contz2==1){
      horaIniZ2+=9;
      contz2=0;
      }
    if (key== 'D'){
      salirz2=true;
      contz2=0;
      }
    }
  while(salirz2==true){
    lcd.setCursor(4, 1);
    lcd.print("MM: ");
    if(minutIniZ2<10){
      lcd.print("0");
      lcd.print(minutIniZ2);
    }else{
    lcd.print(minutIniZ2);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(minutIniZ2>0){
      minutIniZ2--;
      }
    }
    if (key == 'A'){
      if(minutIniZ2<59){
        minutIniZ2++;
      }
    }
    if(key=='1'){
      if(contz2==0){
      minutIniZ2=10;
      contz2=1;
      }
      else{
        minutIniZ2+=1;;
        contz2=0;
        }
      }
    if (key=='2'){
      if(contz2==0){
      minutIniZ2=20;
      contz2=2;
      }else{
      minutIniZ2+=2;
      contz2=0;
      }
      }
    if (key=='3'){
      if(contz2==0){
      minutIniZ2=30;
      contz2=3;
      }else{
      minutIniZ2+=3;
      contz2=0;
      }
      }
    if (key=='4'){
      if(contz2==0){
      minutIniZ2=40;
      contz2=4;
      }else{
      minutIniZ2+=4;
      contz2=0;
      }
      }
    if (key=='5'){
      if(contz2==0){
      minutIniZ2=50;
      contz2=5;
      }else{
      minutIniZ2+=5;
      contz2=0;
      }
      }
    if(key=='6' && contz2 != 0){
      minutIniZ2+=6;
      contz2=0;
      }
    if(key=='7' && contz2 != 0){
      minutIniZ2+=7;
      contz2=0;
      }
    if(key=='8' && contz2 != 0){
      minutIniZ2+=8;
      contz2=0;
      }
    if(key=='9' && contz2 != 0){
      minutIniZ2+=9;
      contz2=0;
      }
    
    if (key== 'D'){
      salirz2=false;
      contz2=0;
      }
    }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" HORA FINAL");
  while(salirz2==false){
    lcd.setCursor(4,1);
    lcd.print("HH: ");
    if(horaFinZ2<10){
      lcd.print("0");
      lcd.print(horaFinZ2);
    }else{
    lcd.print(horaFinZ2);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(horaFinZ2>0){
      horaFinZ2--;
      }
    }
    if (key == 'A'){
      if(horaFinZ2<24){
        horaFinZ2++;
      }
    }
    if(key=='1'){
      if(contz2==0){
      horaFinZ2=10;
      contz2=1;
      }
      else if(contz2==1 or contz2==2){
        horaFinZ2++;
        contz2=0;
        }
      }
    if (key=='2'){
      if(contz2==0){
      horaFinZ2=20;
      contz2=2;
      }else if(contz2==2 or contz2==1){
      horaFinZ2+=2;
      contz2=0;
      }
      }
    if(key=='3' && (contz2==1 or contz2==2)){
      horaFinZ2+=3;
      contz2=0;
      }
    if(key=='4' && (contz2==1 or contz2==2)){
      horaFinZ2+=4;
      contz2=0;
      }
    if(key=='5' && contz2==1){
      horaFinZ2+=5;
      contz2=0;
      }
    if(key=='6' && contz2==1){
      horaFinZ2+=6;
      contz2=0;
      }
    if(key=='7' && contz2==1){
      horaFinZ2+=7;
      contz2=0;
      }
    if(key=='8' && contz2==1){
      horaFinZ2+=8;
      contz2=0;
      }
    if(key=='9' && contz2==1){
      horaFinZ2+=9;
      contz2=0;
      }
    if (key== 'D'){
      salirz2=true;
      contz2=0;
      }
    }
  while(salirz2==true){
    lcd.setCursor(4, 1);
    lcd.print("MM: ");
    if(minutFinZ2<10){
      lcd.print("0");
      lcd.print(minutFinZ2);
    }else{
    lcd.print(minutFinZ2);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(minutFinZ2>0){
      minutFinZ2--;
      }
    }
    if (key == 'A'){
      if(minutFinZ2<59){
        minutFinZ2++;
      }
    }
    if(key=='1'){
      if(contz2==0){
      minutFinZ2=10;
      contz2=1;
      }
      else{
        minutFinZ2+=1;;
        contz2=0;
        }
      }
    if (key=='2'){
      if(contz2==0){
      minutFinZ2=20;
      contz2=2;
      }else{
      minutFinZ2+=2;
      contz2=0;
      }
      }
    if (key=='3'){
      if(contz2==0){
      minutFinZ2=30;
      contz2=3;
      }else{
      minutFinZ2+=3;
      contz2=0;
      }
      }
    if (key=='4'){
      if(contz2==0){
      minutFinZ2=40;
      contz2=4;
      }else{
      minutFinZ2+=4;
      contz2=0;
      }
      }
    if (key=='5'){
      if(contz2==0){
      minutFinZ2=50;
      contz2=5;
      }else{
      minutFinZ2+=5;
      contz2=0;
      }
      }
    if(key=='6' && contz2 != 0){
      minutFinZ2+=6;
      contz2=0;
      }
    if(key=='7' && contz2 != 0){
      minutFinZ2+=7;
      contz2=0;
      }
    if(key=='8' && contz2 != 0){
      minutFinZ2+=8;
      contz2=0;
      }
    if(key=='9' && contz2 != 0){
      minutFinZ2+=9;
      contz2=0;
      }
    if (key== 'D'){
      salirz2=false;
      contz2=0;
      }
    }
  
    lcd.setCursor(0,0);
    lcd.print("   DIAS SEMANA   ");
    lcd.setCursor(0, 1);
    lcd.print("   Lunes: NO   ");
    while(salirz2==false){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Lunes: NO   ");
      lunz2=false;
    }
    if (key == 'A'){
      lcd.print("   Lunes: SI   ");
      lunz2=true;
    }
    if (key == 'D'){
      salirz2=true;
      }
   }
   lcd.setCursor(0, 1);
   lcd.print("   Martes: NO   ");
   while(salirz2==true){
   lcd.setCursor(0, 1);
   key=teclado.getKey();
    if (key == 'B'){
      lcd.print("   Martes: NO   ");
      marz2=false;
    }
    if (key == 'A'){
      lcd.print("   Martes: SI   ");
      marz2=true;
    }
    if (key == 'D'){
      salirz2=false;
      }
   }
  
    lcd.setCursor(0, 1);
    lcd.print(" Miercoles: NO  ");
    while(salirz2==false){
    lcd.setCursor(0, 1);
    key=teclado.getKey();
    if (key == 'B'){
      lcd.print(" Miercoles: NO  ");
      mierz2=false;
    }
    if (key == 'A'){
      lcd.print(" Miercoles: SI  ");
      mierz2=true;
    }
    if (key == 'D'){
      salirz2=true;
      }
   }
  
   lcd.setCursor(0, 1);
   lcd.print("   Jueves: NO   ");
   while(salirz2==true){
   key=teclado.getKey();
   lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Jueves: NO   ");
      juevz2=false;
    }
    if (key == 'A'){
      lcd.print("   Jueves: SI   ");
      juevz2=true;
    }
    if (key == 'D'){
      salirz2=false;
      }
   }
  
    lcd.setCursor(0, 1);
    lcd.print("   Viernes: NO  ");
    while(salirz2==false){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Viernes: NO  ");
      vierz2=false;
    }
    if (key == 'A'){
      lcd.print("   Viernes: SI  ");
      vierz2=true;
    }
    if (key == 'D'){
      salirz2=true;
      }
   }
 
    lcd.setCursor(0, 1);
    lcd.print("   Sabado: NO   ");
    while(salirz2==true){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Sabado: NO   ");
      sabz2=false;
    }
    if (key == 'A'){
      lcd.print("   Sabado: SI   ");
      sabz2=true;
    }
    if (key == 'D'){
      salirz2=false;
      }
   }
    lcd.setCursor(0, 1);
    lcd.print("  Domingo: NO   ");
    while(salirz2==false){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("  Domingo: NO   ");
      domz2=false;
    }
    if (key == 'A'){
      lcd.print("  Domingo: SI   ");
      domz2=true;
    }
    if (key == 'D'){
      salirz2=true;
      }
   }
  lcd.clear();
  }

                                                              //PROGRAMAR ZONA 3
 void programarZ3(){
  boolean salirz3 = false;
  byte contz3=0;
  horaIniZ3=0;
  minutIniZ3=0;
  horaFinZ3=0;
  minutFinZ3=0;
  lunz3=false;
  marz3=false;
  mierz3=false;
  juevz3=false;
  vierz3=false;
  sabz3=false;
  domz3=false;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" HORA DE INICIO");
  while(salirz3==false){
    lcd.setCursor(4,1);
    lcd.print("HH: ");
    if(horaIniZ3<10){
      lcd.print("0");
      lcd.print(horaIniZ3);
    }else{
    lcd.print(horaIniZ3);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(horaIniZ3>0){
      horaIniZ3--;
      }
    }
    if (key == 'A'){
      if(horaIniZ3<24){
        horaIniZ3++;
      }
    }
    if(key=='1'){
      if(contz3==0){
      horaIniZ3=10;
      contz3=1;
      }
      else if(contz3==1 or contz3==2){
        horaIniZ3++;
        contz3=0;
        }
      }
    if (key=='2'){
      if(contz3==0){
      horaIniZ3=20;
      contz3=2;
      }else if(contz3==2 or contz3==1){
      horaIniZ3+=2;
      contz3=0;
      }
      }
    if(key=='3' && (contz3==1 or contz3==2)){
      horaIniZ3+=3;
      contz3=0;
      }
    if(key=='4' && (contz3==1 or contz3==2)){
      horaIniZ3+=4;
      contz3=0;
      }
    if(key=='5' && contz3==1){
      horaIniZ3+=5;
      contz3=0;
      }
    if(key=='6' && contz3==1){
      horaIniZ3+=6;
      contz3=0;
      }
    if(key=='7' && contz3==1){
      horaIniZ3+=7;
      contz3=0;
      }
    if(key=='8' && contz3==1){
      horaIniZ3+=8;
      contz3=0;
      }
    if(key=='9' && contz3==1){
      horaIniZ3+=9;
      contz3=0;
      }
    if (key== 'D'){
      salirz3=true;
      contz3=0;
      }
    }
  while(salirz3==true){
    lcd.setCursor(4, 1);
    lcd.print("MM: ");
    if(minutIniZ3<10){
      lcd.print("0");
      lcd.print(minutIniZ3);
    }else{
    lcd.print(minutIniZ3);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(minutIniZ3>0){
      minutIniZ3--;
      }
    }
    if (key == 'A'){
      if(minutIniZ3<59){
        minutIniZ3++;
      }
    }
    if(key=='1'){
      if(contz3==0){
      minutIniZ3=10;
      contz3=1;
      }
      else{
        minutIniZ3+=1;;
        contz3=0;
        }
      }
    if (key=='2'){
      if(contz3==0){
      minutIniZ3=20;
      contz3=2;
      }else{
      minutIniZ3+=2;
      contz3=0;
      }
      }
    if (key=='3'){
      if(contz3==0){
      minutIniZ3=30;
      contz3=3;
      }else{
      minutIniZ3+=3;
      contz3=0;
      }
      }
    if (key=='4'){
      if(contz3==0){
      minutIniZ3=40;
      contz3=4;
      }else{
      minutIniZ3+=4;
      contz3=0;
      }
      }
    if (key=='5'){
      if(contz3==0){
      minutIniZ3=50;
      contz3=5;
      }else{
      minutIniZ3+=5;
      contz3=0;
      }
      }
    if(key=='6' && contz3 != 0){
      minutIniZ3+=6;
      contz3=0;
      }
    if(key=='7' && contz3 != 0){
      minutIniZ3+=7;
      contz3=0;
      }
    if(key=='8' && contz3 != 0){
      minutIniZ3+=8;
      contz3=0;
      }
    if(key=='9' && contz3 != 0){
      minutIniZ3+=9;
      contz3=0;
      }
    
    if (key== 'D'){
      salirz3=false;
      contz3=0;
      }
    }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" HORA FINAL");
  while(salirz3==false){
    lcd.setCursor(4,1);
    lcd.print("HH: ");
    if(horaFinZ3<10){
      lcd.print("0");
      lcd.print(horaFinZ3);
    }else{
    lcd.print(horaFinZ3);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(horaFinZ3>0){
      horaFinZ3--;
      }
    }
    if (key == 'A'){
      if(horaFinZ3<24){
        horaFinZ3++;
      }
    }
    if(key=='1'){
      if(contz3==0){
      horaFinZ3=10;
      contz3=1;
      }
      else if(contz3==1 or contz3==2){
        horaFinZ3++;
        contz3=0;
        }
      }
    if (key=='2'){
      if(contz3==0){
      horaFinZ3=20;
      contz3=2;
      }else if(contz3==2 or contz3==1){
      horaFinZ3+=2;
      contz3=0;
      }
      }
    if(key=='3' && (contz3==1 or contz3==2)){
      horaFinZ3+=3;
      contz3=0;
      }
    if(key=='4' && (contz3==1 or contz3==2)){
      horaFinZ3+=4;
      contz3=0;
      }
    if(key=='5' && contz3==1){
      horaFinZ3+=5;
      contz3=0;
      }
    if(key=='6' && contz3==1){
      horaFinZ3+=6;
      contz3=0;
      }
    if(key=='7' && contz3==1){
      horaFinZ3+=7;
      contz3=0;
      }
    if(key=='8' && contz3==1){
      horaFinZ3+=8;
      contz3=0;
      }
    if(key=='9' && contz3==1){
      horaFinZ3+=9;
      contz3=0;
      }
    if (key== 'D'){
      salirz3=true;
      contz3=0;
      }
    }
  while(salirz3==true){
    lcd.setCursor(4, 1);
    lcd.print("MM: ");
    if(minutFinZ3<10){
      lcd.print("0");
      lcd.print(minutFinZ3);
    }else{
    lcd.print(minutFinZ3);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(minutFinZ3>0){
      minutFinZ3--;
      }
    }
    if (key == 'A'){
      if(minutFinZ3<59){
        minutFinZ3++;
      }
    }
    if(key=='1'){
      if(contz3==0){
      minutFinZ3=10;
      contz3=1;
      }
      else{
        minutFinZ3+=1;;
        contz3=0;
        }
      }
    if (key=='2'){
      if(contz3==0){
      minutFinZ3=20;
      contz3=2;
      }else{
      minutFinZ3+=2;
      contz3=0;
      }
      }
    if (key=='3'){
      if(contz3==0){
      minutFinZ3=30;
      contz3=3;
      }else{
      minutFinZ3+=3;
      contz3=0;
      }
      }
    if (key=='4'){
      if(contz3==0){
      minutFinZ3=40;
      contz3=4;
      }else{
      minutFinZ3+=4;
      contz3=0;
      }
      }
    if (key=='5'){
      if(contz3==0){
      minutFinZ3=50;
      contz3=5;
      }else{
      minutFinZ3+=5;
      contz3=0;
      }
      }
    if(key=='6' && contz3 != 0){
      minutFinZ3+=6;
      contz3=0;
      }
    if(key=='7' && contz3 != 0){
      minutFinZ3+=7;
      contz3=0;
      }
    if(key=='8' && contz3 != 0){
      minutFinZ3+=8;
      contz3=0;
      }
    if(key=='9' && contz3 != 0){
      minutFinZ3+=9;
      contz3=0;
      }
    if (key== 'D'){
      salirz3=false;
      contz3=0;
      }
    }
  
    lcd.setCursor(0,0);
    lcd.print("   DIAS SEMANA   ");
    lcd.setCursor(0, 1);
    lcd.print("   Lunes: NO   ");
    while(salirz3==false){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Lunes: NO   ");
      lunz3=false;
    }
    if (key == 'A'){
      lcd.print("   Lunes: SI   ");
      lunz3=true;
    }
    if (key == 'D'){
      salirz3=true;
      }
   }
   lcd.setCursor(0, 1);
   lcd.print("   Martes: NO   ");
   while(salirz3==true){
   lcd.setCursor(0, 1);
   key=teclado.getKey();
    if (key == 'B'){
      lcd.print("   Martes: NO   ");
      marz3=false;
    }
    if (key == 'A'){
      lcd.print("   Martes: SI   ");
      marz3=true;
    }
    if (key == 'D'){
      salirz3=false;
      }
   }
  
    lcd.setCursor(0, 1);
    lcd.print(" Miercoles: NO  ");
    while(salirz3==false){
    lcd.setCursor(0, 1);
    key=teclado.getKey();
    if (key == 'B'){
      lcd.print(" Miercoles: NO  ");
      mierz3=false;
    }
    if (key == 'A'){
      lcd.print(" Miercoles: SI  ");
      mierz3=true;
    }
    if (key == 'D'){
      salirz3=true;
      }
   }
  
   lcd.setCursor(0, 1);
   lcd.print("   Jueves: NO   ");
   while(salirz3==true){
   key=teclado.getKey();
   lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Jueves: NO   ");
      juevz3=false;
    }
    if (key == 'A'){
      lcd.print("   Jueves: SI   ");
      juevz3=true;
    }
    if (key == 'D'){
      salirz3=false;
      }
   }
  
    lcd.setCursor(0, 1);
    lcd.print("   Viernes: NO  ");
    while(salirz3==false){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Viernes: NO  ");
      vierz3=false;
    }
    if (key == 'A'){
      lcd.print("   Viernes: SI  ");
      vierz3=true;
    }
    if (key == 'D'){
      salirz3=true;
      }
   }
 
    lcd.setCursor(0, 1);
    lcd.print("   Sabado: NO   ");
    while(salirz3==true){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Sabado: NO   ");
      sabz3=false;
    }
    if (key == 'A'){
      lcd.print("   Sabado: SI   ");
      sabz3=true;
    }
    if (key == 'D'){
      salirz3=false;
      }
   }
  
    lcd.setCursor(0, 1);
    lcd.print("  Domingo: NO   ");
    while(salirz3==false){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("  Domingo: NO   ");
      domz3=false;
    }
    if (key == 'A'){
      lcd.print("  Domingo: SI   ");
      domz3=true;
    }
    if (key == 'D'){
      salirz3=true;
      }
   }
  lcd.clear();
  }
    
                                                                    //PROGRAMAR ZONA 4
 void programarZ4(){
  boolean salirz4 = false;
  byte contz4=0;
  horaIniZ4=0;
  minutIniZ4=0;
  horaFinZ4=0;
  minutFinZ4=0;
  lunz4=false;
  marz4=false;
  mierz4=false;
  juevz4=false;
  vierz4=false;
  sabz4=false;
  domz4=false;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" HORA DE INICIO");
  while(salirz4==false){
    lcd.setCursor(4,1);
    lcd.print("HH: ");
    if(horaIniZ4<10){
      lcd.print("0");
      lcd.print(horaIniZ4);
    }else{
    lcd.print(horaIniZ4);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(horaIniZ4>0){
      horaIniZ4--;
      }
    }
    if (key == 'A'){
      if(horaIniZ4<24){
        horaIniZ4++;
      }
    }
    if(key=='1'){
      if(contz4==0){
      horaIniZ4=10;
      contz4=1;
      }
      else if(contz4==1 or contz4==2){
        horaIniZ4++;
        contz4=0;
        }
      }
    if (key=='2'){
      if(contz4==0){
      horaIniZ4=20;
      contz4=2;
      }else if(contz4==2 or contz4==1){
      horaIniZ4+=2;
      contz4=0;
      }
      }
    if(key=='3' && (contz4==1 or contz4==2)){
      horaIniZ4+=3;
      contz4=0;
      }
    if(key=='4' && (contz4==1 or contz4==2)){
      horaIniZ4+=4;
      contz4=0;
      }
    if(key=='5' && contz4==1){
      horaIniZ4+=5;
      contz4=0;
      }
    if(key=='6' && contz4==1){
      horaIniZ4+=6;
      contz4=0;
      }
    if(key=='7' && contz4==1){
      horaIniZ4+=7;
      contz4=0;
      }
    if(key=='8' && contz4==1){
      horaIniZ4+=8;
      contz4=0;
      }
    if(key=='9' && contz4==1){
      horaIniZ4+=9;
      contz4=0;
      }
    if (key== 'D'){
      salirz4=true;
      contz4=0;
      }
    }
  while(salirz4==true){
    lcd.setCursor(4, 1);
    lcd.print("MM: ");
    if(minutIniZ4<10){
      lcd.print("0");
      lcd.print(minutIniZ4);
    }else{
    lcd.print(minutIniZ4);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(minutIniZ4>0){
      minutIniZ4--;
      }
    }
    if (key == 'A'){
      if(minutIniZ4<59){
        minutIniZ4++;
      }
    }
    if(key=='1'){
      if(contz4==0){
      minutIniZ4=10;
      contz4=1;
      }
      else{
        minutIniZ4+=1;;
        contz4=0;
        }
      }
    if (key=='2'){
      if(contz4==0){
      minutIniZ4=20;
      contz4=2;
      }else{
      minutIniZ4+=2;
      contz4=0;
      }
      }
    if (key=='3'){
      if(contz4==0){
      minutIniZ4=30;
      contz4=3;
      }else{
      minutIniZ4+=3;
      contz4=0;
      }
      }
    if (key=='4'){
      if(contz4==0){
      minutIniZ4=40;
      contz4=4;
      }else{
      minutIniZ4+=4;
      contz4=0;
      }
      }
    if (key=='5'){
      if(contz4==0){
      minutIniZ4=50;
      contz4=5;
      }else{
      minutIniZ4+=5;
      contz4=0;
      }
      }
    if(key=='6' && contz4 != 0){
      minutIniZ4+=6;
      contz4=0;
      }
    if(key=='7' && contz4 != 0){
      minutIniZ4+=7;
      contz4=0;
      }
    if(key=='8' && contz4 != 0){
      minutIniZ4+=8;
      contz4=0;
      }
    if(key=='9' && contz4 != 0){
      minutIniZ4+=9;
      contz4=0;
      }
    
    if (key== 'D'){
      salirz4=false;
      contz4=0;
      }
    }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" HORA FINAL");
  while(salirz4==false){
    lcd.setCursor(4,1);
    lcd.print("HH: ");
    if(horaFinZ4<10){
      lcd.print("0");
      lcd.print(horaFinZ4);
    }else{
    lcd.print(horaFinZ4);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(horaFinZ4>0){
      horaFinZ4--;
      }
    }
    if (key == 'A'){
      if(horaFinZ4<24){
        horaFinZ4++;
      }
    }
    if(key=='1'){
      if(contz4==0){
      horaFinZ4=10;
      contz4=1;
      }
      else if(contz4==1 or contz4==2){
        horaFinZ4++;
        contz4=0;
        }
      }
    if (key=='2'){
      if(contz4==0){
      horaFinZ4=20;
      contz4=2;
      }else if(contz4==2 or contz4==1){
      horaFinZ4+=2;
      contz4=0;
      }
      }
    if(key=='3' && (contz4==1 or contz4==2)){
      horaFinZ4+=3;
      contz4=0;
      }
    if(key=='4' && (contz4==1 or contz4==2)){
      horaFinZ4+=4;
      contz4=0;
      }
    if(key=='5' && contz4==1){
      horaFinZ4+=5;
      contz4=0;
      }
    if(key=='6' && contz4==1){
      horaFinZ4+=6;
      contz4=0;
      }
    if(key=='7' && contz4==1){
      horaFinZ4+=7;
      contz4=0;
      }
    if(key=='8' && contz4==1){
      horaFinZ4+=8;
      contz4=0;
      }
    if(key=='9' && contz4==1){
      horaFinZ4+=9;
      contz4=0;
      }
    if (key== 'D'){
      salirz4=true;
      contz4=0;
      }
    }
  while(salirz4==true){
    lcd.setCursor(4, 1);
    lcd.print("MM: ");
    if(minutFinZ4<10){
      lcd.print("0");
      lcd.print(minutFinZ4);
    }else{
    lcd.print(minutFinZ4);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(minutFinZ4>0){
      minutFinZ4--;
      }
    }
    if (key == 'A'){
      if(minutFinZ4<59){
        minutFinZ4++;
      }
    }
    if(key=='1'){
      if(contz4==0){
      minutFinZ4=10;
      contz4=1;
      }
      else{
        minutFinZ4+=1;;
        contz4=0;
        }
      }
    if (key=='2'){
      if(contz4==0){
      minutFinZ4=20;
      contz4=2;
      }else{
      minutFinZ4+=2;
      contz4=0;
      }
      }
    if (key=='3'){
      if(contz4==0){
      minutFinZ4=30;
      contz4=3;
      }else{
      minutFinZ4+=3;
      contz4=0;
      }
      }
    if (key=='4'){
      if(contz4==0){
      minutFinZ4=40;
      contz4=4;
      }else{
      minutFinZ4+=4;
      contz4=0;
      }
      }
    if (key=='5'){
      if(contz4==0){
      minutFinZ4=50;
      contz4=5;
      }else{
      minutFinZ4+=5;
      contz4=0;
      }
      }
    if(key=='6' && contz4 != 0){
      minutFinZ4+=6;
      contz4=0;
      }
    if(key=='7' && contz4 != 0){
      minutFinZ4+=7;
      contz4=0;
      }
    if(key=='8' && contz4 != 0){
      minutFinZ4+=8;
      contz4=0;
      }
    if(key=='9' && contz4 != 0){
      minutFinZ4+=9;
      contz4=0;
      }
    if (key== 'D'){
      salirz4=false;
      contz4=0;
      }
    }
  
    lcd.setCursor(0,0);
    lcd.print("   DIAS SEMANA   ");
    lcd.setCursor(0, 1);
    lcd.print("   Lunes: NO   ");
    while(salirz4==false){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Lunes: NO   ");
      lunz4=false;
    }
    if (key == 'A'){
      lcd.print("   Lunes: SI   ");
      lunz4=true;
    }
    if (key == 'D'){
      salirz4=true;
      }
   }
   lcd.setCursor(0, 1);
   lcd.print("   Martes: NO   ");
   while(salirz4==true){
   lcd.setCursor(0, 1);
   key=teclado.getKey();
    if (key == 'B'){
      lcd.print("   Martes: NO   ");
      marz4=false;
    }
    if (key == 'A'){
      lcd.print("   Martes: SI   ");
      marz4=true;
    }
    if (key == 'D'){
      salirz4=false;
      }
   }
  
    lcd.setCursor(0, 1);
    lcd.print(" Miercoles: NO  ");
    while(salirz4==false){
    lcd.setCursor(0, 1);
    key=teclado.getKey();
    if (key == 'B'){
      lcd.print(" Miercoles: NO  ");
      mierz4=false;
    }
    if (key == 'A'){
      lcd.print(" Miercoles: SI  ");
      mierz4=true;
    }
    if (key == 'D'){
      salirz4=true;
      }
   }
  
   lcd.setCursor(0, 1);
   lcd.print("   Jueves: NO   ");
   while(salirz4==true){
   key=teclado.getKey();
   lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Jueves: NO   ");
      juevz4=false;
    }
    if (key == 'A'){
      lcd.print("   Jueves: SI   ");
      juevz4=true;
    }
    if (key == 'D'){
      salirz4=false;
      }
   }
  
    lcd.setCursor(0, 1);
    lcd.print("   Viernes: NO  ");
    while(salirz4==false){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Viernes: NO  ");
      vierz4=false;
    }
    if (key == 'A'){
      lcd.print("   Viernes: SI  ");
      vierz4=true;
    }
    if (key == 'D'){
      salirz4=true;
      }
   }
 
    lcd.setCursor(0, 1);
    lcd.print("   Sabado: NO   ");
    while(salirz4==true){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Sabado: NO   ");
      sabz4=false;
    }
    if (key == 'A'){
      lcd.print("   Sabado: SI   ");
      sabz4=true;
    }
    if (key == 'D'){
      salirz4=false;
      }
   }
  
    lcd.setCursor(0, 1);
    lcd.print("  Domingo: NO   ");
    while(salirz4==false){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("  Domingo: NO   ");
      domz4=false;
    }
    if (key == 'A'){
      lcd.print("  Domingo: SI   ");
      domz4=true;
    }
    if (key == 'D'){
      salirz4=true;
      }
   }
  lcd.clear();
  }

                                                                     //PROGRAMAR ZONA 5
 void programarZ5(){
  boolean salirz5 = false;
  byte contz5=0;
  horaIniZ5=0;
  minutIniZ5=0;
  horaFinZ5=0;
  minutFinZ5=0;
  lunz5=false;
  marz5=false;
  mierz5=false;
  juevz5=false;
  vierz5=false;
  sabz5=false;
  domz5=false;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" HORA DE INICIO");
  while(salirz5==false){
    lcd.setCursor(4,1);
    lcd.print("HH: ");
    if(horaIniZ5<10){
      lcd.print("0");
      lcd.print(horaIniZ5);
    }else{
    lcd.print(horaIniZ5);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(horaIniZ5>0){
      horaIniZ5--;
      }
    }
    if (key == 'A'){
      if(horaIniZ5<24){
        horaIniZ5++;
      }
    }
    if(key=='1'){
      if(contz5==0){
      horaIniZ5=10;
      contz5=1;
      }
      else if(contz5==1 or contz5==2){
        horaIniZ5++;
        contz5=0;
        }
      }
    if (key=='2'){
      if(contz5==0){
      horaIniZ5=20;
      contz5=2;
      }else if(contz5==2 or contz5==1){
      horaIniZ5+=2;
      contz5=0;
      }
      }
    if(key=='3' && (contz5==1 or contz5==2)){
      horaIniZ5+=3;
      contz5=0;
      }
    if(key=='4' && (contz5==1 or contz5==2)){
      horaIniZ5+=4;
      contz5=0;
      }
    if(key=='5' && contz5==1){
      horaIniZ5+=5;
      contz5=0;
      }
    if(key=='6' && contz5==1){
      horaIniZ5+=6;
      contz5=0;
      }
    if(key=='7' && contz5==1){
      horaIniZ5+=7;
      contz5=0;
      }
    if(key=='8' && contz5==1){
      horaIniZ5+=8;
      contz5=0;
      }
    if(key=='9' && contz5==1){
      horaIniZ5+=9;
      contz5=0;
      }
    if (key== 'D'){
      salirz5=true;
      contz5=0;
      }
    }
  while(salirz5==true){
    lcd.setCursor(4, 1);
    lcd.print("MM: ");
    if(minutIniZ5<10){
      lcd.print("0");
      lcd.print(minutIniZ5);
    }else{
    lcd.print(minutIniZ5);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(minutIniZ5>0){
      minutIniZ5--;
      }
    }
    if (key == 'A'){
      if(minutIniZ5<59){
        minutIniZ5++;
      }
    }
    if(key=='1'){
      if(contz5==0){
      minutIniZ5=10;
      contz5=1;
      }
      else{
        minutIniZ5+=1;;
        contz5=0;
        }
      }
    if (key=='2'){
      if(contz5==0){
      minutIniZ5=20;
      contz5=2;
      }else{
      minutIniZ5+=2;
      contz5=0;
      }
      }
    if (key=='3'){
      if(contz5==0){
      minutIniZ5=30;
      contz5=3;
      }else{
      minutIniZ5+=3;
      contz5=0;
      }
      }
    if (key=='4'){
      if(contz5==0){
      minutIniZ5=40;
      contz5=4;
      }else{
      minutIniZ5+=4;
      contz5=0;
      }
      }
    if (key=='5'){
      if(contz5==0){
      minutIniZ5=50;
      contz5=5;
      }else{
      minutIniZ5+=5;
      contz5=0;
      }
      }
    if(key=='6' && contz5 != 0){
      minutIniZ5+=6;
      contz5=0;
      }
    if(key=='7' && contz5 != 0){
      minutIniZ5+=7;
      contz5=0;
      }
    if(key=='8' && contz5 != 0){
      minutIniZ5+=8;
      contz5=0;
      }
    if(key=='9' && contz5 != 0){
      minutIniZ5+=9;
      contz5=0;
      }
    
    if (key== 'D'){
      salirz5=false;
      contz5=0;
      }
    }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" HORA FINAL");
  while(salirz5==false){
    lcd.setCursor(4,1);
    lcd.print("HH: ");
    if(horaFinZ5<10){
      lcd.print("0");
      lcd.print(horaFinZ5);
    }else{
    lcd.print(horaFinZ5);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(horaFinZ5>0){
      horaFinZ5--;
      }
    }
    if (key == 'A'){
      if(horaFinZ5<24){
        horaFinZ5++;
      }
    }
    if(key=='1'){
      if(contz5==0){
      horaFinZ5=10;
      contz5=1;
      }
      else if(contz5==1 or contz5==2){
        horaFinZ5++;
        contz5=0;
        }
      }
    if (key=='2'){
      if(contz5==0){
      horaFinZ5=20;
      contz5=2;
      }else if(contz5==2 or contz5==1){
      horaFinZ5+=2;
      contz5=0;
      }
      }
    if(key=='3' && (contz5==1 or contz5==2)){
      horaFinZ5+=3;
      contz5=0;
      }
    if(key=='4' && (contz5==1 or contz5==2)){
      horaFinZ5+=4;
      contz5=0;
      }
    if(key=='5' && contz5==1){
      horaFinZ5+=5;
      contz5=0;
      }
    if(key=='6' && contz5==1){
      horaFinZ5+=6;
      contz5=0;
      }
    if(key=='7' && contz5==1){
      horaFinZ5+=7;
      contz5=0;
      }
    if(key=='8' && contz5==1){
      horaFinZ5+=8;
      contz5=0;
      }
    if(key=='9' && contz5==1){
      horaFinZ5+=9;
      contz5=0;
      }
    if (key== 'D'){
      salirz5=true;
      contz5=0;
      }
    }
  while(salirz5==true){
    lcd.setCursor(4, 1);
    lcd.print("MM: ");
    if(minutFinZ5<10){
      lcd.print("0");
      lcd.print(minutFinZ5);
    }else{
    lcd.print(minutFinZ5);  
    }
    key=teclado.getKey();
    if (key == 'B'){
     if(minutFinZ5>0){
      minutFinZ5--;
      }
    }
    if (key == 'A'){
      if(minutFinZ5<59){
        minutFinZ5++;
      }
    }
    if(key=='1'){
      if(contz5==0){
      minutFinZ5=10;
      contz5=1;
      }
      else{
        minutFinZ5+=1;;
        contz5=0;
        }
      }
    if (key=='2'){
      if(contz5==0){
      minutFinZ5=20;
      contz5=2;
      }else{
      minutFinZ5+=2;
      contz5=0;
      }
      }
    if (key=='3'){
      if(contz5==0){
      minutFinZ5=30;
      contz5=3;
      }else{
      minutFinZ5+=3;
      contz5=0;
      }
      }
    if (key=='4'){
      if(contz5==0){
      minutFinZ5=40;
      contz5=4;
      }else{
      minutFinZ5+=4;
      contz5=0;
      }
      }
    if (key=='5'){
      if(contz5==0){
      minutFinZ5=50;
      contz5=5;
      }else{
      minutFinZ5+=5;
      contz5=0;
      }
      }
    if(key=='6' && contz5 != 0){
      minutFinZ5+=6;
      contz5=0;
      }
    if(key=='7' && contz5 != 0){
      minutFinZ5+=7;
      contz5=0;
      }
    if(key=='8' && contz5 != 0){
      minutFinZ5+=8;
      contz5=0;
      }
    if(key=='9' && contz5 != 0){
      minutFinZ5+=9;
      contz5=0;
      }
    if (key== 'D'){
      salirz5=false;
      contz5=0;
      }
    }
  
    lcd.setCursor(0,0);
    lcd.print("   DIAS SEMANA   ");
    lcd.setCursor(0, 1);
    lcd.print("   Lunes: NO   ");
    while(salirz5==false){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Lunes: NO   ");
      lunz5=false;
    }
    if (key == 'A'){
      lcd.print("   Lunes: SI   ");
      lunz5=true;
    }
    if (key == 'D'){
      salirz5=true;
      }
   }
   lcd.setCursor(0, 1);
   lcd.print("   Martes: NO   ");
   while(salirz5==true){
   lcd.setCursor(0, 1);
   key=teclado.getKey();
    if (key == 'B'){
      lcd.print("   Martes: NO   ");
      marz5=false;
    }
    if (key == 'A'){
      lcd.print("   Martes: SI   ");
      marz5=true;
    }
    if (key == 'D'){
      salirz5=false;
      }
   }
  
    lcd.setCursor(0, 1);
    lcd.print(" Miercoles: NO  ");
    while(salirz5==false){
    lcd.setCursor(0, 1);
    key=teclado.getKey();
    if (key == 'B'){
      lcd.print(" Miercoles: NO  ");
      mierz5=false;
    }
    if (key == 'A'){
      lcd.print(" Miercoles: SI  ");
      mierz5=true;
    }
    if (key == 'D'){
      salirz5=true;
      }
   }
  
   lcd.setCursor(0, 1);
   lcd.print("   Jueves: NO   ");
   while(salirz5==true){
   key=teclado.getKey();
   lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Jueves: NO   ");
      juevz5=false;
    }
    if (key == 'A'){
      lcd.print("   Jueves: SI   ");
      juevz5=true;
    }
    if (key == 'D'){
      salirz5=false;
      }
   }
  
    lcd.setCursor(0, 1);
    lcd.print("   Viernes: NO  ");
    while(salirz5==false){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Viernes: NO  ");
      vierz5=false;
    }
    if (key == 'A'){
      lcd.print("   Viernes: SI  ");
      vierz5=true;
    }
    if (key == 'D'){
      salirz5=true;
      }
   }
 
    lcd.setCursor(0, 1);
    lcd.print("   Sabado: NO   ");
    while(salirz5==true){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("   Sabado: NO   ");
      sabz5=false;
    }
    if (key == 'A'){
      lcd.print("   Sabado: SI   ");
      sabz5=true;
    }
    if (key == 'D'){
      salirz5=false;
      }
   }
  
    lcd.setCursor(0, 1);
    lcd.print("  Domingo: NO   ");
    while(salirz5==false){
    key=teclado.getKey();
    lcd.setCursor(0, 1);
    if (key == 'B'){
      lcd.print("  Domingo: NO   ");
      domz5=false;
    }
    if (key == 'A'){
      lcd.print("  Domingo: SI   ");
      domz5=true;
    }
    if (key == 'D'){
      salirz5=true;
      }
   }
  lcd.clear();
  }

                                                                          //Programa Z1

 void programaz1(){
  if(hour()==horaIniZ1 && minutIniZ1==minute()){
        if(weekday()==2 && lunz1==true){
          digitalWrite(salida1,LOW);
          pinz1=true;
          }
        if(weekday()==3 && marz1==true){
          digitalWrite(salida1,LOW);
          pinz1=true;
        }
        if(weekday()==4 && mierz1==true){
          digitalWrite(salida1,LOW);
          pinz1=true;
          }
        if(weekday()==5 && juevz1==true){
          digitalWrite(salida1,LOW);
          pinz1=true;
        }
        if(weekday()==6 && vierz1==true){
          digitalWrite(salida1,LOW);
          pinz1=true;
          }
        if(weekday()==0 && sabz1==true){
          digitalWrite(salida1,LOW);
          pinz1=true;
        }
        if(weekday()==1 && domz1==true){
          digitalWrite(salida1,LOW);
          pinz1=true;
        }}
  if(hour()==horaFinZ1 && minutFinZ1==minute()){
      digitalWrite(salida1,HIGH);
      pinz1=false;
       }
  }

                                                                             //Programa Z2

 void programaz2(){
 if(hour()==horaIniZ2 && minutIniZ2==minute()){
        if(weekday()==2 && lunz2==true){
          digitalWrite(salida2,LOW);
          pinz2=true;
          }
        if(weekday()==3 && marz2==true){
          digitalWrite(salida2,LOW);
          pinz2=true;
        }
        if(weekday()==4 && mierz2==true){
          digitalWrite(salida2,LOW);
          pinz2=true;
          }
        if(weekday()==5 && juevz2==true){
          digitalWrite(salida2,LOW);
          pinz2=true;
        }
        if(weekday()==6 && vierz2==true){
          digitalWrite(salida2,LOW);
          pinz2=true;
          }
        if(weekday()==0 && sabz2==true){
          digitalWrite(salida2,LOW);
          pinz2=true;
        }
        if(weekday()==1 && domz2==true){
          digitalWrite(salida2,LOW);
          pinz2=true;
        }}
  if(hour()==horaFinZ2 && minutFinZ2==minute()){
      digitalWrite(salida2,HIGH);
      pinz2=false;
       }
  }

                                                                               //Programa Z3

 void programaz3(){
  if(hour()==horaIniZ3 && minutIniZ3==minute()){
        if(weekday()==2 && lunz3==true){
          digitalWrite(salida3,LOW);
          pinz3=true;
          }
        if(weekday()==3 && marz3==true){
          digitalWrite(salida3,LOW);
          pinz3=true;
        }
        if(weekday()==4 && mierz3==true){
          digitalWrite(salida3,LOW);
          pinz3=true;
          }
        if(weekday()==5 && juevz3==true){
          digitalWrite(salida3,LOW);
          pinz3=true;
        }
        if(weekday()==6 && vierz3==true){
          digitalWrite(salida3,LOW);
          pinz3=true;
          }
        if(weekday()==0 && sabz3==true){
          digitalWrite(salida3,LOW);
          pinz3=true;
        }
        if(weekday()==1 && domz3==true){
          digitalWrite(salida3,LOW);
          pinz3=true;
        }}
  if(hour()==horaFinZ3 && minutFinZ3==minute()){
      digitalWrite(salida3,HIGH);
      pinz3=false;
       }
  }

                                                                                 //Programa Z4

 void programaz4(){
  if(hour()==horaIniZ4 && minutIniZ4==minute()){
        if(weekday()==2 && lunz4==true){
          digitalWrite(salida4,LOW);
          pinz4=true;
          }
        if(weekday()==3 && marz4==true){
          digitalWrite(salida4,LOW);
          pinz4=true;
        }
        if(weekday()==4 && mierz4==true){
          digitalWrite(salida4,LOW);
          pinz4=true;
          }
        if(weekday()==5 && juevz4==true){
          digitalWrite(salida4,LOW);
          pinz4=true;
        }
        if(weekday()==6 && vierz4==true){
          digitalWrite(salida4,LOW);
          pinz4=true;
          }
        if(weekday()==0 && sabz4==true){
          digitalWrite(salida4,LOW);
          pinz4=true;
        }
        if(weekday()==1 && domz4==true){
          digitalWrite(salida4,LOW);
          pinz4=true;
        }}
  if(hour()==horaFinZ4 && minutFinZ4==minute()){
      digitalWrite(salida4,HIGH);
      pinz4=false;
       }
  }

                                                                                  //Programa Z5

 void programaz5(){
  if(hour()==horaIniZ5 && minutIniZ5==minute()){
        if(weekday()==2 && lunz5==true){
          digitalWrite(salida5,LOW);
          pinz5=true;
          }
        if(weekday()==3 && marz5==true){
          digitalWrite(salida5,LOW);
          pinz5=true;
        }
        if(weekday()==4 && mierz5==true){
          digitalWrite(salida5,LOW);
          pinz5=true;
          }
        if(weekday()==5 && juevz5==true){
          digitalWrite(salida5,LOW);
          pinz5=true;
        }
        if(weekday()==6 && vierz5==true){
          digitalWrite(salida5,LOW);
          pinz5=true;
          }
        if(weekday()==0 && sabz5==true){
          digitalWrite(salida5,LOW);
          pinz5=true;
        }
        if(weekday()==1 && domz5==true){
          digitalWrite(salida5,LOW);
          pinz5=true;
        }}
  if(hour()==horaFinZ5 && minutFinZ5==minute()){
      digitalWrite(salida5,HIGH);
      pinz5=false;
       }
  }
                                                                                  //Metodo Imprimir Estado Zonas
void imprimirEstado(){
  lcd.setCursor(0,1);
  lcd.print("REGANDO Z:");
  if(pinz1==true){
    lcd.setCursor(11,1);
    lcd.print("1");
    }else{lcd.setCursor(11,1);
    lcd.print(" ");}
  if(pinz2==true){
    lcd.setCursor(12,1);
    lcd.print("2");
    }else{lcd.setCursor(12,1);
    lcd.print(" ");}
  if(pinz3==true){
    lcd.setCursor(13,1);
    lcd.print("3");
    }else{lcd.setCursor(13,1);
    lcd.print(" ");}
  if(pinz4==true){
    lcd.setCursor(14,1);
    lcd.print("4");
    }else{lcd.setCursor(14,1);
    lcd.print(" ");}
  if(pinz5==true){
    lcd.setCursor(15,1);
    lcd.print("5");
    }else{lcd.setCursor(15,1);
    lcd.print(" ");}
  }
                                            //METODO MANUAL
void manual(){
    byte opcm=0;
    byte opcem=0;
    boolean salirm=false;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" -MODO MANUAL- ");
    while(salirm==false){
      key=teclado.getKey();
      if(key=='A'){
        if(opcm<4){
          opcm++;
        }else{opcm=0;}
      }else if(key=='B'){
        if(opcm>0){
          opcm--;
        }else{opcm=4;}
      }else if(key=='C'){
        salirm=true;
      }else if(key=='D'){
        opcm=5;
      }
      switch(opcm){
        case 0:
          lcd.setCursor(0,1);
          lcd.print("ZONA 1");
          opcem=0;
          break;
        case 1:
          lcd.setCursor(0,1);
          lcd.print("ZONA 2");
          opcem=1;
          break;
          
        case 2:
          lcd.setCursor(0,1);
          lcd.print("ZONA 3");
          opcem=2;
          break;
        case 3:
          lcd.setCursor(0,1);
          lcd.print("ZONA 4");
          opcem=3;
          break;
        case 4:
          lcd.setCursor(0,1);
          lcd.print("ZONA 5");
          opcem=4;
          break;
        case 5:
          switch(opcem){
            case 0:
              if(pinz1==true){
              digitalWrite(salida1,HIGH);
              pinz1=false;
              }else if(pinz1==false){digitalWrite(salida1,LOW);
              pinz1=true;
              }
              salirm=true;
              break;
            case 1:
              if(pinz2==true){
              digitalWrite(salida2,HIGH);
              pinz2=false;
              }else if(pinz2==false){digitalWrite(salida2,LOW);
              pinz2=true;
              }
              salirm=true;
              break;
            case 2:
              if(pinz3==true){
              digitalWrite(salida3,HIGH);
              pinz3=false;
              }else if(pinz3==false){digitalWrite(salida3,LOW);
              pinz3=true;
              }
              salirm=true;
              break;
            case 3:
              if(pinz4==true){
              digitalWrite(salida4,HIGH);
              pinz4=false;
              }else if(pinz4==false){digitalWrite(salida4,LOW);
              pinz4=true;
              }
              salirm=true;
              break;
            case 4:
              if(pinz5==true){
              digitalWrite(salida5,HIGH);
              pinz5=false;
              }else if(pinz5==false){digitalWrite(salida5,LOW);
              pinz5=true;
              }
              salirm=true;
              break;
            }
          }
          
        }
    delay(500);
    lcd.clear();
  }



  
