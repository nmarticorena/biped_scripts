#include <Servo.h>     
Servo leftHipServo; //0
Servo leftKneeServo; // 1
Servo leftAnkleServo; // 2
Servo rightHipServo; // 3
Servo rightKneeServo; //4
Servo rightAnkleServo; // 5
int nroFase;
void(* resetFunc) (void) = 0; //declare reset function @ address 0





struct Phase 
{ 
  unsigned long duracion;
  int posMotores[6];
  int  tipo ;  // 1 lineal; 2 acelerado; 3 desacelerado ;4 rapido extremos lento almedio ; 5: 4 alrevez

};





int estadoMercurio;
int pinMercurio;

void girarizq (int grados) {
  // empezar la rutina qla para que gire, la variable grados indica que tan inclinao tiene quen etsar el pie respecto al piso, mientras mas inclinado, mas gira
// para que gire a la izquierda tiene levantar el pie derecho , inclinarlo y volverlo a posicionar al piso, asi , queda en posicion0, pero girado.  

  int posLeftHip; 
  int posLeftKnee;
  int posLeftAnkle;
  int posRightHip;
  int posRightKnee;
  int posRightAnkle;

  //PARTO EN FASE 1
  //PASO A FASE 2 CON UN ANKLE RIGHT MODIFICADO
  posLeftHip=92;
  posLeftKnee=123;
  posLeftAnkle=98;//
  posRightHip=93;
  posRightKnee=91;
  posRightAnkle=104;//EL QUE HACE QUE GIRE
  
  while (grados > 0){




    
  }//while

  
} //giraizq
//// !!!!!!!!!!!!!!!!!!!!!! HAY QUE HACER QUE GIRE MIENTRA CAMINE Y ADEMAS QUE GIRE RESPECT A UN PTO (APROX)







void girader (int grados) {
  // para que gire a la derecha se tiene que levantar el pie izquierdo, inclinarlo respecto al piso
  int posLeftHip;
  int posLeftKnee;
  int posLeftAnkle;
  int posRightHip;
  int posRightKnee;
  int posRightAnkle;

 while (grados > 0) {



  
 } // while



} // girarder
























unsigned long d;
float t;
const int mosfitPin=7;
int mosfitState = HIGH;
int k = 0;
// Servos

//int nroMotores=6;
int nroFases =7;

int posLeftHip;
int posLeftKnee;
int posLeftAnkle;
int posRightHip;
int posRightKnee;
int posRightAnkle;

boolean Todo_esta_bien = true;


//int nroFase;

Phase fase0;  
Phase fase1;
Phase fase2;
Phase fase3;
Phase fase4;
Phase fase5;
Phase fase6;

unsigned long time;
unsigned long t0;
//unsigned long dif;
float dif;

Phase Fases[7];

