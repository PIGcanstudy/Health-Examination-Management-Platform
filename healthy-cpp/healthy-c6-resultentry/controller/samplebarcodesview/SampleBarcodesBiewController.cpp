#include "stdafx.h"
#include"SampleBarcodesBiewController.h"
#include"service/samplebarcodesview/SampleBarcodesViewService.h"
#include"domain/vo/samplebarcodesview/SampleBarcodesViewVO.h"

SampleBarcodesViewJsonVO::Wrapper SampleBarcodesViewController::execQuerySampleBarcodesView(const SampleBarcodesViewQuery::Wrapper& qdto,const PayloadDTO& payload)
{
	// ����һ��Service
	SampleBarcodesViewServer service;
	// ��ѯ����
	auto result = service.barcodesview(qdto, payload);
	// ��Ӧ���
	auto jvo = SampleBarcodesViewJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
