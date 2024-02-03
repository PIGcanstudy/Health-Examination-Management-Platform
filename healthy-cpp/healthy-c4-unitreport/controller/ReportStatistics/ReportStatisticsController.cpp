#include "ReportStatisticsController.h"

PhysicalExaminationPersonnelJsonVO::Wrapper PhysicalExaminationPersonnelController::execQueryPhysicalExaminationPersonnel(const ReportStatisticsQuery::Wrapper& query)
{
	cout << "find sucess";
	return PhysicalExaminationPersonnelJsonVO::Wrapper();
}

ReviewPersonnelJsonVO::Wrapper ReviewPersonnelController::execQueryReviewPersonnel(const ReportStatisticsQuery::Wrapper& query)
{
	return ReviewPersonnelJsonVO::Wrapper();
}

ReviewResultsJsonVO::Wrapper ReviewResultsController::execQueryReviewResults(const ReportStatisticsQuery::Wrapper& query)
{
	return ReviewResultsJsonVO::Wrapper();
}
