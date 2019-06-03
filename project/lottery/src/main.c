#include "userLink.h"
#include "lotLink.h"
#include "controller.h"
#include "LotRecord.h"

int main(void){
	//创建链表

	Lot* headLot = createLotlink();
	User* headUser = create_link();
	LotRec* headRec=createReclink();
	//加载
	loadLot(headLot);
	load_Users(headUser);
	loadRec(headRec);

	Lottrey_control(headUser,headLot,headRec);

	//保存
	save_Rec(headRec);
	save_Users(headUser);
	save_Lot(headLot);
	//销毁所有节点
	freeReclink(headRec);
	free_link(headUser);
	freeLotlink(headLot);
	return 0;
}
