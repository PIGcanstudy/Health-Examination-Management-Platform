import Request from '@/apis/request.js'
const baseUrl = ''

/* 该接口文件的封装顺序参考接口文档网址从上到下排列 */
/* 对应亿图脑图中的主检评价接口，页面对应医生总检 */

// 获取体检项目结果明细（后端缺页面，接口只有危险值提示的参数）  1
export const queryDangerousInfo = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/Dangerous/query-depart', params)
}

// 获取添加项目结论列表（分页）  2
export const queryAddConclusionList = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/result/depart-result', params)
}

//保存总检信息  3
export const querySaveInfoInspect = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/info/save-info-inspect', params)
}

// 报告预览  4
export const queryPreviewReport = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/report', params)
}

// 获取术语名称列表(条件+分页)(公共)  5
export const queryTermsList = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/Term/query-positive', params)
}

// 获取阳性结果列表(分页+条件)  6
export const queryPositiveResultsList = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/positive/query-positive', params)
}

// 获取体检项目结果明细  7
export const queryExaminationItemResult = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/item-result', params)
}

//获取问诊明细  8
export const queryEvaluateDetails = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/evalue/inquiry-detail', params)
}

//复查(获取复查项目列表)  9
export const queryReviewItemList = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/review/query-review', params)
}

//复查(修改复查项目)  10
export const modifyReviewItems = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/review', params)
}

//复查(删除复查项目)  11
export const deleteReview = (params) => {
  return Request.requestJson(Request.DELETE, baseUrl + '/review/{id}', params)
}

//复查(复查报告查看)  12
export const queryReviewReport = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/review/pdf-review', params)
}

//复查(新增复查项目)  13
export const addReview = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/review/post-addNewItems', params)
}

// 审查  14
export const updatePersonalReview = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/healthy-c7-common/update-personal-review', params)
}

// 下载个人报告word  15
export const downloadPersonalReport = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/healthy-c7一common/ download-word', params)
}

//忽略指定基础项目  16
export const ignoreAssignedProject = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/healthy-c7-common/update-depart-item-result', params)
}

// 获取人员详情  17
export const queryPersonDetails = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/personDetail/query-detail', params)
}

//获取体检人员名称列表(条件+分页)  18
export const queryExaminerNameList = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/getUserName/query-unit', params)
}
