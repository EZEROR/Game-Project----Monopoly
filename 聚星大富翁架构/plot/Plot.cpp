#include "Plot.h"


/*
	�Գ�����ֵ
	���� plot_kind ��ȡ���ƣ������� name
	�����������������г�ʼ��

	��ʼ�� yesButton �� noButton

*/
Plot::Plot(int x, int y, int w, int h) :xywh_{ x,y,w,h }
{
	yes_Button_ = new Button(x, y, w, h, "ȷ��");
	no_Button_ = new Button(x, y, w, h, "ȡ��");
}

Plot::~Plot()
{
}

/*
	���� xywh_ �ڶ�Ӧλ�ã�������Ӧ��С�ĵؿ�
		���ƾ���
		��������	�����и���nameд���ؿ�����	���磺���Ϻ�����
*/
//void Plot::Draw()
//{
//
//}

void Plot::Draw()
{
}

///*
//	���������ζԻ���
//	ȷ�� �� ȡ����ť
//	��ʾ�ı�
//*/
//void Plot::DrawWindow()
//{
//
//
//}

/*
	�ж� ��������� msg �Ƿ��ڵ�ǰ plot �ķ�Χ�ڣ�Ĭ�ϴ��������down��
*/
//bool Plot::inArea(const ExMessage& msg)
//{
//	return false;
//}

/*
	�ж� ��������� msg �Ƿ��ڵ�ǰ window�е� button �ķ�Χ�ڣ�Ĭ�ϴ��������down��
		�ֱ��ж� yes��nobutton �� inarea �Ƿ񱻴���
*/

bool Plot::inWindow(const ExMessage& msg, Player& player)
{
	if ((*player.current_plot_)->level_ == 2 || (*player.current_plot_)->owner_ID_ != player.ID_ && (*player.current_plot_)->owner_ID_)
	{
		cout << "No window to show." << endl;
		return true;
	}



	if (yes_Button_->inArea(msg)) {
		/*
			ִ�ж�Ӧ����
		*/
		cout << "YES button clicked." << endl;
		Event(player);
		return true;
	}
	/*
		ͬ�� no_button
	*/
	else if(no_Button_->inArea(msg))
	{
		cout << "NO button clicked." << endl;
		return true;
	}
	return false;

}

void Plot::Event(Player& player)
{
}

