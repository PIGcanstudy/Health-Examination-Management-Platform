import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  getMedicalPersonNameApi,
  getMedicalPersonDetailsApi,
  ignoreProjectApi,
  downloadReportApi,
  reviewApi,
  addReviewItemApi,
  getReviewItemsListApi,
  getInquiryDetailsApi,
  getMedicalExaminationResultsApi,
  getPositiveResultsListApi,
  storageInspectorReportApi,
  getAddedProjectConclusionsListApi,
  getMedicalExaminationResultsListApi
} from '@/apis/MedicalRegistration/index.js'
export const useMedicalRegistrationStore = defineStore('MedicalRegistration', () => {
  // 将接口返回的数据存储到仓库中
  const getMedicalPersonName = async (params) => {
    return await getMedicalPersonNameApi(params)
  }
  const getMedicalPersonDetails = async (params) => {
    return await getMedicalPersonDetailsApi(params)
  }
  // 将保存好的数据暴露出去，方便页面调用
  return {
    getMedicalPersonName,
    getMedicalPersonDetails
  }
})
