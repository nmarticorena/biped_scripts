
//#define DEBUG
#ifdef DEBUG
  #define DEBUG_PRINT(x)      Serial.print(x)
  #define DEBUG_PRINTLN(x)      Serial.println(x)
#else
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTLN(x)
#endif

#include <Servo.h>
#define LARGOLISTA 20
#define NADA 5

Servo leftHipServo; //0
Servo leftKneeServo; // 1
Servo leftAnkleServo; // 2
Servo rightHipServo; // 3
Servo rightKneeServo; //4
Servo rightAnkleServo; // 5

int estadoAccelZ;


void(* resetFunc) (void) = 0; //declare reset function @ address 0
int DatosZ[LARGOLISTA];
int SumZ=0;

struct Phase 
{ 
  unsigned long duracion;
  int posMotores[6];
  int  tipo ;  // 1 lineal; 2 acelerado; 3 desacelerado ;4 rapido extremos lento almedio ; 5: 4 alrevez

};



























int posLeftHip;
int posLeftKnee;
int posLeftAnkle;
int posRightHip;
int posRightKnee;
int posRightAnkle;

Phase Fases[17];

unsigned long tiempoentrandofuncion;
unsigned long tiemposaliendofuncion;
unsigned long tiempociclo;
unsigned long tiempoTransicion=0;
unsigned long tiempoInicioFase;

const int mosfitPin=7;
int mosfitState = HIGH;
int pinMercurio = 2;

int cotasup = 700 ;
int cotainf = 500 ;

void update (int tiempo) {   //REEMPLAZA A TODOS LOS DELAY
 DEBUG_PRINT("entrando a la funcion update / ");
  tiempoentrandofuncion = millis();

  
  
  uint32_t tinicial = millis();
  while (millis() - tinicial < tiempo) {
    estadoAccelZ=analogRead(A4);
    if (estadoAccelZ < cotainf){                               //si una medición es menor a la cota inferior
      Serial.println("CREO QUE ME CAIIIIIIIIIIIIIIIIII");
      for(int j=0;j<LARGOLISTA;j+=1){                          //empezar a guardar datos
         DatosZ[j]=estadoAccelZ;
         estadoAccelZ=analogRead(A4);
         delay(10);
      }
      for(int j=0;j<LARGOLISTA;j+=1){                          //?
         SumZ+=DatosZ[j];
      }
      if (SumZ<15){                                            //si una cantidad determinada de datos es menor al umbral
          Serial.println("SI ME CAIIIIIIIIIIIIIIIIIIIIIIIIII");//vamo a matarno
          leftHipServo.detach();
          leftKneeServo.detach();
          leftAnkleServo.detach();
          rightHipServo.detach();
          rightKneeServo.detach();
          rightAnkleServo.detach();
      while (true){
      estadoAccelZ = analogRead(A4);
      Serial.println("Levantame Porfavor");
      for(int j=0;j<LARGOLISTA;j+=1){                           //empezar a medir de nuevo
         DatosZ[j]=estadoAccelZ;
         estadoAccelZ=analogRead(A4);
         delay(10);
      }
      for(int j=0;j<LARGOLISTA;j+=1){                           //?
         SumZ+=DatosZ[j];
      }
      if (SumZ==20) {                                           //si los datos guardados se enderezan y todos están sobre el umbral                                 
          Serial.println("Gracias *.*");                        //vamo a revivirno
          delay(4000);
          leftHipServo.attach(11);
          leftKneeServo.attach(10);
          leftAnkleServo.attach(9);
          rightHipServo.attach(6);
          rightKneeServo.attach(5);
          rightAnkleServo.attach(3);
            leftHipServo.write(Fases[0].posMotores[0]);
          delay(100);
        leftKneeServo.write(Fases[0].posMotores[1]);
        delay(100);
        leftAnkleServo.write(Fases[0].posMotores[2]);
        delay(100);
        rightHipServo.write(Fases[0].posMotores[3]);
        delay(100);
        rightKneeServo.write(Fases[0].posMotores[4]);
        delay(100);
        rightAnkleServo.write(Fases[0].posMotores[5]);  
        //nroFase=1;
        //FaseActual=1
        resetFunc(); 
          break;
          
     }

      
    }
    }
    }
    /*else if (estado Mercurio == 1) {
        leftHipServo.attach();
        leftKneeServo.attach();
        leftAnkleServo.attach();
        rightHipServo.detach();
        rightKneeServo.detach();
        rightAnkleServo.detach();


      
    }*/

    
    delay(1);
    Serial.print("tiempo que estuve en la funcion update: ");
    tiemposaliendofuncion = millis();
    tiempociclo += tiemposaliendofuncion - tiempoentrandofuncion;
    Serial.println(tiemposaliendofuncion - tiempoentrandofuncion);  
  }
}

int FaseSig;
int FaseActual;
int FasePosterior;

