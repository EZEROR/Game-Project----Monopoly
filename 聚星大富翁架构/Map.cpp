#include "Map.h"


/*
������: ����
���� :���Ƴ������ŵ�ͼ�ķ����Լ������������Ϣ
����Plot����,Ȼ��ͨ��list��Ĺ��캯��,����ؿ��������ʼ��ַ�ͽ�����ַ�����еؿ�Ž�list
����Plot�Ļ��ƺ���,��ÿ���ؿ���Ƴ���
���� :NULL
����ֵ:NULL
*/
//�ο�����:
// class Map 
// {
// private:
//     list<Plot*> game_map_; //ע��������ָ��
// public:

//     Map()
//     {
//         Plot plot[n];
//         plot[0] = Plot(plot_kind, price[3], name, xywh[4], IMAGE* pic);
//         plot[1] = Plot(plot_kind, price[3], name, xywh[4], IMAGE* pic);
//         game_map_ = new list(plot,plot+n);
        // for(auto it : game_map_)
        // {
        //     //���Ƶؿ�
        // }
//     }

// }




Map::Map()
{
    //�����������
    Plot* birth = new BirthPointPlot(302, 386, 47, 52);//��д����
    //1
    int beijing_prices[3] = { 450,250, 650 };//��д����
    int beijing_sell_prices[3] = { 225,350, 675 };//��д����
    int beijing_pass_prices[3] = { 80,330,980 };//��д����
    Plot* beijing = new HousePlot(352, 386, 47, 52, beijing_prices, beijing_sell_prices, beijing_pass_prices, "����", "����");//��д����
    //2
    int shenzhen_prices[3] = { 420, 200, 500 };//��д����
    int shenzhen_sell_prices[3] = { 210,310, 560 };//��д����
    int shenzhen_pass_prices[3] = { 70,270,770 };//��д����
    Plot* shenzhen = new HousePlot(401, 386, 47, 52, shenzhen_prices, shenzhen_sell_prices, shenzhen_pass_prices, "����", "����");//��д����

    //����ɻ�����
    Plot* plane = new PlanePlot(452, 386, 47, 52);//��д����
    //3
    int shanghai_prices[3] = { 420, 200, 500 };//��д����
    int shanghai_sell_prices[3] = { 210,310, 560 };//��д����
    int shanghai_pass_prices[3] = { 70,270,770 };//��д����
    Plot* shanghai = new HousePlot(452, 330, 47, 52, shanghai_prices, shanghai_sell_prices, shanghai_pass_prices, "�Ϻ�", "�Ϻ�");//��д����
    //4
    int guangzhou_prices[3] = { 350, 140, 350 };//��д����
    int guangzhou_sell_prices[3] = { 175, 245, 420 };//��д����
    int guangzhou_pass_prices[3] = { 45,185,535 };//��д����
    Plot* guangzhou = new HousePlot(452, 275, 47, 52, guangzhou_prices, guangzhou_sell_prices, guangzhou_pass_prices, "����", "����");//��д����
    //5
    int xiamen_prices[3] = { 350, 140, 350 };//��д����
    int xiamen_sell_prices[3] = { 175, 245, 420 };//��д����
    int xiamen_pass_prices[3] = { 45,185,535 };//��д����
    Plot* xiamen = new HousePlot(501, 275, 47, 52, xiamen_prices, xiamen_sell_prices, xiamen_pass_prices, "����", "����");//��д����

    //���������и���
    Plot* auction = new AuctionPlot(551, 275, 47, 52, game_map_);//��д����

    //6
    int sanya_prices[3] = { 300, 150, 300 };//��д����
    int sanya_sell_prices[3] = { 150, 225, 375 };//��д����
    int sanya_pass_prices[3] = { 40,190,490 };//��д����
    Plot* sanya = new HousePlot(551, 220, 47, 52, sanya_prices, sanya_sell_prices, sanya_pass_prices, "����", "����");//��д����
    //7
    int nanjing_prices[3] = { 300, 150, 300 };//��д����
    int nanjing_sell_prices[3] = { 150, 225, 375 };//��д����
    int nanjing_pass_prices[3] = { 40,190,490 };//��д����
    Plot* nanjing = new HousePlot(551, 167, 47, 52, nanjing_prices, nanjing_sell_prices, nanjing_pass_prices, "�Ͼ�", "�Ͼ�");//��д����

    //�����������
    Plot* prison = new PrisonPlot(551, 110, 47, 52);//��д����
    //8
    int qingdao_prices[3] = { 300, 150, 300 };//��д����
    int qingdao_sell_prices[3] = { 150, 225, 375 };//��д����
    int qingdao_pass_prices[3] = { 40,190,490 };//��д����
    Plot* qingdao = new HousePlot(501, 110, 47, 52, qingdao_prices, qingdao_sell_prices, qingdao_pass_prices, "�ൺ", "�ൺ");//��д����
    //9
    int hangzhou_prices[3] = { 250, 130, 250 };//��д����
    int hangzhou_sell_prices[3] = { 125, 190, 315 };//��д����
    int hangzhou_pass_prices[3] = { 35,165,415 };//��д����
    Plot* hangzhou = new HousePlot(452, 110, 47, 52, hangzhou_prices, hangzhou_sell_prices, hangzhou_pass_prices, "����", "����");//��д����
    //10
    int fuzhou_prices[3] = { 250, 130, 250 };//��д����
    int fuzhou_sell_prices[3] = { 125, 190, 315 };//��д����
    int fuzhou_pass_prices[3] = { 35,165,415 };//��д����
    Plot* fuzhou = new HousePlot(452, 57, 47, 52, fuzhou_prices, fuzhou_sell_prices, fuzhou_pass_prices, "����", "����");//��д����

    //���췢�������
    Plot* generator = new GeneratorPlot(452, 3, 47, 52);//��д����
    //11
    int ningbo_prices[3] = { 200,80,190 };//��д����
    int ningbo_sell_prices[3] = { 100,140,235 };//��д����
    int ningbo_pass_prices[3] = { 30,110,300 };//��д����
    Plot* ningbo = new HousePlot(401, 3, 47, 52, ningbo_prices, ningbo_sell_prices, ningbo_pass_prices, "����", "����");//��д����
    //12
    int tianjin_prices[3] = { 200,80,190 };//��д����
    int tianjin_sell_prices[3] = { 100,140,235 };//��д����
    int tianjin_pass_prices[3] = { 30,110,300 };//��д����
    Plot* tianjin = new HousePlot(353, 3, 47, 52, tianjin_prices, tianjin_sell_prices, tianjin_pass_prices, "���", "���");//��д����

    //����𳵸���
    Plot* train = new TrainPlot(303, 3, 47, 52);//��д����

    //13
    int zhuhai_prices[3] = { 200, 80, 190 };//��д����
    int zhuhai_sell_prices[3] = { 100, 140, 235 };//��д����
    int zhuhai_pass_prices[3] = { 30,110,300 };//��д����
    Plot* zhuhai = new HousePlot(303, 57, 47, 52, zhuhai_prices, zhuhai_sell_prices, zhuhai_pass_prices, "�麣", "�麣");//��д����
    //14
    int wenzhou_prices[3] = { 180,70, 180 };//��д����
    int wenzhou_sell_prices[3] = { 90, 125, 215 };//��д����
    int wenzhou_pass_prices[3] = { 20,90,270 };//��д����
    Plot* wenzhou = new HousePlot(303, 110, 47, 52, wenzhou_prices, wenzhou_sell_prices, wenzhou_pass_prices, "����", "����");//��д����
    //15
    int yiwu_prices[3] = { 170, 60, 160 };//��д����
    int yiwu_sell_prices[3] = { 85, 115,195 };//��д����
    int yiwu_pass_prices[3] = { 40,80,240 };//��д����
    Plot* yiwu = new HousePlot(253, 110, 47, 52, yiwu_prices, yiwu_sell_prices, yiwu_pass_prices, "����", "����");//��д����

    //��������¼�����
    Plot* random = new RandomPlot(204, 110, 47, 52);//��д����
    //16
    int suzhou_prices[3] = { 150,60,150 };//��д����
    int suzhou_sell_prices[3] = { 75,105,180 };//��д����
    int suzhou_pass_prices[3] = { 15,75,225 };//��д����
    Plot* suzhou = new HousePlot(204, 167, 47, 52, suzhou_prices, suzhou_sell_prices, suzhou_pass_prices, "����", "����");//��д����
    //17
    int wuhan_prices[3] = { 150,60,150 };//��д����
    int wuhan_sell_prices[3] = { 75,105,180 };//��д����
    int wuhan_pass_prices[3] = { 15,75,225 };//��д����
    Plot* wuhan = new HousePlot(204, 220, 47, 52, wuhan_prices, wuhan_sell_prices, wuhan_pass_prices, "�人", "�人");//��д����

    //�������ָ���
    Plot* linear = new LinerPlot(204, 275, 47, 52);//��д����
    //18
    int jinan_prices[3] = { 130,40,120 };//��д����
    int jinan_sell_prices[3] = { 65,85,145 };//��д����
    int jinan_pass_prices[3] = { 15,55,175 };//��д����
    Plot* jinan = new HousePlot(254, 275, 47, 52, jinan_prices, jinan_sell_prices, jinan_pass_prices, "����", "����");//��д����
    //19
    int dongguan_prices[3] = { 100, 30, 90 };//��д����
    int dongguan_sell_prices[3] = { 50, 65, 110 };//��д����
    int dongguan_pass_prices[3] = { 10,40,130 };//��д����
    Plot* dongguan = new HousePlot(302, 275, 47, 52, dongguan_prices, dongguan_sell_prices, dongguan_pass_prices, "��ݸ", "��ݸ");//��д����
    //20
    int zhongshan_prices[3] = { 100, 30, 90 };//��д����
    int zhongshan_sell_prices[3] = { 50, 65, 110 };//��д����
    int zhongshan_pass_prices[3] = { 10,40,130 };//��д����
    Plot* zhongshan = new HousePlot(302, 334, 47, 52, zhongshan_prices, zhongshan_sell_prices, zhongshan_pass_prices, "��ɽ", "��ɽ");//��д����

    //��������ʵ��ѭ������
    game_map_.push_back(birth); // �� HousePlot �����ָ����ӵ� game_map_ �б���
    game_map_.push_back(beijing);
    game_map_.push_back(shenzhen);
    game_map_.push_back(plane);
    game_map_.push_back(shanghai);
    game_map_.push_back(guangzhou);
    game_map_.push_back(xiamen);
    game_map_.push_back(auction);
    game_map_.push_back(sanya);
    game_map_.push_back(nanjing);
    game_map_.push_back(prison);
    game_map_.push_back(qingdao);
    game_map_.push_back(hangzhou);
    game_map_.push_back(fuzhou);
    game_map_.push_back(generator);
    game_map_.push_back(ningbo);
    game_map_.push_back(tianjin);
    game_map_.push_back(train);
    game_map_.push_back(zhuhai);
    game_map_.push_back(wenzhou);
    game_map_.push_back(yiwu);
    game_map_.push_back(random);
    game_map_.push_back(suzhou);
    game_map_.push_back(wuhan);
    game_map_.push_back(linear);
    game_map_.push_back(jinan);
    game_map_.push_back(dongguan);
    game_map_.push_back(zhongshan);
    //��ͷβ����
    //game_map_.push_back(game_map_.front());

}


Map::~Map()
{
}

/*
    ���ܣ����� plot������������plot��draw���������еؿ�
*/
void Map::Draw()
{
    //�����������
    auto ptr = game_map_.begin();
    while (true)
    {
        (*ptr)->Draw();
        ptr++;
        if (ptr == game_map_.end())
        {
            break;
        }
    }
}

/*
    ���ܣ����� plot������������plot�� inArea �� inWindow������ǰ�����Ϣ����
    ���룺��������� msg
    �����
        �д���----True
        û����----False
*/
bool Map::inArea(const ExMessage& msg, Player& player)
{
    if ((*player.current_plot_)->inWindow(msg, player))
    {
        return true;
    }
    return false;
}