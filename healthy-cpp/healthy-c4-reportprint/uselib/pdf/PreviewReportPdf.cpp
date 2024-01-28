#include "stdafx.h"
#include "PreviewReportPdf.h"
#include <iostream>
#include "PdfComponent.h"
#include "ServerInfo.h"


void PreviewReportPdf::PreviewReportTpl(const PreviewReportDO& Do)
{
	// 渲染模板        
	PdfComponent::registerTplRender("PreviewReport", [](YAML::Node* node, PdfComponent* pdf, void* realData)
		{
			// 创建一个页面
			HPDF_Page newPage = pdf->getNewPage();
			// 设置页面字体
			HPDF_Page_SetFontAndSize(newPage, pdf->getCnSFont("SimSun"), 20);
			// 绘制静态数据
			auto title = (*node)["title"].as<std::string>();
			auto name = (*node)["name"].as<std::string>();
			auto sex = (*node)["sex"].as<std::string>();
			auto age = (*node)["age"].as<std::string>();
			auto idCard = (*node)["idCard"].as<std::string>();
			auto mobile = (*node)["mobile"].as<std::string>();
			auto physicalType = (*node)["physicalType"].as<std::string>();
			auto dept = (*node)["dept"].as<std::string>();
			pdf->drawTextCenterH(title, HPDF_Page_GetHeight(newPage) - 20);
			pdf->drawTextCenterH(name, HPDF_Page_GetHeight(newPage) - 40);
			pdf->drawTextCenterH(sex, HPDF_Page_GetHeight(newPage) - 60);
			pdf->drawTextCenterH(age, HPDF_Page_GetHeight(newPage) - 80);
			pdf->drawTextCenterH(idCard, HPDF_Page_GetHeight(newPage) - 100);
			pdf->drawTextCenterH(mobile, HPDF_Page_GetHeight(newPage) - 120);
			pdf->drawTextCenterH(physicalType, HPDF_Page_GetHeight(newPage) - 140);
			pdf->drawTextCenterH(dept, HPDF_Page_GetHeight(newPage) - 160);
			// 绘制动态数据
			std::string content = static_cast<std::string*>(realData)->c_str();
			pdf->drawTextCenter(content);

			HPDF_Page new1Page = pdf->getNewPage();
			//HPDF_Page_SetFontAndSize(newPage, pdf->getCnSFont("SimSun"), 20);
			auto conclusion = (*node)["conclusion"].as<std::string>();
			auto inspectionDoctor = (*node)["inspectionDoctor"].as<std::string>();
			auto inspectionDate = (*node)["inspectionDate"].as<std::string>();
			auto diagnosticUnit = (*node)["diagnosticUnit"].as<std::string>();
			// 保存到文件
			pdf->saveDocToFile("PreviewReport.pdf");
			
		});

	// 绘制
	PdfComponent pdf;
	auto content = ZH_WORDS_GETTER("pdf.content");
	pdf.drawWithTemplate("tpl/test.yaml", "PreviewReport", &content);
}
