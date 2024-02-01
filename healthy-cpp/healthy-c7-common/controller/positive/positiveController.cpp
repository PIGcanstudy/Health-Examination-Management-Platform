#include "stdafx.h"
#include "positiveController.h"
#include "../../service/positive/PositiveListService.h"

#include "stdafx.h"
using namespace std;
#include "ServerInfo.h"
#include "ExcelComponent.h"

PositiveListPageJsonVO::Wrapper PositiveConrtoller::execQueryPositive(const PositiveQuery::Wrapper& query)
{	// 定义一个Service
	PositiveListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = PositiveListPageJsonVO::createShared();
	jvo->success(result);

	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> PositiveConrtoller::execDownloadFile(const String& filename)
{
	// 构建文件全路径
	std::string fullPath = "public/excel/" + URIUtil::urlDecode(filename.getValue(""));

	// 读取文件
	auto fstring = String::loadFromFile(fullPath.c_str());

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// 影响成功结果
	return response;
}
