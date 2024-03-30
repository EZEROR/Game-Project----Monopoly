#include "Map.h"


/*
负责人: 张三
功能 :绘制出出整张地图的方块以及各个方块的信息
创建Plot对象,然后通过list类的构造函数,输入地块数组的起始地址和结束地址将所有地块放进list
调用Plot的绘制函数,将每个地块绘制出来
参数 :NULL
返回值:NULL
*/
//参考代码:
// class Map 
// {
// private:
//     list<Plot*> game_map_; //注意这里是指针
// public:

//     Map()
//     {
//         Plot plot[n];
//         plot[0] = Plot(plot_kind, price[3], name, xywh[4], IMAGE* pic);
//         plot[1] = Plot(plot_kind, price[3], name, xywh[4], IMAGE* pic);
//         game_map_ = new list(plot,plot+n);
        // for(auto it : game_map_)
        // {
        //     //绘制地块
        // }
//     }

// }




Map::Map()
{
    //构造出生格子
    Plot* birth = new BirthPointPlot(302, 386, 47, 52);//重写参数
    //1
    int beijing_prices[3] = { 450,250, 650 };//重写参数
    int beijing_sell_prices[3] = { 225,350, 675 };//重写参数
    int beijing_pass_prices[3] = { 80,330,980 };//重写参数
    Plot* beijing = new HousePlot(352, 386, 47, 52, beijing_prices, beijing_sell_prices, beijing_pass_prices, "北京", "北京");//重写参数
    //2
    int shenzhen_prices[3] = { 420, 200, 500 };//重写参数
    int shenzhen_sell_prices[3] = { 210,310, 560 };//重写参数
    int shenzhen_pass_prices[3] = { 70,270,770 };//重写参数
    Plot* shenzhen = new HousePlot(401, 386, 47, 52, shenzhen_prices, shenzhen_sell_prices, shenzhen_pass_prices, "深圳", "深圳");//重写参数

    //构造飞机格子
    Plot* plane = new PlanePlot(452, 386, 47, 52);//重写参数
    //3
    int shanghai_prices[3] = { 420, 200, 500 };//重写参数
    int shanghai_sell_prices[3] = { 210,310, 560 };//重写参数
    int shanghai_pass_prices[3] = { 70,270,770 };//重写参数
    Plot* shanghai = new HousePlot(452, 330, 47, 52, shanghai_prices, shanghai_sell_prices, shanghai_pass_prices, "上海", "上海");//重写参数
    //4
    int guangzhou_prices[3] = { 350, 140, 350 };//重写参数
    int guangzhou_sell_prices[3] = { 175, 245, 420 };//重写参数
    int guangzhou_pass_prices[3] = { 45,185,535 };//重写参数
    Plot* guangzhou = new HousePlot(452, 275, 47, 52, guangzhou_prices, guangzhou_sell_prices, guangzhou_pass_prices, "广州", "广州");//重写参数
    //5
    int xiamen_prices[3] = { 350, 140, 350 };//重写参数
    int xiamen_sell_prices[3] = { 175, 245, 420 };//重写参数
    int xiamen_pass_prices[3] = { 45,185,535 };//重写参数
    Plot* xiamen = new HousePlot(501, 275, 47, 52, xiamen_prices, xiamen_sell_prices, xiamen_pass_prices, "厦门", "厦门");//重写参数

    //构造拍卖行格子
    Plot* auction = new AuctionPlot(551, 275, 47, 52, game_map_);//重写参数

    //6
    int sanya_prices[3] = { 300, 150, 300 };//重写参数
    int sanya_sell_prices[3] = { 150, 225, 375 };//重写参数
    int sanya_pass_prices[3] = { 40,190,490 };//重写参数
    Plot* sanya = new HousePlot(551, 220, 47, 52, sanya_prices, sanya_sell_prices, sanya_pass_prices, "三亚", "三亚");//重写参数
    //7
    int nanjing_prices[3] = { 300, 150, 300 };//重写参数
    int nanjing_sell_prices[3] = { 150, 225, 375 };//重写参数
    int nanjing_pass_prices[3] = { 40,190,490 };//重写参数
    Plot* nanjing = new HousePlot(551, 167, 47, 52, nanjing_prices, nanjing_sell_prices, nanjing_pass_prices, "南京", "南京");//重写参数

    //构造监狱格子
    Plot* prison = new PrisonPlot(551, 110, 47, 52);//重写参数
    //8
    int qingdao_prices[3] = { 300, 150, 300 };//重写参数
    int qingdao_sell_prices[3] = { 150, 225, 375 };//重写参数
    int qingdao_pass_prices[3] = { 40,190,490 };//重写参数
    Plot* qingdao = new HousePlot(501, 110, 47, 52, qingdao_prices, qingdao_sell_prices, qingdao_pass_prices, "青岛", "青岛");//重写参数
    //9
    int hangzhou_prices[3] = { 250, 130, 250 };//重写参数
    int hangzhou_sell_prices[3] = { 125, 190, 315 };//重写参数
    int hangzhou_pass_prices[3] = { 35,165,415 };//重写参数
    Plot* hangzhou = new HousePlot(452, 110, 47, 52, hangzhou_prices, hangzhou_sell_prices, hangzhou_pass_prices, "杭州", "杭州");//重写参数
    //10
    int fuzhou_prices[3] = { 250, 130, 250 };//重写参数
    int fuzhou_sell_prices[3] = { 125, 190, 315 };//重写参数
    int fuzhou_pass_prices[3] = { 35,165,415 };//重写参数
    Plot* fuzhou = new HousePlot(452, 57, 47, 52, fuzhou_prices, fuzhou_sell_prices, fuzhou_pass_prices, "福州", "福州");//重写参数

    //构造发电机格子
    Plot* generator = new GeneratorPlot(452, 3, 47, 52);//重写参数
    //11
    int ningbo_prices[3] = { 200,80,190 };//重写参数
    int ningbo_sell_prices[3] = { 100,140,235 };//重写参数
    int ningbo_pass_prices[3] = { 30,110,300 };//重写参数
    Plot* ningbo = new HousePlot(401, 3, 47, 52, ningbo_prices, ningbo_sell_prices, ningbo_pass_prices, "宁波", "宁波");//重写参数
    //12
    int tianjin_prices[3] = { 200,80,190 };//重写参数
    int tianjin_sell_prices[3] = { 100,140,235 };//重写参数
    int tianjin_pass_prices[3] = { 30,110,300 };//重写参数
    Plot* tianjin = new HousePlot(353, 3, 47, 52, tianjin_prices, tianjin_sell_prices, tianjin_pass_prices, "天津", "天津");//重写参数

    //构造火车格子
    Plot* train = new TrainPlot(303, 3, 47, 52);//重写参数

    //13
    int zhuhai_prices[3] = { 200, 80, 190 };//重写参数
    int zhuhai_sell_prices[3] = { 100, 140, 235 };//重写参数
    int zhuhai_pass_prices[3] = { 30,110,300 };//重写参数
    Plot* zhuhai = new HousePlot(303, 57, 47, 52, zhuhai_prices, zhuhai_sell_prices, zhuhai_pass_prices, "珠海", "珠海");//重写参数
    //14
    int wenzhou_prices[3] = { 180,70, 180 };//重写参数
    int wenzhou_sell_prices[3] = { 90, 125, 215 };//重写参数
    int wenzhou_pass_prices[3] = { 20,90,270 };//重写参数
    Plot* wenzhou = new HousePlot(303, 110, 47, 52, wenzhou_prices, wenzhou_sell_prices, wenzhou_pass_prices, "温州", "温州");//重写参数
    //15
    int yiwu_prices[3] = { 170, 60, 160 };//重写参数
    int yiwu_sell_prices[3] = { 85, 115,195 };//重写参数
    int yiwu_pass_prices[3] = { 40,80,240 };//重写参数
    Plot* yiwu = new HousePlot(253, 110, 47, 52, yiwu_prices, yiwu_sell_prices, yiwu_pass_prices, "义乌", "义乌");//重写参数

    //构造随机事件格子
    Plot* random = new RandomPlot(204, 110, 47, 52);//重写参数
    //16
    int suzhou_prices[3] = { 150,60,150 };//重写参数
    int suzhou_sell_prices[3] = { 75,105,180 };//重写参数
    int suzhou_pass_prices[3] = { 15,75,225 };//重写参数
    Plot* suzhou = new HousePlot(204, 167, 47, 52, suzhou_prices, suzhou_sell_prices, suzhou_pass_prices, "苏州", "苏州");//重写参数
    //17
    int wuhan_prices[3] = { 150,60,150 };//重写参数
    int wuhan_sell_prices[3] = { 75,105,180 };//重写参数
    int wuhan_pass_prices[3] = { 15,75,225 };//重写参数
    Plot* wuhan = new HousePlot(204, 220, 47, 52, wuhan_prices, wuhan_sell_prices, wuhan_pass_prices, "武汉", "武汉");//重写参数

    //构造游轮格子
    Plot* linear = new LinerPlot(204, 275, 47, 52);//重写参数
    //18
    int jinan_prices[3] = { 130,40,120 };//重写参数
    int jinan_sell_prices[3] = { 65,85,145 };//重写参数
    int jinan_pass_prices[3] = { 15,55,175 };//重写参数
    Plot* jinan = new HousePlot(254, 275, 47, 52, jinan_prices, jinan_sell_prices, jinan_pass_prices, "济南", "济南");//重写参数
    //19
    int dongguan_prices[3] = { 100, 30, 90 };//重写参数
    int dongguan_sell_prices[3] = { 50, 65, 110 };//重写参数
    int dongguan_pass_prices[3] = { 10,40,130 };//重写参数
    Plot* dongguan = new HousePlot(302, 275, 47, 52, dongguan_prices, dongguan_sell_prices, dongguan_pass_prices, "东莞", "东莞");//重写参数
    //20
    int zhongshan_prices[3] = { 100, 30, 90 };//重写参数
    int zhongshan_sell_prices[3] = { 50, 65, 110 };//重写参数
    int zhongshan_pass_prices[3] = { 10,40,130 };//重写参数
    Plot* zhongshan = new HousePlot(302, 334, 47, 52, zhongshan_prices, zhongshan_sell_prices, zhongshan_pass_prices, "中山", "中山");//重写参数

    //插入容器实现循环链表
    game_map_.push_back(birth); // 将 HousePlot 对象的指针添加到 game_map_ 列表中
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
    //将头尾相连
    //game_map_.push_back(game_map_.front());

}


Map::~Map()
{
}

/*
    功能：遍历 plot链表，调用所有plot的draw，画出所有地块
*/
void Map::Draw()
{
    //遍历链表绘制
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
    功能：遍历 plot链表，调用所有plot的 inArea 和 inWindow。将当前鼠标信息传入
    输入：引用外面的 msg
    输出：
        有触发----True
        没触发----False
*/
bool Map::inArea(const ExMessage& msg, Player& player)
{
    if ((*player.current_plot_)->inWindow(msg, player))
    {
        return true;
    }
    return false;
}