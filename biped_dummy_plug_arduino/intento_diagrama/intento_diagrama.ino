
#include <Servo.h>
#define LARGOLISTA 20


Servo leftHipServo; //0
Servo leftKneeServo; // 1
Servo leftAnkleServo; // 2
Servo rightHipServo; // 3
Servo rightKneeServo; //4
Servo rightAnkleServo; // 5

int estadoMercurio;


void(* resetFunc) (void) = 0; //declare reset function @ address 0
int DatosMercurio[LARGOLISTA];
int SumMercurio=0;

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

Phase Fases[9];

unsigned long tiempoentrandofuncion;
unsigned long tiemposaliendofuncion;
unsigned long tiempociclo;
unsigned long tiempoTransicion=0;

const int mosfitPin=7;
int mosfitState = HIGH;
int pinMercurio = 2;


void update (int tiempo) {   //REEMPLAZA A TODOS LOS DELAY
 Serial.print("entrando a la funcion update / ");
  tiempoentrandofuncion = millis();
  
  uint32_t tinicial = millis();
  while (millis() - tinicial < tiempo) {
    estadoMercurio=digitalRead(13);
    if (estadoMercurio==0){
      Serial.println("CREO QUE ME CAIIIIIIIIIIIIIIIIII");
      for(int j=0;j<LARGOLISTA;j+=1){
         DatosMercurio[j]=estadoMercurio;
         estadoMercurio=digitalRead(13);
         delay(10);
      }
      for(int j=0;j<LARGOLISTA;j+=1){
         SumMercurio+=DatosMercurio[j];
      }
      if (SumMercurio<15){//estadoMercurio == 0) { 
          Serial.println("SI ME CAIIIIIIIIIIIIIIIIIIIIIIIIII");
          leftHipServo.detach();
          leftKneeServo.detach();
          leftAnkleServo.detach();
          rightHipServo.detach();
          rightKneeServo.detach();
          rightAnkleServo.detach();
      while (true){
      estadoMercurio = digitalRead(13);
      Serial.println("Levantame Porfavor");
      for(int j=0;j<LARGOLISTA;j+=1){
         DatosMercurio[j]=estadoMercurio;
         estadoMercurio=digitalRead(13);
         delay(10);
      }
      for(int j=0;j<LARGOLISTA;j+=1){
         SumMercurio+=DatosMercurio[j];
      }
      if (SumMercurio==20) { 
          Serial.println("Gracias *.*");
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
void setup() {
  
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
leftHipServo.attach(11);
  leftKneeServo.attach(10);
  leftAnkleServo.attach(9);
  rightHipServo.attach(6);
  rightKneeServo.attach(5);
  rightAnkleServo.attach(3);  
  digitalWrite(mosfitPin,HIGH); 
  pinMode(pinMercurio, INPUT);          //interruptor de mercurio
  
  
  posLeftHip=106;
  posLeftKnee=113;
  posLeftAnkle=93;//93
  posRightHip=97;
  posRightKnee=87;
  posRightAnkle=97;//97
  
  Fases[0].duracion=2500;
  Fases[0].posMotores[0]=posLeftHip;
  Fases[0].posMotores[1]=posLeftKnee;
  Fases[0].posMotores[2]=posLeftAnkle;
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
  FaseSig=1;
  
  
  
  
  
}













float aceleracion[3]={0,0,0};
int acelPinx0 = 0;
int acelPiny1 = 1;
int acelPinz2 = 2;

void SensorFilter() {
       Serial.print("Entrando a la funcion SensorFilter / ");
 tiempoentrandofuncion = millis();

  //retornar llso valores del acelerometro en cada eje
  float ejex = analogRead(A0);
  float ejey = analogRead(A1);
  float ejez = analogRead(A2);
  //ejex = Vtofloat(ejex);
  //ejey = Vtofloat(ejey);
  //ejez = Vtofloat(ejez);
  
  //hacer las trasnforamaciones de foltaje
  
  aceleracion[0] = ejex;
  aceleracion[1] = ejey;
  aceleracion[2] = ejez;
    Serial.print("tiempo que estuve en la funcion SENSORFILTER: ");
    tiemposaliendofuncion = millis();
    tiempociclo += tiemposaliendofuncion - tiempoentrandofuncion;
    Serial.println(tiemposaliendofuncion - tiempoentrandofuncion);  
    if(tiempoTransicion!=0){tiempoTransicion+=tiemposaliendofuncion - tiempoentrandofuncion;}
}





char valByte = '5'; 
int accionBlue;


void RX() {

    Serial.print("Entrando a la funcion RX / ");
    tiempoentrandofuncion = millis();
    
 if (Serial.available()){
    
   valByte = Serial.read();
 } 
  
  if ( valByte = '0' ){
    //caminar recto
    accionBlue = 0;
  }
  
    if ( valByte = '1' ){
    //caminar recto
    accionBlue = 1;
  }
  
    if ( valByte = '2' ){
    //caminar recto
    accionBlue = 2;
  }
  
    if ( valByte = '3' ){
    //caminar recto
    accionBlue = 3;
  }


    Serial.print("tiempo que estuve en la funcion RX: ");
    tiemposaliendofuncion = millis();
    tiempociclo += tiemposaliendofuncion - tiempoentrandofuncion;
    Serial.println(tiemposaliendofuncion - tiempoentrandofuncion);  
   if(tiempoTransicion!=0){tiempoTransicion+=tiemposaliendofuncion - tiempoentrandofuncion;}
}

unsigned long t0;
float dif;
int durac;
int t;
int d;
float lambda;


int accionBluett;
unsigned long time;

unsigned long tiempo;
unsigned long tiempofase;
boolean termino; 


float calcularLambda(unsigned long tiempo,unsigned long tiempotranscurrido){
 /*
    Serial.print("Entrando a la funcion calcularLambda / ");
    tiempoentrandofuncion = millis(); 
 */
  //float lambda;
   time=millis();
   durac=Fases[FaseSig].duracion;
   Serial.print("estoy en la Fase/FaseActual: ");
   Serial.print(FaseActual);
   Serial.print(" ,    estoy yendo a la Fase/FaseSig: ");
   Serial.print(FaseSig);
   //Serial.println("duracion de la fase: ");
   //Serial.println(durac);++
   dif= time-tiempotranscurrido;
   //Serial.print("dif: ");para que ponerla ?>:c
  
   Serial.print("Tiempo transcurrido: ");//no se si sea necesaria ponerla
   Serial.println(dif);
  
   if (dif >= durac ) { //quiere decir que ya paso el tiempo que debe pasar en la duracion hacia la fase siguiente 
     lambda = 1;
   }  
   else{  
     lambda = 1-cos( dif/durac*PI/2 );
   }
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
void WSM (){
 
  Serial.print("Entrando a la funcion WSM /");
    tiempoentrandofuncion = millis();
 time =tiempoentrandofuncion;

   //usar accionBlue,   
 
 unsigned long tiempotransicion = tiempoTransicion;
 int faseactual =FaseActual;
 int fasesig = FaseSig;
 
 int duracioncambiofase = Fases[FaseSig].duracion;
 
 //preguntar si ya se termino de hacer el cambio de fase
 if ( tiempoTransicion >= duracioncambiofase ){
  termino = true; 
 }
  
  if (accionBlue== 1 ) {//Bluett
     //caminar recto
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
     if ( faseactual == 7 && fasesig==8 ){
      if(termino){FaseActual=FaseSig;FaseSig=3;tiempoTransicion=0;time=millis();}
      
       lambda = calcularLambda(tiempofase,tiempoTransicion);
     }
     
     //else if ( faseactual == 8){
      else{
       if(termino){FaseActual=FaseSig;FaseActual++;tiempoTransicion=0;time=millis();}
       
       lambda = calcularLambda(tiempofase,tiempoTransicion);
     }
     
  }//1
  
  
  else if (accionBlue == 2){//bluett
    //girar totalmente a la izq
    
    
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
     Serial.print("tiempo que estuve en la funcion WSM: ");
    tiemposaliendofuncion = millis();
    tiempociclo += tiemposaliendofuncion - tiempoentrandofuncion;
    Serial.println(tiemposaliendofuncion - tiempoentrandofuncion);  
    if(tiempoTransicion!=0){tiempoTransicion+=time - tiempoentrandofuncion;}
}




//WalkingEngine
int theta[6];


void WalkingEngine() {
  Serial.print("Entrando a la funcion WalkingMachine /");
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
    
     Serial.print("  ,  tiempo que estuve en la funcion WalkingMachine: ");
    tiemposaliendofuncion = millis();
    tiempociclo += tiemposaliendofuncion - tiempoentrandofuncion;
    Serial.println(tiemposaliendofuncion - tiempoentrandofuncion);  
    if(tiempoTransicion!=0){tiempoTransicion+=tiemposaliendofuncion - tiempoentrandofuncion;}
}

void FallManager() {
 
 
 
  
}








void loop() {
  SensorFilter();
  RX();
  WSM();
  WalkingEngine();
  //FallManager();
  //AngulosServo();
  
  
}
