#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<easyx.h>
#include<time.h>
#include<mmsystem.h> 
#pragma comment(lib,"winmm.lib")   //一个库文件和头文件用来播放音乐
#include<conio.h>         //包含有按键退出的函数             

#define STAR_NUM  500
#define METEOR_NUM 100
struct Star 
{
	int x;   int y;    int r;  int speed;
	COLORREF color; //  定义一种颜色
};
struct Meteor
{
	int x; int y; int speed;
};
struct Star star[STAR_NUM];
struct Meteor meteor[METEOR_NUM];
void setStar(int i)     //定义初始化星星的函数
{
	star[i].x = rand() % getwidth();
	star[i].y = rand() % getheight();
	star[i].r = rand() % 2;
	star[i].speed = rand() % 2+1;
	star[i].color = RGB(rand() % 256, rand() % 256, rand() % 256, );
}
void setMeteor(int i)  //初始化流星的函数
{
	meteor[i].x = rand() % (2 * getwidth()) - getwidth();
	meteor[i].y = 20 - 200;
	meteor[i].speed = rand() % 15+1;
}
IMAGE img[2];
IMAGE bk[2];  //定义背景图


void loadImag()
{
	loadimage(img + 0,_T ("./流星/liuxing1.jpg"), 50, 50);
	loadimage(img + 1,_T ("./流星/liuxing2.png"), 50, 50);
}
void drawMeteor()                  //绘制流星
{

	for (size_t i = 0; i < METEOR_NUM; i++)
	{
		
		putimage(meteor[i].x, meteor[i].y, img + rand() % 2,SRCPAINT);
	}
}
void moveMeteor()                   //移动流星
{
	for (size_t i = 0; i < METEOR_NUM; i++)
	{
		meteor[i].x += meteor[i].speed;
		meteor[i].y += meteor[i].speed;
		if (meteor[i].x >= getwidth() || meteor[i].y >= getheight())
		{
			setMeteor(i);
		}
	}
}
void drawStar()    //定义绘制星星的函数u
{
	for (size_t i = 0; i < STAR_NUM; i++)
	{
		putpixel(star[i].x, star[i].y, star[i].color);    // 绘制像素点

		setfillcolor(star[i].color);
		solidcircle(star[i].x, star[i].y, star[i].r);
	}
}
void moveStar()      //移动星星
{
	for (size_t i = 0; i < STAR_NUM; i++)
	{
		star[i].x+=star[i].speed;
		if (star[i].x > getwidth())
		{
			star[i].x = 0;
		}
	}
}



void welcome()
{
	//mci->  media device interface多媒体设备接口
	mciSendString(_T("open yihuik银河与星斗.mp3"), NULL, 0, NULL);
	mciSendString(_T("play yihuik银河与星斗.mp3"),NULL,0,NULL);

	srand((unsigned)time(NULL));

	setbkmode(TRANSPARENT);               //除去心形背景
	settextstyle(40, 0, _T("华文行楷"));  

	 /* int tx=(  getwidth() - textwidth(_T("小朋友，我喜欢你"))  ) / 2; */  //求宽度居中坐标
	 
	  
	  settextcolor(BLUE);      // 设置颜色 
	  while (!_kbhit())     //如果没有按键按下，就一直循环     
	  {
		  cleardevice();
		  putimage(0, 0, bk + 1);
		  settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256, ));
		  outtextxy(220, 10, _T("宝宝，我想你辣~"));
		  outtextxy(150, 70,_T("血包我不要，我只要你"));
		  outtextxy(150, 120,_T("你是朝阳，是晚霞，是我一切的欢喜"));
		  outtextxy(150, 170,_T("情不知所起，一往而情深"));
		  outtextxy(150, 220,_T("月亮和星星或许不会奔你而来，但我会❥(^_-)"));
		  outtextxy(150, 270,_T("我会陪你打游戏，会回泉水接你，会预约等你"));
		  outtextxy(150, 320,_T("想变成小鹿粘着你，战绩里全是你~"));
		  outtextxy(150, 370,_T("生活点滴温柔可爱，美食和你都我要争取"));
		  outtextxy(150, 420, _T("把温柔和可爱全部藏起来，全部留给你"));
		  outtextxy(150, 470,_T("时间可以证明一切，给时间多一点时间"));
		  outtextxy(150, 520,_T("山有木兮木有枝，心悦君兮君不知"));
		  outtextxy(150, 570,_T("你就若千万点流萤,深藏在我的梦境"));
		  outtextxy(150, 620,_T("你像天使一样出现，轻易满足我一切幻想"));
		  outtextxy(150, 670,_T("许愿的法则是，说出来才能实现"));
		  outtextxy(300, 750,_T("爱你哟 我的林奕小公主————你的小哥哥"));

		  for (size_t i = 0; i < 50; i++)
		  {
			  settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256, ));

			  outtextxy(rand()%getwidth(), rand()%getheight(),rand()%2?L"❤":L"♥");
		  }

		

		  Sleep(1000);
	  }
	 
}
int main()
{
	
	initgraph(1800, 800);  //绘制窗口函数
	/*setbkcolor(RGB(99, 99, 99));*/   //设置背景颜色
	
	loadimage(bk + 0, _T("./星空/1000.jpg"), getwidth(), getheight());
	loadimage(bk+  1, _T("./星空/1001.jpg"), getwidth(), getheight());
	
	for (size_t i = 0; i < STAR_NUM; i++)
	{
		setStar(i);
	}
	for (size_t i = 0; i <METEOR_NUM; i++)
	{
		setMeteor(i);
	}
	loadImag();
	welcome(); 
	
	BeginBatchDraw();
	while (1)
	{
		cleardevice(); 
		drawStar();
		moveStar();
		/*putimage(0, 0, bk + 0);*/
		drawMeteor();
		moveMeteor();
		FlushBatchDraw();
		Sleep(10);
	}
	

	EndBatchDraw();







	return 0;

}