void setup() {
  
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
  
  digitalWrite(mosfitPin,HIGH); 
  pinMode(pinMercurio, INPUT);          //interruptor de mercurio
  
  leftHipServo.attach(11);
  leftKneeServo.attach(10);
  leftAnkleServo.attach(9);
  rightHipServo.attach(6);
  rightKneeServo.attach(5);
  rightAnkleServo.attach(3);
  
  posLeftHip=106;
  posLeftKnee=113;
  posLeftAnkle=93;//93
  posRightHip=97;
  posRightKnee=87;
  posRightAnkle=97;//97
  
  Fases[0].duracion=2500;                                           /////// cambiar si se demora mucho
  Fases[0].posMotores[0]=posLeftHip;
  Fases[0].posMotores[1]=posLeftKnee;
  Fases[0].posMotores[2]=posLeftAnkle;                          //CAMBIAR TIEMPO DE DURACION DE 0 SI I DEMORA MUCHO!!!!!!!!!!!!!!!!!!!
  Fases[0].posMotores[3]=posRightHip;
  Fases[0].posMotores[4]=posRightKnee;
  Fases[0].posMotores[5]=posRightAnkle;

  Fases[0].tipo=4;
  
  //fase 1
  posLeftHip=106;
  posLeftKnee=113;//112
  posLeftAnkle=78;//70 
  posRightHip=97;
  posRightKnee=87;//112
  posRightAnkle=83;//75
  Fases[1].duracion=1000;//2K
  Fases[1].posMotores[0]=posLeftHip;
  Fases[1].posMotores[1]=posLeftKnee;
  Fases[1].posMotores[2]=posLeftAnkle;
  Fases[1].posMotores[3]=posRightHip;
  Fases[1].posMotores[4]=posRightKnee;
  Fases[1].posMotores[5]=posRightAnkle;

  Fases[1].tipo=4;


  //fase2
  Fases[2].duracion=1000;//2K //milisegundos
  
  posLeftHip=92;
  posLeftKnee=123;
  posLeftAnkle=78;//100
  
  posRightHip=74;
  posRightKnee=102;
  posRightAnkle=89;//104
  
  Fases[2].posMotores[0]=posLeftHip;
  Fases[2].posMotores[1]=posLeftKnee;
  Fases[2].posMotores[2]=posLeftAnkle;
  Fases[2].posMotores[3]=posRightHip;
  Fases[2].posMotores[4]=posRightKnee;
  Fases[2].posMotores[5]=posRightAnkle;

  Fases[2].tipo=4;  



//fase3
  Fases[3].duracion=500;//2.5K //milisegundos
  posLeftHip=92;
  posLeftKnee=123;
  posLeftAnkle=98;
  posRightHip=69;
  posRightKnee=114;
  posRightAnkle=105;
  Fases[3].posMotores[0]=posLeftHip;
  Fases[3].posMotores[1]=posLeftKnee;
  Fases[3].posMotores[2]=posLeftAnkle;
  Fases[3].posMotores[3]=posRightHip;
  Fases[3].posMotores[4]=posRightKnee;
  Fases[3].posMotores[5]=posRightAnkle;

  Fases[3].tipo=4;  


  //fase4
  Fases[4].duracion=1000;//2.5K //milisegundos
  
  posLeftHip=92;
  posLeftKnee=123;
  posLeftAnkle=110;
  
  posRightHip=93;
  posRightKnee=91;
  posRightAnkle=112;
  
  Fases[4].posMotores[0]=posLeftHip;
  Fases[4].posMotores[1]=posLeftKnee;
  Fases[4].posMotores[2]=posLeftAnkle;
  Fases[4].posMotores[3]=posRightHip;
  Fases[4].posMotores[4]=posRightKnee;
  Fases[4].posMotores[5]=posRightAnkle;

  Fases[4].tipo=4;  


  //fase5
  Fases[5].duracion=1000;//2.K //milisegundos
  posLeftHip=138;
  posLeftKnee=74;
  posLeftAnkle=111;
  
  posRightHip=104;
  posRightKnee=91;
  posRightAnkle=114;
  Fases[5].posMotores[0]=posLeftHip;
  Fases[5].posMotores[1]=posLeftKnee;
  Fases[5].posMotores[2]=posLeftAnkle;
  Fases[5].posMotores[3]=posRightHip;
  Fases[5].posMotores[4]=posRightKnee;
  Fases[5].posMotores[5]=posRightAnkle;

  Fases[5].tipo=4;  



  //fase6                                                 // ACA GIRAAAAAAAAAAAAAAAA    FALTA UN POQUITO EN EL LEFT
  Fases[6].duracion=1000;//2.K //milisegundos
  posLeftHip=137;
  posLeftKnee=94;
  posLeftAnkle=93;
  
  posRightHip=103;
  posRightKnee=69;
  posRightAnkle=98;
  Fases[6].posMotores[0]=posLeftHip;
  Fases[6].posMotores[1]=posLeftKnee;
  Fases[6].posMotores[2]=posLeftAnkle;
  Fases[6].posMotores[3]=posRightHip;
  Fases[6].posMotores[4]=posRightKnee;
  Fases[6].posMotores[5]=posRightAnkle;

  Fases[6].tipo=4;  



  //fase7                                                 
  Fases[7].duracion=1000;//2K //milisegundos
  posLeftHip=123;
  posLeftKnee=107;
  posLeftAnkle=81;
  
  posRightHip=103;
  posRightKnee=69;
  posRightAnkle=79;
  Fases[7].posMotores[0]=posLeftHip;
  Fases[7].posMotores[1]=posLeftKnee;
  Fases[7].posMotores[2]=posLeftAnkle;
  Fases[7].posMotores[3]=posRightHip;
  Fases[7].posMotores[4]=posRightKnee;
  Fases[7].posMotores[5]=posRightAnkle;

  Fases[7].tipo=4;  

  //fase8
  Fases[8].duracion=1000;//2K //milisegundos
  
  posLeftHip=92;
  posLeftKnee=123;
  posLeftAnkle=78;
  
  posRightHip=74;
  posRightKnee=102;
  posRightAnkle=89;
  
  Fases[8].posMotores[0]=posLeftHip;
  Fases[8].posMotores[1]=posLeftKnee;
  Fases[8].posMotores[2]=posLeftAnkle;
  Fases[8].posMotores[3]=posRightHip;
  Fases[8].posMotores[4]=posRightKnee;
  Fases[8].posMotores[5]=posRightAnkle;

  Fases[8].tipo=4;  
  
  
  
  
  //GIRAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR
  
  
  //left     fine 
  Fases[9].duracion=400;
  posLeftHip=92;
  posLeftKnee=123;
  posLeftAnkle=82;
  
  posRightHip=74;
  posRightKnee=102;
  posRightAnkle=97;
  
  Fases[9].posMotores[0]=posLeftHip;
  Fases[9].posMotores[1]=posLeftKnee;
  Fases[9].posMotores[2]=posLeftAnkle;
  Fases[9].posMotores[3]=posRightHip;
  Fases[9].posMotores[4]=posRightKnee;
  Fases[9].posMotores[5]=posRightAnkle;

  Fases[9].tipo=4;  
  
  
  
  ////  left      coargiro   1
  Fases[10].duracion=400;
  posLeftHip=116;
  posLeftKnee=110;
  posLeftAnkle=78;
  
  posRightHip=64;
  posRightKnee=98;
  posRightAnkle=81;
  
  Fases[10].posMotores[0]=posLeftHip;
  Fases[10].posMotores[1]=posLeftKnee;
  Fases[10].posMotores[2]=posLeftAnkle;
  Fases[10].posMotores[3]=posRightHip;
  Fases[10].posMotores[4]=posRightKnee;
  Fases[10].posMotores[5]=posRightAnkle;

  Fases[10].tipo=4;  
  
  
  
  
  ////  left      coargiro   2
  Fases[11].duracion=400;
  posLeftHip=116;
  posLeftKnee=116;
  posLeftAnkle=83;
  
  posRightHip=50;
  posRightKnee=86;
  posRightAnkle=95;
  
  Fases[11].posMotores[0]=posLeftHip;
  Fases[11].posMotores[1]=posLeftKnee;
  Fases[11].posMotores[2]=posLeftAnkle;
  Fases[11].posMotores[3]=posRightHip;
  Fases[11].posMotores[4]=posRightKnee;
  Fases[11].posMotores[5]=posRightAnkle;

  Fases[11].tipo=4;  
  
  
  
  
  
    ////  right      finegiro   
  Fases[12].duracion=400;
  posLeftHip=131;
  posLeftKnee=93;
  posLeftAnkle=88;
  
  posRightHip=103;
  posRightKnee=82;
  posRightAnkle=104;
  
  Fases[12].posMotores[0]=posLeftHip;
  Fases[12].posMotores[1]=posLeftKnee;
  Fases[12].posMotores[2]=posLeftAnkle;
  Fases[12].posMotores[3]=posRightHip;
  Fases[12].posMotores[4]=posRightKnee;
  Fases[12].posMotores[5]=posRightAnkle;

  Fases[12].tipo=4;  
  
  
  
  
  
    ////  right      coargiro   1
  Fases[13].duracion=400;
  posLeftHip=131;
  posLeftKnee=85;
  posLeftAnkle=100;
  
  posRightHip=103;
  posRightKnee=87;
  posRightAnkle=111;
  
  Fases[13].posMotores[0]=posLeftHip;
  Fases[13].posMotores[1]=posLeftKnee;
  Fases[13].posMotores[2]=posLeftAnkle;
  Fases[13].posMotores[3]=posRightHip;
  Fases[13].posMotores[4]=posRightKnee;
  Fases[13].posMotores[5]=posRightAnkle;

  Fases[13].tipo=4;  
  
  
  
  
  
    ////  right      coargiro   2
  Fases[14].duracion=400;
  posLeftHip=139;
  posLeftKnee=113;
  posLeftAnkle=95;
  
  posRightHip=91;
  posRightKnee=82;
  posRightAnkle=106;
  
  Fases[14].posMotores[0]=posLeftHip;
  Fases[14].posMotores[1]=posLeftKnee;
  Fases[14].posMotores[2]=posLeftAnkle;
  Fases[14].posMotores[3]=posRightHip;
  Fases[14].posMotores[4]=posRightKnee;
  Fases[14].posMotores[5]=posRightAnkle;

  Fases[14].tipo=4;  
  
  
  
  
  
  
  /////POSICION ERGUIDA 1
  posLeftHip=106;
  posLeftKnee=113;
  posLeftAnkle=93;//93
  posRightHip=97;
  posRightKnee=87;
  posRightAnkle=97;//97
  
  Fases[15].duracion=700;                                           /////// cambiar si se demora mucho
  Fases[15].posMotores[0]=posLeftHip;
  Fases[15].posMotores[1]=posLeftKnee;
  Fases[15].posMotores[2]=posLeftAnkle;                          //CAMBIAR TIEMPO DE DURACION DE 0 SI I DEMORA MUCHO!!!!!!!!!!!!!!!!!!!
  Fases[15].posMotores[3]=posRightHip;
  Fases[15].posMotores[4]=posRightKnee;
  Fases[15].posMotores[5]=posRightAnkle;

  Fases[15].tipo=4;
  
  
  // POSICIONERGUIDA 2

  Fases[16].duracion=300;                                           /////// cambiar si se demora mucho
  Fases[16].posMotores[0]=posLeftHip;
  Fases[16].posMotores[1]=posLeftKnee;
  Fases[16].posMotores[2]=posLeftAnkle;                          //CAMBIAR TIEMPO DE DURACION DE 0 SI I DEMORA MUCHO!!!!!!!!!!!!!!!!!!!
  Fases[16].posMotores[3]=posRightHip;
  Fases[16].posMotores[4]=posRightKnee;
  Fases[16].posMotores[5]=posRightAnkle;

  Fases[16].tipo=4;
  
  
  
  
  
  
  
  
  leftHipServo.write(Fases[0].posMotores[0]);
  update(100);
  leftKneeServo.write(Fases[0].posMotores[1]);
  update(100);
  leftAnkleServo.write(Fases[0].posMotores[2]);
  delay(100);;
  rightHipServo.write(Fases[0].posMotores[3]);
  update(300);
  rightKneeServo.write(Fases[0].posMotores[4]);
  update(100);
  rightAnkleServo.write(Fases[0].posMotores[5]);  
  //nroFase=1;
  FaseActual=0;
  FaseSig=0;
  tiempoTransicion=0;
  
  tiempoInicioFase=millis();  
  
  
}











