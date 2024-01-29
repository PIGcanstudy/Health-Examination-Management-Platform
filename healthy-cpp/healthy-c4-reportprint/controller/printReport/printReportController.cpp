
#include "stdafx.h"
#include <iostream>
#include "printReportController.h"
#include "../../service/printReport/printReportService.h"
#include "../ApiDeclarativeServicesHelper.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

/*
 * ��ӡPDF����
 */
StringJsonVO::Wrapper printReportController::execModifyprintReport(const printReportDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->id)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	printReportService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// ��Ӧ���
	return jvo;
}


std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> printReportController::execDownloadSampleCode(const String& sampleCodeName)
{
	// ������������ȫ·��
	std::string code_fullPath = "public/static/SampleCode/SampleCode.png";

	// ��ȡ��������
	auto code_fstring = String::loadFromFile(code_fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!code_fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto code_response = createResponse(Status::CODE_200, code_fstring);

	// ������Ӧͷ��Ϣ
	code_response->putHeader("Content-Disposition", "attachment; filename=" + sampleCodeName.getValue("") + ".png");

	// Ӱ��ɹ����
	return code_response;
}