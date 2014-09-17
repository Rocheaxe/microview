/* 
 * microview_wink: a simple winking face animation for the MicroView
 * 
 * Created by: Terri Oda <terri (at) toybox.ca>
 * Sept 16, 2014
 */

#include <MicroView.h>

void setup() {
  uView.begin();		// start MicroView
  uView.clear(PAGE);		// clear page
  uView.print("Hi Terri!");	// say hi
  uView.display();
  delay(1000);
}

void loop () {
  //drawFace();
  winkFaceAnimation();
}

void drawFace() { 
  uView.clear(PAGE);
  
  drawEyes();
  drawNose();
  drawMouth();    

  uView.display();        // display current page buffer
}

void drawEyes() {
  uView.circle(20, 15, 5);
  uView.circle(45, 15, 5);
}

void drawNose() {
  uView.line(30, 22, 35, 32);
  uView.line(35, 32, 31, 32);
}

void drawMouth() {
  uView.line(20, 40, 25, 45);
  uView.line(25, 45, 40, 45);
  uView.line(40, 45, 45, 40);
}

void winkFaceAnimation() {
  for (int i = 0; i < 7; i++) {
    uView.clear(PAGE);
    
    // animate one eye for the wink
    switch (i) {
      case 0: 
      case 6:
        uView.circle(45, 15, 5);
        break;
      case 1:
      case 5: 
        uView.rect(40, 12, 10, 5);
        break;
      case 2:
      case 4:
        uView.rect(40, 14, 10, 2);
        break;
      case 3: 
        uView.line(40, 15, 50, 15);
        break;
    }

    // draw the static parts of the face
    uView.circle(20, 15, 5);    
    drawNose();
    drawMouth();
    
    // display and wait for the next frame to start
    uView.display();
    delay(500);
  }  
}
