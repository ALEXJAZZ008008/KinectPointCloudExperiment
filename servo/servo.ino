#include <Servo.h>

Servo servo;

const int angle_start = 10;
const int angle_end = 170;
const int delay_amount_sync = 1000 / 30;
const int delay_amount_start = 1000;
const int delay_amount_process = 10;

int i = 0;
int time_elapsed = 0;

void setup()
{
  servo.attach(9);

  servo.write(angle_start);

  time_elapsed = 0;

  while(servo.read() != angle_start)
  {
    delay(delay_amount_process);

    time_elapsed += delay_amount_process;
  }

  delay(delay_amount_start - time_elapsed);
}

void loop()
{
  for(i = angle_start; i < angle_end; ++i)
  {
    servo.write(i);

    time_elapsed = 0;

    while(servo.read() != i)
    {
      delay(delay_amount_process);

      time_elapsed += delay_amount_process;
    }
    
    delay(delay_amount_sync - time_elapsed);
  }

  delay(delay_amount_start);
  
  for(i = angle_start; i < angle_end; ++i)
  {
    servo.write(angle_end - i);

    time_elapsed = 0;

    while(servo.read() != (angle_end - i))
    {
      delay(delay_amount_process);

      time_elapsed += delay_amount_process;
    }
    
    delay(delay_amount_sync - time_elapsed);
  }

  delay(delay_amount_start);
}

