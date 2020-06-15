 int mango[3]={2,8,5};//2-->A,5-->D,8-->E
  int arr[10][7]={{2,3,4,5,6,7,0},{3,4,0,0,0,0,0},{2,3,6,5,8,0,0},{2,3,4,5,8,0,0,},{3,4,7,8,0,0,0},{2,4,5,7,8,0,0},{2,4,5,6,7,8,0},{2,3,4,0,0,0,0},{2,3,4,5,6,7,8},{2,3,4,5,7,8,0}};
 int digit[4],num,select,high=0,highd4=0,highd3=0,highd2=0,p=1,highd1=mango[p],score=0;
 boolean game=true,pause=false;
void setup() {
  pinMode(A2,INPUT);
  for(int i=2;i<=13;i++)
  {
    pinMode(i,OUTPUT);
    }
Serial.begin(9600);
}
int level=analogRead(A2);
void d4()
 {
  digitalWrite(13,HIGH);
  select=random(0,3);
  high=mango[select];  
  digitalWrite(high,HIGH);
  
 }
void d3()
{
  highd3=d4;
    digitalWrite(12,HIGH);
    digitalWrite(highd3,HIGH);      
    return highd3; 
  }
void d2()
{
  highd2=d3;
    digitalWrite(11,HIGH);
    digitalWrite(highd2,HIGH);
    return highd2;
}
void remove()
{
  for(int i=2;i<=13;i++)
  {
    digitalWrite(i,LOW);
    }
  }
void loop() {
if(game && !pause)
{
   select=random(0,3);
  high=mango[select]; 
  for(int x=0;x<15000;x++)
  {
     digitalWrite(10,HIGH);
    digitalWrite(highd1,HIGH);
    
    digitalWrite(10,LOW);
    digitalWrite(highd1,LOW);
    
     digitalWrite(11,HIGH);
    digitalWrite(highd2,HIGH);
    
    digitalWrite(11,LOW);
    digitalWrite(highd2,LOW); 
    
     digitalWrite(12,HIGH);
    digitalWrite(highd3,HIGH); 
    
    digitalWrite(12,LOW);  
    digitalWrite(highd3,LOW);  


     digitalWrite(13,HIGH);  
  digitalWrite(highd4,HIGH);
  
  digitalWrite(13,LOW);
  digitalWrite(highd4,LOW); 
  
}

/*if(analogRead(A3)<20 && highd1!=8)
  {
    highd1=mango[p++];     
    
  }
  else if( analogRead(A3)>20&& highd1!=2)
  {
    highd1=mango[p--];  
  
  }
*/
 if(analogRead(A3)>=0 && analogRead(A3)<20 && highd1<4)
  {
    highd1=mango[p++];    
      
  }
  else if(analogRead(A3)>=800 && analogRead(A3)<830&& highd1>2)
  {
    highd1=mango[p--];
  }
  else if(analogRead(A3)>=681 && analogRead(A3)<686 && highd1>2)
  {
    pause=true;
  }
     
  
  
 /*  if(analogRead(A3)<200)
  {
    highd1=5;    
   
  }
  else if(analogRead(A3)>200 && analogRead(A3)<800)
  {
    highd1=2;
     
  }
   else if(analogRead(A3)>=800)
  {
    highd1=8;
    
  }*/
   digitalWrite(highd1,HIGH); 
  delay(2);
if(highd2!=0 && highd2!=highd1)
{
  Serial.println("GAME OVER");
  Serial.print("Score =");
  Serial.println(score);
  game=false;}
  
  else if(highd2!=0 && highd2==highd1)
  {
    score++;
    }
highd2=highd3;
highd3=highd4;
highd4=high;}
if(!game)
{
  int pscore=score;
  Serial.println(score);
  for (int i = 0; i<4; i++)
{
digit[i] = pscore %10;
pscore = pscore / 10;}

          digitalWrite(13,HIGH);
          for(int j=0;j<7;j++)
            {
              if(arr[digit[0]][j]!=0)
              {
                digitalWrite(arr[digit[3]][j],HIGH);
                }
                }
            remove();
            digitalWrite(12,HIGH);
          for(int j=0;j<7;j++)
            {
              if(arr[digit[1]][j]!=0)
              {
                digitalWrite(arr[digit[2]][j],HIGH);
                }
                }
            remove();
            digitalWrite(11,HIGH);
            for(int j=0;j<7;j++)
            {
              if(arr[digit[2]][j]!=0)
              {
                digitalWrite(arr[digit[1]][j],HIGH);
                }
                }
            remove();
            digitalWrite(10,HIGH);
            for(int j=0;j<7;j++)
            {
              if(arr[digit[3]][j]!=0)
              {
                digitalWrite(arr[digit[0]][j],HIGH);
                }
                }
            remove();
  
}
if(game && pause)
{
  for(int x=0;x<15000;x++)
  {
     digitalWrite(10,HIGH);
    digitalWrite(highd1,HIGH);
    
    digitalWrite(10,LOW);
    digitalWrite(highd1,LOW);
    
     digitalWrite(11,HIGH);
    digitalWrite(highd2,HIGH);
    
    digitalWrite(11,LOW);
    digitalWrite(highd2,LOW); 
    
     digitalWrite(12,HIGH);
    digitalWrite(highd3,HIGH); 
    
    digitalWrite(12,LOW);  
    digitalWrite(highd3,LOW);  


     digitalWrite(13,HIGH);  
  digitalWrite(highd4,HIGH);
  
  digitalWrite(13,LOW);
  digitalWrite(highd4,LOW); 
  
}
}
 if(analogRead(A3)>=681 && analogRead(A3)<686 && highd1>2)
  {
    pause=false;
  }

}
