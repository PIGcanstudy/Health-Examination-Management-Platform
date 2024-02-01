#include "stdafx.h"
#include "positiveController.h"
#include "../../service/positive/PositiveListService.h"

#include "stdafx.h"
using namespace std;
#include "ServerInfo.h"
#include "ExcelComponent.h"

PositiveListPageJsonVO::Wrapper PositiveConrtoller::execQueryPositive(const PositiveQuery::Wrapper& query)
{	// ����һ��Service
	PositiveListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = PositiveListPageJsonVO::createShared();
	jvo->success(result);

	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> PositiveConrtoller::execDownloadFile(const String& filename)
{
	// �����ļ�ȫ·��
	std::string fullPath = "public/excel/" + URIUtil::urlDecode(filename.getValue(""));

	// ��ȡ�ļ�
	auto fstring = String::loadFromFile(fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// Ӱ��ɹ����
	return response;
}