// HACER ESTA FUNCION EN DONDE LE PASO UN PARAMETRO EL CUAL SERA UNA VARIABLE GLOBAL, NO SE SI HABLA UN PROBLEMA 
//DE SCOPE AL HACER ESTO, PERO HABRIA QUE INETNTAR, ENTONCES EN VEZ  DE LLAMAR A LA FUNCION SOLO AL PRINCIPIO
// LA LLAMO CADA CIERTO TIEMOPO ENTREGANDOLE 2 VARIAABLE O 1, ASI IR RESTANDO LA MEDICION ANTIGUA Y TOMAR UNA MEDICION NUEVA PARA SUMARSELA A LA SUMA TOTAL

float aceleracion[3]={0,0,0};
int ejex ;
int ejey ;
int ejez ;


void SensorFilter() {
       DEBUG_PRINT("Entrando SensorFilter / ");
 tiempoentrandofuncion = millis();

  //retornar llso valores del acelerometro en cada eje
  int xRead = analogRead(A0);
  int yRead = analogRead(A1);
  int zRead = analogRead(A2);
  //ejex = Vtofloat(ejex);
  //ejey = Vtofloat(ejey);
  //ejez = Vtofloat(ejez);
  
 DEBUG_PRINT("acel en x: " );
 DEBUG_PRINT(ejex);
 DEBUG_PRINT("acel en y: " );
 DEBUG_PRINT(ejey);
 DEBUG_PRINT("acel en z: " );
 DEBUG_PRINT(ejez);
 

  aceleracion[0] = ejex;
  aceleracion[1] = ejey;
  aceleracion[2] = ejez;
    DEBUG_PRINT("Saliendo SensorFilter / t: ");
    tiemposaliendofuncion = millis();
    tiempociclo += tiemposaliendofuncion - tiempoentrandofuncion;
    DEBUG_PRINTLN(tiemposaliendofuncion - tiempoentrandofuncion);  
    if(tiempoTransicion!=0){tiempoTransicion+=tiemposaliendofuncion - tiempoentrandofuncion;}
}


