#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc, char** argv){
	    Mat image;
    Mat image_gray;
	//string fileName;
	//cout<<"Enter the FileName:"<<endl;
	//cin>>fileName;
    image = imread( argv[1], IMREAD_COLOR);  
    //namedWindow( "window1", 1 ); //  imshow( "window1", image );

    CascadeClassifier face_cascade;
    CascadeClassifier eyes_cascade;

    face_cascade.load( "/home/pushpanshu/Desktop/openCV/c++/cv_assignment_2/face_detect/haarcascade_frontalface_default.xml" );
    eyes_cascade.load( "/home/pushpanshu/Desktop/openCV/c++/cv_assignment_2/face_detect/haarcascade_eye.xml");
	// Detect faces
    std::vector<Rect> faces;
    cvtColor(image, image_gray, COLOR_BGR2GRAY);
    equalizeHist(image_gray, image_gray);
    face_cascade.detectMultiScale( image_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(80, 80) );
	if(faces.size()==0){
		cout<<"NO"<<endl;
	}
    else {
		cout<<"YES"<<endl;
		for( int i = 0; i < faces.size(); i++ )
        {
        	Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
            //ellipse( image, center, Size( faces[i].width/2, faces[i].height/2), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
            rectangle(image,Point (faces[i].x,faces[i].y),Point (faces[i].x+faces[i].width, faces[i].y+faces[i].height),Scalar(255,0,255),4,8,0);

            Mat faceROI = image_gray(faces[i]);
            std::vector<Rect> eyes;
            eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30,30));
            for(int j=0; j < eyes.size(); j++)
            {
                Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y  +eyes[j].y + eyes[j].height/2 );
                int radius = cvRound((eyes[j].width+eyes[j].height)*0.25);        
                circle( image,eye_center,radius,Scalar(255, 0, 0),4,8,0 );
				cout<<eye_center<<endl;
            }
		}
	}
    imshow("Detected Face", image );

    waitKey(0);                   
    return 0;
	
	return 0;
}
