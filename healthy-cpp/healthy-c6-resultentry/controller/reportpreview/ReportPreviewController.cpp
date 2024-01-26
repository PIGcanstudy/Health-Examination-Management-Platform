#include "stdafx.h"
#include "ReportPreviewController.h"
#include"service/reportpreview/ReportPreviewService.h"
#include"dldlib/pdf/Pdf.h"
#include"dldlib/fastdfs/FastDfs.h"

StringJsonVO::Wrapper ReportPreviewController::execQueryReportPreview(const ReportPreviewQuery::Wrapper& qdto, const PayloadDTO& payload)
{
	// ����һ��Service
	ReportPreviewService service;
	// ��ѯ����
	auto result1 = service.reportview(qdto, payload);
	auto result2 = service.symptomview(qdto,payload );
	//����PDF
	string filename = "report";
	BarcodesPdf pdf;
	pdf.reportTpl(result1, result2, filename);
	BarcodesFastDfs fdfs;
	string downpath = fdfs.barcodesDfs(filename);
	// ��Ӧ���
	auto jvo = StringJsonVO::createShared();
	jvo->success(downpath);
	return jvo;
}
