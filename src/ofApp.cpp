#include "ofApp.h"

static const int NUM=1000;
float loc_x[NUM];
float loc_y[NUM];
float speed_x[NUM];
float speed_y[NUM];
float radious[NUM];
int red[NUM];
int green[NUM];
int blue[NUM];
bool is_mouse_pressed;
float gravity;
float friction;


//--------------------------------------------------------------
void ofApp::setup(){
ofBackground(0, 0, 0);
    //ofSetFrameRate(60);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    is_mouse_pressed=false;
    //ofSetBackgroundAuto(false);
    gravity=0.1;
    friction=0.999;
//    ofEnableLighting();

    for (int i=0; i<NUM; i++) {
        loc_x[i]=ofRandom(0,ofGetWidth());
        loc_y[i]=ofRandom(0,ofGetHeight());
        speed_x[i]=ofRandom(-10,10);
        speed_y[i]=ofRandom(-10, 10);
        radious[i]=100;
        radious[i]=ofRandom(1, 20);
        red[i]=ofRandom(0,255);
        green[i]=ofRandom(0,255);
        blue[i]=ofRandom(0,255);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
for (int i=0; i<NUM; i++) {
        if (is_mouse_pressed) {
            speed_x[i]=(mouseX-loc_x[i])/16.0;
            speed_y[i]=(mouseY-loc_y[i])/16.0;
        }

        speed_x[i]*=friction;
        speed_y[i]*=friction;
        speed_y[i]+=gravity;

        loc_x[i]+=speed_x[i];
        loc_y[i]+=speed_y[i];

        if (loc_x[i]<0) {
            speed_x[i]*=-1;
        }
        if (loc_x[i]>ofGetWidth()) {
            speed_x[i]*=-1;
        }
        if (loc_y[i]<0||loc_y[i]>ofGetHeight()) {
            speed_y[i]*=-1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
ofSetColor(0, 0, 0,23);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    for (int i=0; i<NUM; i++) {
        ofSetColor(red[i], green[i], blue[i], 127);
        ofDrawCircle(loc_x[i], loc_y[i], radious[i]);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::touchDown(int x, int y, int id){
    is_mouse_pressed=true;

}

//--------------------------------------------------------------
void ofApp::touchMoved(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchUp(int x, int y, int id){
    is_mouse_pressed=false;

    for (int i=0; i<NUM; i++) {
        speed_x[i]=ofRandom(-10,10);
        speed_y[i]=ofRandom(-10, 10);
    }
}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::swipe(ofxAndroidSwipeDir swipeDir, int id){

}

//--------------------------------------------------------------
void ofApp::pause(){

}

//--------------------------------------------------------------
void ofApp::stop(){

}

//--------------------------------------------------------------
void ofApp::resume(){

}

//--------------------------------------------------------------
void ofApp::reloadTextures(){

}

//--------------------------------------------------------------
bool ofApp::backPressed(){
	return false;
}

//--------------------------------------------------------------
void ofApp::okPressed(){

}

//--------------------------------------------------------------
void ofApp::cancelPressed(){

}
