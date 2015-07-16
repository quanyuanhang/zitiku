#include "stdafx.h"
#include <iostream>
#include <opencv2\core\core.hpp>  
#include <opencv2\highgui\highgui.hpp>  
#include <opencv2\imgproc\imgproc.hpp>  
#include <opencv2\contrib\contrib.hpp> 
#include <math.h>
#include <time.h>
using namespace cv;
using namespace std;

int num=24;
float u1(int x,int y,float k1,float c1){	
	return x+k1*y+c1;
}
float u2(int x,int y,float k2,float c2){
	return y+k2*x+c2;
}
void imageTransformation(Mat src,int seed,String savePath,String name){
	int x,y;
	float k1,k2,c1,c2;
	int central_x=src.cols/2;
	int central_y=src.rows/2;
	x=central_x;
	y=central_y;
	srand(seed); //打开随机触发器 与时钟频率同步 
	k1=(rand()%2?1:-1)*(rand()%171)/1000.0;
	k2=(rand()%2?1:-1)*(rand()%101)/500.0;
	//cout<<k1<<" "<<k2<<endl;
	c1=-k1*y;
	c2=-k2*x;
	//cout<<"c1:"<<c1<<endl;
	//cout<<"c2:"<<c2<<endl;
	Mat outImg=Mat(64,64,src.type(),Scalar(255));   

	for(int i=0;i<src.rows;i++){
		for(int j=0;j<src.cols;j++){
			int val = src.at<uchar>(i,j);  
			if(val<100){
				float r=u1(i,j,k1,c1);
				float c=u2(i,j,k2,c2);
				if(c>63) c=63;
				if(c<0) c=0;
				if(r>63) r=63;
				if(r<0)  r=0;

				outImg.at<uchar>(r,c)=int(val);
			}
		}
	}
	stringstream ss;
	ss<<num;
	string path=savePath+"//"+ss.str()+"_"+name+".jpg";
	ss.str("");
	//cvSaveImage(path.c_str(), outImg);
	imwrite(path,outImg);
	num++;
}
int main() { 

	Directory dir;  
	string exten = "*";  
	bool addPath = true;

	string dir_path = "D://文字识别//test64";
	int max=0;
	string errors="error:";
	vector<string> foldernames = dir.GetListFolders(dir_path,exten, addPath);  
	for (int i = 0; i < foldernames.size(); i++){  
		cout<<foldernames[i]<<endl;
		vector<string> names = dir.GetListFiles(foldernames[i],exten, addPath);
		string save_path=foldernames[i];
		cout<<names.size()<<endl;
		num=24;
		string name=save_path.substr(save_path.find_last_of("//")+1,-1);
		
		if(names.size()>240){ 
			max++;
			errors+=name;
		}
		cout<<name<<endl;
		for(int i=0;i<24;i++){
			Mat img=imread(names[i],0);
			for(int j=0;j<9;j++){
				imageTransformation(img,j,save_path,name);
			}
		}
	}
	cout<<max<<endl;
	cout<<errors<<endl;
	waitKey(0);
	return 0;
}