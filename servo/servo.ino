#include <Servo.h>

Servo servo;

const int update_frequency = 30;
const int angle_start = 10;
const int angle_end = 150;
const int delay_amount_start = 1000;
const int delay_amount_process = 1;
const int delay_amount_sync = 1000 / update_frequency;

int i = 0;
int time_elapsed = 0;

int servo_move(int servo_angle)
{
  time_elapsed = 0;
  
  servo.write(servo_angle);

  while(servo.read() != servo_angle)
  {
    time_elapsed += delay_amount_process;
    
    delay(delay_amount_process);
  }

  return time_elapsed;
}

int servo_init()
{
  delay(delay_amount_start - servo_move(angle_start));

  return 1;
}

void setup()
{
  servo.attach(9);

  servo_init();
}

int servo_forwards()
{
  for(i = angle_start; i < angle_end; ++i)
  {
    servo.write(i);
    
    delay(delay_amount_sync - servo_move(i));
  }

  return 1;
}

int servo_backwards()
{
  for(i = angle_start; i < angle_end; ++i)
  {
    delay(delay_amount_sync - servo_move(angle_end - i));
  }

  return 1;
}

void loop()
{
  servo_forwards();

  delay(delay_amount_start);
  
  servo_backwards();

  delay(delay_amount_start);
}

