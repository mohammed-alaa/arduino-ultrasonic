/*
 * Ultrasonic sensor
 * Author: Mohamed Alaa
 * Date: 07/02/2021
 */

/* Trigger pin */
const int trig = 10;

/* Echo pin */
const int echo = 11;

/* Global variables to store the duration & distance */
long duration, distance;

void setup()
{
  /* Begin serial to print the duration & distance */
  Serial.begin(9600);

  /* Set trigger pin to output */
  pinMode(trig, OUTPUT);

  /* Set echo pin to input */
  pinMode(echo, INPUT);
}                                                

/* Calculate the distance */
void getDistance(void)
{
  /* Set trigger to low */
  digitalWrite(trig, LOW);

  /* Wait 2us */
  delayMicroseconds(2);

  /* Set trigger to high */
  digitalWrite(trig, HIGH);

  /* Wait 10us */
  delayMicroseconds(10);

  /* Set trigger to low */
  digitalWrite(trig, LOW);

  /* Get the duration */
  duration = pulseIn(echo, HIGH);

  /* Calculate the distance */
  /* distance = time * speed */
  /* speed = 0.0343 in cm/s (speed of sound) */
  /* distance is in cm */
  distance = (duration / 2) * 0.0343;
}

void loop()
{
  /* Get the distance */
  getDistance()

  /* Print the distance */
  Serial.println(distance);

  /* Wait 5ms */
  delay(5);
}
