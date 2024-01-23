#include "stdafx.h"
#include"SampleBarcodesBiewController.h"
#include"service/samplebarcodesview/SampleBarcodesViewService.h"
#include"domain/vo/samplebarcodesview/SampleBarcodesViewVO.h"

SampleBarcodesViewJsonVO::Wrapper SampleBarcodesViewController::execQuerySampleBarcodesView(const SampleBarcodesViewQuery::Wrapper& qdto,const PayloadDTO& payload)
{
	// 定义一个Service
	SampleBarcodesViewServer service;
	// 查询数据
	auto result = service.barcodesview(qdto, payload);
	// 响应结果
	auto jvo = SampleBarcodesViewJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
