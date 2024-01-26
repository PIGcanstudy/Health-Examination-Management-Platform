#include "stdafx.h"
#include "ReportPreviewController.h"
#include"service/reportpreview/ReportPreviewService.h"
#include"dldlib/pdf/Pdf.h"
#include"dldlib/fastdfs/FastDfs.h"

StringJsonVO::Wrapper ReportPreviewController::execQueryReportPreview(const ReportPreviewQuery::Wrapper& qdto, const PayloadDTO& payload)
{
	// 定义一个Service
	ReportPreviewService service;
	// 查询数据
	auto result1 = service.reportview(qdto, payload);
	auto result2 = service.symptomview(qdto,payload );
	//调用PDF
	string filename = "report";
	BarcodesPdf pdf;
	pdf.reportTpl(result1, result2, filename);
	BarcodesFastDfs fdfs;
	string downpath = fdfs.barcodesDfs(filename);
	// 响应结果
	auto jvo = StringJsonVO::createShared();
	jvo->success(downpath);
	return jvo;
}
