
//Written by William Luk
// posts data to an Adafuit.io feed
let url = '	https://io.adafruit.com/api/v2/Xplosivebum/feeds/testdata';

var data = 0;
var video;

//let MAGNETOB;
//function preload() {
//  fontRegular = loadFont('assets/MAGNETOB.ttf');

function setup() {
  createCanvas(1900,150);
    background(200,160,150);
    
    textSize(72);
    textFont('Magneto');
    text('Welcome to Click Race!', 495, 95);
    
    textSize(18);
    textFont('Arial');
    text('Place your bet on a colour below!', 750, 130);
    
    video = createCapture(VIDEO);
    video.size(1900,500);
    
    myButton1 = createButton('Blue');
    myButton1.mousePressed(drawText1);
    myButton1.position(730,700);
    myButton1.style('background-color:#0CAEF7');
    
    myButton2 = createButton('Red');
    myButton2.mousePressed(drawText2);
    myButton2.position(830,700);
    myButton2.style('background-color:red');
    
    myButton3 = createButton('Yellow');
    myButton3.mousePressed(drawText3);
    myButton3.position(930,700);
    myButton3.style('background-color:#F7D80C');
    
    myButton4 = createButton('Green');
    myButton4.mousePressed(drawText4);
    myButton4.position(1030,700);
    myButton4.style('background-color:#00AE05');
    
    myButton5 = createButton('Erase Bet');
    myButton5.mousePressed(eraseBet);
    myButton5.position(1130,700);
    myButton5.style('background-color:white');
    
    myButton6 = createButton('Start Race');
    myButton6.mousePressed(startServos);
    myButton6.position(1300,400);
    myButton6.style('background-color:#00AE05');
    
    myButton7 = createButton('Stop Race');
    myButton7.mousePressed(stopServos);
    myButton7.position(1300,430);
    myButton7.style('background-color:red');
}

function draw() {
    image(video);

}

function drawText1() {
    textSize(18);
    textFont('Arial');
    fill(12,174,247);
    text('You bet on Blue!', 1020, 130);
}

function drawText2() {
    textSize(18);
    textFont('Arial');
    fill(255,0,0);
    text('You bet on Red!', 1020, 130);
}

function drawText3() {
    textSize(18);
    textFont('Arial');
    fill(255,255,0);
    text('You bet on Yellow!', 1020, 130);
}

function drawText4() {
    textSize(18);
    textFont('Arial');
    fill(0,174,5);
    text('You bet on Green!', 1020, 130);
}

function eraseBet() {
    fill (200,160,150);
    noStroke();
    rect (1020,110,150,25);
}

function startServos() {
    data = 1;
    console.log(data);
    sendData(data);
}

function stopServos() {
    data = 0;
    console.log(data);
    sendData(data);
}

function sendData(turnOn){
  let postData ={
    "value": turnOn,
    "X-AIO-Key": "aio_xDpW81DDXBE1IMn1V21IWg9nxVye"
  };
  httpPost(url, 'json', postData, function(result){
    console.log(result);
  });
}