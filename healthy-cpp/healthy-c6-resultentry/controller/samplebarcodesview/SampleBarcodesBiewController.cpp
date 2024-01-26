#include "stdafx.h"
#include"SampleBarcodesBiewController.h"
#include"service/samplebarcodesview/SampleBarcodesViewService.h"
#include"dldlib/pdf/Pdf.h"
#include"dldlib/fastdfs/FastDfs.h"

StringJsonVO::Wrapper SampleBarcodesViewController::execQuerySampleBarcodesView(const SampleBarcodesViewQuery::Wrapper& qdto,const PayloadDTO& payload)
{
	// 定义一个Service
	SampleBarcodesViewServer service;
	// 查询数据
	auto result = service.barcodesview(qdto, payload);
	//调用PDF
	string filename = "barcodes";
	BarcodesPdf pdf;
	pdf.barcodesTpl(result, filename);
	BarcodesFastDfs fdfs;
	string downpath=fdfs.barcodesDfs(filename);
	// 响应结果
	auto jvo = StringJsonVO::createShared();
	jvo->success(downpath);
	return jvo;
}
