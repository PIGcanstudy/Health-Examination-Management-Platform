#pragma once
#ifndef _PREVIEWREPORTDTO_H_
#define _PREVIEWREPORTDTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 单位列表的数据传输对象实体
* 负责人 Z
*/

class PreviewReportDTO : public oatpp::DTO {
	DTO_INIT(PreviewReportDTO, DTO);

	// 唯一编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("preview.field.id"));
	// 报告编号
	API_DTO_FIELD_DEFAULT(String, reportid, ZH_WORDS_GETTER("preview.field.Reportid"));
	// pdf下载地址
	API_DTO_FIELD_DEFAULT(String, pdfaddress, ZH_WORDS_GETTER("preview.field.pdfaddress"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PREVIEWREPORTDTO_H_
