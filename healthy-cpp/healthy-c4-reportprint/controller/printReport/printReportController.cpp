
#include "stdafx.h"
#include <iostream>
#include "printReportController.h"
#include "../../service/printReport/printReportService.h"
#include "../ApiDeclarativeServicesHelper.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

/*
 * 打印PDF报告
 */
StringJsonVO::Wrapper printReportController::execModifyprintReport(const printReportDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->id)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	printReportService service;
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







