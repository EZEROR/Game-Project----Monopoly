#include "Plot.h"




LinerPlot::LinerPlot(int x, int y, int w, int h) :Plot(x, y, w, h)
{
    this->price_[0] = 150; // ������洢��ͬ�ȼ����еؿ�ļ۸�
    this->price_[1] = 150;
    this->price_[2] = 150;
    this->name_ = "����";
    this->xywh_[0] = x;// ����������
    this->xywh_[1] = y;
    this->xywh_[2] = w;
    this->xywh_[3] = h;
    this->yes_Button_ = new Button();// ���ڱ��� window�е�ȷ�ϰ�ť
    this->no_Button_ = new Button();//  ���ڱ��� window�е�ȡ����ť
    this->flag_window_ = true;
}

LinerPlot::~LinerPlot()
{
    delete yes_Button_;
    delete no_Button_;
}

//�����ˣ�
//���ܣ����Ƶؿ�
//	���ƾ��� 
//  ��������	�����и���nameд���ؿ�����	
//				������ɫ����owner_ID:������̺ڷֱ��ʾ1234����ҡ������ˡ�
// 
//����:��
void LinerPlot::Draw()
{
    IMAGE image;
    if (owner_ID_ == 0) {
        //��ʾ��ͬͼƬ
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



//�����ˣ�
//���ܣ����Ƶ���
//	��������ˣ����ƹ��򵯴���������X��ť��
//����:��
//����ֵ:NULL
void LinerPlot::DrawWindow(Player& player)
{
    //ֻ��playerվ�ڵ�ǰ��������Ż���ʾ����
    if (owner_ID_ == 0)
    {
        //��������
        IMAGE image;
        loadimage(&image, "asserts/LinerPlotwindow.png", 207, 202);
        putimage(593, 124, &image);
        //��ť1
        IMAGE image2;
        //��ť2
        IMAGE image3;
        //��ť ��ֵ
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
    ���ܣ������ﵽ��˵ؿ���жϴ˵ؿ�������ˣ����������֮�أ��ж���������ĸ���ť������X����
            ����������˵ĵؿ飬�ؿ����˼�Ǯ���Լ���Ǯ��
        ��ǰ�������1~12�����ӣ�����player���RandomMove������
    ����ֵ��NULL
    ������NULL
*/
//�ж����Ŀǰ�Ƿ��ڵ�����
bool LinerPlot::inWindow(const ExMessage& msg, Player& player)//0δ�����1�������,2����˳�
{

    //�����ﵽ��˵ؿ���жϴ˵ؿ�������ˣ�
    //��������ˣ����ƹ��򵯴�
    if (owner_ID_ == 0)
    {
        //	�ж���������ĸ���ť������X��
        //��ť1������
        if (msg.message == WM_LBUTTONDOWN && yes_Button_->inArea(msg))
        {
            if (player.cash_ > 150) {
                this->owner_ID_ = player.ID_;//������������
                player.UpdateWealth(-150);
                owner = &player;

            }
            else
            {
                settextstyle(48, 0, "΢���ź�");
                settextcolor(RED);
                outtextxy(10, 10, "�ʽ𲻹���");
            }
            return true;
        }
        //��ť2���˳�
        if (msg.message == WM_LBUTTONDOWN && no_Button_->inArea(msg))
        {
            return true;
        }

        return false;
    }
    //����������˵ĵؿ飬�ؿ����˼�Ǯ���Լ���Ǯ��
    else
    {

        owner->UpdateWealth(45, player);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1, 22);
        int randomNum = dist(gen);
        //δд����������·������
        //δд���ﵽ����һ������
        player.Move(randomNum);

    }

    return true;
}
