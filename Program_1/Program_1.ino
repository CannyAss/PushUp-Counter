void setup() {
  // put your setup code here, to run once:
  /* Record initial value of z, when d is within 3cm for 5 seconds (Using a x=x+1 function)
   *  Emit a sound to indicate ready status
   */
}

void loop() {
  #include <iostream> 
using namespace std;
int main() {
   int x, y, z, d; 
   /* x is the number of push-ups
    *  y is the 'down' counter
    *  z is the 'up' status
    *  d is the distance sensor
    */

  
  do{
    if (d <= 6 || y == 0){
      y++;
    }
    if ( d>z || y == 1){
      x++;
      y--;
    }
  } while ( d<z || d>5) /* entering push-up status, d is smaller than initial position while further than 5cm) */


return 0;

}