char valByte = '5'; 
int accionBlue;

boolean k;
void RX() {

    DEBUG_PRINT("Entrando RX / ");
    tiempoentrandofuncion = millis();
    
 if (Serial.available()){
    
   valByte = Serial.read();
 } 
  
  if ( valByte == '0' ){ //parar(quedarse erguido)

    accionBlue = 0;
    
  }
  
    if ( valByte == '1' ){ //caminar en linea recta
    //caminar recto
    accionBlue = 1;
    valByte='a';
  }
  
    if ( valByte == '2' ){ //girar izq
    //caminar recto
    accionBlue = 2;
    k=true;
    DEBUG_PRINT("ENTRE AL RX2 KTRUE");
    valByte='a';
  }
  
    if ( valByte == '3' ){ //girar der
    //caminar recto
    accionBlue = 3;
    k=true;
    valByte='a';
    //Serial.println("accion: caminar");
  }
  if (valByte == '4' ){ //detenerse
   accionBlue = 4;
  valByte='a'; 
  }
  if (valByte == '7' ){ //emergencia
  accionBlue = 7;
  valByte='a'; 
  }

    DEBUG_PRINT("Saliendo RX / t: ");
    tiemposaliendofuncion = millis();
    tiempociclo += tiemposaliendofuncion - tiempoentrandofuncion;
    DEBUG_PRINTLN(tiemposaliendofuncion - tiempoentrandofuncion);  
   if(tiempoTransicion!=0){tiempoTransicion+=tiemposaliendofuncion - tiempoentrandofuncion;}

}