void setup(){
  digitalWrite(mosfitPin,HIGH); 
  pinMode(pinMercurio, INPUT);          //interruptor de mercurio
  Serial.begin(9600);
  pinMode(mosfitPin,OUTPUT);
  //const int nroFases= 2;
  leftHipServo.attach(11);
  leftKneeServo.attach(10);
  leftAnkleServo.attach(9);
  rightHipServo.attach(6);
  rightKneeServo.attach(5);
  rightAnkleServo.attach(3);



  //fase0
  fase0.duracion=4000; //milisegundos
  /*posLeftHip=105;
  posLeftKnee=112;
  posLeftAnkle=93;
  posRightHip=97;
  posRightKnee=91;
  posRightAnkle=97;
  */
  posLeftHip=106;
  posLeftKnee=113;//112
  posLeftAnkle=93;
  posRightHip=97;
  posRightKnee=87;//91
  posRightAnkle=97;
  
  fase0.posMotores[0]=posLeftHip;
  fase0.posMotores[1]=posLeftKnee;
  fase0.posMotores[2]=posLeftAnkle;
  fase0.posMotores[3]=posRightHip;
  fase0.posMotores[4]=posRightKnee;
  fase0.posMotores[5]=posRightAnkle;

  fase0.tipo=4;

  //fase0.posMotores={posLeftHip,posLeftKnee,posLeftAnkle,posRightHip,posRightKnee,posRightAnkle} ;
  Fases[0].duracion=2500;
  Fases[0].posMotores[0]=posLeftHip;
  Fases[0].posMotores[1]=posLeftKnee;
  Fases[0].posMotores[2]=posLeftAnkle;
  Fases[0].posMotores[3]=posRightHip;
  Fases[0].posMotores[4]=posRightKnee;
  Fases[0].posMotores[5]=posRightAnkle;

  Fases[0].tipo=4;



  //fase 1
  fase1.duracion=3000;
  posLeftHip=88;
  posLeftKnee=112;
  posLeftAnkle=70; //quizas 77
  posRightHip=74;
  posRightKnee=112;
  posRightAnkle=75;
  fase1.posMotores[0]=posLeftHip;
  fase1.posMotores[1]=posLeftKnee;
  fase1.posMotores[2]=posLeftAnkle;
  fase1.posMotores[3]=posRightHip;
  fase1.posMotores[4]=posRightKnee;
  fase1.posMotores[5]=posRightAnkle;

  fase1.tipo=4;

  //fase1.posMotoes={posLeftHip,posLeftKnee,posLeftAnkle,posRightHip,posRightKnee,posRightAnkle} ;


  //fase 1
  posLeftHip=88;
  posLeftKnee=113;//112
  posLeftAnkle=70; 
  posRightHip=74;
  posRightKnee=116;//112
  posRightAnkle=75;
  Fases[1].duracion=2000;//2K
  Fases[1].posMotores[0]=posLeftHip;
  Fases[1].posMotores[1]=posLeftKnee;
  Fases[1].posMotores[2]=posLeftAnkle;
  Fases[1].posMotores[3]=posRightHip;
  Fases[1].posMotores[4]=posRightKnee;
  Fases[1].posMotores[5]=posRightAnkle;

  Fases[1].tipo=4;


  //fase2
  Fases[2].duracion=2000;//2K //milisegundos
  posLeftHip=92;
  posLeftKnee=123;
  posLeftAnkle=100;//98
  posRightHip=93;
  posRightKnee=91;
  posRightAnkle=107;//104
  Fases[2].posMotores[0]=posLeftHip;
  Fases[2].posMotores[1]=posLeftKnee;
  Fases[2].posMotores[2]=posLeftAnkle;
  Fases[2].posMotores[3]=posRightHip;
  Fases[2].posMotores[4]=posRightKnee;
  Fases[2].posMotores[5]=posRightAnkle;

  Fases[2].tipo=4;  


  //fase3
  Fases[3].duracion=2500;//2.5K //milisegundos
  posLeftHip=92;
  posLeftKnee=123;
  posLeftAnkle=117;
  posRightHip=93;
  posRightKnee=91;
  posRightAnkle=120;
  Fases[3].posMotores[0]=posLeftHip;
  Fases[3].posMotores[1]=posLeftKnee;
  Fases[3].posMotores[2]=posLeftAnkle;
  Fases[3].posMotores[3]=posRightHip;
  Fases[3].posMotores[4]=posRightKnee;
  Fases[3].posMotores[5]=posRightAnkle;

  Fases[3].tipo=4;  


  //fase4
  Fases[4].duracion=2000;//2.5K //milisegundos
  posLeftHip=138;
  posLeftKnee=74;
  posLeftAnkle=111;
  posRightHip=104;
  posRightKnee=91;
  posRightAnkle=118;
  Fases[4].posMotores[0]=posLeftHip;
  Fases[4].posMotores[1]=posLeftKnee;
  Fases[4].posMotores[2]=posLeftAnkle;
  Fases[4].posMotores[3]=posRightHip;
  Fases[4].posMotores[4]=posRightKnee;
  Fases[4].posMotores[5]=posRightAnkle;

  Fases[4].tipo=4;  



  //fase5
  Fases[5].duracion=2000;//2.5K //milisegundos
  posLeftHip=138;
  posLeftKnee=98;
  posLeftAnkle=101;
  posRightHip=103;
  posRightKnee=69;
  posRightAnkle=102;
  Fases[5].posMotores[0]=posLeftHip;
  Fases[5].posMotores[1]=posLeftKnee;
  Fases[5].posMotores[2]=posLeftAnkle;
  Fases[5].posMotores[3]=posRightHip;
  Fases[5].posMotores[4]=posRightKnee;
  Fases[5].posMotores[5]=posRightAnkle;

  Fases[5].tipo=4;  



  //fase6
  Fases[6].duracion=2000;//2.5K? //milisegundos
  posLeftHip=138;
  posLeftKnee=101;
  posLeftAnkle=70;
  posRightHip=103; //?????????
  posRightKnee=69;
  posRightAnkle=75;//???????????
  Fases[6].posMotores[0]=posLeftHip;
  Fases[6].posMotores[1]=posLeftKnee;
  Fases[6].posMotores[2]=posLeftAnkle;
  Fases[6].posMotores[3]=posRightHip;
  Fases[6].posMotores[4]=posRightKnee;
  Fases[6].posMotores[5]=posRightAnkle;

  Fases[6].tipo=4;  


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
  nroFase=1;
}



