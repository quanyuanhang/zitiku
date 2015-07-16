// 20150515.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <opencv2\core\core.hpp>  
#include <opencv2\highgui\highgui.hpp>  
#include <opencv2\imgproc\imgproc.hpp>  
#include <opencv2\contrib\contrib.hpp> 
#include "CvxText.h"

using namespace cv;
using namespace std;
int main() { 
	/*IplImage *img = cvLoadImage("32.jpg");
	// 输出汉字
	CvxText text("C:\\Windows\\Fonts\\simsun.ttc"); // "zenhei.ttf"为黑体常规
	const char *msg = "航";
	float p = 1;
	text.setFont(NULL, NULL, NULL, &p);   // 透明处理
	text.putText(img, msg, cvPoint(3.5, 29), CV_RGB(0,0,0));
	// 定义窗口，并显示影象
	cvShowImage("test", img );
	//system("md .\\result1"); 
	cvSaveImage(".//result1//han.jpg", img);
	cvWaitKey(-1);
	cvReleaseImage(&img);*/
	/*Directory dir;  
	string exten = "*";//"Image*";//"*"  
	string save_path="D://文字识别//train//";
	string save_dir="md D:\\文字识别\\train\\";
	bool addPath = false;//false  
	string dir_path = "E://编程练习//20150515//20150515//ziti";    
	vector<string> foldernames = dir.GetListFiles(dir_path,exten, addPath); 
	for (int i = 0; i < foldernames.size(); i++)  
	cout<<foldernames[i]<<endl;*/
	Directory dir;  
	string exten = "*";//"Image*";//"*"  
	string save_path="D://文字识别//train64//";
	string save_dir="md D:\\文字识别\\train64\\";
	bool addPath = false;//false  
	string dir_path = "D://文字识别//train_3755";    
	vector<string> foldernames = dir.GetListFolders(dir_path,exten, addPath);  
	for (int i = 0; i < foldernames.size(); i++)  
		foldernames[i]=foldernames[i].substr(0, foldernames[i].find_first_of("."));
	IplImage *img = cvLoadImage("64.jpg");
	IplImage* img2;
	
	string ziti_path = "E://编程练习//20150515//20150515//ziti";    
	vector<string> ziti_names = dir.GetListFiles(ziti_path,exten, addPath);
	string ziti_root="C:\\Windows\\Fonts\\";
	stringstream ss;
	for(int j=1;j<ziti_names.size();j++){
		//if(j==14) continue;
		string ziti=ziti_root+ziti_names[j];
		cout<<j<<" "<<ziti_names[j]<<" 字体打印中"<<endl;
		CvxText text(ziti.c_str()); 
		for (int i = 0; i < foldernames.size(); i++)  {
			img2 = cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
			//将图片1复制到图片2
			cvCopy(img,img2,NULL);
			const char *msg = foldernames[i].c_str();
			//string cmd=save_dir+foldernames[i];
			//system(cmd.c_str()); 
			float p = 1.0;
			text.setFont(NULL, NULL, NULL, &p);   // 透明处理
			text.putText(img2, msg, cvPoint(7, 58), CV_RGB(0,0,0));
			
			ss<<j;
			string path=save_path+foldernames[i]+"//"+ss.str()+"_"+foldernames[i]+".jpg";
			ss.str("");
			cvSaveImage(path.c_str(), img2);
		}
	}
	//cout<<foldernames[i]<<endl; 
	cvWaitKey(-1);
	cvReleaseImage(&img);
	cvReleaseImage(&img2);
	return 0;

}

