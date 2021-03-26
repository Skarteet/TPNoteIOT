# TP Note IOT

![Image Share Network Windows](./img/capture_0.jpg)

## Team :
- Robin Bigeard
- Thomas Mary
- Maxime Grand
- Antoine Leblanc  

## Requierments :
- Git (clone project *optional)
- FileZila (optional)
- SSH (optional)
- SD Card
- Raspberry Pi
- Arduino UNO
- 1 LED / 1 Resistor
- Captor DHT11 (humidity, temperature)
- Cables

## Install Rapbian OS to SD card and configure Wifi
https://www.seeedstudio.com/blog/2021/01/25/three-methods-to-configure-raspberry-pi-wifi/

## Share you network (optional) :
![Image Share Network Windows](./img/capture_1.png)

```
ssh pi@192.168.137.161
// Authentificate 
// user : pi 
// password : raspberry
pi$ ~ mkdir tp
```

## Transfert script to Raspberry Pi with FileZilla or other
![FileZilla](./img/capture_2.png)

Transfert file in `tp` folder :
- main.py

## Install dependancy :
```
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install python-serial
sudo pip install pyserial
cd tp
pip3 install google-cloud-firestore
```

## Configure Raspberry Pi :
```
# confi
sudo raspi-config

// Interface Options > I2C > Enable
// Interface Options > Serial Port > Enable
```

## Schema Connection 
![Schema Connection](./img/capture_3.png)

## Schema Database 
![Schema Database](./img/capture_4.png)

## Aduino
Install Arduino : https://www.arduino.cc/en/software

![Arduino SDK](./img/capture_5.png)

Open file `TPNoteTemperature_Arduino.ino` 

![Arduino DHT](./img/capture_6.png)
![Arduino DHT](./img/capture_6.png)

Install `DHT` modules in library.  

And compile / transfert the code.

## Import credential authentication for Firebase
https://cloud.google.com/docs/authentication/getting-started
```
export GOOGLE_APPLICATION_CREDENTIALS=/home/pi/tp/BeAware-3d38a27421cd.json
```

## Execute script :
```
python3 main.py
```

