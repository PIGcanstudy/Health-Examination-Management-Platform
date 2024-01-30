
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







