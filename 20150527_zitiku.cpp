// 20150515.cpp : �������̨Ӧ�ó������ڵ㡣
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
	// �������
	CvxText text("C:\\Windows\\Fonts\\simsun.ttc"); // "zenhei.ttf"Ϊ���峣��
	const char *msg = "��";
	float p = 1;
	text.setFont(NULL, NULL, NULL, &p);   // ͸������
	text.putText(img, msg, cvPoint(3.5, 29), CV_RGB(0,0,0));
	// ���崰�ڣ�����ʾӰ��
	cvShowImage("test", img );
	//system("md .\\result1"); 
	cvSaveImage(".//result1//han.jpg", img);
	cvWaitKey(-1);
	cvReleaseImage(&img);*/
	/*Directory dir;  
	string exten = "*";//"Image*";//"*"  
	string save_path="D://����ʶ��//train//";
	string save_dir="md D:\\����ʶ��\\train\\";
	bool addPath = false;//false  
	string dir_path = "E://�����ϰ//20150515//20150515//ziti";    
	vector<string> foldernames = dir.GetListFiles(dir_path,exten, addPath); 
	for (int i = 0; i < foldernames.size(); i++)  
	cout<<foldernames[i]<<endl;*/
	Directory dir;  
	string exten = "*";//"Image*";//"*"  
	string save_path="D://����ʶ��//train64//";
	string save_dir="md D:\\����ʶ��\\train64\\";
	bool addPath = false;//false  
	string dir_path = "D://����ʶ��//train_3755";    
	vector<string> foldernames = dir.GetListFolders(dir_path,exten, addPath);  
	for (int i = 0; i < foldernames.size(); i++)  
		foldernames[i]=foldernames[i].substr(0, foldernames[i].find_first_of("."));
	IplImage *img = cvLoadImage("64.jpg");
	IplImage* img2;
	
	string ziti_path = "E://�����ϰ//20150515//20150515//ziti";    
	vector<string> ziti_names = dir.GetListFiles(ziti_path,exten, addPath);
	string ziti_root="C:\\Windows\\Fonts\\";
	stringstream ss;
	for(int j=1;j<ziti_names.size();j++){
		//if(j==14) continue;
		string ziti=ziti_root+ziti_names[j];
		cout<<j<<" "<<ziti_names[j]<<" �����ӡ��"<<endl;
		CvxText text(ziti.c_str()); 
		for (int i = 0; i < foldernames.size(); i++)  {
			img2 = cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
			//��ͼƬ1���Ƶ�ͼƬ2
			cvCopy(img,img2,NULL);
			const char *msg = foldernames[i].c_str();
			//string cmd=save_dir+foldernames[i];
			//system(cmd.c_str()); 
			float p = 1.0;
			text.setFont(NULL, NULL, NULL, &p);   // ͸������
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

