/*
 Copyright Zero One Star. All rights reserved.

 @Author: DY
 @Date: 2023/12/29 11:30:58

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "InspectPdf.h"
#include <iostream>
#include "PdfComponent.h"
#include "ServerInfo.h"

// ��������������Ҫ����ͷ�ļ�
#include "zxing/MultiFormatWriter.h"
#include "zxing/CharacterSet.h"
#include "zxing/BitMatrix.h"
#include "domain/do/ReportView/ReportDO.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>
using namespace ZXing;

// ����������Ԥ�� https://zxing-cpp.github.io/zxing-cpp/demo_writer.html

void InspectPdf::ReportTpl(const ReportDO& Do)
{
	// ��Ⱦģ��        
	PdfComponent::registerTplRender("Report", [](YAML::Node* node, PdfComponent* pdf, void* realData)
		{
			// ����һ��ҳ��
			HPDF_Page newPage = pdf->getNewPage();
			// ����ҳ������
			HPDF_Page_SetFontAndSize(newPage, pdf->getCnSFont("SimSun"), 20);
			// ���ƾ�̬����
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
			// ���ƶ�̬����
			std::string content = static_cast<std::string*>(realData)->c_str();
			pdf->drawTextCenter(content);

			HPDF_Page new1Page = pdf->getNewPage();
			//HPDF_Page_SetFontAndSize(newPage, pdf->getCnSFont("SimSun"), 20);
			auto conclusion = (*node)["conclusion"].as<std::string>();
			auto inspectionDoctor = (*node)["inspectionDoctor"].as<std::string>();
			auto inspectionDate = (*node)["inspectionDate"].as<std::string>();
			auto diagnosticUnit = (*node)["diagnosticUnit"].as<std::string>();
			// ���浽�ļ�
			pdf->saveDocToFile("Report.pdf");
			
		});

	// ����
	PdfComponent pdf;
	auto content = ZH_WORDS_GETTER("pdf.content");
	pdf.drawWithTemplate("tpl/test.yaml", "Report", &content);
}
