const int btn1 = 5, btn2 = 4;
const int led1 = 3, led2 = 2;

const int z0 = 13, z1 = 12, z2 = 11, z3 = 10;
const int z4 = 9, z5 = 8, z6 = 7, z7 = 6;

int pin[] = {13, 12, 11, 10, 9, 8, 7, 6};

int i;
String data = "";;

void setup () {
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  for (int i = 6; i < 14; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop () {
  checkPerintah();
  Serial.println(data);
  delay(300);
}

void checkPerintah() {
  if (Serial.available()) {
    data = Serial.readString(); 
    Serial.println("Data yang diterima: " + data); 
  }

  if (data == "putarKiri"){
    putarKiri();
    putar();
  }

  if (data == "putarKanan"){
    putarKanan();
    putar();
  }
}

void putarKiri () {
    pin[0] = z0;  pin[1] = z1;  pin[2] = z2;
    pin[3] = z3;  pin[4] = z7;  pin[5] = z6;
    pin[6] = z5;  pin[7] = z4;
    putar();
  }

  void putarKanan () {
    pin[0] = z4;  pin[1] = z5;  pin[2] = z6;
    pin[3] = z7;  pin[4] = z3;  pin[5] = z2;
    pin[6] = z1;  pin[7] = z0;
    putar();
  }

  void putar() {
    for (int i = 0; i < 8; i++) {
      digitalWrite(pin[i], HIGH);
      delay(100);

      digitalWrite(pin[i], LOW);
      delay(100);
    }
  }
