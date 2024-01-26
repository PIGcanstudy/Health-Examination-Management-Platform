#include "stdafx.h"
#include"SampleBarcodesBiewController.h"
#include"service/samplebarcodesview/SampleBarcodesViewService.h"
#include"dldlib/pdf/Pdf.h"
#include"dldlib/fastdfs/FastDfs.h"

StringJsonVO::Wrapper SampleBarcodesViewController::execQuerySampleBarcodesView(const SampleBarcodesViewQuery::Wrapper& qdto,const PayloadDTO& payload)
{
	// ����һ��Service
	SampleBarcodesViewServer service;
	// ��ѯ����
	auto result = service.barcodesview(qdto, payload);
	//����PDF
	string filename = "barcodes";
	BarcodesPdf pdf;
	pdf.barcodesTpl(result, filename);
	BarcodesFastDfs fdfs;
	string downpath=fdfs.barcodesDfs(filename);
	// ��Ӧ���
	auto jvo = StringJsonVO::createShared();
	jvo->success(downpath);
	return jvo;
}