unsigned long t0;
float dif;
int durac;
int t;
int d;
float lambda;



unsigned long time;

unsigned long tiempo;
unsigned long tiempofase;
boolean termino; 
//unsigned long tiempoInicioFase;

float calcularLambda(unsigned long tiempo,unsigned long tiempotranscurrido){
 /*
    Serial.print("Entrando a la funcion calcularLambda / ");
    tiempoentrandofuncion = millis(); 
 */
  //float lambda;
   time=millis();
   durac=Fases[FaseSig].duracion;
   //Serial.print("estoy en la Fase/FaseActual: ");
   //Serial.print(FaseActual);                                       ??????
   DEBUG_PRINT(" ,    estoy yendo a la Fase/FaseSig : ");
   DEBUG_PRINTLN(FaseSig);
   DEBUG_PRINT("duracion de la fase: ");
   DEBUG_PRINTLN(durac);
   //dif= time-tiempotranscurrido;
   dif = millis() - tiempoInicioFase;
   //Serial.print("dif: ");para que ponerla ?>:c
  
   DEBUG_PRINT("Tiempo transcurrido: ");//no se si sea necesaria ponerla
   DEBUG_PRINTLN(dif);
  
   if (dif >= durac ) { //quiere decir que ya paso el tiempo que debe pasar en la duracion hacia la fase siguiente 
     lambda = 1;
   }  
   else{  
     lambda = 1-cos( dif/durac*PI/2 );
   }
   DEBUG_PRINT(" lambda: ");
   DEBUG_PRINTLN(lambda);     // podria ponerlo alfinal del wsm
   Serial.print(" lambda: ");
   Serial.println(lambda);     // podria ponerlo alfinal del wsm
   
/* nose si sera necesaraio tener que poner esto 
    Serial.print("tiempo que estuve en la funcion calcularLambda: ");
   tiemposaliendofuncion = millis();
      tiempociclo += tiemposaliendofuncion - tiempoentrandofuncion;
    Serial.println(tiemposaliendofuncion - tiempoentrandofuncion);  
 
 */
 return lambda; 
}






int situacion;

void FaseManager(){



  
 int duracioncambiofase = Fases[FaseSig].duracion;
 
 
 
 
  //if ( tiempoTransicion >= duracioncambiofase || lambda == 1){
    if ( (millis() -tiempoInicioFase) >= duracioncambiofase || lambda == 1 ){// ||  (FaseActual==0 &&FaseSig==0 &&       ) {
        termino = true; 
      }
 
   if(termino){DEBUG_PRINTLN("ENTRE AL TERMINO"); FaseActual=FaseSig;FaseSig=FasePosterior;tiempoInicioFase=millis(); tiempoTransicion=0; time=millis(); tiempoTransicion+=time; lambda=0; termino=false;}  //tiempoTransicion //time???
       
       DEBUG_PRINT("TIEMPOINICIOFASE ANTES DE ENTRAR AL CALCULOLAMBDA");
       DEBUG_PRINTLN(tiempoInicioFase);
       lambda = calcularLambda(tiempofase,tiempoTransicion);
       
}
 
 
 
 
  

