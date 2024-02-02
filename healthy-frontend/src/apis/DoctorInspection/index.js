import Request from '@/apis/request.js'
const baseUrl = ''

/* 该接口文件的封装顺序参考接口文档网址从上到下排列 */

// 获取危险信息提示（后端缺页面，接口只有危险值提示的参数）  1
export const queryDangerousInfo = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '', params)
}

// 获取添加项目结论列表（分页）  2
export const queryAddConclusionList = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '', params)
}

//保存总检信息  3
export const saveGeneralInspectionInfo = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '', params)
}

// 报告预览  4
export const queryPreviewReport = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '', params)
}

// 获取术语名称列表(条件+分页)(公共)  5
export const queryTermsList = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '', params)
}

// 获取阳性结果列表(分页+条件)  6
export const queryPositiveResultsList = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '', params)
}

// 获取体检项目结果明细  7
export const queryExaminationItemResult = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '', params)
}

//获取问诊明细  8
export const queryEvaluateDetails = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '', params)
}

//复查(获取复查项目列表)  9
export const queryReviewItemList = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '', params)
}

//复查(修改复查项目)  10
export const modifyReviewItems = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '', params)
}

//复查(删除复查项目)  11
export const deleteReviewItems = (params) => {
  return Request.requestJson(Request.DELETE, baseUrl + '', params)
}

//复查(复查报告查看)  12
export const queryReviewReport = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '', params)
}

//复查(新增复查项目)  13
export const addReviewItems = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '', params)
}

// 审查(个人报告)  14
export const updatePersonalReview = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '', params)
}

// 下载个人报告word  15
export const downloadPersonalReport = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '', params)
}

//忽略指定基础项目  16
export const ignoreAssignedProject = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '', params)
}

// 获取人员详情  17
export const queryPersonDetails = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '', params)
}

//获取体检人员名称列表(条件+分页)  18
export const queryExaminerNameList = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '', params)
}
