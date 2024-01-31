#include "stdafx.h"
#include "ReviewController.h"
#include "../../service/review/ReviewService.h"
#include "../ApiDeclarativeServicesHelper.h"

//#include "PdfComponent.h"
//#include "uselib/pdf/ReviewPdf.h"
// FastDFS使用需要的相关头文件
//#include "ServerInfo.h"
//#include "NacosClient.h"
//#include "FastDfsClient.h"

ReviewListPageJsonVO::Wrapper ReviewController::execQueryReview(const ReviewQuery::Wrapper& query)
{
	// 定义一个Service
	ReviewService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ReviewListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//PDF
ReviewJsonVO::Wrapper ReviewController::execQueryPdf(const ReviewQuery::Wrapper& query)
//StringJsonVO::Wrapper ReviewPdfController::execQueryPdf(const String& name)
{
	// 定义一个Service
	ReviewService service;
	// 查询数据
	auto result = service.listByName(query);
	auto jvo = ReviewJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//在AddNewItems中实现 增加功能，此处应删除
//Uint64JsonVO::Wrapper ReviewController::execAddReview(const ReviewListDTO::Wrapper& dto)
//{
//	// 定义返回数据对象
//	auto jvo = Uint64JsonVO::createShared();
//	// 参数校验
//	// 非空校验
//	if (!dto->checkProjectId || !dto->checkProjectName || !dto->reviewExplain)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// 有效值校验
//	if (dto->checkProjectId->empty() || dto->checkProjectName->empty() || dto->reviewExplain->empty())
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//
//	// 定义一个Service
//	ReviewService service;
//	// 执行数据新增
//	uint64_t id = service.saveData(dto);
//	if (id > 0) {
//		jvo->success(UInt64(id));
//	}
//	else
//	{
//		jvo->fail(UInt64(id));
//	}
//	//响应结果
//	return jvo;
//}
// 修改数据
StringJsonVO::Wrapper ReviewController::execModifyReview(const ReviewListDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->id)
	{
		jvo->init(String(""), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ReviewService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
}
// 删除数据
StringJsonVO::Wrapper ReviewController::execRemoveReview(const String& id)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!id)
	{
		jvo->init(String(""), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ReviewService service;
	// 执行数据删除
	if (service.removeData(id.getValue(""))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}