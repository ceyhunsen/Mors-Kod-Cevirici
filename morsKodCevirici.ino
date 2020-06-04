#include <LiquidCrystal.h>
int rs=12,en=11,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
#define buton1 8    // Mors kodunun alinacagi buton
#define buton2 7    // Kodun bittiginin sinyalini veren buton
#define buton3 6    // Kelimenin mors kodunu buzzer'dan cikartacak buton
#define buzzer 9    // Kelimenin mors kodunu cikartacak buzzer
//Yukaridakiler devre icin gerekli tanimlamalar

int uzunluk=0;      // Tusa ne kadar sure bastigimizin bilgisi
int bekle=100;       // Gerekli yerlerdeki bekleme suresi
int uzunlukkritik=3;// Basis suremıze gore nokta veya cizgi oldugunun belirlenmesi
String kelime;      // Tam kelimeyi tutan degisken
String harf;        // Harfin mors kodundaki karsiligini tutan degisken
int durum1,durum2,durum3; // Butonlarin basilip basilmadiginin belirlenmesi

// Harflerin mors kodlari
String A=".-", B="-...", C="-.-.", D="-..",
       E=".", F="..-.", G="--.", H="....",
       I="..", J=".---", K="-.-", L=".-..",
       M="--", N="-.", O="---", P=".--.",
       Q="--.-", R=".-.", S="...", T="-",
       U="..-", V="...-", W=".--",
       X="-..-", Y="-.--", Z="--..";

String harfEkle(String harf,String kelime){
  /*
    Bu fonksiyon gelen kodu tanımlayip
    kelimeye ekler
  */
  if(harf==A)
    kelime+='A';
  else if(harf==B)
    kelime+='B';
  else if(harf==C)
    kelime+='C';
  else if(harf==D)
    kelime+='D';
  else if(harf==E)
    kelime+='E';
  else if(harf==F)
    kelime+='F';
  else if(harf==G)
    kelime+='G';
  else if(harf==H)
    kelime+='H';
  else if(harf==I)
    kelime+='I';
  else if(harf==J)
    kelime+='J';
  else if(harf==K)
    kelime+='K';
  else if(harf==L)
    kelime+='L';
  else if(harf==M)
    kelime+='M';
  else if(harf==N)
    kelime+='N';
  else if(harf==O)
    kelime+='O';
  else if(harf==P)
    kelime+='P';
  else if(harf==Q)
    kelime+='Q';
  else if(harf==R)
    kelime+='R';
  else if(harf==S)
    kelime+='S';
  else if(harf==T)
    kelime+='T';
  else if(harf==U)
    kelime+='U';
  else if(harf==V)
    kelime+='V';
  else if(harf==W)
    kelime+='W';
  else if(harf==X)
    kelime+='X';
  else if(harf==Y)
    kelime+='Y';
  else if(harf==Z)
    kelime+='Z';

  return kelime;
}

void harfSes(String harf){
  /*
    Bu fonksiyon gelen harfin mors
    kodunu buzzer'dan ses olarak verir
  */
  for(int i=0;i<harf.length();i++){
    if(harf[i]=='.')
      morsNokta();
    else
      morsCizgi();
    delay(bekle);
  }
}

void sesCikar(String kelime){
  /*
    Bu fonksiyon verilen kelimeyi
    harflere ayirarak buzzer'dan
    dogru sekilde ses gelmesi icin
    harfSes() fonksiyonunu cagirir
  */
  for(int i=0;i<kelime.length();i++){
    switch(kelime[i]){
      case 'A':
        harfSes(A);
        break;
      case 'B':
        harfSes(B);
        break;
      case 'C':
        harfSes(C);
        break;
      case 'D':
        harfSes(D);
        break;
      case 'E':
        harfSes(E);
        break;
      case 'F':
        harfSes(F);
        break;
      case 'G':
        harfSes(G);
        break;
      case 'H':
        harfSes(H);
        break;
      case 'I':
        harfSes(I);
        break;
      case 'J':
        harfSes(J);
        break;
      case 'K':
        harfSes(K);
        break;
      case 'L':
        harfSes(L);
        break;
      case 'M':
        harfSes(M);
        break;
      case 'N':
        harfSes(N);
        break;
      case 'O':
        harfSes(O);
        break;
      case 'P':
        harfSes(P);
        break;
      case 'Q':
        harfSes(Q);
        break;
      case 'R':
        harfSes(R);
        break;
      case 'S':
        harfSes(S);
        break;
      case 'T':
        harfSes(T);
        break;
      case 'U':
        harfSes(U);
        break;
      case 'V':
        harfSes(V);
        break;
      case 'W':
        harfSes(W);
        break;
      case 'Y':
        harfSes(Y);
        break;
      case 'X':
        harfSes(X);
        break;
      case 'Z':
        harfSes(Z);
        break;
    }
    delay(bekle);
  }
}

void morsCizgi(){   // Cizgi icin ses olusturur
  digitalWrite(buzzer,HIGH);
  delay(300);
  digitalWrite(buzzer,LOW);
}

void morsNokta(){   // Nokta icin ses olusturur
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
}

void setup(){
  pinMode(buton1,INPUT);
  pinMode(buton2,INPUT);
  pinMode(buton3,INPUT);
  pinMode(buzzer,OUTPUT);
  lcd.begin(16,2);
}

void loop(){
  durum1=digitalRead(buton1);
  durum2=digitalRead(buton2);
  durum3=digitalRead(buton3);
  if(durum1){       // Mors kodunu alan buton
    uzunluk++;
  }
  else if(durum2){  // Kodun hangi harfe karsilik geldigini gosteren buton
    lcd.clear();
    lcd.setCursor(0,0);
    kelime=harfEkle(harf,kelime);
    lcd.print(kelime);
    uzunluk=0;
    harf="";
    delay(bekle);
  }
  else if(durum3){  // Kelimenin mors kodunu buzzer'dan veren buton
    sesCikar(kelime);
  }
  else{             // Cizgi mi nokta mi olduguna karar verir
    if(uzunluk<=uzunlukkritik && uzunluk!=0){
      harf+='.';
    }               // Nokta girildigini anlar
    else if(uzunluk>uzunlukkritik && uzunluk!=0){
      harf+='-';
    }               // Uzun cizgi girildigini anlar
    uzunluk=0;
  }
  delay(bekle);
}
