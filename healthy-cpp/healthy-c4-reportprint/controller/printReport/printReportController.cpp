
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


std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> printReportController::execDownloadSampleCode(const String& sampleCodeName)
{
	// 构建样本条码全路径
	std::string code_fullPath = "public/static/SampleCode/SampleCode.png";

	// 读取样本条码
	auto code_fstring = String::loadFromFile(code_fullPath.c_str());

	// 判断是否读取成功
	if (!code_fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto code_response = createResponse(Status::CODE_200, code_fstring);

	// 设置响应头信息
	code_response->putHeader("Content-Disposition", "attachment; filename=" + sampleCodeName.getValue("") + ".png");

	// 影响成功结果
	return code_response;
}