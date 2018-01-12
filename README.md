## **0.Preface**

This is my second submision. In the first time I trun the parameter in a old computer. It's configuration is very poor. I can only comunicate with the simulator about 600 times in a lap. I tried my best but I can't get a good result(even with twiddle). So I didn't get pass for this project.

This time I run my program on a good computer. I can comunicate with the simulator about 6000 times in a lap. I get a good result just turning my paramiter by hand.

So I want to say we really need a good computer :) .

## **1.Compilation**
The code compiled without errors. The result is in "[build](./build)" folder.
## **2.Implementation**
The PID procedure follows what was taught in the lessons.

There is a diffrent : 

I think the CTE in long ago is no useful for the car. So I did't sum all of the CTEs in the past. I just sum the last 20 CTEs as my intigration error.

## **3.Reflection**
 ### **3.1 The effect each of the P, I, D components**
P:

Keyword:"now".

The parameter of P is indicated the importance of the current CTE. For this project, if we want the car steer immediately, when the car is run off the center, we should give the P a big value.

D:

Keyword:"future".

The parameter D is indicated the importance of the future CTE. If we want the controler sensitive for the CTE's change we should give a big value to the D. In the project when the car through a curve the CTE(absolute value) will have a tendency to becoming big or small in the future. So the D value can help us to ajust the car's sensitive for the curve in front.

I:

Keyword:"past".

The I value can help the cotroler to make a decision based on the past CTEs. For example, when the car get a command from the contorler it's tuning but the contoler find that the car is always stay in the left of the road center in last few frames, that means the car should turn more to the right, then the I parameter worked help the car turn more to the right.


### **3.2 how the final hyperparameters were chosen.**

I just turn the hyperparameters by my hand.

The hyperparameters I got is shown in below:

|P|I|D|
|-|-|-|
|0.15|0.00002|5|

## **4.Simulation**
The video of my simulation is located in `./video/record.mp4`.(Please ignore the watermark in the video, I used a free software so you know that.)