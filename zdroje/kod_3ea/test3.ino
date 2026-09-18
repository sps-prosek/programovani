const char cisla[10] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
const int cislaI[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int count = 1;
String prikaz = "";


int zpracuj_prikaz(String p)
{
  p.trim();
  int vys = 0;

  for(int i=0; i<p.length(); i++)
  {
    for(int x=0; x<10; x++)
    {
      if(p[i] == cisla[x])
      {
        vys = vys*count + cislaI[x];
        Serial.println("sss");
        Serial.println(vys);
        count = count*10; 
      }
    }
  }
  return vys;
}


void setup() {
  Serial.begin(9600);

}

int comand = 0;

void loop() {
  
  if(Serial.available())
  {
    char znak = Serial.read();

    if(znak == '\n')
    {
      comand = zpracuj_prikaz(prikaz);
      prikaz = "";
      Serial.println(comand);
    }
    else
    {
      prikaz += znak;
    }
  }

}
