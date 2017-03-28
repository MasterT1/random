#include "ofApp.h"
#include <random> //allow access to C++ random facilities

//--------------------------------------------------------------
void ofApp::setup(){
jewel.load("diamond.png");// image to use (must be stored in "random/bin/data" folder)
getRandom();
//X = {500, 1000, 30, 100, 300, 200, 750, 380 };// set of x-coordinates for jewel
//Y = {630, 400, 900,40, 200, 0, 90, 30}; //set of y-coordinates for jewel
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
ofBackground(0);

for(auto i = 0u; i < X.size(); i++)
 {
   jewel.draw(X[i], Y[i]);
 }
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


void ofApp::getRandom(){	
	std::random_device rd; // will be used to seed the engine eng1 below
    std::mt19937 eng1(rd()); // this engine produces different ouput every time
    std::mt19937 eng2(1337);// this engine  produces the same output every time

    float mean_X = 1000.0f; // average
    float sd_X = 15.0f; // standard deviation
    
    float mean_Y = 800.0f; // average
    float sd_Y = 15.0f; // standard deviation

    int min = 0; // minimum number to generate    
    int max_X = 1200; // maximum number to generate
    int max_Y = 970; // maximum number to generate
    

    // values near the mean are the most likely
    // standard deviation affects the dispersion of generated values from the mean
    std::normal_distribution<float> normX(mean_X,sd_X);
    std::normal_distribution<float> normY(mean_Y,sd_Y);
    
    std::uniform_int_distribution<> unifrmX(min, max_X);
    std::uniform_int_distribution<> unifrmY(min, max_Y);


  //generate 20 normally distributed floats  
  for(int n=0 ;  n < 20 ;  n++) 
   {
        X.push_back(normX(eng1)); // different output each time        
        Y.push_back(normY(eng1));
        
    }

  //generate 20 uniformly distributed integers 
  /*for(int n=0 ;  n < 20 ; n++) 
  {
        X.push_back(unifrmX(eng2));// same output each time        
        Y.push_back(unifrmY(eng2));
   }*/
}
