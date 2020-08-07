// video technology studies
// ntsc study
// developed using processing 3 on a macbook air
// by aaron montoya-moraga
// mit media lab, future sketches research group

// technical details, taken from Wikipedia on August 5 2020
// available at https://en.wikipedia.org/wiki/NTSC

// frame rate is 30/1.001 frames per second
// which is approximately 29.97 frames per second

// each frame is composed of two fields, each consisting of 262.5 lines
// for a total of 525 scan lines

// 483 scan lines make up the visible raster
// the remainder lines (vertical blanking interval)
// allows for vertical sync and retrace

// in the complete raster (disregarding half lines due to interlacing)
// the even scan lines (2, 4, 6, ..., 524) are drawn in the 1st field
// the odd scan lines (1, 3, 5, ..., 525) are drawn in the 2nd field
// which yields a flicker-free image
// at the field refresh frequency of 60/1.001 Hz
// approximately 59.94 Hz

// in comparison, PAL uses 625 lines (576 visible)
// and therefore has a higher vertical resolution
// but also has a lower temporal resolution of 25 or 50 frames per second

// in black and white, the original refresh rate was 60 Hz in USA
// which matches the frequency of alternating current
// this avoids intermodulation (beating), causing rolling bars on the screen

// when color was added, the refresh frequency was shifted slightly downward
// by 0.1 % to approximately 59.94 Hz to eliminate stationary dot patterns
// in the difference frequency between the sound and color carriers

// the actual figure of 525 lines was chosen as a consequence
// of limitations of the vacuum-tube-based tech of the day

// color encoding
// for backward compatibility, NTSC uses a luminance-chrominance encoding system
// the 3 color picture signals are divided into
// luminance (derived mathematically 

boolean showHelpText = false;

//int scanLines = 525;
int scanLines = 100;

int currentScanLine = 0;

float lineSizeX = 0;
float lineSizeY = 0;

// canvas size is 768 px x 768 px
// 768 is 512 + 256
// 768 base 10 is 0011 0000 0000 base 2

void setup() {
  
  size(768, 768);
  
  background(0, 0, 0);
  
  frameRate(30);
  
  // calculate the 
  lineSizeX = width;
  lineSizeY = float(height) / scanLines;
  
  strokeWeight(lineSizeY);
  
}

// draw scan line per draw
void draw() {
  
  // pick random color
  stroke(random(255), random(255), random(255));
  
  // draw line from left to right
  line(0, lineSizeY * 0.5 + currentScanLine * lineSizeY,
  width - 1, lineSizeY * 0.5 + currentScanLine * lineSizeY);
  
  // update currentScanLine
  currentScanLine = (currentScanLine + 2);
  
  if (currentScanLine >= scanLines) {
    // wrap around
    currentScanLine = currentScanLine % scanLines;
    // if even, change to odd, and viceversa
    currentScanLine = 1 - currentScanLine;
  }
  
  displayHelpText();
  
}

void displayHelpText() {
  if (showHelpText) {
    textSize(32);
    text("frameRate:", width/2, height/2);
  }
}


void keyPressed() {
  // h or H key press toggles help text on / off
  if (key == 'h' || key == 'H') {
    println("help");
    showHelpText = ! showHelpText; 
  }
}
