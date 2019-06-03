#ifndef CONTROLLER_H_
#define CONTROLLER_H_
//#include "FruitLink.h"
#include "lotLink.h"
#include "userLink.h"
#include "LotRecord.h"
/*
	功能：彩票界面的管理
	参数：head 头节点
	返回值：无
*/
void Lottrey_control();
/*
	功能:管理员界面的管理
	参数：head 头节点
	返回值：无
*/
void admin_control(User* headUser,Lot* headLot,LotRec* headRec);
/*
	功能:用户界面的管理
	参数：head 头节点
	返回值：无
*/
void user_control(User* headUser,Lot* headLot,LotRec* headRec,int id);
/*
	功能:公证员界面的管理
	参数：head 头节点
	返回值：无
*/
void judge_control(User* headUser,Lot* headLot,LotRec* headRec);
#endif
