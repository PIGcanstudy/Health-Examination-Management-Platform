#include "OrderItemController.h"

StringJsonVO::Wrapper OrderItemController::execRemoveOrder(const String& orderCode)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ��Ӧ���
	return jvo;
}

OrderItemJsonVO::Wrapper OrderItemController::execQueryItem(const OrderItemQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ��Ӧ���
	auto jvo = OrderItemJsonVO::createShared();
	
	return jvo;
}
