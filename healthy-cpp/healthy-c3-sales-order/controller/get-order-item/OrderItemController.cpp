#include "OrderItemController.h"

StringJsonVO::Wrapper OrderItemController::execRemoveOrder(const String& orderCode)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 响应结果
	return jvo;
}

OrderItemJsonVO::Wrapper OrderItemController::execQueryItem(const OrderItemQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 响应结果
	auto jvo = OrderItemJsonVO::createShared();
	
	return jvo;
}
