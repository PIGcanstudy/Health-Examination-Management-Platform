//主检评价接口
import Request from '@/apis/request.js'
const baseUrl = ''

// 获取体检人员名称列表(分页+条件)
export const getMedicalPersonNameApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '', params)
}

// 获取体检人员详情
export const getMedicalPersonDetailsApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '', params)
}

// 忽略指定基础项目
export const ignoreProjectApi = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '', params)
}

// TODO下载个人报告word
export const downloadReportApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '', params)
}

// 审查
export const reviewApi = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '', params)
}

// 新增复查项目
export const addReviewItemApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '', params)
}

// 获取复查项目列表
export const getReviewItemsListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '', params)
}

// 获取问诊明细
export const getInquiryDetailsApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '', params)
}

// 获取体检项目结果明细
export const getMedicalExaminationResultsApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '', params)
}

// 获取阳性结果列表
export const getPositiveResultsListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '', params)
}

// 保存总检报告
export const storageInspectorReportApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '', params)
}

// 获取添加项目结论列表
export const getAddedProjectConclusionsListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '', params)
}

// 获取体检项目结果明细
export const getMedicalExaminationResultsListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '', params)
}
