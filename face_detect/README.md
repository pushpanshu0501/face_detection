#Assignement 1

##Problem statement

OpenCV has inbuilt object and face detection and recognition module uses haarcascades (haarcascades are nothing but pretrained models that can be used directly for feature matching. 

You need to find and download face recognition haar cascade and eye detection haar cascade. (time to show some googling skills :p).

You have to write a file named faceDetect.cpp that takes 1 argument during execution:
	i.e. path to image under consideration
	
NOTE: this means that if the executable generated on compilation is "exec", 
the execution syntax should be 
	$ ./exec <path to image> 	e.g. if path is "image.png" 
						$ ./exec image.png
Test cases: 
	If the image contains a face, your program should output "YES" followed by the location of eyes(in the image coordinates) in the next two lines, else output "NO". 
	e.g. if the face is present, output should be 
		YES
		30 60 		// x1 y1 	where (x1,y1) are coordinates of the approximate center of left eye  
		65 59		// x2 y2 	same for the right eye.
	else if face is not present, output should be
		NO

PLEASE NOTE THAT WE ARE TALKING ABOUT HUMAN FACES HERE. 

##Compiling your code

	//make a folder named build and navigate to it
	$ mkdir build
	$ cd build

	//generate makefile using the CMakeLists.txt provided
	$ cmake ..

	//compile
	$ make 

If there are no errors, you will see that an executable will be generated in the main folder.
You can test your code using this executable and the test image provided.

NOTE: you do not need to make build again and again. Just run 
	$ make 		
to recompile.
 
##Submission
go to build directory and run 
	$ make clean 

Now zip this folder and get xxx_cv_assignment2.zip where xxx is your roll number. Submit this file.
