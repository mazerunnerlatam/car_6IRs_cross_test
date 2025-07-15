// Arduino Mega con 6 sensores IR (Mapeo: Izquierda en A0 a Derecha en A5)
#define IR1_left_far   A0 // Sensor frontal-derecho en la cruz
#define IR2_left_mid   A1 // Sensor frontal-izquierdo en la cruz
#define IR3_left_cen   A2 // Sensor inferior en la cruz
#define IR4_right_cen  A3 // Sensor superior en la cruz
#define IR5_right_mid  A4 // Sensor central-izquierdo en la cruz
#define IR6_right_far  A5 // Sensor extremo-izquierdo en la cruz

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  // Configurar todos los pines de los sensores como ENTRADA
  pinMode(IR1_left_far, INPUT);
  pinMode(IR2_left_mid, INPUT);
  pinMode(IR3_left_cen, INPUT);
  pinMode(IR4_right_cen, INPUT);
  pinMode(IR5_right_mid, INPUT);
  pinMode(IR6_right_far, INPUT);

  Serial.println("✅ Sistema inicializado con 6 sensores.");
  Serial.println("Mostrando lecturas en formato de cruz.");
  delay(1000);
}

void loop() {
  // --- LECTURA DE SENSORES ---
  // (Esta parte no cambia)
  int s1_A0_dig = digitalRead(IR1_left_far);
  int s2_A1_dig = digitalRead(IR2_left_mid);
  int s3_A2_dig = digitalRead(IR3_left_cen);
  int s4_A3_dig = digitalRead(IR4_right_cen);
  int s5_A4_dig = digitalRead(IR5_right_mid);
  int s6_A5_dig = digitalRead(IR6_right_far);

  int s1_A0_an = analogRead(IR1_left_far);
  int s2_A1_an = analogRead(IR2_left_mid);
  int s3_A2_an = analogRead(IR3_left_cen);
  int s4_A3_an = analogRead(IR4_right_cen);
  int s5_A4_an = analogRead(IR5_right_mid);
  int s6_A5_an = analogRead(IR6_right_far);

  // --- IMPRESIÓN DIGITAL EN FORMATO DE CRUZ ---
  Serial.println("Digital (Formato Cruz):");
  Serial.print("\t   "); // Espacios para centrar el sensor superior
  Serial.println(s4_A3_dig); // A3
  Serial.println(); // Línea en blanco para espaciar
  Serial.print(s6_A5_dig);   // A5
  Serial.print("-");
  Serial.print(s5_A4_dig);   // A4
  Serial.print("----");
  Serial.print(s2_A1_dig);   // A1
  Serial.print("-");
  Serial.println(s1_A0_dig); // A0
  Serial.println(); // Línea en blanco para espaciar
  Serial.print("\t   "); // Espacios para centrar el sensor inferior
  Serial.println(s3_A2_dig); // A2
  
  Serial.println("------------------------------------");
  
  // --- IMPRESIÓN ANALÓGICA EN FORMATO DE CRUZ ---
  // Nota: La alineación puede no ser perfecta si los números tienen diferentes longitudes (ej: 12 vs 910)
  Serial.println("Análogo (Formato Cruz):");
  Serial.print("\t   ");
  Serial.println(s4_A3_an); // A3
  Serial.println();
  Serial.print(s6_A5_an);
  Serial.print("-");
  Serial.print(s5_A4_an);
  Serial.print("\t"); // Usamos un tabulador para el espacio central
  Serial.print(s2_A1_an);
  Serial.print("-");
  Serial.println(s1_A0_an); // A0
  Serial.println();
  Serial.print("\t   ");
  Serial.println(s3_A2_an); // A2

  Serial.println("====================================");

  // Pausa antes de repetir el ciclo
  delay(2000);
}