#include "Plot.h"




LinerPlot::LinerPlot(int x, int y, int w, int h) :Plot(x, y, w, h)
{
    this->price_[0] = 150; // 数组里存储不同等级城市地块的价格
    this->price_[1] = 150;
    this->price_[2] = 150;
    this->name_ = "邮轮";
    this->xywh_[0] = x;// 方形类坐标
    this->xywh_[1] = y;
    this->xywh_[2] = w;
    this->xywh_[3] = h;
    this->yes_Button_ = new Button();// 用于保存 window中的确认按钮
    this->no_Button_ = new Button();//  用于保存 window中的取消按钮
    this->flag_window_ = true;
}

LinerPlot::~LinerPlot()
{
    delete yes_Button_;
    delete no_Button_;
}

//负责人：
//功能：绘制地块
//	绘制矩形 
//  绘制文字	矩形中根据name写出地块名称	
//				文字颜色依据owner_ID:红黄蓝绿黑分别表示1234号玩家、无主人。
// 
//参数:无
void LinerPlot::Draw()
{
    IMAGE image;
    if (owner_ID_ == 0) {
        //显示不同图片
        loadimage(&image, _T("asserts/LinerPlot_write.png"));
    }
    else if (owner_ID_ == 1) {
        loadimage(&image, _T("asserts/LinerPlot_red.png"));
    }
    else if (owner_ID_ == 2) {
        loadimage(&image, _T("asserts/LinerPlot_yellow.png"), 47, 52);
    }
    else if (owner_ID_ == 3) {
        loadimage(&image, _T("asserts/LinerPlot_blue.png"));
    }
    else
    {
        loadimage(&image, _T("asserts/LinerPlot_green.png"));
    }
    putimage(xywh_[0], xywh_[1], &image);
}



//负责人：
//功能：绘制弹窗
//	如果无主人，绘制购买弹窗（含购买、X按钮）
//参数:无
//返回值:NULL
void LinerPlot::DrawWindow(Player& player)
{
    //只有player站在当前方格上面才会显示弹窗
    if (owner_ID_ == 0)
    {
        //弹窗背景
        IMAGE image;
        loadimage(&image, "asserts/LinerPlotwindow.png", 207, 202);
        putimage(593, 124, &image);
        //按钮1
        IMAGE image2;
        //按钮2
        IMAGE image3;
        //按钮 赋值
        yes_Button_->x_ = 621;
        yes_Button_->y_ = 272;
        yes_Button_->width_ = 150;
        yes_Button_->height_ = 40;

        no_Button_->x_ = 784;
        no_Button_->y_ = 129;
        no_Button_->width_ = 15;
        no_Button_->height_ = 20;

    }
}

/*
    功能：在人物到达此地块后，判断此地块的所有人，如果是无主之地，判断鼠标点击了哪个按钮（购买、X）；
            如果是其他人的地块，地块主人加钱，自己减钱。
        向前随机传送1~12个格子（调用player类的RandomMove（））
    返回值：NULL
    参数：NULL
*/
//判定鼠标目前是否在弹窗上
bool LinerPlot::inWindow(const ExMessage& msg, Player& player)//0未点击，1点击了是,2点击退出
{

    //在人物到达此地块后，判断此地块的所有人，
    //如果无主人，绘制购买弹窗
    if (owner_ID_ == 0)
    {
        //	判断鼠标点击了哪个按钮（购买、X）
        //按钮1，购买
        if (msg.message == WM_LBUTTONDOWN && yes_Button_->inArea(msg))
        {
            if (player.cash_ > 150) {
                this->owner_ID_ = player.ID_;//这里代表几号玩家
                player.UpdateWealth(-150);
                owner = &player;

            }
            else
            {
                settextstyle(48, 0, "微软雅黑");
                settextcolor(RED);
                outtextxy(10, 10, "资金不够！");
            }
            return true;
        }
        //按钮2，退出
        if (msg.message == WM_LBUTTONDOWN && no_Button_->inArea(msg))
        {
            return true;
        }

        return false;
    }
    //如果是其他人的地块，地块主人加钱，自己减钱。
    else
    {

        owner->UpdateWealth(45, player);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1, 22);
        int randomNum = dist(gen);
        //未写：人物行走路程增加
        //未写人物到达下一个格子
        player.Move(randomNum);

    }

    return true;
}
