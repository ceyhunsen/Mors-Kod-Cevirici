/**
 * Ceyhun Sen
 * Bu kod Universite Fizik II dersi
 * icin yazilmistir.
 **/

#include <LiquidCrystal.h>
#define buton_1 8
#define buton_2 7
#define buton_3 6
#define buzzer  9

int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const unsigned long kisa_basis_suresi = 250;
const int bekle = 100;
const String A = ".-", B = "-...", C = "-.-.", D = "-..",
             E = ".", F = "..-.", G = "--.", H = "....",
             I = "..", J = ".---", K = "-.-", L = ".-..",
             M = "--", N = "-.", O = "---", P = ".--.",
             Q = "--.-", R = ".-.", S = "...", T = "-",
             U = "..-", V = "...-", W = ".--", X = "-..-",
             Y = "-.--", Z = "--..";


void setup();
void loop();
void ekrana_yaz(String kelime);
char hangi_harf(unsigned long basis_suresi);
void ses_cikar(String kelime);
void harf_ses(String harf);
void mors_cizgi();
void mors_nokta();


void setup()
{
  pinMode(buton_1, INPUT);
  pinMode(buton_2, INPUT);
  pinMode(buton_3, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
}

void loop()
{
  int durum_1, durum_2, durum_3;
  static int son_durum_1 = -1, son_durum_2 = -1, son_durum_3 = -1;
  static String harf_mors_kodu = "", kelime = "";
  static unsigned long basis_zamani = 0, birakis_zamani = 0;
  unsigned long basis_suresi = 0;

  durum_1 = digitalRead(buton_1);
  durum_2 = digitalRead(buton_2);
  durum_3 = digitalRead(buton_3);

  if(durum_1 == HIGH && son_durum_1 == LOW) {
    basis_zamani = millis();
  }
  else if(durum_1 == LOW && son_durum_1 == HIGH) {
    birakis_zamani = millis();
    basis_suresi = birakis_zamani - basis_zamani;
    if(basis_suresi < kisa_basis_suresi) {
      harf_mors_kodu += ".";
    }
    else if(basis_suresi > kisa_basis_suresi){
      harf_mors_kodu += "-";
    }
  }
  else if(durum_2 == HIGH && son_durum_2 == LOW) {
    kelime += hangi_harf(harf_mors_kodu);
    ekrana_yaz(kelime);
    harf_mors_kodu = "";
  }
  else if(durum_3 == HIGH && son_durum_3 == LOW) {
    ses_cikar(kelime);
  }

  son_durum_1 = durum_1;
  son_durum_2 = durum_2;
  son_durum_3 = durum_3;
}

void ekrana_yaz(String kelime)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(kelime.substring(0, 16));
  lcd.setCursor(0, 1);
  lcd.print(kelime.substring(16, 32));
}

char hangi_harf(String harf)
{
  if(harf == A)      return 'A';
  else if(harf == B) return 'B';
  else if(harf == C) return 'C';
  else if(harf == D) return 'D';
  else if(harf == E) return 'E';
  else if(harf == F) return 'F';
  else if(harf == G) return 'G';
  else if(harf == H) return 'H';
  else if(harf == I) return 'I';
  else if(harf == J) return 'J';
  else if(harf == K) return 'K';
  else if(harf == L) return 'L';
  else if(harf == M) return 'M';
  else if(harf == N) return 'N';
  else if(harf == O) return 'O';
  else if(harf == P) return 'P';
  else if(harf == Q) return 'Q';
  else if(harf == R) return 'R';
  else if(harf == S) return 'S';
  else if(harf == T) return 'T';
  else if(harf == U) return 'U';
  else if(harf == V) return 'V';
  else if(harf == W) return 'W';
  else if(harf == X) return 'X';
  else if(harf == Y) return 'Y';
  else if(harf == Z) return 'Z';
  return ' ';
}

void ses_cikar(String kelime)
{
  for(unsigned int i = 0; i < kelime.length(); i++) {
    switch(kelime[i]) {
      case 'A':
        harf_ses(A);
        break;
      case 'B':
        harf_ses(B);
        break;
      case 'C':
        harf_ses(C);
        break;
      case 'D':
        harf_ses(D);
        break;
      case 'E':
        harf_ses(E);
        break;
      case 'F':
        harf_ses(F);
        break;
      case 'G':
        harf_ses(G);
        break;
      case 'H':
        harf_ses(H);
        break;
      case 'I':
        harf_ses(I);
        break;
      case 'J':
        harf_ses(J);
        break;
      case 'K':
        harf_ses(K);
        break;
      case 'L':
        harf_ses(L);
        break;
      case 'M':
        harf_ses(M);
        break;
      case 'N':
        harf_ses(N);
        break;
      case 'O':
        harf_ses(O);
        break;
      case 'P':
        harf_ses(P);
        break;
      case 'Q':
        harf_ses(Q);
        break;
      case 'R':
        harf_ses(R);
        break;
      case 'S':
        harf_ses(S);
        break;
      case 'T':
        harf_ses(T);
        break;
      case 'U':
        harf_ses(U);
        break;
      case 'V':
        harf_ses(V);
        break;
      case 'W':
        harf_ses(W);
        break;
      case 'Y':
        harf_ses(Y);
        break;
      case 'X':
        harf_ses(X);
        break;
      case 'Z':
        harf_ses(Z);
        break;
      default:
        harf_ses(" ");
        break;
    }
    delay(bekle);
  }
}

void harf_ses(String harf)
{
  for(unsigned int i = 0; i < harf.length(); i++) {
    if(harf[i] == '.')
      mors_nokta();
    else if(harf[i] == '-')
      mors_cizgi();
    delay(bekle);
  }
}

void mors_cizgi()
{
  digitalWrite(buzzer, HIGH);
  delay(bekle * 3);
  digitalWrite(buzzer, LOW);
}

void mors_nokta()
{
  digitalWrite(buzzer, HIGH);
  delay(bekle);
  digitalWrite(buzzer, LOW);
}
