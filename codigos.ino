#include <Servo.h>
Servo muslo_1;
Servo pant_1;
Servo muslo_2;
Servo pant_2;
Servo muslo_3;
Servo pant_3;
Servo muslo_4;
Servo pant_4;

#define boton 4

int reinicio = 0;

Servo muslos[] = { muslo_1 , muslo_2 , muslo_3 , muslo_4};
Servo pants[] = { pant_1 , pant_2 , pant_3 , pant_4 };  

int angulos_1[] = { 80, 0, 80, 0};
int angulos_2[] = { 0, 15, 0, 15};

int* angulos_if[] = {angulos_1, angulos_2};
int* angulos_else[] = {angulos_2, angulos_1};
int** angulos_todos[] = {angulos_if, angulos_else};


void setup() {
  // put your setup code here, to run once:
  muslo_1.attach(8);
  pant_1.attach(7);
  muslo_2.attach(3);
  pant_2.attach(2);
  muslo_3.attach(4);
  pant_3.attach(5);
  muslo_4.attach(9);
  pant_4.attach(6);
  pinMode(boton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( digitalRead(boton) == HIGH ){
    reinicio = 1;
  }else{
    reinicio = 0;
  }
  mover_pata(muslos, pants, angulos_todos, reinicio);  
  
  
}

void mover_pata(Servo* muslo, Servo* pant, int*** angulos_todos, int reset){
  if (muslo[0].read() == 0 and reset == 0){
    for (int i=0;i<=3;i++){
       muslo[i].write(  ((angulos_todos[0])[0])[i]  );
       pant[i].write(   ((angulos_todos[0])[1])[i]  );
       digital
    }
  }else{
    for (int i=0;i<=3;i++){
       muslo[i].write(  ((angulos_todos[1])[0])[i]  );
       pant[i].write(   ((angulos_todos[1])[1])[i]  );    
    }
  }
  if (reset == 1){
    for (int i=0;i<=3;i++){
       muslo[i].write(  ((angulos_todos[0])[0])[1]  );
       pant[i].write(  ((angulos_todos[0])[1])[1]  );    
    }
  }
delay(100);
}
