#pragma once
#include "domain/do/review/ReviewDO.h"
#ifndef _REVIEWPDF_H_
#define _REVIEWPDF_H_
/**
 * PDF���
 */
class ReviewPdf
{
public:
	// ģ�����
	static void reviewText(const ReviewDO& Do);
	static void reviewTpl(const ReviewDO& Do);
	//static void reviewTpl();
};

#endif // !_REVIEWPDF_H_