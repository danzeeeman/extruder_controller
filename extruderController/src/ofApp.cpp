#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofxXmlSettings xml;
    xml.load("setting.xml");
    serial.setup(xml.getValue("serial", "/dev/tty.usbmodem143201"), 9600);
    
    extruder.add(extruderOn.set("Extruder On", false));
    extruderOn.addListener(this, &ofApp::extruderOnListener);
    extruder.add(extruderForward.set("Extruder Forward", true));
    extruderForward.addListener(this, &ofApp::extruderForwardListener);
    extruder.add(extruderFeedSpeed.set("Feed Speed", 0, 0, 9));
    extruderFeedSpeed.addListener(this, &ofApp::extruderFeedSpeedListener);
    
    gui.setup(extruder);
}

void ofApp::extruderOnListener(bool & b){
    if(b == true){
        serial.writeByte('o');
    }else{
        serial.writeByte('f');
    }
}

void ofApp::extruderForwardListener(bool &b ){
    if(b == true){
        serial.writeByte('c');
    }else{
        serial.writeByte('w');
    }
}

void ofApp::extruderFeedSpeedListener(int & i){
    char c = '0';
    if(i == 0){
        c = '0';
    }else if(i == 1){
        c = '1';
    }else if(i == 2){
        c = '2';
    }else if(i == 3){
        c = '3';
    }else if(i == 4){
        c = '4';
    }else if(i == 5){
        c = '5';
    }else if(i == 6){
        c = '6';
    }else if(i == 7){
        c = '7';
    }else if(i == 8){
        c = '8';
    }else if(i == 9){
        c = '9';
    }
    serial.writeByte(c);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    if(extruderOn){
        float alpha = ofMap(sin(ofGetElapsedTimef()*5), -1, 1, 50, 150);
        float line_width = 25;
        ofPushStyle();
        ofSetColor(255, 0, 0, alpha);
        ofSetLineWidth(line_width);
        ofNoFill();
        ofDrawLine(0, line_width/2, ofGetWidth(), line_width/2);
        ofDrawLine(0, ofGetHeight()-line_width/2, ofGetWidth(), ofGetHeight()-line_width/2);
        ofDrawLine(line_width/2, line_width, line_width/2, ofGetHeight()-line_width);
        ofDrawLine(ofGetWidth()-line_width/2, line_width, ofGetWidth()-line_width/2, ofGetHeight()-line_width);
        ofSetColor(255,alpha+50);
        ofDrawBitmapString("WARNING: EXTRUDER IS ON!", ofGetWidth()/2-100, 2*line_width/3);
        ofPopStyle();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'O' || key == 'o'){
        extruderOn = true;
    }else if(key == 'P' || key == 'p'){
        extruderOn = false;
    }else if(key == OF_KEY_LEFT){
        extruderForward = false;
    }else if(key == OF_KEY_RIGHT){
        extruderForward = true;
    }else if(key == '0'){
        extruderFeedSpeed = 0;
    }else if(key == '1'){
        extruderFeedSpeed = 1;
    }else if(key == '2'){
        extruderFeedSpeed = 2;
    }else if(key == '3'){
        extruderFeedSpeed = 3;
    }else if(key == '4'){
        extruderFeedSpeed = 4;
    }else if(key == '5'){
        extruderFeedSpeed = 5;
    }else if(key == '6'){
        extruderFeedSpeed = 6;
    }else if(key == '7'){
        extruderFeedSpeed = 7;
    }else if(key == '8'){
        extruderFeedSpeed = 8;
    }else if(key == '9'){
        extruderFeedSpeed = 9;
    }
    
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
