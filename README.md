# AQUA_Box
![box](https://github.com/IIOTproject/AQUA_Box/blob/master/install/81726474_583258675571824_2878367119047655424_n.jpg)

## USER MANUAL
> Install the device at a point on the river where the water level is at least 30cm or at a height where the house of the speed sensor does not touch the river floor. The pole support should be securely anchored on the river floor so that it would not be carried by the river current. The water level during installation should be somewhere in the middle of the tube. For best results, install the device on a day where the water level is considered normal. 
The board box can be detached and installed in another location on the river bank. Make sure that the box is high enough so that when the water level rises, the box will not get submerged into the water. The solar cell face should be face up and getting enough sunshine. 
 
* OPERATION
> NORMAL MODE
>> The device will send a regular message every 15mins. The message contains the values for the turbidity, speed, level and rain. These values will be updated on the Wix site including the location of the device. 
 
> ALERT MODE
>> Once the conditions for the alert are met, the device would right away send a message to Losant and which will in turn send an email to the subscribers informing them of the alert. If the conditions persist after 5 mins, it would again send an alert. This would repeat until the conditions returns to normal. If the conditions went back to normal, the device would just return to sending the message every 15 mins.
 


## Background
Flooding is the most common natural disaster occurring 43% of the world's total natural disasters from 1995-2015. As the global precipitation anomaly continues to rise in recent years, flood related incidents is becoming more common and its impact is greater for the global economy. In 2018 alone, 17.44 billion USD of economic damages was reported. The highest ever recorded was in 2011 with 70.76 billion USD. 

![1](https://github.com/IIOTproject/AQUA_Box/blob/master/Reference_pic/1.png)

Around the world, flooding affects 2.3 billion people, which is 56% of the world's population. Highly affected countries includ USA, China, Philippines and India.

![2](https://github.com/IIOTproject/AQUA_Box/blob/master/Reference_pic/2.png)

A study by Hirabayashi et al. predict that as a warmer climate persists in fewer years from now, Asia's and Africa's flood risk would increase. This not only includes in areas near the sea but as well as inland.

![3](https://github.com/IIOTproject/AQUA_Box/blob/master/Reference_pic/3.png)

## Device Structure
> The sensor tube is where the speed, level and turbidity are housed. At the lower end of the tube is a fish is attached, housing the speed sensor, which can follow the flow of water so that the speed sensor is fed with the right direction of water flow. Located at the end of the tube, just above the fish, is the turbidity sensor. Holes are found around the turbidity sensor so that water can go inside the tube and trigger the level sensors which are stacked inside. At the topmost cover of the tube is a groove to attach the board box. All wires run up along the side of the tube to the board box.
 
> The board box houses the Arduino, Sigfox, power bank and rain sensor. The power bank has a solar cell so that it can charge itself and is located at the top face of the box. The rain sensor is also at the top face. It is installed in an inclined position so that it would not accumulate water. 

![STRUCTURE](https://github.com/IIOTproject/AQUA_Box/blob/master/part%20description%202.PNG)
 
## Conponments
![articulture](https://github.com/IIOTproject/AQUA_Box/blob/master/ardiuno_structure/4.png)
### SENSORS
* TURBIDITY SENSOR: 0-3000NTU 
*	LEVEL SENSOR : 0-2(LOW, MEDIUM, HIGH) - 15CM
*	SPEED SENSOR : 0-30L/MIN
*	RAIN SENSOR: 0-700 (LOW, MEDIUM, HIGH)
### BOARDS
*	ARDUINO UNO REV 3
*	UNASHIELD V2/ V2S
### OTHER COMPONENTS
*	POWER BANK WITH SOLAR CELL
*	WIRES AND CABLES
### MECHANICAL COMPONENTS
*	3D PRINTING PLASTIC (PLA)
*	BOLTS AND SCREWS
*	SILICON
*	HEAT SHRINKS
### Ardiuno articulture
![ardiuno](https://github.com/IIOTproject/AQUA_Box/blob/master/ardiuno_structure/5.png)


## Installation
> Install the device at a point on the river where the water level is at least 30cm or at a height where the house of the speed sensor does not touch the river floor. The pole support should be securely anchored on the river floor so that it would not be carried by the river current. The water level during installation should be somewhere in the middle of the tube. For best results, install the device on a day where the water level is considered normal. 
> The board box can be detached and installed in another location on the river bank. Make sure that the box is high enough so that when the water level rises, the box will not get submerged into the water. The solar cell face should be face up and getting enough sunshine.  
![install](https://github.com/IIOTproject/AQUA_Box/blob/master/install/installation.png)