int accionBluett=1;
void WSM (){//inputs que me piden que me lees los sensores y que                           /// ERROR RESUELTO CON TIEMPOINICIOFASE=MILLIS// DURACION DE FASES MUY PEQUEÑAS(?)
 
  DEBUG_PRINT("Entrando WSM /");
    tiempoentrandofuncion = millis();
 time =tiempoentrandofuncion;

   //usar accionBlue,   
 DEBUG_PRINT("ESTOY EN LA FASE ACTUAL:");
 DEBUG_PRINTLN(FaseActual);
 DEBUG_PRINT("FASE SIG:");
 DEBUG_PRINTLN(FaseSig);
 unsigned long tiempotransicion = tiempoTransicion;
 int faseactual =FaseActual;
 int fasesig = FaseSig;
 int faseposterior = FasePosterior;
 //int duracioncambiofase = Fases[FaseSig].duracion;
 
 //preguntar si ya se termino de hacer el cambio de fase
 /*
 if ( tiempoTransicion >= duracioncambiofase || faseactual == fasesig){
  termino = true; 
 }
*/ 
  
    if (accionBlue == 1 ) { // camianr recto
       DEBUG_PRINT("ACCIONBLUE: ");
       DEBUG_PRINTLN(accionBlue);
      /* if (faseactual == 0 && fasesig==1) {// usar el aclerometro ?
          if(termino){FaseActual=FaseSig;FaseSig++;tiempoTransicion = 0;}
          
          lambda = calcularLambda(tiempofase,tiempoTransicion);
         
       }
       //combinar estos solo en uno  ------->> dps fijar limites, onda el caso generalizado de camina recto,if(faseactual,fasesig pertenece a (0,8) entonces, si no son el caso limite 7,8(else) hacer el faseactual=fasesig;fasesig++; (Estrucutra de pares)
       else if (faseactual == 8 && fasesig == 3 ) {
           if(termino){FaseActual=FaseSig;FaseSig++;tiempoTransicion = 0;}
          
          lambda = calcularLambda(tiempofase,tiempoTransicion);    
       } 
       //ademas ver dps que pasa simando una orden en medio de uno de estos(en otro accionbluet)
       */
      
      // else if
      
      ////////////////////////////////////////////////////////////////////////////
         if (   (faseactual == 0 && fasesig == 0) || (faseactual == 15 && fasesig == 15) || (faseactual == 16 && fasesig == 16)     ){
            FasePosterior = 1;
            DEBUG_PRINT("[FASE ACTUAL: ");
            DEBUG_PRINT(FaseActual);
            DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");
            //lambda =1;
        //if(termino){ FaseActual=FaseSig; FaseSig=FasePosterior; FasePosterior++; time=millis();      }
        //Fase
         }
      
      
      
      
      
       else if ( faseactual ==7 && fasesig == 8 ){
          FasePosterior=3;
                      DEBUG_PRINT("[FASE ACTUAL: ");
            DEBUG_PRINT(FaseActual);
            DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");
         //if(termino){FaseActual=FaseSig;FaseSig=FasePosterior;tiempoTransicion=0;time=millis();}
        
         //lambda = calcularLambda(tiempofase,tiempoTransicion);
       }
       // tiene quepasar que c8ando de unavuelta, faseactual=fasesig , fasesig=faseposterior faseposterior=faseposterior
       //else if ( faseactual == 8){
        else { 
          FasePosterior = FaseSig +1;
                      DEBUG_PRINT("[FASE ACTUAL: ");
            DEBUG_PRINT(FaseActual);
            DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");
         //if(termino){ FaseActual=FaseSig;FaseSig=FaseActual;FasePosterior++;tiempoTransicion=0;time=millis();}//FaseActual=FaseSig;FaseActual++;tiempoTransicion=0;time=millis();}
         
         //lambda = calcularLambda(tiempofase,tiempoTransicion);
       }

    }//1
    //funciona pero no avisa en pantalla, cambiar eso(?)
    else if (accionBlue == 0){ //quedarse quieto
         DEBUG_PRINT("ACCIONBLUE: ");
         DEBUG_PRINTLN(accionBlue);
        //esperar a alguna fase estable y ponerse erguido, si es necesario cambiar el comando Bluett a "1" y llamar  a WSM() para que siga derecho/girando hasta que llegue a una fase estable
        // while? DO bluett = 1
        if(   (faseactual == 0 && fasesig == 0) || (faseactual == 15 && fasesig == 15) || (faseactual == 16 && fasesig == 16)     ){   
           FasePosterior = 0;
           DEBUG_PRINT("[FASE ACTUAL: ");
           DEBUG_PRINT(FaseActual);
           DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");
        } 
      //else if( faseactual== FASEESTABLE1 && fasesig == FASE_QUE_INDIQUE_QUE_ESTABA_HACIENDO_ANTES)
        else if(faseactual == 5 && fasesig == 6 ){
         FasePosterior = 0; 
         DEBUG_PRINT("[FASE ACTUAL: ");
         DEBUG_PRINT(FaseActual);
         DEBUG_PRINT(", FASESIG: ");
         DEBUG_PRINT(FaseSig);
         DEBUG_PRINT("  => ");
         DEBUG_PRINT(" FASE POSTERIOR: ");
         DEBUG_PRINT(FasePosterior);
         DEBUG_PRINTLN(" ]");
        }
        else if(faseactual == 3 && fasesig == 4 ){
         FasePosterior = 0; 
         DEBUG_PRINT("[FASE ACTUAL: ");
         DEBUG_PRINT(FaseActual);
         DEBUG_PRINT(", FASESIG: ");
         DEBUG_PRINT(FaseSig);
         DEBUG_PRINT("  => ");
         DEBUG_PRINT(" FASE POSTERIOR: ");
         DEBUG_PRINT(FasePosterior);
         DEBUG_PRINTLN(" ]");
        }
        
    //}
    }
    else if( accionBlue == 2 ){ // girar izq
          DEBUG_PRINT("ACCIONBLUE: ");
         DEBUG_PRINTLN(accionBlue);
         Serial.print("ACCIONBLUE: ");
         Serial.println(accionBlue);
         
         if(   (faseactual == 0 && fasesig == 0) || ( k==true && (faseactual == 15 && fasesig == 15) || (faseactual == 16 && fasesig == 16)    ) ){
           FasePosterior = 10; 
           DEBUG_PRINT("[FASE ACTUAL: ");
           DEBUG_PRINT(FaseActual);
           DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");
         }
         else if (faseactual== 0 && fasesig== 10){
           FasePosterior = 11; 
           DEBUG_PRINT("[FASE ACTUAL: ");
           DEBUG_PRINT(FaseActual);
           DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");
         
         }
         
         else if (faseactual == 10 && fasesig == 11){
           FasePosterior = 15;                        //fase necesaria para que termine de girar
           DEBUG_PRINT("[FASE ACTUAL: ");
           DEBUG_PRINT(FaseActual);
           DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");
          
         }
         else if (faseactual == 11 & fasesig == 15){ //faseposteriro quedara = 0 asi que alfinal sera 0
           FasePosterior = 15;
           k=false;
   
           DEBUG_PRINT("[FASE ACTUAL: ");
           DEBUG_PRINT(FaseActual);
           DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");
         
         }//   !!!!!!!!!!!!!!!!!!!!!!!!!!!!! SI DEMORA MUCHO PASAR A 0 , CREAR OTRO SETPOINT 16 QUESEA IGUAL QUE EL 0 PERO QUE TENGA UNA DURACION MUCHO MENOR
        
        
        //NO E SNECESARIO PONER ESTE ELSE IF YA QUE EL ANTERIOR HACE LOO MISMO(DEJA EL 15 TODO EL TIEMPO)
         else if (faseactual == 15 && fasesig == 15){
           FasePosterior = 15;                        //fase necesaria para que termine de girar
           DEBUG_PRINT("[FASE ACTUAL: ");
           DEBUG_PRINT(FaseActual);
           DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");
          
         }

      
    }
    
    
   else if( accionBlue == 3 ){ // girar der
          DEBUG_PRINT("ACCIONBLUE: ");
         DEBUG_PRINTLN(accionBlue);
         Serial.print("ACCIONBLUE: ");
         Serial.println(accionBlue);
         
         if(   (faseactual == 0 && fasesig == 0) || (faseactual == 15 && fasesig == 15) || (faseactual == 16 && fasesig == 16)     ){
           FasePosterior = 13; 
           DEBUG_PRINT("[FASE ACTUAL: ");
           DEBUG_PRINT(FaseActual);
           DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");
         }
         else if (faseactual== 0 && fasesig== 13){
           FasePosterior = 14; 
           DEBUG_PRINT("[FASE ACTUAL: ");
           DEBUG_PRINT(FaseActual);
           DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");
         
         }
         
         else if (faseactual == 13 && fasesig == 14){
           FasePosterior = 15;                        //fase necesaria para que termine de girar
           DEBUG_PRINT("[FASE ACTUAL: ");
           DEBUG_PRINT(FaseActual);
           DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");
          
         }
         else if (faseactual == 14 & fasesig == 15){ //faseposteriro quedara = 0 asi que alfinal sera 0
           FasePosterior = 15;
           accionBlue=10;
           DEBUG_PRINT("[FASE ACTUAL: ");
           DEBUG_PRINT(FaseActual);
           DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");
         
         }//   !!!!!!!!!!!!!!!!!!!!!!!!!!!!! SI DEMORA MUCHO PASAR A 0 , CREAR OTRO SETPOINT 16 QUESEA IGUAL QUE EL 0 PERO QUE TENGA UNA DURACION MUCHO MENOR
      

      
    }
    else if ( accionBlue == 5 ){ // left fine giro
       DEBUG_PRINT("ACCIONBLUE: ");
       DEBUG_PRINTLN(accionBlue);
       Serial.print("ACCIONBLUE: ");
       Serial.println(accionBlue);
      if(   (faseactual == 0 && fasesig == 0) || (faseactual == 15 && fasesig == 15) || (faseactual == 16 && fasesig == 16)     ){
           FasePosterior=9; 
           DEBUG_PRINT("[FASE ACTUAL: ");
           DEBUG_PRINT(FaseActual);
           DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");        
      }
      else if(faseactual ==0 && fasesig==9 ){
           FasePosterior = 16; 
           DEBUG_PRINT("[FASE ACTUAL: ");
           DEBUG_PRINT(FaseActual);
           DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");     
      }
      
    }
    
    else if ( accionBlue == 6 ){ // right fine giro
       DEBUG_PRINT("ACCIONBLUE: ");
       DEBUG_PRINTLN(accionBlue);
       Serial.print("ACCIONBLUE: ");
       Serial.println(accionBlue);
      if(   (faseactual == 0 && fasesig == 0) || (faseactual == 15 && fasesig == 15) || (faseactual == 16 && fasesig == 16)     ){
           FasePosterior=12; 
           DEBUG_PRINT("[FASE ACTUAL: ");
           DEBUG_PRINT(FaseActual);
           DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");        
      }
      else if(faseactual ==0 && fasesig==12 ){
           FasePosterior = 16; 
           DEBUG_PRINT("[FASE ACTUAL: ");
           DEBUG_PRINT(FaseActual);
           DEBUG_PRINT(", FASESIG: ");
           DEBUG_PRINT(FaseSig);
           DEBUG_PRINT("  => ");
           DEBUG_PRINT(" FASE POSTERIOR: ");
           DEBUG_PRINT(FasePosterior);
           DEBUG_PRINTLN(" ]");     
      }
      
    }    
    else if( accionBlue == 4){
      if(faseactual == 0  && fasesig == 0){
  
      }


      
    }
    else if( accionBlue == 7 ){
          leftHipServo.detach();
          leftKneeServo.detach();
          leftAnkleServo.detach();
          rightHipServo.detach();
          rightKneeServo.detach();
          rightAnkleServo.detach();
    }
    
    

    
    
            // no s esi usar esto o antes de usar FaseSig,FaseActual
  
   float acelx = aceleracion[0] ;
   float acely = aceleracion[1] ;
   float acelz = aceleracion[2] ;
   //hacer algunos if y crear variable booleana y escribirla dependiendo del estado movimiento del robot 
   //tambien if por si esta en posiciones en donde se va a caer, dependiendo la FaseActual, contrarestar el movimiento que hace que se mueva, si no se puede que intnte erguirse.
   //if (esta todo como se debe) {
   //  situacion =0;
   //}
   
    
    
    
    
    // LO QUE DEBO ENTREGAR
    //NextPhase=
    //ACtuaPhase
   //lambda = ... 
   //FallDownState=
       DEBUG_PRINT("saliendo WSM, t: ");
      tiemposaliendofuncion = millis();
      tiempociclo += tiemposaliendofuncion - tiempoentrandofuncion;
      DEBUG_PRINTLN(tiemposaliendofuncion - tiempoentrandofuncion);  
      if(tiempoTransicion!=0){tiempoTransicion+=time - tiempoentrandofuncion;}
  }
  
  
  
  
  //WalkingEngine
  int theta[6];
  
  
  void WalkingEngine() {
    DEBUG_PRINT("Entrando WalkingMachine /");
      tiempoentrandofuncion = millis();
    
    
    
    
    
  
  
  
  
     posLeftHip =   Fases[FaseActual].posMotores[0] + lambda*( Fases[FaseSig].posMotores[0]-Fases[FaseActual].posMotores[0]) ; 
     posLeftKnee=   Fases[FaseActual].posMotores[1] + lambda*( Fases[FaseSig].posMotores[1]-Fases[FaseActual].posMotores[1]) ; //nroFases -1 = ultimo 
     posLeftAnkle = Fases[FaseActual].posMotores[2] + lambda*( Fases[FaseSig].posMotores[2]-Fases[FaseActual].posMotores[2]) ;
     posRightHip=   Fases[FaseActual].posMotores[3] + lambda*( Fases[FaseSig].posMotores[3]-Fases[FaseActual].posMotores[3]) ;
     posRightKnee = Fases[FaseActual].posMotores[4] + lambda*( Fases[FaseSig].posMotores[4]-Fases[FaseActual].posMotores[4]) ;   
     posRightAnkle =Fases[FaseActual].posMotores[5] + lambda*( Fases[FaseSig].posMotores[5]-Fases[FaseActual].posMotores[5]) ;

  
 
  
    theta[0]= posLeftHip;
    theta[1]= posLeftKnee;
    theta[2]=posLeftAnkle;
    theta[3]=posRightHip;
    theta[4]=posRightKnee;
    theta[5]=posRightAnkle;
    
     DEBUG_PRINT("Saliendo WalkingMachine/ t: ");
    tiemposaliendofuncion = millis();
    tiempociclo += tiemposaliendofuncion - tiempoentrandofuncion;
    DEBUG_PRINTLN(tiemposaliendofuncion - tiempoentrandofuncion);  
    if(tiempoTransicion!=0){tiempoTransicion+=tiemposaliendofuncion - tiempoentrandofuncion;}
}

void FallManager() {
 
 
 
  
}





void AngulosServo() {
   // cambiar dps por theta o por algun mecanismo
    leftHipServo.write(posLeftHip);
    leftKneeServo.write(posLeftKnee);
    leftAnkleServo.write(posLeftAnkle);
    rightHipServo.write(posRightHip);
    rightKneeServo.write(posRightKnee);
    rightAnkleServo.write(posRightAnkle); 
    DEBUG_PRINT( " LeftHip: ");
    DEBUG_PRINT(posLeftHip);
    DEBUG_PRINT(" LeftKnee: ");
    DEBUG_PRINT(posLeftKnee);
    DEBUG_PRINT(" LeftAnkle: ");
    DEBUG_PRINT(posLeftAnkle);
    DEBUG_PRINT(" RightHip: ");
    DEBUG_PRINT(posRightHip);
    DEBUG_PRINT(" RightKnee: ");
    DEBUG_PRINT( posRightKnee);
    DEBUG_PRINT(" RightAnkle: ");
    DEBUG_PRINTLN(posRightAnkle);
    
}


void loop() {
  SensorFilter();
  RX();
  //PhaseManager
 FaseManager();
  WSM();
  WalkingEngine();
  //FallManager();
  AngulosServo();
  
  
}