void update (int tiempo) {   //REEMPLAZA A TODOS LOS DELAY
  uint32_t tinicial = millis();
  while (millis() - tinicial < tiempo) {
    int estadoMercurio = digitalRead(13); 
    if (estadoMercurio == 0) { 
        leftHipServo.detach();
        leftKneeServo.detach();
        leftAnkleServo.detach();
        rightHipServo.detach();
        rightKneeServo.detach();
        rightAnkleServo.detach();
    while (true){
    estadoMercurio = digitalRead(13);
     if (estadoMercurio == 1) { 
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
        nroFase=1;
        resetFunc(); 
          break;
          
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
  }
}

void loop()
{
   //a = mosfitState
  
  update(100); // LO CAMBIE, ANTES ESTABA EN 300
  //delay(1000);
  Serial.print("ANT posmotores ");
  Serial.print(fase0.posMotores[0]);
  Serial.print("  duracion");
  Serial.print(fase0.duracion);
  Serial.print("  tipo: ");
  Serial.print(fase0.tipo);
  Serial.println("  espacio   ");

  Serial.print("NEW posmotores "); 
  Serial.print(Fases[6].posMotores[0]);
  Serial.print(Fases[6].posMotores[1]);
  Serial.print(Fases[6].posMotores[2]);
  Serial.print(Fases[6].posMotores[3]);
  Serial.print(Fases[6].posMotores[4]);
  Serial.print(Fases[6].posMotores[5]);
  Serial.print(Fases[6].posMotores[6]);
  Serial.print("  duracion");
  Serial.print(Fases[6].duracion);
  Serial.print("  tipo: ");
  Serial.print(Fases[6].tipo);
  Serial.println("  espacio 2   ");

  //delay(2000);
  time=millis();
  t0=millis();
  //Serial.print("tiempoinicial");
  //Serial.println(t0);
  Todo_esta_bien=true;
  Serial.print("nrofase");
  Serial.println(nroFase);
  while( Todo_esta_bien ){
    //Serial.println("ENTREEEEE al WHILE");
    //if (Fases[nroFase].tipo==100){//lineal
    // Serial.println("VOLVI AENTRAR ");
     //time=millis();
     //d=Fases[nroFase].duracion;
     //Serial.print("duracion: ");
     //Serial.println(d);
     //dif= time-t0;
     //Serial.print("dif: ");
     //Serial.println(dif);
     //t= 1-cos( dif/d*PI/2 );
     //Serial.print(" t ");
     //Serial.println(t); } 
    //Serial.print("nrofase/nroFases");
    //Serial.print(nroFase);
    //Serial.print("/");
    //Serial.println(nroFases);
    if (nroFase != (nroFases - 1) && nroFase != 0 && nroFase != 1   ){ 

      if (Fases[nroFase].tipo==4){//acelerado
        Serial.print("ENTRE A LA FASE (dealmedio) ");
        Serial.println(nroFase);
        time=millis();
        d=Fases[nroFase].duracion;
        Serial.print("duracion: ");
        Serial.println(d);
        dif= time-t0;
        //Serial.print("dif: ");
        Serial.print("Tiempo: ");
        Serial.println(dif);
        t= 1-cos( dif/d*PI/2 );
        Serial.print(" t ");
        Serial.println(t); 
        update(5);
      } 

      posLeftHip =   Fases[nroFase-1].posMotores[0] + t*( Fases[nroFase].posMotores[0]-Fases[nroFase-1].posMotores[0]) ; 
      posLeftKnee=   Fases[nroFase-1].posMotores[1] + t*( Fases[nroFase].posMotores[1]-Fases[nroFase-1].posMotores[1]) ; //nroFases -1 = ultimo 
      posLeftAnkle = Fases[nroFase-1].posMotores[2] + t*( Fases[nroFase].posMotores[2]-Fases[nroFase-1].posMotores[2]) ;
      posRightHip=   Fases[nroFase-1].posMotores[3] + t*( Fases[nroFase].posMotores[3]-Fases[nroFase-1].posMotores[3]) ;
      posRightKnee = Fases[nroFase-1].posMotores[4] + t*( Fases[nroFase].posMotores[4]-Fases[nroFase-1].posMotores[4]) ;   
      posRightAnkle =Fases[nroFase-1].posMotores[5] + t*( Fases[nroFase].posMotores[5]-Fases[nroFase-1].posMotores[5]) ;

      leftHipServo.write(posLeftHip);
      update(5);
      leftKneeServo.write(posLeftKnee);
      leftAnkleServo.write(posLeftAnkle);
      update(5);
      rightHipServo.write(posRightHip);
      rightKneeServo.write(posRightKnee);
      update(5);
      rightAnkleServo.write(posRightAnkle); 

      //Serial.print("Tiempo :");
      //Serial.print(dif);//-t0);
      Serial.print( " LeftHip: ");
      Serial.print(posLeftHip);
      Serial.print(" LeftKnee: ");
      Serial.print(posLeftKnee);
      Serial.print(" LeftAnkle: ");
      Serial.print(posLeftAnkle);
      Serial.print(" RightHip: ");
      Serial.print(posRightHip);
      Serial.print(" RightKnee: ");
      Serial.print( posRightKnee);
      Serial.print(" RightAnkle: ");
      Serial.println(posRightAnkle);

      if(t>=1){
        nroFase=nroFase+1;
        Todo_esta_bien=false;
      }
    }// if grande
    else if (nroFase == 1 && k ==0){
     if (Fases[nroFase].tipo==4){//acelerado
        Serial.print("ENTRE A LA FASE (dealmedio) ");
        Serial.println(nroFase);
        time=millis();
        d=Fases[nroFase].duracion;
        Serial.print("duracion: ");
        Serial.println(d);
        dif= time-t0;
        //Serial.print("dif: ");
        Serial.print("Tiempo: ");
        Serial.println(dif);
        t= 1-cos( dif/d*PI/2 );
        Serial.print(" t ");
        Serial.println(t); 
      } 

      posLeftHip =   Fases[0].posMotores[0] + t*( Fases[nroFase].posMotores[0]-Fases[0].posMotores[0]) ; 
      posLeftKnee=   Fases[0].posMotores[1] + t*( Fases[nroFase].posMotores[1]-Fases[0].posMotores[1]) ; //nroFases -1 = ultimo 
      posLeftAnkle = Fases[0].posMotores[2] + t*( Fases[nroFase].posMotores[2]-Fases[0].posMotores[2]) ;
      posRightHip=   Fases[0].posMotores[3] + t*( Fases[nroFase].posMotores[3]-Fases[0].posMotores[3]) ;
      posRightKnee = Fases[0].posMotores[4] + t*( Fases[nroFase].posMotores[4]-Fases[0].posMotores[4]) ;   
      posRightAnkle =Fases[0].posMotores[5] + t*( Fases[nroFase].posMotores[5]-Fases[0].posMotores[5]) ;

      leftHipServo.write(posLeftHip);
      leftKneeServo.write(posLeftKnee);
      leftAnkleServo.write(posLeftAnkle);
      rightHipServo.write(posRightHip);
      rightKneeServo.write(posRightKnee);
      rightAnkleServo.write(posRightAnkle); 

      //Serial.print("Tiempo :");
      //Serial.print(dif);//-t0);
      Serial.print( " LeftHip: ");
      Serial.print(posLeftHip);
      Serial.print(" LeftKnee: ");
      Serial.print(posLeftKnee);
      Serial.print(" LeftAnkle: ");
      Serial.print(posLeftAnkle);
      Serial.print(" RightHip: ");
      Serial.print(posRightHip);
      Serial.print(" RightKnee: ");
      Serial.print( posRightKnee);
      Serial.print(" RightAnkle: ");
      Serial.println(posRightAnkle);

      if(t>=1){
        nroFase=nroFase+1;
        Todo_esta_bien=false;
      }
      
      
    }// elseif 1 primera pasada
    
   else if (nroFase == 1 && k >0){
     if (Fases[nroFase].tipo==4){//acelerado
        Serial.print("ENTRE A LA FASE (dealmedio) ");
        Serial.println(nroFase);
        time=millis();
        d=Fases[nroFase].duracion;
        Serial.print("duracion: ");
        Serial.println(d);
        dif= time-t0;
        //Serial.print("dif: ");
        Serial.print("Tiempo: ");
        Serial.println(dif);
        t= 1-cos( dif/d*PI/2 );
        Serial.print(" t ");
        Serial.println(t); 
      } 

      posLeftHip =   Fases[6].posMotores[0] + t*( Fases[nroFase].posMotores[0]-Fases[6].posMotores[0]) ; 
      posLeftKnee=   Fases[6].posMotores[1] + t*( Fases[nroFase].posMotores[1]-Fases[6].posMotores[1]) ; //nroFases -1 = ultimo 
      posLeftAnkle = Fases[6].posMotores[2] + t*( Fases[nroFase].posMotores[2]-Fases[6].posMotores[2]) ;
      posRightHip=   Fases[6].posMotores[3] + t*( Fases[nroFase].posMotores[3]-Fases[6].posMotores[3]) ;
      posRightKnee = Fases[6].posMotores[4] + t*( Fases[nroFase].posMotores[4]-Fases[6].posMotores[4]) ;   
      posRightAnkle =Fases[6].posMotores[5] + t*( Fases[nroFase].posMotores[5]-Fases[6].posMotores[5]) ;

      leftHipServo.write(posLeftHip);
      leftKneeServo.write(posLeftKnee);
      leftAnkleServo.write(posLeftAnkle);
      rightHipServo.write(posRightHip);
      rightKneeServo.write(posRightKnee);
      rightAnkleServo.write(posRightAnkle); 

      //Serial.print("Tiempo :");
      //Serial.print(dif);//-t0);
      Serial.print( " LeftHip: ");
      Serial.print(posLeftHip);
      Serial.print(" LeftKnee: ");
      Serial.print(posLeftKnee);
      Serial.print(" LeftAnkle: ");
      Serial.print(posLeftAnkle);
      Serial.print(" RightHip: ");
      Serial.print(posRightHip);
      Serial.print(" RightKnee: ");
      Serial.print( posRightKnee);
      Serial.print(" RightAnkle: ");
      Serial.println(posRightAnkle);

      if(t>=1){
        nroFase=nroFase+1;
        Todo_esta_bien=false;
      }
   }// esleif 1 para casos posteriore
  
    else if (nroFase == 0 ){

      if (Fases[nroFase].tipo==4){//acelerado
        Serial.println("ENTRE A LA FASE 0 ");
        time=millis();
        d=Fases[nroFase].duracion;
        Serial.print("duracion: ");
        Serial.println(d);
        dif= time-t0;
        //Serial.print("dif: ");
        Serial.print("Tiempo: ");
        Serial.println(dif);
        t= 1-cos( dif/d*PI/2 );
        Serial.print(" t ");
        Serial.println(t); 
      } 

      posLeftHip =   Fases[nroFases-1].posMotores[0] + t*( Fases[nroFase].posMotores[0]-Fases[nroFases-1].posMotores[0]) ; 
      posLeftKnee=   Fases[nroFases-1].posMotores[1] + t*( Fases[nroFase].posMotores[1]-Fases[nroFases-1].posMotores[1]) ; //nroFases -1 = ultimo 
      posLeftAnkle = Fases[nroFases-1].posMotores[2] + t*( Fases[nroFase].posMotores[2]-Fases[nroFases-1].posMotores[2]) ;
      posRightHip=   Fases[nroFases-1].posMotores[3] + t*( Fases[nroFase].posMotores[3]-Fases[nroFases-1].posMotores[3]) ;
      posRightKnee = Fases[nroFases-1].posMotores[4] + t*( Fases[nroFase].posMotores[4]-Fases[nroFases-1].posMotores[4]) ;   
      posRightAnkle =Fases[nroFases-1].posMotores[5] + t*( Fases[nroFase].posMotores[5]-Fases[nroFases-1].posMotores[5]) ;

      
      
      leftHipServo.write(posLeftHip);
      leftKneeServo.write(posLeftKnee);
      leftAnkleServo.write(posLeftAnkle);
      rightHipServo.write(posRightHip);
      rightKneeServo.write(posRightKnee);
      rightAnkleServo.write(posRightAnkle); 

      //Serial.print("Tiempo :");
      //Serial.print(dif);//-t0);
      Serial.print( " LeftHip: ");
      Serial.print(posLeftHip);
      Serial.print(" LeftKnee: ");
      Serial.print(posLeftKnee);
      Serial.print(" LeftAnkle: ");
      Serial.print(posLeftAnkle);
      Serial.print(" RightHip: ");
      Serial.print(posRightHip);
      Serial.print(" RightKnee: ");
      Serial.print( posRightKnee);
      Serial.print(" RightAnkle: ");
      Serial.println(posRightAnkle);

      if(t>=1){
        nroFase=nroFase+1;
        Todo_esta_bien=false;
      }
    }//para nrofase ==0

    else if (nroFase == nroFases - 1){

      if (Fases[nroFase].tipo==4){//acelerado
        Serial.print("ENTRE A LA FASE ULTIMA (6) ");
        Serial.println(nroFase);
        time=millis();
        d=Fases[nroFase].duracion;
        Serial.print("duracion: ");
        Serial.println(d);
        dif= time-t0;
        //Serial.print("dif: ");
        Serial.print("Tiempo: "); 
        Serial.println(dif);
        t= 1-cos( dif/d*PI/2 );
        Serial.print(" t ");
        Serial.println(t); 
      } 

      posLeftHip =   Fases[nroFase-1].posMotores[0] + t*( Fases[nroFase].posMotores[0]-Fases[nroFase-1].posMotores[0]) ; 
      posLeftKnee=   Fases[nroFase-1].posMotores[1] + t*( Fases[nroFase].posMotores[1]-Fases[nroFase-1].posMotores[1]) ; //nroFases -1 = ultimo 
      posLeftAnkle = Fases[nroFase-1].posMotores[2] + t*( Fases[nroFase].posMotores[2]-Fases[nroFase-1].posMotores[2]) ;
      posRightHip=   Fases[nroFase-1].posMotores[3] + t*( Fases[nroFase].posMotores[3]-Fases[nroFase-1].posMotores[3]) ;
      posRightKnee = Fases[nroFase-1].posMotores[4] + t*( Fases[nroFase].posMotores[4]-Fases[nroFase-1].posMotores[4]) ;   
      posRightAnkle =Fases[nroFase-1].posMotores[5] + t*( Fases[nroFase].posMotores[5]-Fases[nroFase-1].posMotores[5]) ;

      leftHipServo.write(posLeftHip);
      leftKneeServo.write(posLeftKnee);
      leftAnkleServo.write(posLeftAnkle);
      rightHipServo.write(posRightHip);
      rightKneeServo.write(posRightKnee);
      rightAnkleServo.write(posRightAnkle); 

      //Serial.print("Tiempo :");
      //Serial.print(dif);//-t0);
      Serial.print( " LeftHip: ");
      Serial.print(posLeftHip);
      Serial.print(" LeftKnee: ");
      Serial.print(posLeftKnee);
      Serial.print(" LeftAnkle: ");
      Serial.print(posLeftAnkle);
      Serial.print(" RightHip: ");
      Serial.print(posRightHip);
      Serial.print(" RightKnee: ");
      Serial.print( posRightKnee);
      Serial.print(" RightAnkle: ");
      Serial.println(posRightAnkle);

      if(t>=1){
        nroFase=1;
        Todo_esta_bien=false;
        k++;
      }
    }//para nrofase == nroFase - 1   


  }//while


} //loop



